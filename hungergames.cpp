#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int array[n],i,max_value=0,temp;
	for(i=0;i<n;i++)
		cin >> array[i];
	sort(array,array+n);
	for(i=0;i<n-2;i++)
	{
		temp=abs(array[i]-array[i+2]);
		max_value=max(temp,max_value);
	}
	temp=abs(array[0]-array[1]);
	max_value=max(max_value,temp);
	temp=abs(array[n-1]-array[n-2]);
	max_value=max(temp,max_value);
	cout << max_value << endl;
	return 0;
}