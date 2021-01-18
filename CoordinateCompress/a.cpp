// credit: Zach Ni
void CoordinateCompress(vector<int> u, vector<int> & v){
    sort(u.begin(),u.end()); 
    map<int,int> mpitoind;
    int n = u.size();
    for(int i = 0; i< n; ++i)
        mpitoind[u[i]] = i;
    for(int i = 0; i < n; ++i)
        v[i] = mpitoind[v[i]];
}