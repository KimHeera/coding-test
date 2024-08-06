/*
BOJ 1654.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.06
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int K, N;
    cin >> K >> N;
    vector<int> P(K, 0);

    long start = 1, end = 0;
    for (int i = 0; i < K; i++)
    {
        cin >> P[i];
        if(end < P[i])
            end = P[i];
    }

    long mid = (start + end) / 2;
    while(start <= end){
        int count = 0;

        for (int i = 0; i < K; i++){
            count += P[i] / mid;
        }

        if(count >= N){
            start = mid + 1;
        }
        else
            end = mid - 1;

        mid = (start + end) / 2;
    }

    cout << mid << endl;
}