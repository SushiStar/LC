class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
            std::vector<int> result;
            bool incre = true; 
            for (int i = digits.size()-1; i >=0; --i) {
                if (incre) {
                    digits.at(i) += 1;
                    if(digits.at(i) >= 10){
                        result.push_back(digits.at(i)-10);
                    }else{
                        result.push_back(digits.at(i));
                        incre = false;
                    }
                } else{
                    result.push_back(digits.at(i));
                }
            }
            if (incre) {
                result.push_back(1);
            }
                std::reverse(result.begin(), result.end());
        return result;
     } 

};
