#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/priority_queue.hpp>
//#pragma GCC optimize("O3")
//#pragma GCC target("sse4")
//#pragma GCC target("avx2")
 
#define deb(x) cout << #x << " = " << x << "\n"
#define all(x) (x).begin(), (x).end()
#define len(x) (int) x.size()
#define lsb(x) (x) & -(x)
#define l(x) (x << 1) + 1
#define r(x) (x << 1) + 2
#define v(x) (int)(x - 'a')
 
#define xx first
#define yy second
#define mp make_pair
#define pb push_back
#define lb lower_bound
#define ub upper_bound
 
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ld, ld> pld;
typedef pair <ll, ll> pll;
 
template <class T1, class T2 = less <T1>> using pb_heap = __gnu_pbds::priority_queue <T1, T2, binary_heap_tag>;
template <class T1, class T2 = null_type, class T3 = less <T1>> using pb_map = tree <T1, T2, T3, rb_tree_tag, tree_order_statistics_node_update>;
template <class T1, class T2 = null_type, class T3 = hash <T1>> using pb_umap = gp_hash_table <T1, T2, T3>;
template <class T1, class T2, class T3 = hash <T1>> using umap = unordered_map <T1, T2, T3>;
template <class T> using uset = unordered_set <T>;
template <class T> using vec = vector <T>;
 
const ll infll = numeric_limits <ll>::max() >> 1;
const int inf = numeric_limits <int>::max() >> 1;
const int N = 1e6 + 1;

int solve(int l, int r) 
{
     bitset <N> isprime;
     for (int i = l; i <= r; ++i) {
          isprime[i - l] = 1;
     }
     if (l == 1) {
          isprime[0] = 0;
     }
     for (int i = 2; i * i <= r; ++i) {
          for (int j = (l + i - 1) / i; j <= r / i; ++j) {
               isprime[j * i - l] = 0;
          }
     }
     int res = 0;
     for (int i = l; i <= r; ++i) {
          res += isprime[i - l];
     }
     return res;
}

void input() 
{
     cout << solve(1, 10) << "\n";
}

void solve()
{
}

int main() 
{
     ios_base::sync_with_stdio(false);
     cin.tie(0), cout.tie(0);
     input();
     solve();
}