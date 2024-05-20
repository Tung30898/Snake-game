#include "../include/main.h"

int main(){
    int choice=10;
    cout << "==================================== WELCOME TO SNAKE GAME ====================================\n";
    cout << "1. Play\n2.Exit\n";
    // cin >> choice;
    // switch(choice) {
    //     case 1:
    //         InitDisplay();
    //         break;
    //     case 2:
    //         cout << "See you";
    //         Sleep(3);
    //     default:
    //         cout << "don't suitalbe";
    // }
    while(1){
        int a = getch();
        cout << a << " ";
        switch(a){
            case 75:
                cout << "<";
                break;
            case 77:
                cout << ">";
                break;
            case 80:
                cout << "v";
                break;
            case 72:
                cout << "A";
                break;
            case 3:
                return 0;
                break;
        }
    }
    return 0;
}