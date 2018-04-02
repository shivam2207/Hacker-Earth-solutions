#include <bits/stdc++.h>
using namespace std;
#define sz 10000
typedef struct node
{
	int vertex;
	struct node *next;
}node;
void insert_edge(int u,int v);
void dfs(int);
void print_graph(int );
static int counter;
node *graph[sz+1];
bool visit[sz+1];
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		counter=1;
		int e,x,y,i,sum=0;
		for(i=0;i<=sz;i++)
		{
			graph[i]=NULL;
			visit[i]=false;
		}
		cin >> e;
		while(e--)
		{
			cin >> x >> y;
			insert_edge(x,y);
			insert_edge(y,x);
		}
		for(i=1;i<=sz;i++)
		{
			if(visit[i]==false)
			{
				dfs(i);
				if(counter>1)
					sum+=counter;
				counter=1;
			}
		}
		cout << sum << endl;
	}	
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
void dfs(int ver)
{
	node *p;
	p=graph[ver];
	visit[ver]=true;
	while(p!=NULL)
	{
		ver=p->vertex;
		if(!visit[ver])
		{
			counter++;
			dfs(ver);
		}
		p=p->next;
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