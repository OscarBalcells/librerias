//SUMA
template<class T, int SZ> struct SegTree {
        T sum[2*SZ], lazy[2*SZ];
        SegTree() { for(int i = 0; i < 2*SZ; i++) sum[i] = lazy[i] = 0; }
        void push(int ind, int L, int R) {
                if (L != R) for(int i = 0; i < 2; i++) lazy[2*ind+i] += lazy[ind];
                sum[ind] += (R-L+1)*lazy[ind]; lazy[ind] = 0;
        }
        void pull(int ind) {
        	sum[ind] = sum[2*ind]+sum[2*ind+1]; 
        }
        void build() { 
        	for(int i = SZ-1; i >= 1; i--) pull(i); 
        }
        void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
                push(ind,L,R); if (hi < L || R < lo) return;
                if (lo <= L && R <= hi) { lazy[ind] = inc; push(ind,L,R); return; }
                int mid = (L+R)/2; upd(lo,hi,inc,2*ind,L,mid);
                upd(lo,hi,inc,2*ind+1,mid+1,R); pull(ind);
        }   
        T query(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
                push(ind,L,R); if (lo > R || L > hi) return 0;
                if (lo <= L && R <= hi) return sum[ind];
                int mid = (L+R)/2;
                return query(lo,hi,2*ind,L,mid)+query(lo,hi,2*ind+1,mid+1,R);
        }   
};


//MAXIMO
template<class T, int SZ> struct SegTree {
        T mx[2*SZ], lazy[2*SZ];
        SegTree() { for(int i = 0; i < 2*SZ; i++) mx[i] = lazy[i] = 0; }
        void push(int ind, int L, int R) {
                if (L != R) for(int i = 0; i < 2; i++) lazy[2*ind+i] += lazy[ind];
                mx[ind] += lazy[ind]; 
                lazy[ind] = 0;
        }
        void pull(int ind) { 
        	mx[ind] = max(mx[2*ind],mx[2*ind+1]); 
        }
        void build() { 
        	for(int i = SZ-1; i >= 1; i--) pull(i); 
        }
        void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
                push(ind,L,R); 
                if (hi < L || R < lo) return;
                if (lo <= L && R <= hi) { lazy[ind] = inc; push(ind,L,R); return; }
                int mid = (L+R)/2; upd(lo,hi,inc,2*ind,L,mid);
                upd(lo,hi,inc,2*ind+1,mid+1,R); pull(ind);
        }
        T query(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
                push(ind,L,R); 
                if (lo > R || L > hi) return -(int)1e9;
                if (lo <= L && R <= hi) return mx[ind];
                int mid = (L+R)/2;
                return max(query(lo,hi,2*ind,L,mid),query(lo,hi,2*ind+1,mid+1,R));
        }
};

//MINIMUM
template<class T, int SZ> struct SegTree {
        T mx[2*SZ], lazy[2*SZ];
        SegTree() { for(int i = 0; i < 2*SZ; i++) mx[i] = lazy[i] = 0; }
        void push(int ind, int L, int R) {
                if (L != R) for(int i = 0; i < 2; i++) lazy[2*ind+i] += lazy[ind];
                mx[ind] += lazy[ind]; 
                lazy[ind] = 0;
        }
        void pull(int ind) { 
        	mx[ind] = min(mx[2*ind],mx[2*ind+1]); 
        }
        void build() { 
        	for(int i = SZ-1; i >= 1; i--) pull(i); 
        }
        void upd(int lo,int hi,T inc,int ind=1,int L=0, int R=SZ-1) {
                push(ind,L,R); 
                if (hi < L || R < lo) return;
                if (lo <= L && R <= hi) { lazy[ind] = inc; push(ind,L,R); return; }
                int mid = (L+R)/2; upd(lo,hi,inc,2*ind,L,mid);
                upd(lo,hi,inc,2*ind+1,mid+1,R); pull(ind);
        }
        T query(int lo, int hi, int ind=1, int L=0, int R = SZ-1) {
                push(ind,L,R); 
                if (lo > R || L > hi) return (int)1e9;
                if (lo <= L && R <= hi) return mx[ind];
                int mid = (L+R)/2;
                return min(query(lo,hi,2*ind,L,mid),query(lo,hi,2*ind+1,mid+1,R));
        }
};

