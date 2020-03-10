//Lab 4
//Sam Disharoon
//main.cpp
#include<iostream>
#include"priorityQ.h"
#include<time.h>
#include<string>
int main(){
	int n=0;
	std::cout<<"How large do you want your array?\n";
	std::cin>>n;
	int* arr=new int[n];
	for(int i=0;i<n;i++){
	 arr[i]=i;
	}
	int* arrP=new int[n];
	for(int j=0;j<n;j++){
	arr[j]=j+1;
	}
	HeapQ<int> A1(arr,arrP,n);
	//A1.BuildMaxHeap(A1);	Doesn't work
	





	delete [] arr;
	delete [] arrP;
return 0;
}
