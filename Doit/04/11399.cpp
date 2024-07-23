/*
BOJ 11399.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.23
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> P(N, 0);
    for (int i = 0; i < N; i++){
        cin >> P[i];
    }

    for (int i = 1; i < N; i++){
        int index = i;
        int indexValue = P[i];

        for (int j = i - 1; j >= 0; j--){
            if(P[j] < P[i]){
                index = j + 1;
                break;
            }

            if(j == 0)
                index = 0;
        }

        for (int j = i; j > index; j--){ 
            P[j] = P[j - 1];
        }

        P[index] = indexValue;
    }

    int sum = 0;
    vector<int> S(N, 0);
    S[0] = P[0];
    for (int i = 1; i < N; i++)
    {
        S[i] = S[i - 1] + P[i];
    }

    for (int i = 0; i < N; i++){
        sum += S[i];
    }

    cout << sum << endl;
}
