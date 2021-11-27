#include<iostream>
#include<vector>
#include<array>
#include<algorithm> // for copy() and copy_n()

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
        //cout<<"Checking direction LEFT"<<endl;
        while(temp_y>=0){
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
            cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }


        //Checking direction RIGHT
        temp_y = y; //from this position we are looking for 5 consecutive same values
        count = 0; //count how many consecutive pebbles there are in this direction
        winner = false; //keep track if there is a winning state 
        //cout<<"Checking direction RIGHT"<<endl;
        while(temp_y<=14){
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
            cout<<"returning "<<board[x][y]<<endl;
            return board[x][y];
        }




     }


    return 0;
 }

/**
 * PRECONDITION: Given a 2D array, the color we are playing for, and position we need to change on the board.
 * POSTCONDITION: Changed values on the board
 * DESCRIPTION: Changing the values on hte board. If it is a black player, it will be represented by 1. 
 *              The white player will be represented by 2. Empty spots remain 0's.
 */ 
void play(int board[15][15], int color, int position[2]){
    //Mark the given position on the board with 1 or 2.
    board[position[0]-1][position[1]-1] = (color == 1) ? 1 : 2;
}




















/**
 * DESCTIPTION: Class that represents a node in the Monte Carlo Search Tree.  
 *              - Total simulation reward is an attribute of a node v and in a simplest 
 *                  form is a sum of simulation results that passed through considered node.
 *              - Total number of visits is another attribute of a node v representing a counter of how many times 
 *                  a node has been on the backpropagation path (and so how many times it contributed to the total 
 *                  simulation reward)
 * 
 *              In other words, if you look at random node’s statistics these two values will reflect how promising 
 *              the node is (total simulation reward) and how intensively explored it has been (number of visits). 
 *              Nodes with high reward are good candidates to follow (exploitation) but those with low amount of visits may 
 *              be interesting too (because they are not explored well)
 */
class board_state_node{
    private:
        int game_state[15][15]; //State of the board 
        int pebble_color = 0;
        int total_simulation_reward = 0;
        int total_num_visits = 0;
        board_state_node * parent= NULL;
        vector<board_state_node*> children; //list of children

    public:
        

        //default constructor
        board_state_node(){

        }

        //constructor
        board_state_node(int game_board[15][15], board_state_node * predecessor, int color){
            //Deep copy the state
            for(int i = 0; i < 15; i++){
                for(int k = 0; k < 15; k++){
                    game_state[i][k] = game_board[i][k];
                }
            }
            //copy(&game_board[0][0],&game_board[0][0]+15*15,&game_state[0][0]);
            parent = predecessor;  
            pebble_color = color;          
        }


        //function that checks if a node has parent or not
        bool has_parent(){
            return parent != NULL;
        }

        //check if node has children (leaf or not)
        bool has_children(){
            return !children.empty();
        }

        // //Create children of the node for every possible move
        void create_children(board_state_node* node){
            for(int i = 0; i < 15; i++){
                for(int k =0; k<15 ; k++){
                    //if the position on the board is empty then add a child
                    if(game_state[i][k] == 0){
                        int new_state[15][15]; 
                        //perform a deep copy to a new state
                        copy(&node->game_state[0][0],&node->game_state[0][0]+15*15,&new_state[0][0]);
                        //place new number to that state based on what player you are
                        new_state[i][k] = pebble_color;
                        //create node with that state
                        board_state_node *parent = node; //current node is going to be the parent
                        board_state_node child = board_state_node(new_state, parent, pebble_color); //create a new node
                        board_state_node *point_to_child = &child; //create pointer to that node

                        //add the node to the children list
                        node->children.push_back(point_to_child);
                    } 
                }
            }
        }

        void print_node(){
            display(game_state);
            if (has_parent()){
                cout<<"This node has a parent."<<endl<<endl;
            }else{
                cout<<"This node does not have a parent."<<endl<<endl;
            } 
            if(children.size()>0){
                cout<<"This node has "<<children.size()<<" children."<<endl;
            }else{
                cout<<"This node has no children."<<endl;
            }
        }

};

class MonteCarloTree{
    private:
        board_state_node root;
        board_state_node current;


    public:
        // MonteCarloTree(int state[15][15]){
        //     root = board_state_node(state, NULL);
        // }

        // board_state_node MonteCarloTreeSearch(int state[15][15]){

        // }
};


/*
 * PRECONDITION: Given a 2D array, the color we are playing for, and position array that is going to hold the best position to make a move for the given color.
 * POSTCONDITION: Found the best position to place the stone. 
 * DESCRIPTION: Using Monte Carlo Tree Search to find hte best possible position to place the stone of the given color player, and returning the intiger array that 
 *              represents the best position. 
 */ 
// int search(int board[15][15], int color, int position[2]){
    
//     //initialize root as current board state
//     board_state_node root = board_state_node(board, NULL);
// }


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

    
    board_state_node* root = new board_state_node(gameBoard, NULL, 1);
    root->create_children(root);
    root->print_node();
   
    int gameBoard2[15][15] = {{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,1}};

    board_state_node*  node1 = new board_state_node(gameBoard2, root,2);
    node1->create_children(node1);
    node1->print_node();
    

    

    // int position[2] = {2,1};
    // int position2[2] = {2,2};
    // int position3[2] = {2,3};
    // int position4[2] = {2,4};
    // int position5[2] = {2,5};

    // play(gameBoard, 2, position);
    // play(gameBoard, 2, position2);
    // play(gameBoard, 2, position3);
    // play(gameBoard, 2, position4);
    // //play(gameBoard, 2, position5);

    // int position6[2] = {9,5};
    // int position7[2] = {9,6};
    // int position8[2] = {9,7};
    // int position9[2] = {9,8};
    // int position10[2] = {9,9};

    // play(gameBoard, 1, position6);
    // play(gameBoard, 1, position7);
    // play(gameBoard, 1, position8);
    // play(gameBoard, 1, position9);
    // play(gameBoard, 1, position10);

    // display(gameBoard);

    // int  x = checkBoardStatus(gameBoard);

    // cout<<x<<endl;
    
    return 0;
}