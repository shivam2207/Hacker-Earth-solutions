#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
typedef struct data
{
	int diff;
	int index;
}data;
bool compare(data a,data b)
{
	return a.diff<b.diff;
}
int main()
{
	long long int n;
	cin >> n;
	int i;
	string s1,s2;
	int first[n],second[n];
	data array[n];
	for(i=0;i<n;i++)
	{
		cin >> s1 >> s2;
		first[i]=s1.size();
		second[i]=s2.size();
		array[i].diff=first[i]-second[i];
		array[i].index=i;
	}
	sort(array,array+n,compare);

	return 0;
}