/*
BOJ 1753.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.05.07
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge> > arr; //그래프 정보 저장
vector<int> dist; //최단 거리 저장
vector<bool> visited; //노드 방문 여부
priority_queue<edge, vector<edge>, greater<edge> > q;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, INT_MAX, sizeof(dp));

    int V, E, K;
    cin >> V >> E >> K;

    int u, v, w;
    for (int i = 0; i < E; i++){
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }

    dp[K] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(0, K));

    while(!pq.empty()){
        int current = pq.top().second;

        int start_to_current_distance = -pq.top().first;

        pq.pop();

        if (dp[current] < start_to_current_distance)
            continue;

        for (int i = 0; i < arr[current].size(); ++i){
            int next = arr[current][i].first;
            int start_to_next_distance = start_to_current_distance + arr[current][i].second;

            if (dp[next] > start_to_next_distance){
                dp[next] = start_to_next_distance;

                pq.push(make_pair(-start_to_next_distance, next));
            }
        }
    }


    for (int i = 1; i < V + 1; ++i){
        if (dp[i] > INF)
            cout << "INF" << "\n";
        else
            cout << dp[i] << "\n";
        
    }

    return 0;
}
