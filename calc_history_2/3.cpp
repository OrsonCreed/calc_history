#include<iostream>
using namespace std;
void array(int *arr,int s){
	//int var[] = *arr[];
	int sum = 0;
	for(int i = 0;i<s;i++){
		sum += *arr;
		++arr;
	}
	cout<<sum<<endl;
}

int main(){
	int arr[] = {10,20,30,40};
	int size  = sizeof(arr)/sizeof(arr[0]);
	int *ptr;
	ptr = arr;
	cout<<size<<endl<<endl<<endl<<endl;
	array(ptr,size);
	return 0;
}