#include <stdio.h>

void quicks(int arr[],int low, int high){
	if(low<high){
		int part=partition(arr,low,high);
		
		quicks(arr,low,part-1);
		quicks(arr,low+1,part);
	}
	
}

void partition(int arr[],int low,int high){
	int p=arr[high];
	int i=low-1;
	
	for(int j=low;j<=high-1;j++){
		if(arr[j]<p){
			i++;
			swap(&arr[i],&arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void swap(int* a,int* b){
	int temp=*a;
	*a=*b;
	*b=temp;
}

void merges()


