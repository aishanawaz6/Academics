import React from "react";
import "./Front.css";
import { useNavigate } from "react-router-dom";

export const Front= () =>{

    const navigate = useNavigate();

    const handleClick= () => {
        navigate("./Login")

    }
    const handleClick1= () => {
        navigate("./Signup")

    }



    return(
        
       
      
        <div className="main">
           
            <div className='t1'>
            BUDGET
            </div>

            <div className='t2'>
            CONTROL
            </div>
            <div className='t3'>
            SYSTEM
            </div>
            <div className='b1'>
            <button onClick={handleClick1}>SIGN UP</button>
            </div>
            <div className='b2'>
            <button onClick={handleClick}> LOGIN</button>
            </div>
            
        </div>
        

    );

}
export default Front;