#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
typedef struct data  
{
	int food_type;
	int pokemon_type;
}data;
int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n,i;
		cin >> n;
		data array[n];
		int a,b;
		for(i=0;i<n;i++)
		{

			cin >> a >> b;
			array[i].food_type=a;
			array[i].pokemon_type=b;
		}
		int map[1000001],count=0;
		for(i=1;i<=1000001;i++)
			map[i]=0;
		for(i=0;i<n;i++)
		{
			
			if(array[i].food_type==array[i].pokemon_type)
			{
				//cout << "I am at 1" << endl;
			}
			else if(array[i].food_type!=array[i].pokemon_type && map[array[i].pokemon_type]!=0)
			{
				//cout << "I am at 2" << endl;
				map[array[i].food_type]++;
				map[array[i].pokemon_type]--;
			}
			else
			{
				//cout << "I am at 3" << endl;
				map[array[i].food_type]++;
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}