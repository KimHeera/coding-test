/*
BOJ 10845.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.29
*/

#include <iostream>
#include <queue>
using namespace std;

void condition(string s);
queue<int> myQ;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N; i++){
        string s;
        cin >> s;

        condition(s);
    }
}

void condition(string s){
    if(s == "push"){
        int num;
        cin >> num;
        myQ.push(num);
    }
    else if (s == "pop"){
        if(myQ.empty())
            cout << -1 << "\n";
        else{
            cout << myQ.front() << "\n";
            myQ.pop();
        }
    }
    else if (s == "size"){
        cout << myQ.size() << "\n";
    }
    else if (s == "empty"){
        if(myQ.empty())
            cout << 1 << "\n";
        else
            cout << 0 << "\n";
    }
    else if (s == "front"){
        if (myQ.empty())
            cout << -1 << "\n";
        else
        {
            cout << myQ.front() << "\n";
        }
    }
    else {
        if (myQ.empty())
            cout << -1 << "\n";
        else
        {
            cout << myQ.back() << "\n";
        }
    }
}