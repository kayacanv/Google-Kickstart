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
#define u7 10000000

int n;
int d[N];
int pre[N];
int mp[u7*2+10];
void solve(int ts)
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    mp[0+u7]++;
    lint cnt=0;
    int mx=0,mn=0;
    for (int i = 1; i <= n; i++)
    {
        pre[i]= pre[i-1] + d[i];    
        mx= max(mx,pre[i]);
        mn= min(mn,pre[i]);
        for (int j = 0; j*j <= mx-mn; j++)
        {
            cnt += mp[ pre[i]-j*j + u7];
        }
        mp[pre[i]+u7]++;
    }
    for (int i = 1; i <= n; i++)
        mp[pre[i]+u7]--;
    mp[0+u7]--;
    cout << "Case #" << ts <<": " << cnt << endl;

}
int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i+1);
}



