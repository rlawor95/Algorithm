//
//  4.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/24.
//  Copyright © 2020 김재경. All rights reserved.
// 효율적인 화폐구성 with 나동빈

#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int n,m;
vector<int>arr;

int main()
{
    cin>> n >>m;
    
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        arr.push_back(x);
    }
    
    vector<int>d(m+1,10001);
    
    d[0]=0;
    
    for(int i=0; i<n; i++)
    {
        int money = arr[i];
        while(money<=m)
        {
            d[money] = min(d[money], d[money-arr[i]]+1);
            money+=1;
        }
        
        for(int j=0; j<=m; j++)
        cout<<"idx:"<<j<<" "<<d[j]<<"  ";
        cout<<endl;
    }
    
//    if(d[m]>10000)
//        cout<<-1<<endl;
//    else
//        cout<<d[m]<<endl;
    
    return 0;
}
