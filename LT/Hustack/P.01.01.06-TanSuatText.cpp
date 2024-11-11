#include <bits/stdc++.h>
using namespace std;

map<string, int> freq;

void toSpace(string &text)
{
    for (unsigned int i = 0; i < text.size(); i++)
        if (!isalpha(text[i]) && !isdigit(text[i])) // Nếu không phải ký tự hoặc số -> space
            text[i] = ' ';
}

int main()
{
    string text, line;
    while (getline(cin, line)) // Đọc từng dòng đầu vào
        text += line + " ";    // Nối các dòng lại với nhau, thêm khoảng trắng giữa các dòng

    toSpace(text);

    stringstream ss(text); // stringstream: đọc từng từ trong chuỗi
    string word;

    while (ss >> word) // Đọc từng từ trong chuỗi
        freq[word]++;  // Đếm số lần xuất hiện của từ

    for (const auto &str : freq) // auto: tự động xác định kiểu dữ liệu
        cout << str.first << " " << str.second << endl;

    return 0;
}