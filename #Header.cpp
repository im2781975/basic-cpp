#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")

#include <algorithm>
#include <bitset>
#include <complex>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include<sstream>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <random>
#include <vector>
#include <map>
#include <math.h>
#include <fstream>
#include <type_traits> 
#include <iostream>
#include <iomanip>
#include<iterator>
#include <vector>
#include<map>
//#include<set>
//#include<list>
//#include<cmath>
//#include<queue>
//#include<deque>
//#include<stack>
//#include<ctime>
//#include<string>
//#include<vector>
//#include<fstream>
//#include<cstdlib>
//#include<iomanip>
//#include<cstdlib>
//#include<numeric>
//#include<iostream>
//#include<algorithm>
//#include<unordered_map>
//#include<unordered_set>
//#define ll long long 
//#define vi vector<int>
#define ll long long int
#define all(vec) vec.begin(),vec.end()
#define all(v) v.begin() , v.end()
#define rep(i,a,b) for(i=a;i<=b;i++)
#define repr(i,a,b) for(i=a;i>=b;i--)
#define rall(v) v.rbegin(),v.rend()
#define pb push_back
#define pob pop_back
#define pll pair<ll,ll>
#define vpll vector<pair<ll,ll>>
#define ull unsigned long long int
#define vll vector<ll> 
#define vvll vector<vector<ll>>
#define ll long long int
#define ff first
#define ss second
#define abdo ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define tc ll t ; cin>>t; while(t--)
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
#define Trav(a, x) for (auto &a : x)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define int ll
#define size_t int
#define endl '\n'
#define uni(a) a.resize(distance(a.begin(),unique(a.begin(),a.end())));
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
#define lli long long int
#define ld long double
#define llu long unsigned int
#define mod ((lli)(1e9+7))
#define ilpf(a,b) for(lli i=a;i<=b;i++)
#define jlpf(a,b) for(lli j=a;j<=b;j++)
#define klpf(a,b) for(lli k=a;k<=b;k++) 
#define ilpb(a,b) for(lli i=a;i>=b;i--)
#define jlpb(a,b) for(lli j=a;j>=b;j--)
#define klpb(a,b) for(lli k=b;k>=a;k--)
#define vlli vector<lli>
#define vld vector<ld>
#define vb vector<bool>
#define vch vector<char>
#define vstr vector<string>
#define vpllilli vector<pair<lli,lli>>
#define vpllild vector<pair<lli,ld>>
#define vpldlli vector<pair<ld,lli>>
#define vpllib vector<pair<lli,bool>>
#define vpldld vector<pair<ld,ld>>
#define vpldb vector<pair<ld,bool>>
#define vpstrlli vector<pair<string,lli>>
#define vpllistr vector<pair<lli,string>>
#define vpstrld vector<pair<string,ld>>
#define vpldstr vector<pair<ld,string>>
typedef unsigned long long int ulli;
template<typename T> istream& operator>>(istream& in, vector<T>& a) {for (auto &x : a) in >> x; return in;};
template<typename T> ostream& operator<<(ostream& out, vector<T>& a) {for (auto &x : a) out << x << ' '; return out;};
 template<typename T1, typename T2> ostream& operator<<(ostream& out, const pair<T1, T2>& x) {return out << x.ff << ' ' << x.ss;}
template<typename T1, typename T2> istream& operator>>(istream& in, pair<T1, T2>& x) {return in >> x.ff >> x.ss;}

typedef unsigned long long ull;
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
#include<bits/stdc++.h>
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
ll MOD = 998244353;
double eps = 1e-12;
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
using namespace std;
lli llin(){lli x;scanf("%lld",&x);return x;}
ld ldin(){ld x;scanf("%Lf",&x);return x;}
char chin(){char ch;cin>>ch;return ch;}
string strin(){string str;cin>>str;return str;}
void No(){ cout<<"No"<<endl;}
void NO(){ cout<<"NO"<<endl;}
void Yes(){ cout<<"Yes"<<endl;}
void YES(){ cout<<"YES"<<endl;}
lli fmin_i(vlli v){lli n=v.size(),mn_i=0,mn_e=v[0];ilpf(0,n-1){lli MIN=min(mn_e,v[i]);if(MIN!=mn_e){mn_e=MIN;mn_i=i;}}return mn_i;}
lli fmax_i(vlli v){lli n=v.size(),mx_i=0,mx_e=v[0];ilpf(0,n-1){lli MAX=max(mx_e,v[i]);if(MAX!=mx_e){mx_e=MAX;mx_i=i;}}return mx_i;}
lli lmin_i(vlli v){lli n=v.size(),mn_i=0,mn_e=v[0];ilpf(0,n-1){if(v[i]<=mn_e){mn_e=v[i];mn_i=i;}}return mn_i;}
lli lmax_i(vlli v){lli n=v.size(),mx_i=0,mx_e=v[0];ilpf(0,n-1){if(v[i]>=mx_e){mx_e=v[i];mx_i=i;}}return mx_i;}
lli min_e(vlli v){lli mn_e=v[0],n=v.size();ilpf(0,n-1)mn_e=min(mn_e,v[i]);return mn_e;}
lli max_e(vlli v){lli mx_e=v[0],n=v.size();ilpf(0,n-1)mx_e=max(mx_e,v[i]);return mx_e;}
void make_prime(vb&v){lli I=2,n=(lli)v.size()-1;ilpf(0,n)v[i]=true;v[0]=false;v[1]=false;while(I<=n){while(I<=n&&!v[I])I++;if(I>n)break;lli i=2;while(i*I<=n){v[i*I]=false;i++;}I++;}}

//Vector STL/Function
* vlli v2(v.begin(),v.begin()+size);
* vlli v2(v)
* sort(v.begin().v.end())
* reverse(v.begin(),v.end())
* (bool) binary_search(v.begin(),v.end(),key)
* (iterator) lower_bound(v.begin(),v.end(),key);
* (iterator) upper_bound(v.bein(),v.end(),key);
* (iterator) v.lower_bound(key);
* (iterator) v.upper_bound(key);
* v.erase(v.begin()+i)
* v.erase(unique(v.begin(),v.end()),v.end())
* v.erase(v.begin()+i,v.end()-j)  ||    v.erase(v.begin(),v.begin()+j)
* v.erase(remove(v.begin(),v.end(),data),v.end())  //erase  all the 'data' from the vector
* (bool)next_premutation(v.begin(),v.end())
* (bool)prev_premutation(v.begin(),v.end())
* v.insert(it,data) || v.insert(i,data)  
* v.insert(it,no_of_times,data) || v.insert(i,no_of_times,data)
* v.push_back(data),v.pop_back(data),(data) v.front() ,(data) v.back() ,(data) v[index] ,(iterator) v.begin() ,(iterator) v.end()
* (lli) max_e(v) ,(lli)min_e(v) ,lli fmax_i(v) ,lli lmax_i(v) ,lli fmin_i(v) ,lli lmin_i(v)
 
//Vector of pairs
* vector<pair<key_type,data type>> vp
* vp.push_back(make_pair(key,data))
* sort by key/first element (then data/second)
* sort(vp.begin(),vp.end()) 
* sort by sec element(only by sec)
* bool sortbysec(const pair<int,int> &a, const pair<int,int> &b) { return (a.second < b.second);}
*sort(vp.begin(),vp.end(),sortbysec) 
* (data) vp[i].first ,(data) vp[i].second ,
  
//-------String Manupulation------
* string str2(str1)
* string str2(str1.begin(),str1.begin()+length)
* string s=str.substr(starting_index,length) 
* s.erase(s.begin()+index)
* s.erase(s.begin()+index,s.end()-index)  ||  s.erase(s.begin()+index(),s.begin()+index)
* s.erase(unique(s.begin(),s.end()),s.end())  ::adjecent will not be same
* sort(s.begin(),s.end());
* reverse(s.begin(),s.end())
* str.erase(remove(str.begin(),str.end(),'ch'),str.end()); //erase all the 'ch' from string
* str.insert(it,'ch')  ||  str.insert(i,'ch')
* str.insert(it,no_of_times,'ch') ||  str.insert(i,no_of_times,'ch')
* getline(cin,string_name)
* stringstream(string_name)>>type1_>>type2_>>type3_.........>>typeN_;
* stringstream STREAM_name(string_name)
* STREAM_name>>type1_>>type2_>>type3>>type4_>>type5_;
* s=to_string(2018)

// -----------STACK-----------
* stack<data_type>s
* push()  :s.push(data) :O(1)
* pop()   :s.pop()      :O(1)
* top()   :s.top()      :O(1)
* empty() :s.empty()    :O(1)
* size()  :s.size()     :O(1)

//----------QUEUE-------------
* queue<data_type>q    
* push()  :q.push(data) :O(1)
* pop()   :q.pop()      :O(1)
* front() :q.front()    :O(1)
* back()  :q.back()     :O(1)
* empty() :q.empty()    :O(1)
* size()  :q.size()     :O(1)
  
//--- priority_queue(default MAX HEAP)---------
* priority_queue(data_type>pq
* push()   :pq.push(data) :O(log(n))
* pop()     :pq.pop()     :O(long(n))
* top()     :pq.top()     :O(1)
* size()    :pq.size()    :O(1)
* empty()   :pq.empty()   :O(1)

 /*-------------------------------SET:Element in sorted order(increasing) and UNIQUE*****----------------------
 * declaration     :set<lli>s
 * insertion       :s.insert(data)  //insert if it is not present     :O(log(n))             
 * size            :s.size()                                          :O(1) 
 * find            :auto it=s.find(data) //if it!=s.end -> data found :O(log(n))
 * s.lower_bound() :it=s.lower_bound(data)
 * s.upper_bound() :it=s.upper_bound(data)
 * lower_bound()   :it=lower_bound(s.begin(),s.end(),data)
 * upper_bound()   :it=upper_bound(s.begin(),s.end(),data)
 * erase()         :erase(it)
 * erase()         :s.erase(it1,it2)
 * s.erase()       :s.erase(data)
 * loop            :for(auto it=s.begin();it!=s.end();it++)
 */
 
 /*------------------------------------------MAP:Elemnet r SORTED,unlike set we insert (key and data)--------------------------
 * declaration   :map<key_type,data_type>m
 * insert        :m.insert(make_pair(key,data));                     :O(log(n))
 *               :m.insert(pair<type,type>(key,data))
 * find          :auto it=m.find(key) //if(it!=m.end)it->first=key   :O(log(n))
 * []            :m[key]++      //data=data+1 ,at that key           :O(log(n))
 * size          :m.size()                                           :O(1)
 * m.lower_bound :it=m.lower_bound(key)
 * m.upper_bound :it=m.lower_bound(key)
 * lower_bound   :it=lower_bound(m.begin(),m.end(),key)
 * upper_bound   :it=upper_bound(m.begin(),m.end(),key)
 * erase()       :s.erase(it)
 *               :s.erase(it1,it2)
 *               :s.erase(key)
 * loop          :for(auto it=m.begin();it!=s.end();it++)
 * 
 * it->first ,it->second ,
 */
 
 
 /*------------------------------------------Unorderd SET  :Elements in unsorted order(used hasing to store data)------------------------------------
 * declaration   :unordered_set<lli>s
 * insertion     :s.insert(data)                                     :O(1)
 * size          :s.size()                                           :O(1)
 * find          :auto it=s.find(data)//if it!=s.end ->data found    :O(1)     ||  worst case O(n)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 */

 /*Unordered MAP :Element r UNSORTED,unlike unordered set we insert (key and data)|| 
 * declaration   :unorderd_map<key_type,data_type> m
 * insert        :insert(make_pair(key,data))                        :O(1) 
 * find          :auto it=m.find(key) //if (it!=m.end)it->first=key  :O(1)
 * []            :m[key]++      //data=data+1 ,at that key           :O(1)
 * size          :m.size()                                           :O(1)
 * loop          :for(auto it=s.begin();it!=s.end();it++)
 */
 
 /* muti_set             :similar to set but have duplicate element
  * multi_set<data_type>ms
  * insert()               :ms.insert(data)         :O(log(n))
  * find()                 :auto it=ms.find(data)   :O(long(n))
  * size()                 :ms.size()               :O(1)
  */
  
  /* multimap              :similar to MAP but can have duplicate keys  :search O(logn):insert O(logn):delete O(logn)  
   * mulimap<key_type,data_type>mm
   * mm.insert(pair<key_type,data_type>(key,data))        :O(long(n))
   * multimap<key_type,data_type> mm2(mm.begin(),mm.end())  
   * find()                :it=mm.find(key)  //first it   :O(long(n))
   * mm.lower_bound(key)->second //data      mm.lower_bound(key)=it  1st elemet having the key  or mm.end()
   * mm.upper_bound(key)->second //data      mm.upper_bound(key)=it  1st element just after the key or mm.end()
   * mm.erase(key)         :erase all element of the key value
   * mm.erase(mm.begin(),mm.find(key))    :remove all having(key) less than the given key
   * mm.size()                                             :O(1)
   * for(auto it=mm.begin();it!=mm.end;it++)     :traversal
   */
 /*__________________________________________________________________________________________________________________________________________________*/

//If you want to just put all the worlds of a paragraph in database use VECTOR
//If you want to make dictionary of the words in paragraph use SET
//If you want to calculate frequency of each words in paragraph use MAP

/*____________________________________________________________________________________________________________________________________________________*/


int main()
{
	lli n=llin();
	ilpf(0,n-1)
	{
		string str=strin();
		if((lli)str.length()<=10)
		cout<<str<<endl;
		else
		{
			lli n=(lli)str.length();
			string s=str[0]+to_string(n-2)+str[n-1];
			cout<<s<<endl;
		}
	}
}
