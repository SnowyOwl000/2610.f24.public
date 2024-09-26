#include <iostream>

using namespace std;

int main() {
  int32_t
    f = 1;
    
  for (int32_t n=1;n<=47;n++) {
    f *= n;		// same as f = f * n
    
    cout << n << "\t\t" << f << endl;
  }
  
  return 0;
}

