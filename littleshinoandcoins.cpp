#include <bits/stdc++.h>
using namespace std;
set <char> st;
int main()
{
	int k;
	cin >> k;
	string s;
	cin >> s;
	int i,n=s.size(),total=0,j,p1,p2,flag;
	for(i=0;i<=n-k;i++)
	{
		st.clear();
		flag=0;
		p1=-1;
		p2=-1;
		for(j=i;j<n;j++)
		{
			st.insert(s[j]);
			if((int)st.size()==k)
			{
				if(flag==0)
				{
					p1=j;
					flag=1;
				}
				p2=j;
				//p1=min(p1,j);
				//total+=n-j;
				//break;
			}
			if((int)st.size()>k)
			{
				//p2=j-1;
				break;
			}
		}
		if(!(p1==-1 && p2==-1))
		{
			//cout<<p2-p1+1<<endl;
			total+=p2-p1+1;
		}
	}
	cout << total << endl;
	return 0;
}