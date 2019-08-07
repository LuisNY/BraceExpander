#ifndef BRACE_EXPANDER_H
#define BRACE_EXPANDER_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <assert.h>

struct validChar {
    bool operator()(char x){
        return (!std::isalpha(x) && x!='{' && x!='}' && x!=',');
    }
};

class Expander {

    std::string str_;

public:
    explicit Expander(std::string str) : str_(std::move(str)) {}

    // make sure input string does not contain invalid chars
    bool isValidString();

    // make sure that the input string is balanced and commas are always inside braces
    bool isBalancedString();

    //parse string and return vector of strings with all possible combinations
    std::vector<std::string> parseString(int& index, bool comma_seen);

private:

    // helper function to move the content of temp_strs to local_strs and/or eventually to global_strs
    void combine(std::vector<std::string>& temp_strs, std::vector<std::string>& local_strs,
                 std::vector<std::string>& global_strs);

    //helper function to combine together two vectors of strings
    void merge(std::vector<std::string>& local_strs, const std::vector<std::string>& temp_strs);
};


#endif //BRACE_EXPANDER_H
