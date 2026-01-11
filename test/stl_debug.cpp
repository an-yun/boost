//
// Created by zuo on 2026/1/11.
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    cout << "hello world" << endl;
    vector<string> vec;
    vec.push_back("hello");
    vec.push_back("world");
    cout << "print vec, the size is [" << vec.size() << "]" << endl;
    for (auto &i : vec) {
        cout << i << endl;
    }
}