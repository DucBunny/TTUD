#include <bits/stdc++.h>
using namespace std;

stack<int> s;

int main()
{
    string cmd;

    while (getline(cin, cmd)) // getline: đọc dữ liệu từ bàn phím
    {
        if (cmd.substr(0, 4) == "PUSH") // substr(0, 4) lấy 4 kí tự từ vị trí 0
        {
            int x = stoi(cmd.substr(5)); // stoi: string to int
            s.push(x);
        }
        else if (cmd == "POP")
        {
            if (s.size() == 0)
                cout << "NULL" << endl;
            else
            {
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if (cmd[0] == '#')
            break;
    }

    return 0;
}