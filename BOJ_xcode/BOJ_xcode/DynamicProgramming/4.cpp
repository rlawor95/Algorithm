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
        for(int j=arr[i]; j<=m; j++)
        {
            int idx = j-arr[i];
            if(d[idx] != 10001)
            {
                d[j] = min(d[j],d[idx]+1);
            }
        }
    }
    
    if(d[m]==10001)
        cout<<-1<<endl;
    else
        cout<<d[m]<<endl;
    
    return 0;
}
