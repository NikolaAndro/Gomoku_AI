#include<iostream>
#include<vector>
#include<array>
#include<algorithm> // for copy() and copy_n()
#include<time.h>
#include <cmath>
#include <bits/stdc++.h>
#include <typeinfo>
#include <ctime>
#include <time.h>
#include <memory>

using namespace std;

//creating my own namespace
namespace NAndric{

    /*
    * PRECONDITION: Given a 2D array.
    * POSTCONDITION: Printing the 2D array so it looks like a real board for game of go.
    * DESCRIPTION: Printing the board with indices on left side and on the top. The values are actually index + 1.
    */ 

    void display(int board[15][15]){
        //Printing the indices on the top of the grid
        cout<<"       ";
        for(int i = 0; i <= 14; i++){
            if(i <= 9){
                cout << i << "    ";
            }else{
                cout<<  i << "   ";
            }  
        }
        cout<<endl<<endl;
        ///Printing the grid
        //cout<<endl<<"---------------------------------------------------------------------------------"<<endl;
        cout<<endl<<"       |    |    |    |    |    |    |    |    |    |    |    |    |    |    | "<<endl;
        for(int i=0; i <= 14; i++){
            if(i < 10){
                cout<<i<<"    --";
            }else{
                cout<<i<<"   --";
            }
            for(int j = 0; j <= 14; j++){
                cout << board[i][j] << "----"; 
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
int checkBoardStatus(int board[15][15], int last_position[2]){
    int x = last_position[0];
    int y = last_position[1];

    if(last_position[0] < 0 || last_position[0]>14 || last_position[1]<0 ||last_position[1]>14)
        return 0;
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
        while(temp_x<=14 && board[temp_x][y] == board[x][y] ){
            // cout<<"checking position "<< temp_x<<" "<< y << " where x is "<< board[temp_x][y] <<endl;

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
            
            
            //move one spot down
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
        while(temp_x>=0 && temp_y<=14 && board[temp_x][temp_y] == board[x][y] ){
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
    while(temp_x<=14 && temp_y>=0 && board[temp_x][temp_y] == board[x][y] ){
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

    //Checking direction Diagonal DOWN - RIGHT
    temp_x = x; //from this position we are looking for 5 consecutive same values
    temp_y = y;
    count = 0; //count how many consecutive pebbles there are in this direction
    winner = false; //keep track if there is a winning state 
    //cout<<"Checking direction DIAGONAL DOWN - RIGHT"<<endl;
    while(temp_x<=14 && temp_y<=14 && board[temp_x][temp_y] == board[x][y] ){
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
     * PRECONDITION: Given a 2D array, the color we are playing for, and position we need to change on the board.
     * POSTCONDITION: Changed values on the board
     * DESCRIPTION: Changing the values on hte board. If it is a black player, it will be represented by 1. 
     *              The white player will be represented by 2. Empty spots remain 0's.
     */ 
    void play(int board[15][15], int color, int position[2]){
        //Mark the given position on the board with 1 or 2.
        board[position[0]][position[1]] = (color == 1) ? 1 : 2;
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

            // int pebble_color = 0;
            double total_simulation_reward = 0;
            int total_num_visits = 0;
            shared_ptr<board_state_node> parent= NULL;
            vector<shared_ptr<board_state_node>> children; //list of children (list of shared vectors)
            
        public:
            int game_state[15][15]={{0,0,0},{0,0,0},{0,0,0}}; //State of the board 
            int last_position_played[2]={-1,-1}; //x and y coordinates of the last position played
            
            //getters
            vector<shared_ptr<board_state_node>>& get_children(){return children;}
            int get_visits(){return total_num_visits;}
            double get_reward(){return total_simulation_reward;}
            shared_ptr<board_state_node> &get_parent(){return parent;}
            // int get_pebble_color(){return pebble_color;}
            // int** get_state(){return game_state;}

            //setters
            void set_visits(int num_visits){total_num_visits = num_visits;}
            void set_reward(double value){total_simulation_reward = value;}
            void push_back_child(shared_ptr<board_state_node> child){
                children.push_back(child);
            }
            void set_last_position(int position[2]){
                last_position_played[0] = position[0];
                last_position_played[1]=position[1];
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
            board_state_node(int game_board[15][15], shared_ptr<board_state_node> predecessor){
                // copy the passed board state to the blank board state.    
                copy(&game_board[0][0],&game_board[0][0]+15*15,&game_state[0][0]);
                parent = predecessor;  
                // pebble_color = color;          
            }

            //destructor;
            virtual ~board_state_node(){
                // for(vector<board_state_node*>::iterator it = children.begin(); it != children.end();it++){
                //     delete *it;
                // }
                
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
            
            void print_node(){
                display(game_state);
            }

    };






















    class MonteCarloTree{
        private:
            shared_ptr<board_state_node> root;
            shared_ptr<board_state_node> current;
            int pebble_color;
            bool user_turn = true;

        public:
            MonteCarloTree(int state[15][15], int color){
                root = make_shared<board_state_node>(board_state_node(state, NULL)); 
                current = root;
                pebble_color = color;
            }
            //getters
            shared_ptr<board_state_node> get_root(){return root;}
            shared_ptr<board_state_node> get_current(){return current;}

            void print_current_state(){
                display(current->game_state);
            }

            // //Create children of the node for every possible move
            void create_children(shared_ptr<board_state_node> node){
                for(int i = 0; i < 15; i++){
                    for(int k =0; k<15 ; k++){
                        //if the position on the board is empty then add a child
                        if(node->game_state[i][k] == 0){
                            int new_state[15][15];

                            //perform a deep copy to a new state
                            copy(&node->game_state[0][0],&node->game_state[0][0]+15*15,&new_state[0][0]);
                            
                            //place new number to that state based on what player you are
                            new_state[i][k] = pebble_color;


                            //create node with that state
                            shared_ptr<board_state_node> parent = node; //current node is going to be the parent
                            // board_state_node *point_to_child = new board_state_node(new_state, parent);
                            shared_ptr<board_state_node> point_to_child = make_shared<board_state_node>(board_state_node(new_state, parent)) ;
                            
                            //remember the position played
                            int last_pos[2]={i,k};
                            
                            point_to_child->set_last_position(last_pos);

                            //add the node to the children list
                            node->push_back_child(point_to_child);
                        } 
                    }
                }
            }

            //function according to which the next move is chosen
            //randomly picking a child
            shared_ptr<board_state_node> rollout_policy(shared_ptr<board_state_node> node){
                return node->get_children().at(rand()%node->get_children().size());
            }

            // picking what child we are going to explore based on child's Upper Confidence Bound (UCB)
            //node that is being passed is the initial state
            shared_ptr<board_state_node> traverse(shared_ptr<board_state_node> node){
                //if there are children, calculate UCB for each child and choose the child with maximum UCB
                //we keep doing this until we hit the leaf node that has no children
                while(node->get_children().size() > 0){
                    double best_UCB = 0;
                    double UCB = 0;
                    shared_ptr<board_state_node> best_node = node; 

                    //calculate UCB for every child and remember the best one
                    for(int i = 0; i < node->get_children().size(); i++){
                        //if child has been visited before, calculate UCB using formula
                        //otherwise UCB is 1.
                        shared_ptr<board_state_node> child = node->get_children().at(i);
                        if(child->get_visits() != 0)
                            UCB = child->get_reward()/child->get_visits() + sqrt(2) * sqrt(log(child->get_visits())/child->get_visits());
                        else
                            UCB = 1;
                        //update if a better UCB is found
                        if(UCB >= best_UCB){//****************************************************************************************************************************zbog ovog = znaka uzima poslednjeg u donjem desnom cosku
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
                        if(checkBoardStatus(node->game_state, node->last_position_played) != 0){
                            return node;
                        }
                        //create children for this node
                        create_children(node);

                        //randomly choose a child for the rollout
                        node = rollout_policy(node);
                        // turn = !turn;
                        return node;
                    }
                }
            }

            //function that is going to show the result of the simulation
            int rollout(shared_ptr<board_state_node> node){
                // board_state_node temp_node = board_state_node(node->game_state,NULL, node->pebble_color);
                //keep temporary shared pointer
                shared_ptr<board_state_node> point_to_temp_node = make_shared<board_state_node>(board_state_node(node->game_state,NULL));
                
                //Loop until the game has a winner
                while(checkBoardStatus(point_to_temp_node->game_state, point_to_temp_node->last_position_played) < 1){
                    //if node does not have children, then create children for that node and dig deeper into the tree
                    if(point_to_temp_node->get_children().size() == 0)
                        create_children(point_to_temp_node);                
                    //pick a random child from  the created children to go deeper. 
                    point_to_temp_node = rollout_policy(point_to_temp_node);
                }
                
                //returning the winning pebble or 0 if there is no winner
                return checkBoardStatus(point_to_temp_node->game_state, point_to_temp_node->last_position_played);
            }

            //returning the child with the most visits
            shared_ptr<board_state_node> best_child(shared_ptr<board_state_node> node){
                int most_visits = 0; //keeping trach of the most visits any child has
                shared_ptr<board_state_node> the_best_child = NULL; // keeping track of the child with the most visits
            
                // iterating over each child to see which one has the most visits
                for(int i =0; i<node->get_children().size(); i++){
                    // cout<<i<<endl;
                    if(node->get_children().at(i)->get_visits() > most_visits){
                        most_visits = node->get_children().at(i)->get_visits();
                        the_best_child = node->get_children().at(i);    
                    }
                }
                return the_best_child;
            }

            //backpropagation function
            void backpropagate(shared_ptr<board_state_node> node, double result){
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
            shared_ptr<board_state_node> monte_carlo_tree_search(int state[15][15]){

                //3 seconds should be limitation
                time_t start = time(0);
                int iter = 0;
                while(difftime(time(0), start) < 3){ 
                    iter++;  
                // for(int i = 0; i < 100; i++){
                    //  Traverse to the bottom of the tree and expand the leaf node if has not been visited
                    shared_ptr<board_state_node> leaf = traverse(current);
                    // play a simulation from that node.
                    int simulation_result = rollout(leaf);
                    // cout<<"yes 3"<<endl;
                    backpropagate(leaf,simulation_result);
                    
                }

                current = best_child(current);
                return current;
            }
    };


    /*
    * PRECONDITION: Given a 2D array, the color we are playing for, and position array that is going to hold the best position to make a move for the given color.
    * POSTCONDITION: Found the best position to place the stone. 
    * DESCRIPTION: Using Monte Carlo Tree Search to find hte best possible position to place the stone of the given color player, and returning the intiger array that 
    *              represents the best position. 
    */ 
    void search(int board[15][15], int color, int position[2]){
        
        //initialize root as current board state
        board_state_node root = board_state_node(board, NULL);

        //Use Monte Carlo Tree Search on this node
        MonteCarloTree the_tree = MonteCarloTree(root.game_state, color);
        
        //get the best child
        shared_ptr<board_state_node> BEST = the_tree.monte_carlo_tree_search(root.game_state);


        // display(BEST->game_state);
        cout<<"The best position chosen by AI is: "<<BEST->last_position_played[0]<<" "<<BEST->last_position_played[1]<<endl;

        //update the position parameter with the last positoin chosen by AI
        position[0] = BEST->last_position_played[0];
        position[1] = BEST->last_position_played[1];

        return;
    }

    void human_vs_AI(){
        int user_pebble, AI_pebble;
        //ask user for the color of pebble he/she wants to use
        cout<<"Please enter the number for the color you want to play with:"<<endl<<"1 - black"<<endl<<"2 - white"<<endl<<"Your number is:";
        cin>>user_pebble;
        //get AI pebble
        if(user_pebble == 1)
            AI_pebble = 2;
        else
            AI_pebble = 1;

        //initial state

        int state[15][15] ={{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
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

        //human will have the value 2, AI will play with value 1.
        MonteCarloTree my_tree = MonteCarloTree(state,0);
        // bool game_ended = false; //used to see if we have winner or not or if game just ended with draw.

        int row, col; // row and column that human will  play
        int AI_position[2]= {-1,-1};
        int user_last_position[2]= {-1,-1};
        //play the game until there is a winner or draw;
        while(true){

            //if user has a white pebble then AI plays first
            if(user_pebble == 2){
                //let AI play and save the best its choice in the AI_position list
                search(state,AI_pebble,AI_position);
                // cout<<"Before passoing the AI position to play function position is: "<< AI_position[0]<<" "<<AI_position[1]<<endl;
                
                //play with those positions
                play(state, AI_pebble, AI_position);
            }
            // board_state_node* temp = my_tree.monte_carlo_tree_search(state)->game_state;
            //get the game state to be the copy of the game state after mcts
            // copy(&my_tree.monte_carlo_tree_search(state)->game_state[0][0],&my_tree.monte_carlo_tree_search(state)->game_state[0][0]+15*15,&state[0][0]);
    
            //check if there is a winner
            //Check if the game is over!
            if(checkBoardStatus(state, AI_position)== AI_pebble){
                cout<<"/n/n The winner is AI !/n/n"<<endl<<endl;
                display(state);
                break;
            }
            // else if (checkBoardStatus(state) == user_pebble){
            //     cout<<"The winner is human !"<<endl<<endl;
            //     display(state);
            //     break;
            // }

            //User's turn to play
            while(true){
                display(state);
                cout<<endl<<endl<<"Make your move!"<<endl<<endl;

                //Ask user for the row and column values until the user inputs valid values.
                while(true){
                    try{
                        cout<<"Enter row [0-14]: ";
                        cin >> row;
                        if(row >= 0 && row <= 14)
                            break;
                        else    
                            throw(row);
                    }
                    catch (int row_num){
                        cout<<"NOTE:  The row value should be in range 0-14 inclusive.";
                    } 
                }
                while(true){
                    try{
                        cout<<"Enter column [0-14]: ";
                        cin >> col;
                        if(col >= 0 && col <= 14)
                            break;
                        else    
                            throw(col);
                    }
                    catch (int col_num){
                        cout<<"NOTE:  The column value should be in range 0-14 inclusive.";
                    } 
                }

                //if the position desired is free, place user pebble on that position.
                int human_position[2] = {row,col};
                if (state[row][col] == 0){
                    play(state,user_pebble,human_position);
                    break;
                }else{
                    cout<<"The position is already taken! Try again!"<<endl;
                }
            }
            //After the user played, check if he/she is the winner!
            user_last_position[0]=row;
            user_last_position[1]=col;
            if (checkBoardStatus(state,user_last_position) == user_pebble){
                cout<<"/n/n The winner is human !/n/n"<<endl<<endl;
                display(state);
                break;
            }

            cout<<endl<<"Let AI think for 3 seconds..."<<endl<<endl;
            //if user has a black pebble then AI plays second
            if(user_pebble == 1){
                //let AI play and save the best its choice in the AI_position list
                search(state,AI_pebble,AI_position);
                //play with those positions
                play(state, AI_pebble, AI_position);
            }

            //Check if the game is over!
            if(checkBoardStatus(state, AI_position)== AI_pebble){
                cout<<"/n/n The winner is AI !/n/n"<<endl<<endl;
                display(state);
                break;
            }
        }

        return;
    }
}
int main(){
    //seeding the random number generator
    srand(time(0));

    NAndric::human_vs_AI();
  
    return 0;
}