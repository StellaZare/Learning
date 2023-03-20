#include <iostream>
struct Node{
    int value;
    Node* next;

    Node() : value(0), next(nullptr) {}
    Node(int v) : value(v), next(nullptr) {}
    Node(int v, Node* p) : value(v), next(p) {}
};

void printList(struct Node* list){
    Node* curr = list;
    std::cout << "List: ";
    while(curr != nullptr){
        std::cout << curr->value << " ";
        curr = curr->next;
    }
    std::cout << "\n";
}

struct Node* addToEnd(Node* list, int v){
    if(list == nullptr){
        return new Node(v);
    }

    Node* curr = list;
    while(curr->next != nullptr){
        curr = curr->next;
    }
    curr->next = new Node(v);
    return list;
}

struct Node* mergeTwoLists(Node* list1, Node* list2){
    Node* ptr1 = list1;
    Node* ptr2 = list2;
    Node* mergedList = nullptr;

    while(ptr1 != nullptr && ptr2 != nullptr){
        if(ptr1->value < ptr2->value){
            mergedList = addToEnd(mergedList, ptr1->value);
            ptr1 = ptr1->next;
        }else{
            mergedList = addToEnd(mergedList, ptr2->value);
            ptr2 = ptr2->next;
        }
    }
    
    while(ptr1 != nullptr){
        mergedList = addToEnd(mergedList, ptr1->value);
        ptr1 = ptr1->next;
    }
    while(ptr2 != nullptr){
        mergedList = addToEnd(mergedList, ptr2->value);
        ptr2 = ptr2->next;
    }
    return mergedList;
}

int main() {
    //method #1
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(5);
    node1->next = node2;
    node2->next = node3;

    Node* list1 = node1;
    
    //mothod #2
    Node* list2 = nullptr;
    list2 = addToEnd(list2, 1);
    list2 = addToEnd(list2, 3);
    list2 = addToEnd(list2, 4);
    list2 = addToEnd(list2, 6);

    Node* mergedList = mergeTwoLists(list1, list2);

    std::cout << "Regular \n";
    printList(list1);
    printList(list2);
    std::cout << "Merged \n";
    printList(mergedList);

    return 0;
}