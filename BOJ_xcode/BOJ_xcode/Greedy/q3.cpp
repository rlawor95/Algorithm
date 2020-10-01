//
//  q3.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  문자열 뒤집기 with 나동빈 백준1439

#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int zero=0;
    int one=0;
    
    int swap = s[0] - '0' == 0 ? 1 : 0; // 반대껄로 초기화.
    for(int i=0; i<s.length(); i++)
    {
        int n = s[i] - '0';
        
        if(n!=swap) // 엇갈릴 때마다 1씩 추가
        {
            swap = n;
            
            if(n==0)
                zero++;
            else if(n==1)
                one++;
        }
    }
    
   cout<<min(zero,one)<<endl; //더 작은 값이 최소 뒤집기 횟수.
    
    return 0;
}
