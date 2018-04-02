#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct data
{
	int initial;
	int final;
	int value;
}data;
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		int n , x, y,i,total_cost=0;
		cin >> n >> x >> y;
		data array[n];
		for(i=0;i<n;i++)
		{
			cin >> array[i].initial >> array[i].final;
			array[i].value=array[i].initial- array[i].final;
		}
		for(i=0;i<n;i++)
		{
			if(array[i].value<0)
			{
				total_cost+=abs(y);
			}
			else
			{
				total_cost+=abs(x);
			}
		}
		cout<< total_cost <<endl;
	}
	return 0;
}