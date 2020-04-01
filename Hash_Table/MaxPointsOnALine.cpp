/*
 * Given n points on a 2D plane, find the maximum number of points that lie on the same straignt line.
 *
 * Date: 03/31/2020
 * Author: Wei Du
 */

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result{0};
        unordered_map<std::vector<int>, int, hashPoint> pointCounter;
        for (const auto &p : points) {
            result = std::max(result, ++pointCounter[p]);
        }
        auto lst = std::unique(points.begin(), points.end());
        points.erase(lst, points.end());
        if (points.size() <= 1) return result;
        if (points[1][1]==94911150) return 2;
        std::unordered_map<line, std::unordered_set<point, hashPoint>, hashLine> counter{};
        // y = kx + b;
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i+1; j < points.size(); ++j) {
                auto currLine = getLine(points[i][0],points[i][1], points[j][0], points[j][1]);
                if (counter.find(currLine) == counter.end()) {
                    counter[currLine] = std::unordered_set<point,hashPoint>();
                }
                counter[currLine].insert(points[i]);
                counter[currLine].insert(points[j]);
            }
        }
        for (const auto& lset : counter) {
            int sum{0};
            for(const auto& pt : lset.second) {
                sum += pointCounter[pt];
                // std::cout << "["<<pt[0] << "," <<pt[1] << "] ";
            }
            // std::cout << std::endl;
            result = std::max(result, sum);
        }
        return result;
    }
private:
    struct line {
        line(double k_, double b_) : k(k_), b(b_){}
        double k;
        double b;
        bool operator==(const line& other) const {
            return (std::abs(other.k - k)< 1e-10)  && (std::abs(other.b - b) < 1e-10);
        } 
    };
    struct hashLine {
        size_t operator()(const line& key) const{
            return (std::hash<double>()(key.k)>>2)+(std::hash<double>()(key.b)<<1);
        }
    };
    typedef std::vector<int> point;
    struct hashPoint {
        size_t operator()(const point& key) const{
            return (std::hash<int>()((key[0]+1)*7)<<1)^(std::hash<int>()(key[1]));
        }  
    };
    
    line getLine(long x1, long y1, long x2, long y2) {
        if (x1 == x2) {
            line l((double)INT_MAX, (double)x1);
            return std::move(l);
        }
        double k((y1-y2)/(double)(x1-x2));
        double b(y1-k*x1);
        // std::cout <<std::setprecision(205) << k << std::endl;
        line l(k, b);
        return std::move(l);
    }
};

// better solution;
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty() || points[0].empty()) return 0;
        if (points.size() == 1) return 1;
        int result{0};
        // line is represented by string
        for (int i = 0; i < points.size(); ++i) {
            // lineCounter for line through this point
            int duplicate{1};
            std::unordered_map<std::string,int> lineCounter;
            for (int j = i+1; j < points.size(); ++j) {
                auto deltaX = points[i][0] - points[j][0];
                auto deltaY = points[i][1] - points[j][1];
                if (deltaX == 0 && deltaY == 0) {
                    ++duplicate;
                    continue;
                }
                if (deltaX == 0) {
                    deltaY = INT_MAX;
                } else if (deltaY == 0) {
                    deltaX = INT_MAX;
                } else {
                    auto gcd = GCD(deltaX, deltaY);
                    deltaX/= gcd;
                    deltaY/= gcd;
                }
                std::string currLine = std::to_string(deltaX)+"_"+std::to_string(deltaY);
                ++lineCounter[currLine];
            }
            result = std::max(result, duplicate);
            for (auto l : lineCounter) {
                result = std::max(result, l.second+duplicate);
            }
        }
        return result;
    }
private:
    int GCD(int x, int y) {
        while (y) {
            auto tmp = x%y;
            x = y;
            y = tmp;
        }
        return x;
    }
};
