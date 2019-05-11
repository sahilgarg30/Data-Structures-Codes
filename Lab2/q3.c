#include <stdio.h>
#include <math.h>
float *getData(float a){
	float *ptr = &a;
	printf("Enter the coefficients of equation ax^2+bx+c - \n");
	scanf("%f%f%f",ptr,ptr+1,ptr+2);
	return ptr;
}
float *quadratic(float *ptr,float a){
	float ab = *ptr;
	float d = (*(ptr+1))*(*(ptr+1))-4*(*ptr)*(*(ptr+2));
	float *rootp = &a;
	if(d==0.0){
		*(rootp) = -(*(ptr+1))/(2*ab);
		*(rootp+1) = -(*(ptr+1))/(2*ab);
	}
	else if(d>0.0){
		*(rootp) = (-(*(ptr+1))+pow(d,0.5))/(2*ab);	
		*(rootp+1) = (-(*(ptr+1))-pow(d,0.5))/(2*ab);
	}
	else{
		*(rootp) = 32000;
		*(rootp+1) = -d;
	}
	return rootp;
}
void print_roots(float *roots,float *ptr,float a){
	float ab = a;
	if(*(roots)==32000){
		printf("The roots are complex and are %f+%f i and %f - %f i.\n",
			-(*(ptr+1))/(2*ab),(*(roots+1))/(2*ab),-(*(ptr+1))/(2*ab),(*(roots+1))/(2*ab));
	}
	else{
		printf("The roots are real and are - %f and %f\n",*(roots),*(roots+1));
	}
}
void main(){
	float a=0.0,b=0.0;
	float *ptr = getData(a);
	a = *ptr;
	float *roots = quadratic(ptr,b);
	print_roots(roots,ptr,a);
}