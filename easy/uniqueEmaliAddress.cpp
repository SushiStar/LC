/*
 * Attention: string.erase(start pos, distance);
 * final position not included.
 */
class Solution {
public:
    int numUniqueEmails(vector<string>& emails)
    {
        unordered_set<string> sett;
        for (auto& eml : emails) {
            auto at = eml.find_first_of('@');
            auto plus = eml.find_first_of('+');
            if(plus!=string::npos && plus < at) eml.erase(plus, at-plus);
            auto flg = eml.find_first_of('.');

            for( int i = 0; eml.at(i) != '@'; ++i ) {
                if(eml.at(i) == '.') {
                    eml.erase(i,1);
                    i--;
                }
            }
            sett.insert(eml);
        }
        return static_cast<int> (sett.size());
    }
}
