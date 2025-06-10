/*
BOJ 11404.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.06.10
이미 풀었던 문제라 다른 방식으로 풀이함.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > edges;
vector<int> visited;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    edges.resize(n + 1);
    visited.resize(n + 1);

    for (int i = 1; i <= n; i++){
        edges[i].resize(n + 1);

        for (int j = 1; j <= n; j++){
            cin >> edges[i][j];
        }
    }

    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if(edges[i][k] == 1 && edges[k][j] == 1)
                    edges[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cout << edges[i][j] << " ";
        }
        cout << "\n";
    }
}