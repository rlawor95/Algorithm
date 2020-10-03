//
//  q4.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/10/03.
//  Copyright © 2020 김재경. All rights reserved.
//  자물쇠와 열쇠 with 2020 카카오 신입 공채
// https://programmers.co.kr/learn/courses/30/lessons/60059#

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;


// 다 회전할 필요없이 키의 1 위치만 알면 된다.
void RotateKey(vector<vector<int>>&key) // 시계방향으로 키를 회전시킨다.
{
    vector<vector<int>>temp = key;
    
    for(int i=0; i<key.size(); i++)
    {
        int r = (int)key[i].size()-1;
        
        for(int j=0; j<key[i].size(); j++)
        {
            key[i][j] = temp[r][i];
            r--;
        }
    }
}

vector<pair<int,int>>GetKeypair(vector<vector<int>>&key)
{
    vector<pair<int, int>>keypair;
    
    for(int i=0; i<key.size(); i++)
    {
        for(int j=0; j<key[i].size(); j++)
        {
            if(key[i][j]==1)
                keypair.push_back(make_pair(i, j));
        }
    }
    
    return keypair;
}

bool Check( vector<vector<int>>vLockMap, vector<vector<int>> lock, vector<vector<int>>key)
{
    for(int i = 0; i< lock.size(); i++)
    {
        int x = (int)key.size()-1+i;
        
        for(int j=0; j<lock[i].size(); j++)
        {
            int y = (int)key.size()-1+j;
            
            if(vLockMap[x][y]!=0)
                return false;
        }
    }
    return true;
}

void Debugkey(vector<vector<int>>&key)
{
    cout<<endl;
    for(int i=0; i<key.size(); i++)
    {
        for(int j=0; j<key[i].size(); j++)
        {
            cout<<key[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void Debugkeypair(vector<pair<int,int>>&keypair)
{
    for(int i=0; i<keypair.size(); i++)
    {
        cout<<keypair[i].first<<","<<keypair[i].second<<" ";
    }
    cout<<endl;
}


bool solution(vector<vector<int>> key, vector<vector<int>> lock)
{
    bool answer = false;
    
    vector<pair<int, int>>keypair = GetKeypair(key); // 키 좌표 초기화.
    
    int size =(int)(lock.size() + (key.size()-1) *2);
    vector<vector<int>>vLockMap(size,vector<int>(size));
    fill(vLockMap.begin(), vLockMap.end(), vector<int>(size,2)); // padding 영역은 2로 초기화
    
    for(int i = 0; i< lock.size(); i++)
    {
        int x = (int)key.size()-1+i;
        
        for(int j=0; j<lock[i].size(); j++)
        {
            int y = (int)key.size()-1+j;
            
            if(lock[i][j]==0)
                vLockMap[x][y] = 1;
            else
                vLockMap[x][y]=0;
        }
    }
    
    for(int i=0; i<vLockMap.size(); i++)
    {
        for(int j=0; j<vLockMap[i].size(); j++)
        {
            cout<<vLockMap[i][j]<<" ";
        }
        cout<<endl;
    }
    
    //check
    for(int c=0; c<4; c++)
    {
        RotateKey(key);
        keypair = GetKeypair(key);
        
        for(int i=0; i<vLockMap.size() - key.size(); i++)
        {
            for(int j=0; j<vLockMap[i].size() -key.size(); j++)
            {
                for(int k=0; k<keypair.size(); k++)
                {
                    int x = keypair[k].first+i;
                    int y = keypair[k].second+j;
                    
                    vLockMap[x][y] -= 1;
                }
        
                if(Check(vLockMap,lock,key))
                    return true;
                else
                {
                    for(int k=0; k<keypair.size(); k++)
                    {
                        int x = keypair[k].first+i;
                        int y = keypair[k].second+j;
                        vLockMap[x][y] += 1;
                    }
                }
            }
        }
    }
    return answer;
}



int main()
{
    vector<vector<int>>vKey;
    vector<vector<int>>vLock;
    
    vKey.push_back({0,0,0});
    vKey.push_back({1,0,0});
    vKey.push_back({0,1,1});
    
    vLock.push_back({1,1,1});
    vLock.push_back({1,1,0});
    vLock.push_back({1,0,1});
    
    //vector<vector<int>>vLockMap(3,vector<int>(3));
    
    cout<<solution(vKey,vLock)<<endl;
    
    
    return 0;
}
