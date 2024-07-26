/*
BOJ 2023.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.26
*/

#include <iostream>
using namespace std;

int N;
void DFS(int v, int numCount);
bool isPrime(int num);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    DFS(2, 1);
    DFS(3, 1);
    DFS(5, 1);
    DFS(7, 1);
}

void DFS(int v, int numCount){
    if(numCount == N){
        if(isPrime(v))
            cout << v << "\n";
        return;
    }

    for (int i = 1; i < 10; i++){
        if(i%2 == 0)
            continue;
        if(isPrime(v * 10 + i))
            DFS(v * 10 + i, numCount + 1);
    }
}

bool isPrime(int num){
    for (int i = 2; i <= num / 2; i++){
        if(num % i == 0)
            return false;
    }

    return true;
}