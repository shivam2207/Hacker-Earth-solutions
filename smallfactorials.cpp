#include <iostream>
using namespace std;

int main()
{
	int t;
	cin >> t;
	int array[200]={0},carry=0,j,i,temp;
	int result[101][200];
	array[199]=1;
	for(i=1;i<=100;i++)
	{
		carry=0;
		for(j=199;j>=0;j--)
		{
			temp=(array[j]*i+carry);
			array[j]=temp%10;
			carry=temp/10;
			result[i][j]=array[j];
		}
	}
	while(t--)
	{
		int n,k;
		cin >> n;
		k=0;
		while(result[n][k]==0)
			k++;
		while(k<=199)
		{
			cout<<result[n][k];
			k++;
		}
		cout<<"\n";
	}
	return 0;
}