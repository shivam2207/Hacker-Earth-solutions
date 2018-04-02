#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
bool seive[10000001]={false};
int main()
{
	long int i,j;
	seive[0]=true;
	seive[1]=true;
	vector<long int> v;
	for(i=2;i*i<=10000001;i++)
	{
		if(seive[i]==false)
		{
			for(j=i*i;j<10000001;j+=i)
			{
				seive[j]=true;
			}
		}
	}
	/*for(i=2;i<10000001;i++)
	{
		if(seive[i]==false)
		{
			v.push_back(i);
		}
	}*/
	int n;
	cin >> n;
	while(n--)
	{
		long int x;
		cin >>x;

		if(x==1 || x==2 || x==3 || x==4)
			cout<<"NO"<<endl;

		else if(seive[x]==false)
			cout<<"NO"<<endl;

		else if(x%2==0)
			cout<<"YES"<<endl;

		else if(sqrt(x)*sqrt(x)==x)
			cout<<"NO"<<endl;

		else
			cout<<"YES"<<endl;
	}
	return 0;
}