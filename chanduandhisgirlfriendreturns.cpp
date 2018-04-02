#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
    	int n ,m;
    	cin >> n >> m;
    	int first[n],second[m],final[n+m],i,j,k;
    	for(i=0;i<n;i++)
    		cin >> first[i];
    	for(i=0;i<m;i++)
    		cin >> second[i];
   		i=0;j=0;k=0;
    	while(i<n && j<m)
    	{
    		if(first[i]>second[j])
    		{
    			final[k]=first[i];
    			k++;
    			i++;
    		}
    		else if(first[i]<second[j])
    		{
    			final[k]=second[j];
    			j++;
    			k++;
    		}
    		else
    		{
    			final[k]=first[i];
    			i++;
    			k++;
    			final[k]=second[j];
    			j++;
    			k++;
    		}
    	}
    	if(i<n)
    	{
            //cout << "hello" << endl;
    		for(;i<n;i++)
    		{
    			final[k]=first[i];
    			k++;
    		}
    	}
    	else if(j<m)
    	{
            //cout << "hello2" << endl;
    		for(;j<m;j++)
    		{
    			final[k]=second[j];
    			k++;
    		}
    	}
    	for(i=0;i<m+n;i++)
    	{
    		cout << final[i] <<" ";
    	}
    	cout << "\n";
    }
    return 0;
}
