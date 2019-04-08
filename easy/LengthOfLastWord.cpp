class Solution {
public:
    int lengthOfLastWord(string s) {
        int x = 0;
        if (s.empty()) return x;
        int mark = s.size()-1;
        while(' ' == s[mark]){
            mark--;
        }
        for( int i = mark; i >= 0; --i) {
            if(' ' != s[i]){
                x++;
            } else {
                return x;
            }
        }
        return x;
    }
};
