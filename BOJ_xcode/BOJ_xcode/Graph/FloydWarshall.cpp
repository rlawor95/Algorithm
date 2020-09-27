//
//  FloydWarshall.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/27.
//  Copyright © 2020 김재경. All rights reserved.
//  플로이드 워셜 알고리즘 with 나동빈

#include <stdio.h>
#include <stdio.h>
#include<iostream>
#include<vector>
using namespace std;
#define INF 1e9 // 무한을 의미하는 값으로 10억을 설정

// 노드의 개수(N), 간선의 개수(M)
// 노드의 개수는 최대 500개라고 가정
int n, m;
// 2차원 배열(그래프 표현)를 만들기
int graph[501][501];

int main(void)
{
    // 최단 거리 테이블을 모두 무한으로 초기화
    for (int i = 0; i < 501; i++)
    {
        fill(graph[i], graph[i] + 501, INF);
    }
    
    // 자기 자신에서 자기 자신으로 가는 비용은 0으로 초기화
    for (int a = 1; a <= n; a++)
    {
        for (int b = 1; b <= n; b++)
        {
            if (a == b)
                graph[a][b] = 0;
        }
    }
    
    // 각 간선에 대한 정보를 입력 받아, 그 값으로 초기화
    for (int i = 0; i < m; i++)
    {
        // A에서 B로 가는 비용은 C라고 설정
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = c;
    }
    
    // 점화식에 따라 플로이드 워셜 알고리즘을 수행
    // 1번 노드를 거쳐서 가는거 부터 시작해서
    // 모든 노드를 거쳐서 가는 경우를 전부 체크해서 가장 작은 값으로 업데이트한다.
    for (int k = 1; k <= n; k++)
    {
        for (int a = 1; a <= n; a++)
        {
            for (int b = 1; b <= n; b++)
            {
                graph[a][b] = min(graph[a][b], graph[a][k] + graph[k][b]);
            }
        }
    }
}
