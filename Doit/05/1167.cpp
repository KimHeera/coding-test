/*
BOJ 1167.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.29
*/

#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> edge;
vector<vector<edge>> P;
vector<bool> visited;
vector<int> myDistance;

void BFS(int v);


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        int s;
        cin >> s;

        while(true){
            int e, v;
            cin >> e;

            if(e == -1)
                break;

            cin >> v;
            P[s].push_back(make_pair(e, v));
        }
    }

    visited = vector<bool>(N + 1, false);
    myDistance = vector<int>(N + 1, 0);
    BFS(1);

    int max = 1;
    for (int i = 2; i < myDistance.size(); i++){
        if(myDistance[max] < myDistance[i])
            max = i;
    }

    fill(visited.begin(), visited.end(), false);
    BFS(max);

    max = myDistance[0];
    for (int i = 1; i < myDistance.size(); i++){
        if(max < myDistance[i])
            max = myDistance[i];
    }

    cout << max << endl;
}

void BFS(int v){
    queue<int> myQ;
    myQ.push(v);
    visited[v] = true;

    while(!myQ.empty()){
        int now = myQ.front();

        for (int i = 0; i < P[now].size(); i++){
            if(!visited[P[now][i].first]){
                myQ.push(P[now][i].first);
                visited[P[now][i].first] = true;
                myDistance[P[now][i].first] = myDistance[now] + P[now][i].second;
            }
        }
    }
}