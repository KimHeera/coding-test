/**
BOJ 10986.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.03
*/

#include <iostream>
#include <string.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, result = 0;
    cin >> N >> M;

    int s[N], c[M];

    for (int i = 0; M; i++){
        c[i] = 0;
    }
    
    int A;

    cin >> A;
    s[0] = A;

    for (int i = 1; i < N; i++)
    {
        cin >> A;
        s[i] = s[i - 1] + A;
    }

    for(int num : s){
        int tmp = num % M;

        if(tmp == 0)
            result++;
        c[tmp]++;
    }

    for (int i = 0; i < M; i++){
        if(c[i] > 1)
            result += (c[i] * (c[i] - 1) / 2);
    }

    cout << result;
}