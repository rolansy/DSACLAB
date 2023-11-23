#include<stdio.h>

#define MAX_SIZE 4

typedef struct cq {
    int queue[MAX_SIZE];
    int front, rear;
} cq;

typedef struct PrioElm{
	int data;
	int prio;
}PrioElm;

typedef struct pq {
    PrioElm queue[MAX_SIZE];
    int size;
} pq;

void initPriorityQueue(pq *pq) {
    pq->size = 0;
}

int isPriorityQueueEmpty(const pq *pq) {
    return pq->size == 0;
}

int isPriorityQueueFull(const pq *pq) {
    return pq->size == MAX_SIZE;
}

void enqueuePriorityQueue(pq *pq, PrioElm item) {
    if (isPriorityQueueFull(pq)) {
        printf("Priority queue is full. Cannot enqueue.\n");
    } else {
        int i = pq->size - 1;
        while (i >= 0 && item.prio < pq->queue[i].prio) {
            pq->queue[i + 1] = pq->queue[i];
            i--;
        }
        pq->queue[i + 1] = item;
        pq->size++;
        printf("%d enqueued successfully.\n", item.data);
    }
}

void dequeuePriorityQueue(pq *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued successfully.\n", pq->queue[0].data);
        for (int i = 1; i < pq->size; i++) {
            pq->queue[i - 1].data = pq->queue[i].data;
        }
        pq->size--;
    }
}

void displayPriorityQueue(const pq *pq) {
    if (isPriorityQueueEmpty(pq)) {
        printf("Priority queue is empty.\n");
    } else {
        printf("Priority queue elements : ");
        for (int i = 0; i < pq->size; i++) {
        		printf("\n");
            	printf("%d [%d]", pq->queue[i].data, pq->queue[i].prio);
            
        }
        printf("\n");
    }
}

void prioq(){
    int cchoice;
    pq priorityQueue;
    initPriorityQueue(&priorityQueue);
    PrioElm elm;
    while(cchoice!=4){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d",&cchoice);
        switch(cchoice){
            case 1: printf("Enter element to insert : ");
                    scanf("%d", &elm.data);
                    printf("Enter Priority of element : ");
                    scanf("%d", &elm.prio);
                    enqueuePriorityQueue(&priorityQueue, elm);
                    break;
            case 2: dequeuePriorityQueue(&priorityQueue);
                    break;
            case 3: displayPriorityQueue(&priorityQueue);
                    break;
            case 4: break;
        }
    }
    
}

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

void initCircularQueue(cq *cq) {
    cq->front = cq->rear = -1;
}

int isCircularQueueEmpty(const cq *cq) {
    return cq->front == -1 && cq->rear == -1;
}

int isCircularQueueFull(const cq *cq) {
    return (cq->rear + 1) % MAX_SIZE == cq->front;
}

void enqueueCircularQueue(cq *cq, int item) {
    if (isCircularQueueFull(cq)) {
        printf("Queue is full. Cannot enqueue.\n");
    } else {
        if (isCircularQueueEmpty(cq)) {
            cq->front = cq->rear = 0;
        } else {
            cq->rear = (cq->rear + 1) % MAX_SIZE;
        }
        cq->queue[cq->rear] = item;
        printf("%d enqueued\n", item);
    }
}

void dequeueCircularQueue(cq *cq) {
    if (isCircularQueueEmpty(cq)) {
        printf("Queue is empty. Cannot dequeue.\n");
    } else {
        printf("%d dequeued\n", cq->queue[cq->front]);
        if (cq->front == cq->rear) {
            cq->front = cq->rear = -1;
        } else {
            cq->front = (cq->front + 1) % MAX_SIZE;
        }
    }
}

void displayCircularQueue(const cq *cq) {
    if (isCircularQueueEmpty(cq)) {
        printf("Queue is empty.\n");
    } else {
        int i = cq->front;
        printf("Queue elements: ");
        do {
            printf("%d ", cq->queue[i]);
            i = (i + 1) % MAX_SIZE;
        } while (i != (cq->rear + 1) % MAX_SIZE);
        printf("\n");
    }
}

void circq(){
    cq circularQueue;
    initCircularQueue(&circularQueue);
    int pchoice,item;
    while(pchoice!=4){
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit.\n");
        scanf("%d", &pchoice);
        switch(pchoice){
            case 1: printf("Enter Element : ");
                    scanf("%d", &item);
                    enqueueCircularQueue(&circularQueue, item);
                    displayCircularQueue(&circularQueue);
                    break;
            case 2: dequeueCircularQueue(&circularQueue);
            		displayCircularQueue(&circularQueue);
                    break;
            case 3: displayCircularQueue(&circularQueue);
                    break;
            case 4: break;
        }
    }
}

int main() {
    int choice;
    while(choice !=3){
        printf("\n1.Circular Queue\n2.Priority Queue\n3.Exit\n");
        printf("Enter Choice : ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                circq();
                break;
            case 2:
                prioq();
                break;
            case 3:
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}



