#include<simplecpp>
using namespace std;

int removeDuplicate(vector<int>&nums){
	int n = nums.size();
	if(n<=1)
		return n;
	int k =1;
	for(int i= 1; i<n; ++i){
		if(nums[i] != nums[i-1]){
			nums[k] = nums[i];
			++k;
		}
	}
	return k;
}

int main(){
	vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
	int k = removeDuplicate(nums);
	cout << k << "\n";
	for (int i= 0; i<k; ++i){
		cout << nums[i] << ", ";
}
cout << endl;
}
