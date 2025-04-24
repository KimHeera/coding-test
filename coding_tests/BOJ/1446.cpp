/*
BOJ 1446.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2025.04.24
*/

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<pair<int, int> > arr[10001];
int dp[10001];
int N, D;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(dp, -1, sizeof(dp));

    int s, a, j;
    cin >> N >> D;

    while(N--){
        cin >> s >> a >> j;
        if (a > D || a - s < j)
            continue;
        arr[a].push_back(make_pair(s, j));
    }

    dp[0] = 0;
    for (int i = 1; i <= D; i++){
        dp[i] = dp[i - 1] + 1;
        for (int k = 0; k < (int)arr[i].size(); k++){
            dp[i] = min(dp[i], dp[arr[i][k].first] + arr[i][k].second);
        }
    }

    cout << dp[D];
}