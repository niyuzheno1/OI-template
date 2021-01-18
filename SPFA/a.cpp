/*credit Zach Ni
https://codeforces.com/contest/1442/submission/100226053
*/
while(!q.empty()){
		pii f = q.front(); q.pop();
		int vx = f.first;
		int lev = f.second;
		int odd = lev % 2;
		for(int i = 0; i < edges[vx].size(); ++i){
			int nvx = edges[vx][i].first;
			int cost = edges[vx][i].second;
			if(cost == odd){
				if( best[nvx][lev] == -1|| best[nvx][lev]>best[vx][lev] + 1){
					best[nvx][lev] = best[vx][lev] + 1;
					q.push(make_pair(nvx, lev));
				}
			}else{
				if(lev < 31)
					if( best[nvx][lev+1] == -1|| best[nvx][lev+1]>best[vx][lev] + 1){
						best[nvx][lev+1] = best[vx][lev] + 1;
						q.push(make_pair(nvx, lev+1));
					}
			}
		}
	}