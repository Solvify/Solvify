var toLowerCase = function(str) {
    // ASCII code difference between upper and lower case 32
    let arr = str.split('');
    let AscCode;
    let maxCode = 'Z'.charCodeAt();
    let minCode = 'A'.charCodeAt();
    for (let i = 0; i < arr.length; i++) {
      // Convert to ASCII
      AscCode = arr[i].charCodeAt();
      // Capitalized to lowercase
      if (maxCode >= AscCode && minCode <= AscCode) {
        arr[i] = String.fromCharCode(AscCode+32);
      }
    }
    return arr.join('');
  };

toLowerCase("Hello")