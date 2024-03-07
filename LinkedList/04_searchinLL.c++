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
int lengthLL(Node* head){
    Node* temp=head;
    int cnt=0;
     while(temp!=NULL){
        //cout<<temp->data<<" ";
        temp=temp->next;
        cnt+=1;
    }
    return cnt;
}
int search(Node* head,int key){
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==key){
            return 1;
        }
        temp=temp->next;
    }
    return -1;
}
int main(){
    vector<int>arr={100,2,5,5,6,9,5,89,7,5,8,7,76,6,7,8};
    // Node* y= new Node(arr[2],NULL);
    // cout<<y->data<<endl;
    int key ;
    cin>>key;
    Node* head= convertArray2LL(arr);
    
    int lengthOfLL=lengthLL(head);
    cout<<lengthOfLL<<endl;
    
    int searchel=search(head,key);
    cout<<searchel<<endl;
    return 0;
}
