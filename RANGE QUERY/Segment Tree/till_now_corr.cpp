typedef long long ll;

ll given[100004];
ll Tree[400005];
void SegInit(ll node , ll s , ll e)
{
    if(s==e){
        Tree[node] = given[s] ; return;
    }
    ll mid = (s+e)/2;
    ll l = 2*node;
    ll r = l+1;
    SegInit(l,s,mid);
    SegInit(r,mid+1,e);
    Tree[node] = Tree[l] + Tree[r];
}
void SegUpdate(ll node, ll s, ll e, ll in, ll x)
{
    if(in<s || in>e) return;
    if(s==in && e==in){
        Tree[node] = x; return;
    }
    ll mid = (s+e)/2;
    ll l = 2*node;
    ll r = l+1;
    SegUpdate(l,s,mid,in,x);
    SegUpdate(r,mid+1,e,in,x);
    Tree[node] = Tree[l] + Tree[r];
}

ll SegQuery(ll node, ll s, ll e, ll x, ll y)
{
    if(x>e || y<s){
        return 0;
    }
    if(s>=x && e<=y){
        return Tree[node];
    }
    ll mid = (s+e)/2;
    ll l = 2*node;
    ll r = l+1;
    ll q1 = SegQuery(l,s,mid,x,y);
    ll q2 = SegQuery(r,mid+1,e,x,y);
    return q1+q2;
}