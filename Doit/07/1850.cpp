/*
BOJ 1850.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.09
*/

#include <iostream>
using namespace std;
int gcd(long a, long b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A, B;
    cin >> A >> B;

    long result = gcd(A, B);

    while(result--)
        cout << 1;
}

int gcd(long a, long b){
    if(b == 0)
        return a;
    else
        return gcd(b, a % b);
}