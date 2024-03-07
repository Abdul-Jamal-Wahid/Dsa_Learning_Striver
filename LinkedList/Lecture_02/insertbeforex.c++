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
Node* DeleteTail(Node* head){
   
    if(head==NULL|| head->next==NULL){
        return NULL;
    }
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    free(temp->next);
    temp->next=NULL;
    return head;
}

Node* removeElem(Node* head,int elem){
    if(head==NULL){
        return head;
    }
    if(head->data==elem){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){

        if(temp->data==elem){

            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
Node* inserHead(Node* head,int val){
    Node * temp=new Node(val,head);
    return temp;
}
void print(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
Node* insertLast(Node* head,int val){
    if(head==NULL){
        return new Node(val);
    }
    Node* temp=head;
    while (temp->next!=NULL){
        temp=temp->next;
    }
    Node* newNode=new Node(val);
    temp->next=newNode;
    return head;
}
Node* insertbeforeelem(Node* head,int el,int val){
    if(head==NULL){
        return NULL;
    }
    
    if(head->data==val){
        return new Node(el,head);
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
       // cnt+=1;

        if(temp->next->data==val){
            Node* x=new Node(el,temp->next);
           // x->next=temp->next;
            temp->next=x;
            break;
        }
        temp=temp->next;
    }
    return head;
}

int main(){
    vector<int>arr={1000,2,3,5,6,6,7,8};
 // deleting the h aed"<<endl;
    // print(head);
    // head=DeleteTail(head);
    // cout<<"after deleting the node"<<endl;

    // print(head);
    Node* head=convertArray2LL(arr);
    // head=removeElem(head,2);
    // print(head);
    // cout<<endl;
    // head=inserHead(head,5);
    // print(head);
    head=insertbeforeelem(head,88,8);
    print(head);
    return 0;
} 
