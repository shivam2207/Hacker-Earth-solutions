#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int binary_search_left(int *,int,int,int);
int binary_search_right(int *,int,int,int);
int n;
int main()
{
	int q;
	cin >> n;
	int array[n],i;
	for(i=0;i<n;i++)
		cin >> array[i];
	sort(array,array+n);
	cin >> q;
	for(i=0;i<n;i++)
		cout <<  array[i] << " ";
	cout <<"\n";
	while(q--)
	{
		int l,r,pos_l=-1,pos_r=-1;
		cin >> l >> r;
		if(array[n-1]<l)
			cout << "0" << endl;
		else
		{
			pos_l=binary_search_left(array,l,0,n-1);
		//cout << pos_l << endl;
			pos_r=binary_search_right(array,r,0,n-1);
		//cout << pos_r << endl;
		//cout << pos_l << " " << pos_r << endl;
		
		//else
			cout << pos_r-pos_l+1 << endl;
		}
	}
	return 0;
}
int binary_search_left(int array[],int l,int start,int end)
{
	if(start==end)
	{
		if(array[start]==l)
			return start;
		if(array[start]<l)
			return start+1;
		else
			return start;
	}
	else
	{
		int mid=(start+end)/2;
		if(array[mid]==l)
		{
			//cout << "hello1" << endl;
			//return binary_search_left(array,l,start,mid);
			int i=mid;
			while(i>=0 && array[i]==l)
			{
				i--;
			}
			if(i<0)
				return i+1;
			else
			{
				if(array[i]==l)
					return i;
				else
					return i+1;
			}
		}
		else if(array[mid]<l)
		{
			//cout << "hello2" << endl;
			return binary_search_left(array,l,mid+1,end);
		}
		else
		{
			//cout << "hello3" << endl;
			return binary_search_left(array,l,start,mid-1);
		}
	}
}
int binary_search_right(int array[],int l,int start,int end)
{
	if(start==end)
	{
		if(array[start]==l)
			return start;
		else 
		{
			if(array[start]<l || start!=n-1)
				return start+1;
			else 
				return start;
		}
	}
	else
	{
		int mid=(start+end)/2;
		if(array[mid]==l)
		{
			//cout << "hello1" << endl;
			//return binary_search_right(array,l,mid,end);
			int i=mid;
			while(i<=n-1 && array[i]==l)
			{
				i++;
			}
			if(i==n)
				return i-1;
			else
			{
				if(array[i]==l)
					return i;
				else
					return i-1;
			}
		}
		else if(array[mid]>l)
		{
			//cout << "hello2" << endl;
			return binary_search_right(array,l,start,mid-1);
		}
		else
		{
			//cout << "hello3" << endl;
			return binary_search_right(array,l,mid+1,end);
		}
	}
}