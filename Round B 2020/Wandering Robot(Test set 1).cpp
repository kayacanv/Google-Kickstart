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
long long int fact[N];
void init_fact()
{
    fact[0] = 1;
    for (int i = 1; i <= N; i++)
    fact[i]= (fact[i-1]*1ll*i) % MOD;
}


double W,H,L,U,R,D;
double com(lint a,lint b)
{
    if(a-b<b) b= a-b;
    double ans=1;\
    int bt=b;
    for (int i = 0; i < bt; i++)
    {
        ans*=a;
        ans/=b;
        a--;
        b--;
    }
    return ans;
}
double us2(lint a)
{
    double ans=1;
    for (int i = 0; i < a; i++)
        ans*=2;
    return ans;
}
double all;
double tcom(lint x,lint y)
{
    if(x<=0 || y<=0) return 0;
    double t=com(x+y-2,x-1)/us2(x+y-2)/2;
    if(x==W)
    {
        double ans=0;
        for (int i = W-1; i <=x+y-2; i++)
        {
            ans+=com(x+y-2,i);
        }
        t=ans/us2(x+y-2);    
    }
    if(y==H)
    {
        double ans=0;
        for (int i = H-1; i <=x+y-2; i++)
        {
            ans+=com(x+y-2,i);
        }
        t=ans/us2(x+y-2);    
    }
//    cout << x << " " << y << " "<< t << endl;  
    return t;
}
int solve(int tn)
{
    cin >> W >> H >> L >> U >> R >> D;

    double ans=0;
     all=com(W+H-2,min(W,H)-1);
 //    cout << all << endl;
    for (int i = L; i <= R; i++)
    {
        ans+=tcom(i,U-1);
    }
    for (int i = U; i <= D; i++)
    {
        ans+=tcom(L-1,i);
    }
    

    cout << "Case #"<<1+tn <<": ";
    printf("%.6lf\n",1-(ans));
   
}
int main()
{
    int ts=1;   
     init_fact();
   cin >> ts;
    for (int i = 0; i < ts; i++)
        solve(i);
    
}
