#include<stdio.h>

int ElemCount=0;
void displayQueue(int x,int y,int n,int Queue[n]){

	//printf("front:%d\nrear:%d\n",x,y);
	if(ElemCount==0){
		printf("Queue is empty\n");
	
	}
	else{
		printf("Queue is:");
		for(int i=x;i<=y;i++){
			printf("%d ",Queue[i]);
		}
		printf("\n");
	}
}


void main(){
	int n;
	printf("Enter size of Queue : ");
	scanf("%d",&n);
	
	int queue[n];
	int rear=-1,front=-1;
	
	int choice;
	printf("enter\n1.enqueue\n2.dequeue\n3.stop\n");
	scanf("%d",&choice);
	
	while(choice!=3){
		if(choice==1){
			if(rear==(n-1)){
				printf("Queue is full\n");
			}
			else{
				int x;
				printf("Enter Number to be Inserted : ");
				scanf("%d",&x);
				
				
				rear++;
				queue[rear]=x;
				if(front==-1){
					front++;
				}
				
				int i=rear;
				while(queue[i]>queue[i-1]&&i>=1){
					int temp=queue[i];
					queue[i]=queue[i-1];
					queue[i-1]=temp;
					i--;
				}
				ElemCount++;
				
			}
		}
		else if(choice==2){
			if(front==-1){
				printf("Queue is empty");
			}
			else if(front==(rear+1)){
				printf("Queue is empty");
			}
			else{
				ElemCount--;
				front++;
			}
		}
		if(choice!=3){
			displayQueue(front,rear,n,queue);
		}
		
		printf("\n1.enqueue\n2.dequeue\n3.stop\n");
		printf("Enter Choice : ");
		scanf("%d",&choice);
	
	}
}



