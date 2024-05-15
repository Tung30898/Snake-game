#include"screen.h"

#define UNUSED(x) (void)(x)

void display(int direct){
    UNUSED(direct);
    for(int i = -500; i <=500; ++i) {
        for(int j = -500; j<= 500; ++j) {
            if(i > -500 && i <500 && j >-500 && j <500) {
                cout << ' ';
                continue;
            }
            cout << "o";
        }
        cout << "\n";
    }
}