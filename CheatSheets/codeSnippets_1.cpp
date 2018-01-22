
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
	std::string delimiter = " ";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		std::cout << token << endl;
		s.erase(0, pos + delimiter.length());
	}
	std::cout << s << endl;
}



// Number splitter 2.0 

void numSplit (int num) {
	
	for (int exp = 1; num/exp > 0; exp *= 10) {
		cout << (num/exp) % 10 << endl;
		/* Perform your number operations here */
	}
}