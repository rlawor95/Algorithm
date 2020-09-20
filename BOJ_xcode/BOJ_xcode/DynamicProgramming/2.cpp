//
//  2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/20.
//  Copyright © 2020 김재경. All rights reserved.
//  개미전사 with 나동빈

#include <stdio.h>
#include <iostream>
using namespace std;

int DP[1000];


// 점화식은 DP[idx] = MAX(DP[idx-1], value+DP[idx-2])
void solve(int idx, int value)
{
    if(idx==0)      //0번째 인덱스는 비교할게 없으니 그냥 넣는다.
        DP[idx] =value;
    else if(idx==1) // 0번째 보다 크다면 값을 갱신하고 0번쨰 인덱스보다 작다면 0번째 인덱스로 입력
        DP[idx] = max(DP[0],value);
    else            
        DP[idx] = max(DP[idx-1], value+DP[idx-2]);
}

int main()
{
    int cnt;
    cin>>cnt;
    
    for(int i=0; i<cnt; i++)
    {
        int v;
        cin>>v;
        solve(i, v);
    }
    
    cout<<DP[cnt-1]<<endl;
    
    return 0;
}
