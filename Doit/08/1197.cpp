/*
BOJ 1197.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.06.27
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void Nunion(int a, int b);
int find(int a);
static vector<int> parent;

typedef struct Edge {
    int s, e, v;

    bool operator> (const Edge& temp) const{
        return v > temp.v;
    }
} Edge;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, E;
    cin >> N >> E;

    priority_queue<Edge, vector<Edge>, greater<Edge>> pq;
    parent.resize(N + 1);

    for (int i = 0; i <= N; i++){
        parent[i] = i;
    }

    for (int i = 0; i < E; i++){
        int s, e, v;
        cin >> s >> e >> v;

        pq.push(Edge{s, e, v});
    }

    int useEdge = 0;
    int result = 0;

    while (useEdge < N - 1){
        Edge now = pq.top();
        pq.pop();

        if(find(now.s) != find(now.e)){
            Nunion(now.s, now.e);
            result += now.v;
            useEdge++;
        }
    }

    cout << result;
}

void Nunion(int a, int b){
    a = find(a);
    b = find(b);

    if(a != b)
        parent[b] = a;
}

int find(int a){
    if(a == parent[a])
        return a;
    else{
        return parent[a] = find(parent[a]);
    }
}