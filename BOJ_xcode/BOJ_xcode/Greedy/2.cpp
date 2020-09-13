//
//  2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/14.
//  Copyright © 2020 김재경. All rights reserved.
//  숫자카 카드 게임 with 나동빈

#include <stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int result =0;
    int n,m=0;
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
    {
        int minvalue=10001; // 카드의 맥스값은 10000
        for(int j=0; j<m; j++)
        {
            int v;
            cin>>v;
            minvalue = min(minvalue,v);
        }
        result = max(result ,minvalue);
    }
    
    cout<<result<<endl;
    return 0;
}
