#include<stdio.h>
void linears();
void binarys();
void main(){
	int c,s=0;
	while(s==0){
		printf("1.Linear Search\n2.Binary Search\n3.Exit\n");
		printf("Enter Choice : ");
		scanf("%d",&c);
		switch(c){
			case(1):
				linears();
				break;
			case(2):
				binarys();
				break;
			case(3):
				s=1;
				break;
		}
}
}
void binarys(){
	int i,x,n,z[100],a=0,j,y,l=0,r,mid=0;
	printf("Enter the Number of Elements : ");
	scanf("%d",&n);
	printf("Enter the Elements : \n");
	for(i=0;i<n;i++){
		printf("Enter element %d : ",i+1);
		scanf("%d",&z[i]);
	}
	printf("Enter the element to be searched : ");
	scanf("%d",&x);
	for (i=0;i<n;i++){
		for(j=0;j<n;j++){
			if (z[j-1]>z[j]){
				y=z[j-1];
				z[j-1]=z[j];
				z[j]=y;
			}
		}
	}
	printf("Elements Sorted : ");
	for(i=0;i<n;i++){
		printf("%d, ",z[i]);
	}
	printf("\n");
	r=n;
	while(l<=r){
		mid=(r+l)/2;
		if (z[mid]==x){
			printf("Element found at Position %d\n",mid+1);
			a=1;
			break;
		}
		else if (z[mid]<x){
			l=mid+1;
		}
		else if (z[mid]>x){
			r=mid-1;
		}
	}
	if (a==0){
		printf("Element not Found\n");
		}
	
}

void linears(){
	int i,x,n,l[100],a=0;
	printf("Enter the Number of Elements : ");
	scanf("%d",&n);
	printf("Enter the Elements : \n");
	for(i=0;i<n;i++){
		printf("Enter element %d : ",i+1);
		scanf("%d",&l[i]);
	}
	printf("Enter the element to be searched : ");
	scanf("%d",&x);
	for(i=0;i<n;i++){
		if (l[i]==x){
			printf("Element found at Position %d\n",i+1);
			a=1;
			break;
			}
	if (a==0){
		printf("Element not Found\n");
		}
	}
}
