#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int K[10001][10001];
int knapSack(int,int *,int *,int);
int main()
{
        int t;
        cin >> t;
        while (t--)
        {
                int l,i;
                cin >> l;
                int val[l],wt[l],ans;
                for(i=0;i<l;i++)
                {
                        cin >> val[i];
                        wt[i]=i+1;
                }
                ans=knapSack(l,wt,val,l);
                cout<< ans << endl;
        }
        return 0;
}

int knapSack(int W, int wt[], int val[], int n)
{
        int i, w;
        
        for (i = 0; i <= n; i++)
        {
                for (w = 0; w <= W; w++)
                {
                   if (i==0 || w==0)
                       K[i][w] = 0;
                   else if (wt[i-1] <= w)
                         K[i][w] = max((w/i)*val[i-1] + K[i-1][w-(w/i)*wt[i-1]],  K[i-1][w]);
                   else
                         K[i][w] = K[i-1][w];
                }
        }
        return K[n][W];
}