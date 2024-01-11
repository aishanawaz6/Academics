import React from 'react';
import ReactDOM from 'react-dom/client';
import './index.css';
import App from './App';
import reportWebVitals from './reportWebVitals';

import store from  "./Components/store.js";
import { PATIENTAdded, PATIENTCheckup, PATIENTRemoved } from "./Components/actions.js";
import * as actions from './Components/actionsTypes.js';


const root = ReactDOM.createRoot(document.getElementById('root'));
root.render(
  <React.StrictMode>
    
    <App />
    
  </React.StrictMode>

  
);


// If you want to start measuring performance in your app, pass a function
// to log results (for example: reportWebVitals(console.log))
// or send to an analytics endpoint. Learn more: https://bit.ly/CRA-vitals
reportWebVitals();

//REDUX-------------------------------------------------->



const unsubscribe = store.subscribe(() => {
    console.log("Store changed!", store.getState());
})

store.dispatch(PATIENTAdded("Ashii Nz"));
console.log(store.getState());
store.dispatch({
  type:"PATIENTAdded",
  payload: { name:'Lamar' }
})
store.dispatch(PATIENTRemoved(1));
store.dispatch(PATIENTCheckup(2))

unsubscribe();
store.dispatch({
  type:"PATIENTRemoved",
  payload: { id:2 }
})

console.log(store.getState());