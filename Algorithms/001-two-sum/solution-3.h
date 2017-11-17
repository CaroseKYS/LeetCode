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
	
	result.clear(); 
	
	for(; p != end; p++){
		if(viMap.find(*p) != viMap.end()){
			result.push_back(viMap[*p]);
			result.push_back(p - nums.begin());
			return  result;
		}
		tmp = target - *p;
		viMap[tmp] = nums.begin() - p;
	}
	
	return result;
}
