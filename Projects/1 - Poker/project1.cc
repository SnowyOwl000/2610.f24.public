#include <iostream>

using namespace std;

int main() {
  // step 0: variables
  int
    card1,card2,card3,card4,card5,  // card numbers
    rank1,rank2,rank3,rank4,rank5;  // card ranks (0=two, 12=ace)
  
  // step 1: input five cards from cin
  
  // step 2: calculate ranks of all five cards
  rank1 = card1 % 13;
  
  // step 3: verify that cards are valid
  
  // step 4: check for royal flush
  // rank1 == 8 ... or, check rank5 == 12
  // AND card2 == card1 + 1
  // AND card3 == card2 + 1
  // AND card4 == card3 + 1
  // AND card5 == card4 + 1
  
  // step 5: check for straight flush
  
  // step 6: check for four of a kind
  // rank1 == rank4 ... because ranks are sorted, ranks 2 and 3 also same
  // OR rank2 == rank5
  
  // step 7: check for full house
  // (rank1 == rank3 AND rank4 == rank5)
  // OR (rank1 == rank2 AND rank3 == rank5)
  
  // keep going...
  
  return 0;
}

