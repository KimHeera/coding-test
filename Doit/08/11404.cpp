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
using namespace std;
// typedef pair<int, int> edge;
vector<vector<int> > edges;

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

        edges[a][b] = c;
    }

    

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << edges[i][j] << "  ";
    //     }
    //     cout << "\n";
    // }
}