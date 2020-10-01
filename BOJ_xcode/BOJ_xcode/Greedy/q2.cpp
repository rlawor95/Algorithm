//
//  q2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/01.
//  Copyright © 2020 김재경. All rights reserved.
//  곱하기 혹은 더하기 with 나동빈


#include <stdio.h>
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main()
{
    string s;
    cin>>s;
    
    int result = 0;
    
    for(int i=0; i<s.length(); i++)
    {
        int n = s[i] - '0';
        
        if((n+result) > (n*result))
            result += n;
        else
            result *= n;
    }
    
    cout<<result<<endl;
    
    return 0;
}
