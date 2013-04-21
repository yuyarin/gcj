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

bool solve(VI &keys, VI &opened, VI &order, int n_opened){
	int n = type_of_chest.size();
	if(n_opened==n){
		Rep(i,n-1)
			cout << order[i]+1 << " ";
		cout << order[n-1]+1 << endl;
		return true;
	}
	Rep(i,n){
		if(opened[i]) continue;
		Rep(key,200){
			if(keys[key]<1) continue;
			if(type_of_chest[i]!=key) continue;
			VI new_keys(keys);
			new_keys[key]--;
			foreach(inkeys_of_chest[i],inkey)
				new_keys[*inkey]++;
			// check
			VI available_keys(new_keys);
			int kc = -1;
			Rep(j,n){
				if(type_of_chest[j]==key)
				{
					if(opened[j]==0)
						kc++;
				}
				else
				{
					foreach(inkeys_of_chest[j],inkey)
						available_keys[*inkey]++;
				}
			}
			if(kc>0 && available_keys[key]==0)
				 continue;
			VI new_opened(opened);
			new_opened[i] = 1;
			VI new_order(order);
			new_order.pb(i);
			bool can_open = solve(new_keys, new_opened, new_order, n_opened+1);
			if(can_open) return true;
		}
	}
	return false;
}

bool pre_check(VI &keys){
	int n = type_of_chest.size();
	VI n_types(200,0);
	VI n_keys(keys);
	foreach(type_of_chest,itr)
		n_types[*itr] += 1;
	foreach(inkeys_of_chest,inkeys)
		foreach(*inkeys,itr)
			n_keys[*itr] += 1;
	Rep(i,n)
		if(n_keys[i]<n_types[i])
			return false;
	return true;
}

void main2(void){
	z = 0;
	int k,n;
	cin >> k >> n;
	VI n_keys(200,0);
	VI opened(200,0);
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
	VI order;
	bool f = pre_check(n_keys);
	if(f)
		f &= solve(n_keys, opened, order,0);
	if(!f)
		cout << "IMPOSSIBLE" << endl;
}

int main(void){
	int T,t;
	cin >> T;
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
