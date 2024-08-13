/*
BOJ 1325.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.13
*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<vector<int>> P;
vector<bool> visited;
vector<int> answer;
void bfs(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    P.resize(N + 1);
    answer.resize(N + 1);
    visited.resize(N + 1);
    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;

        P[A].push_back(B);
    }

    for (int i = 0; i <= N; i++){
        fill(visited.begin(), visited.end(), false);
        bfs(i);
    }

    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        if(max < answer[i])
            max = answer[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if (max == answer[i])
            cout << i << " ";
    }
}

void bfs(int node){
    queue<int> myQ;
    myQ.push(node);
    visited[node] = true;

    while(!myQ.empty()){
        int newNode = myQ.front();
        myQ.pop();

        for (int i = 0; i < P[newNode].size(); i++){
            if(visited[P[newNode][i]] == false){
                visited[P[newNode][i]] = true;
                answer[P[newNode][i]]++;
                myQ.push(P[newNode][i]);
            }
        }
    }
}