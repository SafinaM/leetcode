//Given a string s, return the longest palindromic substring in s.
//
//
//
//Example 1:
//
//Input: s = "babad"
//Output: "bab"
//Explanation: "aba" is also a valid answer.
//Example 2:
//
//Input: s = "cbbd"
//Output: "bb"
//
//
//Constraints:
//
//1 <= s.length <= 1000
//s consist of only digits and English letters.

#include <string>
#include <map>

class Solution {
public:

	bool check(const std::string& s, int& low, int& high) {
		int l = low;
		int h = high;
		bool isPaliandrome = false;
		while (l >= 0 && h < s.size()) {
			if (s[l] != s[h]) {
				break;
			}
			isPaliandrome = true;
			low = l;
			high = h;
			--l;
			++h;
		}
		return isPaliandrome;
	}

	std::string longestPalindrome(std::string s) {

		if (!s.size())
			return "";

		if (s.size() == 1)
			return s;
		std::multimap<int, std::pair<int, int>> indexes;
		for (uint32_t i = 0; i < s.size(); ++i) {
			int low = i;
			int high = i + 1;
			if (high < s.size() && check(s, low, high)) {
				indexes.emplace(high - low, std::make_pair(high, low));
			}

			low = i;
			high = i + 2;
			if (high < s.size() && check(s, low, high)) {
				indexes.emplace(high - low, std::make_pair(high, low));
			}
		}
		if (indexes.empty())
			return s.substr(0, 1);
		int high = indexes.rbegin()->second.first;
		int low = indexes.rbegin()->second.second;

		return s.substr(low, high - low + 1);
	}
};

int main() {
	Solution solution;
	std::string str1 = "abba";
	std::string str2 = "bddc";
	std::string str3 = "babad";
	std::string str4 = "ac";
	auto result = solution.longestPalindrome(str4);

	return 0;
}