#include <iostream>

using namespace std;

void drawBoard(int* boardState, int size, int player1ID, int player2ID);
bool isWinner(int* board, int currentPlayer, int sideLength);
int gameLogic(const int boardSize);
int getValidBoardPosition(int* boardState, int nonePlayerID, int size);
bool isColumnFilled(int* boardState, int currentPlayer, int sideLength);
bool isRowFilled(int* boardState, int currentPlayer, int sideLength);
bool isDiagoalFilled(int* boardState, int currentPlayer, int sideLength);  

int main(){
  const int boardSize = 3;

  int winner = gameLogic(boardSize);

  cout << "congratulations to player " << winner << "!"<<endl;
  return 0;
}

int gameLogic(const int boardSize){
  const int numberOfTiles = boardSize * boardSize;
  const int nonePlayer = 0;
  const int player1ID = 1;
  const int player2ID = 2;
  
  int board [numberOfTiles];
  for(int i = 0; i < numberOfTiles; i++){
    board[i] = nonePlayer;
  }
  int currentPlayerID = player1ID;
  while(true){
    int newPosition = getValidBoardPosition(board, nonePlayer, numberOfTiles);
    board[newPosition] = currentPlayerID;
    drawBoard(board, boardSize, player1ID, player2ID);
    if(isWinner(board, currentPlayerID, boardSize)){
      return (currentPlayerID);
    }
    if(currentPlayerID == player1ID){
      currentPlayerID = player2ID;
    }else{
      currentPlayerID = player1ID;
    }
  }
}

int getValidBoardPosition(int* boardState, int nonePlayerID, int size){
  int newPos = 0;
  cout << "Please enter your next move. It must be between 1 and "<< size << endl;
  cin >> newPos;
  newPos--; //accounts for 1-size index when typing
  if(newPos >= 0 && newPos < size){
    if(boardState[newPos] == nonePlayerID){
      return newPos;
    }
  }
  return getValidBoardPosition(boardState, nonePlayerID, size);
}

void drawBoard(int* boardState, int sideLength, int player1ID, int player2ID){
  cout << "\n" << endl;
  for(int i = 0; i < sideLength; i++){
    for(int j = 0; j < sideLength; j++){
      int currentTile = boardState[i*sideLength + j];
      if(currentTile == player1ID){
        cout << "X";
      }else if(currentTile == player2ID){
        cout << "O";
      }else{
        cout << "#";
      }
    }
    cout << endl;
  }
  cout << "\n\n\n";
}

bool isWinner(int* boardState, int currentPlayer, int sideLength){
  bool verticals, horizontals, diagonals;
  verticals = isColumnFilled(boardState, currentPlayer, sideLength);
  horizontals = isRowFilled(boardState, currentPlayer, sideLength);
  diagonals = isDiagoalFilled(boardState, currentPlayer, sideLength);
  return(verticals || horizontals || diagonals);
}

bool isRowFilled(int* boardState, int currentPlayer, int sideLength){
  
  for(int i = 0; i < sideLength; i++){
    bool rowFilled = true;
    for(int j = 0; j < sideLength; j++){
      if(boardState[i*sideLength + j] != currentPlayer){
        rowFilled = false;
        break;
      }
    }
    if(rowFilled){
      return true;
    }
  }
  return false;
}

bool isColumnFilled(int* boardState, int currentPlayer, int sideLength){
  
  for(int i = 0; i < sideLength; i++){
    bool columnFilled = true;
    for(int j = 0; j < sideLength; j++){
      if(boardState[j*sideLength + i] != currentPlayer){
        columnFilled = false;
        break;
      }
    }
    if(columnFilled){
      return true;
    }
  }
  return false;
}

bool isDiagoalFilled(int* boardState, int currentPlayer, int sideLength){
  bool firstDiagonalFilled = true;
  for(int i = 0; i < sideLength; i++){
    if(boardState[i*sideLength + i] != currentPlayer){
      firstDiagonalFilled = false;
      break;
    }
  }
  if(firstDiagonalFilled){
    return true;
  }else{
    for(int i = 0; i < sideLength; i++){
      if(boardState[(sideLength - i -1)*sideLength + i] != currentPlayer){
        return false;
      }
    }
  }
  return true;
}
