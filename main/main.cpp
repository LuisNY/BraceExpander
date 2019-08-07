#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include "../expander/src/Expander.h"


int main() {

    std::string input_str;
    std::cin >> input_str;

    Expander exp(input_str);
    if (!exp.isValidString() || !exp.isBalancedString()) {
        return -1;
    }

    int index=0;
    bool c =false;
    auto vect = exp.parseString(index,c);

    // print all possible strings to stdout
    for(auto str : vect ){
        std::cout << str << std::endl;
    }

    return 0;
}