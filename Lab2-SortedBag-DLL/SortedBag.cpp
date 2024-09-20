#include "SortedBag.h"
#include "SortedBagIterator.h"

SortedBag::SortedBag(Relation r) {
    head = nullptr;
    tail = nullptr;
    rel = r;
    nrElems = 0;
}

void SortedBag::add(TComp e) {
	//0. add because list is empty
    //1. add in front because e is smaller then head
    //2. add in between elements
    //3. add at the end of the list because it's larger than all

    TElem newElem = std::pair(e, 1);
    Node * newNode = new Node(newElem);

    //0.
    if (head == nullptr) {
        head = tail = newNode;
        return;
    }
    
    
    Node * current = head;
    //1.
    if (rel(e, current->elem.first)) {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    
    //put current in correct position
    while (current != nullptr && rel(current->elem.first, e)) {
        current = current->next;
    }

    
    //3. current reached end of DLL  && //2.
    if (current == nullptr) {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    } else {
        //link new node addresses with next and prev
        newNode->next = current;
        newNode->prev = current->prev;
        if (current->prev != nullptr) {
            current->prev->next = newNode;
        }
        current->prev = newNode;
        if (current == head) {
            head = newNode;
        }
    }
    
}


bool SortedBag::remove(TComp e) {
	//TODO - Implementation
	return false;
}


bool SortedBag::search(TComp elem) const {
    Node * current = head; //temp node that points to the start of the DLL&
    
    while (current != nullptr) {
        if (current->elem.first == elem) {
            return true;
        }
        current = current->next;
    }
	return false;
}


int SortedBag::nrOccurrences(TComp elem) const {
    Node * current = head;
    while (current != nullptr) {
        if (current->elem.first == elem) {
            return current->elem.second;
        }
    }
	return 0;
}


int SortedBag::size() const {
    int counter = 0;
    Node * current = head;
    while (current != nullptr) {
        counter += current->elem.second;
        current = current->next;
    }
	return counter;
}


bool SortedBag::isEmpty() const {
	return head == nullptr;
}


SortedBagIterator SortedBag::iterator() const {
	return SortedBagIterator(*this);
}


SortedBag::~SortedBag() {
    while (head != nullptr) {
        Node * temp = head;
        head = head->next;
        delete temp;
    }
}
