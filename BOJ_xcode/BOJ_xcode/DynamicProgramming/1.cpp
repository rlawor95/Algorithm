//
//  1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/20.
//  Copyright © 2020 김재경. All rights reserved.
//  1로 만들기

#include <stdio.h>
#include <iostream>
using namespace std;

int DP[1000001] = { 0 };

int Solve(int v)
{
    int t = DP[v - 1];
    
    if(v%5==0)
    {
        int temp = v/5;
        if(DP[temp] < t)
            t= DP[temp];
    }
    if (v % 3 == 0)
    {
        int temp = v/3;
        if(DP[temp] < t)
            t= DP[temp];
    }
    if (v % 2 == 0)
    {
        int temp = v/2;
        if(DP[temp] < t)
            t= DP[temp];
    }
    
    return t + 1;
}

int main()
{
    DP[2] = 1;
    DP[3] = 1;
    
    for (int i = 4; i < sizeof(DP)/4; i++)
    {
        DP[i] = Solve(i);
    }
    
    int input = 0;
    cin >> input;
    cout << DP[input] << endl;
}
