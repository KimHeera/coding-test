/*
BOJ 1916.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.04.30
*/

#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

static int N, M;
typedef pair<int, int> edge;
static vector<vector<edge> > arr;
static vector<int> dist;
static vector <bool> visited;
int dijkstra(int start, int end);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int s, a, c;
    cin >> N >> M;
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), INT_MAX);
    visited.resize(N + 1);
    fill(visited.begin(), visited.end(), false);
    arr.resize(N + 1);

    for (int i = 0; i < M; i++){
        cin >> s >> a >> c;
        arr[s].push_back(make_pair(a, c));
    }

    cin >> s >> a;
    int result = dijkstra(s, a);
    cout << result << "\n";

    return 0;
}

int dijkstra(int start, int end){
    priority_queue<edge, vector<edge>, greater<edge> > pq;
    //비용 기준 정렬을 위해 데이터 순서를 비용, 노드로 설정

    pq.push(make_pair(0, start));
    dist[start] = 0;

    while(!pq.empty()){
        edge nowNode = pq.top();
        pq.pop();
        int now = nowNode.second;

        if(!visited[now]){
            visited[now] = true;

            for(edge n : arr[now]){
                if(dist[n.first] > dist[now] + n.second){
                    dist[n.first] = dist[now] + n.second;
                    pq.push(make_pair(dist[n.first], n.first));
                }
            }
        }
    }

    return dist[end];
}