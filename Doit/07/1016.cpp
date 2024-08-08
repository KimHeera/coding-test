/*
BOJ 1016.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.08
*/

#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long min, max;
    cin >> min >> max;

    vector<bool> P(max - min + 1);

    for (long i = 2; i * i <= max; i++)
    {
        long pow = i * i;
        long startIndex = min / pow;

        if(min % pow != 0)
            startIndex++;

        for (long j = startIndex; j * pow <= max; j++)
        {
            P[(int)((j * pow) - min)] = true;
        }
    }

    int count = 0;
    for (int i = 0; i <= max - min; i++){
        if(!P[i])
            count++;
    }

    cout << count << endl;
}