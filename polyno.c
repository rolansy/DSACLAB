#include <stdio.h>

struct poly{
	int e;
	int c;
};



void read(struct poly *p,int *n);
void display(struct poly *p,int n);
void sort(struct poly *p,int n);
int add(struct poly *p,struct poly *q,struct poly *r,int n,int m );

void read(struct poly *p,int *n){
	printf("Enter Number of Terms : ");
	scanf("%d",n);
	for(int i=0; i<*n;i++){
		printf("Enter Coefficient : ");
		scanf("%d",&p[i].c);
		printf("Enter Power x^ : ");
		scanf("%d",&p[i].e);
		}
}

void display(struct poly *p,int n){
	for(int i=0; i<n;i++){
		if (p[i].c==0){
			continue;
			}
		else if (p[i].e==0){
			printf("%d",p[i].c);
			}
		else {
			printf("%dx^%d",p[i].c,p[i].e);
			}
		if (i!=n-1){
			printf(" + ");	
			}
		}
}

void sortp(struct poly *p,int n){
	struct poly temp;
	for (int i=0;i<n-1;i++){
		for(int j=0; j<n-i-1;j++){
			if (p[j].e<p[j+1].e){
				temp=p[j];
				p[j]=p[j+1];
				p[j+1]=temp;
				}
			}
		}
}

int add(struct poly *p,struct poly *q,struct poly *r,int n,int m ){
	int i=0; int j=0; int k=0;
	while(i<n && j<m){
		if (p[i].e>q[j].e){
			r[k]=p[i];
			i++;k++;
			}
		else if (p[i].e<q[j].e){
			r[k]=q[j];
			j++;k++;
			}
		else {
			r[k].c=p[i].c+q[j].c;
			r[k].e=p[i].e;
			k++;i++;j++;
			}
		}
	while(i<n){
		r[k]=p[i];
		k++;i++;
		}
	while(j<m){
		r[k]=q[j];
		k++;j++;
		}
	return k;
}



void main(){
	struct poly p[100],q[100],r[200];
	int n;int m;int c;int k;int s=0;
	while(s==0){
	printf("1.Input Polynomials\n2. Display polyomial 1\n3. Display Polynomial 2\n4. Display Resultant Polynomial\n5. Exit\n");
	printf("Enter Choice : ");
	scanf("%d",&c);
	switch(c){
			case(1):
				read(p,&n);
				read(q,&m);
				break;
			case(2):
				printf("Polynomial 1 : ");
				sortp(p,n);
				display(p,n);
				printf("\n");
				break;
			case(3):
				printf("Polynomial 2 : ");
				sortp(q,m);
				display(q,m);
				printf("\n");
				break;
			case(4):
				sortp(p,n);
				sortp(q,m);
				k=add(p,q,r,n,m);
				printf("Resultant Polynomial : ");
				display(r,k);
				printf("\n");
				break;
			case(5):
				s=1;
				break;
				
		}
	}
}
