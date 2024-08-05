/*
BOJ 1744.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.05
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

    priority_queue<int> plusQ;
    priority_queue<int, vector<int>, greater<int>> minusQ;
    int oneCount = 0, zeroCount = 0;

    int input;
    for (int i = 0; i < N; i++)
    {
        cin >> input;

        if(input == 1)
            oneCount++;
        else if(input == 0)
            zeroCount++;
        else if(input > 1)
            plusQ.push(input);
        else
            minusQ.push(input);
    }

    int sum = 0;
    int data1 = 0, data2 = 0;

    while(plusQ.size() > 1){
        data1 = plusQ.top();
        plusQ.pop();
        data2 = plusQ.top();
        plusQ.pop();

        sum += data1 * data2;
    }

    if(!plusQ.empty())
        sum += plusQ.top();

    while (minusQ.size() > 1)
    {
        data1 = minusQ.top();
        minusQ.pop();
        data2 = minusQ.top();
        minusQ.pop();

        sum += data1 * data2;
    }

    if (!minusQ.empty()){
        if(zeroCount == 0)
            sum += minusQ.top();
    }

    sum += oneCount;
    cout << sum << endl;
}