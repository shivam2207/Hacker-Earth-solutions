#include <bits/stdc++.h>
using namespace std;
set <int> visit;
int tree[1000000],n;

void left_view(int vertex,int level,int *max_level)
{
	if(vertex >n || tree[vertex]==0 )
		return;
	//cout <<"ver:"<< vertex << endl;
	if(*max_level < level)
	{
		auto it = visit.find(vertex);
		if(it==visit.end())
		{
			cout << tree[vertex]<<endl;
			visit.insert(vertex);
			*max_level = level;
		}
	}
	left_view(vertex*2,level+1,max_level);
	left_view(vertex*2+1,level+1,max_level);
}

void right_view(int vertex,int level,int *max_level)
{
	if(vertex >n || tree[vertex]==0 )
		return;
	//cout <<"ver:"<< vertex << endl;
	if(*max_level < level)
	{
		auto it = visit.find(vertex);
		if(it==visit.end())
		{
			cout << tree[vertex]<<endl;
			visit.insert(vertex);
			*max_level = level;
		}
	}
	right_view(vertex*2+1,level+1,max_level);
	right_view(vertex*2,level+1,max_level);
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		visit.clear();
		memset(tree,0,sizeof(tree));
		cin >> n;
		int i,max_level=0;
		for(i=1;i<=n;i++)
			cin >> tree[i];
		right_view(1,1,&max_level);
		max_level = 0;
		left_view(1,1,&max_level);
	}
	return 0;
}