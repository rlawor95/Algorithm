//
//  q1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/02.
//  Copyright © 2020 김재경. All rights reserved.
//  럭키 스트레이트 with 나동빈 (백준 18406)

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
using namespace std;

int main()
{
    int n;
    cin>>n;
    
    //자리수 구하기
    int square=1; //자리수 변수
    int div=1;
    while (div!=0)
    {
        div = n/pow(10, square);
        if(div>0)
            square += 2;
    }
    square -= 2; // 자리수가 10의 몇 제곱인지
    
    //해당 제곱의 절반의 반올림으로 나누면 절반으로 짤림
    int temp = pow(10,round((double)square/2));
    int leftvalue = n / temp;
    int rightvalue = n % temp;
    
    div = pow(10,square/2); // 각 자리를 나눌 수 초기화.
    
    int left =0,right =0;
    for(int i=square/2; i>=0; i--) //왼쪽값과 오른쪽값 각각을 맨 앞자리부터 나눈다.
    {
        left += leftvalue/div; //맨 앞자리부터 자른값을 변수에 저장
        leftvalue = leftvalue % div; // 잘른 값은 빼준다.
        
        right += rightvalue/div;
        rightvalue = rightvalue % div;
        
        div /=10;
    }
    
    if(left==right)
        cout<<"LUCKY"<<endl;
    else
        cout<<"READY"<<endl;
}
