//Points , Report , Addd budget
//import logo from './logo.svg';
import '../App.css';
import { useState } from 'react'
import logoBCS from './Images/spendee.jpg';

// Component
const Hello = (msg) => {
    const { user } = msg;
    return (
        <b>{user}</b>

    )
}

function Points() {
    const [dispMessage, showMessage] = useState();
    const viewPoints = () => {
        showMessage('Your current points are : 4789');
    }
    const redeemPoints = () => {
        showMessage('The number of points you can redeem are: 4789 (Expires 20/10/23)' );
    }
    const assignPoints = () => {
        showMessage('You must be logged in as admin first. ');
    }
    return (
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
            <img src={logoBCS} alt=" " />

            <h1> BUDGET CONTROL SYSTEM </h1>

            <p></p> <p></p> <p></p>
            <h2> -    MANAGE POINTS     - </h2>
            <p></p> <p></p> <p></p>

            <button class="h2" onClick={viewPoints}>View Points</button>
            <p></p> <p></p> <p></p><p></p> <p></p> <p></p>

            <button onClick={redeemPoints}>Redeem Points</button>

            <p></p> <p></p> <p></p><p></p> <p></p> <p></p>
            <button onClick={assignPoints}>Assign Points</button>

            <p></p><p></p>
            < Hello user={dispMessage} />

        </div>
    );
}

export default Points;