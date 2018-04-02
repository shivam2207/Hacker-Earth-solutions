

    #include<bits/stdc++.h>
    #define ll long long
    using namespace std;
    ll Cost[1000005];
    int main() {
            int T;
            for(cin>>T;T;--T) {
                ll  N,X,START = 0,SUM;
                bool FLAG = false;
                cin>>N>>X;
                for(int i=0;i<N;i++)
                {
                    cin>>Cost[i];
                }
                SUM = Cost[0];
                for(int i=1;i<N;i++)
                {
                     while(SUM > X)
                    {
                        SUM -= Cost[START];
                        START++;
                    }
                    if(SUM == X )
                    {
                        FLAG = true;
                        break;
                    }
                    SUM += Cost[i];
                }
                while(SUM > X)
                {
                    SUM -= Cost[START];
                    START++;
                }
                if(SUM == X)
                {
                    FLAG = true;
                }
                if(FLAG)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
            return 0;
        }
