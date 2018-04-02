#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
typedef struct node
{
	struct node *next;
	int vertex;
}node;
node *g[100001];
static int j;
int visit[100001];
int n,c;
void readgraph(void);
void insert(int,int);
void dfs(int);
void print_graph(int );
int main()
{
	int i;
	cout <<"Enter number of nodes"<<endl;
	scanf("%d",&n);
	readgraph();
	j=1;
	for(i=0;i<n;i++)
		visit[i]=0;
	for(i=0;i<n;i++)
	{
		if(visit[i]==0)
		{
			dfs(i);
		}
	}
	cout << j << endl;
	// for(i=0;i<n;i++)
	// 	print_graph(i);
	return 0;
}
void dfs(int i)
{
	node *p;
	p=g[i];
	visit[i]=1;
	while(p!=NULL)
	{
		i=p->vertex;
		if(!visit[i])
		{
			j++;
			dfs(i);
		}
		p=p->next;
	}
}

void readgraph(void)
{
	int i,u,v;
	for(i=0;i<n;i++)
		g[i]=NULL;
	cout << "Enter number of edges" << endl;  
	scanf("%d",&c);
	for(i=0;i<c;i++)
	{
		scanf("%d %d",&u,&v);
		insert(u,v);
		insert(v,u);
	}
	return ;
}

void insert(int u,int v)
{
	node *p,*q;
	q=(node *)malloc(sizeof(node));
	q->vertex=v;
	q->next=NULL;
	if(g[u]==NULL)
	{
		g[u]=q;
	}
	else
	{
		p=g[u];
		while(p->next!=NULL)
		{
			p=p->next;
		}
		p->next=q;
	}
}
void print_graph(int ver)
{
	node *p;
	p=g[ver];
	cout<<ver<<"->"<<" ";
	while(p!=NULL)
	{
		cout<<p->vertex<<" ";
		p=p->next;
	}
	cout<<"\n";
	return;
}