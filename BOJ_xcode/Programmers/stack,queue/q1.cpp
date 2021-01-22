//
//  q1.cpp
//  BOJ_xcode
//
//  Created by 김재경 on 2021/01/14.
//  Copyright © 2021 김재경. All rights reserved.
//  프로그래머스 - 다리를 지나는 트럭

#include <stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
#include<queue>
#include<string>
#include<cstring>
#include <functional>
#include<algorithm>
#include<unordered_map>
#include<map>
#include<stack>
using namespace std;

//int solution(int bridge_length, int weight, vector<int> truck_weights)
//{
//    //현재 도로에 올라가져있는 차 무게
//    int answer = 0, currentWeight = 0;
//    //도로에 올라가져있는차, 차마다 남은 거리
//    queue<int> count, bridgeOn;
//    while (true)
//    {
//        //중간에 차가 빠져나가면 계산이 바뀌기때문에 size고정
//        int size = bridgeOn.size();
//
//        for (int i = 0; i < size; i++)
//        {
//            int length = bridgeOn.front();
//            bridgeOn.pop();
//            //도로 남은길이가 없다면
//            if (length <= 1)
//            {
//                //도로에서 현재차 무게를 제외
//                currentWeight -= count.front();
//                //도로에 올라가져 있는차 제외
//                count.pop();
//                continue;
//            }
//            //남아있다면 길이감소후 다시넣기
//            bridgeOn.push(length - 1);
//        }
//
//        //대기차가 1대이상 있고 도로가 무게를 견딜 수 있다면
//        if (truck_weights.size() > 0 && currentWeight + truck_weights.at(0) <= weight)
//        {
//            //도로에 올라가져있는 차 추가
//            count.push(truck_weights.at(0));
//            //현재 올라가져있는 무게 추가
//            currentWeight += truck_weights.at(0);
//            //남은 도로거리 추가
//            bridgeOn.push(bridge_length);
//            //대기차량 삭제
//            truck_weights.erase(truck_weights.begin());
//        }
//        //시간초 증가
//        answer++;
//        //도로에 올라가져있는차와 대기차가 모두없다면 반복문 탈출
//        if (truck_weights.size() == 0 && count.size() == 0)
//            break;
//    }
//    return answer;
//}

//int solution(int bridge_length, int weight, vector<int> truck_weights)
//{
//    int answer = 0;
//
//    int curTime = 1; // 현재 시간
//    int curIdx=0; // 현재 몇번쨰 트럭인지
//    int curWeight = 0; // 다리위에 올라간 트럭의 총 무게
//
//    queue<pair<int, int>>truckOnBridge; // 트럭위에 올라간 트럭의 정보 <무게, 다리를 다 지나갔을 떄의 종료 시간>
//
//    while (curIdx < truck_weights.size() || !truckOnBridge.empty())
//    {
//        if(!truckOnBridge.empty()) // 다리위에 트럭이 있는지
//        {
//            if(truckOnBridge.front().second == curTime) // 트럭이 다리를 다 지났는지 체크
//            {
//                curWeight -= truckOnBridge.front().first;
//                truckOnBridge.pop(); // 다리에서 트럭을 뺌
//            }
//        }
//
//        //다리에 트럭을 더 올릴 수 있느지
//        if(curWeight <= weight && curIdx < truck_weights.size() && curWeight+truck_weights[curIdx] <= weight)
//        {
//            truckOnBridge.push(make_pair(truck_weights[curIdx], bridge_length+curTime));
//            curWeight +=truck_weights[curIdx];
//            curTime++;
//            curIdx++;
//        }
//        else // 다리에 더 이상 트럭을 올릴 수 없으면 타임워프
//        {
//            if(!truckOnBridge.empty())
//            curTime = truckOnBridge.front().second;
//        }
//    }
//
//    answer = curTime;
//
//    return answer;
//}

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    int answer = 0;

    int tot_w = 0;

    int t_front = 0;
    int t_cur = 0;

    int sec = 0;

    queue <int> q;

    while (t_front != truck_weights.size())
    {
        if (!q.empty() && (sec - q.front() == bridge_length))
        {
            tot_w -= truck_weights[t_front];
            ++t_front;
            q.pop();
        }
        
        if (t_cur != truck_weights.size() && tot_w + truck_weights[t_cur] <= weight)
        {
            tot_w += truck_weights[t_cur];
            ++t_cur;
            q.push(sec);
        }
        ++sec;
    }

    answer = sec;

    return answer;
}

void print(int bridge_length, int weight, vector<int> truck_weights, int answer)
{
    int t = solution(bridge_length, weight, truck_weights);
    cout << t << " , ";
    if (t == answer)
        cout << "정답" << endl;
    else
        cout << "틀림" << endl;
}
 
int main()
{
    print(100, 100, { 10,10,10,10,10,10,10,10,10,10 }, 110);
    //print(2, 10, { 7,4,5,6 }, 8);
    //print(100, 100, { 10 }, 101);
 
    return 0;
}
