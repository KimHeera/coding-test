/*
BOJ 13023.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.26
*/

#include <iostream>
#include <vector>
using namespace std;

bool arrive = false;
vector<vector<int>> A;
vector<bool> visited;
void DFS(int num, int depth);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    A.resize(N + 1);
    visited = vector<bool>(N + 1, false);

    for (int i = 0; i < M; i++){
        int start, end;
        cin >> start >> end;

        A[start].push_back(end);
        A[end].push_back(start);
    }

    for (int i = 0; i < N; i++){
        DFS(i, 1);

        if(arrive)
            break;
    }

    if(arrive)
        cout << 1 << endl;
    else
        cout << 0 << endl;
}

void DFS(int num, int depth){
    if(depth == 5 || arrive){
        arrive = true;
        return;
    }

    visited[num] = true;
    for (int i = 0; i < A[num].size(); i++){
        if(!visited[A[num][i]]){
            DFS(A[num][i], depth + 1);
        }
    }

    visited[num] = false;
}