#include <iostream>
using namespace std;

void func(long int);
long int n,cur;
long long int k;
static long long int count;
int main()
{
	long int t;
	cin >> t >>n;
	while(t--)
	{
		count=0;
		cin >> cur >> k;
		func(0);
		cout << count << endl;
	}
	return 0;
}

void func(long int m)
{
	if(m>cur)
		return;
	if(m==cur)
	{
		count++;
		return;
	}
	else
	{
		func(m+2);
		func(m+5);
		func(m+k);
	}
}