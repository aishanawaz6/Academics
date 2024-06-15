import React, { useState } from "react";
import { useEffect } from "react";
import "./Signup.css";
//import "./Front.css"
import img1 from "./Images/spendee.jpg";
import axios from "axios";
import { useNavigate } from "react-router-dom";
import { FaUser, FaLock } from "react-icons/fa";

function Login() {
  const navigate = useNavigate();

  const handleClick3 = () => {
    navigate("./Home");
  };
  const [username, setusername] = useState("");
  const [password, setpassword] = useState("");

  const [loginStatus, setLoginStatus] = useState("");

  async function handleSubmit(e) {
    e.preventDefault();
    try {
      const response = await axios.post("http://localhost:5000/Login", {
        username: username,
        password: password,
      });

      console.log(response.data.message);
      if (response.data?.message) {
        setLoginStatus("Wrong Username/Password");
        //setLoginStatus(response.data.message)
        console.log(loginStatus);
      } else {
        console.log(response.data);

        setLoginStatus("Logged In");
        console.log(loginStatus);
        navigate("/home");
      }
    } catch (error) {
      console.log(error);
      setLoginStatus("An error occurred. Please try again later.");
    }
  }

  return (
    <>
      <div>
        <img src={img1} alt="" />
        <p className="p1">BUDGET CONTROL SYSTEM</p>
      </div>

      <div className="container">
        <form
          id="form"
          className="form"
          autoComplete="off"
          onSubmit={handleSubmit}
        >
          <h2>Login</h2>
          <div className="form-control">
            <label htmlFor="username">
              <FaUser />
              <span>Username</span>
            </label>
            <input
              type="text"
              id="username"
              placeholder="Enter username"
              onChange={(e) => setusername(e.target.value)}
            />
          </div>
          <div className="form-control">
            <label htmlFor="password">
              <FaLock />
              <span>Password</span>
            </label>
            <input
              type="password"
              id="password"
              placeholder="Enter password"
              onChange={(e) => setpassword(e.target.value)}
            />
          </div>
          <button
            type="submit"
            // onClick={() => {log();
            //   handleClick3();
            //   }}
          >
            Login
          </button>
        </form>
        <small className='status'>{loginStatus}</small>
      </div>
      <p className="p2">Don't Have an Account? </p>
      <a className="p3" href="./Signup">
        Sign Up
      </a>
    </>
  );
}
export default Login;
