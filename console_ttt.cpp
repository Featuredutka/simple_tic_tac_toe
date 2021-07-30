#include <iostream>

class Game{
    public:
        char field[3][3];
        int positions[3][3];
        int move;
        
        void fields_display(){
            
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    std::cout << field[i][j];
                    std::cout << ' ';
                }
                std::cout << "         ";
                for(int j = 0; j < 3; j++){
                    if (positions[i][j] == 10){
                    std::cout << ' ';
                    } else{
                        std::cout << positions[i][j];
                    }
                    std::cout << ' ';
                }
                std::cout << '\n';
           }

        }
        
        char switch_player(char current_player){
            if (current_player == 'X'){
                return 'O';
            }else{
                return 'X';   
            }
        }

        void win_check(char player){
            int hor_win = 0;
            int ver_win = 0;

            if (field[0][0] == player and field[1][1] == player and field[2][2] == player){
                std::cout << "Player " << player <<" won" << std::endl;
                exit(0);
            }

            if  (field[0][2] == player and field[1][1] == player and field[2][0] == player){
                std::cout << "Player " << player <<" won" << std::endl;
                exit(0);
            }

            for(int i = 0; i<3; i++){
                for(int j = 0; j<3; j++){
                    if (field[i][j] == player){
                        hor_win ++;
                    }
                    if (field[j][i] == player){
                        ver_win ++;
                    }
                }

                if(hor_win == 3){
                    std::cout << "Player " << player <<" won" << std::endl;
                    exit(0);
                }
                 if(ver_win == 3){
                    std::cout << "Player " << player <<" won" << std::endl;
                    exit(0);
                }

                ver_win = 0;
                hor_win = 0;
            }

            game_move(switch_player(player));
        }

        void game_move(char player){
            fields_display();
            std::cout << "Choose a position to mark\n";
            std::cout << "Avaliable positions: ";
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    if (positions[i][j] != 10){
                        std::cout << positions[i][j] << ' ';
                    }
                }
            }
            while (true){
                std::cout << "Position: ";
                std::cin >> move;
                if (move >= 0 and move < 10){
                    for(int i = 0; i < 3; i++){
                        for(int j = 0; j < 3; j++){
                            if (positions[i][j] == move){
                                positions[i][j] = 10;
                                field[i][j] = player;
                                std::cout << "Marked\n";
                                std::cout << "-----------------------------------\n";
                                win_check(player);
                            }
                        }
                    
                    }   
                }
                std::cout << "No such position avaliable" << std::endl;
            }
        }
    
    void menu(){
    char player;
    while (true){
        std::cout << "Choose who goes first(X/O):";
        std::cin >> player;
        if (player == 'x' or player == 'X'){
            std::cout << "X goes first\n";
            game_move('X');
        }
        if (player == 'o' or player == 'O'){
            std::cout << "O goes first\n";
            game_move('O');
        }
        std::cout << "Invalid choice. Please, try again\n";
    }
}

        Game(){
            int filler = 1;
            for(int i = 0; i < 3; i++){
                for(int j = 0; j < 3; j++){
                    field[i][j] = ' ';
                    positions[i][j] = filler++;
                }
            }
        }


};

int main(){
    Game gameprocess;
    gameprocess.menu();
    return 0;
}
