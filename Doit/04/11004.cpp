/*
BOJ 11004.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.23
*/

#include <iostream>
#include <vector>
using namespace std;

void QuickSort(vector<int> &P, int start, int end, int K);
int Partition(vector<int> &P, int start, int end);
void Swap(vector<int> &P, int i, int j);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> P(N, 0);

    for (int i = 0; i < N; i++){
        cin >> P[i];
    }

    QuickSort(P, 0, N - 1, K - 1);
    cout << P[K - 1];
}

void QuickSort(vector<int> &P, int start, int end, int K)
{
    int pivot = Partition(P, start, end);

    if(pivot == K)
        return;
    else if(K < pivot)
        QuickSort(P, start, pivot - 1, K);
    else
        QuickSort(P, pivot + 1, end, K);
}

int Partition(vector<int> &P, int start, int end)
{
    if(start + 1 == end){
        if(P[start] > P[end])
            Swap(P, start, end);
        return end;
    }

    int mid = (start + end) / 2;
    Swap(P, mid, start);

    int pivot = P[start];

    int i = start + 1, j = end;
    while(i <= j){
        while(j >= start + 1 && pivot < P[j])
            j--;
        
        while(i <= end && pivot > P[i])
            i++;

        if(i < j)
            Swap(P, i++, j--);
        else   
            break;
    }

    P[start] = P[j];
    P[j] = pivot;

    return j;
}

void Swap(vector<int> &P, int i, int j)
{
    int tmp = P[i];
    P[i] = P[j];
    P[j] = tmp;
}