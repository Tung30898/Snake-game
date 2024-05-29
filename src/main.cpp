#include "../include/main.h"

int main(){
    int choice=10;
    Screen snake;
    PrintWelcome();
    while(1) {
        cin >> choice;
        switch(choice) {
            case 1:
                cout << "Play game\n";
                snake.InitDisplay();
                snake.DetectDirect();
                PrintWelcome();
                break;
            case 2:
                cout << "Difficult Level\n";
                snake.SelectDificult();
                PrintWelcome();
                break;
            case 3:
                cout << "See you";
                Sleep(3);
                return 0;
            default:
                cout << "don't suitalbe";
        }
    }
    
    return 0;
}