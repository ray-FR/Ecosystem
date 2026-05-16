#include "Loup.hpp"
#include "Mouton.hpp"
#include "Herbe.hpp"
#include "Sel.hpp"

void displayGrid(std::vector<std::vector<std::shared_ptr<Pion>>>& grid, int cols, int rows){
    std::cout << "     ";
    for (int i = 0; i<cols;i++){
        std::cout << i << " | ";
    }
    std::cout << std::endl << std::endl;
    for(int i = 0; i<rows; i++){
        std::cout << (char)('A'+i) << " |  ";
        for (int j = 0; j<cols; j++){
            if (auto a = std::dynamic_pointer_cast<Loup>(grid[i][j])){
            std::cout << "L | ";
            a->reset_moved();
            }
            else if (auto a = std::dynamic_pointer_cast<Mouton>(grid[i][j])){
            std::cout << "M | ";
            a->reset_moved();
            }
            else if (auto a = std::dynamic_pointer_cast<Herbe>(grid[i][j]))
            std::cout << "H | ";
            else if (auto a = std::dynamic_pointer_cast<Sel>(grid[i][j]))
            std::cout << "S | ";

            else 
            std::cout << "  | ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}


int main(){
    int rows;
    int cols;
    int wolves;
    int sheeps;
    long time_choosen;

    int curr_wolves_count = 0;
    int curr_sheeps_count = 0;
    int tour_n = 1;
    int max_regen = 3;
    
    std::cout << "Nombre de lignes? ";
    std::cin >> rows;
    std::cout << "Nombre de colonnes? ";
    std::cin >> cols;
    std::cout << "Nombre de loups? ";
    std::cin >> wolves;
    std::cout << "Nombre de moutons? ";
    std::cin >> sheeps;
    std::cout << "Combien de secondes entre chaque tour? ";
    std::cin >> time_choosen;
    
    if ((sheeps+wolves) > rows*cols){
        std::cout << "Erreur. Trop d'animaux. " << std::endl;
        exit(1);
    }



    srand(time(NULL));
    std::vector<std::vector<std::shared_ptr<Pion>>> grid(rows, std::vector<std::shared_ptr<Pion>>(cols));
    for(int i = 0; i<rows; i++){
        int count = 0;
        for(int j = 0; j<cols; j++){
            if(rand() % 2 == 0 && count < cols-1){
                if(rand()%2 == 0 && (curr_wolves_count != wolves)){
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
    
    displayGrid(grid, cols, rows);


    while(1){
        std::cout << "Tour: " << tour_n++ << " Moutons: " << curr_sheeps_count << " Loups: " << curr_wolves_count << std::endl;
        int regen = 0;
        if (curr_sheeps_count == 0 && curr_wolves_count == 0){
            std::cout << std::endl << "=== Plus aucun animaux n'est en vie! L'univers est mort! ===" << std::endl << std::endl;
            exit(0);
        }
        for(int i = 0; i<rows; i++){
            for (int j = 0; j<cols; j++){
                
                if(grid[i][j]->get_salt() == 1){
                    
                    auto dstM = std::dynamic_pointer_cast<Mouton>(grid[i][j]);
                    auto dstL = std::dynamic_pointer_cast<Loup>(grid[i][j]);
                    if (dstM){
                        curr_sheeps_count--;
                        std::cout << "Le mouton à la case (" << i << " " << j <<") est mort!" << std::endl; 
                        std::cout << "Nombre de moutons restants: " << curr_sheeps_count << std::endl;
                    } 
                    else{
                        curr_wolves_count--;
                        std::cout << "Le loup à la case (" << i << " " << j <<") est mort!" << std::endl; 
                        std::cout << "Nombre de loups restants: " << curr_wolves_count << std::endl;
                    
                    }


                    grid[i][j] = std::make_shared<Sel>();
                    continue;
                }
                
                else if (auto a = std::dynamic_pointer_cast<Sel>(grid[i][j])){
                    std::cout << "Grâce au sels minéraux, l'herbe à repoussé à la case (" << i << " " << j << ")" << std::endl;
                    grid[i][j] = std::make_shared<Herbe>();
                    continue;
                }
                

                else if (auto a = std::dynamic_pointer_cast<Animal>(grid[i][j])){
                    int found_choice = 0;

                    if(a->get_reproduced_status() == 1)
                        a->reset_reproduced_status();

                    if (a->get_moved())
                        continue;
                    int interact_i, interact_j;
                    int retry = 1;
                    std::vector<int> v;
                    v.clear();
                    while (retry == 1 && v.size() < 8) {
                        
                        if (v.size() == 8){
                            found_choice = 0;
                            break;}
                        int choice = rand() % 8;              
                        if (std::count(v.begin(), v.end(), choice) != 0)
                            continue;
                        int ni = i, nj = j;                     
                            
                            switch (choice) {
                                case 0:  
                                ni = i - 1;  nj = j - 1;
                                break;
                                case 1:  
                                ni = i - 1;  nj = j;
                                break;
                                case 2:  
                                ni = i - 1;  nj = j + 1;
                                break;
                                case 3:  
                                ni = i;      nj = j - 1;
                                break;
                                case 4:  
                                ni = i;      nj = j + 1;
                                break;
                                case 5:  
                                ni = i + 1;  nj = j - 1;
                                break;
                                case 6:  
                                ni = i + 1;  nj = j;
                                break;
                                case 7:  
                                ni = i + 1;  nj = j + 1;
                                break;
                            }
                            
                            
                            if (ni >= 0 && ni < rows && nj >= 0 && nj < cols) {
                                interact_i = ni;
                                interact_j = nj;
                                
                                if (!grid[interact_i][interact_j] || !grid[i][j]) {
                                    v.push_back(choice);
                                    continue;
                                }
                                
                                auto srcM = std::dynamic_pointer_cast<Mouton>(grid[i][j]);
                                auto dstM = std::dynamic_pointer_cast<Mouton>(grid[interact_i][interact_j]);
                                auto srcL = std::dynamic_pointer_cast<Loup>(grid[i][j]);
                                auto dstL = std::dynamic_pointer_cast<Loup>(grid[interact_i][interact_j]);
                                
                                if (((dstM) && (srcM)) || ((dstL) && (srcL))) {                               
                                    v.push_back(choice);
                                    continue;
                                }
                                
                                retry = 0;
                                found_choice = 1;
                                if (a->get_reproduced_status() == 2){
                                    if (srcM){
                                        grid[i][j] = std::make_shared<Mouton>(); 
                                        std::cout << "Le mouton de la case (" << i << " " << j << ")" << " à donné naissance à la case (" << interact_i << " " << interact_j << ")" << std::endl;}
                                    else if (srcL){
                                        grid[i][j] = std::make_shared<Loup>(); 
                                        std::cout << "Le loup de la case (" << i << " " << j << ")" << " à donné naissance à la case (" << interact_i << " " << interact_j << ")" << std::endl;}

                                }

                            }
                            else {
                                v.push_back(choice);
                            }
                    }
                        
                        if (found_choice){
                            if (a->get_reproduced_status() == 2){
                                a->reset_reproduced_status();
                                continue;
                            }
                            std::cout << "(" << i << " " << j << ")" << " ";
                            a->play_turn(grid[interact_i][interact_j]);
                            std::cout << "(" << interact_i << " " << interact_j << ")" << std::endl;
                            
                            if(a->get_reproduced_status() < 1){
                                grid[interact_i][interact_j] = grid[i][j];
                                grid[i][j] = std::make_shared<Pion>();
                                
                            }
                        }

                    continue;
                }

                else{
                    if (tour_n % 4 == 0 && rand()%2==0 && regen < max_regen){
                        std::cout << "De l'herbe à magiquement repoussé à la case (" << i << " " << j << ")" << std::endl;
                        grid[i][j] = std::make_shared<Herbe>();
                        regen++;
                    }

                    continue;
                }

                    
            }
        }
        std::cout << std::endl;
        displayGrid(grid, cols, rows);
        std::this_thread::sleep_for(std::chrono::seconds(time_choosen));
    }
        
        
        
        
        
        
        
        
        return 0;
    }