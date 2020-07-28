/*
 * Given an absolute path for a file (Unix-style), simplify it. Or in other
 * words, convert it to the canonical path.
 *
 * In a UNIX-style file system, a period . refers to the current directory.
 * Furthermore, a double period .. moves the directory up a level.
 *
 * Note that the returned canonical path must always begin with a slash /, and
 * there must be only a single slash / between two directory names. The last
 * directory name (if it exists) must not end with a trailing /. Also, the
 * canonical path must be the shortest string representing the absolute path.
 *
 * Date: 07/28/2020
 * Author: Wei Du
 */
#include "../common.h"

class Solution {
 public:
  string simplifyPath(string path) {
    std::string ret("/");
    path.push_back('/');
    for (int i = 0; i < path.size(); ++i) {
      if (path[i] == '/') {
        if (ret.back() == '.') {
          int cntdot{0};
          for (int i = ret.size() - 1; i > 0; --i) {
            if (ret[i] == '.') {
              ++cntdot;
            } else {
              break;
            }
          }
          if (cntdot == 1) {
            ret.pop_back();
            continue;
          } else if (cntdot == 2) {
            int cntslash{0};
            while (!ret.empty() && cntslash < 2) {
              if (ret.back() == '/') ++cntslash;
              ret.pop_back();
            }
          }
          ret.push_back('/');
        } else if (ret.back() != '/')
          ret.push_back('/');
      } else {
        ret.push_back(path[i]);
      }
      if (ret.empty()) ret.push_back('/');
    }
    if (ret.back() == '/' && ret.size() > 1) ret.pop_back();
    return ret;
  }
};
