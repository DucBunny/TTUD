// Queue trong C++ (FIFO)

#include <bits/stdc++.h>
using namespace std;

queue<int> q;

int main()
{
    string cmd;

    while (getline(cin, cmd))
    {
        if (cmd.substr(0, 4) == "PUSH")
        {
            int x = stoi(cmd.substr(5));
            q.push(x);
        }
        else if (cmd == "POP")
        {
            if (q.size() == 0)
                cout << "NULL" << endl;
            else
            {
                cout << q.front() << endl;
                q.pop();
            }
        }
        else if (cmd[0] == '#')
            break;
    }

    return 0;
}