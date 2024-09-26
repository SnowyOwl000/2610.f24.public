#include <iostream>
#include <cmath>

using namespace std;

int main() {
  // variables
  double
    a,b,c,		// coefficients
    d;			// discriminant
  
  // get coefficients
  cout << "Enter coefficients a,b,c: ";
  cin >> a >> b >> c;
  
  // calculate d
  d = b * b - 4 * a * c;
  
  // handle error case
  if (a == 0 && b == 0) {
    cout << "Error: a and b cannot both be zero." << endl;
  
  // handle linear equation
  } else if (a == 0) {
    double
      root = -c / b;
      
    cout << "Linear equation, root is " << root << endl;
  
  // handle complex roots
  } else if (d < 0) {
    double
      re = -b / (2 * a),
      im = sqrt(-d) / (2 * a);
      
    cout << "Roots are " << re << " + " << im << "i and "
      << re << " - " << im << 'i' << endl;
  
  // handle double roots
  } else if (d == 0) {
    double
      root = -b / (2 * a);
      
    cout << "Double root is " << root << endl;
  
  // handle real roots
  } else {
    double
      x1 = (-b + sqrt(d)) / (2 * a),
      x2 = (-b - sqrt(d)) / (2 * a);
      
    cout << "Roots are " << x1 << " and " << x2 << endl;
  }
  
  // all done!
  return 0;
}

