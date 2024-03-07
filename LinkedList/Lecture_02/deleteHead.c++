#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    //Constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }

     Node(int data ,Node* next){
        this->data=data;
        this->next=next;
    }


};

//Array -> LL

Node* convertArray2LL(vector<int>&arr){
    Node* head=new Node(arr[0]);
    Node* mover=head;
    for(int i=1;i<arr.size();i++){
        Node * temp=new  Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;

}
Node* deleteNode(Node* head){
    if(head==NULL){
        return head;
    }
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
void print(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}
int main(){
    vector<int>arr={1000,2,3,5,6,6,7,8};
    // Node* y= new Node(arr[2],NULL);
    // cout<<y->data<<endl;
    Node* head= convertArray2LL(arr);
    cout<<"Before deleting the haed"<<endl;
    print(head);
    head=deleteNode(head);
    cout<<"after deleting the node"<<endl;

    print(head);

    return 0;
}
