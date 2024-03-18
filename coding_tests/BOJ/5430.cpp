/*

*/
#include <iostream>
#include <queue>
#include <list>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    int R, D;
    string p, x;

    cin >> T; //input test case

    while(T--){
        R = 0, D = 0;
        list<int> numList;
        int tmp;
        cin >> p >> n >> x;

        x = x.substr(1, x.length() - 2);

        stringstream ss(x);
        string token;
        while (getline(ss, token, ','))
        {
            tmp = stoi(token);
            numList.push_back(tmp);
        }

        //numList에 숫자가 잘 들어갔는지 확인하는 코드
        list<int>::iterator iter;
        // for (iter = numList.begin(); iter != numList.end(); iter++)
        // {
        //     cout << "Iterator : " << *iter << endl;
        // }

        for (char ch : p)
        {
            if (ch == 'R')
                R++;
            if (ch == 'D')
                D++;
        }

        if(D > n){
            cout << "error\n";
            break;
        }
        else{
            for(char ch : p){
                if(ch == 'D'){
                    numList.pop_front();
                }
                else if(ch == 'R'){
                    numList.reverse();
                }
            }
        }

        cout << "[";
        for (iter = numList.begin(); iter != numList.end(); iter++)
        {
            if (iter == numList.end()){
                cout << *iter;
            }else{
                cout << *iter << ",";
            }
        }
        cout << "]\n";
    }
}

