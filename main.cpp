#include<iostream>
#include<vector>
#include<array>

using namespace std;


/*
 * PRECONDITION: Given a 2D array.
 * POSTCONDITION: Printing the 2D array so it looks like a real board for game of go.
 * DESCRIPTION: Printing the board with indices on left side and on the top. The values are actually index + 1.
 */ 

void display(int board[15][15]){
    cout<<"     | ";
    for(int i = 1; i <= 15; i++){
        if(i < 9){
            cout << i << "  | ";
        }else{
            cout<<  i << "  |";
        }  
    }
    cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
    for(int i=0; i < 15; i++){
        if(i+1 < 10){
            cout<<i+1<<"    | ";
        }else{
            cout<<i+1<<"   | ";
        }
        for(int j = 0; j < 15; j++){
            if(j+1 < 10){
                cout << board[i][j] << "  | ";
            }else{
                cout << board[i][j] << "  | ";
            }  
        }
    cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
    }        
}

/*
 * PRECONDITION: Given a 2D array.
 * POSTCONDITION: Returning if there is a winner in the game. 
 * DESCRIPTION: Checking columns, diagonals, and rows to see if there is 5 pebbles in the row of the same collor.
 *              First, finding all positions that contain 1 or 2 on the board. 
 *              Second, starting from eaach position in the vector, look for 5 consecutive plays by row, column, or any diagonal. 
 */
 int checkBoardStatus(int board[15][15]){
     ///Get all the positions where there is a pebble
     vector<array<int,2>> current_positions = {};
     for(int i = 0; i < 15; i++){
         for(int j=0; j < 15; j++){
             if(board[i][j] == 1 || board[i][j] == 2 ){
                 current_positions.push_back({i,j});
             }
         }
     }
     cout<<"size of the vecotor is "<<current_positions.size()<<endl;

    return 1;
 }

/*
 * PRECONDITION: Given a 2D array, the color we are playing for, and position we need to change on the board.
 * POSTCONDITION: Changed values on the board
 * DESCRIPTION: Changing teh values on hte board. If it is a black player, it will be represented by 1. 
 *              The white player will be represented by 2. Empty spots remain 0's.
 */ 
void play(int board[15][15], int color, int position[2]){
    //Mark the given position on the board with 1 or 2.
    board[position[0]-1][position[1]-1] = (color == 1) ? 1 : 2;
}



int main(){

    int gameBoard[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}};

    int position[2] = {2,1};
    play(gameBoard, 2, position);
    display(gameBoard);

    int  x = checkBoardStatus(gameBoard);
    
    return 0;
}