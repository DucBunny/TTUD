// Tổng 2 số nguyên lớn

#include <bits/stdc++.h>
using namespace std;

int main()
{
    string a, b, result;
    cin >> a >> b;

    int carry = 0;        // số nhớ
    int i = a.size() - 1; // vị tri cuối cùng của chuỗi a
    int j = b.size() - 1; // vị tri cuối cùng của chuỗi b
    // trừ 1 vì vị trí cuối là kí tự kết thúc chuỗi
    while (i >= 0 || j >= 0)
    {
        int sum = carry;
        if (i >= 0)
        {
            sum += a[i] - '0';
            i--;
        }
        if (j >= 0)
        {
            sum += b[j] - '0';
            j--;
        }
        carry = sum / 10;
        result += to_string(sum % 10);
    }

    if (carry > 0) // nếu còn số nhớ
        result += to_string(carry);

    reverse(result.begin(), result.end()); // đảo ngược chuỗi

    cout << result << endl;
    return 0;
}