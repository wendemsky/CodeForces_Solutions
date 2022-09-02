//~Himanshu Maithani~
#include <bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define fo(i, n) for (i = 0; i < n; i++)
#define Fo(i, k, n) for (i = k; k < n ? i < n : i > n; k < n ? i += 1 : i -= 1)
#define ll long long
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(x) x.begin(), x.end()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)
#define PI 3.1415926535897932384626
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim)
{
    uniform_int_distribution<int> uid(0, lim - 1);
    return uid(rang);
}
int mpow(int base, int exp);
void ipgraph(int n, int m);
void dfs(int u, int par);

const int mod = 1'000'000'007;
const int N = 3e5, M = N;
//=======================

vi g[N];
int a[N];

void solve()
{
    string s;
    cin>>s;
    int a=0,b=0;
    int l = s.size();
    if(l==1) cout<<"Bob "<<s[0]-'a'+1<<endl;
    else if(l%2==0){
        for(int i=0;i<s.size();i++){
            a+= (s[i]-'a'+1);
        }cout<<"Alice "<<a<<endl;
    }
    else{
        int a1=0,a2=0,b1=0,b2=0;
        for(int i=1;i<l;i++){
            a1 += (s[i]-'a'+1);
        }b1 = s[0]-'a'+1;
        //cout<<"a1,b1:"<<a1<<" "<<b1<<endl;
        for(int i=0;i<l-1;i++){
            a2 += (s[i]-'a'+1);
        }b2 = s[l-1]-'a'+1;
        //cout<<"a2,b2:"<<a2<<" "<<b2<<endl;

        if(a1>a2){
            if(a1>b1) cout<<"Alice "<<a1-b1<<endl;
            else cout<<"Bob "<<b1-a1<<endl;
        }
        else{
            if(a2>b2) cout<<"Alice "<<a2-b2<<endl;
            else cout<<"Bob "<<b2-a2<<endl;

        }

    }



}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    cin >> t;
    while(t--)
    {
        //Google Code Jam
        //cout<<"Case #"<<i<<":";
        solve();
    }

    return 0;
}

int mpow(int base, int exp)
{
    base %= mod;
    int result = 1;
    while (exp > 0)
    {
        if (exp & 1)
            result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void ipgraph(int n, int m)
{
    int i, u, v;
    while (m--)
    {
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
}

void dfs(int u, int par)
{
    for (int v : g[u])
    {
        if (v == par)
            continue;
        dfs(v, u);
    }
}