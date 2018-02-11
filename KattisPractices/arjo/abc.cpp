#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char** argv){
	int nums[3];
	char str[4];
	cin >> nums[0] >> nums[1] >> nums[2];
	sort(nums, nums+3);
	cin >> str;
	for(int i = 0; i < 3; i++){
		cout << nums[str[i]-'A'] << " ";
	}
	return 0;
}
