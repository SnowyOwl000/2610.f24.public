#include <iostream>
#include <fstream>
#include <cstdint>

using namespace std;

int main() {
  ifstream
    inFile;
  uint32_t
    val,
    sum=0;
    
  inFile.open("infile.dat");
  if (!inFile) {
    cout << "Open failed" << endl;
    
    // this isn't in the book
    // gives some more information about last error (the file open)
    perror("open");
    
    return 1;
  }
  
  // this is the book's version
  while (inFile >> val) {
  
  // this is my version
  //while (true) {
  //  inFile >> val;
  //  if (!inFile)
  //    break;
    
    cout << val << endl;
    
    sum += val;
  }

  inFile.close();
    
  cout << "Sum is " << sum << endl;
  
  return 0;
}

