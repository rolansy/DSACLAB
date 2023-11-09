//linear search
#include <stdio.h>
void main(){
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
