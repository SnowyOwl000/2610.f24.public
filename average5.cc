#include <iostream>

using namespace std;

int main() {
  int32_t
    sum=0,
    count=0,
    val;
  double
    average;
    
  while (true) {	// set up an infinite loop
    cout << "Enter a number (-1 to quit): ";
    cin >> val;

    if (val == -1)	// check here to see if we should stop
      break;

    sum += val;		// same as sum = sum + val, but shorter
    
    count++;
  }
  
  average = (double)sum / count;
  
  cout << "average: " << average << endl;
  
  return 0;
}

