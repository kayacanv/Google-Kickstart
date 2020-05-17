#include <bits/stdtr1c++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000LL
#define MP make_pair
#define N 100005
#define MOD 998244353 
#define orta ((x+y+1)/2)
using namespace std;
typedef long long int lint;
typedef pair<lint,lint> ii;

int n;

void solve(int ts)
{
    int k;
    cin >> n  >> k; 
    int cnt=0;
    int t=k;
    for (int i = 0; i < n; i++)
    {
        int o;
        cin >> o;
        if(o==t)
        {
            t--;
            if(t==0){
                cnt++;
                t=k;
            }
        }
        else
        {
            t=k;
            if(t==o)
                t--;
        }
    }    

    cout << "Case #" << ts <<": " << cnt << endl;
}
int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i+1);
}



