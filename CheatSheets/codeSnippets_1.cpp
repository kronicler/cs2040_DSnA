
// To get input of different cases and move on to the next test case on newline

void getInput () {
	int num;
	while(true) {
		cin >> num;
		// Perform your operations here

		if (cin.peek() == '\n') 
			break;
	}
}


// Tokenisation for strings

void tokenise (string s) {
	// Use getline (cin, line) to store the line 

	string delimiter = " ";

	size_t pos = 0;
	string token;
	while ((pos = s.find(delimiter)) != string::npos) {
		token = s.substr(0, pos);
		cout << token << endl;
		s.erase(0, pos + delimiter.length());
	}
	cout << s << endl;
}

void tokenise_2 (string line) {
	// Another form of str tok 
	// Depends on sstream
	// Use getline (cin, line) to store the line 
	istringstream iss (line);
	string token;
	while (getline(iss, token, '-'))
		cout << token[0]; // Perform operations here
	cout << endl;
}


// Number splitter 2.0 

void numSplit (int num) {
	
	for (int exp = 1; num/exp > 0; exp *= 10) {
		cout << (num/exp) % 10 << endl;
		/* Perform your number operations here */
	}
}


// Custom sorting with stl

void customCompareSort (vector<int> * ) {
	// sort using a standard library compare function object
    std::sort(s.begin(), s.end(), std::greater<int>());


    // sort using a custom function object
    struct {
        bool operator()(int a, int b) const
        {   
            return a < b;
        }   
    } customLess;
    std::sort(s.begin(), s.end(), customLess);
    

	// sort using a lambda expression 
    std::sort(s.begin(), s.end(), [](int a, int b) {
        return a > b;   
    }); // Sort in descending order 
}

// To iterate and remove elements from a list in std list 

void itr_remove_from_list (list<int> mylist) {
	for (auto i = mylist.begin(); i != mylist.end() ; /*make sure not to increment here*/)
	{
		if (/*your conditions here*/) {
			i = mylist.erase(i); // This is because erasing the element will make i redundant if you dont update it.
		}else {
			i++; // When there's no erasing done then just increment as per normal
		}
	}
}


// Creation of tuples 

int main () {
	auto t = make_tuple (1, "Foo" , 3.14);

	// Index based access:
	int i = get<0><t>;

	// Type based access: 
	string str = get<string><t>;
}


// Union and intersection of vectors 

int main () {

    vector<int> A({1,3,7,5,8});
    vector<int> B({4,9,3,2,7});
    vector<int> C;
    vector<int> D;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    
    auto it = set_intersection(A.begin(), A.end(), B.begin(), B.end(), back_inserter(C)); // it points to C.begin() technically 
    
    for (auto it = C.begin(); it != C.end(); it++) {
        cout << *it << " "; // will print 3, 7
    }
    cout << endl;
    set_union(A.begin(), A.end(), B.begin(), B.end(), back_inserter(D));
    
    for (auto it = D.begin(); it != D.end(); it++) {
        cout << *it << " "; // will print 1 2 3 4 5 7 8 9
    }
    cout << endl;

    return 0;
}


// Infix to postfix converter
// Precond: string must be tokenised before insertion. Operators only include the various symbols shown in map 
// Depends on map, stack

void processPostFix (string s, string *postfix, stack<string> *opstack) {
    map<string, int> prec;
    prec ["+"] = 1;
    prec ["-"] = 1;
    prec ["*"] = 2;
    prec ["/"] = 2;
    // Check if its a digit first
    if (s[0] <= '9' && s[0] >= '0' ){
        *postfix += s;
        *postfix += " ";
    } else {
        if (s[1] <= '9' && s[1] >= '0') {
            // Negative number
            *postfix += s;
            *postfix += " ";
            return;
        }
        if (opstack->empty()) {
            opstack->push(s);
        } else {
            // Check precedence
            if (s == "(") {
                opstack->push(s);
                return;
            }
            
            if (s == ")") {
                while (opstack->top() != "(") {
                    *postfix += opstack->top();
                    *postfix += " ";
                    opstack->pop();
                }
                opstack->pop();
                return;
            }
            
            if (prec[opstack->top()] > prec[s] || opstack->top() == "(") {
                opstack->push(s);
            } else {
                // popped
                *postfix += opstack->top();
                *postfix += " ";
                opstack->pop();
                opstack->push(s);
            }
        }
    }
}

string postFix (string s) {
    stack<string> opstack;
    string delimiter = " ";
    size_t pos = 0;
    string token;
    string postfix;
    while ((pos = s.find(delimiter)) != string::npos) {
        token = s.substr(0, pos);
        processPostFix(token, &postfix, &opstack);
        s.erase(0, pos + delimiter.length());
    }
    
    //cout << s << endl;
    
    processPostFix(s, &postfix, &opstack);
    
    
    
    while (!opstack.empty()) {
        postfix += opstack.top();
        postfix += " ";
        opstack.pop();
    }
    return postfix;
}


// Flood fill using stack implementation 

void searchNeighbours (stack<tuple<int, int>> *mystack, vector<vector<int>> thisVector, tuple<int, int> currentCoords, int paint) {
    int x = get<0>(currentCoords);
    int y = get<1>(currentCoords);
    
    if (x+1 < thisVector.at(0).size() && thisVector.at(y).at(x+1) != paint){
        auto newCoords = make_tuple(x+1, y);
        mystack->push(newCoords);
    }
    if (x-1 >= 0 && thisVector.at(y).at(x-1) != paint) {
        auto newCoords = make_tuple(x-1, y);
        mystack->push(newCoords);
    }
    if (y-1 >= 0 && thisVector.at(y-1).at(x) != paint) {
        auto newCoords = make_tuple(x, y-1);
        mystack->push(newCoords);
    }
    if (y+1 < thisVector.size() && thisVector.at(y+1).at(x) != paint) {
        auto newCoords = make_tuple(x, y+1);
        mystack->push(newCoords);
    }
}

void floodFill_stacks(vector<vector<int>> *thisVector, tuple<int, int> firstCoords, int paint) {
    stack<tuple<int, int>> myStack;
    myStack.push(firstCoords);
    
    while (!myStack.empty()) {
        auto current = myStack.top();
        myStack.pop();
        thisVector->at(get<1>(current)).at(get<0>(current)) = paint;
        searchNeighbours(&myStack, *thisVector, current, paint);
    }
}


// Quick Select find kth smallest  
int partition(int arr[], int l, int r)
{
    int x = arr[r], i = l;
    for (int j = l; j <= r - 1; j++) {
        if (arr[j] <= x) {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
            i++;
        }
    }
    int t = arr[i];
    arr[i] = arr[r];
    arr[r] = t;
    return i;
}


int kthSmallest(int arr[], int l, int r, int smallestElement)
{
    // This function returns k'th smallest
    // element in arr[l..r] using QuickSort
    // based method.  ASSUMPTION: ALL ELEMENTS
    // IN ARR[] ARE DISTINCT
    
    
    // If k is smaller than number of
    // elements in array
    if (smallestElement > 0 && smallestElement <= r - l + 1) {
        
        // Partition the array around last
        // element and get position of pivot
        // element in sorted array
        int index = partition(arr, l, r);
        
        // If position is same as k
        if (index - l == smallestElement - 1)
            return arr[index];
        
        // If position is more, recur
        // for left subarray
        if (index - l > smallestElement - 1)
            return kthSmallest(arr, l, index - 1, smallestElement);
        
        // Else recur for right subarray
        return kthSmallest(arr, index + 1, r,
                           smallestElement - index + l - 1);
    }
    
    // If k is more than number of
    // elements in array
    return INT_MAX;
}


// Using upper bound and lower bound
// TODO: Add more applications to this eg finding out if there are duplicates 
int main () {
    vector<int> v({1,2,2,2,3,3,3,4});
    auto low=std::lower_bound (v.begin(), v.end(), 2);
    
    cout << (*low) << endl; // Prints 2
    cout << (low - v.begin()) << endl; // pos 1
    
    auto high=std::upper_bound (v.begin(), v.end(), 2);
    
    
    cout << (*high) << endl; // Prints 3, first number that's bigger than the one we want 
    cout << (high - v.begin()) << endl; // pos 4


    if (low != --high) cout << "duplicates detected" << endl;
}

// Power thru bit shifting 


int bitMasking (int power) {
    return 1<<power; // Using bit shifting 
}


// Find longest substring that occurs more than once

void longest_substr (string input) {
    map<string, int> freq;
    int flag = 0;
    for (int i = (input.length())/2; i >= 1 && !flag; i--) {
        cout << i << endl;
        for (int d = 0; d + i + i <= input.length(); d++) {
            if (input.substr(d, i) == input.substr(d + i, i)) {
                
                //cout << input.substr(d, i) << endl;
                // How to find the most frequent substring?
                freq[input.substr(d,i)]++;
                flag = 1; // stop at this size
            }
        }
    }
    
    int largest = 0;
    //string largest;
    auto x = max_element(freq.begin(), freq.end(),
                              [](const pair<string, int>& p1, const pair<string, int>& p2) {
                                  return p1.second < p2.second; });
    cout << x->first << endl; // Will output the longest substr 
}


