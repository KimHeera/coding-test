/*
BOJ 12891.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.07.10
*/

#include <iostream>
using namespace std;

int minNum[4];
int checkNum[4];
int check = 0;
void add(char ch);
void remove(char ch);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int s, p;
    cin >> s >> p;

    string DNA;
    cin >> DNA;

    int result = 0;

    for (int i = 0; i < 4; i++){
        cin >> minNum[i];
        if(minNum[i] == 0)
            check++;
    }

    for (int i = 0; i < p; i++)
    {
        add(DNA[i]);
    }

    if(check == 4)
        result++;

    for (int i = p; i < s; i++)
    {
        int j = i - p;

        add(DNA[i]);
        remove(DNA[j]);

        if(check == 4)
            result++;
    }

    cout << result << endl;
}

void add(char ch){
    switch(ch){
        case 'A': {
            checkNum[0]++;

            if(minNum[0] == checkNum[0])
                check++;
            break;
        }
        case 'C': {
            checkNum[1]++;

            if (minNum[1] == checkNum[1])
                check++;
            break;
        }
        case 'G':
        {
            checkNum[2]++;

            if (minNum[2] == checkNum[2])
                check++;
            break;
        }
        case 'T':
        {
            checkNum[3]++;

            if (minNum[3] == checkNum[3])
                check++;
            break;
        }
    }
}

void remove(char ch){
    switch(ch){
        case 'A': {
            if(minNum[0] == checkNum[0])
                check--;

            checkNum[0]--;
            break;
        }
        case 'C':
        {
            if (minNum[1] == checkNum[1])
                check--;

            checkNum[1]--;
            break;
        }
        case 'G':
        {
            if (minNum[2] == checkNum[2])
                check--;

            checkNum[2]--;
            break;
        }
        case 'T':
        {
            if (minNum[3] == checkNum[3])
                check--;

            checkNum[3]--;
            break;
        }
    }
}