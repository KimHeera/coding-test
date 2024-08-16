/*
BOJ 1927.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.16
*/

#include <iostream>
#include <queue>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> myHeap;

    int N;
    cin >> N;

    int x;
    while (N--){
        cin >> x;

        if(x == 0){
            if(myHeap.empty())
                cout << 0 << "\n";
            else{
                cout << myHeap.top() << "\n";
                myHeap.pop();
            }
        }
        else{
            myHeap.push(x);
        }
    }
}