/*
 *
 * Date: 04/17/2020
 * Author: Wei Du
 */
class Solution {
public:
    vector<string> subdomainVisits(vector<string> &cpdomains) {
        std::vector<string> rlt{};
        if (cpdomains.empty()) return rlt;
        std::unordered_map<std::string, int> counter;
        for (auto &s : cpdomains) {
            std::vector<std::string> segments{};
            breakString(segments, s);
            int ct(std::stoi(segments[0]));
            for (int i = 1; i < segments.size(); ++i)
                counter[segments[i]] += ct;
        }
        for (auto &p : counter) {
            rlt.push_back(std::to_string(p.second) + " " + p.first);
        }
        return rlt;
    }

private:
    void breakString(std::vector<std::string> &rlt, std::string &s) {
        rlt.clear();
        auto bk = s.find_first_of(' ');
        rlt.push_back(s.substr(0, bk));

        s.erase(0, bk + 1);
        rlt.push_back(s);
        while ((bk = s.find_first_of('.')) != std::string::npos) {
            s.erase(0, bk + 1);
            rlt.push_back(s);
        }
    }
};
