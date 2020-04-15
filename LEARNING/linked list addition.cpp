#include<iostream>
using namespace std;

// here we first add a new class name node: a node is nothing
//but a box 
class node{
    public:
        int data;
        node* next;


        //constructor
        node(int d){
            next = NULL;
            data = d;     
            }
};

void insertathead(node*head, int data){
    node*n = new node(data);
    n-> next = head;
    head = n;

}

void printlink(node*head){
    node* temp = head;

    while(temp!=NULL){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){

    node* head = NULL;
    insertathead(head,3);
    insertathead(head,4);
    insertathead(head,5);

    printlink(head);


    return 0;
}
