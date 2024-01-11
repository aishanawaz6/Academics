window.onload=init;
function init() {


const clickableText = document.getElementById('main-box');
clickableText.addEventListener('click', handleClickOnCard);

const resetButton = document.getElementById('reset-button');
resetButton.addEventListener('click', handleReset);


const nextButton= document.getElementById('next-button');
nextButton.addEventListener('click', handleClickOnNext);

document.getElementById('prev-button').style.display='none';
document.getElementById('main-box').style.display='none';
document.getElementById('next-button').style.display='none';
document.getElementById('reset-button').style.display='none';


const prevButton= document.getElementById('prev-button');
prevButton.addEventListener('click', handleClickOnPrev);

const fileButton= document.getElementById('file-button');
fileButton.addEventListener('click', readFile);


let questionOnDisplay=false; 
let started=false; 
  
var questions=[];
var answers=[];
var currentIndex=-1;


function handleClickOnCard() {
if (started){
if(questionOnDisplay){    
document.getElementById('question-text').textContent=answers[currentIndex];
questionOnDisplay=false;
document.getElementById('question-text').style.color='blue';
}
else{
document.getElementById('question-text').textContent=questions[currentIndex];
questionOnDisplay=true;
document.getElementById('question-text').style.color='#041E42';
}
}
else{
alert("Click 'Next' Button to get Started!");
}
}

function handleClickOnNext(){
if(currentIndex===-1)
{started=true;}
if(started)
{
currentIndex=currentIndex+1;
questionOnDisplay=false;
handleClickOnCard()
if(currentIndex===1)
{document.getElementById('prev-button').style.display='';}
if(currentIndex+1===questions.length)
{document.getElementById('next-button').style.display='none';}
}
}

function handleClickOnPrev(){
if(started){
currentIndex=currentIndex-1;
questionOnDisplay=false;
handleClickOnCard()

if(currentIndex===0)
{document.getElementById('prev-button').style.display='none';}
if(currentIndex+1<questions.length)
{document.getElementById('next-button').style.display='';}


}
}
function readFile() {
    const fileInput = document.getElementById('fileInput');
    
    // Check if any file is selected
    if (fileInput.files.length === 0) {
        alert('Please select a file.');
        return;
    }
    
    const file = fileInput.files[0];
    const reader = new FileReader();
    
    reader.onload = function(event) {
        const content = event.target.result;
        const lines = content.split('\n'); // Splitting by newline to get an array of lines
        
        // Populate questions and answers arrays
        for (let i = 0; i < lines.length; i += 2) {
            questions.push(lines[i]); // Pushing questions into the questions array
        }
        
        for (let i = 1; i < lines.length; i += 2) {
            answers.push(lines[i]); // Pushing answers into the answers array
        }
        
       alert("Flash Cards Generated Successfully!");
document.getElementById('main-box').style.display='';
document.getElementById('next-button').style.display='';
document.getElementById('instructions-box').style.display='none';
document.getElementById('reset-button').style.display='';
document.getElementById('welcome').textContent='FLASH CARDS';
    };
    
    reader.readAsText(file);
}

function handleReset(){
questions.length = 0;
answers.length=0;
document.getElementById('instructions-box').style.display='';
document.getElementById('main-box').style.display='none';
document.getElementById('next-button').style.display='none';
document.getElementById('reset-button').style.display='none';
document.getElementById('prev-button').style.display='none';
document.getElementById('welcome').textContent='WELCOME TO FLASHCARDS VIEWER!';

}
};