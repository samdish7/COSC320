//Sam Disharoon
//priorityQ.h
#ifndef PRIORITYQ_H
#define PRIORITYQ_H
template <class T>
class HeapQ {
	private:
	template <class U>
	struct Heapobj {
	T data;
	int key;
	};
	Heapobj<T>* arr;
	int length,heap_size;
	void increase_key(HeapQ,int,int);
	public:
	HeapQ(T*,int*,int);
	int parent(int);
	int left(int);
	int right(int);
	void MaxHeapify(HeapQ,int);
	void BuildMaxHeap(HeapQ);
	void printH(HeapQ);
	T extract_Max(HeapQ);
	T peek();
	void insert(HeapQ,int);

};
#include"priorityQ.cpp"
#endif
