
#include <bits/stdc++.h>
using namespace std;
//MINIMIZE hash collisions by doubling the hash buckets
#define MAX_WOMEN 400001

//_prq stuff
#define parent(i) (i-1)/2
#define left(i) 2*i+1
#define right(i) 2*i+2

string women_by_arrival[MAX_WOMEN]; 
int dilation_by_id[MAX_WOMEN];
int prq_position[MAX_WOMEN];
int num_women = 0;
int curr_max = 0;
int arrival = 0;
struct Vertex {
	Vertex *next;
	int id;
	string name;
};
class Llist {
	Vertex *home;
public:
	Llist(){
		home = NULL;
	}
	void add(int id,string name){
		Vertex* nt = new Vertex();
		nt->next = home;
		nt->id = id;
		nt->name = name;
		home = nt;
	};
	int check(string str){
		Vertex* x = home;
		while(x != NULL){
			if(x->name == str) return x->id;
			x = x->next;
		}
		return -1;
	}		 
};

class _prq{
	public:
		int arr[MAX_WOMEN];
		int size;
		void repair(int i, int maxSize) {
			if (left(i) < size && right(i) < maxSize) {
				if (arr[left(i)] < arr[right(i)]) {
					if (arr[left(i)] < arr[i]) {
						swap(prq_position[arr[i]],prq_position[arr[left(i)]]); 
						swap(arr[i], arr[left(i)]);
						repair(left(i), maxSize);
					}
				}else {
					if (arr[right(i)] < arr[i]) {
						swap(prq_position[arr[i]],prq_position[arr[right(i)]]);
						swap(arr[i], arr[right(i)]);
						repair(right(i), maxSize);
					}
				}
			}
			else if (left(i) < maxSize) {
				if (arr[left(i)] < arr[i]) {
					swap(prq_position[arr[i]],prq_position[arr[left(i)]]);
					swap(arr[i], arr[left(i)]);
					repair(left(i), maxSize);
				}
			}
			else if (right(i) < maxSize) {
				if (arr[right(i)] < arr[i]) {
					swap(prq_position[arr[i]],prq_position[arr[right(i)]]);
					swap(arr[i], arr[right(i)]);
					repair(right(i), maxSize);
				}
			}
			else {
				return;
			}
		}
		void adjust (int i) {
			if (arr[i] < arr[parent(i)]) {
				swap(prq_position[arr[i]],prq_position[arr[parent(i)]]);
				swap(arr[i], arr[parent(i)]);
				adjust(parent(i));
			}else {
				return;
			}
		}
		_prq(){
			size=0;
		}
		void push (int value) {
			arr[size++]=value;
			prq_position[value] = size-1;
			adjust(size - 1);
		}
		int top(){
			return arr[0];
		}
		void delete_index(int index){
			arr[index] = arr[size-1];
			size--;
			if(arr[index] < arr[parent(index)]){
				adjust(index);
			}
			else{
				repair(index,size);
			}
		}
		void pop() {
			swap(prq_position[arr[0]], prq_position[arr[size-1]]);
			swap(arr[0], arr[size - 1]);
			size--;
			if (size==0) return;
			repair(0, size);
		}
		bool empty(){
			return size == 0;
		}
};


_prq pq[100];

class unordered_kvpair {
	std::hash<std::string> hash_fn;
	Llist lst[MAX_WOMEN];
	public:
	int get(string str){
		size_t index = hash_fn(str)%MAX_WOMEN;
		int count = 0;
		return lst[index].check(str);
	}
	void set(string str, int arrival){
		size_t index = hash_fn(str)%MAX_WOMEN;
		//cout << "trying at " << index <<endl;
		//cout << "placing at " << index <<endl;
		lst[index].add(arrival,str);
		//cout << table_arrival[index] << ":" << arrival_occupied[index] <<endl;
	}
};

unordered_kvpair myk;

void ArriveAtHospital(string& womanName, int dilation){
	//cout << "processing " <<womanName <<endl;
	myk.set(womanName,arrival);
	women_by_arrival[arrival] = womanName;
	dilation_by_id[arrival] = dilation;
	pq[dilation].push(arrival);
	arrival++;
	num_women++;
}


void UpdateDilation(string& womanName, int increaseDilation){
	//cout << "updating "<< womanName<<endl;
	int id = myk.get(womanName);
	int prev_dilation = dilation_by_id[id];
	dilation_by_id[id] += increaseDilation;
	//cout << "moved from" << prev_dilation << ", " << prq_position[id];
	pq[prev_dilation].delete_index(prq_position[id]);
	pq[dilation_by_id[id]].push(id);
	//cout << "to" << dilation_by_id[id] << ", " << prq_position[id] << endl;
}

void GiveBirth(string& womanName){
	//cout << "removing " <<womanName <<endl;
	int id = myk.get(womanName);
	int dil = dilation_by_id[id];
	pq[dil].delete_index(prq_position[id]);
	//myk.erase(womanName);
	num_women--;
}

void Query() {
	if(num_women>0){
		for(int i = 99; i >=0 ;i--){
			if(!pq[i].empty()){
				//cout << "non empty"<<endl;
				cout << women_by_arrival[pq[i].top()]<<endl;
				return;
			}
		}
	} else{
		cout << "The delivery suite is empty"<<endl;
	}
}
int main() {
	int commands;
	cin >> commands;
	for(int i = 0 ; i < commands; i++){
		int j, dil;
		string name;
		cin >> j;
		switch(j){
			case 0:
				cin >> name >> dil;
				ArriveAtHospital(name,dil);
				break;
			case 1:
				cin >> name >> dil;
				UpdateDilation(name,dil);
				break;
			case 2: 
				cin >> name;
				GiveBirth(name);
				break;
			case 3:
				Query();
				break;	
		}
	}
	cout << "By submitting this C++ source code, I declare that it is MY OWN implementation work. I fully understand the underlying algorithm behind the C++ code that I wrote and can prove it to Lab TA if asked."<<endl;
}
