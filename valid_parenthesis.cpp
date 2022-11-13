// https://leetcode.com/problems/valid-parentheses/
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
//An input string is valid if:
//
//Open brackets must be closed by the same type of brackets.
//Open brackets must be closed in the correct order.
//Every close bracket has a corresponding open bracket of the same type.
//
//
//Example 1:
//
//Input: s = "()"
//Output: true
//Example 2:
//
//Input: s = "()[]{}"
//Output: true
//Example 3:
//
//Input: s = "(]"
//Output: false


#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

class Solution {
public:
	bool isValid(const std::string& s) {
		std::stack<char> st;
		std::unordered_map<char, char> elems{{'[', ']'}, {'(', ')'}, {'{', '}'}};
		for (char ch: s) {
			if (elems.find(ch) != elems.end()) {
				st.push(ch);
			} else {

				if (st.empty())
					return false;

				auto tmp = st.top();
					st.pop();

				if (ch != elems[tmp])
					return false;

			}
		}

		return st.empty();

	}
};

int main() {

	//	std::string s = "()[[[[[[]]]]][[][]{}";
	std::string s = "]";
	Solution solution;
	auto ans = solution.isValid(s);
	std::cout << ans << std::endl;



	return 0;
}