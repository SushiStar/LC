/*
 * Given a url startUrl and an interface HtmlParser, implement a Multi-threaded
 * web crawler to crawl all links that are under the same hostname as startUrl.
 *
 * Return all urls obtained by your web crawler in any order.
 * Your crawler should:
 * Start from the page: startUrl
 * Call HtmlParser.getUrls(url) to get all urls from a webpage of given url.
 * Do not crawl the same link twice.
 * Explore only the links that are under the same hostname as startUrl.
 *
 * Date: 08/13/2020
 * Author: Wei Du
 */
#include "../common.h"

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
  std::unordered_set<std::string> crawed;
  std::string hostname;
  string GetHostName(std::string &url) {
    int cnt_slash{0}, idx{0};
    while (idx < url.size() && cnt_slash < 3) {
      if (url[idx] == '/') ++cnt_slash;
      ++idx;
    }
    if (url[idx - 1] == '/') --idx;
    return url.substr(0, idx);
  }
  bool SameHost(const std::string &url) {
    for (int i = 0; i < hostname.size(); ++i)
      if (hostname[i] != url[i]) return false;
    return true;
  }

public:
  vector<string> crawl(string startUrl, HtmlParser htmlParser) {
    hostname = GetHostName(startUrl);
    vector<string> bfs{startUrl};
    crawed.insert(startUrl);
    while (!bfs.empty()) {
      std::vector<std::future<std::vector<std::string>>> futures(bfs.size());
      std::vector<string> buffer;
      for (int i = 0; i < bfs.size(); ++i)
        futures[i] = std::async(&HtmlParser::getUrls, &htmlParser, bfs[i]);
      for (int i = 0; i < bfs.size(); ++i) {
        auto tmp = futures[i].get();
        for (auto &s : tmp) {
          if (!SameHost(s) || crawed.find(s) != crawed.end()) continue;
          crawed.insert(s);
          buffer.push_back(s);
        }
      }
      std::swap(buffer, bfs);
    }
    return std::vector<string>(crawed.begin(), crawed.end());
  }
};
