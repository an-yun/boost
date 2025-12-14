//
// Created by zuo on 2025/12/9.
//
#define ADD_MEMBER
#include <macro_pod.hpp>


int main() {
    const size_t macro_pod_size = sizeof(macro_pod);
    std::cout << "In main.cpp macro_pod_size:" << macro_pod_size <<std::endl;
    macro_pod m{1};
    size_t n = 6;
    std::vector<macro_pod> v;
    init_macro_pod_vector(v, n, m);
    std::cout << "After insert macro_pod_vector size:" << v.size() <<std::endl;
}
