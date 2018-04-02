#include <bits/stdc++.h>
using namespace std;
#define sz 1000000
int main()
{
	int count[sz+1]={0},n,m,i,sum=0;
	//int arr[sz+1]={0};
	int table[sz+1]={0};
	cin >> n >> m;
	while(m--)
	{
		int l,r;
		cin >> l >>r;
		count[l]++;
		count[r+1]--;
	}
	for(i=1;i<=n;i++)
	{
		sum+=count[i];
		//arr[i]=sum;
		table[sum]++;
	}
	for(i=1;i<=sz;i++)
		table[i]+=table[i-1];
	int q;
	cin >> q;
	while(q--)
	{
		int x;
		cin >> x;
		if(x==0)
			cout << "0" << endl;
		else
		{
			cout<<n-table[x-1]<<endl;
		}
	}
	return 0;
}