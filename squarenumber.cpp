#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
using namespace std;
int main()
{
	// bool prime[100001]=false;
	// int i,j;
	// for(i=2;i*i<=100000;i++)
	// {
	// 	if(prime[i]==false)
	// 	{
	// 		for(j=i*i;j<=100000;j+=i)
	// 		{
	// 			prime[j]=true;
	// 		}
	// 	}
	// }
	//int t=10;
	//while(t--)
	//{
	long long int n;
	cin >> n;
	double d;
	int i,flag=0;
	d=pow(n,0.5);
	string s=to_string(d);
	// for(i=0;i<(int)s.size();i++)
	// {
	// 	if(s[i]=='.')
	// 	{
	// 		flag=1;
	// 		break;
	// 	}
	// }
	i=0;
	while(s[i]!='.')
	{
		i++;
	}
	i++;
	while(i<(int)s.size())
	{
		if(s[i]!='0')
		{
			flag=1;
			break;
		}
		i++;
	}
	//cout << s << endl;
	if(flag==1)
		cout <<"NO"<< endl;
	else
		cout <<"YES" << endl;
	//cout << d << endl;
	//}	
	return 0;
}