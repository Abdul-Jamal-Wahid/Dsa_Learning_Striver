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

Node* deleteKth(Node* head,int k){
    if(head==NULL){
        return head;
    }
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt+=1;

        if(cnt==k){

            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}
void print(Node* head){
    Node* temp=head;

    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main(){
    vector<int>arr={1000,2,3,5,6,6,7,8};
 // deleting the haed"<<endl;
    // print(head);
    // head=DeleteTail(head);
    // cout<<"after deleting the node"<<endl;

    // print(head);
    Node* head=convertArray2LL(arr);
    head=deleteKth(head,5);
    print(head);
    return 0;
} 
