#include <iostream>
#define MAX 100


using namespace std;


int main(int argc, char const *argv[])
{
	char arr[MAX][MAX];
	int num;
	cin >> num;
	for (int i = 0; i < num; ++i)
	{
		for (int d = 0; d < (2 * num) - 1; ++d)
		{
			arr[i][d] = ' ';

		}
	}


	for (int i = num-1; i >= 0 ; --i)
	{
		for (int d = (2* num) - 1 - (num - i); d >= num - 1 - i ; --d)
		{
			arr[i][d] = '*';

		}
	}

	int smallNum = num - 2;

	for (int i = smallNum; i >= 0 ; --i)
	{
		for (int d = (2* smallNum) - (smallNum - i); d >= smallNum  - i + 2; --d)
		{
			arr[i][d] = '#';

		}
	}

	for (int i = 0; i < num; ++i)
	{
		for (int d = 0; d < (2* num) - 1; ++d)
		{
			printf("%c", arr[i][d]);
		}
		printf("\n");
	}

	return 0;
}