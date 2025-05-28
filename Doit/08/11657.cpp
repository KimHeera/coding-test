/*
BOJ 11657.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.05.28
*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <tuple>
using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> edges;
vector<long> dist;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    int s, e, w;

    cin >> N >> M;
    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), LONG_MAX);

    for (int i = 0; i < M; i++)
    {
        cin >> s >> e >> w;
        edges.push_back(make_tuple(s, e, w));
    }

    dist[1] = 0;

    for (int i = 1; i < N; i++){
        for (int j = 0; j < M; j++){
            edge medge = edges[j];

            int start = get<0>(medge);
            int end = get<1>(medge);
            int weight = get<2>(medge);

            if(dist[start] != LONG_MAX && dist[end] > dist[start] + weight){
                dist[end] = dist[start] + weight;
            }
        }
    }

    bool cycle = false;

    for (int i = 0; i < M; i++){
        edge medge = edges[i];

        int start = get<0>(medge);
        int end = get<1>(medge);
        int weight = get<2>(medge);

        if (dist[start] != LONG_MAX && dist[end] > dist[start] + weight){
            cycle = true;
        }
    }

    if(!cycle){
        for (int i = 2; i <= N; i++){
            if(dist[i] == LONG_MAX)
                cout << -1 << "\n";
            else
                cout << dist[i] << "\n";
        }
    }
    else
        cout << -1 << "\n";
}