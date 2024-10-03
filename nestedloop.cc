#include <iostream>
#include <cstdint>

using namespace std;

int main() {
  uint32_t
    row,col;
    
  // this will clear the terminal window
  cout << "\033[2J\033[H";
    
//  for (row=1;row<=3;row++)
//    for (col=1;col<=3;col++)
//      cout << row * col << endl;
      
//  for (row=1;row<=3;row++)
//    for (col=1;col<=3;col++)
//      cout << row * col;
      
  for (row=1;row<=3;row++) {
    for (col=1;col<=3;col++)
      cout << '\t' << row * col;
    cout << endl;
  }
      
  return 0;
}

