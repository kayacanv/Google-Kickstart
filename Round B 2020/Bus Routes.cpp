#include <bits/stdtr1c++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000LL
#define MP make_pair
#define N 100005
#define MOD 998244353 
#define orta ((x+y)/2)
using namespace std;
typedef long long int lint;
typedef pair<lint,lint> ii;

long long  int d[100005];
int solve(int tn)
{
   long long int n , k;
    cin >> n >> k;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }

    for (int i = n-1; i >=0; i--)
    {
        k=k/d[i]*d[i];
    }

 

    cout << "Case #"<<1+tn <<": " << k <<endl;
   
}
int main()
{
    int ts=1;   
    cin >> ts;
    for (int i = 0; i < ts; i++)
        solve(i);
    
}
