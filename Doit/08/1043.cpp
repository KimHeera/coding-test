/*
BOJ 1043.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.22
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> P;
vector<vector<int>> party;
void unionFunc(int a, int b);
int findFunc(int a);

int main()
{
    int N, M;
    cin >> N >> M;

    P.resize(N + 1);
    for (int i = 0; i < N + 1; i++)
        P[i] = i;

    int knowP;
    cin >> knowP;
    vector<int> knowPeople(knowP);
    party.resize(M);

   for (int i = 0; i < knowP; i++){
        cin >> knowPeople[i];
    }

    for (int j = 0; j < M; j++){
        int partyNum;
        cin >> partyNum;

        for (int i = 0; i < partyNum; i++)
        {
            int input;
            cin >> input;
            party[j].push_back(input);
        }
    }

    for (int i = 0; i < M; i++)
    {
        int first = party[i][0];

        for (int j = 1; j < party[i].size(); j++){
            unionFunc(first, party[i][j]);
        }
    }

    int result = 0;
    for (int i = 0; i < M; i++){
        bool flag = true;
        int first = party[i][0];

        for (int j = 0; j < knowP; j++){
            if(findFunc(first) == findFunc(knowPeople[j])){
                flag = false;
                break;
            }
        }

        if(flag)
            result++;
    }
    
    cout << result << "\n";
}

void unionFunc(int a, int b){
    a = findFunc(a);
    b = findFunc(b);

    if(a != b)
        P[b] = a;
}

int findFunc(int a){
    if(a == P[a])
        return a;
    else
        return P[a] = findFunc(P[a]);
}