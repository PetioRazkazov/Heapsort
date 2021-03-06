#include "stdafx.h"
#include <iostream>
#include <algorithm>

using namespace std;

void heapify(int arr[], int size, int root)
{
	int largest = root; //we take root as the biggest
	int l = 2 * root + 1;
	int r = 2 * root + 2;
	//If left child is bigger than root
	if (l < size && arr[l] > arr[largest])
	{
		largest = l;
	}
	//If right child is bigger than largest
	if (r <size && arr[r] > arr[largest])
	{
		largest = r;
	}
	//We place the largest element at the top(root) if root isn't the biggest element
	if (largest != root)
	{
		swap(arr[root], arr[largest]);
		//recursion to heapify the subtree
		heapify(arr, size, largest);
	}
}

void HeapSort(int arr[], int size)
{
	for (int i = size / 2 - 1; i >= 0; i--)
	{
		//Build Heap
		heapify(arr, size, i);
	}
	//Extraction of elements from Heap
	for (int i = size - 1; i >= 0; i--)
	{
		swap(arr[0], arr[i]); // moves current root to end
		heapify(arr, i, 0);
	}
}

void printArr(int arr[],int size) // Prints Array
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
}

int main()
{
	//An Example
	int arr[] = { 14,13,45,3,9,10 };
	HeapSort(arr, 6);
	printArr(arr,6);
    return 0;
}

