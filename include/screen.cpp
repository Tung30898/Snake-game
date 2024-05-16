#include"screen.h"

#define UNUSED(x) (void)(x)

int maxX = 25, maxY = 25, minX = -25, minY = -25;
string snake = "o o o ";

void InitDisplay(){
    for(int i = minX; i <=maxX; ++i) {
        for(int j = minY; j<= maxY; ++j) {
            // display boundary
            if(i == minX || i == maxX) {
                cout << "--";
                continue;
            }

            if(j == minY || j == maxY) {
                cout << "|";
                continue;
            }

            if(0 == i && -1 == j) {
                cout << snake;
                j+=(snake.size()/2-1);
                continue;
            }

            cout << "  ";
        }
        cout << "\n";
    }
}

void display(int direct, int x, int y){
    for(int i = minX; i <=maxX; ++i) {
        for(int j = minY; j<= maxY; ++j) {
            // display boundary
            if(i == minX || i == maxX) {
                cout << "--";
                continue;
            }

            if(j == minY || j == maxY) {
                cout << "|";
                continue;
            }

            if(0 == i && -1 == j) {
                cout << snake;
                j+=(snake.size()/2-1);
                continue;
            }

            cout << "  ";
        }
        cout << "\n";
    }
}