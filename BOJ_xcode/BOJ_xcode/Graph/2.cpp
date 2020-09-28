//
//  2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/28.
//  Copyright © 2020 김재경. All rights reserved.
//  전보 with 나동빈

#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정
#define MAX 30001

int n,m,C; // 도시개수 , 간선개수, 출발위치
vector<pair<int,int>>graph[MAX];
int distanceTable[MAX];

void solve()
{
    priority_queue<pair<int,int>>pq; //거리 , 인덱스
    
    pq.push(make_pair(0,C));
    distanceTable[C]=0;
    
    while(!pq.empty())
    {
        int cost = pq.top().first;
        int idx = pq.top().second;
        pq.pop();
        
        if(distanceTable[idx]<cost) //이미 최단 경로를 체크한 경우.
            continue;
        
        for(int i=0; i<graph[idx].size(); i++)
        {
            int nextIdx = graph[idx][i].first;
            int nextCost = graph[idx][i].second+cost;
            
            if(distanceTable[nextIdx] > nextCost)
            {
                distanceTable[nextIdx]=nextCost;
                pq.push(make_pair(nextCost, nextIdx));
            }
        }
    }
}

int main()
{
    cin>>n>>m>>C;
    
    for(int i=0; i<m; i++)
    {
        int x,y,z; // x에서 y로 가는 비용은 z다
        cin>>x>>y>>z;
        graph[x].push_back(make_pair(y,z));
    }
    
    fill(distanceTable,distanceTable+MAX,INF);
    solve();
    
    int resultCount =0;
    int resultMaxTime =0;
    for(int i=0; i<MAX; i++)
    {
        if(i==C)
            continue;
        
        if(distanceTable[i]<INF)
        {
            resultCount++;
            if(resultMaxTime < distanceTable[i])
                resultMaxTime = distanceTable[i];
        }
    }
    
    cout<<resultCount<<" "<<resultMaxTime<<endl;
    
    return 0;
}
