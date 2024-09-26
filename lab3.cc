#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
  // step 0: variables
  double
    r,		// interest rate per payment
    pv,		// loan value
    n,		// number of payments
    pmt,	// payment amount
    apr,	// APR of loan
    
    amtPaid,	// total amount repaid
    totInt;	// total interest paid
    
  // step 1: get inputs
  // get loan amount
  cout << "Enter loan amount: ";
  cin >> pv;
  
  // get APR
  cout << "Enter APR [5.99% = 5.99]: ";
  cin >> apr;
  
  // get number of payments
  cout << "Enter number of loan payments: ";
  cin >> n;
  
  // step 2: do the thing
  // but first... calculate per payment rate
  r = apr / 1200;
  
  // r = per payment rate
  // pv = "present value," amount of loan
  // n = number of payments
  // calculate pmt = (r * pv) / (1 - (1+r)^-n)
  pmt = r * pv / (1 - pow(1+r,-n));
  
  // step 3: output results
  cout << setprecision(2) << fixed;
  cout << "Payment amount: $" << pmt << endl;

  // step 4: extra fun
  // amount paid: pmt * n
  amtPaid = pmt * n;
  
  cout << "Total amount paid: $" << amtPaid << endl;
  
  // total interest: amtPaid - pv
  totInt = amtPaid - pv;
  
  cout << "Interest paid on loan: $" << totInt << endl;

  // all done!
  return 0;
}

