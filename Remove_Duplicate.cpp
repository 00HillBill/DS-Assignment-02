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

void remove_duplicates(Node* &head) {
    for (Node* i = head; i != NULL; i = i->next) {
        Node* prev = i;
        for (Node* j = i->next; j != NULL; ) {
            if (j->val == i->val) {
                Node* temp = j;
                prev->next = j->next;
                j = j->next;
                delete temp;
            } else {
                prev = j;
                j = j->next;
            }
        }
    }
}

void print_linked_list(Node *head)  
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
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

    remove_duplicates(head);
    print_linked_list(head);

   
}
