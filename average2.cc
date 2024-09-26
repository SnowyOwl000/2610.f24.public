#include <iostream>

using namespace std;

int main() {
  int32_t
    sum=0,
    count=0,
    average,
    val;
    
  cout << "Enter a number (-1 to quit): ";
  cin >> val;

  while (val != -1) {
    sum += val;		// same as sum = sum + val, but shorter
    
    count++;

    cout << "Enter a number (-1 to quit): ";
    cin >> val;
  }
  
  average = sum / count;
  
  cout << "average: " << average << endl;
  
  return 0;
}

