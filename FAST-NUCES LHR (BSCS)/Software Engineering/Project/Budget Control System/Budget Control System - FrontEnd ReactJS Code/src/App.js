import React from 'react';
import Signup from './components/Signup';
import Home from './components/Home';
import "./App.css";
//import Navbar from './components/Navbar'
import About from './components/About'
import Products from './components/Products';
import { Routes, Route}  from 'react-router-dom';
import Login from './components/Login';
import Budget from './components/Budget';
import Reports from './components/Reports';
import Points from './components/Points';
import BudgetSetting from './components/Budget';

function App() {
  return (
    <>
  
    <div>
     
       <Routes>
       
        <Route path="/" element={<Login/>}/>
        <Route path="/signup/login" element={<Login/>}/>
        <Route path="/login/home" element={<Home/>}/>
        <Route path="/signup/login/home" element={<Home/>}/>
        <Route path="/signup/signup" element={<Signup/>}/>
        <Route path="/login" element={<Login/>}/>
        <Route path="/signup" element={<Signup/>}/>
        <Route path="/home" element={<Home/>}/>
        <Route path="/about" element={<About/>}/>
        <Route path="/products" element={<Products/>}/>
        <Route path="/budget" element={<Budget/>}/>
        <Route path="/reports" element={<Reports/>}/>
        <Route path="/points" element={<Points/>}/>
      </Routes> 
      
    
      
    
    </div>
    
    
    
    </>
  );
}

export default App;
