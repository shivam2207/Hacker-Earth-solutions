#include <bits/stdc++.h>
using namespace std;
int func(string,int);
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,k;
		cin >> n >> k;
		string s;
		cin >> s;
		cout <<func(s,k)<<endl;
	}
	return 0;
}
int func(string s,int k)
{
	char c;
	int count,i,n=s.size(),j,l,max_val=INT_MIN;
	for(c='a';c<='z';c++)
	{
		i=0;
		j=-1;
		l=0;
		count=0;
		//cout << c << endl;
		while(i<n)
		{
			if(s[i]==c)
			{
				i++;
				count++;
			}
			else if(s[i]!=c)
			{
				if(j==-1)
					j=i;
				l++;
				i++;
				count++;
			}
			if(l>k)
			{
				//cout << count << endl;
				count--;
				max_val=max(max_val,count);
				l=0;
				i=j+1;
				j=-1;
				count=0;
			}
		}
		max_val=max(max_val,count);
		//cout << max_val << endl;
	}
	return max_val;
}