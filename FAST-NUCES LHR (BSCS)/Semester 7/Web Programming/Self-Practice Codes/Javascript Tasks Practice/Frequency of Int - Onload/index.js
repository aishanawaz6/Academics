window.onload = freqGet;

function freqGet(){
const arrY=[1,'A','B',7,0,1];
var count=0;
for (let i=0;i<arrY.length;i=i+1){
if(typeof arrY[i] === 'number'){
count=count+1;
}
}
console.log(count);
}