import React from "react";
import Navbar from "./Navbar";
import "./Navbar.css"
import { AiOutlineShoppingCart} from 'react-icons/ai';
import { AiFillFacebook, AiFillTwitterCircle,AiOutlineInstagram} from 'react-icons/ai';

export const Home=()=>{
    return(

      <div>
        <Navbar/>
        <div class="card">Budget</div>
        <div class="card1"><AiOutlineShoppingCart color="white" size="5rem"/></div>
        <div class="card2">Stay Updated</div>

       <div className="Fa">
        <button className="facebook"><AiFillFacebook /></button>
        <button className="twitter"><AiFillTwitterCircle/></button>
        <button className="instagram"><AiOutlineInstagram/></button>
       </div>


      </div>
      
   
    );
};
export default Home;