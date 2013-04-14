#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>

using namespace std;

#define REP(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)

vector<string> fairs;

bool check(string s){
	int l = (int)s.length();
	int i,j,n,m;
	if(l>50)
		return false; 
	if(l<1)
		return true;
	vector<int> v(2*l-1,0);
	REP(i,l) REP(j,l) {
		n = s[i]-'0';
		m = s[j]-'0';
		v[i+j] += n*m;
		if(v[i+j]>9) return false;
	}
	if(v[0]>0){
		string r;
		foreach(v,it)
			r += (*it)+'0';
		fairs.push_back(r);
	}
	return true;
}

void dfs(string s){
	int i;
	if(check(s))
		REP(i,4){
			string d = string(1,'0'+i);
			dfs(d+s+d);
		}
}

bool compare(string &s1, string &s2){
	if(s1.length() > s2.length())
		return true;
	if(s1.length() < s2.length())
		return false;
	return !(s1 < s2);
}

void main2(void){
	string A, B;
	cin >> A >> B;
	int c = 0;
	foreach(fairs,i){
		if(compare(*i,A) && compare(B, *i))
			c += 1;
	}
	cout << c << endl;
}

int main(void){
	int T,t;
	dfs("");
	dfs("0");
	dfs("1");
	dfs("2");
	dfs("3");
	cin >> T;
	REP(t,T){
		printf("Case #%d: ",t+1);
		main2();
	}
	return 0;
}
