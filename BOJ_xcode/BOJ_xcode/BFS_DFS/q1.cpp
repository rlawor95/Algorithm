//
//  q1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/04.
//  Copyright © 2020 김재경. All rights reserved.
//  특정 거리의 도시 찾기 with 나동빈 백준 18352번

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

#define MAX 300001
#define INF 1e9

vector<int>vN[MAX];
int d[MAX];

void solve(int start, int k)
{
    queue<int>q;
    q.push(start);
    d[start]=0;
    
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        
        for(int i=0; i<vN[x].size(); i++)
        {
            int n = vN[x][i];
            if(d[n]<0)
            {
                d[n] = d[x]+1;
                q.push(n);
            }
        }
    }
}

int main()
{
    int n,m,k,x;
    cin>>n>>m>>k>>x;
    
    fill(d, d+MAX, -1);
    
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        vN[a].push_back(b);
    }
    
    solve(x, k);
    
    vector<int>result;
    for(int i=1; i<10; i++)
    {
        if(d[i]==k)
            result.push_back(i);
    }
    
    if(result.size()==0)
        cout<<-1<<endl;
    else
    {
        for(int i=0; i<result.size(); i++)
        cout<<result[i]<<endl;
    }
    
    return 0;
}
