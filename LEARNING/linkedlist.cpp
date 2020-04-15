#include <iostream>

using namespace std;

struct node{
	node* next;
	int data;
};

struct node* head;

int addtofirst(int data){
	node* temp = new node;
	temp->data = data;
	temp->next=head;
	head= temp;
	return 0;
}

void printLL(node* &head){
	node *temp = head;

	while(temp!=NULL){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
}

int addToN(int data,int n){
	int i=0;
	node* temp1 = head;
	node* temp2 = new node;

	temp2->data = data;
	temp2->next = NULL;


	while(temp1->next!=NULL && i<n-1){
		temp1= temp1->next;
		i++;
	}

	temp2->next = temp1->next;
	temp1->next=temp2;
	return 0;

}


int main(){
	head=NULL;

	addtofirst(5);
	addtofirst(3);
	addtofirst(4);
	addToN(1,2);
	addToN(7,3);

	printLL(head);




	return 0;
}