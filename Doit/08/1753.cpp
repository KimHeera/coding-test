/*
BOJ 1753.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.04.24
*/

#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int> > arr[20001];
int dp[20001];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int V, E, K;
    cin >> V >> E;
    cin >> K;

    int u, v, w;
    for (int i = 0; i < E; i++){
        cin >> u >> v >> w;
        arr[u].push_back(make_pair(v, w));
    }

    
}