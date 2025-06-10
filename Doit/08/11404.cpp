/*
BOJ 11404.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.06.10
*/

#include <iostream>
#include <vector>
#include <limits.h>
#include <math.h>
using namespace std;
vector<vector<long> > edges;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    edges.resize(n + 1);

    for (int i = 1; i <= n; i++){
        edges[i].resize(n + 1, INT_MAX);
        edges[i][i] = 0;
    }

    int a, b, c;
    for (int i = 0; i < m; i++){
        cin >> a >> b >> c;

        if(edges[a][b] > c)
            edges[a][b] = c;
    }

    for (int i = 1; i <= n; i++){
        for (int s = 1; s <= n; s++){
            for (int e = 1; e <= n; e++){
                edges[s][e] = min(edges[s][e], edges[s][i] + edges[i][e]);
            }
        }
    }

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            if (edges[i][j] == INT_MAX)
                cout << 0 << " ";
            else
                cout << edges[i][j] << " ";
        }
        cout << "\n";
    }
}