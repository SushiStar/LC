/*
 *  The function firstly discard as many whitespaces as possible,
 *  until the first non-whitespace character is found.
 *  Then starting from this character, takes an optional '+' sign or '-' sign
 *  followed by as many numerical digits as possible. And interprets them as
 *  numerical values.
 *
 *  Date: Mar/02/2019
 *
 *  Author: Wei Du
 */

class Solution {
public:
    int myAtoi(string str) {
        std::string extract("");        
        bool sign = false;     
        bool space = false;
        bool begin0 = false
        int sg = 1;   
        for (int i = 0; i < str.size(); ++i) {
            if (!space && str.at(i) == ' ')  {
                continue;
            }
            if (!sign && (str.at(i) == 43 || str.at(i) == 45) ){
                if (str.at(i) == 45) sg = -1;   
                sign = true;  
                space = true;
            } else if (str.at(i) >= 48 && str.at(i) <= 57){
                sign = true;
                space = true;
                if(!begin0 && str.at(i) == 0 ) {
                    continue;
                } else {
                    begin0 = true;
                    extract += str.at(i);           
                }

            } else {
                break;         
            }                  
        }                      
        
        uint64_t temp(0);      
        int size = extract.size();      
        if(size > 10) {
            if (sg == 1 ) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }               
        }
        if(size  > 0) {        
            for (int i = size-1; i >= 0; --i) { 
                temp += (extract.at(i)-48) * pow(10,size-1-i);
            } 

            if (temp <= INT_MAX) {           
                if (sg == 1) {
                    return temp;              
                } else {
                    return -1*temp;
                }
            } else {
                if (sg == 1 ) {
                    return INT_MAX;
                } else {
                    return INT_MIN;
                }               
            }

        } 
        return 0;
    }   // myAtoi
}

