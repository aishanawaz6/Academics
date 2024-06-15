// import { hasFormSubmit } from '@testing-library/user-event/dist/utils';
import {  useNavigate } from 'react-router-dom';
import React, { useState } from 'react';
import './F.css';

function Test() {
  const [formData, setFormData] = useState({
    firstName: '',
    lastName: '',
    password:'', 
    email: '',
    phone: '',
    address: '',
    city: '',
    state: ''
  });

  const [formErrors, setFormErrors] = useState({});

  const validateForm = () => {
    let errors = {};

    if (!formData.firstName) {
      errors.firstName = 'Please enter your first name.';
    }

    if (!formData.lastName) {
      errors.lastName = 'Please enter your last name.';
    }

    if (!formData.email) {
      errors.email = 'Please enter your email address.';
    } else if (!/\S+@\S+\.\S+/.test(formData.email)) {
      errors.email = 'Please enter a valid email address.';
    }

    if(!formData.password){
        errors.password='Enter the Password';
    }
    if (!formData.phone) {
      errors.phone = 'Please enter your phone number.';
    } else if (!/^\d{11}$/.test(formData.phone)) {
      errors.phone = 'Please enter a valid phone number.';
    }

    if (!formData.address) {
      errors.address = 'Please enter your address.';
    }

   

    setFormErrors(errors);

    return Object.keys(errors).length === 0;
  };

  const handleSubmit = (event) => {
    event.preventDefault();
    if (validateForm()) {
      console.log('Form submitted:', formData);
    }
  };

  const handleChange = (event) => {
    setFormData({
      ...formData,
      [event.target.name]: event.target.value
    });
  };
  const Navigate = useNavigate();

  const handleClick = () =>{
    Navigate("./Signup")

  }

  return (
    
  
    <div className="form-container">
      <form className="form" onSubmit={handleSubmit}>
        <h2>Registeration Form</h2>
        <div className="form-group">
          <label htmlFor="firstName">First Name:</label>
          <input type="text" id="firstName" name="firstName" className="input-field" value={formData.firstName}
           onChange={handleChange} />
          {formErrors.firstName && <span className="error">{formErrors.firstName}</span>}
        </div>
        <div className="form-group">
          <label htmlFor="lastName">Last Name:</label>
          <input type="text" id="lastName" name="lastName" className="input-field" value={formData.lastName} onChange={handleChange} />
          {formErrors.lastName && <span className="error">{formErrors.lastName}</span>}
        </div>
        <div className="form-group">
          <label htmlFor="email">Email:</label>
          <input type="email" id="email" name="email" className="input-field" value={formData.email} onChange={handleChange} />
          {formErrors.email && <span className="error">{formErrors.email}</span>}
        </div>
        <div className="form-group">
          <label htmlFor="password">Password:</label>
          <input type="password" id="password" name="password" className="input-field" value={formData.password} onChange={handleChange} />
          {formErrors.password && <span className="error">{formErrors.password}</span>}
        </div>
    
    
        <div className="form-group">
          <label htmlFor="address">Address:</label>
          <textarea id="address" name="address" className="input-field" value={formData.address} onChange={handleChange} />
          {formErrors.address && <span className="error">{formErrors.address}</span>}
          </div>
          <div className="form-group">
          <button onClick={handleClick}>Login</button>
          
          </div>
          </form>
          </div>
  )};
  export default Test;

