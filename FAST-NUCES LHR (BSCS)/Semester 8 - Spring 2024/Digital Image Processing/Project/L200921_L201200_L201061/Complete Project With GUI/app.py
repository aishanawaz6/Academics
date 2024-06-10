from flask import Flask, render_template, request, redirect, url_for, send_from_directory
import numpy as np
import cv2
import os
from werkzeug.utils import secure_filename

app = Flask(__name__)
app.config['UPLOAD_FOLDER'] = 'static/uploads/'
app.config['RESULT_FOLDER'] = 'static/results/'

# Ensure the upload and result directories exist
os.makedirs(app.config['UPLOAD_FOLDER'], exist_ok=True)
os.makedirs(app.config['RESULT_FOLDER'], exist_ok=True)

def convert_to_grayscale(image):
    return cv2.cvtColor(image, cv2.COLOR_BGR2GRAY)

def create_matrix_converter(color_image):
    matrix_converter = np.zeros((4, 256, 3), dtype=np.uint8)
    gray_image = convert_to_grayscale(color_image)
    for gray_level in range(256):
        gray_indices = np.where(gray_image == gray_level)
        mean_red = np.mean(color_image[gray_indices][:, 0])
        mean_green = np.mean(color_image[gray_indices][:, 1])
        mean_blue = np.mean(color_image[gray_indices][:, 2])
        matrix_converter[0, gray_level] = [mean_red, mean_green, mean_blue]
        matrix_converter[1:, gray_level] = [gray_level, gray_level, gray_level]
    return matrix_converter

def pseudo_color(gray_image, matrix_converter):
    pseudo_color_image = np.zeros((gray_image.shape[0], gray_image.shape[1], 3), dtype=np.uint8)
    for x in range(gray_image.shape[0]):
        for y in range(gray_image.shape[1]):
            gray_level = gray_image[x, y]
            color_values = matrix_converter[:, gray_level, :]
            pseudo_color_image[x, y] = color_values[0]
    return pseudo_color_image

@app.route('/', methods=['GET', 'POST'])
def upload_file():
    if request.method == 'POST':
        color_file = request.files['color_image']
        gray_file = request.files['gray_image']
        if color_file and gray_file:
            color_filename = secure_filename(color_file.filename)
            gray_filename = secure_filename(gray_file.filename)
            color_filepath = os.path.join(app.config['UPLOAD_FOLDER'], color_filename)
            gray_filepath = os.path.join(app.config['UPLOAD_FOLDER'], gray_filename)
            color_file.save(color_filepath)
            gray_file.save(gray_filepath)

            # Load and process images
            color_image = cv2.imread(color_filepath)
            gray_image = cv2.imread(gray_filepath, cv2.IMREAD_GRAYSCALE)
            matrix_converter = create_matrix_converter(color_image)
            result_image = pseudo_color(gray_image, matrix_converter)
            result_filename = 'result_' + gray_filename
            result_filepath = os.path.join(app.config['RESULT_FOLDER'], result_filename)
            cv2.imwrite(result_filepath, result_image)

            return redirect(url_for('results', color_filename=color_filename, gray_filename=gray_filename, result_filename=result_filename))
    return render_template('upload.html')



@app.route('/results/<color_filename>/<gray_filename>/<result_filename>')
def results(color_filename, gray_filename, result_filename):
    return render_template('results.html', color_filename=color_filename, gray_filename=gray_filename, result_filename=result_filename)


if __name__ == '__main__':
    app.run(debug=True)
