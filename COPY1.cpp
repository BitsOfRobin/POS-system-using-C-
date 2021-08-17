#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#pragma warning (disable:4996)

struct employed
{
	int day, month, year;
};
struct acedemy
{
	char degree[30], country[30];
};
struct info
{
	char id[10], designat[30], name[30];
	struct employed date;
	struct acedemy qualification;
};



void addstaff();
void locatingstaff(int*feedback,int*stop,int*totalcount);
void modifystaff(int feedback, int stop, int totalcount);
void displaystaff();
void resignstaff(int*feedback, int*stop, int*totalcount);

void main()
{
	int feedback;
	
	int num,stop,totalcount;
	printf("\t\tplease enter the number to choose the option \n \t\t1. to add the record \n\n \t\t2. to search the record\n\n\n \t\t3. to modify the record\n\n\t\t 4. to display the records\n\n\t\t 5. to delete the record\n\n\t\t  -1 to exit \n\n");
	
	scanf("%d", &num);;
	while (num != -1)
	{
		if (num == 1)
		{
			addstaff();
		}

		else if (num == 2)
		{
			
			
			locatingstaff(&feedback, &stop , &totalcount);

		}

		else if (num == 3)
		{

			
		 locatingstaff( &feedback,&stop ,  &totalcount);
			
			modifystaff(feedback,stop,totalcount);


		}

		else if (num == 4)
		{
			displaystaff();
		}


		else if (num == 5)
		{
			displaystaff();
			
			resignstaff(&feedback,  &stop,  &totalcount);
		}

		else
		{
			printf("Error!\n");
		}
		printf("\t\tplease enter the number to choose the option \n \t\t1. to add the record \n\n \t\t2. to search the record\n\n\n \t\t3. to modify the record\n\n\t\t 4. to display the records\n\n\t\t 5. to delete the record\n\n\t\t  -1 to exit \n\n");
		rewind(stdin);
		scanf("%d", &num);
	}


	system("pause");
}
void addstaff()
{
	char sure[8];
	int invalid = 0,count=0,count2=0,count3=0,valid=0,valid2=0;
	struct info staff[99],employee[99];
	FILE*file; 
	FILE*file2= fopen("staffinfo.txt", "r");
	rewind(stdin);
	printf("Are you sure to add the record <Type \"sure\" to enter records >>?\n\n");
	scanf("%[^\n]", &sure);
	if (strcmp(strlwr(sure), "sure") == 0)
	{


		while (!feof(file2))
		{

			fscanf(file2, "%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^|]|%[^\n]\n", &employee[count3].id, &employee[count3].qualification.country, &employee[count3].name, &employee[count3].date.day, &employee[count3].date.month, &employee[count3].date.year, &employee[count3].qualification.degree, &employee[count3].designat);
			count3++;
		}
		fclose(file2);
		rewind(stdin);
		printf("ID:  @@@ to exit \n\n");
		scanf("%[^\n]", &staff[count].id);
		
		if (strcmp(staff[count].id, "@@@") != 0)
		{
			for (count2 = 0; count2 < count3; count2++)
			{
				if (strcmp(strupr(staff[count].id), strupr(employee[count2].id)) == 0)
				{


					printf("The ID is present in the records!!! Invalid ID\n\n");

					valid++;

					break;

				}
				

			}



			if (valid > 0)
			{
				rewind(stdin);
				printf("ID:    @@@ to exit \n\n");
				scanf("%[^\n]", &staff[count].id);
				strupr(staff[count].id);
				for (count2 = 0; count2 < count3; count2++)
				{
					while (strcmp(strupr(staff[count].id), strupr(employee[count2].id)) == 0)
					{

						rewind(stdin);
						printf("ID:    @@@ to exit \n\n");
						scanf("%[^\n]", &staff[count].id);
						strupr(staff[count].id);
						count2 = 0;
					}
					
				}

				
			}
			
				
				while (strcmp(strupr(staff[count].id), "@@@") != 0)
				{
					rewind(stdin);
					printf("DESIGNATION:\n\n");
					scanf("%[^\n]", &staff[count].designat);
					rewind(stdin);
					printf("NAME:\n\n");
					scanf("%[^\n]", &staff[count].name);
					do
					{
						invalid = 0;

						printf("Days of employed:\n\nMonths of employed:\n\nyears of employed:\n\n");
						scanf("%d %d %d", &staff[count].date.day, &staff[count].date.month, &staff[count].date.year);
						if (staff[count].date.day > 31 || staff[count].date.day < 1)
						{
							printf("Invalid date\n\n");
							invalid++;
						}
						else if (staff[count].date.day > 28 && staff[count].date.month == 2)
						{
							printf("Invalid date\n\n");
							invalid++;
						}
						else if (staff[count].date.month > 12)
						{
							printf("Invalid date\n\n");
							invalid++;
						}
						else if (staff[count].date.year > 2020 || staff[count].date.year < 1900)
						{
							printf("Invalid date\n\n");
							invalid++;
						}

					} while (invalid != 0);

					rewind(stdin);
					printf("qualification:\n\n");
					scanf("%[^\n]", &staff[count].qualification.degree);
					rewind(stdin);
					printf("country of qualification:\n\n");
					scanf("%[^\n]", &staff[count].qualification.country);
					file = fopen("staffinfo.txt", "a");
					fprintf(file, "%s|%s|%s|%d-%d-%d|%s|%s\n", staff[count].id, staff[count].qualification.country, staff[count].name
						, staff[count].date.day,
						staff[count].date.month, staff[count].date.year,
						staff[count].qualification.degree, staff[count].designat);
					fclose(file);
					file = fopen("staffinfo.txt", "r");
					count3 = 0;
					while (!feof(file))
					{
						

						fscanf(file, "%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^|]|%[^\n]\n", &employee[count3].id, &employee[count3].qualification.country, &employee[count3].name, &employee[count3].date.day, &employee[count3].date.month, &employee[count3].date.year, &employee[count3].qualification.degree, &employee[count3].designat);
						count3++;
					}
					fclose(file);
					count++;
					rewind(stdin);
					printf("ID:    @@@ to exit \n\n");
					scanf("%[^\n]", &staff[count].id);
					strupr(staff[count].id);
					if (strcmp(staff[count].id, "@@@") != 0)
					{
						for (count2 = 0; count2 < count3; count2++)
						{
							if (strcmp(strupr(staff[count].id), strupr(employee[count2].id)) == 0)
							{


								printf("The ID is present in the records!!! Invalid ID\n\n");

								valid2++;

								break;

							}
						}

						if (valid2 > 0)
						{
							rewind(stdin);
							printf("ID:    @@@ to exit \n\n");
							scanf("%[^\n]", &staff[count].id);
							strupr(staff[count].id);
							for (count2 = 0; count2 < count3; count2++)
							{
								while (strcmp(strupr(staff[count].id), strupr(employee[count2].id)) == 0)
								{
									rewind(stdin);
									printf("ID:    @@@ to exit \n\n");
									scanf("%[^\n]", &staff[count].id);
									strupr(staff[count].id);
									count2 = 0;

								}


							}


						}
						
					}
				}

			

		}
	}
	
}

void locatingstaff(int*feedback, int*stop, int*totalcount)

{
	struct info employee[99];
	int count = 0, count2 = 0;
	FILE*file2 = fopen("staffinfo.txt", "r");
	if (file2 == NULL)
	{
		printf("Error No contents!!!\n");
		


	}
	char search[30];
	rewind(stdin);
	printf("Please search the ID   @@@ to exit \n\n\n");
	scanf("%[^\n]", &search);

	

	
	
		
		
		while (!feof(file2))
		{

			fscanf(file2, "%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^|]|%[^\n]\n", &employee[count].id, &employee[count].qualification.country, &employee[count].name, &employee[count].date.day,&employee[count].date.month, &employee[count].date.year,&employee[count].qualification.degree,&employee[count].designat);
			count++;
		}
		printf("%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t\n\n\n", "ID", "COUNTRY", "DESIGNATION", "NAME", "DATE OF EMPLOYED", "QUALIFICATION");

		

		

		if (strcmp(strupr(search), "@@@") != 0)
		{
			for (count2 = 0; count2 < count; count2++)
			{
				if (strcmp(strupr(search), strupr(employee[count2].id)) == 0)
				{



					printf("%-10s\t", employee[count2].id);
					printf("%-10s\t", employee[count2].qualification.country);
					printf("%-10s\t\t", employee[count2].designat);
					printf("%-10s\t", employee[count2].name);

					printf("%-02d-%-02d-%-02d\t\t", employee[count2].date.day, employee[count2].date.month, employee[count2].date.year);
					printf("%-10s ", employee[count2].qualification.degree);
					
					printf("\n\n");
					*feedback = 1;
					break;





				}

			

				else 
				{
					
					*feedback = 0;



				}




			}

			

		}


		if (*feedback == 0)
		{
			printf("Record not found!!!\n\n");
		}



		else if (strcmp(strupr(search), "@@@") == 0)
		{
			*feedback = 2;


		}

		
		  

			*stop =count2;
			*totalcount = count;
	fclose(file2);

}

void modifystaff(int feedback,int stop,int totalcount)
{
	
	char sure[10];
	
	struct info staff[99],employee[99];
	int count = 0,count2=0, count3 = 0, invalid;
	


	FILE*file3 = fopen("staffinfo.txt", "r");
	if (file3 == NULL)
	{
		printf("Error No contents!!!\n");
		


	}
	

		while (!feof(file3))
		{

			fscanf(file3, "%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^|]|%[^\n]\n", &employee[count2].id, &employee[count2].qualification.country,
				&employee[count2].name, &employee[count2].date.day, &employee[count2].date.month, &employee[count2].date.year,
				&employee[count2].qualification.degree, &employee[count2].designat);
			count2++;
		}
	

	fclose(file3);
	if (feedback == 1)
	{

		do
		{
			rewind(stdin);
			printf("sure to be modified yes to enter @@@ to exit :\n\n");
			scanf("%[^\n]", &sure);

			strlwr(sure);

			if (strcmp(strlwr(sure), "yes") == 0)
			{

				locatingstaff(&feedback, &stop, &totalcount);
				
				rewind(stdin);
				printf("DESIGNATION:\n\n");
				scanf("%[^\n]", &staff[count].designat);
				rewind(stdin);
				printf("NAME:\n\n");
				scanf("%[^\n]", &staff[count].name);
				do
				{

					invalid = 0;
					printf("Days of employed:\n\nMonths of employed:\n\nyears of employed:\n\n");
					scanf("%d %d %d", &staff[count].date.day, &staff[count].date.month, &staff[count].date.year);
					if (staff[count].date.day > 31|| staff[count].date.day<1)
					{
						printf("Invalid date\n\n");
						invalid++;
					}
					else if (staff[count].date.day > 28 && staff[count].date.month == 2)
					{
						printf("Invalid date\n\n");
						invalid++;
					}
					else if (staff[count].date.month > 12)
					{
						printf("Invalid date\n\n");
						invalid++;
					}
					else if (staff[count].date.year > 2020|| staff[count].date.year < 1900)
					{
						printf("Invalid date\n\n");
						invalid++;
					}

				} while (invalid != 0);


				rewind(stdin);
				printf("qualification:\n\n");
				scanf("%[^\n]", &staff[count].qualification.degree);
				rewind(stdin);
				printf("country of qualification:\n\n");
				scanf("%[^\n]", &staff[count].qualification.country);



				strcpy(employee[stop].designat, staff[count].designat);
				strcpy(employee[stop].name, staff[count].name);
				employee[stop].date.day = staff[count].date.day;
				employee[stop].date.month = staff[count].date.month;
				employee[stop].date.year = staff[count].date.year;

				strcpy(employee[stop].qualification.degree, staff[count].qualification.degree);
				strcpy(employee[stop].qualification.country, staff[count].qualification.country);
				

				printf("%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t\n\n\n", "ID", "COUNTRY", "DESIGNATION", "NAME", "DATE OF EMPLOYED", "QUALIFICATION");
				for (count3 = 0; count3 < totalcount; count3++)
				{

					printf("%-10s\t", employee[count3].id);
					printf("%-10s\t\t", employee[count3].qualification.country);
					printf("%-10s\t\t", employee[count3].designat);
					printf("%-10s\t\t", employee[count3].name);

					printf("%-02d-%-02d-%-02d\t\t", employee[count3].date.day, employee[count3].date.month, employee[count3].date.year);
					printf("%-10s\t\t ", employee[count3].qualification.degree);
					
					printf("\n\n");
				}
			}
			file3 = fopen("staffinfo.txt", "w");
		

		
			for (count3 = 0; count3 < totalcount; count3++)
			{
				fprintf(file3, "%s|%s|%s|%d-%d-%d|%s|%s\n", employee[count3].id, employee[count3].qualification.country, employee[count3].name,
					employee[count3].date.day, employee[count3].date.month, employee[count3].date.year, employee[count3].qualification.degree,
					 employee[count3].designat);


			}

			fclose(file3);

			



		} while (strcmp(sure, "@@@") != 0);

	
	}
	else  if (feedback==0)
	{
		printf("invalid searching \n\n");
		
		locatingstaff( &feedback,&stop, &totalcount);
		 modifystaff( feedback,  stop,  totalcount);
		
	}
	
	


	
}


void displaystaff()
{
	struct info employee;
	int count = 0,count2=0,count3=0;
	
	FILE*file4 = fopen("staffinfo.txt", "r");



	if (file4==NULL)
	{
		printf("Error No contents!!!\n");
		
		
	}
	printf("%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t\n\n\n", "ID", "COUNTRY", "NAME", "DATE OF EMPLOYED", "QUALIFICATION", "DESIGNATION");
	while (!feof(file4))
	{
		if (fscanf(file4, "%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^|]|%[^\n]\n", &employee.id, &employee.qualification.country,
			&employee.name, &employee.date.day, &employee.date.month,
			&employee.date.year, &employee.qualification.degree, &employee.designat) == -1)
		{

			printf("empty  contents!!!\n");

		}
		else
		{
		


				printf("%-10s\t", employee.id);
				printf("%-10s\t", employee.qualification.country);
				printf("%-10s\t", employee.name);



				printf("%-02d-%-02d-%-02d\t\t", employee.date.day, employee.date.month, employee.date.year);
				printf("%-10s\t\t ", employee.qualification.degree);
				printf("%-10s\t\t", employee.designat);
				printf("\n\n");


			
		}
	}
	fclose(file4);


}

void resignstaff(int*feedback, int*stop, int*totalcount)
{
	struct info employee[99];

	
	int count, position, count2 = 0,count3,option,count4=0,count5;
	FILE*file2 = fopen("staffinfo.txt", "r");

	if (file2 == NULL)
	{
		printf("Error No contents!!!\n");
		


	}


	
	while (!feof(file2))
	{

		fscanf(file2, "%[^|]|%[^|]|%[^|]|%d-%d-%d|%[^|]|%[^\n]\n", &employee[count2].id, &employee[count2].qualification.country,
			&employee[count2].name, &employee[count2].date.day, &employee[count2].date.month, &employee[count2].date.year,
			&employee[count2].qualification.degree ,&employee[count2].designat);
		count2++;
	}

	fclose(file2);

	printf("method to delete,1 for delete via number,2 for delete with ID  other to exit \n\n");
	scanf("%d", &option);
	if (option == 1)
	{
		printf("Enter the location where you wish to delete element  -1 to exit\n\n");
		rewind(stdin);
		scanf("%d", &position);
		rewind(stdin);
		if(position != -1)
		{

			if (position >= *totalcount + 1)
			{

				printf("Deletion not possible.\n\n");

			}
			else
			{

				for (count = position - 1; count < *totalcount - 1; count++)
				{

					strcpy(employee[count].id, employee[count + 1].id);
					strcpy(employee[count].designat, employee[count + 1].designat);
					strcpy(employee[count].name, employee[count + 1].name);
					employee[count].date.day = employee[count + 1].date.day;
					employee[count].date.month = employee[count + 1].date.month;
					employee[count].date.year = employee[count + 1].date.year;

					strcpy(employee[count].qualification.degree, employee[count + 1].qualification.degree);
					strcpy(employee[count].qualification.country, employee[count + 1].qualification.country);

				}
				file2 = fopen("staffinfo.txt", "w");
				printf("%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t\n\n\n", "ID", "COUNTRY", "DESIGNATION", "NAME", "DATE OF EMPLOYED", "QUALIFICATION");
				for (count = 0; count < *totalcount - 1; count++)
				{

					printf("%-10s\t", employee[count].id);
					printf("%-10s\t\t", employee[count].qualification.country);
					printf("%-10s\t\t", employee[count].designat);
					printf("%-10s\t\t", employee[count].name);

					printf("%-02d-%-02d-%-02d\t\t", employee[count].date.day, employee[count].date.month, employee[count].date.year);
					printf("%-10s\t\t ", employee[count].qualification.degree);

					printf("\n\n");

				}
				
				for (count3 = 0; count3 < *totalcount - 1; count3++)
				{

					fprintf(file2, "%s|%s|%s|%d-%d-%d|%s|%s\n", employee[count3].id, employee[count3].qualification.country, employee[count3].name,
						employee[count3].date.day, employee[count3].date.month, employee[count3].date.year, employee[count3].qualification.degree, employee[count3].designat);
				}




				fclose(file2);
			}

			

		}
	

	}
	else if (option == 2)
	{
		locatingstaff(feedback, stop, totalcount);
		printf("%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t%-5s\t\t\n\n\n", "ID", "COUNTRY", "DESIGNATION", "NAME", "DATE OF EMPLOYED", "QUALIFICATION");
		file2 = fopen("staffinfo.txt", "w");
		for (count4 = 0; count4 < *totalcount; count4++)
		{
			if (strcmp(strupr(employee[count4].id), strupr(employee[*stop].id)) != 0)
			{


					printf("%-10s\t", employee[count4].id);
					printf("%-10s\t\t", employee[count4].qualification.country);
					printf("%-10s\t\t", employee[count4].designat);
					printf("%-10s\t\t", employee[count4].name);

					printf("%-02d-%-02d-%-02d\t\t", employee[count4].date.day, employee[count4].date.month, employee[count4].date.year);
					printf("%-10s\t\t ", employee[count4].qualification.degree);

					printf("\n\n");

				
				



			}
		
		}
		for (count5 = 0; count5 < *totalcount; count5++)
		{
			if (strcmp(strupr(employee[count5].id), strupr(employee[*stop].id)) != 0)
			{
				fprintf(file2, "%s|%s|%s|%d-%d-%d|%s|%s\n", employee[count5].id, employee[count5].qualification.country, employee[count5].name,
					employee[count5].date.day, employee[count5].date.month, employee[count5].date.year, employee[count5].qualification.degree, employee[count5].designat);
			}
		}

		fclose(file2);
	}

	else
	{

	printf("Invalid input!!!\n\n");
    }
	
}