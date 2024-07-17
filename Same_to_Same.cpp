#include<bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};
void insert_tail(Node *&head, Node *&tail, int val)
{
    Node *newNode = new Node(val);    
    if (head == NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int main(){
    Node* head1= NULL;
    Node* tail1= NULL;
    int val1, count=0, flag=0;
    while(true){
        cin>>val1;
        if(val1==-1)
            break;
        insert_tail(head1, tail1 , val1);
    }
    Node* head2= NULL;
    Node* tail2= NULL;
    int val2;
    while(true){
        cin>>val2;
        if(val2==-1)
            break;
        insert_tail(head2, tail2 , val2);
    }
   
    Node* temp1 =head1;
    Node* temp2 =head2;
    bool result =true;

    while(temp1 != NULL && temp2 != NULL){
        if(temp1->val != temp2->val){
            result=false;
            break;
        }
        temp1 =temp1->next;
        temp2 =temp2->next;
    }

    if(temp1 != NULL||temp2 != NULL) {
        result=false;
    }

    if(result)
        cout<<"YES"<<endl;
    else
        cout<<"NO"<<endl;
}