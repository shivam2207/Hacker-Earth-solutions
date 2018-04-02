#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,p,k,i,count=0,j=0,count1;
		cin >> n >> k >> p;
		int array[k+1];
		for(i=1;i<=k;i++)
		{
			cin >> array[i];
			if(array[i]<=p)
				count++;
		}
		//cout << "hello0" << endl;
		//sort(array+1,array+k+1);
		if(count==0)
		{
			cout << p << endl;
		}
		else
		{	
			count1=array[count]-count;
			j=count+1;
			//cout << "hello1" << endl;
			if((n-k)<p)
				cout<<"-1"<<endl;
			else
			{
				for(i=array[count]+1;i<=n;i++)
				{
					//cout << "hello2" << endl;
					if(j<=k && i==array[j])
					{
						j++;
					}
					else
					{
						count1++;
						if(count1==p)
						{
							break;
						}
					}
				}
				cout << i << endl;
			}
		}
	}
	return 0;
}