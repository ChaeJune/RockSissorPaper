#include<stdio.h>
double arr[]={0,0,1.5,2.25,3.21429,4.48571,6.21982,8.64674, 12.1044, 17.0919, 24.3496, 34.9795, 50.625, 73.7404, 107.993, 158.868, 234.574, 347.395, 515.729, 767.136, 1142.9032, 1704.905174, 2545.877839, 3804.832603, 5690.1708, 8514.3502, 12745.877651, 19087.2886, 28592.1068, 42840.2677, 65201.2387, 96228.6760, 144252.3842, 216226.2209, 324259.911928, 486216.7217, 729109.8928, 1093397.2222, 1639762.8240, 2459229.643956, 3688328.070956};
double G[100]={0,};
int save[100]={0,};
bool is_prime3(int n)
{
	
	//int cnt3;
    if(n<2){return false;}
    for(int i=2;i*i<=n;i++){if(n%i==0){
	//cnt3++;
	return false;}}return true;
}

double func(int i){
	
	if(G[i]!=0)return G[i];
	else{
		
		for(int j=2;j<=i;j++){
			
			if(i%j==0){
				double temp = arr[j]*((float)i/j)+func(i/j);
				if(G[i]==0||G[i]>temp){
				G[i]=temp;
				save[i] = j;
				}
			}	
		}
		
		
		return G[i];
	}
}



int main(){
	for(int i=2;i<=40;i++){
		if(is_prime3(i)){
			G[i]=arr[i];
		}
	//	printf("전체 인원 수: %2d, isprime: %d, 그룹 구성원의 수: %2d, G(N): %lf \n",i,is_prime3(i),save[i]==0?i:save[i],func(i));
	if(is_prime3(i)!=1)
		printf("전체 인원 수: %2d, isprime: %d, 그룹 구성원의 수: %2d, G(N): %lf \n",i,is_prime3(i),save[i]==0?i:save[i],func(i));
	//	printf("%2d,%2d,%lf\n",i,save[i]==0?i:save[i],func(i));
	}
}	
