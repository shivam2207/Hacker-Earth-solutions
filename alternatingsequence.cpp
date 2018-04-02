#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
string decimal_to_binary(int);
int binary_to_decimal(string);
bool is_prime(int);
int gcd(int,int);
int longestalternatingseq(int,int);
int n;
int table[5001],vec[5001];
int main()
{
	int i;
	cin >> n;
	//vector <int> vec(n,0);
	memset(table,-1,sizeof(table));
	for(i=0;i<n;i++)
		cin >> vec[i];
	cout << longestalternatingseq(0,0) << endl;
	return 0;
}
int longestalternatingseq(int index,int selindex)
{
	int temp1=0,temp2=0;
	if(index==n)
		return 0;
	else if(selindex!=-1 && table[selindex]!=-1)
	  	return table[selindex];
	// else if(selindex==-1 && table[index]!=-1)
	// 	return table[index]; 
	else if(index==0)
	{
		temp1=longestalternatingseq(index+1,index)+1;
		temp2=longestalternatingseq(index+1,-1)+0;
		//cout << index <<" "<<max(temp1,temp2) << endl;
		table[selindex]=max(temp1,temp2);
		return table[selindex];
	}
	else
	{
		if(selindex!=-1)
		{
			if(abs(vec[index])-abs(vec[selindex])>0)
			{
				if((vec[index]>0 && vec[selindex]<0) || (vec[index]<0 && vec[selindex]>0))
				{
					temp1=longestalternatingseq(index+1,index)+1;
				}
			}
			temp2=longestalternatingseq(index+1,selindex)+0;
			//cout << index <<" "<<max(temp1,temp2) << endl;
			table[selindex]=max(temp1,temp2);
			return table[selindex];
			//return(max(temp1,temp2));
		}
		else
		{
			temp1=longestalternatingseq(index+1,index)+1;
			temp2=longestalternatingseq(index+1,-1)+0;
			table[index]=max(temp1,temp2);
			return table[index];
			//cout << index <<" "<<max(temp1,temp2) << endl;
			//return(max(temp1,temp2));
		}
	}
}
string decimal_to_binary(int n)
{
	int i=0;
	string binary=bitset<32>(n).to_string();
	while(i<32 && binary[i]=='0') i++;
	return binary.substr(i);
}
int binary_to_decimal(string s)
{
	int n=bitset<32>(s).to_ulong();
	return n;
}
int gcd(int a,int b)
{
	if(a==0 && b==0) return -1;else if(a==0) return b;else if(b==0) return a;
	else return	gcd(b%a,a);
}
bool is_prime(int n)//return true if prime
{
	if(n<2) return false; else if(n==2) return true; else if(n%2==0) return false;
	else
	{
		for(int i=3;i*i<=n;i+=2) 
			if(n%i==0) return false;
		return true;
	}
}