#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>  
#include <complex>
#include <queue>
#include <set>
#include <unordered_set>
#include <list>
#include <chrono>
#include <random>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
#include <stack>
#include <iomanip>
#include <fstream>
#include <type_traits> 
using namespace std;
#include <iostream>
#include <math.h>
// #include <bits/stdc++.h>
#include <cmath>
#include <iomanip>
#include <bitset>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <set>
#include <deque>
#include <map>
#include <stack>
#include <cstring>
#include<bits/stdc++.h>
#define ll            long long int
#define all(vec)      vec.begin(),vec.end()
#define rep(i,a,b)    for(i=a;i<=b;i++)
#define repr(i,a,b)   for(i=a;i>=b;i--)
#define pb            push_back
#define pll           pair<ll,ll>
#define vpll          vector<pair<ll,ll>>
#define ull           unsigned long long int
#define vll           vector<ll> 
#define vvll          vector<vector<ll>>
// #define ll long long int
 
// #define pll pair<ll,ll>
// #define vpll vector<pair<ll,ll>>
// #define ull unsigned long long int
// #define vll vector<ll>
// #define vvll vector<vector<ll>>
// #define rep(i,a,b) for(i=a;i<=b;i++)
// #define repr(i,a,b) for(i=a;i>=b;i--)
// #define all(v) v.begin() , v.end()
// #define rall(v) v.rbegin(),v.rend()
// #define ff first
// #define ss second
// #define pb push_back
// typedef unsigned long long int ulli;
// template<typename T> istream& operator>>(istream& in, vector<T>& a) {for (auto &x : a) in >> x; return in;};
// template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for (auto &x : a) out << x << ' '; return out;};
 
// template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.ff << ' ' << x.ss;}
// template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.ff >> x.ss;}
#define abdo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long int
#define tc ll t ; cin>>t; while(t--)
#define pb push_back
#define pob pop_back
#define loopj(j,a,b) for(ll j = a ; j < b-1 ; j++)
#define loopi(i,a,b) for (ll i = a; i < b; i++)
#define vl vector<ll>
#define vi vector<int>
#define lb lower_bound
#define ub upper_bound
#define sumv(v) accumalate(v.begin(),v.end(),0)
#define mii map<int,int>
#define umii unordered_map<int,int>
#define order(v) sort(v.begin(),v.end())
#define ed '\n'
#define el "\n"
#define all(v) v.begin(),v.end()
#define YES cout<<"YES"<<ed;
#define NO cout<<"NO"<<ed;
#define Yes cout<<"Yes"<<ed;
#define No cout<<"No"<<ed;
#define yEs cout<<"yEs"<<ed;
#define yeS cout<<"yeS"<<ed;
#define nO cout<<"nO"<<ed;
#define yes cout<<"yes"<<ed;
#define no cout<<"no"<<ed;
#define ans1 ll ans = 0;
#define cnt1 ll cnt = 0;
#define sum(a , b) (a + b)
#define product(a , b) (a * b)
#define squarear(a) (a * a)
#define rectanglear(a , b) (a * b)
#define squarepre(a) (a * 4)
#define rectanglpr(a , b) ((a + b)*2)
typedef unsigned long long ull;
typedef long double lld;
using namespace std;
typedef long long ll;
#define Trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define size_t int
#define endl '\n'
#define uni(a) a.resize(distance(a.begin(),unique(a.begin(),a.end())));

typedef long long ll;
typedef long double ld;
typedef pair<int,int> p32;
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<vector<ll> > vv64;
typedef vector<vector<p64> > vvp64;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
ll MOD = 998244353;
double eps = 1e-12;
#define forn(i,e) for(ll i = 0; i < e; i++)
#define forsn(i,s,e) for(ll i = s; i < e; i++)
#define rforn(i,s) for(ll i = s; i >= 0; i--)
#define rforsn(i,s,e) for(ll i = s; i >= e; i--)
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 2e18
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define all(x) (x).begin(), (x).end()
#define sz(x) ((ll)(x).size())
   
  
void solve(){
}
int main()
{
    fast_cin();
    ll t;
    cin >> t;
    for(int it=1;it<=t;it++) {
     cout << "Case #" << it+1 << ": ";
        solve();
    }
    return 0;
}
