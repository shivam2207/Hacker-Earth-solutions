#include <iostream>
#include <vector>
using namespace std;

long int gcd(long int,long int);
int array[100001]={0};

int main()
{
	int s,q,i,temp;
	cin >> s>>q;
	for(i=0;i<q;i++)
	{
		cin>>temp;
		temp=gcd(s,temp);
		if(array[temp]==0)
		{
			cout<<temp<<endl;
			array[temp]++;
		}
		else
			cout<<-1<<endl;
	}

}

long int gcd(long int a,long int b)
{
	long int c = a % b;
  	while(c != 0)
  	{
    		a = b;
    		b = c;
    		c = a % b;
  	}
  	return b;
}