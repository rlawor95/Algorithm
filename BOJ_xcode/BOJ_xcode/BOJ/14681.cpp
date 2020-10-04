//
//  14681.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/04.
//  Copyright © 2020 김재경. All rights reserved.
//  백준 14681 사분면 고르기

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

int main()
{
    int x,y;
    cin>>x >> y;
    
    int result =0;
    if(x>0 && y>0)  // 우측 상단
        result=1;
    else if(x>0 && y<0)  // 우측 하단
        result =4;
    else if(x<0 && y>0)
        result = 2;
    else if(x<0 && y<0)
        result=3;
    
    cout<<result<<endl;
    return 0;
}
