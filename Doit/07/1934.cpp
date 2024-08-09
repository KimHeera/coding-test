/*
BOJ 1934.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.09
*/

#include <iostream>
using namespace std;

int gcd(int a, int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while(T--){
        int A, B;
        cin >> A >> B;

        int result = A * B / gcd(A, B);
        cout << result << "\n";
    }
}

int gcd(int a, int b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}