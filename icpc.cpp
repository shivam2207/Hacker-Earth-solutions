#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main()
{
	int t;
	cin >>t;
	char array[1000][100];
	while(t--)
	{
		int n,k,i,flag=0;
		cin>>n>>k;
		int length[n],length1[101]={0};
		//memset(length1,0,sizeof(length1));
		for(i=0;i<n;i++)
		{
			cin>>array[i];
			length[i]=strlen(array[i]);
			length1[length[i]]++;
		}
		if(k>n)
		{
			cout<<"Not possible"<<endl;
		}
		else
		{
			for(i=0;i<101;i++)
			{
				if(length1[i]!=0)
				{
					if(length1[i]%k!=0)
					{
						flag=1;
						break;
					}
				}
			}
			if(flag==1)
				cout<<"Not possible"<<endl;
			else
				cout<<"Possible"<<endl;
		}
		//sort(length,length+n);

		//for(i=0;i<n;i++)
		//	cout<<length[i]<<endl;
	}
	return 0;
}