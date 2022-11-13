//
// Created by mar on 06.11.2022.
//

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

class Solution {

public:

	void convert(const std::string& str, std::vector<int>& digits) {

		for (int j = 1; j < str.size(); ++j) {
			digits[j-1] = str[j] - str[j-1];
		}
	}

	bool areSame(const std::vector<int>& str1, const std::vector<int>& str2) {
		if (str1.size() != str2.size())
			return false;

		for (int i = 0; i < str1.size(); ++i) {
			if (str1[i] != str2[i])
				return false;
		}
		return true;
	}

	int findTheOnlyDifferent(const std::vector<std::vector<int>>& arr) {
		int n = arr.size();

		if (areSame(arr[0], arr[1]) && !areSame(arr[0], arr[2]))
			return 2;
		if (areSame(arr[0], arr[2]) && !areSame(arr[0], arr[1]))
			return 1;
		if (areSame(arr[1], arr[2]) && !areSame(arr[0], arr[1]))
			return 0;

		for (int i = 3; i < n; i++) {
			if (!areSame(arr[i], arr[i - 1]))
				return i;
		}
		return 0;
	}


	std::string oddString(std::vector<std::string>& words) {
		if (words.empty())
			return "";

		std::vector<std::vector<int>> results;

		const int size = int(words[0].size() - 1);
		std::vector<int> digits;
		digits.resize(size);
		const int n = (int)words.size();
		for (int i = 0; i < n; ++i) {
			convert(words[i], digits);
			results.push_back(digits);
		}
		int index = findTheOnlyDifferent(results);
		return words[index];
	}
};

class SolutionHash {

public:

	uint64_t convert(const std::string& str) {
		uint64_t sum = 0;
		for (int j = 1; j < str.size(); ++j) {
			sum = (str[j] - str[j-1]) + sum * 10;
		}
		return sum;
	}

	std::string oddString(std::vector<std::string>& words) {
		if (words.empty())
			return "";

		const int size = int(words[0].size() - 1);
		std::unordered_map<uint64_t, int> map;
		std::unordered_map<uint64_t, int> indexes;
		for (int i = 0; i < words.size(); ++i) {
			uint64_t digit = convert(words[i]);
			++map[digit];
			indexes[digit] = i;
		}

		for (auto it = map.begin(); it != map.end(); ++it) {
			if (it->second == 1)
				return words[indexes[it->first]];
		}

		return "";
	}


};

int main() {

	SolutionHash solution;
	std::vector<std::string> input{"mll","edd","jii","tss","fee","dcc","nmm","abb","utt","zyy","xww","tss","wvv","xww","utt"};
	auto result = solution.oddString(input);

	std::cout << result << std::endl;
	return 0;
}