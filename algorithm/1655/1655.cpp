#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int> maxHeap;
priority_queue<int, vector<int>, greater<int>> minHeap;
bool flag = true;

int main()
{
    // 입출력 속도 향상을 위한 코드
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int inputSize;
    int inputNum;

    cin >> inputSize;
    for (int i = 0; i < inputSize; i++)
    {
        cin >> inputNum;
        // 처음 입력받는 경우
        if (maxHeap.empty())
        {
            maxHeap.push(inputNum);
        }
        else
        {
            // maxheap의 size가 더 크다면, minheap에 inputNum을 넣는다.
            if (maxHeap.size() > minHeap.size())
            {
                minHeap.push(inputNum);
            }
            else
            { // size가 같다면 maxheap에 innputNum을 넣는다.
                maxHeap.push(inputNum);
            }

            // maxheap의 root 노드 > minheap의 root 노드 -> swap함.
            if (maxHeap.top() > minHeap.top())
            {
                int maxTop = maxHeap.top();
                int minTop = minHeap.top();

                maxHeap.pop();
                minHeap.pop();

                maxHeap.push(minTop);
                minHeap.push(maxTop);
            }
        }

        cout << maxHeap.top() << '\n';
    }

    return 0;
}
