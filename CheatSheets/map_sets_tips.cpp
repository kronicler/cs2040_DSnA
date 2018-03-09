#include <iostream>
#include <stdio.h>
#include <unordered_map>
#include <map>
#include <unordered_set>

using namespace  std;

int main () {
	unordered_map<string, int> myMap ;
	myMap.insert(make_pair("six", 6));
	myMap.insert(make_pair("five", 5));

	cout << myMap.count("six") << endl;
	cout << myMap.count("four") << endl; // Will print zero as it doesnt exist 

	// will reach end of map when it doesnt find anything 
	if (myMap.find("ten") == myMap.end()) cout << "ten does not exist" << endl; // Will be printed 

	myMap.erase(myMap.find("six")); 
	cout << myMap.count("six") << endl; // Will return 0 as it no longer exists 

}