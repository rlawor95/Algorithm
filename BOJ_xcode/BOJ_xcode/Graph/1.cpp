//
//  1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/28.
//  Copyright © 2020 김재경. All rights reserved.
//  미래도시 with 나동빈
/*
 5 7
 1 2
 1 3
 1 4
 2 4
 3 4
 3 5
 4 5
 4 5
*/

#include <stdio.h>
#include <iostream>
using namespace std;
#define INF 1e9
#define MAX 101
int n, m; // 노드, 간선 개수
int x, k; // k -> x 거쳐야할 노드 인덱스
int graph[MAX][MAX];

int main()
{
    for (int i = 0; i < MAX; i++)
    {
        fill(graph[i], graph[i] + MAX, INF);
    }
    
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[a][b]=1;
        graph[b][a]=1; // 연결되있는 노드는 양방향 비용 1 이라는 조건이 있기에
    }
    cin>>x>>k;
    
    for(int c=1; c<=n; c++)
    {
        for(int b=1; b<=n; b++)
        {
            for(int a=1; a<=n; a++)
            {
                graph[a][b]=min(graph[a][b], graph[a][c] + graph[c][b]);
            }
        }
    }
    if(graph[1][k]+graph[k][x]>n)
        cout<<-1<<endl;
    else
        cout<<graph[1][k]+graph[k][x]<<endl;
    
    return 0;
}
