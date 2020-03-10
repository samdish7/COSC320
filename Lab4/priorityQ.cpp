//Sam Disharoon
//priorityQ.cpp
#include"priorityQ.h"
#include<iostream>
#include<algorithm>
#include<limits>
template<class T>
HeapQ<T>::HeapQ(T* A, int* p, int i){
	for(int x=0;x<i;x++){
	arr[x]=A[x];
	}
	for(int y=0;y<i;y++){
	}
		
}
template<class T>
int HeapQ<T>::parent(int i){return i/2;}
template<class T>
int HeapQ<T>::left(int i){return 2*i;}
template<class T>
int HeapQ<T>::right(int i){return (2*i)+1;}
template<class T>
void HeapQ<T>::MaxHeapify(HeapQ A, int i){
int l=left(i);
        int r=right(i);
        int largest=0;
        if(l<=A.heap_size && A[l]>A[i]){
        largest=l;
        }
        else {largest=i;}
        if(r<=A.heap_size && A[r]>A[largest]){
        largest=r;
        }
        if(i!=largest){std::swap(A[i],A[largest]);
        MaxHeapify(A,largest);
        }
}
template<class T>
void HeapQ<T>::BuildMaxHeap(HeapQ A){
        A.heap_size=A.length;
        for(int i=A.length/2;i>0;i--){MaxHeapify(A,i);}
}
template<class T>
T HeapQ<T>::extract_Max(HeapQ A){
	T tmp=A[0];
	A[0]=A[A.heap_size];
	MaxHeapify(A,1);
	return tmp;
}
template<class T>
T HeapQ<T>::peek(){
	return arr[0];
}
template<class T>
void HeapQ<T>::insert(HeapQ A, int i){
	A.heap_size=A.heap_size+1;
	A[A.heap_size]=std::numeric_limits<int>::min();
}
template<class T>
void HeapQ<T>::increase_key(HeapQ A, int i, int k){
	if (k<A[i])
	{std::cout<<"New key is smalelr than old key!\n";
	return;}
	A[i]=k;
	while(i>1 && A[parent(i)]<A[i])
	{std::swap(A[i],A[parent(i)]);
	i=parent(i);
	}
}
