#include<iostream>

using namespace std;


struct node{
    int val;
    node *next;

};

node *root=NULL;

void Insert(int val){
    if(root==NULL){
        root = new node();
        root->val=val;
        root->next=NULL;
    }else {
        node *cur=root;
        while(cur->next!=NULL){
            cur=cur->next;
        }
        node *newNode=new node();
        newNode->val=val;
        newNode->next=NULL;
        cur->next=newNode;
    }
}

void RemoveDuplicate(){
    if(root==NULL) return;

    node *cur = root;

    while(cur->next!=NULL){
        if(cur->val==cur->next->val){
            node *nextNode = cur->next->next;
            delete(cur->next);
            cur->next=nextNode;
        }else {
            cur=cur->next;
        }

    }
}

void printList(){
    if(root==NULL) return;

    node *cur=root;

    while(cur->next!=NULL){
        cout << cur->val <<" ";
        cur = cur->next;
    }
}

int main(){

    cout << "Enter Number of Elements : " << endl;
    int n;
    cin >> n;
    cout << "Enter Elements : " << endl;
    for(int i=0 ; i<n ; i++){
        int x;
        cin >> x;
        Insert(x); /// insert value into linked list
    }

    RemoveDuplicate();
    printList();

    return 0;
}
