//
//  5585.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/13.
//  Copyright © 2020 김재경. All rights reserved.
//  백준 5585번 거스름돈

#include<iostream>
using namespace std;

int bill = 1000;

int main()
{
    int count =0;
    int pay=0;
    cin>>pay;
    
    pay = bill -pay;
    
    while (pay>0)
    {
        if(pay / 500 >0)
        {
            pay -=500;
            count++;
        }
        else if(pay/100>0)
        {
            pay -=100;
            count++;
        }
        else if(pay/50>0)
        {
            pay -=50;
            count++;
        }
        else if(pay/10>0)
        {
            pay -=10;
            count++;
        }
        else if(pay/5>0)
        {
            pay-=5;
            count++;
        }
        else if(pay/1>0)
        {
            pay-=1;
            count++;
        }
    }
    
    cout<<count;
    
    return 0;
}
