#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct data
{
	int count;
	char ch;
	int index;
}data;
bool compare(data a,data b)
{
 	return a.count<=b.count;
}
void swapdata(data *a,data *b)
{
	data temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s;
		cin >> s;
		int n=s.size(),i,j,temp;
		data array[26];
		for(i=0;i<26;i++)
		{
			array[i].count=0;
			array[i].index=i;
			array[i].ch=(char)i+97;
		}
		for(i=0;i<n;i++)
		{
			temp=s[i]-'a';
			array[temp].count++;
		}
		// sort(array,array+26,compare);
		for(i=0;i<26;i++)
		{
			cout<<array[i].ch<<" ";
		}
		cout << "\n";
		for(i=0;i<25;i++)
		{
			for(j=0;j<25-i;j++)
			{
				if(array[j].count>=array[j+1].count)
				{
					swapdata(&array[j],&array[j+1]);
				}
			}
		}
		for(i=0;i<26;i++)
		{
			cout<<array[i].ch<<" ";
		}
		cout << "\n";
	}
	return 0;
}