//
//  1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/20.
//  Copyright © 2020 김재경. All rights reserved.
//  이진 탐색 재귀 함수 버전

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>&arr, int target, int start, int end)
{
    if(start>end)
        return -1;
    
    int mid = (start+end)/2;
    
    if(arr[mid]==target)
        return mid;
    else if(arr[mid]>target)   // 중간점의 값보다 찾고자 하는 값이 작은 경우 왼쪽 확인
        return binarySearch(arr,target,start,mid-1);    // end값이 점차 줄며 값이 없는 경우 start값보다 작아진다. 
    else                          // 중간점의 값보다 찾고자 하는 값이 큰 경우 오른쪽 확인
        return binarySearch(arr,target,mid+1,end);  // start 값이 점차 증가하며 값이 없는 경우 end값을 넘긴다.
}

int n, target;
vector<int> arr;
int main()
{
    cin>>n >>target; // 원소의 개수와 찾고자 하는 값.
    
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        arr.push_back(x);
    }
    
    int result = binarySearch(arr, target, 0, n - 1);
    if (result == -1)
    {
        cout << "원소가 존재하지 않습니다." << '\n';
    }
    else
    {
        cout << result + 1 << '\n';
    }
    return 0;
}
