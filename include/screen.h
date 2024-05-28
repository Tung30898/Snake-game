#ifndef SCREEN_H
#define SCREEN_H

#include<curses.h>
#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include<string>
#include<stdio.h>
// #include <curses.h>

using namespace std;

class Screen {
public:
    // khai bao cau truc
    vector<pair<int,int>> mPosition;
    vector<vector<bool>> mMark;
    vector<int> rowD;
    vector<int> colD;
    int maxX;
    int maxY;
    int minX;
    int minY;
    int mPreyX;
    int mPreyY;
    bool mLose;
    // method
    Screen();
    virtual ~Screen();
    void InitDisplay();
    void GameDisplay(const int direct);
    void CalPosSnake(const int direct);
    void DetectDirect();
};


#endif