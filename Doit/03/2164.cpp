/*
BOJ 2164.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.20
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    queue<int> myQueue;
    for (int i = 1; i <= N; i++){
        myQueue.push(i);
        
    }

    int top;
    while (myQueue.size() != 1)
    {
        myQueue.pop();

        top = myQueue.front();
        myQueue.pop();
        myQueue.push(top);
    }

    cout << myQueue.front() << endl;
}