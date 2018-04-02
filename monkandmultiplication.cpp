#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	long int n;
	cin>>n;
	long int a[n],i;
	for(i=0;i<n;i++)
		cin>>a[i];
	if(n==1)
		cout<<-1<<endl;
	if(n==2)
	{
		cout<<-1<<endl;
		cout<<-1<<endl;
	}
	if(n>=3)
	{
		cout<<-1<<endl;
		cout<<-1<<endl;
		long int temp1,temp2,temp3;
		sort(a,a+3);
		temp1=a[2];
		temp2=a[1];
		temp3=a[0];

		cout<<temp3*temp2*temp1<<endl;
		for(i=3;i<n;i++)
		{
			if(a[i]>=temp1)
			{
				temp3=temp2;
				temp2=temp1;
				temp1=a[i];
			}
			else if(a[i]>=temp2)
			{
				temp3=temp2;
				temp2=a[i];
			}
			else if(a[i]>=temp3)
				temp3=a[i];
			cout<<temp3*temp2*temp1<<endl;
		}
	}
	return 0;
}