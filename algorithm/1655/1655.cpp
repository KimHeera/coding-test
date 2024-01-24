#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
bool flag = true;

void main()
{
    int inputSize;
    int inputNum;

    cin >> inputSize;
    for (int i = 0; i < inputSize; i++)
    {
        cin >> inputNum;
        CalculateHeap(inputNum);
    }
}

void CalculateHeap(int inputNum)
{
}
