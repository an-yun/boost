//
// Created by zuo on 2025/12/14.
//
#include<macro_pod.hpp>

void nothing() {
    std::vector<macro_pod> v;
    macro_pod m{0};
    bug_insert_vector(v, 0, m);
    std::cout << "nothing" << std::endl;
}