#include <iostream>

using namespace std;

int main() {
  // variables!
  double
    area,
    xCur,yCur,
    xPrev,yPrev,
    x1,y1;

  // area ← 0
  area = 0;

  // Get first point (x1, y1)
  cout << "Enter coordinates of first point: ";
  cin >> x1 >> y1;
  
  // Copy first point to current point (xCur , yCur ) ← (x1, y1)
  xCur = x1;
  yCur = y1;
  
  // do {
  do {
  
    // Copy current point to previous point (xPrev , yPrev ) ← (xCur , yCur )
    xPrev = xCur;
    yPrev = yCur;

    // Get current point (xCur , yCur )
    cout << "Enter coordinates of next point: ";
    cin >> xCur >> yCur;
    
    // area ← area + xPrev * yCur − xCur * yPrev
    area = area + xPrev * yCur - xCur * yPrev;	// also... area += xPrev * yCur - yPrev * xCur
  
  // } while current point does not equal first point
  } while (xCur != x1 || yCur != y1);
  
  // area ← area / 2
  area = area / 2;
  
  // output area
  cout << "Area is: " << area << endl;

  return 0;
}

