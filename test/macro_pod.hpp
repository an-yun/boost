//
// Created by zuo on 2025/12/14.
//

#ifndef MYPROJECT_MACRO_CLASS_HPP
#define MYPROJECT_MACRO_CLASS_HPP
#include <vector>
#include <string>
#include <iostream>
#include <sstream>


class macro_pod {
public:
    macro_pod(int normal_i = 0):
    normal_i(normal_i)
    ,normal_ui(static_cast<unsigned>(normal_i) + 1)
#ifdef ADD_MEMBER
    ,macro_ul(static_cast<unsigned long>(normal_i) + 2)
#endif
    {}
    std::string str() const {
        std::ostringstream ss;
        ss << "normal_i is:" << normal_i << std::endl;
        ss << "normal_ui is:" << normal_ui << std::endl;
#ifdef ADD_MEMBER
        ss << "normal_ui is:" << macro_ul << std::endl;
#endif
        return ss.str();
    }

private:
    int normal_i;
    unsigned normal_ui;
#ifdef ADD_MEMBER
    unsigned long macro_ul;
#endif
};

class macro_pod_vector {
public:
    macro_pod_vector(std::vector<macro_pod> &v):v(&v) {}

    void insert(size_t n, const macro_pod &c) {
        v->insert(v->end(), n, c);
    }


    void print() const {
        std::cout << "vector length is: " << v->size();
        // std::string comma{"\n "};
        // for (const macro_pod &i: v) {
        //     std::cout << comma << i.str();
        //     comma = ", ";
        // }
        std::cout << std::endl;
    }
private:
    std::vector<macro_pod> *v;
};
// bug here
void bug_insert_vector(std::vector<macro_pod> &v, size_t n, const macro_pod &c) {
    const size_t macro_pod_size = sizeof(macro_pod);
    std::cout << "In macro_pod.hpp macro_pod_size:" << macro_pod_size <<std::endl;
    macro_pod copy_c{c};
    macro_pod_vector member_v{v};
    member_v.insert(n, copy_c);
    member_v.print();
}

inline void init_macro_pod_vector(std::vector<macro_pod> &v, size_t n, const macro_pod &c) {
    bug_insert_vector(v, n,c);
}



#endif //MYPROJECT_MACRO_CLASS_HPP