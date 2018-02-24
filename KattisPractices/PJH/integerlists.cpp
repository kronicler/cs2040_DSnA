// Integer Lists
// submitting this code verbatim clearly TLE (and please do not do so, no point submitting my clearly AC demo code to Kattis just to get Kattis points... you will learn more by adapting your own code until AC or writing your own version from scratch until AC)
// we have discussed the reasons in class and Steven has shown how to write a fast enough code

#include <bits/stdc++.h>
using namespace std;

int main() {
  int TC;
  scanf("%d ", &TC); // consume '\n' (newline) character
  while (TC--) {
    char p[100010]; // enlarge a bit just in case, max p in the problem is 100K characters
    int i, n, x_val;
    scanf("%s ", &p);
    scanf("%d ", &n);
    scanf("["); // a potentially new scanf technique, consume '[' character, if you are a pure C++ coder, you can use cin.get()

    deque<int> x; // something is SLOW because of this... try forward_list, list, deque?
    for (i = 0; i < n; i++) {
      if (i) scanf(","); // consume those commas in between x_val(ues)
      scanf("%d", &x_val);
      x.push_back(x_val);
    }
    scanf("] "); // lastly, consume ']' and '\n' (newline) characters

    bool error = false;
    int checker = 1;
    for (i = 0; p[i]; i++) { // go through all commands
      if (p[i] == 'R')
        checker = checker * (-1);
      else { // a 'D'
        if (x.empty()) {
          error = true;
          break;
        }
        else {
            if (checker == 1)
                x.pop_front();
            else
                x.pop_back();
    }
      }
    }
    if (!error) {
      printf("[");
        i = 0;
      if (checker == -1){
        reverse(x.begin(),x.end());
      }
      for (auto &v : x) {
        if (i) printf(",");
        i++;
        printf("%d", v);
      }
      printf("]\n");
    }
    else
      printf("error\n");
  }
  return 0;
}
