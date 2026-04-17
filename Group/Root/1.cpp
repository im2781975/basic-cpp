/** **/
void bfs(int a,vector<vector<int> > &adj,int visited[],int dist[]){
	queue<int> q;
	q.push(a);
	visited[a]=1;
	while(!q.empty()){
	    int node=q.front();
	    q.pop();
	    for(int i=0;i<adj[node].size();i++){
	        int child=adj[node][i];
	        if(!visited[child]){
	            visited[child]=1;
	            dist[child]=dist[node]+1;
	            q.push(child);
	        }
	    }
	}
}
void bfsme(int x1,int y1,int x2,int y2,vector<vector<char> > &a,vector<vector<int> > &visited, vector<vector<char> > &path,queue<pair<int,int> > &q,int n,int m){
    if(q.empty()){
        return;
    }
    pair<int,int> p=q.front();
    q.pop();
    int x=p.first;
    int y=p.second;
    if(x>0){
        if(a[x-1][y]!='#' && visited[x-1][y]>visited[x][y]+1){
            visited[x-1][y]=visited[x][y]+1;
            path[x-1][y]='D';
            q.push(make_pair(x-1,y));
        }
    }
    if(x<n-1){
        if(a[x+1][y]!='#' && visited[x+1][y]>visited[x][y]+1){
            visited[x+1][y]=visited[x][y]+1;
            path[x+1][y]='U';
            q.push(make_pair(x+1,y));
        }
    }
    if(y>0){
        if(a[x][y-1]!='#' && visited[x][y-1]>visited[x][y]+1){
            visited[x][y-1]=visited[x][y]+1;
            path[x][y-1]='R';
            q.push(make_pair(x,y-1));
        }
    }
    if(y<m-1){
        if(a[x][y+1]!='#' && visited[x][y+1]>visited[x][y]+1){
            visited[x][y+1]=visited[x][y]+1;
            path[x][y+1]='L';
            q.push(make_pair(x,y+1));
        }
    }
    bfsme(x1,y1,x2,y2,a,visited,path,q,n,m);
}
/** **/
#include <bits/stdc++.h>
using namespace std;
// https://codeforces.com/problemset/problem/977/D/
typedef long long ll;

int n;
bool flag = false;
map<ll, vector<ll>> adj;
map<ll, bool> visited;
vector<ll> ans;

void bfs(ll src)
{
    queue<ll> q;
    q.push(src);
    visited[src] = true;
    ans.push_back(src);
    while (!q.empty())
    {
        if (ans.size() == n)
        {
            flag = true;
            return;
        }
        ll parent = q.front();
        q.pop();
        for (auto child : adj[parent])
        {
            if (parent * 2 == child && !visited[child])
            {
                q.push(child);
                visited[child] = true;
                ans.push_back(child);
            }
            else if ((parent % 3 == 0) && (parent / 3 == child) && !visited[child])
            {
                q.push(child);
                visited[child] = true;
                ans.push_back(child);
            }
        }
    }
}

void init()
{
    ans.clear();
    visited.clear();
}

int main()
{
    cin >> n;
    vector<ll> v(n);

    for (int i = 0; i < n; i++)
        cin >> v[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                adj[v[i]].push_back(v[j]);
            }
        }
    }

    for (auto val : adj)
    {
        cout << val.first << "->";
        for (auto i : val.second)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    for (auto val : adj)
    {
        bfs(val.first);
        if (flag)
            break;
        init();
    }

    for (auto val : ans)
        cout << val << " ";

    return 0;
}
#include<bits/stdc++.h>
using namespace std;
int main()
{
    //https://codeforces.com/problemset/problem/1823/B
    int n, k;
    cin >> n >> k;
    map<int, int>mp;
    for(int i=1; i<=n; i++)
    {
        int in;
        cin >> in;
        map[in] = i;
    }
    int cnt = 0;
    for(auto val:mp)
    {
        int cur, currect;
        cur = val.second;
        currect = val.first;
        if(abs(cur - currect) % k! =0)
            cnt++;
    }
    if(cnt==0)
        cout << 0;
    else if(cnt==2)
        cout << 1;
    else 
        cout << -1;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,w;
bool done[100009];
vector<int>v[100009];
void dfs(int node)
{
    done[node]=1;
    for(int i=0;i<v[node].size();i++)
    {
        int u=v[node][i];
        if(!done[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            w++;
            dfs(i);
        }
    }
    cout<<w;
}
#include<bits/stdc++.h>
using namespace std;
int n,m,w;
int done[100009];
vector<int>v[100009];
void dfs(int node)
{
    done[node]=w;
    for(int i=0;i<v[node].size();i++)
    {
        int u=v[node][i];
        if(!done[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    int q;
    cin>>q;
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            w++;
             dfs(i);
        }
    }

    for(int i=0;i<q;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        if(done[a]==done[b])
        {
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
}
#include<bits/stdc++.h>
using namespace std;
int n,m,sum;
bool done[100009];
vector<int>v[100009];
void dfs(int node)
{
    done[node]=1;
    sum+=v[node].size();
    for(int i=0;i<v[node].size();i++)
    {
        int u=v[node][i];
        if(!done[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--,b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            dfs(i);
            cout<<sum/2<<endl;
            sum=0;

        }
    }
}
#include<bits/stdc++.h>
using namespace std;
int x,n,m,ww,w;
bool done[100009];
vector<int>v[100009];
void dfs(int node)
{
    if(!done[node])w++;
    done[node]=1;
    for(int i=0;i<v[node].size();i++)
    {
        int u=v[node][i];
        if(!done[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    cin>>n>>m>>x;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            dfs(i);
            if(w>=x)
            {
                ww++;
            }
            w=0;
        }
    }
    cout<<ww;
}
#include<bits/stdc++.h>
using namespace std;
int sum,n,m,mx,arr[100009];
bool done[100009];
vector<int>v[1000009];
void dfs(int node)
{
    if(!done[node])
    {
        mx=max(arr[node],mx);
    }
    done[node]=1;
    for(int i=0;i<v[node].size();i++)
    {
        int u=v[node][i];
        if(!done[u])
        {
            dfs(u);
        }
    }
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        if(!done[i])
        {
            dfs(i);
            sum+=mx;
            mx=0;
        }
    }
    cout<<sum;
}
#include<bits/stdc++.h>
using namespace std;
void TrappedRainWater()
{
    //trapping rainwater using an array representing the heights of walls.
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int leftmax = 0, rightmax = 0;

    while (left <= right) {
        if (height[left] <= height[right]) {
            if (height[left] >= leftmax) {
                leftmax = height[left];
            } else {
                res += leftmax - height[left];
            }
            left++;
        } else {
            if (height[right] >= rightmax) {
                rightmax = height[right];
            } else {
                res += rightmax - height[right];
            }
            right--;
        }
    }
    cout<< res;
}
/** **/
 int n, m;
 cin>>n>>m;
 vector<int> v(m);
 for (int i = 0; i < m; i++)
 {
      if(i>3){
    swap(v[i], v[i-1]);}
    cin>>v[i];
 }
 cout<<"ME"<<endl;
   deque<int> deque1 {1, 2, 3, 4, 5};

 deque<int> dq;
 string s; cin>>s;

map<int, int> mp;
 int cnt = 1;
 for (int i = 1; i <= n; i++)
 {
     dq.push_back(i);
 }

for(int i = 0; i<v.size(); i++){
     bool og1 = false;

  deque<int>::iterator it;
  it = find(dq.begin(), dq.end(), 
              v[i]);
 deque<int>::iterator itr;
   itr = find(dq.begin(), dq.end(), v[i]);
   if(itr != dq.end())
   {
     cout << "Found";
   }
   else
   {
     cout << "Not Found";
   }

   if(it != dq.end())
  {
      cout<<"MElskjfdslfdsjflsdf";
    it = dq.begin() + *it;
     cout<<"Lolo";
     cout<<"i am it"<<*it<<endl;
      distance(v.begin(), itr);

    dq.erase(distance);
     dq.push_front(v[i]);
    continue;
   }
   else
  {
         dq.push_front(v[i]);
         int temp = dq.back();
    
     mp[temp] = cnt;
     dq.pop_back();
         cnt++;

  }
 int pos = binarySearch(dq, 0, dq.size(), v[i]);
     cout<<"pos is "<<pos<<endl;

if(pos == -1){

     dq.push_front(v[i]);
 }
 else {
     deque<int>::iterator it;
 
    it = dq.begin()+pos;
     dq.erase(it);
     dq.push_front(v[i]);
      dq.erase()
 }
     int temp = dq.back();
    if(mp.find(temp) != mp.end()){
         continue;
    }
    mp[temp] = cnt;
     dq.pop_back();
    
     cnt++;
-----

	int BinarySearch(vector<long long> v, int item)
	{
		int low = 0;
		int high = v.size() - 1;
		int mid = NULL;
		int count = 0;
		while (low <= high)
		{
			mid = (low + high) / 2;

			if (v[mid] == item)
			{
				return mid + 1;
			}
			if (v[mid] > item)
			{
				high = mid - 1;
			}
			else
			{
				low = mid + 1;
			}
		}
		return NULL;
	}

	

	

	

	
	
	

	string s = "987";

	long long counte = 0;
	
	bool b = true;
	vector<bool> used(1000, false);

	void recu(int ind,int length,int maxnum,vector<char> v,char arr[])
	{
		if (ind == length)
		{
			string a = "";
			for (int i = 0; i < length; i++)
				a += v[i];
			if (a == s)
			{
				cout << "Success";
				b = false;
			}
			return;
		}
		for (int i = 0; (i < maxnum)&&b; i++)
		{
			v[ind] = arr[i];
			recu(ind + 1, length, maxnum, v, arr);
		}
	}

	int k;
	vector<char> c;
	int q;
	int p;
	bool be = true;

	void Scobka(int ind, int bal) 
	{
		if (ind == k)
		{
			if (bal == 0)
			{
					string a;
					for (int i = 0; i < k; i++)
						a += c[i];
					cout << a << endl;
			}
			return;
		}
 		c[ind] = '(';
		Scobka(ind + 1, bal + 1);
		if (bal == 0)
			return ;
		c[ind] = ')';
		Scobka(ind + 1, bal - 1);
	}
/** **/
#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int a[500001],n;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		m[a[i]]++;
	}
	if(m.count(0)) puts("NO");
	else if(m.size()==2)
	{
		int cnt=0;
		for(auto i:m)
		{
			a[++cnt]=i.first;
		}
		if(a[1]+a[2]==0) puts("NO");
		else puts("YES");
	}
	else puts("YES");
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
unordered_map<string,vector<int>> p;
int n,k;
ll ans;
string s;
int main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		auto &v=p[s];
		ans+=v.end()-lower_bound(v.begin(),v.end(),i-k-1);
		v.push_back(i);
	}
	cout<<ans<<endl;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;

string s;
int x=0,y=0;
unordered_set<string> h;
string m[8]={"ULD","URD","LDR","LUR","DLU","DRU","RUL","RDL"};
int main()
{
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;i++)
    {
        if((s[i]=='L'&&s[i+1]=='R')||(s[i]=='R'&&s[i+1]=='L'))
        {
            puts("NO");
            return 0;
        }
        if((s[i]=='U'&&s[i+1]=='D')||(s[i]=='D'&&s[i+1]=='U'))
        {
            puts("NO");
            return 0;
        }
        if(s[i]=='U') y++;
        else if(s[i]=='R') x++;
        else if(s[i]=='D') y--;
        else x--;
    }
    for(int i=0;i<len-2;i++)
    {
        string ans="";
        ans=s[i]+s[i+1]+s[i+2];
        h.insert(ans);
    }
    for(int i=0;i<8;i++)
    {
        if(h.count(m[i])) 
        {
            puts("NO");
            return 0;
        }
    }
    if(x==0&&y==0) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N = 0x3f3f3f3f;
typedef long long ll;
ll mp[2031][2031];


int main()
{
	int i,j,k;
	for(i=1;i<=2021;i++)
		for(j=1;j<=2021;j++)
			mp[i][j]=mp[j][i]=N; 
	for(i=1;i<=2021;i++)
		for(j=1;j<=2021;j++)
			if(abs(i-j)<=21)
				mp[i][j]=mp[j][i]=(i*j)/(__gcd(i,j));
	for(k=1;k<=2021;k++)
	{
		for(i=1;i<=2021;i++)
		{
			for(j=1;j<=2021;j++)
			{
				if(mp[i][j]>mp[i][k]+mp[k][j]) mp[i][j]=mp[j][i]=mp[i][k]+mp[k][j];
			}
		}
	}
	cout<<mp[1][2021]<<endl;
	return 0;
}
#include<iostream>
typedef long long ll;
using namespace std;
int n,m;
int g[10][10];
int st[10][10];
int dx[4]={-1,0,1,0};
int dy[4]={0,1,0,-1};
int ans=100,sum=0;
int total;
void dfs(int x,int y,int total,int s)
{
	if(total==sum/2)
	{
		ans=min(ans,s);
		return ;
	}
	if(total>sum/2) return ;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i],ny=y+dy[i];
		if(st[nx][ny]==0&&nx>=0&&ny>=0&&nx<n&&ny<m) 
		{
			st[nx][ny]=1;
			dfs(nx,ny,total+g[nx][ny],s+1);
			st[nx][ny]=0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>m>>n;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>g[i][j];
			sum+=g[i][j];
		}
	}
	st[0][0]=1;
	dfs(0,0,g[0][0],1);
	if(ans!=100) cout<<ans<<endl;
	return 0;
}
int binarySearch(vector<int>& v, int l, int r, int x)
{
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (x == v[m])
            return m;
        else if (x < v[m])
            r = m - 1;
        else
            l = m + 1;
        /* code */
    }
    return 0;
}

int binarySearch6(vector<int> arr, int l, int r, int x)
{
    // left
    int result = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == x)
        {
            result = m;
            r = m - 1;
        }
        else if (x < arr[m])
        {
            result = m;
            r = m - 1;
        }
        else
        {
            result = m + 1;
            l = m + 1;
        }
        /* code */
    }
    return result + 1;
}

int binarySearch4(vector<int> arr, int l, int r, int x)
{
    int result = -1;
    while (l <= r)
    {
        int m = (l + r) / 2;
        if (arr[m] == x)
        {
            result = m;
            l = m + 1;
            return result + 1;
        }
        else if (arr[m] < x)
        {
            l = m + 1;
            result = m;
        }
        else
        {
            r = m - 1;
            result = m - 1;
        }
    }
    return result + 1;
}
-----
bool check(ll k, string &s, ll x) {
     map<char, ll>m;
     ll n = s.length();
     for (ll i = 0; i < k; i++) m[s[i]]++;
     if (m.size() >= x) return true;
     for (ll i = k; i < n; i++) {
         m[s[i - k]]--;
        if (m[s[i - k]] == 0) m.erase(s[i - k]);
        m[s[i]]++;
         if (m.size() >= x) return true;
     }
    return false;
}
int main()
{
    string s;
        map<char,ll> av;
        cin>>s;
        for(char x: s)
        av[x]++;
        if(av.size()%2)
        cout<<"IGNORE HIM!"<<endl;
        else
        cout<<"CHAT WITH HER!"<<endl;
}
int main()
{
ll a,b=0,n,i;
       cin>>n;
       map<ll,ll> z;
       for(i=0;i<n;i++)
       {
                cin>>a;
                z[a]++;
                b=max(b,z[a]);
       }
       cout<<b<<" "<<z.size()<<endl;
}
int main()
{
ll n=6,x,i,f=0;
      map<ll,ll> mp;
      for(i=0;i<n;i++)
      {
                cin>>x;
                mp[x]++;
                f=max(f,mp[x]);
                
      }
      if((mp.size()==2 && f==4) || (mp.size()==1))
      cout<<"Elephant"<<endl;
      else if((mp.size()==3 && f==4) || (mp.size()==2 && f==5))
      cout<<"Bear"<<endl;
      else
      cout<<"Alien"<<endl; 
}
int main()
{
    ll i,n,x=0;
     map<string,ll> mp;
     string s;
     cin>>n;
     while(n--)
     {
        cin>>s;
        mp[s]++;
     }
     for(auto it : mp)
     {
           if(it.second>x)
           {
                x=it.second;
                s=it.first;
           }
     }
     cout<<s<<endl;
}
int main()
{
      ll n,m,i,j,a;
      map<ll,ll> mp;
      ll x=INT_MAX,y;
      y=x;
      a=y;
      cin>>n>>m;
      while(n--)
      {
                cin>>j;
                mp[j]++;
                x=min(x,j);
       }
       while(m--)
       {
                cin>>j;
                if(mp[j]!=0)
                {
                        a=min(a,j);
                }
                y=min(y,j);
        }
        cout<<min({a,x*10+y,y*10+x})<<endl;    
}
class segmentTree{
public:
	vector<int> a,c,lazy;
	segmentTree(int n)
	{
		//this->n=n;
		lazy.resize(4*(n+5),0);
		a.resize(4*(n+5));
		c.resize(n+5);
	}
	void bulid(int s=1,int e=n,int p=1)
	{
		if(s==e){
			a[p]=c[s];
			return ;
		}
		int m=(s+e)/2;
		bulid(s,m,p*2);
		bulid(m+1,e,p*2+1);
	}
	void change(int s,int e,int x,int ss=1,int ee=4*n,int p=1)
	{
		if(s<=ss&&ee<=e){
			a[ss]+=x*(ee-ss+1),lazy[p]+=x;
			return ;
		}
		int m = ss + ((ee - ss) >> 1);
		if (lazy[p] && ss != ee) {
			a[p * 2] += lazy[p] * (ee - ss + 1), a[p * 2 + 1] += lazy[p] * (ee - m);
			lazy[p * 2] += lazy[p], lazy[p * 2 + 1] += lazy[p]; 			lazy[p] = 0; 	
		}
		if (s <= m) change(s, e, x, ss, m, p * 2);
		if (e > m)  change(s, e, x, m + 1, ee, p * 2 + 1);
		a[p] = a[p * 2] + a[p * 2 + 1];
	}
	int getsum(int s,int e,int ss=1,int ee=4*n,int p=1)
	{
		if (ss <= s && ee <= e) return a[p];
		int m = ss + ((ee - ss) >> 1);
		if (lazy[p]) {
			a[p * 2] += lazy[p] * (ee - ss + 1), a[p * 2 + 1] += lazy[p] * (ee - m);
			lazy[p * 2] += lazy[p], a[p * 2 + 1] += lazy[p]; 			lazy[p] = 0;     
		}
		int sum = 0;
		if (s <= m) sum = getsum(s, e, ss, m, p * 2);
		if (e > m) sum += getsum(s, e, m + 1, ee, p * 2 + 1);
		return sum;
	}
};
class trie
{
public:
	trie* c[128];
	int val;
	trie()
	{
		for(int i=0;i<128;i++)c[i]=NULL;
		val=0;
	}
	int find(string s)
	{
		trie *p=this;
		for(int i=0;i<s.size();i++)
		{
			if(!p->c[s[i]])
				return 0;
			p=p->c[s[i]];
		}
		return p->val;
	}
	void insert(string s)
	{
		trie *p=this;
		for(int i=0;i<s.size();i++)
		{
			if(!p->c[s[i]])
				p->c[s[i]]=new trie();
			p=p->c[s[i]];
		}
		p->val++;
	}
};
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(nums[0]<target)
            {
            	if(nums[0]<target&&target<nums[mid])
				r=mid-1;
				else l=mid+1;
            }
            else
            {
            	if(nums[mid]>target&&taregt<=nums[n-1])
            		l=mid+1;
            	else r=mid-1;
            }
        }
        return -1;
    }
};
#include<iostream>
using namespace std;

struct edge {
    int x, y;
} edges[110];

int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> edges[i].x >> edges[i].y;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int max_y = 0, max_x = 0;
        for (int j = 0; j < n; j++) {
            if (edges[i].x == edges[j].x) 
                max_y = max(max_y, edges[j].y);
            if (edges[i].y == edges[j].y) 
                max_x = max(max_x, edges[j].x);
        }
        ans = max(ans, (max_x - edges[i].x) * (max_y - edges[i].y));
    }
    cout << ans;
    return 0;
}
#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 1e5+10;

struct edge{
	int ts,id;
	bool operator < (const edge x) const {
		return ts<x.ts;
	} 
}edges[N];

int n,m,ti;
map<int,int> m;
int main()
{
	cin>>n>>m>>ti;
	
	for(int i=0;i<m;i++)
		cin>>edges[i].ts>>edges[i].id;	
	sort(edges,edges+m);
	
	
	
	return 0;
}
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring> 
#include<iomanip>
using namespace std;

struct Stu{
	char name[1000];
	int sn;
	int st;
}stu[1000];

int n,m;
int cmp(Stu x,Stu y)
{
	if(x.sn==y.sn) 
	{
		return x.st<y.st;
	}
	return x.sn>y.sn;
}
int main()
{
	cin>>n>>m;
	int p=0;
	while(cin>>stu[p].name)
	{
		for(int i=0;i<n;i++)
		{
			char ch;
			int k,l;
			cin>>k;
			if(k<=0) continue;
			stu[p].sn++;
			stu[p].st+=k;
			if(getchar()=='(')
			{
				cin>>l;
				cin>>ch;
				stu[p].st+=l*m;
			}
		}
		p++;
	}
	sort(stu,stu+n,cmp);
	for(int i=0;i<p;i++)
	{
		cout<<left<<setw(10)<<stu[i].name<<" "<<right<<setw(2)<<stu[i].sn<<right<<" "<<setw(4)<<stu[i].st<<endl;
	}
	return 0;
} 
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

#define ll long long
#define vll vector<ll>
#define ff first
#define ss second

typedef pair<ll, ll> pi;

vector<ll> dijkstra(ll V, vector<vector<pair<ll, ll>>> adj, ll s, vll &par) {
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, s});
    vector<ll> dist(V, LLONG_MAX);
    par.assign(V, -1);
    dist[s] = 0;

    while (!pq.empty()) {
        ll dis = pq.top().first;
        ll ind = pq.top().second;
        pq.pop();

        for (auto it : adj[ind]) {
            if (dist[it.ff] > dis + it.ss) {
                par[it.ff] = ind;
                dist[it.ff] = dis + it.ss;
                pq.push({dist[it.ff], it.ff});
            }
        }
    }

    return dist;
}

int main() {
    // Example usage
    ll V = 5;
    vector<vector<pair<ll, ll>>> adj(V);

    // Populate the adjacency list with edges and weights

    ll sourceNode = 0;
    vll parent(V, -1);

    vector<ll> distances = dijkstra(V, adj, sourceNode, parent);

    // Process distances or parent array as needed

    return 0;
}
-----
pair<int,int> dfscount(int node,vector<vector<int> > adj,int visited[]){
     visited[node]=1;
     int ve=1;
     int ed=0;
     for(int i=0;i<adj[node].size();i++){
         int child=adj[node][i];
         ed++;
         if(!visited[child]){
             pair<int,int> p=dfscount(child,adj,visited);
             ve=ve+p.first;
             ed=ed+p.second;
         }
     }
     return make_pair(ve,ed);
}

int dfschild(int node,vector<vector<int> > &adj,int visited[]){
    visited[node]=1;
    int sum=0;
    for(int i=0;i<adj[node].size();i++){
        int child=adj[node][i];
        if(!visited[child]){
            int r=dfschild(child,adj,visited);
            sum+=r+1;
        }
    }
    return sum;
}
ll dfs(int node,vector<vector<int> > &adj,int visited[],int parent){
     int count=0;
     for(int i=0;i<adj[node].size();i++){
         int child=adj[node][i];
         if(child==parent){
             continue;
         }
         if(visited[child]==0){
             visited[child]=1;
             count+=dfs(child,adj,visited,node);
         }else{
             count++;
        }
     }
     return count;
 }
void dfs(int node,vector<vector<int> > &adj,int visited[],int len[],int in[]){
     for(int i=0;i<adj[node].size();i++){
         int child=adj[node][i];
         len[child]=maxi(len[child],len[node]+1);
         if(visited[child]==0){
             visited[child]=1;
             dfs(child,adj,visited,len,in);
         }
        
     }
}
 int dfs(int node,vector<vector<int> > &adj,int visited[],int parent,int *sum){
     *sum=*sum+1;
     int count=0;
     int counter=0;
     for(int i=0;i<adj[node].size();i++){
        
                 if(adj[node][i]==node){
                     count++;
             continue;
         }
         int child=adj[node][i];
         if(visited[child]==0){
             visited[child]=1;
             int a=dfs(child,adj,visited,node,sum);
            count+=a+1;
         }else{
             if(counter==1){
                 count++;
             }else{
                 if(child!=parent){
                     count++;
                }else{
                     counter=1;
                 }
             }
         }
     }
     return count;
}
int dfs(int node,vector<vector<int> > &adj,int visited[],int dp[]){
    int count=0;
    for(int i=0;i<adj[node].size();i++){
        int child=adj[node][i];
        if(visited[child]==0){
            visited[child]=1;
            int a=dfs(child,adj,visited,dp);
            count=max(count,a+1);
        }else{
            count=max(count,dp[child]+1);
        }
    }
    dp[node]=count;
    return count;
}
void dfsdp(int node,vector<vector< int> > &adj,int visited[],int* x){
    if(*x>=1000000){
        return;
    }
    *x=*x+1;
    visited[node]=1;
    for(int i=0;i<adj[node].size();i++){
        int child=adj[node][i];
        if(!visited[child]){
            dfsdp(child,adj,visited,x);
        }
        
    }
    visited[node]=0;
    return;
}
ll dfsbipartite(ll node,vector<vector<ll> > &adj,ll visited[],ll color[]){
     cout<<node<<endl;
     for(int i=0;i<4;i++){
        cout<<color[i]<<" ";
     }
     cout<<endl;
    visited[node]=1;
    ll coloring;
    if(color[node]==1){
        coloring=2;
    }else{
        coloring=1;
    }
    ll sum=0;
    for(ll i=0;i<adj[node].size();i++){
        ll child=adj[node][i];
         cout<<node<<" "<<child<<endl;
         cout<<visited[child]<<" "<<color[node]<<" "<<color[child]<<endl;
        
        if(visited[child]==1){
            if(color[node]==color[child]){
                return 1;
            }
        }else{
             cout<<child<<endl;
            color[child]=coloring;
            sum+=dfsbipartite(child,adj,visited,color);
        }
    }
    return sum;
}
void dfstemp(ll node,vector<vector<ll> > &adj,ll visited[],ll color[],ll* white,ll* black,vector<ll> &ve){
    ve.push_back(node);
    visited[node]=1;
    ll coloring;
    if(color[node]==1){
        coloring=2;
    }else{
        coloring=1;
    }
    for(ll i=0;i<adj[node].size();i++){
        ll child=adj[node][i];
        if(!visited[child]){
            color[child]=coloring;
            if(coloring==1){
                *white=*white+1;
            }else{
                *black=*black+1;
            }
            dfstemp(child,adj,visited,color,white,black,ve);
        }
    }
    return;
}
int recur(int node,int visited[],vector<vector<int> > m,int color[]){
    visited[node]=1;
    int coloring;
    if(color[node]==1){
        coloring=0;
    }else{
        coloring=1;
    }
    int counter=0;
    for(int i=0;i<m[node].size();i++){
        int child=m[node][i];
        if(node==child){
            counter=1;
            continue;
        }
        if(!visited[child]){
            color[child]=coloring;
            int ans=recur(child,visited,m,color);
            if(ans==1){
                counter=1;
            }
        }else{
            if(color[child]!=coloring){
                counter=1;
            }
        }
    }
    // cout<<node<<" "<<counter<<endl;
    return counter;
}
vector<int>adjList[N];
int dfs(int node,int parent) {
    visited[node] = true;
    for (auto adjNode : adjList[node]) {
        if (!visited[adjNode]) {
            group.pb(adjNode);
            dfs(adjNode, node);
        }
        else if (visited[adjNode] && adjNode != parent)
            return 1;
    }
    return 0;
}
 */
/*
void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = 1;
    while (!q.empty()) {
        group.pb(q.front());
        for (auto adjNode : adjList[q.front()])
            if (!visited[adjNode])
                q.push(adjNode), visited[adjNode] = 1;
        q.pop();
    }
}

void dijkstra(int source, vector<vector<pair<int,int>>>&graph) {
    int n = graph.size();
    vector<int> dist(n, inf), pre(n, -1);
    // cost , node
    priority_queue<pair<int, int>> nextToVisit;

    dist[source] = 0;
    pre[source] = source;
    nextToVisit.push({0, source});

    while (!nextToVisit.empty()) {
        int u = nextToVisit.top().second;
        nextToVisit.pop();
        if (visited[u])continue;
        visited[u] = 1;
        for (auto e : graph[u]) {
            int v = e.first;
            int c = e.second;
            if (dist[u] + c < dist[v]) {
                dist[v] = dist[u] + c;
                pre[v] = u;
                nextToVisit.push({-dist[v], v});
            }
        }
    }
}
void dfs(int node) {
    group.pb(node);
    visited[node] = true;
    for (auto adjNode: adjList[node])
        if (!visited[adjNode])
            dfs(adjNode);
}
