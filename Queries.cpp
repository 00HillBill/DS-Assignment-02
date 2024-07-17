#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int val;
    Node *next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};

void insert_head(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    newNode->next = head;
    head = newNode;
    if(tail == NULL){ 
        tail = newNode;
    }
}

void insert_at_tail(Node *&head, Node *&tail, int val){
    Node *newNode = new Node(val);
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    tail = newNode;
}

void delete_at_position(Node* &head, Node* &tail, int index){
    if(head == NULL){
        return; 
    }
    if(index == 0){
        Node* del_node = head;
        head = head->next;
        if (head == NULL){
            tail = NULL;
        }
        delete del_node;
        return;
    }
    Node* temp = head;
    for(int i = 1; i < index; i++){
        if(temp->next == NULL){
            return;
        }
        temp = temp->next;
    }
    if(temp->next == NULL){
        return;
    }
    Node* del_node = temp->next;
    temp->next = temp->next->next;
    if (temp->next == NULL){
        tail = temp;
    }
    delete del_node;
}

void print_linked_list(Node *head){
    Node *tmp = head;
    while(tmp != NULL){
        cout << tmp->val << " ";
        tmp = tmp->next;
    }
    cout << endl;
}

int main() {
    int Q;
    cin >> Q;

    int X, T;
    Node* head = NULL;
    Node* tail = NULL;

    while(Q--){
        cin >> X >> T;

        if(X == 0) {
            insert_head(head, tail, T);
        } 
        else if(X == 1){
            insert_at_tail(head, tail, T);
        } 
        else if(X == 2){
            delete_at_position(head, tail, T);
        }
        print_linked_list(head);
    }

    return 0;
}
