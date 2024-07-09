/*
BOJ 1253.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.09
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int N;
    cin >> N;

    vector<int> A(N, 0);

    for (int i = 0; i < N; i++){
        cin >> A[i];
    }
    sort(A.begin(), A.end());

    int count = 0;
    for (int k = 0; k < N; k++)
    {
        long find = A[k];
        int i = 0, j = N - 1;

        while(i < j){
            if(A[i] + A[j] == find){
                if(i != k && j !=k){
                    count++;
                    break;
                }
                else if(i == k)
                    i++;
                else
                    j--;
            }
            else if(A[i] + A[j] < find)
                i++;
            else
                j--;
        }
    }

    cout << count << endl;
}