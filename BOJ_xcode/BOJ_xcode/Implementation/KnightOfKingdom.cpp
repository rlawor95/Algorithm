//
//  KnightOfKingdom.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/16.
//  Copyright © 2020 김재경. All rights reserved.
//  왕실의 나이트 with 나동빈

#include <stdio.h>
#include <iostream>

using namespace std;

#define MAPSIZE 8

int dx[] = {-2, -2, 2, 2,1,-1,1,-1};
int dy[] = {1, -1, -1, 1,2,2,-2,-2};

int map[MAPSIZE][MAPSIZE];

int main()
{
    char input[2];
    cin>>input;
    
    int x = input[0];
    int y = input[1];
    x-=97; // a == 97
    y-=49; // 1 == 49
    
    int result = 0;
    
    for(int i=0; i<8; i++)
    {
        int mx = x + dx[i];
        int my = y + dy[i];
        
        if(mx >=MAPSIZE || my >=MAPSIZE ||
           mx < 0 || my<0)
            continue;
        
        result++;
    }
    
    cout<<result<<endl;
    
    return 0;
}
