//
//  3.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/22.
//  Copyright © 2020 김재경. All rights reserved.
//  바닥공사 1*2 , 2*1 , 2*2 타일링 문제

#include <stdio.h>
#include <iostream>
using namespace std;

int Tile[1001];

int main()
{
    int input=0;
    cin>>input;
    
    Tile[1]=1; //1칸일때의 모든 경우의 수
    Tile[2]=3; //2칸일때의 모든 경우의 수
    
    for(int i=3; i<=input; i++)
    {
        Tile[i] = (Tile[i-1] + Tile[i-2] + Tile[i-2]) % 10007;
    }
    
    //double result = Tile[input]/10007;
    //result = Tile[input] - result;
    //cout<<result<<endl;
    cout<<Tile[input]<<endl;
    return 0;
}
