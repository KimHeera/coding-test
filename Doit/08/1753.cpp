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
#include <limits.h>
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

    int V, E, K;
    cin >> V >> E >> K;

    dist.resize(V + 1);
    fill(dist.begin(), dist.end(), INT_MAX);
    visited.resize(V + 1);
    fill(visited.begin(), visited.end(), false);
    arr.resize(V + 1);

    int u, v, w;
    for (int i = 0; i < E; i++){
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }

    dist[K] = 0;
    q.push(make_pair(0, K));

    while(!q.empty()){
        edge nowNode = q.top();

        q.pop();

        int now = nowNode.second;
        if (!visited[now]){
            visited[now] = true;

            for(edge n : arr[now]){
                if (dist[n.first] > dist[now] + n.second){
                    dist[n.first] = dist[now] + n.second;
                    q.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }

    for (int i = 1; i < V + 1; ++i){
        if (dist[i] == INT_MAX)
            cout << "INF" << "\n";
        else
            cout << dist[i] << "\n";
        
    }

    return 0;
}