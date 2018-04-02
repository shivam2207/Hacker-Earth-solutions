#include <iostream>
#include <vector>

#define div 1000000007
using namespace std;

int gcd (int,int);
int recgcd(int);
vector<int> v;
int n;
int main()
{
	int temp,i;
	cin >> n;
	long int pro=1,output;
	for(i=0;i<n;i++)
	{
		cin >> temp;
		v.push_back(temp);
		pro=(pro*temp)%div;
	}
	if(n==1)
	{
		for(i=0;i<v[0]-1;i++)
		{
			//cout<<"hello1"<<endl;
			pro=(pro*v[0])%div;
		}
		cout<<pro<<endl;
	}
	else if(n==2)
	{
		temp=gcd(v[0],v[1]);
		//cout<<temp<<endl;
		output=pro;
		for(i=0;i<temp-1;i++)
		{
			output=(output*pro)%div;
		}
		cout<<output<<endl;
	}
	else
	{
		temp=recgcd(0);
		//cout<<temp<<endl;
		output=pro;
		for(i=0;i<temp-1;i++)
		{
			output=(output*pro)%div;
		}
		cout<<output<<endl;
	}
	return 0;
}

int gcd (int a,int b)
{
	if(a==0 && b==0)
		return -1;
	else if(a==0)
		return b;
	else if(b==0)
		return a;
	else
		return gcd(b%a,a);
}

int recgcd(int i)
{
	int temp;
	if(i<n-2)
	{
		temp=recgcd(i+1);
		if(temp==1)
			return 1;
		else
			return gcd(v[i],temp);
	}
	else
		return gcd(v[i],v[i+1]);
}