/*credit from: geeksforgeeks*/
typedef pair<int,int> pii;
#define MAXN 100010
int f[MAXN][32];

void process(vector<pii> & nums, int n){
    for(int i = 0 ; i < n; ++i)
        f[i][0] = i;
   for (int j = 1; (1 << j) <= n; ++j){
       for(int i = 0; (i+(1<<j) - 1) < n; ++i)
            if(nums[f[i][j-1]] < nums[f[i+(1<<(j-1))][j-1]])
                f[i][j] = f[i][j-1];
            else
                f[i][j] = f[i+(1<<(j-1))][j-1];    
   }
}

int q(vector<pii> & nums, int l, int r){
    int j = (int)log2(r-l+1);
    if (nums[f[l][j]] <= nums[f[r-(1<<j)+1][j]])
        return f[l][j];
    else
        return f[r-(1<<j)+1][j];
}

