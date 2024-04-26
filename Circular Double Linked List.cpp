#include <bits/stdc++.h>
using namespace std;
template<class T>
class node{
public:
    T info;
    node* prev;
    node* next;
};
template<class T>
class CircularDoublyLinkedList{
private:
    node<T>* head;
    node<T>* tail;
    int size;
public:
    CircularDoublyLinkedList() {
        head = tail = nullptr;
        size = 0;

    }

    void swap(int indexOne, int indexTwo)
    {
        if (indexOne == indexTwo)
            return;
        if (indexOne > indexTwo)swap(indexOne, indexTwo);
        node<T>* currentFirstNode = head;
        node<T>* prevFirstNode = tail;
        node<T>* nextFirstNode = head->next;

        for (int i = 0; i < indexOne; ++i) {
            prevFirstNode = currentFirstNode;
            currentFirstNode = currentFirstNode->next;
            nextFirstNode = currentFirstNode->next;
        }

        node<T>* currentSecondNode = head;
        node<T>* prevSecondNode = tail;
        node<T>* nextSecondNode = head->next;
        for (int i = 0; i < indexTwo; ++i) {
            prevSecondNode = currentSecondNode;
            currentSecondNode = currentSecondNode->next;
            nextSecondNode = currentSecondNode->next;
        }
        if (indexTwo == size - 1 && indexOne == 0)
        {
            currentSecondNode->next = currentFirstNode->next;
            currentFirstNode->next = currentSecondNode;
            prevSecondNode->next = currentFirstNode;
            tail = currentFirstNode;
            head = currentSecondNode;
            head->prev = tail;
            tail->next = head;

        }
        else if (indexTwo - indexOne == 1)
        {
            if (size == 2)
            {
                head = tail;

                tail = currentFirstNode;
            }
            else {

                currentSecondNode->next = currentFirstNode;
                currentFirstNode->next = nextSecondNode;
                currentSecondNode->prev = prevFirstNode;
                currentFirstNode->prev = currentSecondNode;
                nextSecondNode->prev = currentFirstNode;
                prevFirstNode->next = currentSecondNode;
                if (indexOne == 0)
                {
                    currentSecondNode->prev = tail;
                    tail->next = currentSecondNode;
                    head = currentSecondNode;
                }
                if (indexTwo == size - 1)
                {
                    currentFirstNode->next = head;
                    head->prev = currentFirstNode;
                    tail = currentFirstNode;
                }
            }


        }
        else
        {

            currentFirstNode->next = nextSecondNode;
            currentSecondNode->next = nextFirstNode;
            prevFirstNode->next = currentSecondNode;
            currentSecondNode->prev = prevFirstNode;
            prevSecondNode->next = currentFirstNode;
            currentFirstNode->prev=prevSecondNode;
        }


    }
    void replaceAt(T newElement, int index) {
        if(index==0){
            head->info=newElement;

        }
        else if(index == size - 1){
            tail->info=newElement;

        }
        else{
            node<T> *current;
            current = head;
            int countnode=0;
            while(countnode<index){
                current=current->next;
                countnode++;
            }
            current->info=newElement;

        }

    }
    void insertAt(T element, int index) {
        if(index==0){
            insertAtHead(element);
        }
        else if(index == size - 1){
            insertAtTail(element);
        }
        else{
            node<T> *current;
            node<T> *prevcurrent;
            current = head;
            int countnode=0;
            node<T>* newNode;
            newNode=new node<T>;
            newNode->info=element;
            newNode->prev=NULL;
            newNode->next=NULL;
            while(countnode<index){
                current=current->next;
                countnode++;
            }
            prevcurrent=current->prev;
            newNode->next=current;
            current->prev=newNode;
            prevcurrent->next=newNode;
            newNode->prev=prevcurrent;
            size++;


        }

    }
    T retrieveAt(int index) {
        node<T> *current;
        current = head;
        int countnode=0;
        while(countnode<index){
            current=current->next;
            countnode++;
        }
        return current->info;

    }
    void clear() {
        node<T> *current;
        while(size--){
            current = head;
            head=head->next;
            delete current;
        }
        size=0;
        head=NULL;
        tail=NULL;

    }
    bool isItemAtEqual(T element, int index) {
        int countnode=0;
        node<T> *current;
        current = head;
        if(index<0|| index>size)
        {
            cout<<"invaild index\n";
        }
        else
        {

            while(countnode<index){
                current=current->next;
                countnode++;
            }
            if(current->info==element){
                return true;
            }
            else{
                return false;
            }

        }
    }
    void removeAt(int index) {
        if(head == NULL){
            cout<<"can not delete from empty list";
        }
        else {
            if (index == 0) {
                removeAtHead();
            }

            else if (index == size - 1) {
                removeAtTail();

            }
            else {
                node<T> *current;
                node<T> *prevcurrent;
                current = head;
                int countnode=0;
                while(countnode<index){
                    current=current->next;
                    countnode++;
                }
                prevcurrent=current->prev;
                prevcurrent->next=current->next;
                prevcurrent->next->prev=prevcurrent;
                size--;
                delete current;
            }
        }
    }
    void removeAtTail() {
        if(tail != NULL){
            node<T> *current;
            current =tail;
            tail=tail->prev;
            if(tail != NULL){
                tail->next=head;
                head->prev=tail;
            }
            else{
                head=NULL;
            }
            size--;
            delete current;
        }
    }
    void removeAtHead() {
        if(head != NULL){
            node<T> *current;
            current = head;
            head=head->next;
            if(head != NULL){
                head->prev=tail;
                tail->next=head;
            }
            else{
                tail=NULL;
            }
            size--;
            delete current;
        }
    }
    bool isExist(T element) {
        node<T> *current;
        current = head;
        int sz=size;
        while (sz--) {
            if(current->info==element){
                return true;
            }
            current = current->next;
        }
        return false;
    }
    void print() {
        node<T> *current;
        current = head;
        if(isEmpty()){
            cout<<"empty list"<<endl;
        }
        else{
            int sz= size;
            while (sz--) {
                cout << current->info<<" ";
                current = current->next;
            }
        }
    }
    int linkedListSize() {
        return size;
    }

    bool isEmpty() {
        if(size == 0){
            return true;
        }
        else{
            return false;
        }
    }
    void insertAtTail(T element) {
        node<T>* newNode;
        newNode=new node<T>;
        newNode->info=element;
        newNode->prev=NULL;
        newNode->next=NULL;
        if(head == NULL){
            head=newNode;
            tail=newNode;
            tail->next=head;
            head->prev=tail;
            size++;
        }
        else{
            tail->next=newNode;
            newNode->prev=tail;
            tail=newNode;
            head->prev=tail;
            tail->next= head;
            size++;
        }
    }

    void insertAtHead(T element) {
        node<T>* newNode;
        newNode=new node<T>;
        newNode->info=element;
        newNode->prev=NULL;
        newNode->next=NULL;
        if(head == NULL){
            head=newNode;
            tail=newNode;
            tail->next=head;
            head->prev=tail;
            size++;
        }
        else{

            newNode->next=head;
            head->prev=newNode;
            head=newNode;
            newNode->prev=tail;
            tail->next=newNode;
            size++;
        }
    }
};

int main() {
    CircularDoublyLinkedList<int> d;
    d.insertAtHead(50);
    d.insertAtHead(55);
    d.insertAtTail(13);
    d.insertAtHead(10);
    d.print();
    cout<<endl;
    d.insertAt(60,2);
    d.print();
    cout<<endl;
    d.replaceAt(65,2);
    d.print();
    cout<<endl;
    cout<<d.retrieveAt(0)<<endl;
    d.swap(1,2);
    d.print();
    cout<<endl;
    d.removeAt(3);
    d.print();
    cout<<d.linkedListSize()<<endl;
    cout<<d.isItemAtEqual(65,1)<<endl;
    cout<<d.isExist(13)<<endl;
    cout<<d.isExist(50)<<endl;
    d.clear();
    cout<<d.isEmpty();
    return 0;
}
