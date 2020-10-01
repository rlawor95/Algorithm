//
//  1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  팀 결성 with 나동빈 서로소 집합 문제.

#include <stdio.h>
#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

#define MAX 100001

int v, e;
int parent[MAX];

int findParent(int x)
{
    if(x==parent[x])
        return x;
    return parent[x]=findParent(parent[x]);
}

void unionParent(int a,int b)
{
    int p_a = findParent(a);
    int p_b = findParent(b);
    
    if(p_a > p_b)
        parent[p_a] = p_b;
    else
        parent[p_b] = p_a;
}

int main()
{
    int n,m;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
    }
    
    for(int i=0; i<m; i++)
    {
        int which,a,b;
        cin>>which>>a>>b;
        
        if(which==0) // 팀 합치기(union)
        {
            unionParent(a, b);
        }
        else    //같은 팀 여부 확인
        {
            if(findParent(a) == findParent(b))
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
        
    }
    
    return 0;
}
