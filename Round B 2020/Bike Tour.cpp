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

int d[105];
int solve(int tn)
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
    }
    int say=0;
    for (int i = 1; i < n-1; i++)
        if(d[i] > max(d[i-1],d[i+1]))
            say++;
    cout << "Case #"<<1+tn <<": " << say <<endl;
   
}
int main()
{
    int ts=1;   
    cin >> ts;
    for (int i = 0; i < ts; i++)
        solve(i);
    
}

