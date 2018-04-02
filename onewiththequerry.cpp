#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <array>
using namespace std;
array <vector<int>,26> v;
int main()
{
	string s;
	cin >> s;
	int i,temp;
	for(i=0;i<(int)s.size();i++)
	{
		temp=s[i]-'a';
		v[temp].push_back(i);
	}
	int q;
	cin >> q;
	while(q--)
	{
		string t;
		cin >> t;
		int index0=0,index1=0,index2=0,index3=0,index4=0,index5=0,index6=0,index7=0,index8=0,
	}
	return 0;
}
