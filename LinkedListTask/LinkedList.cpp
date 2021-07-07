#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T data;
    Node* next;
};

//standard push function
template <typename T>
void push(Node<T>** headPtr, T newData) {
    Node<T>* newNode = new Node<T>();
    newNode->data = newData;
    newNode->next = (*headPtr);
    (*headPtr) = newNode;
}

template <typename T>
void printList(Node<T>* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

template <typename T>
Node<T>* sortedMerge(Node<T>* list1, Node<T>* list2) {
    Node<T>* result = NULL;

    if (list1 == NULL) {
        return list2;
    }
    else if (list2 == NULL) {
        return list1;
    }

    //comparing the data in two lists and choosing the least
    if (list1->data <= list2->data) {
        result = list1;
        result->next = sortedMerge(list1->next, list2);
    }
    else {
        result = list2;
        result->next = sortedMerge(list1, list2->next);
    }
    return result;
}

//split initial list into two parts using fast and slow pointer
template <typename T>
void splitList(Node<T>* head, Node<T>** firstPtr, Node<T>** secondPtr) {
    Node<T>* fast;
    Node<T>* slow;
    slow = head;
    fast = head->next;

    /*when fast pointer is at the end of the list,
        the slow pointer is at the middle of the list*/
    while (fast != NULL) {
        fast = fast->next;
        if (fast != NULL) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *firstPtr = head;
    *secondPtr = slow->next;
    slow->next = NULL;
}

//sorting the linked list
template <typename T>
void mergeSort(Node<T>** headPtr) {
    Node<T>* head = *headPtr;
    Node<T>* list1;
    Node<T>* list2;

    //empty list or list of 1 element
    if ((head == NULL) || (head->next == NULL)) {
        return;
    }

    //split initial list into 2 parts
    splitList(head, &list1, &list2);

    //sorting lists a and b
    mergeSort(&list1);
    mergeSort(&list2);

    //sorted list is a result of merging sorted parts
    *headPtr = sortedMerge(list1, list2);
}

int main() {
    Node<int>* linkedList = NULL;

    push(&linkedList, 5);
    push(&linkedList, 1);
    push(&linkedList, 19);
    push(&linkedList, 10);
    push(&linkedList, 12);
    push(&linkedList, 15);
    push(&linkedList, 23);
    push(&linkedList, 20);
    push(&linkedList, 3);
    push(&linkedList, 2);
    push(&linkedList, -7);
    push(&linkedList, 99);
    push(&linkedList, 0);
    push(&linkedList, -56);
    push(&linkedList, 38);


    cout << "unsorted list: " << endl;
    printList(linkedList);

    mergeSort(&linkedList);

    cout << "sorted list: " << endl;
    printList(linkedList);

    return 0;
}