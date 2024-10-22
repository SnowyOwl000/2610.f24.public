#include <iostream>

using namespace std;

const int
  MAX_ROLLS = 21;

int main() {
  int
    rolls[MAX_ROLLS],
    score,
    nextRoll=0,
    frameNum=1,
    ballNum=1,
    frameScore=0,
    scores[11]={0};
    
  while (frameNum <= 10) {
    cin >> score;
    
    frameScore += score;
      
    rolls[nextRoll] = score;
    nextRoll++;
    
    cout << "Frame: " << frameNum << "  ball: " << ballNum << "  score: " << score << endl;
    
    // did we get a strike or spare?
    if (frameScore == 10) {
      cout << "  Frame score: " << frameScore << endl;
      scores[frameNum] = scores[frameNum-1] + frameScore;
      frameNum++;		// move to next frame
      ballNum = 1;		// first ball, next frame
      frameScore = 0;
    } else {
      ballNum++;		// next ball, this frame
      if (ballNum == 3) {	// already two rolls
        cout << "  Frame score: " << frameScore << endl;
        scores[frameNum] = scores[frameNum-1] + frameScore;
        frameNum++;		// move to next frame
        ballNum = 1;
        frameScore = 0;
      }
    }
  }
  
  cout << "Number of rolls: " << nextRoll << endl;
//  for (int i=0;i<nextRoll;i++)
//    cout << rolls[i] << endl;

  for (int i=1;i<=10;i++)
    cout << "Frame " << i << "  score: " << scores[i] << endl;
    
  return 0;
}

