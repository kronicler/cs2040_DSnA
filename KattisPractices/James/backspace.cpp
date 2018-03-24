#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main () {
	char c;
	stack<char> st;

	while(scanf("%c", &c) != EOF && c != '\n') {
		if (c == '<') st.pop();
		else st.push(c);
	}

	if(!st.empty()) {
		char out[st.size() + 1];
		out[st.size()] = '\0';
		while (!st.empty()) {
			out[st.size()-1] = st.top();
			st.pop();
		}
		cout << out << endl;
	}

	return 0;
}