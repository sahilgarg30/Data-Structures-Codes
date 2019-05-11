#include <stdio.h>
int gcd(int a,int b){
	if(a==0) return b;
	return gcd(b%a,a);
}
int lcm(int a,int b){
	static int temp = 1;
	if(temp%a==0 && temp%b==0)
		return temp;
	else{
		temp++;
		return lcm(a,b);	
	}
	
}
void main(){
	int a,b;
	printf("Enter the numbers - \n");
	scanf("%d%d",&a,& b);
	printf("GCD is - %d\n",gcd(a,b));
	printf("LCM is - %d\n",lcm(a,b));
}
