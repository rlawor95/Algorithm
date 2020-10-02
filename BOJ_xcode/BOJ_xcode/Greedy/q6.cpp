//
//  q6.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  무지의 먹방 라이브 카카오 신입 공채 문제

#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
#include <string>
using namespace std;

int solution(vector<int> food_times, long long k)
{
    int answer = 0;
    
    int idx=-1;
    while (true)
    {
        k--;
        idx++;
        if(idx>=food_times.size())
            idx=0;
        if(k<0)
            break;
        while(food_times[idx]==0)
        {
            idx++;
            if(idx>=food_times.size())
                idx=0;
        }
        food_times[idx]-=1;
    }
    answer = idx+1;
    
    return answer;
}

int main()
{
    vector<int>test;
    int k=5;
    test.push_back(3);
    test.push_back(1);
    test.push_back(2);
    int r = solution(test, k);
    
    cout<<r<<endl;
}
