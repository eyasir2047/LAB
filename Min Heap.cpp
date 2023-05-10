
#include<iostream>
#include<climits> 
using namespace std;


void swap(int *x, int *y);


class MinHeap
{
	int *arr; 
	int capacity; 
	int size; 

public:
	
	MinHeap(int capacity);

	void MinHeapify(int );

	int parent(int i) { return (i-1)/2; }

	int left(int i) { return (2*i + 1); }

	int right(int i) { return (2*i + 2); }

	
	int extractMin();

	
	void decreaseKey(int i, int new_val);

	
	int getMin() { return arr[0]; }

	
	void deleteKey(int i);

	
	void insertKey(int k);
};


MinHeap::MinHeap(int cap)
{
	size = 0;
	capacity = cap;
	arr = new int[cap];
}


void MinHeap::insertKey(int k)
{
	if (size == capacity)
	{
		cout << "\nOverflow: Could not insertKey\n";
		return;
	}

	// First insert the new key at the end
	size++;
	int i = size - 1;
	arr[i] = k;

	
	while (i != 0 && arr[parent(i)] > arr[i])
	{
	swap(&arr[i], &arr[parent(i)]);
	i = parent(i);
	}
}


// new_val is smaller than arr[i].
void MinHeap::decreaseKey(int i, int new_val)
{
	arr[i] = new_val;
	while (i != 0 && arr[parent(i)] > arr[i])
	{
	swap(&arr[i], &arr[parent(i)]);
	i = parent(i);
	}
}


int MinHeap::extractMin()
{
	if (size <= 0)
		return INT_MAX;
	if (size == 1)//only one element
	{
		size--;
		return arr[0];
	}

	
	int root = arr[0];
	arr[0] = arr[size-1];
	size--;
	MinHeapify(0);

	return root;
}



void MinHeap::deleteKey(int i)
{
	decreaseKey(i, INT_MIN);
	extractMin();
}



void MinHeap::MinHeapify(int v)
{
	int l = left(v);
	int r = right(v);

	int smallest = v;
	if (l < size && arr[l] < arr[v])
		smallest = l;

	if (r < size && arr[r] < arr[smallest])
		smallest = r;

	if (smallest != v)
	{
		swap(&arr[v], &arr[smallest]);
		MinHeapify(smallest);
	}
}

// A utility function to swap two elements
void swap(int *x, int *y)
{
	int temp = *x;
	*x = *y;
	*y = temp;
}

// Driver program to test above functions
int main()
{
	MinHeap h(11);
	h.insertKey(3);
	h.insertKey(2);
	h.deleteKey(1);//delete 3 
	h.insertKey(15);
	h.insertKey(5);
	h.insertKey(4);
	h.insertKey(45);
	cout << h.extractMin() << " ";
	cout << h.getMin() << " ";
	h.decreaseKey(2, 1);
	cout << h.getMin();
	return 0;
}
