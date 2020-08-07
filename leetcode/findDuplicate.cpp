#include <iostream>
#include <vector>

using namespace std;

vector<int> findDuplicates(vector<int>& nums) {
	vector<int> Ret={};
	for(int i=0;i<nums.size();i++){
		if(nums[abs(nums[i])-1]>0)
			nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
		else {
			nums[abs(nums[i])-1]=-nums[abs(nums[i])-1];
			Ret.push_back(abs(nums[i]));
		}
	}
	return Ret;
}

int main() {
	vector<int> input = {1,1,1,1};
	vector<int> ret = findDuplicates(input);
	for (int i = 0; i < ret.size(); i++) {
		cout << ret[i] << " ";
	}
}