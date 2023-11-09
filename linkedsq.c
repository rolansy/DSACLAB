#include <stdio.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *link;
};

struct node *top,*f,*r;

void spush(x){
	struct node *new=(struct node *)malloc(sizeof (struct node));
	new->data=x;
	new->link=NULL;
	if (top==NULL){
		top=new;
	}
	else{
		new->link=top;
		top=new;
	}
	sdisp();
}

void spop(){
	if (top==NULL){
		printf("\nStack is empty\n");
	}
	else{
		struct node *ptr;
		ptr=top;
		printf("\nPopped Element is : %d\n",top->data);
		top=top->link;
		free(ptr);
		sdisp();
	}
}

void sdisp(){
	struct node *ptr;
	if (top==NULL){
		printf("\nStack is empty\n");
	}
	else{
		ptr=top;
		printf("\nStack elements are : ");
		while(ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
	}
}

void enq(x){
	struct node *new=(struct node *)malloc(sizeof (struct node));
	new->data=x;
	new->link=NULL;
	if(f==NULL){
		f=new;
		r=new;
	}
	else{
		r->link=new;
		r=r->link;
	}
	qdisp();
}

void deq(){
	struct node *ptr;
	if (f==NULL){
		printf("Queue Empty\n");
	}
	else if (f->link==NULL){
		ptr=f;
		printf("Deleted Element : %d",f->data);
		f=NULL;
		r=NULL;
		free(ptr);
	}
	else{
		ptr=f;
		printf("Deleted Element : %d",f->data);
		f=ptr->link;
		free(ptr);
	}
	
}

void qdisp(){
	struct node *ptr;
	if (f==NULL){
		printf("Queue is Empty");
	}
	else{
		ptr=f;
		printf("Queue Elements are : ");
		while (ptr!=NULL){
			printf("%d ",ptr->data);
			ptr=ptr->link;
		}
	}
}


void queue(){
	int x,c=0;
	while(c!=4){
		printf("\n1.Enqueu\n2.Delete Queue\n3.Display Queue\n4.Exit from Queue\n");
		printf("Enter Choice : ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter Element to be Inserted : ");
				scanf("%d",&x);
				enq(x);
				break;
			case 2:
				deq();
				break;
			case 3:
				qdisp();
				break;
			case 4:
				break;
				
		}
	}	
}


void stack(){
	int x,c=0;
	while(c!=4){
		printf("\n1.Push\n2.Pop\n3.Display\n4.Exit From Stack\n");
		printf("Enter Choice : ");
		scanf("%d",&c);
		switch(c){
			case 1:
				printf("Enter Element to be Pushed : ");
				scanf("%d",&x);
				spush(x);
				break;
			case 2:
				spop();
				break;
			case 3:
				sdisp();
				break;
			case 4:
				break;
				
		}
	}	
}


void main(){
	int x,ch=0;
	while(ch!=3){
		printf("\n1.Stack\n2.Queue\n3.Exit\n");
		printf("Enter Choice : ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
				stack();
				break;
			case 2:
				queue();
				break;
			case 3:
				break;
		}
	}
}
