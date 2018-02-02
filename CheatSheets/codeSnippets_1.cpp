
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

