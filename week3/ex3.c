#include<stdio.h> 
#include<stdlib.h> 

// Linked list node
typedef struct node 
{ 
	int data; 
	struct node* next; 
} Node; 

typedef Node* LinkedList;

// Create a new linked list with one element
LinkedList new_list(int data)
{
	LinkedList node = malloc(sizeof(Node));
    node->data  = data;
    node->next = NULL;
    return node;
}

// Print a linked list
void print_list(LinkedList head) 
{ 
	while(head != NULL) 
	{ 
		printf("%d ", head->data); 
		head = head->next; 
	} 
	printf("\n");
} 

// Insert a node at the beginging of the linked list
void insert_node_at_start(LinkedList *head, int data) 
{
    LinkedList node = malloc(sizeof(Node));
    node->data  = data;
    node->next = *head;

    *head = node;
}

// Insert a node at the end of the linked list
void insert_node_at_end(LinkedList *head, int data) 
{
	LinkedList node = malloc(sizeof(Node));
    node->data  = data;
    node->next = NULL;

	LinkedList l = *head;

	if(l == NULL)
	{
		*head = node;
	}
	else
	{
		while (l->next != NULL) l = l->next;
    	l->next = node;
	}
}

// Insert a node at the index of the linked list
int insert_node(LinkedList *head, int data, int indx) 
{
	if(indx == 0)
	{
		insert_node_at_start(head, data);
		return 1;
	}

	LinkedList l = *head;
	LinkedList pl = NULL;

	for (int i = 0; i < indx; ++i)
	{
		if(l == NULL) return 0;
		pl = l;
		l = l->next;
	}

	if(l == NULL) 
	{
		insert_node_at_end(head, data);
		return 1;
	}

    Node* node = malloc(sizeof(Node));
    node->data  = data;
    node->next = l;

    pl->next = node;
    return 1;
}

// Delete the node at the index
int delete_node(LinkedList *head, int indx) 
{ 
	if (head == NULL) return 1; 
  
    LinkedList l = *head; 
  
    if (indx == 0)
    {
    	*head = l->next;   
    	free(l);
    	return 1; 
    } 
  
    for (int i = 0; l != NULL && i < indx - 1; ++i) l = l->next; 
    if (l == NULL || l->next == NULL) return 0; 
  
    LinkedList n = l->next->next; 
    free(l->next);   
    l->next = n;  
} 

int main(int argc, char const *argv[])
{
	LinkedList ll = new_list(1);

	insert_node_at_end(&ll, 2);
	insert_node_at_end(&ll, 9);
	insert_node(&ll, 3, 0);
	insert_node(&ll, 4, 1);
	insert_node(&ll, 5, 3);

	if(!insert_node(&ll, 12, 100)) printf("Can't insert\n");

	print_list(ll);

	delete_node(&ll, 3);
	delete_node(&ll, 0);
	delete_node(&ll, 0);
	delete_node(&ll, 0);
	delete_node(&ll, 0);
	delete_node(&ll, 0);

	print_list(ll);	

	insert_node_at_end(&ll, 2);
	insert_node(&ll, 0, 0);

	print_list(ll);
	return 0;
}
