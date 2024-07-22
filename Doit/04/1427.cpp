/*
BOJ 1427.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.22
*/

//이미 성공한 문제를 다른 방식으로 접근함.

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    vector<int> array(str.size(), 0);
    for (int i = 0; i < str.size(); i++){
        array[i] = stoi(str.substr(i, 1));
    }

    for (int i = 0; i < str.length(); i++){
        int Max = i;
        for (int j = i + 1; j < str.length(); j++){
            if(array[j] > array[Max])
                Max = j;
        }
        if(array[i] < array[Max]){
            int tmp = array[i];
            array[i] = array[Max];
            array[Max] = tmp;
        }
    }

        for (int i = 0; i < array.size(); i++)
        {
            cout << array[i];
        }
}