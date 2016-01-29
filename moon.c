#include <stdio.h>
#include <math.h>
#include <stdbool.h>

/*
* Simple Lunar Lander Program
* By: Hoyoung Jung 5 0 5 4 .4 .6
* Best Landing: Time = (14) s, Fuel = (86.0) kg, Velocity = (-1.82) m/s^2
* 
* This program is a lunar landing game that is intended to have the best/safest landing with the least amount of fuel consumption.
* Try and have the best landing!
* If you fall to fast, you die!
*/

int main()
{
	printf("Lunar Lander - (c) 2012, by Hoyoung Jung\n");
	double altitude = 100;  /* Meters */
    double velocity = 0;    /* Meters per second */
    double fuel = 100;      /* Kilograms */
    double power = 1.5;     /* Acceleration per pound of fuel */
    double g = -1.63;       /* Moon gravity in m/s^2 */
    double burn;            /* Amount of fuel to burn */
    bool valid;			  	/* Boolean variable */
    double t = 0;		/* Time in the air */
    
    while(altitude>=0)
    {
		printf("Altitude: %.2f\n", altitude);
		printf("Velocity: %.2f\n", velocity);
		printf("You have %.1f kilograms of fuel\n", fuel);
		
		/* Program to test the users input for fuel burning/consumption*/
		do
		{
			valid = false;   /* Assume invalid until we know otherwise */
			printf("How much fuel would you like to burn: ");
			scanf("%lf", &burn);
			if(burn < 0)
				{
					printf("You can't burn negative fuel\n");
					valid = false;
				}
			else if(burn > 100)
				{
					printf("You can't burn fuel you don't have\n");
					valid = false;
				}	
			else
				{
					if(burn <= 5)
					{
						printf("Burning %.1f kilograms of fuel\n", burn);
						valid = true;
					}
					else
					{
						printf("That is too much fuel consumption per second\n");
						valid = false;
					}
				}
		}while(!valid);
		/*_________________________________________________________________*/
		if(fuel>0)
			{
				velocity = velocity + g + power * burn;
				altitude += velocity;
				fuel -= burn;
			}
		else if(fuel<=0)
			{
				printf("You are out of fuel and free falling, so pressing the gas doesn't do you much\n");
				velocity = velocity + g;
				altitude += velocity;
				fuel = 0;
			}
		t++;
    }
    
	/* Test if the user has landed safely or not */
    if(fabs(velocity) > 3)
    {
        printf("Your next of kin have been notified because you are dead!\n");
    }
    else
    {
    	printf("You have landed safely\n");
    	printf("Landing: Time = %.0f s, Fuel = %.1f kg, Velocticy = %.2f m/s^2\n", t, fuel, velocity);
    }
    /*____________________________________________________________________*/
}
