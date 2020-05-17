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

int R,C;


int say[N],mark[N],mark2[N];

void solve(int ts)
{
    vector <char> v[N];
    map <char , char> mp[N];
    char mat[30][30]={0};
    memset(say,0,sizeof(say));
    memset(say,0,sizeof(say));
    memset(mark,0,sizeof(say));
    memset(mark2,0,sizeof(say));
    cin >> R >> C;
    for (int i = 0; i < R; i++)
    for (int j = 0; j < C; j++)
    {
        char c;
        scanf(" %c",&c);
        mat[i][j]=c;
        mark[c] =1 ;
    }
    for (int j = 0; j < C; j++)
    for (int i1 = 0; i1 < R; i1++)
    for (int i2 = i1+1; i2 < R; i2++)
    {
        char c1=mat[i2][j];
        char c2=mat[i1][j];
        if(mp[c1][c2]) continue;
        mp[c1][c2]=1;
        if(c1!=c2)
        {
            
            v[c1].pb(c2);
            say[c2]++;
        }
    }
    queue <char> q;
    for (int i = 0; i <= 'Z'; i++)
        if(mark[i] && say[i]==0)
            q.push(i);    
    string ans;
    while(!q.empty())
    {
        char tmp=q.front();
        q.pop();
        mark2[tmp]=1;
        ans.push_back(tmp);
        for(auto it:v[tmp])
        {
            say[it]--;
            if(say[it]==0)
                q.push(it);
        }
    }
    int fl=1;
    for (int i = 0; i <='Z'; i++)
        if(mark[i] && mark2[i]==0)
            fl=0;
    if(fl==0)    
        cout << "Case #" << ts <<": " << -1 << endl;
    else
        cout << "Case #" << ts <<": " << ans << endl;

}
int main()
{

    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve(i+1);
}



