#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int prime [100001]={0},i,j;
	for(i=2;i*i<100001;i++)
	{
		if(prime[i]==0)
		{
			for (int j = i*i; j < 100001; j+=i)
			{
				prime[j]=1;
			}
		}
	}
	vector<int> v;
	for(i=2;i<100001;i++)
	{
		if(prime[i]==0)
		{
			v.push_back(i);
		}
	}
	while(t--)
	{
		int n;
		cin >> n;
		//auto jj=v.cend();
		//auto ii=v.cbegin();
		i=0;
		j=v.size()-1;
		//cout<<j<<endl;
		while(i<j)
		{
			//cout<<v[i]<<endl;
			if(v[i]+v[j]==n || 2*v[i]==n || 2*v[j]==n)
			{
				cout<<"Deepa"<<endl;
				break;
			}
			else if(v[i]+v[j]>n)
			{
				j--;
			}
			else
			{
				i++;
			}
		}
		if(i>=j)
			cout<<"Arjit"<<endl;
	}
	return 0;
}