//
//  4344.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/04.
//  Copyright © 2020 김재경. All rights reserved.
//  백준 4344 평균은 넘겠지

#include <stdio.h>
#include<iostream>
#include <algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<numeric>
using namespace std;

#define MAX 1000
vector<int>v[MAX];
int average[MAX];

int main()
{
    int n;
    cin>>n;
    
    for(int i=0; i<n; i++)
    {
        int m, score;
        cin>>m;
        
        for(int j =0; j<m; j++)
        {
            cin>>score;
            v[i].push_back(score);
        }
        
        float avg = accumulate(v[i].begin(), v[i].end(), 0.0f)/ v[i].size();
        
        int cnt=0;
        for(int j=0; j<m; j++)
        {
            if(v[i][j]>avg)
                cnt++;
        }
        
        float studAvg =  ((float)cnt/v[i].size())*100;
        studAvg =  round(studAvg*1000)/1000;
        //cout.precision(3);
        //cout<<studAvg<<"%"<<endl;
        printf("%.3f",studAvg);
        cout<<"%"<<endl;
    }
    
    return 0;
}
