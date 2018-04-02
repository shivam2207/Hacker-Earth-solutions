#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,temp,j,i;
		cin >> n;
		long long array[10]={0};
		for(i=1;i<=n;i++)
		{
			string s=to_string(i);
			for(j=0;j<(int)s.size();j++)
			{
				temp=s[j]-'0';
				array[temp]++;
			}
		}
		for(i=0;i<10;i++)
			cout << array[i] << " ";
		cout<<"\n";
	}
	return 0;
}