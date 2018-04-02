#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

ll tree[300000];
ll arr[200000];

void build(ll i, ll st, ll en)
{
	if(st == en)
	{
		tree[i] = arr[st]; // Leaf node will have a single element
	}
	else
	{
		ll mid = (st + en) / 2;
		build(2*i, st, mid);// Recurse on the left child
		build(2*i+1, mid+1, en);// Recurse on the right child
		tree[i] = tree[2*i] + tree[2*i+1];// Internal node will have the sum of both of its children
	}
}

void update(ll i, ll st, ll en, ll idx, ll val)
{
	if(st == en)// Leaf node
	{
		tree[i] = tree[i]-arr[idx]+val;
		arr[idx] = val;
	}
	else
	{
		ll mid = (st + en) / 2;
		if(st <= idx and idx <= mid)// If idx is in the left child, recurse on the left child
		{
			update(2*i, st, mid, idx, val);
		}
		else// if idx is in the right child, recurse on the right child
		{
			update(2*i+1, mid+1, en, idx, val);
		}
		tree[i] = tree[2*i] + tree[2*i+1];// Internal node will have the sum of both of its children
	}
}

ll query(ll i, ll st, ll en, ll l, ll r)
{
	if(r < st or en < l)// range represented by a node is completely outside the given range
	{
		return 0;
	}
	if(l <= st and en <= r)// range represented by a node is completely inside the given range
	{
		return tree[i];
	}
	// range represented by a node is partially inside and partially outside the given range
	ll mid = (st + en) / 2;
	ll p1 = query(2*i, st, mid, l, r);
	ll p2 = query(2*i+1, mid+1, en, l, r);
	return (p1 + p2);
}


int main()
{
	ll n;
	cin>>n;
	for(ll i=1;i<=n;i++)
	{
		ll g;
	   cin>>g;
	   arr[i]=g%2==0?1:0;
	}

	build(1,1,n);
	// for(i=1;i<=2*n+1;i++)
	// 	cout << tree[i]<<" ";
	// cout <<"\n";
// for(int k=1;k<=n;k++)
// 	cout << arr[k]<<" ";
// cout <<"\n";
for(int k=1;k<=15;k++)
	cout<<k<<" "<<tree[k]<<endl;

	ll t;
	cin>>t;

	while(t--)
	{
		int chk;
		cin>>chk;
		if(chk==1)
		{
			ll a,b;
			cin>>a>>b;
			cout<<query(1,1,n,a,b)<<endl;
		}
		else if(chk==0)
		{
			ll idx,val;
			cin>>idx;
			cin>>val;
			update(1,1,n,idx,val%2==0?1:0);
			for(int i=1;i<=2*n+1;i++)
				cout <<i<<" "<<tree[i]<<endl;
		}
		else
		{
			ll a,b;
			cin>>a>>b;
			cout<<b-a+(b!=a?1:0)-query(1,1,n,a,b)<<endl;
		}
	}
}