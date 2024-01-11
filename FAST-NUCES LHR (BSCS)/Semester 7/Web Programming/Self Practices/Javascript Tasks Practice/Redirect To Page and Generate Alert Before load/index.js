window.onload=getAlert;

function getAlert(){
document.getElementById('Redirect').onclick=alertNow;
}

function alertNow(){

alert('THIS IS AN ALERT! ABORT MISSION')
window.location=this; /*To Make a's href work*/
return false;

}