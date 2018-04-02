#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
bool myfunction(int *,int);

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,i;
		cin >> n;
		int array[n],temp,firstflag=0,secondflag=0,index1=-1,index2=-1;
		for(i=0;i<n;i++)
		{
			cin >> array[i];
		}
		if(is_sorted(array,array+n))
			cout << -1 <<" "<< -1 << endl;
		else if(myfunction(array,n))
			cout << -1 <<" "<< -1 <<endl;
		else
		{
			temp=array[0];
			for(i=1;i<n;i++)
			{
				if(firstflag==0 && array[i]>temp)
				{
					temp=array[i];
				}
				else if(firstflag==1 && secondflag==0 && array[i]>temp)
				{
					secondflag=1;
					index2=i;
				}
				else
				{
					if(firstflag==0)
					{
						firstflag=1;
						index1=i;
					}

				}
			}
			if(index1==-1)
				index1=1;
			if(index2==-1)
				index2=n;
			cout << index1 <<" "<< index2 << endl;
		}
	}
	return 0;
}
bool myfunction(int *array,int n)
{
	stack <int> mystack;
	int i,temp=0,flag=0;
	mystack.push(array[0]);
	for(i=1;i<n;i++)
	{
		if(array[i]<mystack.top())
			mystack.push(array[i]);
		else
		{		
			while(!mystack.empty() && mystack.top()<array[i])
			{
				temp=mystack.top();
				mystack.pop();
			}
			mystack.push(array[i]);
		}
		if(array[i]<temp)
		{
			flag=1;
			break;
		}
	}
	if(flag==1)
		return true;
	else
		return false;
}