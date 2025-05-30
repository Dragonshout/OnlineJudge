int main(){
	int n=0;
	int x=0;
	scanf("%d",&n);
	while(n!=1){
		if(n%2==0){
			n=n/2;
			x++;
		}
	else{
		n=(n*3+1)/2;
		x++;
	}
}
	printf("%d",x);
	return 0;
	
}