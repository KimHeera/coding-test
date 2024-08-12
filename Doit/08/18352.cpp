/*
BOJ 18352.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.12
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void bfs(int index);
vector<vector<int>> P;
vector<int> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> result;
    int N, M, K, X;
    cin >> N >> M >> K >> X;

    P.resize(N + 1);

    for (int i = 0; i < M; i++){
        int a, b;
        cin >> a >> b;

        P[a].push_back(b);
    }

    visited.resize(N + 1);
    for (int i = 0; i <= N; i++){
        visited[i] = -1;
    }

    bfs(X);

    for (int i = 0; i <= N; i++){
        if(visited[i] == K)
            result.push_back(i);
    }

    if(result.empty())
        cout << -1 << endl;
    else{
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++){
            cout << result[i] << "\n";
        }
    }
}

void bfs(int index){
    queue<int> myQ;

    myQ.push(index);
    visited[index]++;

    while(!myQ.empty()){
        int nowIndex = myQ.front();
        myQ.pop();

        for (int i = 0; i < P[nowIndex].size(); i++){
            if (visited[P[nowIndex][i]] == -1){
                visited[P[nowIndex][i]] = visited[nowIndex] + 1;
                myQ.push(P[nowIndex][i]);
            }
        }
    }
}