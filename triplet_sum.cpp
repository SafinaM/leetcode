//
// Created by mar on 10.11.2022.
//

#include <vector>
#include <algorithm>
#include <iostream>

class Solution {
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
		if (nums.empty())
			return {};

		if (nums.size() < 3)
			return {};

		std::sort(nums.begin(), nums.end());

		if (nums[0] > 0)
			return {};

		std::vector<std::vector<int>> result;
		for (int i = 0; i < nums.size(); ++i) {
			int low = i + 1;
			int high = nums.size() - 1;

			if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
				break;
			}
			if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
				continue;
			}

			while (low < high) {
				int sum = nums[i] + nums[low] + nums[high];

				if (sum > 0) {
					--high;
				} else if (sum < 0) {
					++low;
				} else {
					result.push_back({nums[i], nums[low], nums[high]});
					int lastLow = nums[low];
					while (low < high && nums[low] == lastLow) {
						++low;
					}

					int lastHigh = nums[high];
					while (low < high && nums[high] == lastHigh) {
						--high;
					}
				}
			}
		}
		return result;
	}
};

//class Solution {
//public:
//    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
//        sort(nums.begin() , nums.end());    //Sorted Array
//        if(nums.size() < 3){    //Base case 1
//            return {};
//        }
//        if(nums[0] > 0){        //Base case 2
//            return {};
//        }
//        std::vector<std::vector<int>> answer;
//        for(int i = 0 ; i < nums.size() ; ++i){     //Traversing the array to fix the number.
//            if(nums[i] > 0){     //If number fixed is +ve, stop there because we can't make it zero by searching after it.
//                break;
//            }
//            if(i > 0 && nums[i] == nums[i - 1]){    //If number is getting repeated, ignore the lower loop and continue.
//                continue;
//            }
//            int low = i + 1 , high = nums.size() - 1;   //Make two pointers high and low, and initialize sum as 0.
//            int sum = 0;
//            while(low < high){                          //Search between two pointers, just similiar to binary search.
//                sum = nums[i] + nums[low] + nums[high];
//                if(sum > 0){   //If sum is +ve, means, we need more -ve numbers to make it 0, decreament high (high--).
//                    high--;
//                } else if(sum < 0){ //If sum is -ve, means, we need more +ve numbers to make it 0, increament low (low++).
//                    low++;
//                } else {
//                    answer.push_back({nums[i] , nums[low] , nums[high]});  //we have found the required triplet, push it in answer vector
//                    int last_low_occurence = nums[low] , last_high_occurence = nums[high];  //Now again, to avoid duplicate triplets, we have to navigate to last occurences of num[low] and num[high] respectively
//                    while(low < high && nums[low] == last_low_occurence){   // Update the low and high with last occurences of low and high.
//                        low++;
//                    }
//                    while(low < high && nums[high] == last_high_occurence){
//                        high--;
//                    }
//                }
//            }
//        }
//        return answer;      //Return the answer vector.
//    }
//};

int main() {
//	std::vector<int>vec{-1, 0, 1, 2, -1, -4};
	std::vector<int>vec{1,-1,-1,0};
	Solution solution;
	auto result = solution.threeSum(vec);
	std::cout << "size = " << result.size() << std::endl;

	return 0;
}