#include <bits/stdtr1c++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000LL
#define MP make_pair
#define N 100005
#define MOD 1000000000 
#define orta ((x+y)/2)
using namespace std;
typedef long long int lint;
typedef pair<lint,lint> ii;


long long int f_p(long long int a,long long int b) // It has %MOD
{
    assert(b>=0);// cant be negative
    if(b<=1) return (b&1) ? a%MOD : 1;
    long long int tmp=f_p(a%MOD,b/2);
    return (((tmp*tmp)%MOD)*((b&1) ? a : 1))%MOD;
}


int d[105];
int solve(int tn)
{
    string a;
    cin >> a;
    long long int crp=1;
    vector<long long> st;
    long long int x=0,y=0;
    for (int i = 0; i < a.size(); i++)
    {

        if(a[i]>='0' && a[i]<='9')
        {
            st.pb(a[i]-'0');
            crp*=a[i]-'0';
            crp%=MOD;
            i++;
            continue;
        }
        else if(a[i]==')')
        {
            st.pop_back();
            crp=1;
            for (auto it : st)
            {
                crp*=it;
                crp%=MOD;
            }            
        }
        else
        {
            if(a[i]=='N')
            {
                y-=crp;
                y%=MOD;
            }
            if(a[i]=='S')
            {
                y+=crp;
                y%=MOD;
            }
            if(a[i]=='E')
            {
                x+=crp;
                x%=MOD;
            }
            if(a[i]=='W')
            {
                x-=crp;
                x%=MOD;
            }
        }
        if(x<0) x+=1000000000;
        if(y<0) y+=1000000000;
        
    }
    
    cout << "Case #"<<1+tn <<": " << x+1 << " " << y+1 <<endl;
   
}
int main()
{
    int ts=1;   
    cin >> ts;
    for (int i = 0; i < ts; i++)
        solve(i);
    
}
