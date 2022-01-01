#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
using namespace std;

#ifdef LOCAL
  #define eprintf(...) fprintf(stderr, __VA_ARGS__);fflush(stderr);
#else
  #define eprintf(...) 42
#endif


#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define fi first
#define se second

const int N = 1e5+5;
void solve()
{

    int n;
    cin >> n;
    vector<int> a(n + 1);
    priority_queue<int, vector<int>, less<int> > red;
    priority_queue<int, vector<int>, greater<int> > blue;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'R')
        {
            red.push(a[i]);
        }
        else
        {
            blue.push(a[i]);
        }
    }
    int t1 = n, t2 = 1;
    while (!red.empty())
    {
        int x = red.top();
        red.pop();
        if (x > t1)
        {
            cout << "NO\n";
            return;
        }
        t1 -= 1;
    }
    while (!blue.empty())
    {
        int x = blue.top();
        blue.pop();
        if (x < t2)
        {
            cout << "NO\n";
            return;
        }
        t2 += 1;
    }
    cout << "YES\n";
}
int main()
{

//  freopen("input.txt", "r", stdin);
//  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);
  while(t--) solve();

  return 0;
}
