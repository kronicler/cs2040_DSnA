
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