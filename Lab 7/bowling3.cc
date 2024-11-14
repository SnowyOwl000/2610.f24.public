#include <iostream>
#include <iomanip>

using namespace std;

const int
  MAX_ROLLS = 21,
  MAX_BOWLERS = 5;
  
int
  rolls[MAX_ROLLS * MAX_BOWLERS],
  nextRoll=0,
  frameNum=1,
  scores[11][MAX_BOWLERS]={0},
  frameStart[11][MAX_BOWLERS]={0},     // this wastes position 0, remembers where frame starts in rolls array
  nRollsPerFrame[11][5];          // also wastes position 0, how many rolls used to score this frame (2 or 3)
  /*
void displayFrame(int frameNum) {
  int
    r,c,
    n1,n2,n3;
    
  r = 2;
  
  if (frameNum == 10)
    c = 73;
  else
    c = 15 + frameNum * 6;
  
  cout << "\033[" << r << ';' << c << 'H';

  n1 = rolls[frameStart[frameNum]];

  if (n1 == 10)
    cout << 'X';
  else if (n1 > 0)
    cout << n1;
  else
    cout << '-';
    
  if (n1 < 10) {
    c += 2;
    cout << "\033[" << r << ';' << c << 'H';
    
    n2 = rolls[frameStart[frameNum]+1];
    
    if (n1 + n2 == 10)
      cout << '/';
    else if (n2 == 0)
      cout << '-';
    else
      cout << n2;
  }
  
  // 10th frame, first roll is a strike
  if (frameNum == 10 && n1 == 10) {
    c += 2;
    cout << "\033[" << r << ';' << c << 'H';

    n2 = rolls[frameStart[frameNum]+1];
    
    if (n2 == 10)
      cout << 'X';
    else if (n2 == 0)
      cout << '-';
    else
      cout << n2;
      
    c += 2;
    cout << "\033[" << r << ';' << c << 'H';

    n3 = rolls[frameStart[frameNum]+2];
    
    if (n3 == 10)
      cout << 'X';
    else if (n3 == 0)
      cout << '-';
    else if (n2 + n3 == 10)
      cout << '/';
    else
      cout << n3;
  }
  
  // 10th frame, second roll is a spare
  if (frameNum == 10 && n1 < 10 && n1 + n2 == 10) {
    c += 2;
    cout << "\033[" << r << ';' << c << 'H';

    n3 = rolls[frameStart[frameNum]+2];
    
    if (n3 == 10)
      cout << 'X';
    else if (n3 == 0)
      cout << '-';
    else
      cout << n3;
  }
  
  r = 4;
  c = 14 + frameNum * 6;
  
  cout << "\033[" << r << ';' << c << 'H' << setw(3) << scores[frameNum];
}
  
bool tryToScoreFrame(int frameNum) {

  // check to see if enough rolls have been made
  if (nextRoll < frameStart[frameNum] + nRollsPerFrame[frameNum])
    return false;

  scores[frameNum] = scores[frameNum-1];        // start with previous frame's score
  for (int j=0;j<nRollsPerFrame[frameNum];j++)           // add in all of the frame's rolls (2 or 3)
    scores[frameNum] += rolls[frameStart[frameNum]+j];
    
  displayFrame(frameNum);
    
  return true;
}
*/
int main() {
  int
    score,
    ballNum=1,
    playerNum=0,
    frameScore=0,
    nextFrameToScore[MAX_BOWLERS]={1,1,1,1,1},
    nBowlers;
  string
    playerName[MAX_BOWLERS];
    
  // initialize nRollsPerFrame
  for (int i=0;i<11;i++)
    for (int j=0;j<5;j++)
      nRollsPerFrame[i][j] = 2;
    
  // get bowler count and names
  cout << "\033[2J\033[HHow many bowlers? ";
  cin >> nBowlers;
  for (int i=0;i<nBowlers;i++) {
    cout << "Enter name of bowler " << (i+1) << ": ";
    cin >> playerName[i];
  }
    
  // draw screen, starting with top line
  cout << "\033[2J\033[H\033(0"
          "lqqqqqqqqqqqqqqqq"
          "wqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqwqk\n";
          
  for (int i=0;i<nBowlers;i++) {
    cout << "x                "
          "x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x x\n"
          "x                "
          "x mqvqu mqvqu mqvqu mqvqu mqvqu mqvqu mqvqu mqvqu mqvqnqvqvqu\n"
          "x                "
          "x     x     x     x     x     x     x     x     x     x     x\n";
    if (i < nBowlers-1)
      cout << "tqqqqqqqqqqqqqqqq"
          "nqwqwqnqwqwqnqwqwqnqwqwqnqwqwqnqwqwqnqwqwqnqwqwqnqwqwqnqwqwqu\n";
    else
      cout << "mqqqqqqqqqqqqqqqq"
          "vqqqqqvqqqqqvqqqqqvqqqqqvqqqqqvqqqqqvqqqqqvqqqqqvqqqqqvqqqqqj\n";
  }
  cout << "\033(B";
          
  // display player name
  for (int i=0;i<nBowlers;i++)
    cout << "\033[" << (3+4*i) << ";2H" << setw(16) << playerName[i];
  /*
  while (frameNum <= 10) {
    if (ballNum == 1)                   // remember where rolls for this frame are stored
      frameStart[frameNum] = nextRoll;
      
    cout << "\033[22;1HEnter roll: ";
    cin >> score;             // get next score
    
    // see if we can score a frame
    if (tryToScoreFrame(nextFrameToScore)) {
      //cout << "Frame " << nextFrameToScore << "  score " << scores[nextFrameToScore] << endl;
      nextFrameToScore++;
    }
    
    frameScore += score;      // add it to frame total (to see if we get all 10 pins)
      
    rolls[nextRoll] = score;  // remember the roll - add to list
    nextRoll++;
    
    //cout << "Frame: " << frameNum << "  ball: " << ballNum << "  score: " << score << endl;
    
    // did we get a strike or spare?
    if (frameScore == 10) {
      //cout << "  Frame score: " << frameScore << endl;
      nRollsPerFrame[frameNum] = 3;     // include bonus roll(s)
      //scores[frameNum] = scores[frameNum-1] + frameScore;
      frameNum++;		// move to next frame
      ballNum = 1;		// first ball, next frame
      frameScore = 0;           // new frame, clear frame score
    } else {
      ballNum++;		// next ball, this frame
      if (ballNum == 3) {	// already two rolls
        //cout << "  Frame score: " << frameScore << endl;
        nRollsPerFrame[frameNum] = 2;   // no bonus roll
        //scores[frameNum] = scores[frameNum-1] + frameScore;
        frameNum++;		// move to next frame
        ballNum = 1;            // first ball, next frame
        frameScore = 0;         // new frame, clear frame score
      }
    }
  }
  
  // process any bonus rolls from the 10th frame
  while (nextRoll < frameStart[10] + nRollsPerFrame[10]) {
    cin >> rolls[nextRoll];
    nextRoll++;
  }
  
  while (nextFrameToScore < 11) {
    tryToScoreFrame(nextFrameToScore);
    //cout << "Frame " << nextFrameToScore << "  score " << scores[nextFrameToScore] << endl;
    nextFrameToScore++;
  }    
  */
  cout << "\033[22;1H";
  
  return 0;
}
