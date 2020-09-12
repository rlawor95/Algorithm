//백준 18352번 특정 거리의 도시 찾기
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> result; // 결과를 저장할 벡터
vector<int> *graph;
int visit[300001] = {
    -1,
};

// void BFS(int start, int k)
// {
//     queue<int> q; // 탐색 큐
//     int dis = -1; // 시작 위치 기준으로 거리
//     int loopcnt = 0;

//     q.push(start);
//     vector<int>::iterator iter;
//     while (k > dis)
//     {
//         dis++;
//         int cnt = q.size();
//         for (int i = 0; i < cnt; i++)
//         {
//             int idx = q.front();
//             q.pop();

//             if (visit[idx] < 0)
//             {
//                 visit[idx] = dis;
//             }
//             if (visit[idx] == k)
//                 result.push_back(idx);

//             for (iter = graph[idx].begin(); iter < graph[idx].end(); iter++)
//             {
//                 q.push(*iter);
//             }
//         }
//     }
// }

void BFS(int start, int k)
{
    queue<int> q; // 탐색 큐
    int dis = -1; // 시작 위치 기준으로 거리
    q.push(start);
    // visit[start] = dis;
    vector<int>::iterator iter;

    while (!q.empty())
    {
        dis++;
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            int idx = q.front();
            q.pop();

            if (visit[idx] < 0)
                visit[idx] = dis;
            if (visit[idx] == k)
                result.push_back(idx);

            for (iter = graph[idx].begin(); iter < graph[idx].end(); iter++)
            {
                q.push(*iter);
            }
        }
    }
}

int main(void)
{
    fill(visit, visit + 300001, -1);
    int n, m, k, x = 0;
    cin >> n >> m >> k >> x;

    graph = new vector<int>[n + 1]; // 인덱스 편하게 계산하기 위해 +1로 초기화

    for (int i = 0; i < m; i++)
    {
        int a, b = 0;
        cin >> a >> b;
        graph[a].push_back(b);
    }

    BFS(x, k);

    int t = -1;
    if (result.size() == 0)
        cout << t;
    else
    {
        sort(result.begin(), result.end());
        for (int i = 0; i < result.size(); i++)
            cout << result[i] << endl;
    }

    for (int i = 0; i < 10; i++)
        cout << visit[i] << " ";

    return 0;
}
