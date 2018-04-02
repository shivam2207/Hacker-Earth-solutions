#include <bits/stdc++.h>
using namespace std;
#define sz 2*10000
typedef struct node
{
	int vertex;
	struct node *next;
}node;
void insert_edge(int u,int v);
void dfs(int);
void bfs(int);
void print_graph(int );
void print_set(void);
node *graph[sz+1];
bool visit[sz+1];
unordered_set <int> temp1,temp2;
unordered_set <int> ::const_iterator it;
int main()
{
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t,t1=1;
	//cin >> t;
	scanf("%d",&t);
	while(t1<=t)
	{
		int n,i,e,maxx=0,ans=0,x,y;
		scanf("%d",&n);
		//cin >> n ;
		e=n;
		for(i=0;i<=sz;i++)
		{
			graph[i]=NULL;
			visit[i]=false;
		}
		while(e--)
		{
			//cin >> x >> y;
			scanf("%d %d",&x,&y);
			insert_edge(x,y);
			insert_edge(y,x);
			maxx=max(maxx,x);
			maxx=max(maxx,y);
		}
		// for(i=1;i<=maxx;i++)
		// 	print_graph(i);
		for(i=1;i<=maxx;i++)
		{
			if(visit[i]==false && graph[i]!=NULL)
			{
				//cout <<"Hello"<<endl;
				ans+=max(temp1.size(),temp2.size());
				temp1.clear();
				temp2.clear();
				//cout <<"temp1="<<i<<endl;
				temp1.insert(i);
				bfs(i);
			}
		}
		ans+=max(temp1.size(),temp2.size());
		//cout <<"Case "<<t1<<": ";
		//cout << ans << endl;
		printf("Case %d: ",t1);
		printf("%d\n",ans);
		temp1.clear();
		temp2.clear();
		t1++;
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
		graph[u]=q;
		q->next=p;
		// while(p->next!=NULL)
		// {
		// 	p=p->next;
		// }
		// p->next=q;
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
void bfs(int ver)
{
	bool temp1flag;
	node *p;
	queue <int> q;
	q.push(ver);
	visit[ver]=true;
	while(!q.empty())
	{
		ver=q.front();
		q.pop();
		//cout << "ver="<<ver<<endl;
		if(temp1.count(ver))
		{
			//temp2flag=false;
			temp1flag=true;
		}
		else
		{
			temp1flag=false;
			//temp2flag=true;
		}
		for(p=graph[ver];p!=NULL;p=p->next)
		{
			ver=p->vertex;
			if(!visit[ver])
			{
				if(temp1flag)
				{
					//cout <<"temp2="<<ver<<endl;
					temp2.insert(ver);
				}
				else
				{
					//cout <<"temp1="<<ver<<endl;
					temp1.insert(ver);
				}
				q.push(ver);
				visit[ver]=true;
			}
		}
		//cout <<"Hello"<<endl;
		temp1flag=false;
		//temp2flag=false;
	}
	//print_set();
	return ;
}
void print_set(void)
{
	cout <<"NEW"<<endl;
	cout << "Set A" << endl;
	for(it=temp1.begin();it!=temp1.end();it++)
		cout << *it<< " ";
	cout <<"\n";
	cout << "Set B" << endl;
	for(it=temp2.begin();it!=temp2.end();it++)
		cout << *it<< " ";
	cout<<"\n\n";
}