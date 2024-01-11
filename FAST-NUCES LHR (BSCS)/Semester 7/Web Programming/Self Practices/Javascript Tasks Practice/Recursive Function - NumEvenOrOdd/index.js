function isEven(number) {
  // Base case: if the number is 0, it's even.
  if (number === 0) {
    return true;
  }
  // Base case: if the number is 1, it's odd.
  else if (number === 1) {
    return false;
  }
  // Recursive case: For any other positive integer, subtract 2 and call the function again.
  else if (number > 1) {
    return isEven(number - 2);
  }
  // Handle negative numbers by calling the function with the absolute value.
  else {
    return isEven(Math.abs(number));
  }
}

// Test the function with some examples
console.log(isEven(4)); // Output: true (4 is even)
console.log(isEven(7)); // Output: false (7 is odd)
console.log(isEven(-2)); // Output: true (-2 is even)
console.log(isEven(-5)); // Output: false (-5 is odd)
