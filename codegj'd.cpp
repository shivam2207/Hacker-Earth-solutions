#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
bool func(long int i,long int j)
{
	return (i>j);
}
int main()
{
	int t,i;
	cin>>t;
	while(t--)
	{
		long int n,temp,count1,count2;
		cin >> n;
		vector <long int>v;
		for(i=0;i<n;i++)
		{
			cin >> temp;
			v.push_back(temp);
		}
		if(v.size()==1)
		{
			cout<<0<<endl;
		}
		else
		{
			sort(v.begin(),v.end(),func);
			count1=v[0]+v[1];
			count2=count1;
			for(i=2;i<n;i++)
			{
				count1+=v[i];
				//cout<<count1<<endl;
				count2+=count1;
			}
			cout<<count2<<endl;
		}
	}
	return 0;
}