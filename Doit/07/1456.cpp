/*
BOJ 1456.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.08
*/

#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long A, B;
    cin >> A >> B;

    long P[10000001];
    for (int i = 2; i < 10000001; i++)
    {
        P[i] = i;
    }

    for (int i = 2; i <= sqrt(10000001); i++)
    {
        if(P[i] == 0)
            continue;

        for (int j = i + i; j < 10000001; j += i)
            P[j] = 0;
    }

    int count = 0;
    for (int i = 2; i < 10000001; i++)
    {
        if(P[i] != 0){
            long tmp = P[i];
            while((double)P[i] <= (double)B / (double)tmp){
                if ((double)P[i] >= (double)A / (double)tmp)
                    count++;
                tmp *= P[i];
            }
        }
    }

    cout << count << endl;
}