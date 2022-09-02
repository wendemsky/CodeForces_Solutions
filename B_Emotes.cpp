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
    ll n,m,k;
    cin>>n>>m>>k;
    ll arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    ll max=INT_MIN, max2=INT_MIN;
    for(int i=0;i<n;i++){
        if(arr[i]>=max2 && arr[i]>=max){
            max2 = max;
            max = arr[i];
        }else if(arr[i]>max2 && arr[i]<max){
            max2=arr[i];
        }
    }
    //cout<<"max, max2:"<<max<<" "<<max2<<endl;
    ll ans=0;
    // if(max==max2){
    //     cout<<max*m<<endl;
    // }
    // else{
    //     while(m>0){
    //         if(k<=m){
    //             ans+=max*k;
    //             m-=k;
    //         }else{
    //             ans+=max*(m);
    //             m-=m;
    //         }

    //         if(m>0){
    //             ans+=max2;
    //             m--;
    //         }
    //     }
    //     cout<<ans<<endl;
    // }

    ans = floor(m/(k+1))*(max*k + max2) + (m%(k+1))*max;
    cout<<ans<<endl;

}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    srand(chrono::high_resolution_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
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