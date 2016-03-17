#include "mergesort.h"

void MergeSort::merge(int A[], int left[], int right[], int size)
{
	int mid = size / 2;
	int left_size = mid;
	int right_size = size - mid;

	// Iterators for each array
	// i tracks the index of the left array
	// j tracks the index of the right array
	// k tracks the index of the main array
	int i = 0, j = 0, k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] < right[j])
		{
			A[k] = left[i];
			i++;
			k++;
		}
		else
		{
			A[k] = right[j];
			j++;
			k++;
		}
	}
	
	while (i < left_size)
	{
		A[k] = left[i];
		i++;
		k++;
	}
	
	while (j < right_size)
	{
		A[k] = right[j];
		j++;
		k++;
	}
}

void MergeSort::mergeSort(int A[], int size)
{
	// Base case is when we have reached one element in the array
	if (size < 2) return;

	int mid = size / 2;
	int *left = new int[mid];
	int *right = new int[size - mid];

	for (int i = 0; i < mid; i++)
	{
		left[i] = A[i];
	}

	for (int j = 0; j < size - mid; j++)
	{
		right[j] = A[mid + j];
	}

	mergeSort(left, mid);
	mergeSort(right, size - mid);
	merge(A, left, right, size);

	delete[] left;
	delete[] right;
}
