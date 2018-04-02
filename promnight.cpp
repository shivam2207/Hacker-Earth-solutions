#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n,i,j=0;
		cin>>m>>n;
		int boyheight[m],girlheight[n];
		for(i=0;i<m;i++)
			cin>>boyheight[i];
		for (i = 0; i < n; ++i)
			cin>>girlheight[i];
		if(m>n)
			cout<<"NO"<<endl;
		else
		{
			sort(boyheight,boyheight+m);
			sort(girlheight,girlheight+n);
			i=0;
			while(i<m && j<n)
			{
				while(boyheight[i]<=girlheight[j] && j<n)
					j++;
				if(boyheight[i]>girlheight[j] && j<n)
				{
					i++;
					j++;
				}
			}
			if(i==m)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}