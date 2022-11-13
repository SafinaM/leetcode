//https://leetcode.com/problems/words-within-two-edits-of-dictionary/

//You are given two string arrays, queries and dictionary. All words in each array comprise of lowercase English letters and have the same length.
//
//In one edit you can take a word from queries, and change any letter in it to any other letter. Find all words from queries that, after a maximum of two edits, equal some word from dictionary.
//
//Return a list of all words from queries, that match with some word from dictionary after a maximum of two edits. Return the words in the same order they appear in queries.
//
//
//
//Example 1:
//
//Input: queries = ["word","note","ants","wood"], dictionary = ["wood","joke","moat"]
//Output: ["word","note","wood"]
//Explanation:
//- Changing the 'r' in "word" to 'o' allows it to equal the dictionary word "wood".
//- Changing the 'n' to 'j' and the 't' to 'k' in "note" changes it to "joke".
//- It would take more than 2 edits for "ants" to equal a dictionary word.
//- "wood" can remain unchanged (0 edits) and match the corresponding dictionary word.
//Thus, we return ["word","note","wood"].
//Example 2:
//
//Input: queries = ["yes"], dictionary = ["not"]
//Output: []
//Explanation:
//Applying any two edits to "yes" cannot make it equal to "not". Thus, we return an empty array.
//
//
//Constraints:
//
//1 <= queries.length, dictionary.length <= 100
//n == queries[i].length == dictionary[j].length
//1 <= n <= 100
//All queries[i] and dictionary[j] are composed of lowercase English letters.

#include <string>
#include <vector>
#include <cassert>

class Solution {

	bool eq(const std::string& str1, const std::string& str2) {
		const std::size_t n = str1.size();
		if (n != str2.size())
			return false;
		int k = 0;
		for (int i = 0; i < n; ++i) {
			if (str1[i] != str2[i]) {
				++k;
			}
			if (k > 2)
				break;
		}

		return k < 3;
	}
public:
	std::vector<std::string> twoEditWords(const std::vector<std::string>& queries, const std::vector<std::string>& dictionary) {
		std::vector<std::string> result;
		result.reserve(dictionary.size());
		for (auto i = 0; i < queries.size(); ++i) {
			bool interupt = false;
			for (auto j = 0; j < dictionary.size(); ++j) {
				if (eq(queries[i], dictionary[j])) {
					result.push_back(queries[i]);
					interupt = true;
					break;
				}
			}
			if (interupt)
				continue;
		}
		return result;
	}
};

int main() {
	Solution solution;
	auto result = solution.twoEditWords({"word","note","ants","wood"}, {"wood","joke","moat"});
	const std::vector<std::string> test{"word", "note", "wood"};
	assert(test.size() == result.size());
	for (std::size_t i = 0; i < test.size(); ++i) {
		for (std::size_t j = 0; j < test[i].size(); ++j)
			assert(test[i][j] == result[i][j]);
	}
	return 0;
}