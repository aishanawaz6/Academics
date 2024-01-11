import React, { useState,useEffect } from 'react';
import {FaCircleUser} from "react-icons/fa6";
import './rank.css';


function App() {
  const pageLimit=3;
  const [searchTerm,setSearchTerm]=useState('');
  const [searchButtonText,setsearchButtonText]=useState('Search');
  const [indexStart,setIndexStart]=useState(0);
  const [indexEnd,setIndexEnd]=useState(pageLimit);
  const [currentPage,setCurrentPage]=useState(1);
  const [filterValue,setfilterValue]=useState('userName');
  
  const DataOrg = [
    {
      rank: 1,
      userName: "The Avengers",
      userCNIC: "36502-5269482-8",
      totalGames: 29,
      score: "+515678",
      description: "Ranked first with 29 games and a score of +515678.",
      descShow: false
    },
    {
      rank: 2,
      userName: "Skale",
      userCNIC: "36502-9268472-1",
      totalGames: 29,
      score: "+509873",
      description: "Secured second place with 29 games and +509873 score.",
      descShow: false
    },
    {
      rank: 3,
      userName: "One Million Bugs",
      userCNIC: "33502-4239472-6",
      totalGames: 27,
      score: "+496677",
      description: "Holds third position with 27 games and +496677 score.",
      descShow: false
    },
    {
      rank: 4,
      userName: "The Musketeers",
      userCNIC: "73602-3219471-4",
      totalGames: 29,
      score: "+4133249",
      description: "Fourth place with 29 games and an impressive +4133249 score.",
      descShow: false
    },
    {
      rank: 5,
      userName: "Bugs Killer",
      userCNIC: "34402-2239371-2",
      totalGames: 29,
      score: "+3567841",
      description: "Fifth in line with 29 games and +3567841 points.",
      descShow: false
    },
    {
      rank: 6,
      userName: "Foo Fighters",
      userCNIC: "33502-2222479-9",
      totalGames: 25,
      score: "+2955667",
      description: "Ranked sixth, played 25 games, and scored +2955667.",
      descShow: false
    },
    {
      rank: 7,
      userName: "The Ultimate",
      userCNIC: "33502-5222479-3",
      totalGames: 25,
      score: "+2599851",
      description: "Seventh position with 25 games and +2599851 score.",
      descShow: false
    },
    {
      rank: 8,
      userName: "The Densour",
      userCNIC: "32502-5222479-1",
      totalGames: 5,
      score: "+2549852",
      description: "Eighth with 5 games and a score of +2549852.",
      descShow: false
    },
    {
      rank: 9,
      userName: "The Ghsour",
      userCNIC: "32502-5222479-1",
      totalGames: 5,
      score: "+2549852",
      description: "Ninth place with 5 games and a score of +2549852.",
      descShow: false
    },
    {
      rank: 10,
      userName: "The End",
      userCNIC: "32502-5222479-1",
      totalGames: 5,
      score: "+2549852",
      description: "Holding the 10th spot with 5 games and +2549852 points.",
      descShow: false
    }
  ];
  const [data,setData] = useState(DataOrg);
  const [viewPreferred,setViewPreferred]=useState('Grid View')

  function handleNextButton()
  {
    var limit=indexEnd;
    setCurrentPage((p)=>p+1);
    setIndexStart(indexEnd);
    if((indexEnd+pageLimit)<data.length)
    {
      limit=indexEnd+pageLimit
      document.getElementById('prev-button').style.display = 'inline';
    }
    else
    {
      limit=data.length;
      document.getElementById('next-button').style.display = 'none';
      document.getElementById('prev-button').style.display = 'inline';
    }
    setIndexEnd(limit);
  }
  function handlePrevButton()
  {
    setCurrentPage((p)=>p-1);
    var LimitPrev=0;
    setIndexEnd(indexStart);
    if((indexStart-pageLimit)>0)
    {
      LimitPrev=indexStart-pageLimit
      document.getElementById('next-button').style.display='inline';
    }
    else
    {
      LimitPrev=0;
      document.getElementById('prev-button').style.display = 'none';

      document.getElementById('next-button').style.display='inline';
    }
   
    setIndexStart(LimitPrev);
 
  }

  function searchImplementation(){
    if(searchButtonText==='Search'){
      alert(`searching by ${filterValue}`);
    const FilteredData=data.filter(
          (item)=>
          {
            if(typeof item[filterValue]==='string'){
              return item[filterValue].toLowerCase().includes(searchTerm.toLowerCase())
            }
             else{
              return item[filterValue]==searchTerm

     }})
if(FilteredData.length>0){
     setData(FilteredData);
     setsearchButtonText('Go Back');
    }
    else{
      alert(`No Results Found for \"${searchTerm}\" !`);
    }
  }
  else{
    setsearchButtonText('Search')
    setData(DataOrg);
    setSearchTerm('');
  }
  }
  function handleViewDescription(index){
    const updatedData = data.map((item, idx) => 
    (idx === index && item.descShow===false) ? { ...item, descShow: true } : ( (idx === index && item.descShow===true)?{ ...item, descShow: false }:item)
  );
    setData(updatedData);

  }
  function searchIT(e){
    if(e.key=="Enter"){
searchImplementation()
    }}
    return (
      <> 
      <h1 id='headingUser'>~ User Rank List ~</h1>
      <button id='view-button' onClick={()=>setViewPreferred((v)=>v==='Grid View'? 'List View':'Grid View')}>{viewPreferred}</button>
      <input id='search-bar' type='text' placeholder='Search User...' value ={searchTerm} onChange={(e)=>setSearchTerm(e.target.value)}onKeyDown={searchIT}></input>
      <button id='search-button' onClick={searchImplementation}>{searchButtonText}</button>
      <button id='prev-button' onClick={handlePrevButton}>&lt;&lt;</button>
      <p id='page-count'>{currentPage}</p>
      <label>Select Filter:&nbsp;</label>
      <select id='dropdown' value={filterValue} onChange={(e)=>setfilterValue(e.target.value)}>  
       <option value=''>Search By</option>
       <option value='userName'>User name</option>
       <option value='rank'>Rank</option>
       <option value='userCNIC'>CNIC</option>
       <option value='totalGames'>Total Games Played</option>
       <option value='score'>Score</option>
       </select>
    
      <button id='next-button' onClick={handleNextButton}>&gt;&gt;</button>
    
  <div className='main-container'>
    {(viewPreferred==='Grid View')&&(
    <table className='table'>
      <tr className='heading'>
        <th>RANK</th>
        <th>USER NAME</th>
        <th>USER CNIC</th>
        <th>TOTAL GAMES PLAYED</th>
        <th>SCORE</th>
        <th>Description</th>
      </tr>
      {data.map((elem,index)=>{
        return(
        <>
        {(index>=indexStart&&index<indexEnd)&&<>
        <tr className='Rows'>
          <td>{elem.rank}</td>
          <td className='User'> <span className='icon'><FaCircleUser/></span> {elem.userName}</td>
          <td>{elem.userCNIC}</td>
          <td>{elem.totalGames}</td>
          <td>{elem.score}</td>
          <td><button onClick={()=>handleViewDescription(index)}>View Description</button></td>
        </tr>
           {elem.descShow&&(<tr id='des-row' colSpan={9} >{elem.description}</tr>)}
       </> }
        </>
 );
      })}
    </table>)}
    {(viewPreferred=='List View')&&(
      <div class="grid-container">
        {data.map((elem,index)=>{
          return ( 
             <>
        {(index>=indexStart&&index<indexEnd)&&<>
             <div class="grid-item">
              <p>{elem.rank}</p>
              <p><span className='icon'><FaCircleUser/></span> {elem.userName}</p>
              <p>{elem.userCNIC}</p>
              <p>{elem.totalGames}</p>
              <p>{elem.score}</p>         
              </div>
</>}
            </>);
  
  })  }  
      
</div>

    )
}

  </div>
  </>
  );
}

export default App;