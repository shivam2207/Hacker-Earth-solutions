#include <bits/stdc++.h>
using namespace std;
#define sz 100000
typedef struct node
{
	int vertex;
	struct node *next;
}node;
void insert_edge(int ,int );
void print_graph(int );
void bfs(int);
node *graph[sz+1]={NULL};
int color[sz+1];
int out[sz+1]={0};
int main()
{
	int n,c,i,t;
	cin >> n >> c;
	for(i=1;i<n;i++)
	{
		cin >> t;
		insert_edge(i+1,t);
	}
	for(i=1;i<=n;i++)
		cin >> color[i];
	for(i=1;i<=n;i++)
		bfs(i);
	for(i=1;i<=n;i++)
	{
		if(out[i]==0)
			out[i]=-1;
		cout << out[i]<<" ";
	}
	cout<<"\n";
	return 0;
}
void insert_edge(int u,int v)
{
	node *p,*q;
	q=(node*)malloc(sizeof(node));
	q->vertex=v;
	q->next=NULL;
	if(graph[u]==NULL)
		graph[u]=q;
	else
	{
		p=graph[u];
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=q;
	}
	return;
}
void print_graph(int ver)
{
	node *p;
	p=graph[ver];
	cout << ver<<"->"<<" ";
	while(p!=NULL)
	{
		cout << p->vertex <<" ";
		p=p->next;
	}
	cout<<"\n";
	return;
}

void bfs(int ver)
{
	int v;
	node *p;
	queue <int> q;
	q.push(ver);
	while(!q.empty())
	{
		v=q.front();
		q.pop();
		for(p=graph[v];p!=NULL;p=p->next)
		{
			v=p->vertex;
			if(color[ver]==color[v])
			{	
				out[ver]=v;
				return;
			}
			q.push(v);
		}
	}
	return ;
}