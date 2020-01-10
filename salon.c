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
	int capacity;
};
	

struct sans sans[7]={"Joker",20,"Marriage Story",25,"Parasite",30,"Toy Story 4",30,"Once Upon a Time in Hollywood",35,"Little Women",10,"The Irishman",20};
		

//vari//
int selection;
int isans;
int numberOfSeats;



void printWelcome(void);
void printSans(void);
void printCapacityOfSans(int isans);
void reserve(void);
void changeSans(void);
void exitt(void);




//program//
int main()
{
//	FILE *f;
//	f=fopen("salon.txt","r");
//	int i;
//	for(i=0;i<7;i++)
//	{
//		fscanf(f,"%s %d",sans[i].movie.name,&sans[i].zarfiat);
//	}	
	
	printWelcome();
	
	while(selection!=3)
	{
		switch (selection)
		{
		case 1:
			printSans();
			printCapacityOfSans(isans);
			reserve();
			
			system("pause");
            system("cls");
            printWelcome();
			break;
		case 2:
			printSans();
			changeSans();
			
			system("pause");
            system("cls");
            printWelcome();
            break;
		case 3:
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
	printf("2.Change the sans\n");
	printf("3.Exit\n");
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

void printCapacityOfSans(int isans)
{
	printf("\ncapacityof these movie is %d\n",sans[isans-1].capacity);
	printf("\nHow many seats do you want?\n");
	scanf("%d",&numberOfSeats);
}

void reserve(void)
{
	if(numberOfSeats<=sans[isans-1].capacity)
	{
		sans[isans-1].capacity=sans[isans-1].capacity-numberOfSeats;
		printf("successfully reserved.\n\n",sans[isans-1].capacity);
	}
	else
		printf("sorry, the numbers of seats are more than capacity.\n");	
}
void changeSans(void)
{
	printf("you can change \"%s\" \n",sans[isans-1].movie.name);
	printf("please Enter the name of the new movie:");
	scanf("%s",sans[isans-1].movie.name);
	printf("please Enter the new capacity:");
	scanf("%d",&sans[isans-1].capacity);
}

void exitt(void)
{
	printf("\nThank you for using this system\n");
	exit(0);
}
