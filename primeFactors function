// 18 = 2 * 3 * 3
vector<int> primeFactors(int n){
	vector<int> v;
	while(n%2==0){
		v.push_back(2);
		n/=2;
	}
	for(int i=3;i*i<=n;i+=2){
		while(n%i==0){
			v.push_back(i);
			n/=i;
			if(n==1){
				break;
			}
		}
	}
	if(n>1){
		v.push_back(n);
	}
	return v;
