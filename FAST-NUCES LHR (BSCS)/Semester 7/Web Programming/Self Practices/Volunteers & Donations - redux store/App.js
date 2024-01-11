import React, { useState,useEffect } from 'react';
import { BrowserRouter as Router, Routes, Route, Link, Outlet, useParams } from 'react-router-dom';
import { useSelector, useDispatch } from 'react-redux';
import { updateDonations } from './store/khidmatDonationSlice.ts';
import { updateVolunteers,removeVolunteer } from './store/khidmatVolunteerSlice.ts';
import './khidmatStore.css';


function App() {
  const [donateForm,setDonateForm]=useState(false);
  const [history,setHistory]=useState(false);
  const [removeVolunteerF,setremoveVolunteer]=useState(false);
  const [donationFormInput, setDonationFormInput] = useState({
    DonorName: '',
    date: '',
    area: '',
    cardType: '',
    amount: 0,
  });
  const [namee,setName]=useState('');
  const [areaa,setArea]=useState('');
  const [amountt,setAmount]=useState(0);
  const [datee,setDate]=useState('');
  const [cardTypee,setCardType]=useState('');
  const donationsData=useSelector((state)=>state.donationHistory.donations);
  const volunteersData=useSelector((state)=>state.volunteerHistory.volunteers);
  const dispatch=useDispatch();

  useEffect(() => {
    // Update the donationFormInput whenever any of the relevant variables change
    setDonationFormInput({
      DonorName: namee,
      date: datee,
      area: areaa,
      cardType: cardTypee,
      amount: amountt,
    });
  }, [namee, areaa, amountt, datee, cardTypee]);
  const handleSubmit = () => {
    console.log('Form Data:', donationFormInput);
    alert('Your Payment has been Confirmed!');
    dispatch(updateDonations([...donationsData,donationFormInput]));
    setDonateForm(false);
    setName('');
    setArea('');
    setAmount(0);
    setCardType('');
    setDate('');
  };
  function ProcessDonations(){
  
    return (
    donateForm && 
      <div>
      <h2>Donation Form</h2>

      <label>Your Name</label>
      <input
        type='text'
        placeholder='Enter Full Name here'
        value={namee}
        onChange={(e)=>setName(e.target.value)}
      />
      <p></p>

      <label>Date</label>
      <input
        type='text'
        placeholder='Today &rsquo;s date'
        value={datee}
        onChange={(e)=>setDate(e.target.value)}
      />
      <p></p>

      <label>Donation Area</label>
      <input
        type='text'
        placeholder='Area to Donate'
        value={areaa}
        onChange={(e)=>setArea(e.target.value)}
      />
      <p></p>

      <label>Card Type</label>
      <input
        type='text'
        placeholder='Card Type for Payment'
        value={cardTypee}
        onChange={(e)=>setCardType(e.target.value)}
     />
      <p></p>

      <label>Amount</label>
      <input
        type='number'
        placeholder='Amount of Donation'
        value={amountt}
        onChange={(e)=>setAmount(e.target.value)}
   />
      <p></p>

      
     <button className='processDoneButton' onClick={handleSubmit}>Confirm Payment!</button>
      </div>
    );
  }
  useEffect(()=>{
    const pastDonations=[
      {    DonorName:'Aisha Nawaz',
        date:'20-October-2023',
        area:'Sindh',
        cardType:'MasterCard',
        amount:'20000',
      },
      { DonorName:'Ajan Nail',
        date:'24-October-2023',
        area:'Punjab',
        cardType:'DebitCard',
        amount:'8200',
      },
        {
          DonorName:'Arish Azam',
          date:'12-November-2023',
          area:'Punjab',
          cardType:'MasterCard',
          amount:'90000',
        }
    ];
    const pastVolunteers=[
      {    Name:'Aliya Noor',
        area:'Sindh',
      },
      { Name:'J',
        area:'Punjab',
      },
        {
          Name:'Aiman Azeem',
          area:'Punjab',
        }
    ];
 
   
    dispatch(updateDonations(pastDonations));
    dispatch(updateVolunteers(pastVolunteers));
  },[]);
  function showHistory(){
    return (
     history &&( 
      <div>
      <ul>
      <h2>Donors</h2>
      {donationsData.map((donation,i)=>
      (
       <li key={i}>
         <p>Donor Name: {donation.DonorName}</p>
         <p>Date: {donation.date}</p>
         <p>Donated Area: {donation.area}</p>
         <p>Amount Donated:{donation.amount}</p>
       </li>
      ))
      }
      </ul>
          <ul>
          <h2>Volunteers</h2>
          {volunteersData.map((volunteer,i)=>
          (
           <li key={i}>
             <p>Volunteer Name: {volunteer.Name}</p>
             <p>Area: {volunteer.area}</p>
           </li>
          ))
          }
          </ul>
</div>    
      )
    );
  }
  const [volunteerName,setVolunteerName]=useState('');
  function HandleRemoveVolunteer(){
    return (
     removeVolunteerF &&(
      <div>
      <label>Enter Volunteer Name: </label>
      <input placeholder='Volunteer to remove name' value={volunteerName}
      onChange={(e)=>{setVolunteerName(e.target.value)}}></input>
      <button className='processDoneButton' onClick={removeVolunteerNow}>Remove Now</button>
      </div>

     )
    );
  }
  function removeVolunteerNow(){
    console.log('Volunteer Name to remove:', volunteerName);
    dispatch(removeVolunteer({Name:volunteerName}));
    alert('Volunteer Removed');
    console.log(volunteerName);
    setremoveVolunteer(false);
    setVolunteerName('');
  }
  return (
    <>
   <h1>Khidmat: Donations & Volunteers Platform</h1>
   <button className='processButton' onClick={()=>setHistory(history? false:true)}>Show History</button>
  {showHistory()}
   <button className='processButton' onClick={()=>setDonateForm(donateForm? false:true)}>Donate Now!</button>
   <ProcessDonations/>
   <button className='processButton' onClick={()=>setremoveVolunteer(removeVolunteerF? false:true)}>Remove Volunteer</button>
   <HandleRemoveVolunteer/>
  
  </>
  );
}

export default App;