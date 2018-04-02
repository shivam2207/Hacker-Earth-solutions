#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

long int max(int);
vector<long int> d;
vector<long int> b;
int n;

int main()
{
	int i;
	cin >> n;
	
	long int temp,temp1,temp2;
	for(i=0;i<n;i++)
	{
		cin >> temp;
		d.push_back(temp);
	}
	for(i=0;i<n;i++)
	{
		cin >> temp;
		b.push_back(temp);
	}
	temp1=max(1);
	temp2=max(2);
	if(temp1>temp2)
	{
		cout<<"Dom"<<endl;
		cout<<temp1<<endl;
	}
	else if(temp1==temp2)
	{
		cout<<"Tie"<<endl;
		cout<<temp1<<endl;
	}
	else
	{
		cout<<"Brian"<<endl;
		cout<<temp2<<endl;
	}
}

long int max(int a)
{
	int i;
	long int max=0;
	for(i=1;i<n;i++)
	{
		if(a==1)
		{
			if(abs(d[i]-d[i-1])>max)
				max=abs(d[i]-d[i-1]);
		}
		else
		{
			if(abs(b[i]-b[i-1])>max)
				max=abs(b[i]-b[i-1]);
		}
	}
	return max;
}