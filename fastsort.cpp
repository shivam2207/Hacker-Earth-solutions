#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
using namespace std;
typedef struct node 
{
	int count;
	int order;
	int sequence;
	char data;
}node;
bool mycomp (node a,node b)
{
	return (a.sequence<b.sequence);
}
bool mycomp2(node a,node b)
{
	return (a.order<b.order);
}
int main()
{
	int t;
	cin >> t;
	//string pattern,input;
	//cin >> pattern;
	//cin >> input;
	while(t--)
	{
		string pattern,input;
		cin >> pattern;
		cin >> input;
		int i,pos,j;
		node array[26];
		for(i=0;i<26;i++)
		{
			array[i].data=pattern[i];
			array[i].order=i;
			array[i].count=0;
			array[i].sequence=pattern[i]-'a';
		}
		//cout<<"hello1"<<endl;
		sort(array,array+26,mycomp);

		for(i=0;i<(int)input.size();i++)
		{
			pos=input[i]-'a';
			array[pos].count++;
		}
		//cout<<"hello2"<<endl;
		sort(array,array+26,mycomp2);
		for(i=0;i<26;i++)
		{
			j=0;
			while(j<array[i].count)
			{
				cout<<array[i].data;
				j++;
			}
		}
		cout<<"\n";
	}
	return 0;
}