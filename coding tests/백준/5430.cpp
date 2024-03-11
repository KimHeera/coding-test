#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T, n;
    int R = 0, D = 0;
    string p, x;

    cin >> T; //input test case

    while(T--){
        cin >> p >> n >> x;
        cout << x;

        for(char ch : p){
            if(ch == 'R')
                R++;
            if(ch == 'D')
                D++;
        }

        if(D > n) {
            cout << "error\n";
        }
        else{
            if(R%2 != 0){
                
            }
        }
    }
}

