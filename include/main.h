#ifndef MAIN_H
#define MAIN_H

#include<iostream>
#include<bits/stdc++.h>
#include<windows.h>
#include"screen.h"
// #include<conio.h>


using namespace std;

// declare functions
int main(void);
void PrintWelcome(){
    system("cls");
    cout << "==================================== WELCOME TO SNAKE GAME ====================================\n";
    cout << "1. Play\n2. Difficult Level\n3. Exit\n";
};
#endif