#include <iostream>
#include <unordered_map>
using namespace std;

int main () {
	int jack, jill;
	while (scanf("%d %d", &jack, &jill), (jack || jill)) {
		long cd, ans = 0;
		unordered_map <long, long> Ja;
		for (int i = 0; i < jack; i++) {
			scanf("%ld", &cd);
			Ja[cd] = 1;
		}
		for (int i = 0; i < jill; i++) {
			scanf("%ld", &cd);
			if (Ja.count(cd) > 0) ans++;
		}
		printf("%ld\n", ans);
	}
	return 0;
}