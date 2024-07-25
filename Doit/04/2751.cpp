/*
BOJ 2751.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.25
*/

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int start, int end);
vector<int> P;
vector<int> tmp;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    P = vector<int>(N + 1, 0);
    tmp = vector<int>(N + 1, 0);

    for (int i = 1; i < N+1; i++){
        cin >> P[i];
    }

    mergeSort(1, N);

    for (int i = 1; i < N + 1; i++)
    {
        cout << P[i] << "\n";
    }
}

void mergeSort(int start, int end){
    if(end - start < -1)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(start, mid);
    mergeSort(mid + 1, end);

    for (int i = start; i <= end; i++)
        tmp[i] = P[i];

    int index1 = start;
    int index2 = mid + 1;
    int resultIndex = start;
    while(index1 <= mid && index2 <= end){
        if(tmp[index1] > tmp[index2]){
            P[resultIndex] = tmp[index2];
            resultIndex++;
            index2++;
        }
        else{
            P[resultIndex] = tmp[index1];
            resultIndex++;
            index1++;
        }
    }

    while(index1 <= mid){
        P[resultIndex] = tmp[index1];
        resultIndex++;
        index1++;
    }
    while (index2 <= end)
    {
        P[resultIndex] = tmp[index2];
        resultIndex++;
        index2++;
    }
}