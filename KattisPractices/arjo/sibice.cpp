#include <iostream>
using namespace std;
int main(){
    int w,h,matches;
    cin >> matches >> w >> h;
    int hyp = w*w + h*h;
    for(int i = 0 ; i < matches;i++){
        int n;
        cin >> n;
        n*=n;
        if(n<=hyp) cout << "DA" <<endl;
	else cout << "NE" <<endl;
    }
}
