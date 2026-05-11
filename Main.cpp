#include "Loup.hpp"
#include "Mouton.hpp"
#include "Herbe.hpp"
#include "Sel.hpp"

int main(){
    int cols = 6;
    int rows = 6;
    int wolves = 6;
    int sheeps = 8;
    int curr_wolves_count = 0;
    int curr_sheeps_count = 0;
    srand(time(NULL));
    std::vector<std::vector<std::shared_ptr<Pion>>> grid(cols, std::vector<std::shared_ptr<Pion>>(rows));
    for(int i = 0; i<cols; i++){
        int count = 0;
        for(int j = 0; j<rows; j++){
            if(rand() % 2 == 0 && count < rows-1){
                if(rand()%2 == 0 && (curr_wolves_count != wolves || curr_sheeps_count == sheeps)){
                    grid[i][j] = std::make_shared<Loup>();
                    curr_wolves_count++;
                }
                else if (curr_sheeps_count != sheeps){
                    grid[i][j] = std::make_shared<Mouton>();
                    curr_sheeps_count++;
                }
                else 
                    grid[i][j] = std::make_shared<Herbe>();

                count++;
            }
            else
                grid[i][j] = std::make_shared<Herbe>();
        }
    }

    std::cout << "     ";
    for (int i = 0; i<rows;i++){
        std::cout << i << " | ";
    }
    std::cout << std::endl << std::endl;
    for(int i = 0; i<cols; i++){
        std::cout << (char)('A'+i) << " |  ";
        for (int j = 0; j<rows; j++){
            if (auto a = std::dynamic_pointer_cast<Loup>(grid[i][j]))
                std::cout << "L | ";
            else if (auto a = std::dynamic_pointer_cast<Mouton>(grid[i][j]))
                std::cout << "M | ";
            if (auto a = std::dynamic_pointer_cast<Herbe>(grid[i][j]))
                std::cout << "H | ";
        }
        std::cout << std::endl;
    }

    for(int i = 0; i<cols; i++){
        for (int j = 0; j<rows; j++){
            if(grid[i][j]->get_salt() == 1){
                std::make_shared<Sel>();
                grid[i][j]->set_salt(0);
                continue;
            }
            else if (grid[i][j]->get_salt() == 2){
                std::make_shared<Pion>();
                grid[i][j]->set_salt(0);
                continue;
            }

            else if (auto a = std::dynamic_pointer_cast<Sel>(grid[i][j])){
                std::make_shared<Herbe>();
                continue;
            }
            else if (auto a = std::dynamic_pointer_cast<Animal>(grid[i][j])){
                int interact_i, interact_j;
                int retry = 1;
                while (retry == 1){
                    srand(time(NULL));
                    int choice = rand()%8;
                    switch(choice){
                        case 0:
                            if(i-1 < 0 || j-1 < 0)
                                break;
                            interact_i = i-1;
                            interact_j = j-1;
                            retry = 0;
                            break;
                        case 1:
                            if(i-1 < 0)
                                break;
                            interact_i = i-1;
                            interact_j = j;
                            retry = 0;
                            break;
                        case 2:
                            if (i-1 < 0 || j+1 > rows)
                                break;
                            retry = 0;
                            interact_i = i-1;
                            interact_j = j+1;
                            break;
                        case 3:
                            if(j-1 < 0)
                                break;
                            interact_i = i;
                            interact_j = j-1;
                            retry = 0;
                            break;

                        case 4:
                            if(j+1 < 0)
                                break;
                            interact_i = i;
                            interact_j = j+1;
                            retry = 0;
                            break;
                         
                        case 5:
                            if(i+1 > cols || j-1 < 0 )
                                break;
                            interact_i = i+1;
                            interact_j = j-1;
                            retry = 0;
                            break;

                        case 6:
                            if(i+1 > cols)
                                break;
                            interact_i = i+1;
                            interact_j = j;
                            retry = 0;
                            break;

                        case 7:
                            if(i+1 > cols || j+1 > rows)
                                break;
                            interact_i = i+1;
                            interact_j = j+1;
                            retry = 0;
                            break;
                    }
                }
                a->play_turn(grid[interact_i][interact_j]);
                
            }

        }
    }


    return 0;
}