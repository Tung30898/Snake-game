#include"screen.h"

#define UNUSED(x) (void)(x)

void Screen::CreatSprey(){
    bool accept = true;
    do{
        accept = false;
        mPreyX = rand() % (maxX-1) + 1;
        mPreyY = rand() % (maxY-1) + 1;
        for(auto i:mPosition) {
            if(mPreyX == i.first && mPreyY == i.second)
                accept = true;
        }
    }while(accept);
    mMark[mPreyX][mPreyY] = 1;
}

void Screen::InitDisplay(){
    CreatSprey();
    CalPosSnake(10);
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
    system("cls");
    // clrscr();
    if(4 != direct)
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
                if(4 == direct && i == mPosition[0].first && j == mPosition[0].second) {
                    cout << "X ";
                    continue;
                }
                cout << "o ";
                continue;
            }

            cout << "  ";
        }
        cout << "\n";
    }
}

void Screen::CalPosSnake(const int direct){   // 1:^ 2:< 3:v 4:>
    int n = mPosition.size()-1;
    pair<int,int> tail = mPosition[n];
    if(10 == direct) {   
        mMark[15][24] = 1;
        mMark[15][25] = 1;
        mMark[15][26] = 1;
        return;
    } 
    // duyet tu cuoi len dau mang
    mMark[mPosition[n].first][mPosition[n].second] = 0;
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
        oldDir = direct;
    }
    // neu no gap moi thi se tang do dai snake
    if(mPosition[0].first == mPreyX && mPreyY == mPosition[0].second) {
        mPosition.push_back(tail);
        mMark[tail.first][tail.second] = 1;                // tang do dai snake
        mMark[mPreyX][mPreyY] = 0;                         // xoa vi tri moi di
        CreatSprey();                                      // tao sprey moi
    }
    // check neu snake gap tuong hoac gap chinh no thi thua
    if(mPosition[0].first >= maxX || mPosition[0].second <= minX  
    || mPosition[0].first >= maxY || mPosition[0].second <= minY) { // neu gap tuong thi thua
        mLose = true;
    } else if(1 == mMark[mPosition[0].first][mPosition[0].second]) { // neu dau snake gap chinh no thi thua 
        mLose = true;
    } else {
        // Do nothing
    }
    mMark[mPosition[0].first][mPosition[0].second] = 1; // tinh toa do dau snake va danh dau lai de hien thi dau snake
    return;
}

void Screen::DetectDirect() {
    while(!mLose){
        int dir = 5;
        if (_kbhit()) {
            switch(getch()){
                case 56:
                    dir = 0;
                    break;
                case 52:
                    dir = 1;
                    break;
                case 50:
                    dir = 2;
                    break;
                case 54:
                    dir = 3;
                    break;
                case 3:
                    return ;
            }
            oldRow = dir;
        } else {
            dir = oldRow;
        }
        if(dir != 5)
            GameDisplay(dir);
        if(mLose) {
            GameDisplay(4);
            cout << "\n You Lose";
            Sleep(1000);
        }
        Sleep(difficult);
    }
}

void Screen::SelectDificult(){
    bool out = true;
    cout << "<   " << difficult << "   >\n";
    while(out){
        if (_kbhit()) {
            cout << "\x1b[1A"; // Move cursor up one
            cout << "\x1b[2K"; // Delete the entire line
            cout << "<   " << difficult << "   >\n";
            switch(getch()){
                case 52:
                    difficult -= 10;
                    break;
                case 54:
                    difficult += 10;
                    break;
                case 53:
                    out = false;
                    break;
            }
        }
        if(difficult <= 50){
            difficult = 50;
            continue;
        }
        if(difficult >= 500) {
            difficult = 500;
            continue;
        }
    }
    system("cls");
    return;
}