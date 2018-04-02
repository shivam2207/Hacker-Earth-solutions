#include <bits/stdc++.h>
using namespace std;
int tree[4*100005];
int arr[100005];
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
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
void update(int node,int start,int end,int idx,int val)
{
	if(start==end)
	{
		tree[node]=tree[node]-arr[idx]+val;
		arr[idx]=val;
	}
	else
	{
		int mid=(start+end)/2;
		if(start<=idx && idx<=mid)
			update(2*node,start,mid,idx,val);
		else
			update(2*node+1,mid+1,end,idx,val);
		tree[node]=tree[2*node]+tree[2*node+1];
	}
}
int query(int node,int start,int end,int l,int r)
{
	if(r<start || l>end)
		return 0;
	if(l<=start && end<=r)
		return tree[node];
	int mid=(start+end)/2;
	int p1=query(2*node,start,mid,l,r);
	int p2=query(2*node+1,mid+1,end,l,r);
	return p1+p2;
}
int main()
{
	int n,i,t;
	cin >> n;
	for(i=1;i<=n;i++)
	{
		cin >> t;
		arr[i]=t%2==0?1:0;
	}
	build(1,1,n);
	cin >> t;
	while(t--)
	{
		int choice;
		cin >> choice;
		{
			if(choice==0)
			{
				int idx,val;
				cin >> idx >> val;
				update(1,1,n,idx,val%2==0?1:0);
			}
			else if(choice==1)
			{
				int l,r;
				cin >> l >> r;
				cout << query(1,1,n,l,r)<<endl;
			}
			else
			{
				int l,r,temp;
				cin >> l >> r;
				temp=query(1,1,n,l,r);
				cout<<(r-l+1)-temp<<endl;
			}
		}
	}
	return 0;
}