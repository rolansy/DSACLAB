#include <stdio.h>
#include <stdlib.h>

int q[20],n,f,r;

void insert(int x){
    r=(r+1)%n;
    if (r==f)
    {
        printf("Queue is full\n");
    }
    else if(r==-1){
        f=0;
        r=0;
        q[r]=x;
    }
    else{
        q[r]=x;
    }
}

void delete(int x){
    if (f==-1){
        printf("Queue is empty\n");
    }
    else if (f==r)
    {
        x=q[f];
        f=-1;
        r=-1;
    }
    else{
        x=q[f];
        f=(f+1)%n;
    }
}

void display(){
    int i;
    if (f==-1)
    {
        printf("Queue is empty\n");
    }
    else if (f<=r){
        for(i=f;i<=r;i++){
            printf("%d",q[i]);
        }
    }
    else{
        for(i=f;i<n;i++){
            printf("%d",q[i]);
        }
        for (i=0;i<=r;i++){
            printf("%d",q[i]);
        }
    }
}

void main (){
    int ch,x;
    printf("Enter the size of the queue\n");
    scanf("%d",&n);
    f=-1;
    r=-1;
    while(1){
        printf("Enter your choice\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&ch);
        switch(ch){
            case 1:printf("Enter the element to be inserted\n");
                    scanf("%d",&x);
                    insert(x);
                    r++;
                    break;
            case 2:delete(x);
                    break;
                    f++;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
            default:printf("Invalid choice\n");
        }
    }
}


