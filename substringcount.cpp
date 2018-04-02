#include <iostream>
#include <string>
using namespace std;
int main()
{
	int n,i;
	cin >> n;
	string s[n];
	for(i=0;i<n;i++)
	{
		cin>>s[i];
	}
	int q;
	cin >> q;
	while(q--)
	{
		int l,r,count=0;
		cin >> l >> r;
		string str;
		cin >> str;
		for(i=l-1;i<r;i++)
		{
			if(str.length()<=s[i].length())
			{
				string::size_type pos=s[i].find(str);
				if(pos<11)
				{
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}