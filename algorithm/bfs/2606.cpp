#include <iostream>
#include <vector>
#include <string>

using namespace std;

#define MAXNUM 100

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int computerNum, connnectNum;
    bool flag = true;
    vector<int> network;

    cin >> computerNum;
    cin >> connnectNum;

    int node1, node2;

    for (int i = 0; i < connnectNum; i++)
    {
        cin >> node1 >> node2;

        if (flag)
        {
            network.push_back(node1);
            network.push_back(node2);
        }
        else
        {
                }
    }
}