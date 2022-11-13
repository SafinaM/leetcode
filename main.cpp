#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
//https://leetcode.com/problems/combination-sum/
//Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
//
//The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
//
//The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
//
//
//
//Example 1:
//
//Input: candidates = [2,3,6,7], target = 7
//Output: [[2,2,3],[7]]
//Explanation:
//2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
//7 is a candidate, and 7 = 7.
//These are the only two combinations.
//Example 2:
//
//Input: candidates = [2,3,5], target = 8
//Output: [[2,2,2,2],[2,3,3],[3,5]]
//Example 3:
//
//Input: candidates = [2], target = 1
//Output: []
//
//
//Constraints:
//
//1 <= candidates.length <= 30
//2 <= candidates[i] <= 40
//All elements of candidates are distinct.
//1 <= target <= 40

class Solution {
public:
	std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
		std::set<std::vector<int>> res;
		std::unordered_set<int> set {candidates.begin(), candidates.end()};
		for(const auto& elem: set) {
			if (elem > target)
				continue;

			auto reminder = target % elem;
			int n = target / elem;
			if (reminder == 0) {
				std::vector<int> vec;
				vec.resize(n, elem);
				res.emplace(vec);
			}
			for (int i = 1; i <= n; ++i) {
				int last = target - i * elem;
				if (set.find(last) == set.end() ) {
					continue;
				} else {
					std::vector<int> vec;
					vec.resize(i + 1, elem);
					vec.back() = last;
					std::sort(vec.begin(), vec.end());
					res.emplace(vec);
				}
			}

		}
		return {res.begin(), res.end()};
	}
};

int main() {
	Solution sol;
	std::vector<int> input{7,3,2};
	int target = 18;
	auto result = sol.combinationSum(input, target);
	return 0;
}
