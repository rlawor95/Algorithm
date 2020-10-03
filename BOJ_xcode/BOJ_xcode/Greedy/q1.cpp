//
//  q1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  모험가 길드 with 나동빈


#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100001

int arr[MAX];

int main()
{
    int n,result =0;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int p;
        cin>>p;
        arr[p]++;
    }
    
    for(int i=1; i<MAX; i++)
    {
        result += arr[i]/i;
    }
    
    cout<<result<<endl;
    
    return 0;
}


