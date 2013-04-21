#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <functional>
#include <numeric>
#include <bitset>
#include <sstream>

using namespace std;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long ll;
typedef unsigned int uint;

inline int toi(string s){int v; istringstream iss(s);iss>>v;return v;}
template<class T> inline string tos(T x){ostringstream oss;oss<<x;return oss.str();}

#define All(a)  (a).begin(),(a).end()
#define Rall(a) (a).rbegin(),(a).rend()
#define pb push_back
#define mp make_pair
#define sz(a) int((a).size())
#define exist(s,e) ((s).find(e)!=(s).end())

#define Forall(i,v)   for(int i=0;i<(int)v.size();++i)
#define For(i,a,b)    for(int i=(a);i<(b);++i)
#define ForD(i,a,b)   for(int i=(a);i>(b);--i)
#define Step(i,a,b,s) for(int i=(a);i<(b);i+=(s))
#define Rep(i,n)      for(int i=0;i<(n);++i)
#define Each(i,c)     for(typeof((c).begin()) i=(c).begin();i!=(c).end();++i)

#define Fill(a,b)   memset(a,b,sizeof(a))
#define Clear(a)    memset((a),0,sizeof(a))
#define Sort(c)     sort((c).begin(),(c).end())

#define MinOf(x)    *min_element(All(x))
#define MaxOf(x)    *max_element(All(x))

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

VI type_of_chest;
VVI inkeys_of_chest;
ll z;

int N = 200;

bool check(VI n_keys, VI n_opened){
	int n = type_of_chest.size();
	queue<int> keys;
	Rep(k,N)
		if(n_keys[k]>0)
			keys.push(k);
	while(!keys.empty()){
		int key = keys.front();
		keys.pop();
		Rep(i,n){
			if(type_of_chest[i]==key && !n_opened[i])
			{
				n_opened[i] = true;
				foreach(inkeys_of_chest[i],inkey)
				{
					if(n_keys[*inkey]==0){
						n_keys[*inkey]++;
						keys.push(*inkey);
					}
				}
			}
		}
	}
	Rep(i,n)
		if(!n_opened[i]) return false;
	return true;
}

VI solve(VI &n_keys){
	int n = type_of_chest.size();
	VI n_opened(n,0);
	VI order;
	Rep(t,n){
		Rep(i,n){
			// open i th chest with key k
			if(n_opened[i]) continue;
			int k = type_of_chest[i];
			if(n_keys[k]==0) continue;
			n_keys[k]--;
			foreach(inkeys_of_chest[i],inkey)
				n_keys[*inkey]++;
			n_opened[i] = true;
			if(check(n_keys, n_opened))
			{
				order.pb(i+1);
				break;
			}
			n_keys[k]++;
			foreach(inkeys_of_chest[i],inkey)
				n_keys[*inkey]--;
			n_opened[i] = false;
		}
	}
	return order;
}

bool pre_check(VI &keys){
	int n = type_of_chest.size();
	VI n_types(200,0);
	VI n_keys(keys);
	foreach(type_of_chest,itr)
		n_types[*itr] += 1;
	foreach(inkeys_of_chest,inkeys){
		foreach(*inkeys,itr){
			n_keys[*itr] += 1;
		}
	}
	Rep(i,n){
		if(n_keys[i]<n_types[i])
			return false;
	}
	return true;
}

void main2(void){
	z = 0;
	int k,n;
	cin >> k >> n;
	VI n_keys(N,0);
	VI opened(N,0);
	type_of_chest.empty();
	type_of_chest.resize(n,0);
	inkeys_of_chest.empty();
	inkeys_of_chest.resize(n);
	Rep(i,k){
		int key;
		cin >> key;
		n_keys[key-1]++;
	}
	Rep(i,n){
		int tk,nk;
		cin >> tk;
		type_of_chest[i] = tk-1;
		cin >> nk;
		VI inkeys;
		Rep(j,nk){
			int ik;
			cin >> ik;
			inkeys.pb(ik-1);
		}
		inkeys_of_chest[i] = inkeys;
	}
	bool f = pre_check(n_keys);
	if(f){
		VI order = solve(n_keys);
		if(order.size()==n){
			foreach(order,k)
				cout << " " << *k;
			cout << endl;
		}else{
			cout << " IMPOSSIBLE" << endl;
		}
	}
	else{
		cout << " IMPOSSIBLE" << endl;
	}
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d:",t+1);
		main2();
	}
	return 0;
}
