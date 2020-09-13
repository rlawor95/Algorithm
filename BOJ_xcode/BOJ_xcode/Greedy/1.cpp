//
//  1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/13.
//  Copyright © 2020 김재경. All rights reserved.
//  큰 수의 법칙. with 나동빈

#include<iostream>
#include<vector>
using namespace std;

/*
 10 10 5
 12 13 50 34 58 4 5 6 34 67
 661


 10 10 3
 12 13 50 34 58 4 5 6 34 67
 652

 10 9 6
 12 13 50 34 58 4 5 6 34 123
 1042
 */

int main()
{
    int n,m,k =0;
    vector<int>v;

    cin>>n>>m>>k;

    for(int i=0; i<n; i++)
    {
        int t=0;
        cin>>t;
        v.push_back(t);
    }

    sort(v.begin(),v.end(),greater<int>());

    int cnt=0;
    int result=0;

    while(m>0)
    {
        m--; //연산횟수 --

        if(cnt<k)  // 연속으로 더 할 수 있다면
        {
            result += v[0];
            cnt++;
        }
        else
        {
            result += v[1];
            cnt=0;
        }
    }

    cout<<result<<endl;
    return 0;
}

//int n, m, k;
//vector<int> v;
//
//int main() {
//    // N, M, K를 공백을 기준으로 구분하여 입력 받기
//    cin >> n >> m >> k;
//
//    // N개의 수를 공백을 기준으로 구분하여 입력 받기
//    for (int i = 0; i < n; i++) {
//        int x;
//        cin >> x;
//        v.push_back(x);
//    }
//
//    sort(v.begin(), v.end()); // 입력 받은 수들 정렬하기
//    int first = v[n - 1]; // 가장 큰 수
//    int second = v[n - 2]; // 두 번째로 큰 수
//
//    // 가장 큰 수가 더해지는 횟수 계산
//    int cnt = (m / (k + 1)) * k;
//    cnt += m % (k + 1);
//
//    int result = 0;
//    result += cnt * first; // 가장 큰 수 더하기
//    result += (m - cnt) * second; // 두 번째로 큰 수 더하기
//
//    cout << result << '\n'; // 최종 답안 출력
//}
