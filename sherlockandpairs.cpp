#include <iostream>
#include <map>
map<int,int>mymap;
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		mymap.clear();
		int n,i,temp,count=0;
		cin >> n;
		map<int,int>:: iterator it;
		for(i=0;i<n;i++)
		{
			cin>> temp;
			mymap[temp]++;
		}
		for(it=mymap.begin();it!=mymap.end();it++)
		{
			count+=it->second;
		}
		cout<<count<<endl;
	}	
	return 0;	
}