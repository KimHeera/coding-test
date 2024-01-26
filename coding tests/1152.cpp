#include <iostream>
#include <sstream>

using namespace std;

int main()
{
    string input;
    string stringBuffer;
    int cnt = 0;
    getline(cin, input);

    istringstream ss(input);

    while (getline(ss, stringBuffer, ' '))
    {
        if (stringBuffer != "")
        {
            cnt++;
        }
    }

    cout << cnt;
}