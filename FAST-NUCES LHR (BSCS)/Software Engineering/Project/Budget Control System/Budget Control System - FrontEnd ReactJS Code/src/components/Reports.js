//Points , Report , Addd budget
//import logo from './logo.svg';
//import logo from './logo.svg';
import React from "react";
import "../App.css";
import { useState } from "react";
import logoBCS from "./Images/spendee.jpg";
import MonthlyExpenses from "./Data.js";
import MonthlySummary from "./Data2.js";
import ImprovementsReport from "./Data3.js";
import ExpensesSuggestions from "./Data4.js";
import History from "./Data5.js";

const Hello = (msg) => {
  const { user } = msg;
  return <b>{user}</b>;
};

function Report() {
  const [dispMessage, showMessage] = useState();
  const [okay, setOkay] = useState(false);
  const [show, setShow] = useState(true);
  const viewMonthlyExpenses = () => {
    setShow(true);
    showMessage(MonthlyExpenses);
    setOkay(true);
  };
  const viewMonthlySummary = () => {
    setShow(true);
    showMessage(MonthlySummary);
    setOkay(true);
  };
  const viewImprovements = () => {
    setShow(true);
    showMessage(ImprovementsReport);
    setOkay(true);
  };
  const getExpensesSuggestions = () => {
    setShow(true);
    showMessage(ExpensesSuggestions);
    setOkay(true);
  };
  const ViewHistory = () => {
    setShow(true);
    showMessage(History);
    setOkay(true);
  };
  const Close = () => {
    setShow(false);
    setOkay(false);
  };
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
      <h2> - REPORTS & HISTORY - </h2>
      <p></p> <p></p> <p></p>
      <button class="button3" onClick={ViewHistory}>
        {" "}
        <span class="button3-content">View History </span>
      </button>
      <p></p> <p></p> <p></p>
      <p></p> <p></p> <p></p>
      <button class="button3" onClick={viewMonthlyExpenses}>
        <span class="button3-content">View Monthly Expenses Report</span>
      </button>
      <p></p> <p></p> <p></p>
      <p></p> <p></p> <p></p>
      <button class="button3" onClick={viewMonthlySummary}>
        <span class="button3-content">View Monthly Summary Report</span>
      </button>
      <p></p> <p></p> <p></p>
      <p></p> <p></p> <p></p>
      <button class="button3" onClick={viewImprovements}>
        <span class="button3-content">View Improvements Report</span>
      </button>
      <p></p> <p></p> <p></p>
      <p></p> <p></p> <p></p>
      <button class="button3" onClick={getExpensesSuggestions}>
        <span class="button3-content">Get Expenses' Suggestions</span>
      </button>
      <p>&nbsp;</p>
      {show ? <Hello user={dispMessage} /> : null}
      <p>&nbsp;</p>
      {okay ? (
        <buttonOK onClick={Close} className="buttonOK">
          {" "}
          OKAY{" "}
        </buttonOK>
      ) : null}
      <p>&nbsp;</p>
    </div>
  );
}

export default Report;
