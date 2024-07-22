/*
BOJ 1377.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.22
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> array(N, 0);

    for (int i = 0; i < N; i++){
        cin >> array[i];
    }

    int result = 1;
    for (int i = 0; i < N - 1; i++)
    {
        bool flag = false;

        for (int j = 0; j < N - 1 - i; j++)
        {
            if(array[j] > array[j+1]){
                flag = true;
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }

        if(flag){
            result++;
        }
    }

    cout << result << endl;
}