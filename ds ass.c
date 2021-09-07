#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node*next;
	
};
struct node*createlinkedlist(int n);
struct node*middle_element (struct node*head);
void displaylist(struct node*head);
struct node*sorting(struct node *head);
struct node*reverse(struct node*head);
struct node*search(struct node*head ,int n);
struct node *insert_begin(struct node*head,int x);
void delete_Alt(struct node*head);
void middle(struct node*head);
void node_at_middle(struct node*head);
void swap(int n1, int n2,struct node*head);

 
   int main()
{
	int n=0;
	struct node* head=NULL;
	printf("enter node");
	scanf("%d",&n);
	head=createlinkedlist(n);
	sorting(head);
    head=reverse(head);
	search(head,7);
	displaylist(head);
	delete_Alt(head);
	 displaylist(head);
	middle(head);
node_at_middle(head);
  displaylist(head);
  swap(7, 5,head);
  displaylist(head);
  
	
   	
}
struct node*createlinkedlist(int n)
{
	
	int i=0;
	struct node*head=NULL;
	struct node*temp=NULL;
	struct node*ptr=NULL;
	for(i=0;i<n;i++)
	{
		temp=(struct node*)malloc(sizeof(struct node));
		printf("enter the data",i+1);
		scanf("%d",&(temp->data));
		temp->next=NULL;
		if(head==NULL)
		{
			head=temp;
		}
		else
		{
			ptr=head;
			while(ptr->next!=NULL)
				ptr=ptr->next;
				ptr->next=temp;
		}
			
		
	}
	return head;
}
void displaylist(struct node*head)
{
	struct node*ptr=head;
	while(ptr!=NULL)
	{
	
	 	printf("%d\t",ptr->data);
			ptr=ptr->next;
    }  
}
struct node*sorting(struct node *head)
	{
		struct node *i=head;
		struct node*j=NULL;
		int temp;
		for(i=head;i->next!=NULL;i=i->next)
		{
			for(j=i->next;j!=NULL;j=j->next)
			{
				if(i->data >
				j->data)
				{
					temp=i->data;
					i->data=j->data;
					j->data=temp;
				}
			}
		}
		return head;
	}
      struct node*reverse(struct node*head)
	
	{
		
		struct node*current = head;
		struct node *prev=NULL;
		struct node*next;
		while(current!=NULL)
		{
			next= current->next;
			current->next=prev;
			prev=current;
			current =next;
		}
		head=prev;
		return head;
		
		
	}
	struct node*search (struct node*head,int n)
	{
		
	struct node*temp1=head;
	int count=0;
	while(temp1!=NULL)
	  {
		count++;
		if(temp1->data==n)
		{
			printf("found :");
			printf("%d",count);
		}
		temp1=temp1->next;
       }
		return head;
		
		
		
	}
	
   void middle(struct node*head)
 {
 	struct node *slow=head;
 	struct node *fast=head;
 	if(head!=NULL)
 	{
 		
 		while(fast!=NULL&& fast->next!=NULL)
 		{
 			fast = fast->next->next;
 			slow =slow->next;
		 }
		 
		 printf("%d\n",slow->data);
	 }
	 
 	
 }
 
 
	void delete_Alt(struct node*head)
{
	if (head == NULL)
		return;

	struct node *t1 = head;
	struct node *t2 = head->next;

	while (t1!= NULL && t2 != NULL)
	{
		
		t1->next = t2->next;
    	free(t2);

		t1 = t1->next;
		if (t1 != NULL)
			t2 = t1->next;
	}

}
void node_at_middle(struct node*head)
{
	int l=0;
	struct node *p=head;
	while(p!=NULL)
	{
		p=p->next;
		l=l+1;
		
	}
	p=head;
	int c=0;
	while(c<l/2)
	{
		p=p->next;
		c=c+1;
	}
	printf("%d",p->data);
}

void swap(int n1, int n2,struct node*head){  
    struct node *prevnode1= NULL, *currentnode1=head,*temp=NULL;
    struct node *prevnode2= NULL,*currentnode2 =head;
    
      
    if(head == NULL) {  
        return;  
    }  
          
    
    if(n1 == n2)  
        return;  
      

    while(currentnode1 != NULL && currentnode1->data != n1){  
        prevnode1= currentnode1;  
        currentnode1= currentnode1->next;  
    }  
      
    while(currentnode2 != NULL && currentnode2->data != n2){  
        prevnode2 = currentnode2;  
        currentnode2 =currentnode2->next;  
    }  
      
    if(currentnode1 != NULL && currentnode2!= NULL) {  
          
        
        if(prevnode1!= NULL)  
            prevnode1->next = currentnode2;          
        else  
            head  = currentnode2;  
        if(prevnode2!= NULL)  
            prevnode2->next = currentnode1;  
        else  
            head  = currentnode1;  
          
        struct node*temp;
        temp = currentnode1->next;   
        currentnode1->next = currentnode2->next;   
        currentnode2->next = temp;       
    }      
    else{  
        printf("Swapping is not possible\n");  
    }  
}  





#include <stdio.h>
#include <stdlib.h>
struct node 
{
	int data;
	struct node *next;
	
	
};
struct node *head = NULL;
struct node *tail = NULL;

int count1()
{
	int count=0;
	node *temp=head;
	while(temp!=NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;
}

void create(int n)
{
	struct node *ptr = (node*) malloc(sizeof(node));
	ptr->data = n;
	ptr->next= NULL;
	
	if(head == NULL)
	{
		head= ptr;
		tail = ptr;
		
	}
	else
	{
		tail->next = ptr;
		tail=ptr;
	}
	
}
void display()
{
	
	if(head== NULL)
	{
		printf("empty list\n");
	}
	else
	{ 
	  struct  node *temp=head;
	   while(temp!=NULL)
	   {
		   printf("%d\n",temp->data);
		   
		   temp = temp->next;   
	   }
	}
}
void insert_front(int x)
{
		node *ptr = (node*) malloc(sizeof(node));
		ptr->data = x;
		ptr->next = head;
		head = ptr;
}
void insert_middle(int y)
{
		struct node *ptr = (node*) malloc(sizeof(node));
		ptr->data = y;
		ptr->next = NULL;
		
		int key = 20;
		node *temp = head;
		while(temp->data!=key)
		{
			temp = temp->next;
		}
		ptr->next = temp->next;
		temp->next = ptr;
}


void insert_end(int z)
{
	struct node*t3=(struct node*) malloc(sizeof(node));
	t3->data=z;
	t3->next=NULL;
	struct node*temp1=head;
	while(temp1->next!=NULL)
		{
			temp1 = temp1->next;
		}
		  temp1->next=t3;
	
	
	
}

  void  delete_front()
{
	struct node*newNode=head;
	head=head->next;
	free(newNode);
}
void delete_middle()
{
	int key=25;
	node *t1,*t2;
	t1=head;
	while(t1->data!=key)
	{
		t2=t1;
		t1=t1->next;
	}
	t2->next = t1->next;
	free(t1);
}
void delete_last()
{
	struct node *t1= head;
	while(t1->next!=tail)
	{
		t1 = t1->next;
		
	}
	t1->next = NULL;
	free(tail);
	tail=t1;
	
	
}
void distroy_all()
	{
		struct node*store;
		struct node*ptr=tail;
		while(tail!=NULL)
		
		{
			store=ptr;
			free(ptr);
			tail=store;
		}
		printf("elements distroy");
	}




int main()

{
	
	display();
	create(10);
	create(20);
	create(30);
	create(40);
	create(50);
	create(60);
	create(70);
	insert_front(5);
	insert_middle(25);
	insert_end(67);
	display();
	int count;
count= count1();
	printf("count = %d\n",count);
	distroy_all();
	delete_front();
	printf("after delete front\n");
	display();
	distroy_all();
	
	delete_middle();
	printf("after delete at middle\n");
	display();
	
	delete_last();
	printf("after delete last\n");
	display();
	
}







	
	

