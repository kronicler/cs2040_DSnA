// Overriding insert of an array 

void insert (int v, int pos, int *arr, int* size) {

	for (int i = pos; i < size - 1; ++i)
	{
		A[i+1] = A[i]; // In this case, the last element will be LOST or overridden. We should increase the size first. 
	}	
	A[pos] = v;
	*size++;
}



// Direct reference of .size() in a loop esp for item removal

for (int d = 0; d < list.size(); d++) {
	// Will only run "halfway" as each time list pops, it will update list.size()
	cout << "Transferred: " << list.top() << endl;
	list.pop();
}


// Time complexities
/*

F(n) = n + (1/2)n + (1/3)n + ... + 1 is O(2^n) easily mistaken for O(n)

actual fact: harmonic series, so its Olog(n)

Summation usually can be derived from the formula: Sn = a(1-r^n)/(1-r) for geometric progression 

*/


// End iterator of a vector/ deque

vector<int> myvec ({1,2,3});

auto it = myvec.end();

// *it is not 3, its actually the one next to 3 which is a null object  


