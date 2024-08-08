/*
BOJ 1747.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.08
*/

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

bool isPalindrome(int num);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long N;
    cin >> N;

    long A[10000001];

    for (int i = 2; i < 10000001; i++){
        A[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++){
        if(A[i] == 0)
            continue;

        for (int j = i + i; j < 10000001; j += i)
            A[j] = 0;
    }

    int i = N;
    while(true){
        if(A[i] != 0){
            if(isPalindrome(A[i])){
                cout << A[i] << endl;
                break;
            }
        }
        i++;
    }
}

bool isPalindrome(int num){
    string input = to_string(num);
    // char const *tmp = input.c_str(); //문자열을 배열로 변환

    int start = 0;
    int end = input.size() - 1;

    while(start < end){
        if (input[start] != input[end])
            return false;

        start++;
        end--;
    }

    return true;
}