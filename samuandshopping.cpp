#include <iostream>
#include <string.h>
using namespace std;

long int func(int,int);
long int min(long int,long int);

int cost[100000][3],n;
long int table[100000][3];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int i;
		long int ans1,ans2,ans3;
		cin>>n;
		memset(table,0,sizeof(table));
		for(i=0;i<n;i++)
		{
			cin>>cost[i][0]>>cost[i][1]>>cost[i][2];
		}
		ans1=func(0,0);
		ans2=func(0,1);
		ans3=func(0,2);
		ans1=min(ans1,ans2);
		ans1=min(ans1,ans3);
		cout<<ans1<<endl;
	}
	return 0;
}

long int func(int i,int j)
{
	if(i>=n)
		return 0;
	else if(table[i][j]!=0)
		return table[i][j];
	else
	{
		//int temp1=1000000,temp2=1000000,temp3=1000000,temp4=1000000,temp5=1000000,temp6=1000000;
		int temp1,temp2;
		if(j==0)
		{
			temp1=cost[i][0]+func(i+1,1);
			temp2=cost[i][0]+func(i+1,2);
			//temp3=min(temp1,temp2);
		}
		else if(j==1)
		{
			temp1=cost[i][1]+func(i+1,0);
			temp2=cost[i][1]+func(i+1,2);
			//temp4=min(temp1,temp2);
		}
		else
		{
			temp1=cost[i][2]+func(i+1,0);
			temp2=cost[i][2]+func(i+1,1);
			//temp5=min(temp1,temp2);
		}
		temp1=min(temp1,temp2);
		table[i][j]=temp1;
		//cout<<temp1<<" "<<temp2<<" "<<temp3<<" "<<temp4<<" "<<temp5<<" "<<temp6<<endl;
		//temp1=min(temp1,temp2);
		//temp3=min(temp3,temp4);
		//temp5=min(temp5,temp6);
		//temp1=min(temp1,temp3);
		//temp1=min(temp1,temp5);
		return temp1;
	}
}

long int min(long int a,long int b)
{
	if(a>=b)
		return b;
	else
		return a;
}