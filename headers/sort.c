#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int defaultCmp(int a, int b)
{
	return a > b;
}

//--------------------Swap Function-----------------------------

void swap(int *arr, int i, int j)
{
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

//--------------------Inserion Sort-----------------------------


void insertion_sort(int *arr, int n, int(*cmp)(int, int))
{
	if(cmp == NULL) cmp = defaultCmp;
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;

		while(j >= 0 && cmp(arr[j], key))
		{
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}

//--------------------Selection Sort----------------------------

void selection_sort(int *arr, int n, int(*cmp)(int, int))
{
	if(cmp == NULL) cmp = defaultCmp;
	for(int i = 0; i < n; i++)
	{
		int min = i;
		for(int j = i+1; j < n; j++)
		{
			if(cmp(arr[min], arr[j])) min = j;
		}
		swap(arr, i, min);
	}
}

//--------------------Bubble Sort-------------------------------

void bubble_sort(int *arr, int n, int(*cmp)(int, int))
{
	if(cmp == NULL) cmp = defaultCmp;
	for(int i = 0; i < n - 1; i++)
	{
		bool f = false;
		for(int j = 0; j < n - i - 1; j++)
		{
			if(cmp(arr[j], arr[j+1]))
			{
				swap(arr, j, j+1);
				f = true;
			}
		}
		if(f == false) break;
	}
}

//--------------------Merge Sort--------------------------------

void merge(int arr[], int aux[], int left, int mid, int right, int(*cmp)(int, int))
{
	for (int k = left; k <= right; k++) aux[k] = arr[k];

	int i = left;
	int j = mid + 1;

	for (int k = left; k <= right; k++) 
	{
		if (i > mid) arr[k] = aux[j++];
		else if (j > right) arr[k] = aux[i++];
		else if (cmp(aux[j], aux[i])) arr[k] = aux[i++];
		else arr[k] = aux[j++];
	}
}

void merge_sort_recursive(int arr[], int aux[], int left, int right, int(*cmp)(int, int))
{
	if (left >= right) return;

	int mid = (left + right) / 2;
	merge_sort_recursive(arr, aux, left, mid, cmp);
	merge_sort_recursive(arr, aux, mid + 1, right, cmp);
	merge(arr, aux, left, mid, right, cmp);
}

void merge_sort(int *arr, int n, int(*cmp)(int, int))
{
	if(cmp == NULL) cmp = defaultCmp;
	int *aux = (int *) malloc(n * sizeof(int));
	int left = 0;
	int right = n-1;

	merge_sort_recursive(arr, aux, left, right, cmp);
	free(aux);
}

//--------------------Quick Sort--------------------------------

void quick_sort_recursive(int arr[], int left, int right, int(*cmp)(int, int))
{
	if (left >= right) return;

	int pivot = arr[left];
	int i = left + 1;

	for (int j = left + 1; j < right; j++) if (cmp(pivot, arr[j])) swap(arr, i++, j);

	swap(arr, left, --i);
	quick_sort_recursive(arr, left, i - 1, cmp);
	quick_sort_recursive(arr, i + 1, right, cmp);
}

void quick_sort(int arr[], int n, int(*cmp)(int, int))
{
	if(cmp == NULL) cmp = defaultCmp;
	quick_sort_recursive(arr, 0, n, cmp);
}
