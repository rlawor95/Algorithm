//
//  1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/20.
//  Copyright © 2020 김재경. All rights reserved.
//  부품 찾기 with 나동빈
// 계수 정렬이나 set 자료구조를 통해서 구현하면 더 빠르다.

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

vector<int>vN;
vector<int>vM;
int n, m;

bool Search(vector<int>&v,int target,int start, int end)
{
    while(start<=end)
    {
        int mid = (start+end)/2;
        
        if(target == v[mid])
            return true;
        else if(target>v[mid])
            start = mid+1;
        else
            end = mid-1;
    }
    
    return false;
}

int main()
{
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int t;
        cin>>t;
        vN.push_back(t);
    }
    
    
    cin>>m;
    for(int i=0; i<m; i++)
    {
        int t;
        cin>>t;
        vM.push_back(t);
    }
    
    sort(vN.begin(), vN.end());
    
    for(int i=0; i<m; i++)
    {
        if(Search(vN,vM[i], 0, n-1))
            cout<<"Yes"<<" ";
        else
            cout<<"No"<<" ";
    }
    
    
    
    return 0;
}
