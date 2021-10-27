/**
 *  Programmer: Nikola Andric
 *  Last Eddited: 10/27/2021
 *  Email: namdd@umsystem.edu 
 * 
 */

#include<iostream>
#include<vector>
#include<array>
#include <chrono>

using namespace std;
using namespace std::chrono;


/**
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

/**
 * PRECONDITION: Given a 2D array and the position of the last played pebble.
 * POSTCONDITION: Returning if there is a winner in the game. 
 * DESCRIPTION: Checking columns, diagonals, and rows to see if there is 5 pebbles in the row of the same collor starting from
 *              the position of the last pebble placed on the board
 */
int checkBoardStatusPlus(int board[15][15], int last_position[2]){
    int x = last_position[0]-1;
    int y = last_position[1]-1;

    //Checking direction LEFT
    int temp_y = y; //from this position we are looking for 5 consecutive same values
    int count = 0; //count how many consecutive pebbles there are in this direction
    bool winner = false; //keep track if there is a winning state 
    //cout<<"Checking direction LEFT"<<endl;
    while(temp_y>=0  && board[x][temp_y] == board[x][y] ){
        //cout<<"checking position "<< x<<" "<< temp_y <<endl;

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
        //cout<<"returning "<<board[x][y]<<endl;
        return board[x][y];
    }

    //Checking direction RIGHT
    temp_y = y; //from this position we are looking for 5 consecutive same values
    count = 0; //count how many consecutive pebbles there are in this direction
    winner = false; //keep track if there is a winning state 
    //cout<<"Checking direction RIGHT"<<endl;
    while(temp_y<=14  && board[x][temp_y] == board[x][y] ){
        //cout<<"checking position "<< x<<" "<< temp_y <<endl;

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
        temp_y++;
    }
    //return the value of pebble if the winning state is achieved
    if(winner == true){
        //cout<<"returning "<<board[x][y]<<endl;
        return board[x][y];
    }

    //Checking direction UP
        int temp_x = x; //from this position we are looking for 5 consecutive same values
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction UP"<<endl;
        while(temp_x>=0 && board[temp_x][y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< y << " where x is "<< board[temp_x][y] <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x--;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }

        //Checking direction DOWN
        temp_x = x; //from this position we are looking for 5 consecutive same values
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DOWN"<<endl;
        while(temp_x>=0 && board[temp_x][y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< y << " where x is "<< board[temp_x][y] <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x++;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }

        //Checking direction Diagonal UP - LEFT
        temp_x = x; //from this position we are looking for 5 consecutive same values
        temp_y = y;
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DIAGONAL UP - LEFT"<<endl;
        while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][temp_y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x--;
            temp_y--;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }


        //Checking direction Diagonal UP - RIGHT
        temp_x = x; //from this position we are looking for 5 consecutive same values
        temp_y = y;
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DIAGONAL UP - RIGHT"<<endl;
        while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
        //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

        //if the next spot on the board is same as the original one, increment the count
        if (board[temp_x][temp_y] == board[x][y]){
            count++;
        }
        //check if the winning state is achieved
        if(count == 5){
            //cout<<"coonut is 5"<<endl;
            winner = true;
            break;
        }
        
        //move one spot left
        temp_x--;
        temp_y++;
    }
    //return the value of pebble if the winning state is achieved
    if(winner == true){
        //cout<<"returning "<<board[x][y]<<endl;
        return board[x][y];
    }


    //Checking direction Diagonal DOWN - LEFT
    temp_x = x; //from this position we are looking for 5 consecutive same values
    temp_y = y;
    count = 0; //count how many consecutive pebbles there are in this direction
    winner = false; //keep track if there is a winning state 
    //cout<<"Checking direction DIAGONAL DOWN - LEFT"<<endl;
    while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
        //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

        //if the next spot on the board is same as the original one, increment the count
        if (board[temp_x][temp_y] == board[x][y]){
            count++;
        }
        //check if the winning state is achieved
        if(count == 5){
            //cout<<"coonut is 5"<<endl;
            winner = true;
            break;
        }
        
        //move one spot left
        temp_x++;
        temp_y--;
    }
    //return the value of pebble if the winning state is achieved
    if(winner == true){
        //cout<<"returning "<<board[x][y]<<endl;
        return board[x][y];
    }

    //Checking direction Diagonal DOWN - LEFT
    temp_x = x; //from this position we are looking for 5 consecutive same values
    temp_y = y;
    count = 0; //count how many consecutive pebbles there are in this direction
    winner = false; //keep track if there is a winning state 
    //cout<<"Checking direction DIAGONAL DOWN - RIGHT"<<endl;
    while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
        //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

        //if the next spot on the board is same as the original one, increment the count
        if (board[temp_x][temp_y] == board[x][y]){
            count++;
        }
        //check if the winning state is achieved
        if(count == 5){
            //cout<<"coonut is 5"<<endl;
            winner = true;
            break;
        }
        
        //move one spot left
        temp_x++;
        temp_y++;
    }
    //return the value of pebble if the winning state is achieved
    if(winner == true){
        //cout<<"returning "<<board[x][y]<<endl;
        return board[x][y];
    }

    return 0;
}































/**
 * 
 * This function can be deleted...
 * 
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
     //cout<<"size of the vecotor is "<<current_positions.size()<<endl;
     for(int i = 0; i < current_positions.size(); i++){
         
        int x = current_positions.at(i)[0];
        int y = current_positions.at(i)[1];

        //Checking direction LEFT
        int temp_y = y; //from this position we are looking for 5 consecutive same values
        int count = 0; //count how many consecutive pebbles there are in this direction
        bool winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction LEFT"<<endl;
        while(temp_y>=0  && board[x][temp_y] == board[x][y] ){
            //cout<<"checking position "<< x<<" "<< temp_y <<endl;

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
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }


        //Checking direction RIGHT
        temp_y = y; //from this position we are looking for 5 consecutive same values
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction RIGHT"<<endl;
        while(temp_y<=14  && board[x][temp_y] == board[x][y] ){
            //cout<<"checking position "<< x<<" "<< temp_y <<endl;

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
            temp_y++;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }

        //Checking direction UP
        int temp_x = x; //from this position we are looking for 5 consecutive same values
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction UP"<<endl;
        while(temp_x>=0 && board[temp_x][y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< y << " where x is "<< board[temp_x][y] <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x--;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }

        //Checking direction DOWN
        temp_x = x; //from this position we are looking for 5 consecutive same values
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DOWN"<<endl;
        while(temp_x>=0 && board[temp_x][y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< y << " where x is "<< board[temp_x][y] <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x++;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }

        //Checking direction Diagonal UP - LEFT
        temp_x = x; //from this position we are looking for 5 consecutive same values
        temp_y = y;
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DIAGONAL UP - LEFT"<<endl;
        while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][temp_y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x--;
            temp_y--;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }


        //Checking direction Diagonal UP - RIGHT
        temp_x = x; //from this position we are looking for 5 consecutive same values
        temp_y = y;
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DIAGONAL UP - RIGHT"<<endl;
        while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][temp_y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x--;
            temp_y++;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }


        //Checking direction Diagonal DOWN - LEFT
        temp_x = x; //from this position we are looking for 5 consecutive same values
        temp_y = y;
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DIAGONAL DOWN - LEFT"<<endl;
        while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][temp_y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x++;
            temp_y--;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }

        //Checking direction Diagonal DOWN - LEFT
        temp_x = x; //from this position we are looking for 5 consecutive same values
        temp_y = y;
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction DIAGONAL DOWN - RIGHT"<<endl;
        while(temp_x>=0 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
            //cout<<"checking position "<< temp_x<<" "<< temp_y <<endl;

            //if the next spot on the board is same as the original one, increment the count
            if (board[temp_x][temp_y] == board[x][y]){
                count++;
            }
            //check if the winning state is achieved
            if(count == 5){
                //cout<<"coonut is 5"<<endl;
                winner = true;
                break;
            }
            
            //move one spot left
            temp_x++;
            temp_y++;
        }
        //return the value of pebble if the winning state is achieved
        if(winner == true){
            //cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }




     }


    return 0;
 }

/**
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
    //play(gameBoard, 2, position5);

    int position6[2] = {13,9};
    int position7[2] = {12,8};
    int position8[2] = {11,7};
    int position9[2] = {10,6};
    int position10[2] = {9,5};

    play(gameBoard, 1, position6);
    play(gameBoard, 1, position7);
    play(gameBoard, 1, position8);
    play(gameBoard, 1, position9);
    play(gameBoard, 1, position10);

    display(gameBoard);

    int last_pos[2] = {9,5};

    // Get starting timepoint
    auto start = high_resolution_clock::now();

    int  x = checkBoardStatusPlus(gameBoard,last_pos);
    // int  x = checkBoardStatus(gameBoard);

    // Get ending timepoint
    auto stop = high_resolution_clock::now();

    // Get duration. Substart timepoints to 
    // get durarion. To cast it to proper unit
    // use duration cast method
    auto duration = duration_cast<microseconds>(stop - start);

    cout<<"The winner of the game is: "<<x<< " and the< duration of the function is: " << duration.count() <<" microsecunds."<<endl;
    
    return 0;
}