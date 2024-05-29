#ifndef SCREEN_H
#define SCREEN_H

// #include<curses.h>
#include<conio.h>
#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<string>
#include<stdio.h>
#include<stdlib.h>
// #include <curses.h>

using namespace std;

class Screen {
public:
    // khai bao cau truc
    vector<pair<int,int>> mPosition;
    vector<vector<bool>> mMark;
    vector<int> rowD;
    vector<int> colD;
    int oldDir;
    int oldRow;
    int maxX;
    int maxY;
    int minX;
    int minY;
    int mPreyX;
    int mPreyY;
    unsigned int difficult;
    bool mLose;
    // method
    Screen(){
        cout << "constructor of screen";
        //kich thuoc khung
        oldDir = 0;
        oldRow = 5;
        maxX = 30;
        maxY = 50;
        minX = 0;
        minY = 0;
        // toa do con moi
        mPreyX = 0;
        mPreyY = 0;
        // do kho cua game - toc do cua snake
        difficult = 250;
        // neu thua thi set len 1;
        mLose = false;
        mPosition = vector<pair<int,int>> {{15,24},{15,25},{15,26}};     // toa do cua snake
        mMark = vector<vector<bool>> (32,vector<bool>(52,false));        // danh dau xem vi tri cua ran.
        rowD = vector<int> {-1, 0, 1, 0};                                // huong di chua snake X
        colD = vector<int> {0, -1, 0, 1};                                // huong di chua snake Y
    };
    virtual ~Screen(){
    };
    void InitDisplay();
    void GameDisplay(const int direct);
    void CalPosSnake(const int direct);
    void DetectDirect();
    void CreatSprey();
    void SelectDificult();
};


#endif