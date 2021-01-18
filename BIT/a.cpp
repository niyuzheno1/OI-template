//credit : geeksforgeeks, Zach Ni
int lsb(int x){
    return x & (-x);
}
typedef long long ll;
#define MODX 998244353

class FenwickTree{
public:
    ll * B; 
    int n;
    FenwickTree(int n){
        this->n = n;
        this->B = new ll[n+3];
        for(int i = 0; i <= n+1; ++i)
            this->B[i] = 0;
    }
    ll getsum(int index){
        ll sum = 0;
        index = index + 1;
        while(index > 0){
            sum = (this->B[index] + sum) % MODX;
            index -= lsb(index);
        }
        return sum;
    }
    void update(int index, ll val){
        index = index + 1;
        while(index <= n){
            this->B[index] =  (this->B[index] + val ) %MODX;
            index += lsb(index);
        }
    }

};
ll add(ll x, ll y){
    return (x+y)%MODX;
}

ll mul(ll x, ll y){
    return (x*y)%MODX;
}
