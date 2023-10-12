typedef long long ll;

const int maxn = 4e5;
int a[maxn], t[4*maxn];
void build( ll node, ll b, ll e ){
    if ( b == e ){
        t[node] = a[b];
        return;
    }
    ll left = 2*node;
    ll right = 2*node+1;
    ll mid = (b+e)/2;
    build(left, b, mid);
    build(right,mid+1,e);
    t[node] = t[left] + t[right]; 
}
ll query( ll node, ll b, ll e , ll i ,ll val ){
    if ( e < i || b > val )   return 0;
    if ( b >= i && e <= val )   return t[node];
    ll mid = (b+e)/2;
    ll left = 2*node;
    ll right = 2*node+1;
    return query(left,b,mid,i,val) + query(right, mid+1, e, i, val);
}
void update( ll node, ll b, ll e, ll i, ll x ){
    if ( i > e || i < b )   return;
    if ( b == e && b == i ){
        t[node] = x;
        return;
    }
    ll mid = (b+e)/2;
    ll left = 2*node;
    ll right = 2 * node+1;
    update(left, b, mid, i, x );
    update(right, mid+1, e, i, x);
    t[node] = t[left] + t[right];
}