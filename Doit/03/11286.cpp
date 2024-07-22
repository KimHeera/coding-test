/*
BOJ 11286.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.20
*/

#include <iostream>
#include <queue>
using namespace std;

struct compare{
    bool operator()(int o1, int o2){
        int first_abs = abs(o1);
        int second_abs = abs(o2);

        if(first_abs == second_abs)
            return o1 > o2; //절댓값 같을 시 음수 우선 정렬
        else
            return first_abs > second_abs;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    priority_queue<int, vector<int>, compare> myQueue;

    int x;
    for (int i = 0; i < N; i++)
    {
        cin >> x;
        if(x == 0){
            //출력
            if(myQueue.empty())
                cout << "0\n";
            else{
                cout << myQueue.top() << "\n";
                myQueue.pop();
            }
        }
        else{
            //queue에 push
            myQueue.push(x);
        }
    }
}