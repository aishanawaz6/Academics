//import logo from './logo.svg';
import React from "react";
import "../App.css";
import { useState } from "react";
import logoBCS from "./Images/spendee.jpg";

// Component
const Hello = (msg) => {
  const { user } = msg;
  return <b>{user}</b>;
};

const Budget = () => {
  const [dispMessage, showMessage] = useState(null);
  const [print1a, setPrint1a] = useState(false);
  const [print1b, setPrint1b] = useState(false);
  const [print1c, setPrint1c] = useState(false);

  const [dispMessage2, showMessage2] = useState(null);
  const [print2a, setPrint2a] = useState(false);
  const [print2b, setPrint2b] = useState(false);
  const [print2c, setPrint2c] = useState(false);

  function setBudget(val) {
    setPrint2a(false);
    setPrint2b(false);
    setPrint2c(false);
    setPrint1b(true);
    console.warn(val.target.value);
    showMessage(
      "Your Budget was successfully set to " + val.target.value + "!"
    );
  }

  function editBudget(val2) {
    setPrint1a(false);
    setPrint1b(false);
    setPrint1c(false);
    setPrint2b(true);
    console.warn(val2.target.value);
    showMessage2(
      "Your Budget was successfully changed to " + val2.target.value + "!"
    );
  }
  function goA() {
    setPrint2a(false);
    setPrint2b(false);
    setPrint2c(false);
    setPrint1a(true);
  }
  function goB() {
    setPrint1a(false);
    setPrint1b(false);
    setPrint1c(false);
    setPrint2a(true);
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
      <p></p> <p></p> <p></p>
      <p></p> <p></p> <p></p>
      <img src={logoBCS} alt="BSCS  Image" />
      <h1> BUDGET CONTROL SYSTEM </h1>
      <p></p> <p></p> <p></p>
      <h2> - Budget Settings - </h2>
      <p></p>
      <button onClick={() => goA(true)}>Set My Budget</button>
      <p></p>
      <button onClick={() => goB(true)}>Edit Current Budget</button>
      <p></p>
      {print1a ? <b>Enter Budget: </b> : null}
      &nbsp;&nbsp;
      {print1a ? <input type="text" onChange={setBudget} /> : null}
      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      {print1b ? (
        <button class="button2" onClick={() => setPrint1c(true)}>
          SET!{" "}
        </button>
      ) : null}
      <p></p>
      {print1c ? <Hello user={dispMessage} /> : null}
      {print2a ? <b>Enter New Budget: </b> : null}
      {print2a ? <input type="text" onChange={editBudget} /> : null}
      &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;
      {print2b ? (
        <button class="button2" onClick={() => setPrint2c(true)}>
          SET!
        </button>
      ) : null}
      <p></p>
      {print2c ? <Hello user={dispMessage2} /> : null}
    </div>
  );
};

export default Budget;
