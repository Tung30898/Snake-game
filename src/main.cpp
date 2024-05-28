#include "../include/main.h"

int main(){
    int choice=10;
    Screen snake;
    cout << "==================================== WELCOME TO SNAKE GAME ====================================\n";
    cout << "1. Play\n2.Exit\n";
    cin >> choice;
    switch(choice) {
        case 1:
            cout << "Play game";
            snake.InitDisplay();
            snake.DetectDirect();
            break;
        case 2:
            cout << "See you";
            Sleep(3);
        default:
            cout << "don't suitalbe";
    }
    return 0;
}