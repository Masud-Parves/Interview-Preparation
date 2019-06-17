#include<iostream>

using namespace std;


struct node{
    int roll;
    node *next;
};

node *root=NULL;

void append(int roll){
    if(root==NULL){
        root = new node();
        root->roll=roll;
        root->next=NULL;
    }else {
        node *current=root;

        while(current->next!=NULL){
            current=current->next;
        }

        node *newnode = new node();
        newnode->roll=roll;
        newnode->next=NULL;
        current->next=newnode;
    }
}

void add_node(int roll1, int roll2){
    node *current = root;
    node *nextNode = new node();
    while(current->roll!=roll1){
        current = current->next;
        nextNode = current->next;
    }

    node *newnode = new node();
    newnode->roll= roll2;
    newnode->next=nextNode;

    current->next=newnode;

}

void print(){

    node *current=root;
    while(current!=NULL){
        cout << current->roll << endl;
        current=current->next;
    }
}

void print2th(){
    node *current = root;

    int i=1;
    while(i!=3){
        current=current->next;
        i++;
    }

    cout << current->roll << endl;
}

void delete_node(int roll){
    node *current =  root;
    node *previous = new node();

    while(current->roll!=roll){
        previous=current;
        current = current->next;
    }

    if(current==root){
        node *tem=root;
        root=current->next;
        delete(tem);
    }else {
        previous->next=current->next;
        delete(current);
    }
}

int main(){

    append(1);
    append(1);
    append(6);
    append(0);
    append(5);
    add_node(6, 10);
    print();

    //delete_node(1);
    delete_node(0);
    cout << endl;
    cout << endl;
    cout << endl;

    print2th();
    return 0;
}
