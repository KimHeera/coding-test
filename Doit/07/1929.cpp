/*
BOJ 1929.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.08
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M, N;
    cin >> M >> N;

    vector<int> primeNum(N + 1);

    for (int i = 2; i <= N; i++){
        primeNum[i] = i;
    }

    for (int i = 2; i <= sqrt(N); i++){
        if(primeNum[i] == 0)
            continue;

        for (int j = i + i; j <= N; j += i)
            primeNum[j] = 0;
    }

    for (int i = M; i <= N; i++){
        if(primeNum[i] != 0)
            cout << primeNum[i] << "\n";
    }
}