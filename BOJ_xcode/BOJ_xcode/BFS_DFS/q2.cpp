//
//  q2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/09.
//  Copyright © 2020 김재경. All rights reserved.
//  연구소 백준14502 with 삼성전자sw역량테스트

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

#define MAX 8

int map[MAX][MAX];
int n,m;

int dx[4] = {0,0,-1,1};
int dy[4] = {-1,1,0,0};

void BFS(int ptrMap[][MAX], pair<int, int>start) // start는 바이러스의 위치
{
    queue<pair<int, int>>q;
    q.push(start);
    ptrMap[start.first][start.second]=2;
    
    while (!q.empty())
    {
        pair<int, int>x = q.front();
        q.pop();
        
        for(int i=0; i<4; i++)
        {
            if(x.first+dx[i]<0 || x.first+dx[i]>=n ||
               x.second+dy[i]<0 || x.second+dy[i]>=m) // 배열 밖인 경우 (범위 확인 필수)
                continue;
            
            if(ptrMap[x.first+dx[i]][x.second+dy[i]] == 0) // 빈 공간이면
            {
                int n_x = x.first+dx[i];
                int n_y = x.second+dy[i];
                ptrMap[n_x][n_y]=2; //감염
                
                q.push(make_pair(n_x, n_y));
            }
        }
    }
}

int solve(int ptrMap[][MAX])
{
    int result=0;
    int mapcopy[MAX][MAX];
    memcpy(mapcopy, ptrMap, sizeof(map)); // 다른 메모리에 카피
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mapcopy[i][j]==2)
                BFS(mapcopy, make_pair(i, j));
        }
    }
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mapcopy[i][j]==0)
                result++;
        }
    }
    
    return result;
}

void shwoDebug()
{
    //    //칸 데이터 출력
    cout<<endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cout<<  map[i][j]<<" "; // 0-빈칸, 1-벽, 2-바이러스
        }
        cout<<endl;
    }
}

int main()
{
    int result = 0; // 나올 수 없는 최대값으로 초기화
    cin>>n>>m;
    
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            int type=0;
            cin>>type;
            map[i][j] =type; // 0-빈칸, 1-벽, 2-바이러스
        }
    }
    
    int a=0, b=0, c=0; // 벽 3개
    while (a<n*m)
    {
        if(map[a/m][a%m]==0)
        {
            b = a+1;
            map[a/m][a%m] =1;
            while (b<n*m)
            {
                if(map[b/m][b%m] ==0)
                {
                    map[b/m][b%m] =1;
                    c= b+1;
                    while (c<n*m)
                    {
                        if(map[c/m][c%m]==0)
                        {
                            map[c/m][c%m] =1;
                            int r = solve(map);
                            result = max(result, r);
                            map[c/m][c%m] =0;
                        }
                        c++;
                    }
                    
                    map[b/m][b%m] =0;
                }
                b++;
            }
            map[a/m][a%m] =0;
        }
        a++;
    }
    
    
    cout<<result<<endl;
    return 0;
}
