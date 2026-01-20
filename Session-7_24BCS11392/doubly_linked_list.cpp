#include<iostream>
using namespace std;
#include<vector>

class Node {
public:
    int data;
    Node* next;
    Node* prev;
    Node(int value) {
        data = value;
        next = NULL;
        prev = NULL;
    }
};

Node* convertarr2DLL(vector<int>& arr) {
    Node* head = new Node(arr[0]);
    Node* mover = head;
 for (int i = 1; i < arr.size(); i++) {
        Node* temp = new Node(arr[i]);
        temp->prev = mover;
        mover->next = temp;
        mover = temp;
    }
 return head;
}

void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << "<-";
        temp = temp->next;
    }
    cout << "NULL";
}



Node* insertAtHead(Node* head, int value) { //INSERT OPERATIONS
    Node* temp = new Node(value);
   if (head == NULL)
        return temp;

    temp->next = head;
    head->prev = temp;
    head = temp;
 return head;
}

Node* insertAtTail(Node* head, int value) {
    Node* temp = new Node(value);
    if (head == NULL)
        return temp;
    Node* mover = head;
    while (mover->next != NULL) {
        mover = mover->next;
    }   mover->next = temp;
    temp->prev = mover;

    return head;
}

Node* insertAtSpecificPosition(Node* head, int k, int value) {
    if (k == 1) {
        return insertAtHead(head, value);
    }
 Node* temp = head;
 int cnt = 1;
while (temp != NULL && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }
   if (temp == NULL) {
        cout << "Invalid position" << endl;
        return head;
    }

    Node* newNode = new Node(value);
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;

    return head;
}

Node* deletehead(Node* head) { //DELETE OPERATIONS
    Node* temp = head;
    head = head->next;
    head->prev = NULL;
    delete(temp);
    return head;
}

Node* deletetail(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;
    }
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->prev->next = NULL;
    temp->prev = NULL;
    delete(temp);
    return head;
}

Node* deleteatspecificposition(Node* head, int k) {
    if (head == NULL)
        return NULL;

    Node* temp = head;
    int cnt = 0;

    while (temp != NULL) {
        cnt++;
        if (cnt == k)
            break;
        temp = temp->next;
    }

    Node* back = temp->prev;
    Node* front = temp->next;

    if (back == NULL && front == NULL) {
        return NULL;
    }
    else if (back == NULL) {
        return deletehead(head);
    }
    else if (front == NULL) {
        return deletetail(head);
    }
    else {
        front->prev = temp->prev;
        back->next = temp->next;
        temp->next = NULL;
        temp->prev = NULL;
        delete(temp);
        return head;
    }
}
int main() {
    vector<int> arr = {23, 45, 65, 786, 655, 565};
    Node* head = convertarr2DLL(arr);

    cout << "Initial list:" << endl;
    display(head);
    cout << endl;
    head = insertAtHead(head, 10);
    head = insertAtTail(head, 999);
    head = insertAtSpecificPosition(head, 3, 50);
    cout << "\nAfter insert operations:" << endl;
    display(head);
    cout << endl;
    int k;
    cin >> k;
    head = deleteatspecificposition(head, k);
    cout << "\nAfter delete:" << endl;
    display(head);
    return 0;
}
