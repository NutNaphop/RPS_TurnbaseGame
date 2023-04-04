#include <iostream> 
#include <ctime>
#include <cstdlib>
#include <string>
#include <string.h>
#include <cctype>
#include <iomanip>
#include <unistd.h>
using namespace std ;

class game{
    public :
        static string weaponArr[3] ; 
        int result ; 

        int random(){
            srand((unsigned) time(NULL));
            return rand() % 3 ; 
        }
        int showResult(int result){
            switch (result) {
                case 0 : 
                    // Player Attack Mode
                    return 0 ;  
                    break ; 
                case 1 : 
                    // Opponent Attack Mode
                    return 1 ;
                    break ; 
                case 2 : 
                    return 2 ;
                    break ;
            };
        }
        int check(string player , string opponent){
            result = strcmp(player.c_str(),opponent.c_str());
            if (result > 0){
                cout << endl ;
                cout << "***********************************************" << endl;
                cout << "*                                             *" << endl;
                cout << "*                Player Win ! !               *" << endl;
                cout << "*                                             *" << endl;
                cout << "***********************************************" << endl;
                cout << endl ;
                return 1 ;
            }
            else if (result < 0){
                cout << endl ;
                cout << "***********************************************" << endl;
                cout << "*                                             *" << endl;
                cout << "*               Opponent Win ! !              *" << endl;
                cout << "*                                             *" << endl;
                cout << "***********************************************" << endl;
                cout << endl ;
                return 2 ;  
            }
            else {
                cout << endl ;
                cout << "***********************************************" << endl;
                cout << "*                                             *" << endl;
                cout << "*                  DRAW ! !                   *" << endl;
                cout << "*                                             *" << endl;
                cout << "*                                             *" << endl;
                cout << "***********************************************" << endl;
                cout << endl ;
                return 3 ; 
            }
        }
};

string game::weaponArr[3] = {"rock" , "paper" , "scissors"} ; 

class player : public game {
    public : 
        static int score ; 
        static int life_player ;
        string name ; 
        string get_weapon ;
        string weapon ;
        void getWeapon(){
            do{
                cout << endl ;
                cout << "*******************************" << endl;
                cout << "*                             *" << endl;
                cout << "*     Rock Paper Scissor ?    *" << endl;
                cout << "*                             *" << endl;
                cout << "*******************************" << endl;
                cout << "> " ; getline(cin,weapon);
                cout << endl ;
                for (int i = 0 ; i < get_weapon.length() ; i ++){
                    weapon += tolower(get_weapon[i]);
                }
                if (weapon != "rock" && weapon != "paper" && weapon != "scissor"){
                    cout << "I dont know what is it , try again" << endl ;
                }
                else {
                    system("cls");
                    break ; 
                }
            }while(true);
        }     
};
int player::life_player = 5 ;
int player::score = 0  ; 

class opponent : public game {
    public :
        static int life_opponent ; 
        string weapon ; 
        void getWeapon(){
            weapon = weaponArr[random()];
        }
};
int opponent::life_opponent = 5 ;

class display : public player , opponent{
    public :
         void showHealth(int result , int mode){
            if (mode == 1){
                switch (result) {
                case 1 :
                    cout << endl ;
                    cout  << "" << endl; // prints a line of asterisks
                    cout << "=================================================" << endl;
                    cout << "|       Action : You have attacked the opponent  |" << endl;
                    cout << "|                 for 2 damage                   |" << endl;
                    cout << "=================================================" << endl;
                    cout << setfill('*') << setw(40) << "" << endl; // prints another line of asterisks
                    life_opponent -= 2 ;
                    break;
                case 2 :
                    cout << endl ;
                    cout << "=================================================" << endl;
                    cout << "|     Action : Unfortunately, you missed ! ! !  |" << endl;
                    cout << "=================================================" << endl;

                    break;
                }                   
            }
            else if (mode == 2){
                switch (result) {
                case 1 :
                    cout << endl ;
                        cout << "===========================================" << endl;
                        cout << "|            Action : Lucky               |" << endl;
                        cout << "|           Opponent Missed ! ! !         |" << endl;
                        cout << "===========================================" << endl;
                    break;
                case 2 :
                cout << endl ;
                        cout << "============================================" << endl;
                        cout << "|      Action : You have been attacked     |" << endl;
                        cout << "|        by the opponent for 2 damage      |" << endl;
                        cout << "============================================" << endl;
                    life_player -= 2 ;
                    break;             
                };
                
            }
            else if (mode == 3){
                        cout << "============================================" << endl;
                        cout << "|        Action : You draw, so take 1      |" << endl;
                        cout << "|            damage both of you            |" << endl;
                        cout << "============================================" << endl;
                life_opponent -- ;
                life_player -- ;
            }
            else {
                cout << endl ;
                cout << "===============================" << endl;
                cout << "        Battle Statistics      " << endl;
                cout << "===============================" << endl;
                cout << "You have " << setw(1) << life_player << " life points" << endl;
                cout << "Opponent has " << setw(1) << life_opponent << " life points" << endl;
                cout << "===============================" << endl;  
                cout << endl ;
            }
        }

        void showTurn(int show){
            switch (show)
            {
            case 1:
                cout << endl ;
                    cout << "*******************************" << endl;
                    cout << "*                             *" << endl;
                    cout << "*    OPPONENT DEFENSE TURN    *" << endl;
                    cout << "*                             *" << endl;
                    cout << "*******************************" << endl;
                    cout << endl ; 
                    break;
            case 2 :
                    cout << endl ;
                    cout << "*******************************" << endl;
                    cout << "*                             *" << endl;
                    cout << "*     PLAYER DEFENSE TURN     *" << endl;
                    cout << "*                             *" << endl;
                    cout << "*******************************" << endl;
                    cout << endl ;
                    break; 
            default:
                    cout << endl ;
                    cout << "*******************************" << endl;
                    cout << "*                             *" << endl;
                    cout << "*        OOPS ! ! DRAW        *" << endl;
                    cout << "*                             *" << endl;
                    cout << "*******************************" << endl;
                    cout << endl ; 
                    break;
            }
        }
};

int main(){
    game objG ; 
    player objP ; 
    opponent objO ;
    display objD ;
    int a , b ; 
    while (objP.life_player > 0 && objO.life_opponent > 0){
        objD.showHealth(4,4); // show life with normal mode
        objP.getWeapon();
        objO.getWeapon();
        b = objG.check(objP.weapon,objO.weapon); // get check who win in the round to set mode
        
        system("pause");
        sleep(1.2);
        system("cls") ; 

        if (b == 3){
            objD.showHealth(b,3); // show life with draw mode
            cout << "===========================================" << endl;
            cout << "|            Action : NO DAMAGE            |" << endl;
            cout << "===========================================" << endl;
            system("pause");
            system("cls") ;
        }
        else {
            objD.showHealth(4,4);
            objD.showTurn(b);
            objP.getWeapon();
            objO.getWeapon();
            a = objG.check(objP.weapon,objO.weapon) ;  // check who win 
            objD.showHealth(a,objG.showResult(b)); // show life with player , opponent mode || show result is mode
            system("pause");
            sleep(1.2);
            system("cls") ;
        }
    }
    if (objP.life_player <= 0){
        cout << "===============================" << endl;
        cout << "          Out of life          " << endl;
        cout << "           You Lose            " << endl;
        cout << "===============================" << endl;
    }
    else {
        cout << "===============================" << endl;
        cout << "         Congratulation        " << endl;
        cout << "            You win            " << endl;
        cout << "===============================" << endl;
    }

}

