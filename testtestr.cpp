#include <bits/stdc++.h>
using namespace std;

template<typename elementType>
struct node
{
    elementType info;
    node<elementType>* next;
};

template<typename elementType>
class singleLinkedList
{
private:
    node<elementType>* head, * tail;
    int size;
public:
    singleLinkedList();
    void insertAtHead(elementType element);
    void insertAtTail(elementType element);
    void insertAt(elementType element, int index);
    void removeAtHead();
    void  removeAtTail();
    void removeAt(int index);
    elementType retrieveAt(int index);
    void replaceAt(elementType newElement, int index);
    bool isExist(elementType element);
    bool isItemAtEqual(elementType element, int index);
    void swap(int firstItemIdx, int secondItemIdx);
    bool isEmpty();
    int linkedListSize();
    void clear();
    void print();
    void combineNodesBetweenZeros();

    node<elementType>* gethead();
    void push(node<elementType>** head_ref, elementType new_data);
    void addToMerge(node<elementType>* arr[], int n);
    node<elementType>* merge(node<elementType>* firstNode, node<elementType>* secondNode);
    node<elementType>* mergeSort(node<elementType>* head);
    node<elementType>* middle(node<elementType>* head);
};
template<typename elementType>
singleLinkedList<elementType>::singleLinkedList()
{
    head = tail = NULL;
    size = 0;
}

template<typename elementType>
node<elementType>* singleLinkedList<elementType>::gethead()
{
    return this->head;
}

template<typename elementType>
void singleLinkedList<elementType>::insertAtHead(elementType element)
{
    node <elementType>* newNode = new node<elementType>;
    newNode->info = element;
    if (size == 0) {
        head = tail = newNode;
        newNode->next = NULL;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
    size++;
}

template<typename elementType>
void singleLinkedList<elementType>::insertAtTail(elementType element)
{
    node<elementType>* newNode = new node<elementType>;
    newNode->info = element;
    if (size == 0) {
        head = tail = newNode;
        newNode->next = NULL;
    }
    else {
        tail->next = newNode;
        newNode->next = NULL;
        tail = newNode;
    }
    size++;
}

template<typename elementType>
void singleLinkedList<elementType>::insertAt(elementType element, int index)
{
    if (index < 0 || index > size)
        cout << " Out of range" << endl;
    else
    {
        node<elementType>* newNode = new node<elementType>;
        newNode->info = element;
        if (index == 0) //insert at the begining
            insertAtHead(element);
        else if (index == size) //insert at the end;
            insertAtTail(element);
        else
        {
            node<elementType>* current = head;
            for (int i = 1; i < index; i++)
                current = current->next;

            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }
}

template<typename elementType>
void singleLinkedList<elementType>::removeAtHead()
{
    if (size == 0)
        cout << "EMPTY LIST" << endl;
    else if (size == 1)
    {
        delete head;
        tail = head = NULL;
        size--;
    }
    else
    {
        node<elementType>* current = head;
        head = head->next;
        delete current;
        size--;
    }
}

template<typename elementType>
void singleLinkedList<elementType>::removeAt(int index)
{
    if (index < 0 || index >= size)
        cout << "Out of range" << endl;
    else
    {
        node<elementType>* current, * trailCurrent;
        if (index == 0)
        {
            current = head;
            head = head->next;
            delete current;
            size--;
            if (size == 0)
                tail = NULL;
        }
        else
        {
            current = head->next;
            trailCurrent = head;
            for (int i = 1; i < index; i++)
            {
                trailCurrent = current;
                current = current->next;
            }

            trailCurrent->next = current->next;
            if (tail == current) //delete the last item
                tail = trailCurrent;
            delete current;
            size--;
        }
    }
}

template<typename elementType>
void singleLinkedList<elementType>::clear()
{
    node<elementType>* current;
    while (head != NULL)
    {
        current = head;
        head = head->next;
        delete current;
    }
    tail = NULL;
    size = 0;
}

template<typename elementType>
void singleLinkedList<elementType>::print()
{
    node<elementType>* current = head;
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->next;
    }cout << endl;
}

template<typename elementType>
int singleLinkedList<elementType>::linkedListSize()
{
    return size;
}

template<typename elementType>
bool singleLinkedList<elementType>::isEmpty()
{
    return (size == 0);
}

template<typename elementType>
bool singleLinkedList<elementType>::isExist(elementType element)
{
    node<elementType>* current = head;
    while (current != NULL)
    {
        if (current->info == element)
            return true;
        current = current->next;
    }
    return false;
}

template<typename elementType>
bool singleLinkedList<elementType>::isItemAtEqual(elementType element, int index)
{
    if (index < 0 || index > size) {
        return false;
    }
    node<elementType>* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->info == element;
}

template<typename elementType>
void singleLinkedList<elementType>::removeAtTail()
{
    if (size == 0)
        cout << "EMPTY LIST" << endl;
    else if (size == 1)
    {
        delete head;
        head = tail = NULL;
        size--;
    }
    else
    {
        node<elementType>* current = head->next;
        while (current->next != tail)
            current = current->next;
        delete tail;
        current->next = NULL;
        tail = current;
        size--;
    }
}

template<typename elementType>
elementType singleLinkedList<elementType>::retrieveAt(int index) {
    if (index <= 0 || index > size) {
        cout << "Index Out Of Range" << endl;
    }
    else {
        node<elementType>* current = head;
        int count = 0;
        while (current != NULL) {
            if (count == index) {
                return current->info;
            }count++;
            current = current->next;
        }
    }
}

template<typename elementType>
void singleLinkedList<elementType>::replaceAt(elementType newElement, int index) {
    node<elementType>* current;
    int count = 0;
    current = head;
    while (current != NULL) {
        if (count == index) {
            current->info = newElement;
            break;
        }
        else
            current = current->next;
        count++;
    }
}


template<typename elementType>
void singleLinkedList<elementType>::combineNodesBetweenZeros() {
    node<elementType>* current = this->head;
    int sum = 0, index = 0;
    while (current->next != NULL) {
        if (current->next->info == 0) {
            replaceAt(sum, index++);
            sum = 0;
        }
        else {
            sum += current->next->info;
        }current = current->next;
    }
    for (int i = index; i < size;) {
        removeAt(i);
    }
}

template<typename elementType>
void singleLinkedList<elementType>::swap(int firstIndex, int secondIndex) {
    if (firstIndex == secondIndex) return;
    node<elementType>* prevFirst = NULL;
    node<elementType>* currFirst = head;
    while (currFirst && currFirst->info != firstIndex) {
        prevFirst = currFirst;
        currFirst = currFirst->next;
    }
    node<elementType>* prevSecond = NULL;
    node<elementType>* currSecond = head;
    while (currSecond && currSecond->info != secondIndex) {
        prevSecond = currSecond;
        currSecond = currSecond->next;
    }
    if (currFirst == NULL || currSecond == NULL) return;
    if (prevFirst != NULL) prevFirst->next = currSecond;
    else head = currSecond;
    if (prevSecond != NULL) prevSecond->next = currFirst;
    else head = currFirst;
    node<elementType>* temp = currSecond->next;
    currSecond->next = currFirst->next;
    currFirst->next = temp;
}

template<typename elementType>
void singleLinkedList<elementType>::push(node<elementType>** head_ref, elementType new_data)
{

    node<elementType>* newNode = new node<elementType>();
    newNode->info = new_data;
    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

template<typename elementType>
void singleLinkedList<elementType>::addToMerge(node<elementType>* arr[], int n)
{
    node<elementType>* a = NULL;
    for (int i = 0; i < n; i++) {
        while (arr[i] != NULL) {
            push(&a, arr[i]->info);
            arr[i] = arr[i]->next;
        }
    }
    node<elementType>* curr = mergeSort(a);
    while (curr != NULL) {
        cout << curr->info << " ";
        curr = curr->next;
    }

}
template<typename elementType>
node<elementType>* singleLinkedList<elementType>::merge(node<elementType>* firstNode,node<elementType>* secondNode)
{
    node<elementType>* merged = new node<elementType>;
    node<elementType>* temp = new node<elementType>;
    merged = temp;
    while (firstNode != NULL && secondNode != NULL) {

        if (firstNode->info <= secondNode->info) {
            temp->next = firstNode;
            firstNode = firstNode->next;
        }
        else {
            temp->next = secondNode;
            secondNode = secondNode->next;
        }
        temp = temp->next;
    }

    while (firstNode != NULL) {
        temp->next = firstNode;
        firstNode = firstNode->next;
        temp = temp->next;
    }

    while (secondNode != NULL) {
        temp->next = secondNode;
        secondNode = secondNode->next;
        temp = temp->next;
    }
    return merged->next;
}

template<typename elementType>
node<elementType>* singleLinkedList<elementType>::middle(node<elementType>* head)
{
    node<elementType>* slow = head;
    node<elementType>* fast = head->next;

    while (!slow->next && (!fast && !fast->next)) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

template<typename elementType>
node<elementType>* singleLinkedList<elementType>::mergeSort(node<elementType>* head)
{
    if (head->next == NULL) {
        return head;
    }

    node<elementType>* mid = new node<elementType>();
    node<elementType>* head2 = new node<elementType>;
    mid = middle(head);
    head2 = mid->next;
    mid->next = NULL;

    node<elementType>* finalhead = merge(mergeSort(head),mergeSort(head2));
    return finalhead;
}




int main()
{
    cout << "-------------------- Single Linked List -----------------------" << endl;
    singleLinkedList<int>sll, sll2, sll3, sll4, sll5, sll6;
    sll.insertAtHead(10);
    sll.insertAtTail(20);
    sll.insertAtTail(90);
    sll.insertAt(30, 2);
    sll.print();
    sll.swap(1, 2);
    sll.print();
    sll.replaceAt(80, 1);
    cout << sll.retrieveAt(1) << endl;
    sll.print();
    sll.removeAt(2);
    sll.print();
    cout << sll.isItemAtEqual(80, 1) << endl;
    sll.isExist(30);
    sll.removeAtHead();
    sll.removeAt(1);
    sll.removeAtTail();
    cout << sll.isEmpty() << endl;
    sll.print();
    cout << sll.linkedListSize() << endl;
    sll.clear();

    cout << "------------------- Combine Nodes Between Zeros----------------------" << endl;
    sll2.insertAtTail(0);          //[0, 3, 1, 0, 4, 5, 2, 0]
    sll2.insertAtTail(3);
    sll2.insertAtTail(1);
    sll2.insertAtTail(0);
    sll2.insertAtTail(4);
    sll2.insertAtTail(5);
    sll2.insertAtTail(2);
    sll2.insertAtTail(0);
    sll2.print();
    sll2.combineNodesBetweenZeros();
    sll2.print();

    cout << "--------------------Merge K Sorted Linked Lists-----------------------" << endl;
    sll3.insertAtHead(1);
    sll3.insertAtTail(4);
    sll3.insertAtTail(5);
    sll4.insertAtHead(1);
    sll4.insertAtTail(3);
    sll4.insertAtTail(4);
    sll5.insertAtHead(2);
    sll5.insertAtTail(6);
    node<int>* arr[3] = { sll3.gethead(),sll4.gethead(),sll5.gethead() };
    sll6.addToMerge(arr, 3);

    return 0;
}
