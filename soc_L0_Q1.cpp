#include<iostream>
#include<string>
using namespace std;

int dataTypeSize(const string & dataType){
	if (dataType == "Integer"){
		return sizeof(int);
	}
	else if(dataType == "Character"){
		return sizeof(char);
	}
	else if(dataType == "Long"){
		return sizeof(long);
	}
	else if (dataType == "Float"){
		return sizeof(float);
	}
	else if(dataType == "Double"){
		return sizeof(double);
	}
	else {
		return -1;
	}
}


int main(){
	string inputType;
	cout << "Enter the data type of which you want the byte unit(Integer, Character, Long, Float, Double): " ;
        cin >> inputType;

	int size = dataTypeSize(inputType);
	if (size!= -1){
		cout << size << "\n";
	}
	else {
		cout << "-1" << "\n";
	}
	return 0;
}

