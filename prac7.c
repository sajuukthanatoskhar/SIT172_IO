#include <stdio.h>
#include <stdlib.h>


#define a_constant 5.042F
/*
   In this example, file writing and reading will be shown.  
 */

int main()
{
	FILE *ifp,*ofp;
	int data1[10] = {50,82,40,50,60,50,30,40,50,40};
	int data2[10] = {40,52,40,50,60,50,55,95,-50,40};
	int data3[10] = {30,42,50,60,70,80,90,15,90,150};
	int dataread[10];

	int i = 0;
	char choice;

	do{
		printf("\nMenu \nWrite to file\tw\nRead from Data\tr\n >>~$ ");
		scanf("%c",&choice);
		getchar();  //this catches the inevitable enter being pressed to finish the scanf
		switch(choice)
		{
			case 'w':	
				printf("\nWriting file\a!");
				ifp = fopen("datafile","w"); //We are writing to a file called "datafile"
				for(int i=0;i<10;i++)
				{
					fprintf(ifp,"%d\t",data2[i]);
					printf("%d\t",data2[i]);
				}
				fclose(ifp);
				break;

			case 'r':	
				printf("\nReading file\a!");
				ofp = fopen("datafile","r"); //We are reading from a file called "datafile"
				if(ofp == NULL)
				{
					printf("ERROR: FILE NOT FOUND\a\a\a\a\a\a");
					fclose(ofp);
					break;
				}
				else
				{
					for(i=0;i<10;i++) //Reading an array!
					{
						fscanf(ofp,"%d\t",&dataread[i]);
					}
					printf("\n");
					for(i=0;i<10;i++)  //Printing an array!
					{
						printf("%d\t",dataread[i]);
					}
				}
				fclose(ofp);  //Always close a file.  Sure, you are only going to manage one at a time.  
				break;  
			case 'q':   printf("\nQuitting!\a"); 
				    break;
			default :	printf("\nError!  Choose w or r!!!\a");
					break;
		}
	}while(choice != 'q');

	return 0;
}
