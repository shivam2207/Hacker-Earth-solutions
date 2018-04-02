#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
typedef struct data
{
	int f;
	int index;
}data;
bool compare(data a,data b)
{
	return a.f<b.f;
}
int main()
{
	int n,m;
	cin >> n >> m;
	int a[n],i,j;
	vector <int> v;
	int map[m+n],pmap[n];
	memset(map,0,sizeof(map));
	memset(pmap,0,sizeof(pmap));
	for(i=0;i<n;i++)
		cin >> a[i];
	data array[n+m-1];
	for(i=0;i<n+m+-1;i++)
	{
		cin >> array[i].f;
		array[i].index=i;
	}
	sort(array,array+n+m-1,compare);
	//sort(a,a+n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<m+n-1;j++)
		{
			if(a[i]<=array[j].index && map[array[j].index]==0 && pmap[array[j].index-a[i]]==0)
			{
				map[array[j].index]=1;
				pmap[array[j].index-a[i]]=1;
				v.push_back(array[j].f);
				break;
			}
		}
	}
	//cout<<array[j].f<<endl;
	cout<<*max_element(v.begin(),v.end())<<endl;
	return 0;
}