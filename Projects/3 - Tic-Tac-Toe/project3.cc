#include <iostream>

using namespace std;

const char
  LETTERS[3] = {'O',' ','X'};

int
  board[9];
 
//=============================================================================
// void displayBoard()
//   display the board on the screen
//

void displayBoard() {

  cout << "\033[2J\033[H"; // clear the screen
  
  cout << "   |   |\n"
          " ";
          
  if (board[0] == 1)
    cout << 'X';
  else if (board[0] == -1)
    cout << 'O';
  else
    cout << ' ';
    
  cout << " | ";

  if (board[1] == 1)
    cout << 'X';
  else if (board[1] == -1)
    cout << 'O';
  else
    cout << ' ';
    
  cout << " | ";

  if (board[2] == 1)
    cout << 'X';
  else if (board[2] == -1)
    cout << 'O';
  else
    cout << ' ';
    
  cout << "\n"
          "   |   |\n"
          "---+---+---\n"
          "   |   |\n"
          " ";
          
  cout << "O X"[board[3]+1];
  
  cout << " | ";
          
  cout << "O X"[board[4]+1];
  
  cout << " | ";
  
  cout << "O X"[board[5]+1];
  
  cout << "\n"
          "   |   |\n"
          "---+---+---\n"
          "   |   |\n"
          " ";
          
  cout << LETTERS[board[6]+1];
  
  cout << " | ";
          
  cout << LETTERS[board[7]+1];
  
  cout << " | ";
  
  cout << LETTERS[board[8]+1];
  
  cout << "\n"
          "   |   |\n";
}

//=============================================================================
// bool playerWins(int playerLetter)
//   determine if player has won the game
//
// Parameters
//   playerLetter - 1 for X, -1 for O
//
// Returns
//   true if player has won, false if not
//

bool playerWins(int playerLetter) {

  return false; // placeholder
}
  
//=============================================================================
// bool canWin(int playerLetter,int &winningSquare)
//   determine if player can win on this move
//
// Parameters
//   playerLetter  - 1 for X, -1 for O
//   winningSquare - if player can win, this is filled in with the square to
//                   take in order to win
//
// Returns
//   true if player can win on this move, false if player cannot win
//

bool canWin(int playerLetter,int &winningSquare) {

  return false; // placeholder to make compiler less unhappy
}

//=============================================================================
// void getComputerMove(int computerLetter)
//   determine next move for the computer and place move on the board
//
// Parameters
//   computerLetter - 1 if player is X, -1 if player is O
//

void getComputerMove(int computerLetter) {
  int
    winningSquare;

  // if computer can win, make the winning move
  if (canWin(computerLetter,winningSquare)) {
  }
  // else if human can win on the next move, make the blocking move
    else if (canWin(-computerLetter,winningSquare)) {
  }
  // else if center is open, take it
  
  // else if a corner is open, take it
  
  // else take any open square
  
}

//=============================================================================
// void getHumanMove(int humanLetter)
//   get one move from the keyboard, allow for exiting the program
//   also, place move on the board
//
// Parameters
//   humanLetter - 1 if player is X, -1 if player is O
//

void getHumanMove(int humanLetter) {

  // display board
  
  // determine available choices
  
  // do...
  
      // display choices
      
      // get a choice
      
      // if choice not valid, display msg
      
  // ... while choice not valid
  
  // place human's letter on the board at the given location
}

//=============================================================================
// int main()
//   the main code for tic-tac-toe
//

int main() {
  // variables
  bool
    isHumanTurn;
  int
    humanPlayer,
    computerPlayer;
    
  displayBoard();
  
  // randomly choose X player
  
  // loop at most 9 times... for loop here
  
      // get and apply move from proper player... call function for this
      if (isHumanTurn)
          getHumanMove(humanPlayer);
      else
          getComputerMove(computerPlayer);
      
      // see if the current player won the game... if so, display msg and return
      
      // change over to other player, it's their turn
      isHumanTurn = !isHumanTurn;
      
  // end loop

  // all done
  return 0;
}
