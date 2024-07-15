/*
BOJ 1874.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.14
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> inputs(N, 0);
    for (int i = 0; i < N; i++)
    {
        cin >> inputs[i];
    }

    int num = 1;
    vector<char> result;
    stack<int> mystack;
    bool flag = true;

    for (int i = 0; i < N; i++){
        int nowNum = inputs[i];

        if(nowNum >= num){
            while (nowNum >= num){
                mystack.push(num);
                num++;
                result.push_back('+');
            }
            mystack.pop();
            result.push_back('-');
        }
        else{
            int n = mystack.top();
            mystack.pop();

            if(n > nowNum){
                cout << "NO";
                flag = false;
                break;
            }
            else
                result.push_back('-');
        }
    }

    if(flag){
        for (int i = 0; i < result.size(); i++){
            cout << result[i] << "\n";
        }
    }
}