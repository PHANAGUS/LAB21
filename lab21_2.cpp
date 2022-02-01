#include<iostream>
using namespace std;

struct Rect{
	double x,y,w,h;
};

double overlap(Rect * R1, Rect * R2){
	double lapx, lapy, A;
	if(R1->x <= R2->x)
	{
		if(R1->x+R1->w > R2->x && R1->x+R1->w <= R2->x+R2->w)
		{
			lapx = R1->x + R1->w - R2->x;
		}
		else if(R1->x+R1->w > R2->x && R1->x+R1->w > R2->x+R2->w)
		{
			lapx = R2->w;
		}
		else lapx = 0;
	}
	else if(R2->x < R1->x)
	{
		if(R2->x+R2->w > R1->x && R2->x+R2->w <= R1->x+R1->w)
		{
			lapx = R2->x + R2->w - R1->x;
		}
		else if(R2->x+R2->w > R1->x && R2->x+R2->w > R1->x+R1->w)
		{
			lapx = R1->w;
		}
		else lapx = 0;
	}

	if(R1->y >= R2->y)
	{
		if(R1->y-R1->h < R2->y && R1->y-R1->h >= R2->y-R2->h)
		{
			lapy = R1->h - (R1->y - R2->y);
		}
		else if(R1->y-R1->h < R2->y && R1->y-R1->h < R2->y-R2->h)
		{
			lapy = R2->h;
		}
		else lapy = 0;
	}
	else if(R2->y > R1->y)
	{
		if(R2->y-R2->h < R1->y && R2->y-R2->h >= R1->y-R1->h)
		{
			lapy = R2->h - (R2->y - R1->y);
		}
		else if(R2->y-R2->h < R1->y && R2->y-R2->h < R1->y-R1->h)
		{
			lapy = R1->h;
		}
		else lapy = 0;
	}
	A = lapx*lapy;
	if(A < 0) A*= -1;
	return A;
}

int main()
{
	/*Rect R1 = {1,1,5,5};
	Rect R2 = {2,2,5,5};
	cout << overlap(&R1,&R2);*/

	/*Rect R1 = {1,1,5,5};
	Rect R2 = {7,2,3,3};
	cout << overlap(&R1,&R2);*/

	Rect R1 = {-1,2,6.9,9.6};
	Rect R2 = {0,0,1.2,2.5};
	cout << overlap(&R1,&R2);
}