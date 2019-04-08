/**
 * Write a function to find the longest common prefix string
 * amongest an array of strings.
 * If there's no commong prefix, return an empty string "".
 */


class Solution {
public:
    struct compare {
        bool operator()(const std::string& first, const std::string& second){
            return first.size() < second.size();
        }
    };
    
    string longestCommonPrefix(vector<string>& strs) {
        compare c;
        std::sort(strs.begin(), strs.end(), c);
        bool findflag = true;
        if(strs.empty()) return "";
        //int substr_size = strs[0].size();
        for(int str_size = strs[0].size(); str_size > 0; str_size--){
                std::string target = strs[0].substr(0, str_size);
                findflag = true;
                for(auto s : strs){
                    std::string temp = s.substr(0, target.size()); 
                    if(temp!= target){
                        findflag = false;
                        break;  
                    } 
                }
                if(findflag) return target;
        }
        return "";
    }
};
