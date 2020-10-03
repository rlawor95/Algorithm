//
//  q2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/02.
//  Copyright © 2020 김재경. All rights reserved.
//  문자열 재정렬 with 나동빈 (facebook 인터뷰)

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
using namespace std;

int main()
{
    vector<char>vChar;
    int num=0;
    string str;
    cin>>str;
    
    for(int i=0; i<str.length(); i++)
    {
        if((int)str[i]>57)
            vChar.push_back(str[i]);
        else
            num += (int)str[i]-'0';
    }
    
    sort(vChar.begin(), vChar.end());
    
    for(int i=0; i<vChar.size(); i++)
    cout<<vChar[i];
    
    if(num>0)
    cout<<num<<endl;
    
    return 0;
    
}
