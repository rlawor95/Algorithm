//
//  q3.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/03.
//  Copyright © 2020 김재경. All rights reserved.
//  문자열 압축 with 2020카카오 신입 공채
// https://programmers.co.kr/learn/courses/30/lessons/60057
// 실제 문제는 링크에서 풀어야하고 여기선 테스트 코드 작성

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

//int main()
//{
//    string s;
//    cin>>s;
//
//    int result =1001; // 가장 작은 값 출력
//
//    string repeat;
//    for(int i=1; i<=s.length()/2; i++)
//    {
//        bool compress=false;
//        repeat = s.substr(0,i);
//        int sum=0;
//
//        for(int j=i; j<s.length(); j+=i)
//        {
//            string check = s.substr(j,i);
//
//            if(check.compare(repeat)==0)// 같다면
//            {
//                compress=true;
//            }
//            else    // 다르다면
//            {
//                if(compress)
//                    sum += i+1;
//                else
//                {
//                    sum += repeat.length();
//
//                }
//                compress=false;
//                repeat =s.substr(j,i);
//            }
//
//            if(j+i >= s.length())
//            {
//                if(compress)
//                    sum += i+1;
//                else
//                {
//                    sum += repeat.length();
//                }
//            }
//        }
//
//       if(sum!=0)
//        result = min(result,sum);
//    }
//
//    cout<<result<<endl;
//
//    return 0;
//}

int solution(string s)
{
    int answer = s.size();
    // 1개 단위(step)부터 압축 단위를 늘려가며 확인
    for (int step = 1; step < s.size() / 2 + 1; step++)
    {
        string compressed = "";
        string prev = s.substr(0, step); // 앞에서부터 step만큼의 문자열 추출
        int cnt = 1;
        // 단위(step) 크기만큼 증가시키며 이전 문자열과 비교
        
        for (int j = step; j < s.size(); j += step)
        {
            // 이전 상태와 동일하다면 압축 횟수(count) 증가
            if (prev == s.substr(j, step))
                cnt += 1;
            // 다른 문자열이 나왔다면(더 이상 압축하지 못하는 경우라면)
            else
            {
                compressed += (cnt >= 2)? to_string(cnt) + prev : prev;
                prev = s.substr(j, step); // 다시 상태 초기화
                cnt = 1;
            }
        }
        // 남아있는 문자열에 대해서 처리
        compressed += (cnt >= 2)? to_string(cnt) + prev : prev;
        
        // 만들어지는 압축 문자열이 가장 짧은 것이 정답
        answer = min(answer, (int)compressed.size());
    }
    return answer;
}

int main()
{
    string s;
    cin>>s;
    cout<<solution(s);
}
