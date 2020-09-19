//
//  1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2020/09/19.
//  Copyright © 2020 김재경. All rights reserved.
// 성적이 낮은 순서로 학생 출력하기 with 나동빈
// 계수 정렬 ?

#include <stdio.h>
#include <iostream>
#include<vector>
using namespace std;

struct Student
{
    int score;
    string name;
    
    Student(string n,int s)
    {
        score    = s;
        name =n;
    }
    
    // 정렬 기준은 '점수가 낮은 순서'
       bool operator <(Student other) const{
           return this->score < other.score;
       }
};

bool compare(Student a, Student b)
{
    return a.score<b.score;
}

vector<Student>vStudent;

int main()
{
    
    int cnt;
    cin>>cnt;
    
    
    for(int i=0; i<cnt; i++)
    {
        int score;
        string name;
        
        cin>>name>>score;
        Student s(name,score);
        vStudent.push_back(s);
    }
    
    sort(vStudent.begin(), vStudent.end());
    
    vector<Student>::iterator iter;
    for(iter=vStudent.begin(); iter<vStudent.end(); iter++)
    {
        cout<<iter->name<<" ";
    }
    
    return 0;
}
