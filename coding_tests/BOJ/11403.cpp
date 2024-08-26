/*
BOJ 11403.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.26
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> P;
vector<int> visited;
void dfs(int a);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    P.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            int input;
            cin >> input;

            if(input == 1)
                P[i].push_back(j);
        }
    }

    for (int i = 0; i < N; i++){
        fill(visited.begin(), visited.end(), 0);
        dfs(i);

        for (int j = 0; j < N; j++)
            cout << visited[j] << " ";
        cout << "\n";
    }
}

void dfs(int a){
    for (int k = 0; k < P[a].size(); k++){
        if (visited[P[a][k]] == 0)
        {
            visited[P[a][k]] = 1;
            dfs(P[a][k]);
        }
    }
}