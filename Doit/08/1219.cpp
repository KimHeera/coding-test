/*
BOJ 1219.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.05.30
*/

#include <iostream>
#include <vector>
#include <tuple>
#include <limits.h>
using namespace std;

typedef tuple<int, int, int> edge;
vector<edge> edges;
vector<long> dist;
vector<long> wage;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, S, E, M;
    cin >> N >> S >> E >> M;

    dist.resize(N + 1);
    fill(dist.begin(), dist.end(), LONG_MIN);
    wage.resize(N + 1);

    for (int i = 0; i < M; i++){
        int s, e, m;

        cin >> s >> e >> m;
        edges.push_back(make_tuple(s, e, m));
    }

    for (int i = 0; i < N; i++){
        cin >> wage[i];
    }

    dist[S] = wage[S];
    for (int i = 0; i <= N + 50; i++){
        for (int j = 0; j < M; j++){
            edge nowEdge = edges[j];

            int start = get<0>(nowEdge);
            int end = get<1>(nowEdge);
            int money = get<2>(nowEdge);

            // if (dist[start] != LONG_MAX && dist[end] < dist[start] - money + wage[end])
            //     dist[end] = dist[start] - money + wage[end];
            if (dist[start] == LONG_MIN)
                continue;
            else if (dist[start] == LONG_MAX)
                dist[end] = LONG_MAX;
            else if (dist[end] < dist[start] - money + wage[end]){
                dist[end] = dist[start] - money + wage[end];

                if (i >= N + 1)
                    dist[end] = LONG_MAX;
            }
        }
    }

    if (dist[E] == LONG_MAX)
        cout << "Gee";
    else if (dist[E] == LONG_MIN)
        cout << "gg";
    else
        cout << dist[E];
}