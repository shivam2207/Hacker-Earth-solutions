#include <iostream>
//#include <string.h>
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
		if(s.size()>=10)
		{
			cout<<"YES"<<endl;
		}
		else if(s.size()<4)
		{
			cout<<"NO"<<endl;
		}
		else if(s.size()==4)
		{
			if(s[0]==s[1] || s[0]==s[2] || s[0]==s[3] || s[1]==s[2] || s[1]==s[3] || s[2]==s[3])
				cout<<"NO"<<endl;
			else
				cout<<"YES"<<endl;
		}
		else
		{
			int i,j,k,flag=0;
			string sub1,sub2,sub3,sub4;
			for(i=1;i<int (s.length());i++)
			{
				for(j=i+1;j<int(s.length());j++)
				{
					for (k = j+1; k< int(s.length()); k++)
					{
						//for(l=1;l<int(s.length());l++)
						//{
							sub1=s.substr(0,i);
							sub2=s.substr(i,j-i);
							sub3=s.substr(j,k-j);
							sub4=s.substr(k,int(s.size())-k);
							if(sub1!=sub2 && sub1!=sub3 && sub1!=sub4 && sub2!=sub3 && sub2!=sub4 && sub3!=sub4)
							{
								flag=1;
								break;
							}
						//}
						if(flag==1)
							break;
					}
					if(flag==1)
						break;
				}
				if(flag==1)
					break;
			}
			if(flag==1)
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}