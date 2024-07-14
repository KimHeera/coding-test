/*
BOJ 11003.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.14
*/

#include <iostream>
#include <deque>
using namespace std;

typedef pair<int, int> Node;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N, L;
    deque<Node> mydeque;

    cin >> N >> L;

    for (int i = 0; i < N; i++){
        int now;
        cin >> now;

        while(mydeque.size() && mydeque.back().first > now)
            mydeque.pop_back();

        mydeque.push_back(Node(now, i));

        if(mydeque.front().second <= i - L)
            mydeque.pop_front();

        cout << mydeque.front().first << " ";
    }
}