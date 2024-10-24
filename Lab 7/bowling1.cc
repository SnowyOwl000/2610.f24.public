#include <iostream>

using namespace std;

const int
  MAX_ROLLS = 21;
  
int
  rolls[MAX_ROLLS],
  nextRoll=0,
  frameNum=1,
  scores[11]={0},
  frameStart[11]={0},     // this wastes position 0, remembers where frame starts in rolls array
  nRolls[11]={2,2,2,2,2,2,2,2,2,2,2};             // also wastes position 0, how many rolls used to score this frame (2 or 3)

  
bool tryToScoreFrame(int frameNum) {

  // check to see if enough rolls have been made
  if (nextRoll < frameStart[frameNum] + nRolls[frameNum])
    return false;

  scores[frameNum] = scores[frameNum-1];        // start with previous frame's score
  for (int j=0;j<nRolls[frameNum];j++)           // add in all of the frame's rolls (2 or 3)
    scores[frameNum] += rolls[frameStart[frameNum]+j];
    
  return true;
}

int main() {
  int
    score,
    ballNum=1,
    frameScore=0,
    nextFrameToScore=1;
    
  while (frameNum <= 10) {
    if (ballNum == 1)                   // remember where rolls for this frame are stored
      frameStart[frameNum] = nextRoll;
      
    cin >> score;             // get next score
    
    // see if we can score a frame
    if (tryToScoreFrame(nextFrameToScore)) {
      cout << "Frame " << nextFrameToScore << "  score " << scores[nextFrameToScore] << endl;
      nextFrameToScore++;
    }
    
    frameScore += score;      // add it to frame total (to see if we get all 10 pins)
      
    rolls[nextRoll] = score;  // remember the roll - add to list
    nextRoll++;
    
    //cout << "Frame: " << frameNum << "  ball: " << ballNum << "  score: " << score << endl;
    
    // did we get a strike or spare?
    if (frameScore == 10) {
      //cout << "  Frame score: " << frameScore << endl;
      nRolls[frameNum] = 3;     // include bonus roll(s)
      //scores[frameNum] = scores[frameNum-1] + frameScore;
      frameNum++;		// move to next frame
      ballNum = 1;		// first ball, next frame
      frameScore = 0;           // new frame, clear frame score
    } else {
      ballNum++;		// next ball, this frame
      if (ballNum == 3) {	// already two rolls
        //cout << "  Frame score: " << frameScore << endl;
        nRolls[frameNum] = 2;   // no bonus roll
        //scores[frameNum] = scores[frameNum-1] + frameScore;
        frameNum++;		// move to next frame
        ballNum = 1;            // first ball, next frame
        frameScore = 0;         // new frame, clear frame score
      }
    }
  }
  
  // process any bonus rolls from the 10th frame
  while (nextRoll < frameStart[10] + nRolls[10]) {
    cin >> rolls[nextRoll];
    nextRoll++;
  }
  
  while (nextFrameToScore < 11) {
    tryToScoreFrame(nextFrameToScore);
    cout << "Frame " << nextFrameToScore << "  score " << scores[nextFrameToScore] << endl;
    nextFrameToScore++;
  }    
  
  return 0;
}

