//
//  q7.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2021/02/04.
//  Copyright © 2021 김재경. All rights reserved.
//  프로그래머스 - 조이스틱 , 그리디 알고리즘 lv2

#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <string>
#include <iostream>
using namespace std;


int solution(string name)
{
    int answer = 0;
    
    char*str = new char[name.length()+1];
    memset(str, 'A', sizeof(char)*name.length());
    str[name.length()] = '\0';
    
    int cur=0;
    int idx=0;
    while(strcmp(str, name.c_str())!= 0)
    {
        int minDis = 20; // name의 최대 길이가 20으로 제한
        //변환할 위치 찾기
        for(int i=0; i<name.length(); i++)
        {
            if(name[i]==str[i])
                continue;
            
            int dis = min(abs(cur - i), abs(((int)(name.length()-1)- i+ cur + 1)));
            if(dis < minDis)
            {
                idx=i;
                minDis = dis;
            }
        }
        cur=idx;
        cout<<"minDis : "<<minDis <<" cur : "<<cur<<endl;
        answer += minDis;
        
        //변환할 알파벳
        int targetCode = name[cur];
        int curCode = str[cur];
        cout<<"targetCode : "<<targetCode <<" curCode : "<<curCode<<endl;
        int minCnt = min(abs(targetCode-curCode), abs(90-targetCode+1));
        cout<<"minCnt : "<<minCnt<<endl;
        answer += minCnt;
        str[cur]=name[cur];
        cout<<"str : "<<str<<endl<<endl;
        
        //문자 변환
    }
    
    delete [] str;
    return answer;
}

int main()
{
    cout<<solution("JAN")<<endl;
    
    return 0;
}
