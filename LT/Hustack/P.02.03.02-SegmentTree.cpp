// Cây phân đoạn (Segment Tree) là một cấu trúc dữ liệu dùng để giải quyết các bài toán liên quan đến các truy vấn trên một dãy số.

#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e7 + 5;

int N, m;
int id, i, j, value;
int maxVal[maxN];

int GetMaxFromNode(int id, int L, int R, int i, int j) // max trên đoạn [i, j]
{
    if (i > R || j < L)
        return -1;

    if (i <= L && j >= R)
        return maxVal[id];

    int m = (L + R) / 2;
    int leftChild = 2 * id;
    int rightChild = 2 * id + 1;

    int maxLeft = GetMaxFromNode(leftChild, L, m, i, j);
    int maxRight = GetMaxFromNode(rightChild, m + 1, R, i, j);
    return max(maxLeft, maxRight);
}

int GetMax(int i, int j)
{
    return GetMaxFromNode(1, 1, N, i, j);
}

void UpdateFromNode(int id, int L, int R, int index, int value)
{
    if (L > R)
        return;
    if (index < L || index > R)
        return;
    if (L == R)
    {
        maxVal[id] = value;
        return;
    }

    int m = (L + R) / 2;
    int leftChild = 2 * id;
    int rightChild = 2 * id + 1;

    UpdateFromNode(leftChild, L, m, index, value);
    UpdateFromNode(rightChild, m + 1, R, index, value);
    maxVal[id] = max(maxVal[leftChild], maxVal[rightChild]);
}

void Update(int index, int value) // index: vị trí, value: giá trị
{
    UpdateFromNode(1, 1, N, index, value);
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> value;
        Update(i, value);
    }

    cin >> m;
    string cmd;
    do
    {
        getline(cin, cmd);
        stringstream ss(cmd); // stringstream: đọc từng từ trong chuỗi
        string word;          // từ đọc được
        ss >> word;           // đọc từ đầu tiên trong chuỗi
        if (word == "get-max")
        {
            ss >> i >> j; // đọc 2 số tiếp theo trong chuỗi
            cout << GetMax(i, j) << endl;
        }
        else if (word == "update")
        {
            ss >> id >> value;
            Update(id, value);
        }
    } while (m--);

    return 0;
}

/* Input
10
1 10 9 7 1 4 2 4 8 10
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Ouput
4
8
9
20 */