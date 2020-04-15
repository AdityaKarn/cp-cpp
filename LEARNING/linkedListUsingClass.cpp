#include<iostream>

using namespace std;

struct node{
    int data;
    node* next;
};

class linkedListUsingClass
{
private:
    node *head, *tail;
public:

    linkedListUsingClass(){
        head= NULL;
        tail= NULL;
    };

    void createnode(int data){
        node* temp = new node;
        temp->data=data;
        temp->next=NULL;

        if(head==NULL){
            head=temp;
            tail=temp;
        }
        else{
            tail->next=temp;
            tail=temp;
        }
    }

    void insertAtStart(int data){
        node *temp= new node;
        temp->data=data;
        temp->next=head;
        head=temp;
    }

    void insertAtN(int data, int n){
        int i;
        node *temp=head;
        node *t=new node;
        t->data=data;
        while(temp!=NULL && i < n-1){
            temp= temp->next;
            i++;
        }
        t->next=temp->next;
        temp->next=t;
    }
    
    void printLL(){
        node *temp = head;

        while(temp!=NULL){
            cout<<temp->data<<"->";
            temp=temp->next;

            
        }

        cout<<endl;
    }

    void deleteLL(int key){

        node *current =new node;
        node *previous =new node;
        current = head;


        while(current!=NULL){

            if(key==current->data){
                previous->next = current->next;
            }
            previous = current;
            current = current->next;
        }


    }

    void deleteFirst(){
        node *temp = new node;
        temp=head;
        head = head->next;
        delete temp;
    }

    void deleteLast(){
    node *current =new node;
    node *previous =new node;
    current = head;


    while(current->next!=NULL){

        previous = current;
        current = current->next;
        }
        tail=previous;
        previous->next=NULL;
        delete current;
    }

    void reverseUsingIterative(){
        node *n = new node;                              // prev     curr    n
        node *current =new node;
        node *previous =new node;
        current=head;
        previous=NULL;
        

        while(current!=NULL){
            n=current->next;
            current->next = previous;
            previous=current;
            current=n;

        }
        head=previous;
    }

};


int main(){

    linkedListUsingClass l;
    l.createnode(5);
    l.createnode(4);
    l.createnode(3);
    l.createnode(6);
    l.insertAtStart(1);
    l.insertAtN(8,2);
    l.printLL();

    l.reverseUsingIterative();
    l.printLL();
   
    l.deleteLL(8);
    l.printLL();

    l.deleteFirst();
    l.printLL();
    l.deleteLast();
    l.printLL();
}