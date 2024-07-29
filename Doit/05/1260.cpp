/*
BOJ 1260.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.29
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void DFS(int v);
void BFS(int v);
vector<vector<int>> P;
vector<bool> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M, V;
    cin >> N >> M >> V;
    P.resize(N + 1);

    for (int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;

        P[start].push_back(end);
        P[end].push_back(start);
    }

    for (int i = 1; i <= N; i++){
        sort(P[i].begin(), P[i].end());
    }

    visited = vector<bool>(N + 1, false);
    DFS(V);
    cout << "\n";
    fill(visited.begin(), visited.end(), false);
    BFS(V);
    cout << "\n";
}

void DFS(int v){
    cout << v << " ";
    visited[v] = true;

    for (int i = 0; i < P[v].size(); i++){
        if(!visited[P[v][i]]){
            DFS(P[v][i]);
        }
    }
}

void BFS(int v){
    queue<int> myQueue;
    myQueue.push(v);
    visited[v] = true;

    while(!myQueue.empty()){
        int now = myQueue.front();
        myQueue.pop();
        cout << now << " ";

        for (int i = 0; i < P[now].size(); i++){
            if(!visited[P[now][i]]){
                myQueue.push(P[now][i]);
                visited[P[now][i]] = true;
            }
        }
    }
}