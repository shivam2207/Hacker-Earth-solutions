#include <iostream>
#include <algorithm>
using namespace std;
typedef struct data
{
	int index;
	int g;
	int p;
}data;
bool compare(data a, data b)
{
	return (a.p<b.p);
}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n,m,flag=0,i;
		cin >> n >> m;
		data array[n];
		long long cumpower=m;
		for(i=0;i<n;i++)
		{
			cin >> array[i].g >> array[i].p;
			array[i].index=i;
		}
		sort(array,array+n,compare);
		for(i=0;i<n;i++)
		{
			if(cumpower<array[i].p)
			{
				flag=1;
				break;
			}
			cumpower+=array[i].g;
		}
		if(flag==1)
			cout << "NO" <<endl;
		else
			cout << "YES" <<endl;
	}
	return 0;
}