/*
 * Given a list of directory info including directory path, and all
 * the files with contents in this directory, you need to find out
 * all the groups of dupicate files in the file system in terms of
 * their paths.
 *
 * A group of duplicate files consists of at least two files that
 * have exactly the same content.
 * A single directory into string in the input list has the following
 * format:
 * "root/d1/d2/.../dm f1.txt(f1_content) f2.txt(f2_content) ...
 * fn.txt(fn_content)" It means there are n files with contents in this
 * directory. Note that n >=1 and m >=0. If m = 0, it means the directory is
 * just the root directory. The output is a list of group of duplicate file
 * paths. For each group, it contains all the file paths of the files that have
 * the same comtent. A file path is a string that has the following format:
 *  "directory_path/file_name.txt"
 * Date: 04/17/2020
 * Author: Wei Du
 */
class Solution {
public:
	vector<vector<string>> findDuplicate(vector<string> &paths) {
		std::vector<std::vector<std::string>> rlt{};
		std::unordered_map<std::string, std::vector<std::string>> mp;
		for (auto &p : paths) {
			std::vector<std::string> segments{};
			breakStr(segments, p);
			for (int i = 1; i < segments.size(); ++i)
				mp[getContent(segments[i])].push_back(segments[0] + '/' +
						segments[i]);
		}
		for (auto &pr : mp)
			if (pr.second.size() > 1) rlt.push_back(pr.second);
		return rlt;
	}

private:
	void breakStr(std::vector<std::string> &rlt, std::string &s) {
		auto bk = s.find_first_of(' ');
		rlt.push_back(s.substr(0, bk));
		auto prev(bk);
		while ((bk = s.find(' ', bk + 1)) != std::string::npos) {
			rlt.push_back(s.substr(prev + 1, bk - prev - 1));
			prev = bk;
		}
		rlt.push_back(s.substr(prev + 1));
	}

	std::string getContent(std::string &s) {
		auto l = s.find('(');
		auto r = s.find(')');
		auto rtr(s.substr(l + 1, r - l - 1));
		s.erase(l);
		return rtr;
	}
};
