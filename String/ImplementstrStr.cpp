/*
 * Implement strStr().
 * Return the index of the first occurrence of needle in haystack, or
 * -1 if needle is not part of the haystack.
 *
 * Date: 04/27/2020
 * Author: Wei Du
 */

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        if( 0 == needle.size() ) return 0;
        if( haystack.size() < needle.size() )  return -1;
        int size = needle.size();
        for(int i = 0; i < haystack.size() -size + 1; ++i ) 
           if(haystack.substr(i, size) == needle) 
        return -1;
    }
};
