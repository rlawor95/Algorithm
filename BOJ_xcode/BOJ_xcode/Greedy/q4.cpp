//
//  q4.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  만들 수 없는 금액 with 나동빈

#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

//vector<int>vCoin;
//
//bool Do_I_making_money(int m)
//{
//    for(int i=0; i<vCoin.size(); i++)
//    {
//        if(m - vCoin[i] <0) //동전이 금액보다 큰 경우
//            continue;
//
//        m -= vCoin[i];
//        if(m == 0)
//            return true;
//    }
//    return false;
//}
//
//int main()
//{
//    int n;
//    cin>>n;
//
//    int max=0;
//    for(int i=0; i<n; i++)
//    {
//        int m;
//        cin>>m;
//        max+=m;
//
//        vCoin.push_back(m);
//    }
//
//    sort(vCoin.begin(), vCoin.end(), greater<int>()); // 내림차순 정렬
//
//    for(int i=1; i<=max+1; i++) // 못만드는 금액이 없다면 max +1 을 출력하게됨.
//    {
//        if(Do_I_making_money(i))
//            continue;
//        else
//        {
//            cout<<i<<endl;
//            return 0;
//        }
//    }
//
//    //cout<<-1<<endl; //못 만드는 금액이 없다면.
//
//    return 0;
//
//}

int n;
vector<int> arr;

int main(void)
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }

    sort(arr.begin(), arr.end());

    int target = 1;
    for (int i = 0; i < n; i++)
    {
        // 만들 수 없는 금액을 찾았을 때 반복 종료
        if (target < arr[i])
            break;
        target += arr[i];
    }

    // 만들 수 없는 금액 출력
    cout << target << '\n';
}
