#include "../include/main.h"

int main(){
    cout << "==================================== WELCOME TO SNAKE GAME ====================================\n";
    cout << "1. Play\n2.Exit";
    cin >> choice;
    switch(choice) {
        case 1:
            display(2);
            break;
        case 2:
            cout << "See you";
            Sleep(3);
        default:
            cout << "don't suitalbe";
    }
    return 0;
}