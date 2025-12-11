#define BOOST_REGEX_MATCH_EXTRA
#include <boost/regex.hpp>
#include <iostream>
using sub_match_type = boost::smatch::value_type;
// 第1行手动启用了扩展捕获，在下面第43行输出32
const size_t sub_match_size = sizeof(sub_match_type);

void print_captures(const std::string &regx, const std::string &text) {
    boost::regex e(regx);
    boost::smatch what;
    std::cout << "Expression:  \"" << regx << "\"\n";
    std::cout << "Text:        \"" << text << "\"\n";

    if (boost::regex_match(text, what, e, boost::match_extra)) {
        unsigned i, j;
        std::cout << "** Match found **\n   Sub-Expressions:\n";
        size_t s = what.size();
        for (i = 0; i < s; ++i)
            std::cout << "      $" << i << " = \"" << what[i] << "\"\n";
        // 如果定义了如下宏，说明启用了捕获组扩展功能
#ifdef  BOOST_REGEX_MATCH_EXTRA
        std::cout << "   Captures:\n";
        for (i = 0; i < s; ++i) {
            std::cout << "      $" << i << " = {";
            size_t cs = what.captures(i).size();
            for (j = 0; j < cs; ++j) {
                if (j)
                    std::cout << ", ";
                else
                    std::cout << " ";
                std::cout << "\"" << what.captures(i)[j] << "\"";
            }
            std::cout << " }\n";
        }
#endif
    } else {
        std::cout << "** No Match found **\n";
    }
}

int main(int, char *[]) {
    // 此处输出sub_match_size 为32
    std::cout<<"sub_match_size: "<< sub_match_size <<std::endl;
    print_captures("(([[:lower:]]+)|([[:upper:]]+))+", "aBBcccDDDDDeeeeeeee");
    print_captures("(.*)bar|(.*)bah", "abcbar");
    print_captures("(.*)bar|(.*)bah", "abcbah");
    print_captures("^(?:(\\w+)|(?>\\W+))*$",
                   "now is the time for all good men to come to the aid of the party");
    return 0;
}
