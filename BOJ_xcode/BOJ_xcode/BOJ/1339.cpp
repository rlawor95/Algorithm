//
//  1339.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/04.
//  Copyright © 2020 김재경. All rights reserved.
//  백준 1339 단어수학

#include <stdio.h>
#include<iostream>
#include <algorithm>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include<numeric>
#include<string.h>
#include<string>
using namespace std;

#define MAX 26
//int alphabet[MAX]; //A~J 순서대로
vector<int>alphabet(MAX);


int main()
{
    //fill(alphabet, alphabet+MAX, 10); // 0~9 까지니까  초기값은 10으로 세팅
    int n;
    cin>>n;

    for(int i=0; i<n; i++)
    {
        string str;
        cin>>str;
        
        for(int j=0; j<str.length(); j++)
        {
            alphabet[str[j]-'A'] += pow(10, str.length() - j - 1);
        }
    }
            
    for(int i=0; i<alphabet.size(); )
    {
        if(alphabet[i]==0)
            alphabet.erase(alphabet.begin()+i);
        else
            i++;
    }
    
    sort(alphabet.begin(), alphabet.end(), greater<int>());
    
    int result=0;
    int value =9;
    for(int i=0; i<alphabet.size(); i++)
    {
        result+= alphabet[i]*value;
        value--;
    }
    
    cout<<result<<endl;
    return 0;
}


//int main()
//{
//
//    int N;
//    cin>>N;
//
//    //'A'=65
//    int alphabet[26]={0};
//    string s;
//    for(int i=0;i<N;i++)
//    {
//        cin>>s;
//        for(int j=0;j<s.length();j++)
//        {
//            alphabet[s[j]-65]+=(int)pow(10,s.length()-j-1);
//        }
//    }
//
//    int ans=0;
//    vector<int> vec; //존재하는 알파벳 담는 배열
//    for(int i=0;i<26;i++)
//    {
//        if(alphabet[i])
//        {
//            vec.push_back(alphabet[i]);
//        }
//    }
//
//    int cnt=9;
//    sort(vec.begin(),vec.end(),greater<int>()); //내림차순 정렬
//
//    for(int i=0;i<vec.size();i++)
//    {
//        ans+=vec[i]*(cnt--);
//    }
//    cout<<ans<<endl;
//    return 0;
//}
