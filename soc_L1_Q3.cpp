#include<iostream>
using namespace std;

int main(){
	int nums[] = {0};
	int n = sizeof(nums) / sizeof(nums[0]);
	int j = 0;
	for (int i =0; i <n; i++){
		if (nums[i] != 0){
			swap(nums[j], nums[i]);
			j++;
		}
	}
	for (int i = 0; i < n; i++){
		cout << nums[i] << " ";
	}
cout <<"\n";
}
