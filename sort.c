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

void merges(int arr[], int low, int high){
	if(low<high){
		int mid=low+(high-low)/2;
		merges(arr,low,mid);
		merges(arr,mid+1,high);
		merge(arr,low,mid,high);
	}
}

void merge(int arr[],int low,int mid,int high){
	int n1=mid-low+1;
	int n2=high-mid;
	
	int L[n1],R[n2];
	
	for (int i=0;i<n1;i++){
		L[i]=arr[low+i];
	{
	for(int j=0;j<n2;j++){
		R[j]=arr[mid+1+j]
	}
	
	int i=0, j=0, k=low;
	while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}


