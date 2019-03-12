/*
 * Given n pairs of parentheses, write a function to generate all combinations
 * of well-formed parentheses.
 *
 * Author: Wei Du
 *
 * Date: Mar/11/2019
 */

class Solution{
public:
    struct str{
        str():s("("),left(1),right(0){}
        str(const str &out):s(out.s), left(out.left), right(out.right){}
        string s;
        int left;
        int right;
    };

    void addB(str ss, vector<string>& res, int n) {
        if(ss.s.size() == n*2) {
            res.push_back(ss.s);
            return;
        }
        str cpss(ss);

        if (ss.left < n) {
            ++ss.left;
            ss.s += "(";
            addB(ss, res, n);

            if(cpss.left > cpss.right){
                ++cpss.right;
                cpss.s += ")";
                addB(cpss, res, n);
            }
        } else if (ss.left >= n) {
            ++ss.right;
            ss.s += ")";
            addB(ss, res, n);
        } 
        return;
    }

    vector<string> generateParenthesis(int n) {
        std::vector<string> res;
        str ss;
        addB(ss, res, n);
        return res;
    }
};
