import React , {useState} from 'react';
 
export default function NumberManager() {
   // 5. Use React state to store the list of numbers and update it when operations are performed.
  //  const [arrayNums, setarrayNum] = useState('1,2,3'); WRONG WAY TO INITIALIZE ARRAY
    const [arrayNums, setarrayNums] = useState([1, 2, 3]);
    const [newNumber, setNewNumber] = useState(0); // Will temporarly store new num
    // 1. Create a function called 'performOperation' that accepts two arguments: 
    //    an array of numbers and a callback function. 
    //    This function should apply the callback function to each number in the array 
    //    and return a new array with the results.
  function performOperation(arrayNums,callBackFunction) 
  {
    // 4.  Ensure that any changes to the list of numbers are done in an immutable way. 
    //     When the user performs an operation (e.g., square or double) on a number, 
    //     a new list should be generated without modifying the original list.
      return arrayNums.map((number) => callBackFunction(number));
  }

//  2. Implement a function called 'squareNumber' that takes a number as input
//     and returns the square of that number. Ensure that this function is pure.
  function squareNumber(userInput)
  {
    return userInput*userInput;
  }

  function DoubleNumber(userInput)
  {
    return userInput+userInput;
  }

  // 3. Create a new function called 'composeFunctions' that takes an array of functions
  //    as input and returns a single function that applies these functions in sequence to a given number. 
  //    For example, if you pass [squareNumber, doubleNumber],
  //    it should return a function that first squares a number and then doubles it.
  function pipe(...funcs) {
  return (arg) => funcs.reduce((result, func) => func(result), arg);
}
  function composeFunctions(arrayFunctions,num)
  {
    return pipe(...arrayFunctions)(num);
  }

  const handleAddNumber = (event) => {
    setarrayNums([...arrayNums, newNumber]);
    setNewNumber(0);
  };
/*
Your task is to create the 'NumberManager' component that incorporates these concepts.
It should display a list of numbers, allow users to perform operations on those numbers,
and show the results. Additionally, the component should have an input field and a button 
to add new numbers to the list.
The component should have the following elements:
An input field for entering new numbers.
A "Add Number" button for adding a new number to the list.
Buttons for performing operations like "Square" and "Double" on each number in the list.
Display the results of the operations on the numbers.
Ensure that all operations and state updates are done using the principles of
functional programming and React state management.*/
  return (
    <>
    <div>
    <p>{arrayNums}</p>
    <input type='number' onChange={(event) => setNewNumber(Number(event.target.value))}></input>
    <p></p> 
    <button onClick={handleAddNumber}>
    Add Number
    </button>
   <p></p> 
   <button onClick={() => setarrayNums(performOperation(arrayNums, squareNumber))}>
    Square
   </button>
   <p></p> 
    <button onClick={() => setarrayNums(performOperation(arrayNums, DoubleNumber))}>
     Double
    </button>
    </div>
    </>
  );
}

