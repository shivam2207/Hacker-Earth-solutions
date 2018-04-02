#include <iostream>
#include <algorithm>
using namespace std;
int min_number(int );
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,ans;
		cin >> n;
		if(n==1)
			cout << 1 << endl;
		else if(n==2)
			cout << 2 << endl;
		else
		{
			ans=min_number(n);
			cout << ans << endl;
		}
	}
	return 0;
}

int min_number(int n)
{
	int sum=0,i,count=0,current=1;
	for(i=1;i<n;i++)
	{
		if(sum+2*current<n)
		{
			sum+=2*current;
			current++;
			count+=2;
		}
		else if(sum+2*current==n)
		{
			sum+=2*current;
			current++;
			count+=2;
			break;
		}
		else if(sum+current==n)
		{
			sum+=current;
			current++;
			count++;
			break;
		}
		else if(sum+current>n)
		{
			count++;
			break;
		}
		else
		{
			count+=2;
			break;
		}
	}
	return count;
}