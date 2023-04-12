#include<iostream>
#include<array>
using namespace std;

void findindices(int target_number, int array_input[],int array_size){
	for (int j=0;j<(array_size-1);j++){
		for (int k=(j+1);k<array_size;k++){
			if((array_input[j]+array_input[k])==target_number){
				cout<<j;
				cout<<k;
			}
		}
	}

}

int main() {
	int array_size;
	int array_input[105];
	int target_number;
	int i=0;
	cout<<"Please enter number of elements in array";
	cin>>array_size;
	cout<<"Enter the numbers in the array";
	while(i<array_size){
		cin>>array_input[i];
		i++;
	}
	cout<<"Enter the target number to be matched";
 	cin>>target_number;
 	findindices(target_number,array_input,array_size);
}








