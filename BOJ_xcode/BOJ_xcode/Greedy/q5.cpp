//
//  q5.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  볼링공 고르기 with 나동빈 (2019 SW 마에스트로 입학 테스트)

#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//vector<int>vBall;
//
//int main()
//{
//    int result=0;
//    int n,m;
//    cin>>n>>m;
//
//    for(int i=0; i<n; i++)
//    {
//        int v;
//        cin>>v;
//        vBall.push_back(v);
//    }
//
//    for(int i=0; i<vBall.size()-1; i++)
//    {
//        for(int j=i+1; j<vBall.size(); j++)
//        {
//            if(vBall[i] != vBall[j])
//                result++;
//        }
//    }
//
//    cout<<result<<endl;
//
//    return 0;
//}

int n, m;
// 1부터 10까지의 무게를 담을 수 있는 배열
int arr[11];

int main(void)
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr[x] += 1;
    }

    int result = 0;

    // 1부터 m까지의 각 무게에 대하여 처리
    for (int i = 1; i <= m; i++)
    {
        n -= arr[i]; // 무게가 i인 볼링공의 개수(A가 선택할 수 있는 개수) 제외
        result += arr[i] * n; // B가 선택하는 경우의 수와 곱해주기
    }

    cout << result << '\n';
}
