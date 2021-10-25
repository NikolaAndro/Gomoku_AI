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
    //Printing the indices on the top of the grid
    cout<<"       ";
    for(int i = 1; i <= 15; i++){
        if(i < 9){
            cout << i << "    ";
        }else{
            cout<<  i << "   ";
        }  
    }
    cout<<endl<<endl;
    ///Printing the grid
    //cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
    cout<<endl<<"       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | "<<endl;
    for(int i=0; i < 15; i++){
        if(i+1 < 10){
            cout<<i+1<<"    --";
        }else{
            cout<<i+1<<"   --";
        }
        for(int j = 0; j < 15; j++){
            if(j+1 < 10){
                cout << board[i][j] << "----";
            }else{
                cout << board[i][j] << "----";
            }  
        }
    cout<<endl<<"       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | "<<endl;
    }        
}

/*
 * PRECONDITION: Given a 2D array.
 * POSTCONDITION: Returning if there is a winner in the game. 
 * DESCRIPTION: Checking columns, diagonals, and rows to see if there is 5 pebbles in the row of the same collor.
 *              For each position chech all 8 directions. This can be optimized, but will not make much difference in teh runtime. 
 *              We want to check each position for 8 directions before we move onto another position because the value of our current
 *              position is already on the cache memory. Otherwise, if we checked for 1 direction everyy point, then for another direction 
 *              each point, computer would have to spend time accessing the value of the same point in cache 8 times...
 *              Also, we will first check where are the pebbles on the board. That will take 1 iteration,, which is better then checking each
 *              spot for 8 directions. 
 */
 int checkBoardStatus(int board[15][15]){
     ///Get all the positions where there is a pebble.
     vector<array<int,2>> current_positions = {};
     for(int i = 0; i < 15; i++){
         for(int j=0; j < 15; j++){
             if(board[i][j] == 1 || board[i][j] == 2 ){
                 current_positions.push_back({i,j});
             }
         }
     }
     cout<<"size of the vecotor is "<<current_positions.size()<<endl;
     for(int i = 0; i < current_positions.size(); i++){
         
        int x = current_positions.at(i)[0];
        int y = current_positions.at(i)[1];

        //Checking direction LEFT
        int temp_y = y; //from this position we are looking for 5 consecutive same values
        int count = 0; //count how many consecutive pebbles there are in this direction
        bool winner = false; //keep track if there is a winning state 
        while(temp_y>=0){
            cout<<"checking position "<< x<<" "<< temp_y <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[x][temp_y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                winner = true;
                break;
            }
            //move one spot left
            temp_y--;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }


        //Check Right 



     }


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
    int position2[2] = {2,2};
    int position3[2] = {2,3};
    int position4[2] = {2,4};
    int position5[2] = {2,5};

    play(gameBoard, 2, position);
    play(gameBoard, 2, position2);
    play(gameBoard, 2, position3);
    play(gameBoard, 2, position4);
    play(gameBoard, 2, position5);
    display(gameBoard);

    int  x = checkBoardStatus(gameBoard);

    cout<<x<<endl;
    
    return 0;
}