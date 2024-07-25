/*
BOJ 1517.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.25
*/

#include <iostream>
#include <vector>
using namespace std;

void mergeSort(int start, int end);
vector<int> p;
vector<int> tmp;
int result;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    p = vector<int>(N+1);
    tmp = vector<int>(N+1);

    for (int i = 1; i < N + 1; i++){
        cin >> p[i];
    }

    result = 0;
    mergeSort(1, N);

    cout << result << endl;
}

void mergeSort(int start, int end){
    if(end - start < 1)
        return;

    int mid = start + (end - start) / 2;

    mergeSort(start, mid);
    mergeSort(mid + 1, end);

    for (int i = start; i < end + 1; i++)
        tmp[i] = p[i];

    int resultIndex = start;
    int index1 = start;
    int index2 = mid + 1;
    while(index1 <= mid && index2 <= end){
        if(tmp[index1] > tmp[index2]){
            p[resultIndex] = tmp[index2];
            result += index2 - resultIndex;
            resultIndex++;
            index2++;
        }
        else{
            p[resultIndex] = tmp[index1];
            resultIndex++;
            index1++;
        }
    }

    while(index1 <= mid){
        p[resultIndex] = tmp[index1];
        resultIndex++;
        index1++;
    }

    while(index2 <= end){
        p[resultIndex] = tmp[index2];
        resultIndex++;
        index1++;
    }
}