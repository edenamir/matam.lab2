/*Lab2 prog1- determinate if a given point is inside a circle  */
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>

/*point structure- stores x and y values of a point*/
typedef struct {
	double x;
	double y;
}point;

/*circle structure- stores a point and radius of a circle  */
typedef struct {
	point center;
	int radius;
}circle;


int is_in(point, circle);

void main() {

	point given_point;
	circle given_circle;
	printf("Enter your coordinates of your point:");
	scanf("%lf %lf", &given_point.x, &given_point.y);

	printf("Enter the radius and the center of your circle:");
	scanf("%d %lf %lf", &given_circle.radius, &given_circle.center.x, &given_circle.center.y);

	if (is_in(given_point,given_circle))
		printf("The point is included in the circle");
	else
		printf("The point is not included in the circle");

}

/*func name: is_in
input: point struct, circle struct
output: int
algorithm: check if the distance of point from center is smaller than the radius (thus in the circle). */
int is_in(point given_point, circle given_circle) {
	int radius = given_circle.radius;
	double distance, delta_x = given_point.x- given_circle.center.x, delta_y = given_point.y- given_circle.center.y;
	distance = sqrt(pow(delta_x, 2) + pow(delta_y, 2));
	if (radius>=distance)
		return 1;
	return 0;
}