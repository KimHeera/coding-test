/*
BOJ 1931.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.06
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<pair<int, int>> P(N);
    for (int i = 0; i < N; i++){
        cin >> P[i].first;
        cin >> P[i].second;
    }

    sort(P.begin(), P.end());

    int end = -1;
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if(end <= P[i].first){
            end = P[i].second;
            count++;
        }
    }

    cout << count+1 << endl;
}