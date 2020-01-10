#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Movie
{
	char name[40];		
};

struct Sans
{
	struct Movie Movie;
	int capacity;
};
	
struct Sans Sans[7];
		
//variable//
int selection;
int isans;
int numberOfSeats;

//functions//

void printWelcome(void);
void printSans(void);
void printCapacityOfSans(int isans);
void reserve(void);
void changeSans(void);
void exitt(void);




//program//
int main()
{
	int i;
	
	FILE *f;
	f=fopen("file.txt","rb+"); //file exist in the same folder with this program//
	
	for(i=0;i<7;i++)
	{
	fseek( f, i * sizeof( struct Sans ), SEEK_SET );
	fread( &Sans[i], sizeof( struct Sans ), 1, f );
	}	
	
	printWelcome();
	
	while(selection!=3)
	{
		switch (selection)
		{
		case 1: //reserve//
			printSans();
			printCapacityOfSans(isans);
			reserve();
			
			system("pause");
            system("cls");
            printWelcome();
			break;
		case 2: //change//
			printSans();
			changeSans();
			
			system("pause");
            system("cls");
            printWelcome();
            break;
		case 3: //exit//
			exitt();
			break;
		}	
	}
	
	for(i=0;i<7;i++)
	{
	fseek( f, i * sizeof( struct Sans ), SEEK_SET );
	fwrite( &Sans[i], sizeof( struct Sans), 1, f );
	}
	fclose(f);
	return 0;
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
	printf("%d.%-40s [%d:00]\n",i+1,Sans[i].Movie.name,11+2*i);
	printf("\nEnter your sans : ");
	scanf("%d",&isans);
}

void printCapacityOfSans(int isans)
{
	printf("\ncapacityof these movie is %d\n",Sans[isans-1].capacity);
	printf("\nHow many seats do you want?\n");
	scanf("%d",&numberOfSeats);
}

void reserve(void)
{
	if(numberOfSeats<=Sans[isans-1].capacity)
	{
		Sans[isans-1].capacity=Sans[isans-1].capacity-numberOfSeats;
		printf("successfully reserved.\n\n",Sans[isans-1].capacity);
	}
	else
		printf("sorry, the numbers of seats are more than capacity.\n");	
}
void changeSans(void)
{
	printf("you can change \"%s\" \n",Sans[isans-1].Movie.name);
	printf("please Enter the name of the new movie:");
	scanf("%s",Sans[isans-1].Movie.name);
	printf("please Enter the new capacity:");
	scanf("%d",&Sans[isans-1].capacity);
}

void exitt(void)
{
	printf("\nThank you for using this system\n");
	exit(0);
}
