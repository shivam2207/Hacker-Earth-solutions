#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool func(int i,int j)
{
	return(i>j);
}
int main()
{
	int n,i,temp;
	cin >> n;
	vector <int> v1;
	vector <int> v2;
	long long int sum=0;
	for(i=0;i<n;i++)
	{
		cin >>temp;
		v1.push_back(temp);
	}
	for(i=0;i<n;i++)
	{
		cin >> temp;
		v2.push_back(temp);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	for(i=0;i<n;i++)
	{
		sum=sum+v1[i]*v2[i];
	}
	cout<<sum<<endl;
	return 0;
}