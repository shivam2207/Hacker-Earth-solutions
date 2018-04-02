#include <iostream>
#include <algorithm>
#include <stack>
#include <string>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		stack <char> st;
		int i=0,count=0;
		while(i<(int)s.size())
		{
			if(s[i]=='W')
			{
				st.push('W');
			}
			else if(s[i]=='B')
			{
				if(!st.empty())
				{
					st.pop();
					count++;
				}
				if(!st.empty())
				{
					st.pop();
					count++;
				}
				if(s[i+1]=='W')
				{
					i++;
					count++;
				}
				if(s[i+1]=='W')
				{
					i++;
					count++;
				}
			}
			i++;
		}
		cout << count << endl;
	}
	return 0;
}