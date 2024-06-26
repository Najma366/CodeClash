#include<simplecpp>
using namespace std;
 int findPeakElement(vector<int>& nums){
	 int n = nums.size();
	 int left = 0, right = n -1;
	 while(left < right){
		 int mid = left + (right - left) / 2;
		 if (nums[mid] > nums[mid + 1])
			 right = mid;
		 else
		         left = mid + 1 ;
	 }
	 return left;
 }
int main(){
	vector<int> nums = {1,2,1,3,5,6,4};
	int peakIndex = findPeakElement(nums);
	cout << peakIndex << "\n";
}
