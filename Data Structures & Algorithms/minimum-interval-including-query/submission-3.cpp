#define vi vector<int>

class ST
{
    public:
    vector<int> t, lazy;
    int N;

    void build(int v, int tl, int tr, vi &arr)
    {
        if (tl > tr)
            return;
        if (tl == tr) {
            t[v] = arr[tl];
            return;
        }
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid, arr);
        build(2 * v + 1, mid + 1, tr, arr);
        t[v] = min( t[2 * v], t[2 * v + 1]);
    }

    ST(vi arr)
    {
        N = arr.size();
        t.resize(4 * N);
        lazy.resize(4 * N);
        build(1, 0, N - 1, arr);
    }

    ST(int n)
    {
        N = n;
        vector<int> arr(n,-1);
        t.resize(4 * N);
        lazy.resize(4 * N);
        build(1, 0, N - 1, arr);
    }

     void lazyUpdate(int v)
    {
        if (lazy[v])
        {
            t[v * 2] = t[v * 2 + 1] = t[v];
            lazy[v * 2] = lazy[v * 2 + 1] = true;
            lazy[v] = false;
        }
    }

    void update(int v, int tl, int tr, int ql, int qr, int val)
    {
        if (tr < ql || qr < tl)
            return;
        if (ql <= tl && tr <= qr)
        {
            t[v] = val;
            lazy[v] = 1;
            return;
        }
        lazyUpdate(v);
        int mid = (tl + tr) / 2;
        update(2 * v, tl, mid, ql, qr, val);
        update(2 * v + 1, mid + 1, tr, ql, qr, val);
        t[v] = min( t[2 * v], t[2 * v + 1]);
    }

    int query(int v, int tl, int tr, int ql, int qr)
    {
        if (tr < ql || qr < tl)
            return INT_MAX;
        if ( ql <= tl && tr <= qr)
            return t[v];

        lazyUpdate(v);
        int mid = (tl + tr) / 2;
        return min( query(2 * v, tl, mid, ql, qr),
               query(2 * v + 1, mid + 1, tr, ql, qr));
    }

    int query(int l,int r) {
        return query(1, 0, N - 1, l , r );
    }

    void update(int l,int r,int val) {
        update(1, 0, N - 1, l , r, val );
    }
};

class Solution {

public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& q) {

        vector<int> ans;
        ST st = ST(*max_element(q.begin(),q.end())+1);
        
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b){
            return a[1] - a[0] > b[1] - b[0];
        });

        for ( auto x : intervals ) {
            int s = x[0];
            int e = x[1];
            st.update(s,e,e-s+1);
        }

        for ( auto x : q)
            ans.push_back(st.query(x,x));

        return ans;
    }
};
