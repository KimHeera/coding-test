/*
BOJ 11047.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.05
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> P(N);

    for (int i = 0; i < N; i++){
        cin >> P[i];
    }

    int count = 0;
    for (int i = N - 1; i >= 0; i--){
        if(P[i] <= K){
            count += (K / P[i]);
            K %= P[i];
        }
    }

    cout << count << endl;
}