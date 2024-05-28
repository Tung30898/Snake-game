#include"screen.h"

#define UNUSED(x) (void)(x)

Screen::Screen() {
    //kich thuoc khung
    maxX = 50;
    maxY = 50
    minX = 0;
    minY = 0;
    // toa do con moi
    mPreyX = 0;
    mPreyY = 0;
    // neu thua thi set len 1;
    mLose = false;
    mPosition = vector<pair<int,int>> {{25,24},{25,25},{25,26}};     // toa do cua snake
    mMark = vector<vector<bool>> (52,vector<bool>(52,false));        // danh dau xem vi tri cua ran.
    rowD = vector<int> {-1, 0, 1, 0};                                // huong di chua snake X
    colD = vector<int> {0, -1, 0, 1};                                // huong di chua snake Y
}

void Screen::InitDisplay(){
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
            // neu da danh dau thi hien thi snake
            if(1 == mMark[i][j]) {
                cout << "o ";
                continue;
            }
            cout << "  ";
        }
        cout << "\n";
    }
}

void Screen::GameDisplay(const int direct){
    CalPosSnake(direct);
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

            if(1 == mMark[i][j]) {
                cout << "o ";
                continue;
            }

            cout << "  ";
        }
        cout << "\n";
    }
}

void Screen::CalPosSnake(const int direct){             // 1:^ 2:< 3:v 4:>
    int n = mPosition().size()-1;
    pair<int,int> tail = mPosition[n];
    if(0 == direct) {                                   // screen luc bat dau
        mMark[25][24] = 1;
        mMark[25][25] = 1;
        mMark[25][26] = 1;
        return;
    }
    // duyet tu cuoi len dau mang
    mMark[[n].first][mPosition[n].second] = 0;
    for(int i = n; i>0;--i) {
        mPosition[i].first = mPosition[i-1].first;
        mPosition[i].second = mPosition[i-1].second;
    }
    // update vi tri moi cho dau snake.
    if(oldDir == direct || 2 == abs(oldDir-direct)) {   // neu huong di moi bang hoac nguoc
        mPosition[0].first += rowD[oldDir];             // huong di cu thi tiep tuc di theo huong cu
        mPosition[0].second += colD[oldDir];
    } else {                                            // neu khong thi di theo huong di moi
        mPosition[0].first += rowD[direct];
        mPosition[0].second += colD[direct];
    }

    // check neu snake gap tuong hoac gap chinh no thi thua
    if(mPosition[0].first > maxX || mPosition[0].second < minX  
    || mPosition[1].first > maxY || mPosition[1].second < minY) {
        mLose = true;
    } else if(1 = mMark[mPosition[0].first][mPosition[0].second]) {
        mLose = true;
    } else {
        // Do nothing
    }

    // neu no gap moi thi se tang do dai snake
    if(mPosition[0].first == mPreyX && mPreyY == mPosition[0].second) {
        mPosition.push_back(tail);
        mMark[tail.first][tail.second] = 1;
    }

    oldDir = direct;
    return;
}

void Screen::DetectDirect() {
    while(1){
        cout << "Goto detect Direct";
        int a ;
        int dir = 0;
        a = getch();
        cout << a << " ";
        switch(a){
            case 72:
                dir = 1;
                cout << "A";
                break;
            case 75:
                dir = 2;
                cout << "<";
                break;
            case 77:
                dir = 3;
                cout << ">";
                break;
            case 80:
                dir = 4;
                cout << "v";
                break;
            case 3:
                return ;
        }
        GameDisplay(dir);
        if(mLose) {
            cout << "\n You Lose";
        }
    }
}