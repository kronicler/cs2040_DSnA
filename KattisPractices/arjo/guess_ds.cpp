#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define STACK 0 
#define Q 1
#define PQ 2


#define parent(i) (i-1)/2
#define left(i) 2*i+1
#define right(i) 2*i+2

using namespace std;

int main(int argc, char** argv) {
	int test_case;
	while(cin >> test_case){
		stack<int> st;
		queue<int> q;
		priority_queue<int> pq;
		int data_type[3];
		for(int i = 0 ; i < 3; i++) data_type[i] = 1;
		for(int i = 0; i < test_case; i++){
			int x,y;
			cin >> x >> y;
			if(x == 1){
				st.push(y);
				q.push(y);
				pq.push(y);
			}
			else{
				if(!st.empty() && data_type[STACK]){
					if(st.top()!=y) data_type[STACK] = 0;
					st.pop();
				}
				else data_type[STACK] = 0;
				if(!q.empty() && data_type[Q]){
					if(q.front()!=y) data_type[Q] = 0;
					q.pop();
				}
				else data_type[Q] = 0;
				if(!pq.empty() && data_type[PQ]){
					if(pq.top()!=y) data_type[PQ] = 0;
					pq.pop();
				}
				else data_type[PQ] = 0;

				
			}
		}
		int sum = 0;
		for(int i = 0 ; i < 3; i++) sum+=data_type[i];
		if(sum > 1) {
			cout << "not sure"<<endl;
			continue;
		} 
		if(sum == 0) {
			cout << "impossible" <<endl;
			continue;
		}
		if(data_type[STACK]) cout << "stack"<<endl;
		if(data_type[Q]) cout <<"queue"<<endl;
		if(data_type[PQ]) cout << "priority queue"<<endl;
	}
	//cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked." <<endl;
	return 0;
}
