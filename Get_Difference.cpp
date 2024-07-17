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

void insert_at_tail(Node* &head, Node* &tail, int val){
    Node* newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

int difference(Node* head){
    int minVal = INT_MAX;
    int maxVal = INT_MIN;

    Node* temp = head;
    while(temp != NULL){
        if(temp->val < minVal){
            minVal = temp->val;
        }
        if(temp->val > maxVal){
            maxVal = temp->val;
        }
        temp = temp->next;
    }

    int diff = maxVal - minVal;
    return diff;
}

int main(){
    int x;
    Node* head = NULL;
    Node* tail = NULL;
    while(true){
        cin >> x;
        if(x == -1){
            break;
        }
        insert_at_tail(head, tail, x);
    }
    
    int diff = difference(head);
    cout << diff << endl;

    return 0;
}
