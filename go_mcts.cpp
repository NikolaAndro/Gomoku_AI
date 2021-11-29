#include<iostream>
#include<vector>
#include<array>
#include<algorithm> // for copy() and copy_n()
#include<time.h>
#include <cmath>
#include <bits/stdc++.h>
#include <typeinfo>

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
            cout << board[i][j] << "----"; 
        }
    cout<<endl<<"       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | "<<endl;
    }        
}

// void display(int* board[15]){
//     //Printing the indices on the top of the grid
//     cout<<"       ";
//     for(int i = 1; i <= 15; i++){
//         if(i < 9){
//             cout << i << "    ";
//         }else{
//             cout<<  i << "   ";
//         }  
//     }
//     cout<<endl<<endl;
//     ///Printing the grid
//     //cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
//     cout<<endl<<"       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | "<<endl;
//     for(int i=0; i < 15; i++){
//         if(i+1 < 10){
//             cout<<i+1<<"    --";
//         }else{
//             cout<<i+1<<"   --";
//         }
//         for(int j = 0; j < 15; j++){
//             cout << board[i][j] << "----"; 
//         }
//     cout<<endl<<"       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | "<<endl;
//     }        
// }

/*
 * PRECONDITION: Given a 2D array.
 * POSTCONDITION: Returning if there is a winner in the game. 
 * DESCRIPTION: Checking columns, diagonals, and rows to see if there is 5 pebbles in the row of the same collor.
 *              For each position chech all 8 directions. This can be optimized, but will not make much difference in teh runtime. 
 *              We want to check each position for 8 directions before we move onto another position because the value of our current
 *              position is already on the cache memory. Otherwise, if we checked for 1 direction everyy point, then for another direction 
 *              each point, computer would have to spend time accessing the value of the same point in cache 8 times...
 *              Also, we will first check where are the pebbles on the board. That will take 1 iteration, which is better then checking each
 *              spot for 8 directions. 
 *              Returning the value of the winning pebble in case of the win or 0 in case when nobody wins.
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
    //  cout<<"size of the vecotor is "<<current_positions.size()<<endl;
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
            // cout<<"returning "<<board[x][y]<<endl;
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
        // int game_state[15][15]; //State of the board 
        // int** game_state = new int*[15];

        int pebble_color = 0;
        double total_simulation_reward = 0;
        int total_num_visits = 0;
        board_state_node * parent= NULL;
        vector<board_state_node*> children; //list of children

    public:
        int game_state[15][15]; //State of the board 
        
        //getters
        vector<board_state_node*>& get_children(){return children;}
        int get_visits(){return total_num_visits;}
        double get_reward(){return total_simulation_reward;}
        board_state_node* &get_parent(){return parent;}
        int get_pebble_color(){return pebble_color;}
        // int** get_state(){return game_state;}

        //setters
        void set_visits(int num_visits){total_num_visits = num_visits;}
        void set_reward(double value){total_simulation_reward = value;}
        void push_back_child(board_state_node* child){
            children.push_back(child);
        }
        


        //default constructor
        board_state_node(){
            // for(int i = 0; i < 15; i++)
            //     game_state[i] = new int[15];
            
            //fill out the grid with zeros
            for(int i = 0; i < 15; i++){
                for(int k = 0; k < 15; k++){
                    game_state[i][k] = 0;
                }
            }
        }

        //constructor
        board_state_node(int game_board[15][15], board_state_node * predecessor, int color){
            //create the original game state
            // for(int i = 0; i < 15; i++)
            //     game_state[i] = new int[15];

            // copy the passed board state to the blank board state.    
            copy(&game_board[0][0],&game_board[0][0]+15*15,&game_state[0][0]);
            parent = predecessor;  
            pebble_color = color;          
        }


        //destructor;
        ~board_state_node(){
            for(vector<board_state_node*>::iterator it = children.begin(); it != children.end();it++){
                delete *it;
            }
            
            // //delete the game state pointers
            // for(int i = 0 ; i < 15; i++)
            //     delete[] game_state[i];
            // delete[] game_state;

        }



        //function that checks if a node has parent or not
        bool has_parent(){
            return parent != NULL;
        }

        //check if node has children (leaf or not)
        bool has_children(){
            return !children.empty();
        }

        // // //Create children of the node for every possible move
        // void create_children(board_state_node* node){
        //     for(int i = 0; i < 15; i++){
        //         for(int k =0; k<15 ; k++){
        //             //if the position on the board is empty then add a child
        //             if(game_state[i][k] == 0){
        //                 int new_state[15][15]; 
        //                 //perform a deep copy to a new state
        //                 copy(&node->game_state[0][0],&node->game_state[0][0]+15*15,&new_state[0][0]);
        //                 // cout<<"BEFORE adding hte pebble:"<<endl;
        //                 // display(new_state);
        //                 //place new number to that state based on what player you are
        //                 new_state[i][k] = pebble_color;

        //                 // cout<<"AFTER adding hte pebble:"<<endl;
        //                 // display(new_state);
        //                 //create node with that state
        //                 board_state_node *parent = node; //current node is going to be the parent
        //                 board_state_node *point_to_child = new board_state_node(new_state, parent, pebble_color);
        //                 // cout<<"POINTER SHOWS:"<<endl;
        //                 // display(point_to_child->game_state);
                        
        //                 //add the node to the children list
        //                 node->children.push_back(point_to_child);
        //             } 
        //         }
        //     }
        // }











        // // picking what child we are going to explore based on child's Upper Confidence Bound (UCB)
        // //node that is being passed is the initial state
        // board_state_node* traverse(board_state_node* node){
            
        //     //if there are children, calculate UCB for each child and choose the child with maximum UCB
        //     //we keep doing this until we hit the leaf node that has no children
        //     while(node->children.size() > 0){
        //         double best_UCB = 0;
        //         double UCB = 0;
        //         board_state_node* best_node = node; 

        //         //calculate UCB for every child and remember the best one
        //         for(int i = 0; i < node->children.size(); i++){
        //             //if child has been visited before, calculate UCB using formula
        //             //otherwise UCB is 1.
        //             board_state_node* child = node->children.at(i);
        //             if(child->total_num_visits != 0)
        //                 UCB = child->total_simulation_reward/child->total_num_visits + 2 * sqrt(log(child->total_num_visits)/child->total_num_visits);
        //             else
        //                 UCB = 1;
        //             //update if a better UCB is found
        //             if(UCB >= best_UCB){
        //                 best_UCB = UCB;
        //                 best_node = child;
        //             }
        //         }
        //         //we are going deeper by setting the node to be the child with the best UCB
        //         node = best_node;
        //     }
        //     //at this point we got the to a leaf node and we need to expand
        //     if(!node->has_children()){
        //         //if the node has never been sampled/visited, then simply rollout from there.
        //         //otherwise, for each available action, add a new state to the tree
        //         if(node->total_num_visits == 0)
        //             return node;
        //         else{
        //             //check if the game is ended
        //             if(checkBoardStatus(node->game_state) != 0){
        //                 return node;
        //             }

        //             //create children for this node
        //             create_children(node);

        //             //randomly choose a child for the rollout
        //             node = rollout_policy(node);

        //             return node;
        //         }
        //     }
        // }











        // //function that is going to show the result of the simulation
        // int rollout(board_state_node* node){
        //     // board_state_node temp_node = board_state_node(node->game_state,NULL, node->pebble_color);
        //     board_state_node* point_to_temp_node = new board_state_node(node->game_state,NULL, node->pebble_color);

        //     while(checkBoardStatus(point_to_temp_node->game_state) < 1){
        //         if(point_to_temp_node->children.size() == 0)
        //             create_children(point_to_temp_node);
                
        //         //pick a random child
        //         point_to_temp_node = rollout_policy(point_to_temp_node);
        //     }
        //     //returning the winning pebble or 0 if there is no winner
        //     return checkBoardStatus(point_to_temp_node->game_state);
        // }












        // //returning the child with the most visits
        // board_state_node* best_child(board_state_node* node){
        //     int most_visits = 0; //keeping trach of the most visits any child has
        //     board_state_node* the_best_child = NULL; // keeping track of the child with the most visits
         

        //     // vector<board_state_node*>::iterator it;
        //     // for(it = node->children.begin(); it != node->children.end();it++){
        //     //     if((*it)->total_num_visits> most_visits ){
        //     //         most_visits = (*it)->total_num_visits;
        //     //         the_best_child = (*it);
        //     //     }
        //     // }
        //     // iterating over each child to see which one has the most visits
        //     for(int i =0; i<node->children.size(); i++){
        //         // cout<<i<<endl;
        //         if(node->children.at(i)->total_num_visits >= most_visits){
        //             most_visits = node->children.at(i)->total_num_visits;
        //             the_best_child = node->children.at(i);
        //         }
        //     }
            

        //     return the_best_child;
        // }







        // //function according to which the next move is chosen
        // //randomly picking a child
        // board_state_node* rollout_policy(board_state_node* node){
        //     return node->children.at(rand()%node->children.size());
        // }



        // //backpropagation function
        // void backpropagate(board_state_node* node, double result){
        //     //update the score and the number of visits on each node on this path
        //     node->total_simulation_reward += result;
        //     node->total_num_visits += 1;
        //     //if we hit the root that does not have parent, then we stop.
        //     if(!node->parent)
        //         return;
        //     //backpropagate up the tree
        //     backpropagate(node->parent, -result);
        // }



        // //Monte Carlo Tree Search Function



        
        void print_node(){
            display(game_state);
            // if (has_parent()){
            //     cout<<"This node has a parent."<<endl<<endl;
            // }else{
            //     cout<<"This node does not have a parent."<<endl<<endl;
            // } 
            // if(children.size()>0){
            //     cout<<"This node has "<<children.size()<<" children."<<endl;
            //     board_state_node* test = best_child(node);
            //     display(test->game_state);
            //     cout<<"The best child has " << best_child(node)->get_visits()<<" visits."<<endl;
            //     display(best_child(node)->game_state);
            // }else{
            //     cout<<"This node has no children."<<endl;
            // }
            // cout<<"\n type of game state  is: "<<  typeid(game_state).name(); 
            // display(node->children.at(244)->game_state);
            
        }

};

class MonteCarloTree{
    private:
        board_state_node* root;
        board_state_node* current;
        int pebble_color;


    public:
        MonteCarloTree(int state[15][15], int pebble_color){
            root = new board_state_node(state, NULL, pebble_color);
            current = root;
        }
        //getters
        board_state_node* get_root(){return root;}
        board_state_node* get_current(){return current;}

        void print_current_state(){
            display(current->game_state);
        }

        // //Create children of the node for every possible move
        void create_children(board_state_node* node){
            for(int i = 0; i < 15; i++){
                for(int k =0; k<15 ; k++){
                    //if the position on the board is empty then add a child
                    if(node->game_state[i][k] == 0){
                        // int** new_state = new int*[15]; 
                        // //create the original game state
                        // for(int i = 0; i < 15; i++)
                        //     new_state[i] = new int[15];
                        int new_state[15][15];

                        //perform a deep copy to a new state
                        copy(&node->game_state[0][0],&node->game_state[0][0]+15*15,&new_state[0][0]);
                        // cout<<"BEFORE adding hte pebble:"<<endl;
                        // display(new_state);
                        //place new number to that state based on what player you are
                        new_state[i][k] = pebble_color;

                        // cout<<"AFTER adding hte pebble:"<<endl;
                        // display(new_state);
                        //create node with that state
                        board_state_node *parent = node; //current node is going to be the parent
                        board_state_node *point_to_child = new board_state_node(new_state, parent, pebble_color);
                        // cout<<"POINTER SHOWS:"<<endl;
                        // display(point_to_child->game_state);
                        
                        //add the node to the children list
                        node->push_back_child(point_to_child);
                    } 
                }
            }
        }





        //function according to which the next move is chosen
        //randomly picking a child
        board_state_node* rollout_policy(board_state_node* node){
            return node->get_children().at(rand()%node->get_children().size());
        }





        // picking what child we are going to explore based on child's Upper Confidence Bound (UCB)
        //node that is being passed is the initial state
        board_state_node* traverse(board_state_node* node){
            
            //if there are children, calculate UCB for each child and choose the child with maximum UCB
            //we keep doing this until we hit the leaf node that has no children
            while(node->get_children().size() > 0){
                double best_UCB = 0;
                double UCB = 0;
                board_state_node* best_node = node; 

                //calculate UCB for every child and remember the best one
                for(int i = 0; i < node->get_children().size(); i++){
                    //if child has been visited before, calculate UCB using formula
                    //otherwise UCB is 1.
                    board_state_node* child = node->get_children().at(i);
                    if(child->get_visits() != 0)
                        UCB = child->get_reward()/child->get_visits() + 2 * sqrt(log(child->get_visits())/child->get_visits());
                    else
                        UCB = 1;
                    //update if a better UCB is found
                    if(UCB >= best_UCB){
                        best_UCB = UCB;
                        best_node = child;
                    }
                }
                //we are going deeper by setting the node to be the child with the best UCB
                node = best_node;
            }
            //at this point we got the to a leaf node and we need to expand
            if(!node->has_children()){
                //if the node has never been sampled/visited, then simply rollout from there.
                //otherwise, for each available action, add a new state to the tree
                if(node->get_visits() == 0)
                    return node;
                else{
                    //check if the game is ended
                    if(checkBoardStatus(node->game_state) != 0){
                        return node;
                    }

                    //create children for this node
                    create_children(node);

                    //randomly choose a child for the rollout
                    node = rollout_policy(node);

                    return node;
                }
            }
        }











        //function that is going to show the result of the simulation
        int rollout(board_state_node* node){
            // board_state_node temp_node = board_state_node(node->game_state,NULL, node->pebble_color);
            board_state_node* point_to_temp_node = new board_state_node(node->game_state,NULL, node->get_pebble_color());

            while(checkBoardStatus(point_to_temp_node->game_state) < 1){
                if(point_to_temp_node->get_children().size() == 0)
                    create_children(point_to_temp_node);
                
                //pick a random child
                point_to_temp_node = rollout_policy(point_to_temp_node);
            }
            //returning the winning pebble or 0 if there is no winner
            return checkBoardStatus(point_to_temp_node->game_state);
        }












        //returning the child with the most visits
        board_state_node* best_child(board_state_node* node){
            int most_visits = 0; //keeping trach of the most visits any child has
            board_state_node* the_best_child = NULL; // keeping track of the child with the most visits
         

            // vector<board_state_node*>::iterator it;
            // for(it = node->children.begin(); it != node->children.end();it++){
            //     if((*it)->total_num_visits> most_visits ){
            //         most_visits = (*it)->total_num_visits;
            //         the_best_child = (*it);
            //     }
            // }
            // iterating over each child to see which one has the most visits
            for(int i =0; i<node->get_children().size(); i++){
                // cout<<i<<endl;
                if(node->get_children().at(i)->get_visits() >= most_visits){
                    most_visits = node->get_children().at(i)->get_visits();
                    the_best_child = node->get_children().at(i);
                }
            }
            

            return the_best_child;
        }







        



        //backpropagation function
        void backpropagate(board_state_node* node, double result){
            //update the score and the number of visits on each node on this path
            node->set_reward(node->get_reward() + result );
            node->set_visits(node->get_visits()+1);
            //if we hit the root that does not have parent, then we stop.
            if(!node->get_parent())
                return;
            //backpropagate up the tree
            backpropagate(node->get_parent(), -result);
        }



        // Monte Carlo Tree Search Function
        board_state_node* monte_carlo_tree_search(int state[15][15]){

            
            for(int i = 0; i < 1000; i++){
                cout<<"yes 1"<<endl;
                board_state_node* leaf = traverse(current);
                cout<<"yes 2"<<endl;
                int simulation_result = rollout(leaf);
                cout<<"yes 3"<<endl;
                backpropagate(leaf,simulation_result);
            }

            current = best_child(current);
            return current;
        }
        // void print_node(board_state_node* node){
        //     display(game_state);
        //     if (node->has_parent()){
        //         cout<<"This node has a parent."<<endl<<endl;
        //     }else{
        //         cout<<"This node does not have a parent."<<endl<<endl;
        //     } 
        //     if(node->get_children().size()>0){
        //         cout<<"This node has "<<node->get_children().size()<<" children."<<endl;
        //         board_state_node* test = best_child(node);
        //         display(test->game_state);
        //         cout<<"The best child has " << best_child(node)->get_visits()<<" visits."<<endl;
        //         display(best_child(node)->game_state);
        //     }else{
        //         cout<<"This node has no children."<<endl;
        //     }
        //     // cout<<"\n type of game state  is: "<<  typeid(game_state).name(); 
        //     // display(node->children.at(244)->game_state);
            
        // }

};


/*
 * PRECONDITION: Given a 2D array, the color we are playing for, and position array that is going to hold the best position to make a move for the given color.
 * POSTCONDITION: Found the best position to place the stone. 
 * DESCRIPTION: Using Monte Carlo Tree Search to find hte best possible position to place the stone of the given color player, and returning the intiger array that 
 *              represents the best position. 
 */ 
int search(int board[15][15], int color, int position[2]){
    
    //initialize root as current board state
    board_state_node root = board_state_node(board, NULL,color);

    //Use Monte Carlo Tree Search on this node
    MonteCarloTree the_tree = MonteCarloTree(root.game_state,color);

    //get the best child
    board_state_node* BEST = the_tree.monte_carlo_tree_search(root.game_state);

    display(BEST->game_state);

    //Return the best position
    return 1;
}


int main(){
    //seeding the random number generator
    srand(time(0));

  
    // MonteCarloTree my_tree = MonteCarloTree(game_board, 1);
    // my_tree.print_current_state();
    // board_state_node* root = new board_state_node(gameBoard, NULL, 1);
    // root->create_children(root);
    // root->print_node(root);
   
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
                             {0,0,0,0,0,0,0,0,0,0,0,0,0,0,2}};

    board_state_node myNode = board_state_node(gameBoard2,NULL,2);
    
    // int position[] = {1,4};
    // play(myNode.game_state,1,position);
    // int position1[] = {1,5};
    // play(myNode.game_state,1,position1);
    // int position2[] = {1,6};
    // play(myNode.game_state,1,position2);
    // int position3[] = {1,7};
    // play(myNode.game_state,1,position3);
    // int position4[] = {1,8};
    // play(myNode.game_state,1,position4);
    // myNode.print_node();
    // // cout<< checkBoardStatus(myNode.game_state)<<endl;

    MonteCarloTree my_tree = MonteCarloTree(gameBoard2,1);
    // display(my_tree.get_root()->game_state );
    my_tree.print_current_state();
    my_tree.create_children(my_tree.get_root());
    // cout<<my_tree.get_root()->get_children().size()<<endl;

    board_state_node* final= my_tree.monte_carlo_tree_search(my_tree.get_current()->game_state);
    display(final->game_state);
    // board_state_node*  node1 = new board_state_node(gameBoard2, root,2);
    // node1->create_children(node1);
    // board_state_node* tester =  node1->get_children().at(3);
    
    
    
    // tester->print_node(tester);
    // tester->set_visits(6);
    // cout<<"tester has "<<tester->get_visits()<<" visits."<<endl;
    // node1->print_node(node1);
    

    

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