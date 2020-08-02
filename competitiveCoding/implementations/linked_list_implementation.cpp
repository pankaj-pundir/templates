// implementation of linked lists with classes

#include<bits/stdc++.h>
using namespace std;

struct S // structure implementation
{	
	int data;
	S *prev, *next;
};


class linked_list // class implementation
{
public:
	// declaration of variables
	int data;
	linked_list *prev,*next;

	linked_list() { // defining the data values
		// this->data = data;
		this->prev = NULL;
		this->next = NULL;
	}

	~linked_list(); // initaillizing the destructor
};

linked_list::~linked_list(){ // destructor of the class
	cout<<"----  the list is deleted ------ \n";
}



void printInfoOfNode(linked_list node){
	cout<<" Data = "<<node.data;
	cout<<"\n prev = "<<node.prev;
	cout<<"\n next = "<<node.next;
}

linked_list *AddNode(linked_list *parentNode,int data){
	linked_list *child;
	child->data = data;
	while(parentNode->next != NULL) parentNode = parentNode->next;
	parentNode->next = child;
	return parentNode;
}

void printLinkedList(linked_list *root){
	cout<<"\n *********** Printing the list ******** \n";
	while(root->next!=NULL){
		cout<<root->data<<"\n";
		root = root->next;
	}
	cout<<root->data;
}

int main(){
	S a;
	linked_list *l;
	l->data = 90;
	// printInfoOfNode(l);
	int arr[] = {3};
	for(auto i: arr){
		cout<<i<<" in\n";
		l = AddNode(l,i);
	}

	cout<<"\n"<<sizeof(l)<<"\n";
	printLinkedList(l);

	return 0;
}