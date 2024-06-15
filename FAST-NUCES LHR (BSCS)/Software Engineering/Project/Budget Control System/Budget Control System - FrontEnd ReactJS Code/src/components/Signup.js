import React, { useState } from "react";
import { useNavigate } from "react-router-dom";
import "./Signup.css";
import { MdOutlineDriveFileRenameOutline } from "react-icons/md";
import { BiPhoneCall } from "react-icons/bi";
import { FaUser, FaLock } from "react-icons/fa";
import { AiTwotoneMail } from "react-icons/ai";
import Axios from "axios";
const Signup = () => {
  const navigate = useNavigate();
  const Nav = () => {
    navigate("./Login");
  };

  const [FisrtNameReg, setFisrtNameReg] = useState("");
  const [LastNameReg, setLastNameReg] = useState("");
  const [ContactReg, setContactReg] = useState("");
  const [usernameReg, setusernameReg] = useState("");
  const [EmailReg, setEmailReg] = useState("");
  const [passwordReg, setpasswordReg] = useState("");

  const register = async () => {
    try {
      const response = await Axios.post("http://localhost:5000/Signup", {
        firstname: FisrtNameReg,
        lastname: LastNameReg,
        contact: ContactReg,
        username: usernameReg,
        email: EmailReg,
        password: passwordReg,
      });

      console.log(response);

      // Navigate to login page after successful registration
      //navigate('./Login');
    } catch (error) {
      console.error(error);
    }
  };
  return (
    <div className="container">
      <form id="form" className="form" autoComplete="off">
        <h2>Signup</h2>
        <div className="panel panel-default"></div>
        <div className={`form-control`}>
          <label for="firstName">
            <MdOutlineDriveFileRenameOutline />
            <span>First Name</span>{" "}
          </label>
          <input
            type="text"
            onChange={(e) => {
              setFisrtNameReg(e.target.value);
              console.log(FisrtNameReg);
            }}
            id="firstName"
            placeholder="Enter First Name"
          />
        </div>
        <div className={`form-control`}>
          <label for="firstName">
            <MdOutlineDriveFileRenameOutline />
            <span>Last Name</span>{" "}
          </label>

          <input
            type="text"
            onChange={(e) => {
              setLastNameReg(e.target.value);
              console.log(LastNameReg);
            }}
            id="lastName"
            placeholder="Enter Last Name"
          />
        </div>
        <div className={`form-control`}>
          <label for="contact">
            <BiPhoneCall />
            <span>Contact No</span>
          </label>
          <input
            type="number"
            onChange={(e) => {
              setContactReg(e.target.value);
              console.log(ContactReg);
            }}
            id="contact"
            placeholder="Enter Contact Number"
          />
        </div>
        <div className={`form-control`}>
          <label for="username">
            <FaUser />
            <span>Username</span>
          </label>
          <input
            type="text"
            onChange={(e) => {
              setusernameReg(e.target.value);
              console.log(usernameReg);
            }}
            id="username"
            placeholder="Enter username"
          />
        </div>
        <div className={`form-control`}>
          <label for="email">
            <AiTwotoneMail size="1.2rem" />
            Email
          </label>
          <input
            type="text"
            onChange={(e) => {
              setEmailReg(e.target.value);
              console.log(EmailReg);
            }}
            id="email"
            placeholder="Enter email"
          />
        </div>
        <div className={`form-control`}>
          <label for="password">
            <FaLock />
            <span>Passsword</span>
          </label>
          <input
            type="password"
            onChange={(e) => {
              setpasswordReg(e.target.value);
              console.log(passwordReg);
            }}
            id="password"
            placeholder="Enter password"
          />
        </div>
        <button
          type="submit"
          onClick={() => {
            register();
            Nav();
          }}
        >
          Sign Up
        </button>
      </form>
    </div>
  );
};

export default Signup;
