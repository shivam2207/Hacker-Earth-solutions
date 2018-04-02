#include <iostream>
using namespace std;

int palindrome(int);
int array[6];
int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		int a,b,count=0,i;

		cin >>a>>b;
		for(i=a;i<=b;i++)
		{
			if(palindrome(i))
				count++;
		}
		cout<<count<<endl;
	}
	return 0;
}

int palindrome(int n)
{
	int i=0,j;
	while(n>0)
	{
		array[i]=n%10;
		n=n/10;
		i++;
	}
	i--;
	for(j=0;j<i;j++,i--)
	{
		if(array[i]!=array[j])
			return 0;
	}
	return 1;
}