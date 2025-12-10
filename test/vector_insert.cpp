//
// Created by zuo on 2025/12/9.
//
#include <vector>
#include <string>
#include <iostream>
#include <boost/regex.hpp>
using insert_type=boost::match_results<std::string::const_iterator>::value_type;

void print_vector(const std::vector<insert_type> & v) {
    std::cout << "vector长度为" << v.size();
    std::string comma {": "};
    for (const insert_type & i : v) {
        std::cout << comma << i.str();
        comma = ", ";
    }
    std::cout << std::endl;
}


void insert(std::vector<insert_type> & v, size_t n, const std::string &c) {
    insert_type content(c.begin());
    content.second = c.end();
    content.matched = true;
    size_t len = v.size();
    if(len > n + 2)
    {
        v.erase(v.begin()+n+2, v.end());
        std::fill(v.begin(), v.end(), content);
    }
    else
    {
        std::fill(v.begin(), v.end(), content);
        if(n+2 != len)
            v.insert(v.end(), n+2-len, content);
    }
    print_vector(v);
}


int main() {
    std::vector<insert_type> v;
    std::string content{"hello"};
    insert(v, 4, content);
    print_vector(v);
}