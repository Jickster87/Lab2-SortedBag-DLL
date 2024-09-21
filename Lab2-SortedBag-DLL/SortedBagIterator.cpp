#include "SortedBagIterator.h"
#include "SortedBag.h"
#include <exception>

using namespace std;

SortedBagIterator::SortedBagIterator(const SortedBag& b) : bag(b) {
    currentElem = bag.head;
    freqCounter = 0;
}

TComp SortedBagIterator::getCurrent() {
    if (!valid()) {
        throw exception();
    }
    return currentElem->elem.first;
}

bool SortedBagIterator::valid() {
	return currentElem != nullptr;
}

void SortedBagIterator::next() {
    if (!valid()) {
        throw exception();
    }
    freqCounter++;
    if (freqCounter > currentElem->elem.second) {
        currentElem = currentElem->next;
        freqCounter = 1;
    }
}

void SortedBagIterator::first() {
    currentElem = bag.head;
}

