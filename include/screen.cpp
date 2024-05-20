#include"screen.h"

#define UNUSED(x) (void)(x)

// khai bao cau truc
vector<pair<int,int>> position = {{0,-1},{0,0},{0,1}};      // toa do cua snake
vector<vector<bool>> visit (52,vector<bool>(50,false));
vector<int> rowD {-1, 0, 1, 0},                             // huong di chua snake
            colD {0, -1, 0, 1};                             //

// khai bao bien 
int maxX = 25, maxY = 25, minX = -25, minY = -25;           //kich thuoc khung 
int curDir = 0, oldDir = 0;                          // huong di chuyen moi, huong di chuyen cu

void InitDisplay(){
    CalPosSnake(0);
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

            if(visit[i][j]) {
                cout << "o ";
                continue;
            }

            cout << "  ";
        }
        cout << "\n";
    }
}

void GameDisplay(int direct){
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

            if(visit[i][j]) {
                cout << "o ";
                continue;
            }

            cout << "  ";
        }
        cout << "\n";
    }
}

void CalPosSnake(int direct){ // 1:^ 2:< 3:v 4:>
    if(0 == direct) { // screen luc bat dau
        visit[25][24] = 1;
        visit[25][25] = 1;
        visit[25][26] = 1;
        return;
    }
    // duyet tu cuoi len dau mang
    for(int i = position.size()-1; i>0;--i) {
        position[i].first = position[i-1].first;
        position[i].second = position[i-1].second;
    }
    // update vi tri moi cho dau snake.
    if(oldDir == direct || 2 == abs(oldDir-direct)) {   // neu huong di moi bang hoac nguoc
        position[0].first += rowD[oldDir];              // huong di cu thi tiep tuc di theo huong cu
        position[0].second += colD[oldDir];
    } else {                                            // neu khong thi di theo huong di moi
        position[0].first += rowD[direct];
        position[0].second += colD[direct];
    }

    return;


}