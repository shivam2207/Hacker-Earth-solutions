#include <iostream>
#include <string>
#include <algorithm>
#include <array>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string w,r;
		cin >> w >> r;
		sort(r.begin(),r.end());
		int i=0,j=0,m,n;

		n=w.length();
		m=r.length();
		while(i<n && j<m)
		{
			if(w[i]>r[j])
			{
				w[i]=r[j];
				i++;
				j++;
			}
			else
			{
				i++;
			}
		}
		cout<<w<<endl;
	}
	return 0;
}