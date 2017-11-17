#include <iostream>
#include <cassert>
#include <vector>
#include "solution-3.h";

using namespace std;
int main(void){
	Solution s3;
	vector<int> arr = {2, 3, 4};
	vector<int> result = s3.twoSum(arr, 6);
	
	cout << result.size() << " ";
	for(int i: result){
		cout << i << " ";
	}
}
