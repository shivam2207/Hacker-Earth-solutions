#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	long int q;
	cin >> q;
	cout<<s.size()<<endl;
	while(q--)
	{
		long int count=0,l,r,i,j;
		int array[7]={0};
		cin >> l>> r;
		if(r-l+1<11)
		{
			cout<<"0"<<endl;
		}
		else if(r-l+1==11)
		{
			for(i=l-1;i<=r-1;i++)
			{
				if(s[i]=='a' || s[i]=='A')
				{
					array[0]++;
				}
				else if(s[i]=='c' || s[i]=='C')
				{
					array[1]++;
				}
				else if(s[i]=='e' || s[i]=='E')
				{
					array[2]++;
				}
				else if(s[i]=='h' || s[i]=='H')
				{
					array[3]++;
				}
				else if(s[i]=='k' || s[i]=='K')
				{
					array[4]++;
				}
				else if(s[i]=='r' || s[i]=='R')
				{
					array[5]++;
				}
				else if(s[i]=='t' || s[i]=='T')
				{
					array[6]++;
				}
			}
			if(array[0]==2 && array[1]==1 && array[2]==2 && array[3]==2 && array[4]==1 && array[5]==2 && array[6]==1)
			{
				cout<<1<<endl;
			}
			else
			{
				cout<<0<<endl;
			}
		}
		else
		{
			j=r-l+1;
			while(j>=11)
			{
				memset(array,0,sizeof(array));
				for(i=l-1;i<l+10;i++)
				{
					if(s[i]=='a' || s[i]=='A')
					{
						array[0]++;
					}
					else if(s[i]=='c' || s[i]=='C')
					{
						array[1]++;
					}
					else if(s[i]=='e' || s[i]=='E')
					{
						array[2]++;
					}
					else if(s[i]=='h' || s[i]=='H')
					{
						array[3]++;
					}
					else if(s[i]=='k' || s[i]=='K')
					{
						array[4]++;
					}
					else if(s[i]=='r' || s[i]=='R')
					{
						array[5]++;
					}
					else if(s[i]=='t' || s[i]=='T')
					{
						array[6]++;
					}
					//cout<<"a"<<endl;		
				}
				if(array[0]==2 && array[1]==1 && array[2]==2 && array[3]==2 && array[4]==1 && array[5]==2 && array[6]==1)
				{
					count++;
				}
				j--;
				l++;
			}
			cout<<count<<endl;
		}
	}
	return 0;
}