/*
SimplePhonebook - SimplePhonebook made with C language.

Copyright (c) Nusantara Project. All rights reserved.
*/

#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


int newContact();
int listContact();
int searchContact();
int deleteContact();

char bilas;

int main()
{
	int menu;

	printf("Phone Book\n");
	printf("==========\n");
	printf("1. Add New Contact\n");
	printf("2. View List Contact\n");
	printf("3. Search Contact\n");
	printf("4. Delete Contact\n");
	printf("5. Exit\n");
	printf("Choose menu: ");
	scanf("%d", &menu);
	scanf("%c", &bilas); //fflush(stdin);

	switch (menu) {
	case 1:
		newContact();
		break;
	case 2:
		listContact();
		break;
	case 3:
		searchContact();
		break;
	case 4:
		deleteContact();
		break;
	case 5:
		//return 0;
		break;
	}


	puts("");
	system("pause");
	return 0;
}



int newContact()
{
	char name[64],
		phoneNumber[64];
	int i,
		validate = 0;

	system("cls");
	printf("Add New Contact\n");

	do {
		validate = 0;
		printf("Input name [1..30 char]: ");
		scanf("%[^\n]", name);
		scanf("%c", &bilas); //fflush(stdin);

		if (strlen(name) > 30)
		{
			printf("\tLength of name should be between 1 and 30 characters\n");
			validate += 1;
		}

		if (isalpha(name[0]) == 0)
		{
			printf("\tFirst letter of name should be an alphabet\n");
			validate += 1;
		}

	} while (validate != 0);

	do {
		validate = 0;
		printf("Input phone number [6..12 digits]: ");
		scanf("%[^\n]", phoneNumber);
		scanf("%c", &bilas); //fflush(stdin);

		if (strlen(phoneNumber) < 6 || strlen(phoneNumber) > 12)
		{
			printf("\tLength of phone numbers should be between 6 and 12 digits\n");
			validate += 1;
		}

		for (i = 0; i < strlen(phoneNumber); i++)
		{
			if (isalpha(phoneNumber[i]) != 0)
			{
				printf("\tPhone numbers should only contain digits 0-9\n");
				validate += 1;
				break;
			}
		}

	} while (validate != 0);

	puts("");
	printf("New contact successfully added!\n");

	system("pause");
	return 0;
}

int listContact()
{

	return 0;
}

int searchContact()
{

	return 0;
}

int deleteContact()
{

	return 0;
}


/*
reference:

1. fflush(stdin) issue @ http://stackoverflow.com/a/33216224

*/