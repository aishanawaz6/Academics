
//export default Products;*/
import React from 'react';
//import React, { useState, useContext, useEffect } from 'react'
import img1 from './Images/spendee.jpg';
import './Product.css'
import { useState } from 'react';
const Products=()=>{

  const [message,setmsg]=useState("");
  const ProductSelect=()=>{
    setmsg("Product Selected");
  }

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
        <h2> - PRODUCTS - </h2>
        <p></p> <p></p> <p></p>
        
        <div class="form__group field">
            <input type="input" class="form__field" placeholder="SearchProduct" required=""/>
            <label for="name" class="form__label">     search</label>
        </div>

        <div className="cardd">
            <div className="card-details">
                <p className="text-title">Plain Yoghurt</p>
                <p className="text-body">Rs. 100 <br></br> Nestle <br></br><br></br> Grocery</p>
            </div>
            <button className="card-button">Select</button>
        </div>

        <div className="cardd2">
            <div className="card-details">
                <p className="text-title">Mango Yoghurt</p>
                <p className="text-body">Rs. 120 <br></br> Nestle <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>

        <div className="cardd3">
            <div className="card-details">
                <p className="text-title">Yoghurt</p>
                <p className="text-body">Rs. 70 <br></br> Adams <br></br><br></br> Grocery<button>Select</button> </p>
            </div>
        </div>


        <div className="cardd4">
            <div className="card-details">
                <p className="text-title">Milk</p>
                <p className="text-body">Rs. 230 <br></br> Nestle <br></br><br></br> Grocery <button>Select</button></p>
            </div>
            <button className="card-button">Select</button>
        </div>

        <div className="cardd5">
            <div className="card-details">
                <p className="text-title">Chocolate Milk</p>
                <p className="text-body">Rs. 100 <br></br> Adams <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>


        <div className="cardd6">
            <div className="card-details">
                <p className="text-title">Almond Milk</p>
                <p className="text-body">Rs. 300 <br></br> Anhaar <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>

        <div className="cardd7">
            <div className="card-details">
                <p className="text-title">Milk</p>
                <p className="text-body">Rs. 140 <br></br> Adams <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>


        <div className="cardd8">
            <div className="card-details">
                <p className="text-title">Cheddar Cheese</p>
                <p className="text-body">Rs. 600 <br></br> Adams <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>

        <div className="cardd9">
            <div className="card-details">
                <p className="text-title">Mozzarella Cheese</p>
                <p className="text-body">Rs. 650 <br></br> Adams <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>

        <div className="cardd10">
            <div className="card-details">
                <p className="text-title">Mozzarella Cheese</p>
                <p className="text-body">Rs. 710 <br></br> Nestle <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>

        <div className="cardd11">
            <div className="card-details">
                <p className="text-title">Eggs</p>
                <p className="text-body">Rs. 240 <br></br> Anhaar <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>

        <div className="cardd12">
            <div className="card-details">
                <p className="text-title">Plain Bread</p>
                <p className="text-body">Rs. 190 <br></br> Dawn <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>


        <div className="cardd13">
            <div className="card-details">
                <p className="text-title">Bran Bread</p>
                <p className="text-body">Rs. 240 <br></br> Dawn <br></br><br></br> Grocery <button>Select</button></p>
            </div>
        </div>

        <div className="cardd14">
            <div className="card-details">
                <p className="text-title">Wireless Headset</p>
                <p className="text-body">Rs. 25000 <br></br> Samsung <br></br><br></br> Electronics <button>Select</button></p>
            </div>
        </div>


        <div className="cardd15">
            <div className="card-details">
                <p className="text-title">UHD TV</p>
                <p className="text-body">Rs. 107,900 <br></br> TCL <br></br><br></br> Electronics <button>Select</button></p>
            </div>
        </div>


        <div className="cardd16">
            <div className="card-details">
                <p className="text-title">LED TV</p>
                <p className="text-body">Rs. 190,000 <br></br> Samsung <br></br><br></br> Electronics <button>Select</button></p>
            </div>
        </div>


        <div className="cardd17">
            <div className="card-details">
                <p className="text-title">H/T G056 Tires</p>
                <p className="text-body">Rs. 7000 <br></br> AMF Motors <br></br><br></br> Spare Parts <button>Select</button></p>
            </div>
        </div>


        <div className="cardd18">
            <div className="card-details">
                <p className="text-title">Printed Kurti</p>
                <p className="text-body">Rs. 5000 <br></br> Limelight <br></br><br></br> Cothes <button>Select</button></p>
            </div>
        </div>


        <div className="cardd19">
            <div className="card-details">
                <p className="text-title">Gents Kurta</p>
                <p className="text-body">Rs. 6000 <br></br> Limelight <br></br><br></br> Cothes <button>Select</button></p>
            </div>
        </div>


        <div className="cardd20">
            <div className="card-details">
                <p className="text-title">Petrol</p>
                <p className="text-body">Rs. 280 <br></br> PSO <br></br><br></br> Fuel <button>Select</button></p>
            </div>
        </div>

        <div className="cardd21">
            <div className="card-details">
                <p className="text-title">Disel</p>
                <p className="text-body">Rs. 290 <br></br> PSO <br></br><br></br> Fuel <button>Select</button></p>
            </div>
        </div>


        <div className="cardd22">
            <div className="card-details">
                <p className="text-title">Light Disel</p>
                <p className="text-body">Rs. 170 <br></br> Shell <br></br><br></br> Fuel <button>Select</button></p>
            </div>
        </div>

        </div>
    )
};



export default Products;