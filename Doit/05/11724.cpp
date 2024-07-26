/*
BOJ 11724.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.26
*/

#include <iostream>
#include <vector>
using namespace std;

void DFS(int v);
vector<vector<int>> A;
vector<bool> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    visited = vector<bool>(N+1, false);

    for (int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;

        A[start].push_back(end);
        A[end].push_back(start);
    }

    int result = 0;
    for (int i = 1; i < N+1; i++)
    {
        if(!visited[i]){
            result++;
            DFS(i);
        }
    }

    cout << result << endl;
}

void DFS(int v){
    if(visited[v])
        return;
        
    visited[v] = true;
    for (int i = 0; i < A[v].size(); i++){
        if(!visited[A[v][i]])
            DFS(A[v][i]);
    }
}