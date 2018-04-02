#include <bits/stdc++.h>
using namespace std;
long long int gcd(long long int a,long long int b)
{
	if(b==0)
		return a;
	else
		return gcd(b,a%b);
}
int main()
{
	// int t;
	// cin >> t;
	// while(t--)
	// {
		ios_base::sync_with_stdio(false);
		long long int cnt=0,total=0,a,b,c,d,e,f,g;
		int n,m,i,j,k,l;
		cin >> n >> m;
		string str[n];
		vector <int> vec[n];
		bool table[n][m];
		memset(table,false,sizeof(table));
		for(i=0;i<n;i++)
			cin >> str[i];
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(str[i][j]=='0')
					vec[i].push_back(j);
			}
		}
		set <pair<int,int>> st;
		pair <int,int> p,q;
		for(i=0;i<n-1;i++)
		{
			for(j=0;j<(int)vec[i].size()-1;j++)
			{
				for(k=j+1;k<(int)vec[i].size();k++)
				{
					cnt=0;
					q=make_pair(vec[i][j],vec[i][k]);
					if(st.find(q)==st.end())
					//if(table[vec[i][j]][vec[i][k]]==false)
					{
						for(l=i+1;l<n;l++)
						{
							if(str[l][vec[i][j]]=='0' && str[l][vec[i][k]]=='0')
								cnt++;
						}
						p=make_pair(vec[i][j],vec[i][k]);
						st.insert(p);
						// table[vec[i][j]][vec[i][j]]=true;
						total+=(cnt)*(cnt+1)/2;
					}
				}
			}
		}
	//	cout << total << endl;
		if(total==0)
			cout << "1 1" <<endl;
		else
		{
			a=5;
			b=6*total;
			c=total-1;
			d=total;
			e=a*d+b*c;
			f=b*d;
			g=gcd(e,f);
			cout << e/g <<" "<< f/g << endl;
		}
	// }
	return 0;
}