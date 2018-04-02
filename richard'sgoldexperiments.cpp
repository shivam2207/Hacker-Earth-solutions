#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
int main()
{
	ios_base::sync_with_stdio(false);
	int n,m,k;
	cin >> n >> m >> k;
	int arr[n],i,hash[1001]={0},cnt,neghash[1001]={0},freq[1001]={0},maxx=0,minn,left,sum=0,temp=0;
	long long int total=0;
	for(i=0;i<n;i++)
	{
		cin >> arr[i];
		maxx=max(arr[i],maxx);
		hash[arr[i]]++;
	}
	for(i=1;i<=maxx;i++)
	{
		if(hash[i])
		{
			cnt=(i/k);
			if(i%k!=0)
			{
				cnt+=1;
				freq[i]=cnt;
				neghash[k-i%k]++;
			}
			else
			{
				freq[i]=cnt;
				neghash[0]++;
			}
		}
	}
	if(freq[maxx]>=m)
	{
		for(i=1;i<=maxx;i++)
		{
			if(hash[i])
			{
				minn=min(freq[i],m);
				cnt=minn*(2*i+(minn-1)*-k)/2;
				total+=cnt*hash[i];
				total=(total%mod+mod)%mod;
			}
		}
	}
	else
	{
		for(i=1;i<=maxx;i++)
		{
			if(hash[i])
			{
				cnt=freq[i]*(2*i+(freq[i]-1)*-k)/2;
				total+=cnt*hash[i];
				//total=(total%mod+mod)%mod;
			}
		}
		// cout<<total<<endl;
		for(i=0;i<k;i++)
			sum+=neghash[i];
		left=(m-freq[maxx]);
		// cout<<"left: "<<left<<" sum: "<<sum<<endl;
		temp=left%sum;
		for(i=0;i<k;i++)
		{
			if(neghash[i])
			{
				if(neghash[i]<=temp)
				{
					cnt=((left/sum)+1)*(2*i+(left/sum)*k)/2;
					cnt=cnt*neghash[i];
					total-=cnt;
					temp-=neghash[i];
					//total=(total%mod+mod)%mod;
				}
				else
				{
					cnt=((left/sum)+1)*(2*i+(left/sum)*k)/2;
					cnt=cnt*temp;
					total-=cnt;
					cnt=((left/sum))*(2*i+(left/sum-1)*k)/2;
					cnt=cnt*(neghash[i]-temp);
					temp=0;
					total-=cnt;
					//total=(total%mod+mod)%mod;
				}
			}
		}
	}
	cout << (total%mod+mod)%mod << endl;
	return 0;
}