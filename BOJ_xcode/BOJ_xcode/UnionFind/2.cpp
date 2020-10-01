//
//  2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  도시 분할 계획 백준 1647 , with 나동빈
//  크루스칼 알고리즘

#include <stdio.h>
#include <stdio.h>
#include<iostream>
#include<vector>
#include<tuple>
#include<algorithm>
#include<queue>
using namespace std;

#define MAX 100001

int parent[MAX];
//vector<pair<int,pair<int,int>>>edges;
vector<tuple<int,int,int>>vEdges;

// 특정 원소가 속한 집합을 찾기
int findParent(int x)
{
    // 루트 노드가 아니라면, 루트 노드를 찾을 때까지 재귀적으로 호출
    if (x == parent[x])
        return x;
    return parent[x] = findParent(parent[x]);
}

// 두 원소가 속한 집합을 합치기
void unionParent(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main()
{
    int n,m,result =0;
    cin>>n>>m;
    
    for(int i=1; i<=n; i++)
    {
        parent[i]=i;
    }
    
    for(int i=0; i<m; i++)
    {
        int a,b,c;
        cin>>a>>b>>c;
        vEdges.push_back(make_tuple(c,a,b));
    }
    
    sort(vEdges.begin(),vEdges.end());
    
    int maxCost = 0;
    for(int i=0; i<vEdges.size(); i++)
    {
        int cost = get<0>(vEdges[i]);
        int a = get<1>(vEdges[i]);
        int b = get<2>(vEdges[i]);
        
        if(findParent(a)!=findParent(b))
        {
            unionParent(a, b);
            if(cost>maxCost)
                maxCost=cost;
            result+=cost;
        }
    }
    
    cout<<result-maxCost<<endl;
    
    
    return 0;
}
