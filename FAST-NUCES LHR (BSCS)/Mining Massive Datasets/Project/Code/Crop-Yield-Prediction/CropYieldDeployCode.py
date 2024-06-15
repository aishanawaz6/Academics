import pyspark
from pyspark.sql import *
from pyspark.sql.functions import *
from pyspark import SparkContext, SparkConf
import sys
from pyspark.mllib.regression import LabeledPoint
from pyspark.mllib.tree import RandomForest
from pyspark.mllib.linalg import Vectors
from sklearn.metrics import  mean_absolute_percentage_error, mean_absolute_error, mean_squared_error, mean_squared_log_error, r2_score
import numpy as np
from pyspark.ml.linalg import Vector
from pyspark.ml.feature import VectorAssembler
from pyspark.ml.regression import LinearRegression
from pyspark.ml.evaluation import RegressionEvaluator
from pyspark.sql.functions import monotonically_increasing_id
from pyspark.ml.regression import GBTRegressor
from pyspark.sql.functions import abs as pyspark_abs
from sklearn.metrics import pairwise_distances
import random
from pyspark.ml.clustering import KMeans
from pyspark.ml.evaluation import ClusteringEvaluator
import time
from sklearn.metrics import silhouette_score
from pyspark.mllib.clustering import KMeans, KMeansModel
from pyspark.ml.clustering import KMeans
from math import sqrt


# Creating the Spark session and ContextRun PySpark.
conf = SparkConf().set("spark.ui.port","4050")
sc = pyspark.SparkContext(conf=conf)
spark = SparkSession.builder.appName("DataFrame").config('spark.ui.port', '4050').getOrCreate()     

dfName=sys.argv[1]
dfName2=sys.argv[2]
randomForestDF = spark.read.csv(dfName, header=True, inferSchema=True)
df = spark.read.csv(dfName, inferSchema=True,header=True)
clusteringDF = spark.read.csv(dfName2, header=True, inferSchema=True)

# Converting to RDD of LabeledPoint objects. Not using the target column, "Yield" to make feature vector
rddLabeledPoints = randomForestDF.rdd.map(lambda row: LabeledPoint(row["Yield"], Vectors.dense(row[1:-1])))

train_data, test_data = rddLabeledPoints.randomSplit([0.8, 0.2], seed=42)  #80% training, 20% testing split of data

# Parameters for training model
cFInfo = {} #empty because categorical variables are already properly encoded as numerical values
numTrees = 3  # Trees in random forest
featureSubsetStrategy = "auto"  # this is the strategy for selecting the feature subset
impurity = "variance"  # Impurity measure for variance calculation
maxDepth = 10  # Maximum depth of the trees
maxBins = 32  # Maximum number of bins used for splitting features
seed = 42  # for reproducibility in bootstrapping and feature subset selection

model = RandomForest.trainRegressor(train_data, cFInfo, numTrees,
                                    featureSubsetStrategy=featureSubsetStrategy, impurity=impurity,
                                    maxDepth=maxDepth, maxBins=maxBins, seed=seed)

# MODEL EVALUATION ON TEST DATA
predictions = model.predict(test_data.map(lambda x: x.features))
labelsPredictions = test_data.map(lambda lp: lp.label).zip(predictions)
actualValues = labelsPredictions.map(lambda lp: lp[0]).collect()
predictedValues = labelsPredictions.map(lambda lp: lp[1]).collect()

print('\n------------ Random Forest Results')
# 1) TEST MSE
testMSE = labelsPredictions.map(lambda lp: (lp[0] - lp[1]) ** 2).mean()
print("Test Mean Squared Error = " + str(testMSE))

# 2) Mean Absolute Error (MAE)
testMAE = np.mean(np.abs(np.array(actualValues) - np.array(predictedValues)))
print("Test Mean Absolute Error (MAE) =", testMAE)

# 3) Mean Absolute Percentage Error (MAPE)
testMAPE = np.mean(np.abs((np.array(actualValues) - np.array(predictedValues)) / np.array(actualValues))) * 100
print("Test Mean Absolute Percentage Error (MAPE) =", testMAPE)

# 4) Root Mean Squared Error (RMSE)
testRMSE = np.sqrt(mean_squared_error(actualValues, predictedValues))
print("Test Root Mean Squared Error (RMSE) =", testRMSE)

# 5) Calculate R-squared (R2)
test_r2 = r2_score(actualValues, predictedValues)
print("Test R-squared (R2) =", test_r2)

# 6) Calculating accuracy within a specific tolerance level
tolerance = 1.5  # tolerance level
correctPredictions = np.sum(np.abs(np.array(actualValues) - np.array(predictedValues)) <= tolerance)
accuracy = (correctPredictions / len(actualValues)) * 100
print("Accuracy within the", tolerance, "tolerance =", accuracy)

print('\n------------ Linear Regression Results')

# Vector Assembler

assembler = VectorAssembler(inputCols=['Production','Annual_Rainfall','Fertilizer','Pesticide','Area','Crop','Crop_Year','Season','State'],outputCol='features')
output= assembler.transform(df)
final_data=output.select('features','Yield')
final_data.head(5)

# Setting the tolerance level

tolerance = 1.5

# Splitting the data and training the model

train_data2,test_data2=final_data.randomSplit([0.8,0.2], seed=20) 
lr2 =LinearRegression(featuresCol='features',labelCol='Yield')
model2=lr2.fit(train_data2)
results2 = model2.evaluate(train_data2)
# Combining actual and predicted yield in a single PySpark dataframe
unlabeled_data2=test_data2.select('features')
preds2=model2.transform(unlabeled_data2)
preds2 = preds2.select('prediction')
actual2 = test_data2.select('Yield')
preds2 = preds2.withColumn("index", monotonically_increasing_id())
actual2 = actual2.withColumn("index", monotonically_increasing_id())
preds_labels2 = preds2.join(actual2, on="index").drop("index")

# Evaluating the results using accuracy, R2 Score, RMSE and MAE metrics

evaluator2 = RegressionEvaluator(labelCol="Yield", predictionCol="prediction", metricName="r2")
r22 = evaluator2.evaluate(preds_labels2)
evaluator2.setMetricName("mse")
mse2 = evaluator2.evaluate(preds_labels2)
evaluator2.setMetricName("mae")
mae2 = evaluator2.evaluate(preds_labels2)

within_tolerance2 = preds_labels2.filter(abs(preds_labels2.prediction - preds_labels2.Yield) <= tolerance)
correct_predictions2 = within_tolerance2.count()
total_predictions2 = preds_labels2.count()
accuracy2 = (correct_predictions2 / total_predictions2) * 100

print("Accuracy within the", tolerance, "tolerance =", accuracy2)
print('R2 Score on Testing Data:',r22)
print('Root Mean Squared Error on Testing Data:',(mse2**(1/2)))
print('Mean Absolute Error on Testing Data:',mae2)


print('\n------------ Gradient Boosted Trees Results')
assembler = VectorAssembler(inputCols=['Production','Annual_Rainfall','Fertilizer','Pesticide','Area','Crop','Crop_Year','Season','State'],outputCol='features')
output= assembler.transform(df)
final_data=output.select('features','Yield')
tolerance = 1.5

train_data2,test_data2=final_data.randomSplit([0.8,0.2], seed=20) 
gbt2 = GBTRegressor(featuresCol='features', labelCol='Yield')
model5 = gbt2.fit(train_data2)

# Combining actual and predicted yield in a single PySpark dataframe

unlabeled_data5=test_data2.select('features')
preds5 = model5.transform(unlabeled_data5)
preds5 = preds5.select('prediction')
actual5 = test_data2.select('Yield')
preds5 = preds5.withColumn("index", monotonically_increasing_id())
actual5 = actual5.withColumn("index", monotonically_increasing_id())
preds_labels5 = preds5.join(actual5, on="index").drop("index")

# Evaluating the results using accuracy, R2 Score, RMSE and MAE metrics

evaluator5 = RegressionEvaluator(labelCol="Yield", predictionCol="prediction", metricName="r2")
r25 = evaluator5.evaluate(preds_labels5)
evaluator5.setMetricName("mse")
mse5 = evaluator5.evaluate(preds_labels5)
evaluator5.setMetricName("mae")
mae5 = evaluator5.evaluate(preds_labels5)

within_tolerance5 = preds_labels5.filter(pyspark_abs(preds_labels5.prediction - preds_labels5.Yield) <= tolerance)
correct_predictions5 = within_tolerance5.count()
total_predictions5 = preds_labels5.count()
accuracy5 = (correct_predictions5 / total_predictions5) * 100

print("Accuracy within the", tolerance, "tolerance =", accuracy5)
print('R2 Score on Testing Data:',r25)
print('Root Mean Squared Error on Testing Data:',(mse5**(1/2)))
print('Mean Absolute Error on Testing Data:',mae5)


print('\n------------ KMeans Clustering Results')

# Vector Assembler

input_cols = ['Yield','Production','Season']
vec_assembler = VectorAssembler(inputCols = input_cols, outputCol="features")
final_data = vec_assembler.transform(clusteringDF)


# Function to calculate the BCSS

def calculateBcss(clusterCenters):

    bsse = 0.0

    num = len(clusterCenters)


    for i in range(num):

        for j in range(num):

          if(i!=j):

            centeri = clusterCenters[i]

            centerj = clusterCenters[j]

            squaredDist = np.sum((centeri - centerj) ** 2)

            bsse = bsse + squaredDist


    return bsse


# Fitting the model
print('K=5')
kmeans2 = KMeans(featuresCol='features',k=5)
model2 = kmeans2.fit(final_data)
centroids2 = model2.clusterCenters()

model2.transform(final_data).groupBy('prediction').count().show()
# Calculating the Silhouette Score
predictions2=model2.transform(final_data)
evaluator = ClusteringEvaluator(predictionCol="prediction", featuresCol="features", metricName="silhouette", distanceMeasure="squaredEuclidean")

silhouette2 = evaluator.evaluate(predictions2)
print("Silhouette Score:",silhouette2)

# Calculating the WCSS

print('WCSS: ',model2.summary.trainingCost)
# Calculating the BCSS

print('BCSS: ',calculateBcss(centroids2))