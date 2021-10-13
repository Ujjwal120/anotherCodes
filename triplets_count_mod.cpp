#define int long long

vector<int> solve(int n, vector<int> a, int b){
	vector<int> ct(b);
	
    for(int i=0;i<n;i++) ct[ a[i]%b ]++;
	
	
	vector<int> result1(b), r(b);
	
	for(int i=0;i<b;i++){
		for(int j=i+1;j<b;j++){
			result1[ (i+j)%b ]+= ct[i]*ct[j];
			r[ (i+2*j)%b ]-= ct[i]*ct[j]*ct[j];
			r[ (2*i+j)%b ]-= ct[i]*ct[i]*ct[j];
		}
	}	

	
	for(int i=0;i<b;i++){
		for(int j=0;j<b;j++){
			r[(i+j)%b] += result1[i]*ct[j];
		}
	}	
	
	
	for(int i=0;i<b;i++){
		r[ (3*i)%b ] += ct[i] * (ct[i]-1) * (ct[i]-2) /2;
		for(int j = 0; j < b; j++){
			if(i != j){
				r[ (2*i+j)%b ]+= 3 * ct[i] * (ct[i]-1) * ct[j]/2;
			}
		}
	}
	
	for(int i=0;i<b;i++){
		r[i] /= 3;
	}

    return r;
}