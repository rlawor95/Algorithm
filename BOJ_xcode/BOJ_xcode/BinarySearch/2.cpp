//
//  2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/20.
//  Copyright © 2020 김재경. All rights reserved.
//  떡볶이 떡 만들기 with 나동빈 파라메트릭 서치

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int Search(vector<int>&arr,int target, int start,int end) // start = 0, end 가장 긴 떡의 길이.
{
    
    //인덱스 값을 찾는게 아니고 값을 찾고 인덱스들과 검사해서 유효한지 검사해야함.
    while(start<=end)
    {
        int cakelen=0;
        int mid = (start+end)/2;
        
        for(int i=0; i<arr.size(); i++)
        {
            if(arr[i]>mid)
            {
                cakelen+= arr[i]-mid;
            }
            else
                break;
        }
        
        if(cakelen == target)
            return mid;
        else if(cakelen>target)
            start = mid+1;
        else
            end = mid-1;
    }
    
    return -1;
}

vector<int>cakes;
int main()
{
    int cnt,h;
    cin >> cnt >>h;
    for(int i=0; i<cnt; i++)
    {
        int t;
        cin>>t;
        cakes.push_back(t);
    }
    sort(cakes.begin(),cakes.end(),greater<int>());
    
    cout<<Search(cakes, h, 0, cakes[0])<<endl;
    
    
    return 0;
}
