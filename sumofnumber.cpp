#include <iostream>
#include <vector>
using namespace std;

void sos(int,long long int);
int n,flag=0;
long long int array[15],s;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int i;
		cin >> n;
		flag=0;
		for (i=0;i<n;i++)
		{
			cin >> array[i];
		}
		cin >> s;
		if(s==0)
		{
			cout<<"YES"<<endl;
		}
		else
		{
			sos(0,0);
			if(flag==1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}

void sos (int m,long long int sum)
{
	if (m>n || flag==1)
		return;

	if (sum==s)
	{
		flag=1;
		return;
	}

	//if (array[m]>s)
	//	sos(m+1,sum);
	else
	{
		sos(m+1,sum+array[m]);
		//cout<<sum<<endl;
		sos(m+1,sum);
		//cout<<sum<<endl;
	}
}