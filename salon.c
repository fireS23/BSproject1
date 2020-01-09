#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct movie
{
	char name[40];		
};

struct sans
{
	struct movie movie;
	int zarfiat;
};

struct sans sans[7]={"Joker",20,"Marriage Story",25,"Parasite",30,"Toy Story 4",30,"Once Upon a Time in Hollywood",35,"Little Women",10,"The Irishman",20};
	

//vari//
int selection;
int isans;
int numberOfSeats;


void printWelcome(void);
void printSans(void);
void printZarfiatOfsans(int isans);
void reserve(void);
void exitt(void);




//program//
int main()
{

	
	printWelcome();
	
	while(selection!=2)
	{
		switch (selection)
		{
		case 1:
			printSans();
			printZarfiatOfsans(isans);
			reserve();
			
			system("pause");
            system("cls");
            printWelcome();
			break;
		case 2:
			exitt();
			break;
		}	
	}

	
}



//functions//

void printWelcome(void)
{
	printf("WELCOME TO THIS THEATER\n\nMAIN MENU:\n\n");
	printf("1.Reserve a seat\n");
	printf("2.Exit\n");
	printf("\nEnter your selection : ");
	scanf("%d",&selection);	
}

void printSans(void)
{
	int i;
	
	printf("\nThese are the sans:\n");
	for(i=0;i<7;i++)
	printf("%d.%-40s [%d:00]\n",i+1,sans[i].movie.name,11+2*i);
	printf("\nEnter your sans : ");
	scanf("%d",&isans);
}

void printZarfiatOfsans(int isans)
{
	printf("\nzarfiat of these movie is %d\n",sans[isans-1].zarfiat);
	printf("\nHow many seats do you want?\n");
	scanf("%d",&numberOfSeats);
}

void reserve(void)
{
	if(numberOfSeats<=sans[isans-1].zarfiat)
	{
		sans[isans-1].zarfiat=sans[isans-1].zarfiat-numberOfSeats;
		printf("successfully reserved.\n\n",sans[isans-1].zarfiat);
	}
	else
		printf("sorry, the numbers of seats are more than capacity.\n");	
}

void exitt(void)
{
	printf("\nThank you for using this system\n");
	exit(0);
}
