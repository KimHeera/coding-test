/*
BOJ 11689.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.08
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long n;
    cin >> n;

    long result = n;
    for (long i = 2; i <= sqrt(n); i++){
        if(n%i == 0){
            result = result - result / i;
            while(n%i == 0)
                n /= i;
        }
    }

    if(n>1)
        result = result - result / n;

    cout << result << endl;
}