import React, { Component } from 'react';
import { FormErrors } from './FormErrors';

import './Signup.css';



class Form extends Component {
  constructor (props) {
    super(props);
    this.state = {
      email: '',
      password: '',
      firstName:'',
      lastName:'',
      contact:'',
      userName:'',
      cpassword:'',
      formErrors: {email: '', password: '',firstName:'',lastName:'',contact:'',userName:'',cpassword:''},
      emailValid: false,
      passwordValid: false,
      firstNameValid:false,
      lastNameValid:false,
      contactValid:false,
      userNameValid:false,
      cpasswordValid:false,
      formValid: false
    }
  }

  handleUserInput = (e) => {
    const name = e.target.name;
    const value = e.target.value;

    this.setState({[name]: value},
                  () => { this.validateField(name, value) });
  }

  validateField(fieldName, value) {
    let fieldValidationErrors = this.state.formErrors;
    let emailValid = this.state.emailValid;
    let passwordValid = this.state.passwordValid;
    let firstNameValid=this.state.firstNameValid;
    let lastNameValid=this.state.lastNameValid;
    let contactValid=this.state.contactValid;
    let userNameValid=this.state.userNameValid;
    let cpasswordValid=this.state.cpassword;

    switch(fieldName) {
      case 'email':
        emailValid = value.match(/^([\w.%+-]+)@([\w-]+\.)+([\w]{2,})$/i);
        fieldValidationErrors.email = emailValid ? '' : ' is invalid';
        break;
      case 'password':
        passwordValid = value.length >= 6;
        fieldValidationErrors.password = passwordValid ? '': ' is too short';
        break;
       case 'firstName':
        firstNameValid=value.length>0
        fieldValidationErrors.firstName=firstNameValid ? '': 'is mandatory';
        break;
        case 'lastName':
        lastNameValid=value.length>0
        fieldValidationErrors.lastName=lastNameValid ?  '':' is mandatory';
        break;
        case 'contact':
        contactValid=value.length>10
        fieldValidationErrors.contact=contactValid?'':'should be of 11 digits';
        break;
        case 'userName':
            userNameValid=value.length>0
            fieldValidationErrors.userName=userNameValid?'':'is mandatory';
            break
        case 'cpassword':
            cpasswordValid=value.length>=6;
            fieldValidationErrors.cpassword=cpasswordValid?'': 'is too short';    
            break;
      default:
        break;
    }
    this.setState({formErrors: fieldValidationErrors,
                    emailValid: emailValid,
                    passwordValid: passwordValid,
                    lastNameValid:lastNameValid,
                    firstNameValid:firstNameValid,
                    contactValid:contactValid,
                    userNameValid:userNameValid,
                    cpasswordValid:cpasswordValid,
                  }, this.validateForm);
  }

  validateForm() {
    this.setState({formValid: this.state.emailValid && this.state.passwordValid && this.state.firstNameValid && this.state.lastNameValid && this.state.contactValid && this.state.userNameValid && this.state.cpassword});
  }

  errorClass(error) {
    return(error.length === 0 ? '' : 'has-error');
  }
  

   render  ()  {
   
    return (
        <div className='container'> 
      <form className="form">
        <h2>Sign Up</h2>
        <div className="panel panel-default">
          <FormErrors formErrors={this.state.formErrors} />
        </div>
        <div className={`form-control ${this.errorClass(this.state.formErrors.firstName)}`}>
          <label htmlFor="firstName">First Name</label>
          <input type="text" required className="form-control" name="firstName"
            placeholder="firstName"
            value={this.state.firstName}
            onChange={this.handleUserInput}  />
        </div>
        <div className={`form-control ${this.errorClass(this.state.formErrors.lastName)}`}>
          <label htmlFor="lastName">Last Name</label>
          <input type="text" required className="form-control" name="lastName"
            placeholder="lastName"
            value={this.state.lastName}
            onChange={this.handleUserInput}  />
        </div>
        <div className={`form-control ${this.errorClass(this.state.formErrors.contact)}`}>
          <label htmlFor="contact">Contact</label>
          <input type="number" required className="form-control" name="contact"
            placeholder="contact"
            value={this.state.contact}
            onChange={this.handleUserInput}  />
        </div>
        <div className={`form-control ${this.errorClass(this.state.formErrors.email)}`}>
          <label htmlFor="email">Email address</label>
          <input type="email" required className="form-control" name="email"
            placeholder="Email"
            value={this.state.email}
            onChange={this.handleUserInput}  />
        </div>
        <div className={`form-control ${this.errorClass(this.state.formErrors.userName)}`}>
          <label htmlFor="userName">User Name</label>
          <input type="text" required className="form-control" name="userName"
            placeholder="userName"
            value={this.state.userName}
            onChange={this.handleUserInput}  />
        </div>
        <div className={`form-control ${this.errorClass(this.state.formErrors.password)}`}>
          <label htmlFor="password">Password</label>
          <input type="password" className="form-control" name="password"
            placeholder="Password"
            value={this.state.password}
            onChange={this.handleUserInput}  />
        </div>
        <div className={`form-control ${this.errorClass(this.state.formErrors.cpassword)}`}>
          <label htmlFor="cpassword">Confirm Password</label>
          <input type="password" className="form-control" name="cpassword"
            placeholder="CPassword"
            value={this.state.cpassword}
            onChange={this.handleUserInput}  />
        </div>
        <button type="submit" className="btn btn-primary" disabled={!this.state.formValid}>Sign up</button>
      </form>
      </div>
//     <div className="container">
//     <form id="form" className="form" autocomplete="off">
//         <h2>Signup</h2>
//         <div className="panel panel-default">
//           <FormErrors formErrors={this.state.formErrors} />
//         </div>
//         <div className={`form-control ${this.errorClass(this.state.formErrors.firstName)}`}>
//             <label for="firstName">First Name</label>
//             <input type="text" id="firstName" placeholder="Enter First Name" 
//              value={this.state.firstName}
//                     onChange={this.handleUserInput} 
//             />
          
//         </div>
//         <div className={`form-control ${this.errorClass(this.state.formErrors.lastName)}`}>
//             <label for="lastName">Last Name</label>
//             <input type="text" id="lastName" placeholder="Enter Last Name"
//              value={this.state.lastName}
//                  onChange={this.handleUserInput}

         
//           />
          
//         </div>
//         <div className={`form-control ${this.errorClass(this.state.formErrors.contact)}`}>
//             <label for="contact">Contact No.</label>
//             <input type="number" id="contact" placeholder="Enter Contact Number" 
//                     value={this.state.contact}
//                     onChange={this.handleUserInput}
            
//             />
            
//         </div>
//         <div className={`form-control ${this.errorClass(this.state.formErrors.userName)}`}>
//             <label for="username">Username</label>
//             <input type="text" id="username" placeholder="Enter username" 
//              value={this.state.userName}
//              onChange={this.handleUserInput} />
           
//         </div>
//         <div className={`form-control ${this.errorClass(this.state.formErrors.userName)}`}>
//             <label for="email">Email</label>
//             <input type="text" id="email" placeholder="Enter email"value={this.state.email}
            
//             onChange={this.handleUserInput} />
            
//         </div>
//         <div className={`form-control ${this.errorClass(this.state.formErrors.userName)}`}>
//             <label for="password">Password</label>
//             <input type="password" id="password" placeholder="Enter password"value={this.state.password}
            
//             onChange={this.handleUserInput} />
      
//         </div>
//         <div className={`form-control ${this.errorClass(this.state.formErrors.userName)}`}>
//             <label for="password2">Confirm Passsword</label>
//             <input type="password" id="password2" placeholder="Enter password again"value={this.state.cpassword}
            
//             onChange={this.handleUserInput} />
             
//         </div>
//         <button type="submit" disabled={!this.state.formValid} >Sign Up</button>
//     </form>
// </div>
    )
  }
}

export default Form;
