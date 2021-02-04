//
//  q2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2021/01/31.
//  Copyright © 2021 김재경. All rights reserved.
//  프로그래머스 - 프린터

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include <functional>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<stack>
using namespace std;

queue<pair<int, int>>q_priority;
priority_queue<int>pq;


int solution(vector<int> priorities, int location)
{
    int answer = 0;
    
    for(auto i = 0; i< priorities.size(); i++)
    {
        pq.push(priorities[i]);
        q_priority.push(make_pair(priorities[i], i));
    }
    
    while (!pq.empty())
    {
        pair<int, int>pair = q_priority.front();
    
        
        if(pq.top()==pair.first)
        {
            answer++;
            pq.pop();
            q_priority.pop();
            
            if(pair.second==location)
                break;
        }
        else // 나올 순서가 아닐 때
        {
            q_priority.pop();
            q_priority.push(pair);
        }
    }
    
    return answer;
}


int main()
{
    
    vector<int>v = {1,1,9,1,1,1};
    int r =solution(v, 0);
    
    cout<<r<<endl;
    
    return 0;
}
