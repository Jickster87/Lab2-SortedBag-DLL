#include "SortedBag.h"
#include "SortedBagIterator.h"
#include <iostream>
#include "ShortTest.h"
#include "ExtendedTest.h"

using namespace std;

int main() {
	testAll();
    cout << "Short tests over" << endl;
	testAllExtended();
	
	cout << "Test over" << endl;
	system("pause");
}
