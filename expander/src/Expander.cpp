#include "Expander.h"

bool Expander::isValidString(){

    if(str_.empty()){
        return false;
    }

    //look for the first invalid char and if found return false
    auto invalid_char = std::find_if(str_.begin(), str_.end(), validChar());
    if(invalid_char!=str_.end()){
        return false;
    }
    return true;
}

// make sure that the input string is balanced and commas are always inside braces
bool Expander::isBalancedString(){

    std::stack<char> stk; // use stack to keep track of nested braces
    int i=0;
    while (i<str_.size()) {

        if (str_[i] == '}' && stk.empty()) {
            return false;
        } else if (str_[i] == '}' && (str_[i-1] == '{' || str_[i-1] == ',')) {
            return false;
        } else if(str_[i] == ',' && ((str_[i-1] == '{' || str_[i-1] == ',') || stk.empty())) {
            return false;
        } else if (str_[i] == '}') {
            stk.pop();
        } else if (str_[i] == '{') {
            stk.push('{');
        } else if (std::isalpha(str_[i])) {
            while(std::isalpha(str_[i])) {
                i++;
            }
            continue;
        }
        i++;
    }
    if (!stk.empty()) {
        return false;
    }
    return true;
}

//parse string and return vector of strings with all possible combinations
std::vector<std::string> Expander::parseString(int& index, bool comma_seen) {

    std::vector<std::string> temp_strs; // used to cache the alpha chars as they are parsed
    std::vector<std::string> local_strs; // used to momentarily save the parsed combinations within current braces
    std::vector<std::string> global_strs; // used to save and return all combinations of chars parsed at every time

    while(index<str_.size()){

        if(str_[index] == '{'){

            if(!comma_seen){ //check if the opening braces are nested braces and are found after a comma
                combine(temp_strs, local_strs, global_strs);
            } else {
                if(local_strs.empty()){ // if local_strs is empty local_strs becomes temp_strs
                    local_strs = temp_strs;
                } else if (!temp_strs.empty()) { //else merge the two vectors of strings
                    merge(local_strs, temp_strs);
                }
                temp_strs.clear();
            }

            auto strs = parseString(++index, comma_seen); //recursive call every time we find opening brace

            // merge the return value of recursive call with local_strs
            if(local_strs.empty()){
                local_strs = strs;
            } else { // if local already contains strings then combine with the strings returned from recursive call
                merge(local_strs,strs);
            }

        } else if (str_[index] == ','){
            index++;
            comma_seen=true;
            combine(temp_strs, local_strs, global_strs);
            global_strs.insert(global_strs.end(), local_strs.begin(), local_strs.end());
            local_strs.clear();
        } else if (str_[index] == '}'){
            index++;
            combine(temp_strs, local_strs, global_strs);
            global_strs.insert(global_strs.end(), local_strs.begin(), local_strs.end());
            return global_strs;
        } else { // it must be an alpha character at this point
            std::string str;
            while(std::isalpha(str_[index])){
                str+=str_[index++];
            }
            temp_strs.push_back(str);
        }
    }

    combine(temp_strs, local_strs, global_strs);
    global_strs.insert(global_strs.end(), local_strs.begin(), local_strs.end());
    return global_strs;
}


// helper function to move the content of temp_strs to local_strs and/or eventually to global_strs
void Expander::combine(std::vector<std::string>& temp_strs, std::vector<std::string>& local_strs,
             std::vector<std::string>& global_strs){

    if(temp_strs.empty()){
        return;
    }

    if(!local_strs.empty()){
        merge(local_strs, temp_strs); // merge local_strs with temp_strs
        if(!global_strs.empty()){
            global_strs.insert(global_strs.end(), local_strs.begin(), local_strs.end());
            local_strs.clear();
        }
    } else if(!global_strs.empty()){
        global_strs.insert(global_strs.end(), temp_strs.begin(), temp_strs.end());
    } else {
        local_strs.insert(local_strs.end(), temp_strs.begin(), temp_strs.end());
    }
    temp_strs.clear();
}

//helper function to combine together two vectors of strings
void Expander::merge(std::vector<std::string>& local_strs, const std::vector<std::string>& temp_strs){
    auto local_copy = local_strs;
    local_strs.clear();
    for (int i = 0; i < local_copy.size(); i++) {
        for (const auto &str : temp_strs) {
            local_strs.push_back(local_copy[i] + str);
        }
    }
}