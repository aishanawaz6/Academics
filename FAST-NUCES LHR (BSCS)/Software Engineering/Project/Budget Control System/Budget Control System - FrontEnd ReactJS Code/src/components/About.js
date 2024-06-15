/*import React from "react";

export const About=()=>{
    return(

        <div>
           <h1>This is About Page</h1>
        </div>
    );
};
export default About;*/
import React from 'react';
//import React, { useState, useContext, useEffect } from 'react'
import img1 from './Images/spendee.jpg';

const About=()=>{
    return(
        <div className="App">
        
        <div class="button">
                <div class="box">Y</div>
                <div class="box">O</div>
                <div class="box">U</div>
                <div class="box">R</div>
                <div class="box"> </div>
                <div class="box">B</div>
                <div class="box">U</div>
                <div class="box">D</div>
                <div class="box">G</div>
                <div class="box">E</div>
                <div class="box">T</div>
            </div>
            <p></p> <p></p> <p></p><p></p> <p></p> <p></p>
            <img src={img1} alt="BSCS  Image" />

        <h1> BUDGET CONTROL SYSTEM </h1>

        <p></p> <p></p> <p></p>
        <h2> - ABOUT - </h2>
        <p></p> <p></p> <p></p>
        <div className='body'>
            Spendee  is your budget control partner. We not help you track your expenses, 
        </div>
        <div className='body'> 
            but also actually help you achieve your budget goals by providing you product options 
        </div>
        <div className='body'>
        for all your expenses, considering the budget you have set in each budget category.
        </div>
        <div className='body'>
        Spendee helps you spend well!
        </div>
        <div className='body'>
____________________________________________________________________________
        </div>
        <div className='body'>
            Customer Reviews!
        </div>
        <div className='body'>
        -//"With Spendee, I can spend more consciously!"
        </div>
        <div className='body'>
            Faryal Makhdoom, one of our valued customers-//
        </div>
        <div className='body'>
****************************************************
        </div>
        <div className='body'>
        "My New Year's Resolution for 2023 was to keep not exceed my monthly budget,
        </div>
        <div className='body'>
        and for the first time in my life, I have been able to keep up with my NY resolution."
        </div>
        <div className='body'>
        - Daniyal Ali
        </div>
        <div className='body'>
            *************************************************************
        </div>
        <div className='body'>
        "Spendee, THANK YOU!"
        </div>
        <div className='body'>
        Fatima Kamran
        </div>
        
        
        
       



        </div>
    )
};

export default About;
