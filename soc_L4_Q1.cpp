#include<iostream>
#include<vector>
using namespace std;

void subsetSums(int arr[], int l, int r, int sum = 0){
	if(l > r){
		cout << sum << " ";
		return;
	}
	subsetSums(arr, l + 1, r, sum + arr[l]);
	subsetSums(arr, l + 1, r, sum);
}

int main(){
	int arr[] = {2,3};
	int n = 2;
	subsetSums(arr, 0,n - 1);
}
