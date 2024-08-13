/*
BOJ 1707.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.13
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> P;
vector<bool> visited;
vector<int> check;
bool isEven;
void dfs(int node);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, V, E;
    cin >> K;

    while(K--){
        cin >> V >> E;
        P.resize(V + 1);
        visited.resize(V + 1);
        check.resize(V + 1);
        isEven = true;

        for (int i = 0; i < E; i++){
            int s, e;
            cin >> s >> e;

            P[s].push_back(e);
            P[e].push_back(s);
        }

        for (int i = 1; i == V; i++){
            if(isEven)
                dfs(i);
            else    
                break;
        }

        if(isEven)
            cout << "YES" << "\n";
        else
            cout << "NO" << "\n";

        for (int i = 0; i <= V; i++){
            P[i].clear();
            visited[i] = false;
            check[i] = 0;
        }
    }
}

void dfs(int node){
    visited[node] = true;

    for (int i = 0; i < P[node].size(); i++){
        if(!visited[P[node][i]]){
            check[P[node][i]] = (check[node] + 1) % 2;
            dfs(P[node][i]);
        }
        else if(check[node] == check[P[node][i]])
            isEven = false;
    }
}