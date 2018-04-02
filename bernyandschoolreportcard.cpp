#include <bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,m,x;
		cin >> n >> m >> x;
		int array[n],i;
		long long int sum=0,total,out;
		for(i=0;i<n;i++)
		{
			cin >> array[i];
			sum+=array[i];
		}
		total=(long long int)x*(n+1);
		out=total-sum;
		if(out > m)
			cout << "Impossible" << endl;
		else if(out < 0)
			cout << "1" << endl;
		else
			cout << out << endl;
	}
	return 0;
}