#include <map>
#include <vector>

class Solution {
  public:
    std::vector<int> twoSum(std::vector<int> &, int);
};

std::vector<int> Solution::twoSum(std::vector<int> & nums, int target){
	static std::vector<int> result;
	std::map<int, int> viMap;
	int tmp;
	
	auto p = nums.begin();
	auto end = nums.end();
	
	for(; p != end; p++){
		tmp = target - *p;
		if(viMap.find(tmp) != viMap.end()){
			result.push_back(viMap[tmp]);
			result.push_back(nums.begin() - p);
			return  result;
		}
		viMap[tmp] = nums.begin() - p;
	}
	
	return result;
}
