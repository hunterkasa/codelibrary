// http://www.shafaetsplanet.com/?p=604
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
using namespace std;
 
#define io ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP( i, n ) for( int i = 0; i < n; i++ )
#define rep(i, a, b) for (int i = a; i < b; i++)
#define endl '\n'
#define pb push_back
#define ppb pop_back
#define ANS(x) cout << x << endl;
#define MAX INT_MIN
#define MIN INT_MAX
#define INF 1000000007

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<long long> vll;
typedef vector<pair<int , int>> pi;
typedef vector<pair<long , long>> pll;

#define pii pair<int,int>
int fx[]={1,-1,0,0}; //ডিরেকশন অ্যারে
int fy[]={0,0,1,-1};
int cell[100][100]; //cell[x][y] যদি -১ হয় তাহলে সেলটা ব্লক
int d[100][100],vis[100][100]; //d means destination from source. 
int row,col;
void bfs(int sx,int sy) //Source node is in [sx][sy] cell.
{
	memset(vis,0,sizeof vis);
	vis[sx][sy]=1;
	queue<pii>q; //A queue containing STL pairs
	q.push(pii(sx,sy));
	while(!q.empty())
	{		
		pii top=q.front(); q.pop();
		for(int k=0;k<4;k++)
		{
			int tx=top.first+fx[k];
			int ty=top.second+fy[k]; //Neighbor cell [tx][ty]
			if(tx>=0 and tx<row and ty>=0 and ty<col and cell[tx][ty]!=-1 and vis[tx][ty]==0) //Check if the neighbor is valid and not visited before.
			{				
				vis[tx][ty]=1;
				d[tx][ty]=d[top.first][top.second]+1; 
				q.push(pii(tx,ty)); //Pushing a new pair in the queue
			}
		}
	}
}

int main(){

}