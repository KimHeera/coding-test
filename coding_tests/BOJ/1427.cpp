#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int input;
    cin >> input;

    priority_queue<int, vector<int>, less<int> > arr;

    while(input > 0){
        int num = input % 10;
        arr.push(num);
       
        input /= 10;
    }

    while (!arr.empty()){
        cout << arr.top();
        arr.pop();
    }
}