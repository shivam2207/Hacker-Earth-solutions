#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int t;
	cin >>t;
	while(t--)
	{
		char s[1000000];
		cin>>s;
		long int length=strlen(s),i,j,count1,count2,count3=0,max=-100;

		for(i=0;i<length;i++)
		{
			if(s[i]=='R')
				count3++;
			count1=0;
			count2=0;
			for(j=i;j<length;j++)
			{

				if(s[j]=='R')
					count1++;
				else
					count2++;
				if(count2-count1>max)
					max=count2-count1;

			}
			/*if((count2-count1)>max)
				max=count2-count1;
			else
				max=max;*/
		}
		//cout<<count3<<" "<<max<<endl;
		cout<<count3+max<<endl;
	}
	return 0;
}