#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
long long int sum=0;
int x;
void combinationUtil(int arr[],int n,int r,int index,int data[],int i);
void printCombination(int arr[], int n, int r)
{
    int data[r];
    combinationUtil(arr, n, r, 0, data, 0);
}
void combinationUtil(int arr[], int n, int r, int index, int data[], int i)
{
    if (index == r)
    {
        long long int temp=data[0];
        for (int j=1; j<r; j++)
        {
            temp^=data[j];
            //printf("%d ",data[j]);
        }
        //printf("\n");
        if(temp==x)
            sum++;
        return;
    }
        if (i >= n)
            return;
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
    combinationUtil(arr, n, r, index, data, i+1);
}
int main()
{
    int n;
    cin >> n >> x;
    int arr[n],i;
    for(i=0;i<n;i++)
        cin >> arr[i];
    //int r = 3;
    //int n = sizeof(arr)/sizeof(arr[0]);
    for(i=1;i<=n;i++)
        printCombination(arr, n, i);
    cout << sum%mod << endl;
    return 0;
}