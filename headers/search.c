#include <stdlib.h>
#include "search.h"

int linear_search(const int* arr, const int* target, int size){
	for(int i = 0; i < size ; i++){
		if(arr[i] == *target){
			return i;
		}
	}
	return -1;
}

int binary_search(const int* arr, const int* target, int size){
	int left = 0;
	int right = size - 1;
	while(left <= right){
		int mid = left + (right - left)/2;
		if(arr[mid] == *target){
			return mid;
		}
		else if(arr[mid] < *target){
			left = mid + 1;
		}
		else{
			right = mid - 1;
		}
	}
	return -1;
}
