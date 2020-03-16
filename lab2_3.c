/*lab2 prog3-print the complex number with the largest radius. */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define NUM 3

typedef struct{

	float real;
	float imagenary;

}complex; 

float CRadius(complex num);
complex* Cmax(complex* arr);


void main() {
	int i;
	complex arr[NUM], *index;
	float max_re,max_im;
	printf("Enter %d complex numbers:\n", NUM);
	for (i = 0; i < NUM; i++)
		scanf("%f %f", &arr[i].real, &arr[i].imagenary);
	max_re = Cmax(arr)->real;
	max_im = Cmax(arr)->imagenary;
	index = Cmax(arr);

	printf("the max complex number is %0.2f + %0.2fi\n", max_re, max_im);
	printf("the radius of the max number is %0.2f", CRadius(*index));
	

}

/*func name: CRadius
input: complex num
output: return float
algorithm: calculate the radius of a given complex number.*/
float CRadius(complex num) {
	float re = num.real , im= num.imagenary,radius;
	radius = sqrt(pow(re, 2) + pow(im, 2));
	return radius;
}

/*func name: Cmax
input: complex* arr
output: pointer to the complex number with the largest radius in the array.
algorithm: compare the radius of each number in the array to find max.*/
complex* Cmax(complex* arr) {
	float max = 0;
	int i, index = 0,num=NUM;

	for (i = 0; i < num; i++) {
		if (CRadius(arr[i]) > max) {
			max = CRadius(arr[i]);
			index = i;
		}
		
	}

	return &arr[index];
}