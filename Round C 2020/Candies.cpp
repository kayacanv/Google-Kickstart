#include <bits/stdtr1c++.h>
#define pb push_back
#define fi first
#define sc second
#define inf	1000000000LL
#define MP make_pair
#define N 200005
#define MOD 998244353 
#define orta ((x+y+1)/2)
using namespace std;
typedef long long int lint;
typedef pair<lint,lint> ii;
#define u7 10000000
int n,q;

lint d[N];
struct FenwickTree {
    vector<lint> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    lint sum(int r) {
        lint ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    lint sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, lint delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};


void solve(int ts)
{
    cin >> n >> q;
    FenwickTree FT(n+1),FT2(n+1);
    for (int i = 1; i <= n; i++)
        cin >> d[i];

    for (int i = 1; i <= n; i++)
    {
        FT.add(i,i*1ll*d[i]  * (i%2 ? 1 : -1 ) );
        FT2.add(i,d[i]  * (i%2 ? 1 : -1 ) );
    } 
    lint totalSum=0;   
    for (int i = 0; i < q; i++)
    {
        char c;
        lint a,b;
        cin >> c >> a >> b;
        if(c=='U')
        {
            FT.add(a,a*1ll*(b-d[a])  * (a%2 ? 1 : -1 ) );
            FT2.add(a,(b-d[a])  * (a%2 ? 1 : -1 ) );
            d[a]=b;
        }
        else
        {
            lint sum=0;
            if(a%2)
            {
                sum=FT.sum(a,b);
                sum-=FT2.sum(a,b)*1ll*(a-1);
            }
            else
            {
                sum=FT.sum(a,b);
                sum-=FT2.sum(a,b)*1ll*(a-1);
                sum=-sum;
            }
            totalSum+=sum;
//            cout << sum << " " << FT.sum(a,b) " " << FT.sum(a,b) << endl;
        }
        
    }
    cout << "Case #" << ts <<": " << totalSum << endl;       
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i+1);
}



