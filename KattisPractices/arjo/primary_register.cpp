#include <iostream>
using namespace std;
int main(int argc, char** argv){
   int primes[] = {1,2,6,30,210,2310,30030,510510};
   int array[8]; 
   long total = 0;
   for(int i = 0; i < 8; i++){
       cin >> array[i];
   }
   for(int i = 0; i < 8; i++){
       total += array[i]*primes[i];
   }
   cout << 9699689 - total << endl;
}
