#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string reverse(string );
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,i,q;
		cin >> n >> q;
		string array[n],ans,revarray[n],temp;
		for(i=0;i<n;i++)
			cin >> array[i];
		for(i=0;i<n;i++)
		{
			revarray[i]=reverse(array[i]);
		}
		ans.append(array[0]);
		ans.append(revarray[0]);
		temp=ans;
		ans.append(array[1]);
		for(i=2;i<n;i++)
		{
			ans.append(revarray[i-1]);
			ans.append(temp);
			temp='\0';
			temp=ans;
			ans.append(array[i]);
		}
		while(q--)
		{
			int t;
			cin >> t;
			cout << ans[t];
		}
		cout << "\n";
		ans='\0';
	}
	return 0;
}

string reverse(string s)
{
	int i,j;
	j=s.size()-1;
	i=0;
	char temp;
	while(i<j)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
		i++;
		j--;
	}
	return s;
}