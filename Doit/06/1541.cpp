/*
BOJ 1541.
Author: Heera Kim
E-mail Address: heeerala.a@gmail.com
C++
Last Changed: 2024.08.06
*/

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

vector<string> split(string input, char delimiter);
int sum(string input);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string input;
    cin >> input;

    vector<string> result = split(input, '-');

    int numResult = 0;
    int answer = 0;
    for (int i = 0; i < result.size(); i++)
    {
        numResult = sum(result[i]);

        if(i ==0)
            answer += numResult;
        else
            answer -= numResult;
    }

    cout << answer << endl;
}

vector<string> split(string input, char delimiter){
    istringstream iss(input);
    vector<string> result;
    string buffer;

    while(getline(iss, buffer, delimiter))
        result.push_back(buffer);

    return result;
}

int sum(string input){
    vector<string> numSet = split(input, '+');

    int result = 0;
    for (int i = 0; i < numSet.size(); i++)
    {
        result += stoi(numSet[i]);
    }

    return result;
}