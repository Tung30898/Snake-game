#include "../include/main.h"

int main(){
    int choice;
    cout << "==================================== WELCOME TO SNAKE GAME ====================================\n";
    cout << "1. Play\n2.Exit\n";
    cin >> choice;
    switch(choice) {
        case 1:
            InitDisplay();
            break;
        case 2:
            cout << "See you";
            Sleep(3);
        default:
            cout << "don't suitalbe";
    }
    return 0;
}