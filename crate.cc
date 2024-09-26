#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main() {
  // variables and constants
  const double
    PRICE_PER_CF = 0.5,
    COST_PER_CF = 0.23;
  double
    length,width,height,		// dimensions of crate
    volume,				// volume of crate
    cost,				// cost to produce
    price,				// customer price
    profit;				// profit
  
  // input
  // get length, width, height
  cout << "Enter length (in feet): ";
  cin >> length;
  
  cout << "Enter width (in feet): ";
  cin >> width;
  
  cout << "Enter height (in feet): ";
  cin >> height;
  
  // calculations

  // volume = length * width * height
  volume = length * width * height;
  
  // price = volume * price constant
  // cost = volume * cost constant
  price = volume * PRICE_PER_CF;
  cost = volume * COST_PER_CF;
  
  // rounding
  price = round(price * 100) / 100.0;
  cost = round(cost * 100) / 100.0;
  
  // profit = price - cost
  profit = price - cost;
  
  // output
  // blank line to separate input from output
  cout << endl;
  
  cout << "Volume: " << volume << " cf" << endl;
  
  cout << setprecision(2) << fixed;
  cout << "Cost to produce: $" << cost << endl;
  cout << "Customer price: $" << price << endl;
  cout << "Profit: $" << profit << endl;
  
  // all done!
  return 0;
}

