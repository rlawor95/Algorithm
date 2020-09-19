//
//  2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/19.
//  Copyright © 2020 김재경. All rights reserved.
//  두 배열의 원소 교체 with 나동빈

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    
    vector<int>a;
    vector<int>b;
    
    for(int j=0; j<n; j++)
    {
        int t;
        cin>>t;
        a.push_back(t);
    }
    for(int j=0; j<n; j++)
    {
        int t;
        cin>>t;
        b.push_back(t);
    }
    
    sort(a.begin(),a.end(),less<int>());
    sort(b.begin(),b.end(),greater<int>());
    
    for(int i=0; i<k; i++)
    {
        if(a[i] > b[i])
            break;
        
        int temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
    
    double result=0;
    for(int i=0; i<a.size(); i++)
    result+=a[i];
    
    cout <<result<<endl;
    
    return 0;
}
