window.onload=showQuote;

function showQuote(){
document.getElementById('BenjaminFranklin').onclick=Quote;
document.getElementById('WilliamShakespeare').onclick=Quote;
document.getElementById('AlexanderPope').onclick=Quote;
}

function Quote(){
switch(this.id){

case 'BenjaminFranklin':
alert('Three can keep a secret, if two of them are dead.')
break;

case 'WilliamShakespeare':
alert('To be or not to be, that is the question..')
break;

case 'AlexanderPope':
alert('To err is human; to forgive, divine.')
break;

}
}
