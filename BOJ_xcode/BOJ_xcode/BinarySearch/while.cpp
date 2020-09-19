//
//  2.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/20.
//  Copyright © 2020 김재경. All rights reserved.
//  이진 탐색 반복문 구현

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int target, int start, int end)
{
    while (start <= end)
    {
        int mid = (start + end) / 2;
        
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            end = mid - 1;
        else
            start = mid + 1;
    }
    
    return -1;
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
