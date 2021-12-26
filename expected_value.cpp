#include<stdio.h>
double arr[100]={0,0,1.5,2.25};

long long int fac(int t){
	long long int k=1;
	for(int i=1;i<=t;i++){
		k*=i;
	}
	return k;
}

long long int nCr(int n, int k){
	return fac(n)/fac(n-k)/fac(k);
}


long long int power(int n, int k){
	int temp=1;
	for(int i=0;i<k;i++){
		temp*=n;
	}
	return temp;
}

long double sigma(int n){
	double temp=0;
	for(int k=1;k<=n-1;k++){
		temp+=(double)arr[k]*nCr(n,k)/(power(2,n)-2)+(double)power(3,n-1)/(power(2,n)-2)/(power(2,n)-2)*nCr(n,k);
	}
	return temp;
}

int main(){
//printf("%d\n",fac(5));
//printf("%d\n",nCr(5,1));
//printf("%d\n",power(2,2));

for(int j=2;j<=20;j++){
	arr[j]=sigma(j);
	printf("%d, %lf\n",j,arr[j]);
}
double sum = 0;

printf("%d\n",sizeof(long long int)); 
printf("%d\n",sizeof(int));
	for(int i=1;i<=31;i++){
		sum += (double)i*i*2/power(3,i);
	}
	
	printf("V(x): %lf", sum-(9.0/4));
}
