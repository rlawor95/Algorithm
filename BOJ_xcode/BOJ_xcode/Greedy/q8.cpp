//
//  q8.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2021/02/06.
//  Copyright © 2021 김재경. All rights reserved.
//  프로그래머스 - 섬 연결하기 

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include <functional>
#include <algorithm>
#include<unordered_map>
#include<map>
#include<stack>
using namespace std;

int table[100]; // 사이클 체크

bool cmp(vector<int>&a , vector<int>&b)
{
    return a[2]<b[2];
}

int CheckTable(int x)
{
    if (x == table[x])
        return x;
    
    return table[x] = CheckTable(table[x]);
}

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    
    for(int i=0; i<n; i++)
    {
        table[i] =i;
    }
    
    sort(costs.begin(), costs.end(),cmp); // 비용 오름차순으로 정렬
    
    for(int i=0; i<costs.size(); i++)
    {
        int cost = costs[i][2];
        
        int a = CheckTable(costs[i][0]);
        int b = CheckTable(costs[i][1]);
        
        if(a!=b) // 사이클이 발생하지 않으면 트루
        {
            if(a>b)
                table[b] = table[a];
            else
                table[a] = table[a];
            
            /*
             if(a>b)
                table[costs[i][0]] = costs[i][1];
            else
                table[costs[i][1]] = costs[i][0];
             */
            
            answer += cost;
        }
    }
               
    return answer;
}

int main()
{
    vector<vector<int>>v;
    v.push_back({0,1,1});
    v.push_back({0,2,2});
    v.push_back({1,2,5});
    v.push_back({1,3,1});
    v.push_back({2,3,8});
    
    cout<<solution(4, v)<<endl;
    return 0;
}
