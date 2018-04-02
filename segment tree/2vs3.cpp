#include <bits/stdc++.h>
using namespace std;
#define sz 100005
int tree[4*sz];
int arr[sz];
int power[sz];
void fastpower(void)
{
	power[0]=1;
	for(int i=1;i<sz;i++)
		power[i]=(power[i-1]*2)%3;
}
void build(int node,int start,int end)
{
	if(start==end)
	{
		tree[node]=arr[start];
	}
	else
	{
		int mid=(start+end)/2;
		build(2*node,start,mid);
		build(2*node+1,mid+1,end);
		tree[node]=((tree[2*node]*power[end-mid])%3+tree[2*node+1])%3;
	}
}
void update(int node,int start,int end,int idx)
{
	if(start==end)
	{
		tree[node]=1;
		arr[idx]=1;
	}
	else
	{
		int mid=(start+end)/2;
		if(start<=idx && idx<=mid)
			update(2*node,start,mid,idx);
		else
			update(2*node+1,mid+1,end,idx);
		tree[node]=((tree[2*node]*power[end-mid])%3+tree[2*node+1])%3;
	}
}
int query(int node,int start,int end,int l,int r)
{
	if(r<start || l>end)
		return 0;
	if(l<=start && end<=r)
		return tree[node]*power[r-end]%3;
	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r);
	int p2=query(2*node+1,mid+1,end,l,r);
	return (p1+p2)%3;
}
int main()
{
	int n,i,t;
	cin >> n;
	string s;
	cin >> s;
	fastpower();
	for(i=0;i<n;i++)
	{
		arr[i+1]=s[i]-48;
	}
	build(1,1,n);
	cin >> t;
	while(t--)
	{
		int choice;
		cin >> choice;
		if(choice==0)
		{
			int l,r;
			cin >> l >> r;
			cout << query(1,1,n,l+1,r+1)<<endl;
		}
		else
		{
			int l;
			cin >> l;
			if(s[l]=='0')
			{
				s[l]=1;
				arr[l+1]=1;
				update(1,1,n,l+1);
			}
		}
	}
	return 0;
}