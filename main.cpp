#include <iostream>
using namespace std;
template<typename elementType>
struct node
{
    elementType info;
    node<elementType> *next;
};
template<typename elementType>
class singleLinkedList
{
private:
    node<elementType> *head, *tail;
    int size;
public:
    singleLinkedList();
    void insertAtHead(elementType element);
    void insertAtTail (elementType element);
    void insertAt (elementType element, int index) ;
    void removeAtHead ();
    void removeAt (int index);
    void clear ();
    void print();
    int linkedListSize ();
    bool isEmpty();
    bool isExist (elementType element);
    bool isItemAtEqual (elementType element, int index);
    void  removeAtTail ();
    elementType retrieveAt (int index);
    void replaceAt (elementType newElement, int index);
    ~singleLinkedList();
    void combineNodesBetweenZeros();
    void swapl(int firstItemIdx, int secondItemIdx);
    singleLinkedList<elementType> addTreeListsInOne(singleLinkedList<elementType> list1, singleLinkedList<elementType> list2, singleLinkedList<elementType> list3);
    singleLinkedList<elementType>  mergeSortedLinkedLists();
    bool sorted();
    //singleLinkedList<elementType> mergeSortedLinkedLists(singleLinkedList<elementType>(arr2));
    //node<elementType>* mergeKLists(node<elementType>* arr[], int last);
    //node<elementType>* SortedMerge(node<elementType>* a, node<elementType>* b);

};
template<typename elementType>
singleLinkedList<elementType>:: singleLinkedList()
{
    head= tail = NULL;
    size = 0;
}

template<typename elementType>
void singleLinkedList<elementType>:: insertAtHead(elementType element)
{
    node <elementType> *newNode = new node<elementType>;
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
void singleLinkedList<elementType>:: insertAtTail (elementType element)
{
    node<elementType> *newNode = new node<elementType>;
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
            node<elementType> *newNode = new node<elementType>;
            newNode->info = element;
            if (index == 0) //insert at the begining
                insertAtHead(element);
            else if (index == size) //insert at the end;
                insertAtTail(element);
            else
            {
                node<elementType> *current = head;
                for (int i = 1; i < index; i++)
                    current = current->next;

                newNode->next = current->next;
                current->next = newNode;
                size++;
            }
        }
    }

template<typename elementType>
void singleLinkedList<elementType>:: removeAtHead ()
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
            node<elementType> *current = head;
            head = head->next;
            delete current;
            size--;
        }
}

template<typename elementType>
void singleLinkedList<elementType>::removeAt (int index)
{
    if (index < 0 || index >= size)
        cout << "Out of range" << endl;
    else
    {
        node<elementType> *current, *trailCurrent;
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
void singleLinkedList<elementType>::clear ()
{
    node<elementType>*current;
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
    node<elementType> *current = head;
    while (current != NULL)
    {
        cout << current->info << " ";
        current = current->next;
    }cout<<endl;
}

template<typename elementType>
int singleLinkedList<elementType>:: linkedListSize ()
{
    return size;
}

template<typename elementType>
bool singleLinkedList<elementType>::isEmpty()
{
    return (size == 0);
}

template<typename elementType>
bool singleLinkedList<elementType>::isExist (elementType element)
{
    node<elementType> *current = head;
    while (current != NULL)
    {
        if (current->info == element)
            return true;
        current = current->next;
    }
    return false;
}

template<typename elementType>
bool singleLinkedList<elementType>:: isItemAtEqual (elementType element, int index)
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
void singleLinkedList<elementType>:: removeAtTail ()
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
        node<elementType> *current = head->next;
        while (current->next != tail)
            current = current->next;
        delete tail;
        current->next = NULL;
        tail = current;
        size--;
    }
}

template<typename elementType>
elementType singleLinkedList<elementType>:: retrieveAt (int index){
    if(index<=0 || index>size){
        cout<<"Index Out Of Range"<<endl;
    }else{
        node<elementType> *current=head;
        int count =0 ;
        while (current!=NULL){
            if(count == index){
                return current->info;
            }count++;
            current =current->next;
        }
    }
}

template<typename elementType>
void singleLinkedList<elementType>::replaceAt (elementType newElement, int index){
    node<elementType> *current;
    int count=0;
    current =head;
    while (current!=NULL){
        if(count ==index){
            current->info =newElement;
            break;
        } else
            current=current ->next;
        count++;
    }
}

template<typename elementType>
singleLinkedList<elementType>::~singleLinkedList()
{
    clear ();
}

template<typename elementType>
void singleLinkedList<elementType>::combineNodesBetweenZeros() {
    node<elementType>* current =this-> head;
    int sum=0,index=0;
    while (current->next!=NULL){
        if(current->next->info==0){
            replaceAt(sum,index++);
            sum=0;
        }else{
            sum+=current->next->info;
        }current=current->next;
    }
    for(int i=index;i<size;){
        removeAt(i);
    }
}

template<typename elementType>
void singleLinkedList<elementType>::swapl(int firstItemIdx, int secondItemIdx) {
    if (firstItemIdx == secondItemIdx) return;
    node<elementType>* prevFirst = NULL;
    node<elementType>* currFirst = head;
    while (currFirst && currFirst->info != firstItemIdx) {
        prevFirst = currFirst;
        currFirst = currFirst->next;
    }
    node<elementType>* prevSecond = NULL;
    node<elementType>* currSecond = head;
    while (currSecond && currSecond->info != secondItemIdx) {
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
singleLinkedList<elementType> singleLinkedList<elementType>:: addTreeListsInOne(singleLinkedList<elementType> list1, singleLinkedList<elementType> list2, singleLinkedList<elementType> list3) {
    singleLinkedList<elementType>list;
    node<elementType>*current =list1.head;
   for(int i=0;i<list1.size;i++){
       list.insertAtTail(current->info);
       current=current->next;
   }
   current =list2.head;
   for(int i=0;i<list2.size;i++){
        list.insertAtTail(current->info);
        current=current->next;
    }current =list3.head;
    for(int i=0;i<list3.size;i++){
        list.insertAtTail(current->info);
        current=current->next;
    }current=NULL;
    list.print();
    cout<<list.sorted()<<endl;
    list.mergeSortedLinkedLists();
    list.print();
    return list;
}

template<typename elementType>
singleLinkedList<elementType> singleLinkedList<elementType> ::mergeSortedLinkedLists(){
    node<elementType>* current = this->head;
    while (!this->sorted()){
        if(current->info > current->next->info){
            swap(current->info,current->next->info);
        }if(!sorted() && current->next==NULL){

            current=this->head;
        }current=current->next;
    }

    this->print();
}

template<typename elementType>
bool singleLinkedList<elementType> ::sorted(){
    node<elementType>* current = this->head;
    while (current->next!=NULL){
        if(current->info > current->next->info){
            return false;
        }
        current = current->next;
    }return true;
}

/*
template<typename elementType>
singleLinkedList<elementType> singleLinkedList<elementType>::mergeSortedLinkedLists(singleLinkedList<elementType>(list2)){
    node<elementType> result;
    if(this->size==0){
        return list2;
    }else if (list2.size == 0)
        return this;
    if(this <= list2->info){
        result = this;
        result.next = this->next.mergeSortedLinkedLists(list2);
    }else{
        result=list2;
        result.next =  this->mergeSortedLinkedLists(list2->next);
    }
    print();
    list2.print();
}
template<typename elementType>
node<elementType>* singleLinkedList<elementType>::SortedMerge(node<elementType>* a, node<elementType>* b)
{
    node<elementType>* result = NULL;

    //Base case to end search
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    // Choose either a or b, and start recursion
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }

    return result;
}
template<typename elementType>
// Primary function that gives sorted output.
node<elementType>* mergeKLists(node<elementType>* arr[], int last)
{
    // repeat until only one list is left
    while (last != 0) {
        int i = 0, j = last;


        while (i < j) {
            // merge List i with List j and store it in List i
            arr[i] = SortedMerge(arr[i], arr[j]);

            // consider next pair
            i++, j--;

            // If all pairs are merged, update last
            if (i >= j)
                last = j;
        }
    }

    return arr[0];
}

template<typename elementType>
void singleLinkedList<elementType>::merge(){

}*/

int main()
{
    singleLinkedList<int>sll,sll2,sll3,sll4,sll5,sll6;
    sll.insertAtHead(10);
    sll.insertAtTail(20);
    sll.insertAtTail(90);
    sll.insertAt(30,2);
    sll.print();
    sll.swapl(1,2);
    sll.print();
    sll.replaceAt(80,1);
    cout<<sll.retrieveAt(1)<<endl;
    sll.print();
    sll.removeAt(2);
    sll.print();
    cout<<sll.isItemAtEqual(80,1)<<endl;
    sll.isExist(30);
    sll.removeAtHead();
    sll.removeAt(1);
    sll.removeAtTail();
    cout<<sll.isEmpty()<<endl;
    sll.print();
    cout<<sll.linkedListSize()<<endl;
    sll.clear();
    cout<<"-------------------------------------------"<<endl;
    sll2.insertAtTail(0);//[0, 3, 1, 0, 4, 5, 2, 0]
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
    cout<<"-------------------------------------------"<<endl;
    sll3.insertAtHead(1);
    sll3.insertAtTail(4);
    sll3.insertAtTail(5);
    sll4.insertAtHead(1);
    sll4.insertAtTail(3);
    sll4.insertAtTail(4);
    sll5.insertAtHead(2);
    sll5.insertAtTail(6);
    //sll6.addTreeListsInOne(sll3,sll4,sll5);

    //node<int>head1=new node<int>();
    //node<int>head = mergeKLists(node<int>sll3,3-1);
    return 0;
}












