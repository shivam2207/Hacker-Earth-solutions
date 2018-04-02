#include <iostream>
using namespace std;
int table[101][101];
void pascal(void)
{
	for (int line = 0; line < 101; line++)
	{
		for (int i = 0; i <= line; i++)
		{
	  		if (line == i || i == 0)
		   		table[line][i] = 1;
	  		else
		   		table[line][i] = (table[line-1][i-1] + table[line-1][i])%10000007;
	  		//printf("%d ", arr[line][i]);
		}
		//printf("\n");
  	}
}
int main()
{
	//cout << "Hello World!" << endl;
	pascal();
	int n,r;
	cin >> n >> r;
	if(r>n)
		cout << "-1" << endl;
	else if (n==r)
		cout << "1" << endl;
	else
	{
		cout << table[n-1][r-1]<<endl;
	}
	return 0;
}
