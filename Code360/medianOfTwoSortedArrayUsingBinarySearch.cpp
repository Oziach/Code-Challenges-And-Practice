double median(vector<int>& a, vector<int>& b) {
	int m = a.size();
	int n = b.size();

	if(n < m){return median(b, a);}

	int k = (m + n) / 2;

	int s = 0;
	int e = m;

	while(s <= e){
		int mid1 = s + (e-s)/2;
		int mid2 = k - mid1;

		int l1, l2 = INT_MIN;
		int r1, r2 = INT_MAX;

		if(mid1 > 0){l1 = a[mid1-1];}
		if(mid2 > 0){l2 = b[mid2-1];}
		if(mid1 < a.size()){r1 = a[mid1];}
		if(mid2 < b.size()){r2 = b[mid2];}

		if(max(l1,l2) <= min(r1,r2)){
			if((m+n) & 1){
				return min(r1,r2);
			}
			else{
				return (max(l1,l2) + min(r1,r2)) / (double) 2;
			}
		}
		else if(l1 > r2){
			e = mid1-1;
		}
		else{
			s = mid1+1;
		}

	}

	return -1;

}