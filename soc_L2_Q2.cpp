#include<iostream>
using namespace std;
int findRotationCount(int arr[], int n){
	int minElement = arr[0];
	int minIndex = 0;
	for (int i = 0; i < n; ++i){
		if(arr[i] < minElement){
			minElement = arr[i];
			minIndex = i;
		}
	}
	return minIndex;
}

int main(){
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr) / sizeof(arr[0]);
	int rotations = findRotationCount(arr, n);
	cout << rotations << endl;
}
