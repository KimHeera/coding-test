/*
BOJ 1717.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.16
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> P;
void unionCal(int a, int b);
int findCal(int a);
bool isSame(int a, int b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    P.resize(N + 1);
    for (int i = 0; i <= N; i++){
        P[i] = i;
    }

    int input, a, b;
    while (M--){
        cin >> input >> a >> b;

        if(input == 0){
            unionCal(a, b);
        }
        else{
            findCal(a);

            if(isSame(a, b))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }
}

void unionCal(int a, int b){
    a = findCal(a);
    b = findCal(b);

    if(a != b)
        P[b] = a;
}

int findCal(int a){
    if(a == P[a])
        return a;
    else
        return P[a] = findCal(P[a]);
}

bool isSame(int a, int b){
    a = findCal(a);
    b = findCal(b);

    if(a == b)
        return true;
    else
        return false;
}