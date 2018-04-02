#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
	int n,k,i;
	cin >> n >> k;
	int array[n],a,b;
	for(i=0;i<n;i++)
	{
		cin >> array[i];
	}
	sort(array,array+n);
	for(i=0;i<n;i++)
	{
		if(array[i]>=k)
		{
			break;
		}
	}
	if(i==0)
		cout<<array[i]<<endl;
	else
	{	
		a=abs(array[i]-k);
		b=abs(array[i-1]-k);
		if(a<=b)
			cout<<array[i]<<endl;
		else
			cout<<array[i-1]<<endl;
	}
	return 0;
}