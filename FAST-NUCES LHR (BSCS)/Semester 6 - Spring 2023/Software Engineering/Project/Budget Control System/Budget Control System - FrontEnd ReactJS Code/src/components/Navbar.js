import React from "react";
import { Link } from "react-router-dom";
import "./Navbar.css"

export const Navbar = () =>{

    return(
        <>
        <nav>
            
            <div>
                <ul id="navbar">
                    <li><Link to="/home" className="active"> Home</Link></li>
                    <li><Link to="/about"> About</Link></li>
                    <li><Link to="/budget"> Budget</Link></li>
                    <li><Link to="/products"> Products</Link></li>
                    <li><Link to="/reports"> Reports</Link></li>
                    <li><Link to="/points"> Points</Link></li>  
                    <li><Link to ="/">Sign Out</Link></li>   
                </ul>
            </div>
        </nav>
        </>
    );
}
export default Navbar;