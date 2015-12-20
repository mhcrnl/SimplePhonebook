/*
	SimplePhonebook - Simple phonebook console made with C language.

	(c) 2015 Nusantara Project.
*/

#define _CRT_SECURE_NO_WARNINGS //Error	C4996	'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char bilas; // fflush variable

/* phoneBook structure */
struct phoneBook {	
	int index;
	char name[64],
		phoneNumber[64];
};


/* Function prototyping */
int newContact(int, struct phoneBook*);
int listContact(int, struct phoneBook*);
int searchContact(int, struct phoneBook*);
int deleteContact(int, struct phoneBook*);
int sortContact(const void *, const void *);
int storeContact(int, struct phoneBook*);

int main()
{
	int menu,
		counter = 0; // contact counter
	struct phoneBook contact[200]; // The old nokia phone model. If you know what I mean. haha
	
	/* Menu selection */
	do
	{
		system("cls");
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
			newContact(counter, contact);
			counter++;
			qsort(contact, 200, sizeof(struct phoneBook), sortContact);	// Sort contact struct by name
			break;
		case 2:
			listContact(counter, contact);
			break;
		case 3:
			searchContact(counter, contact);
			break;
		case 4:
			deleteContact(counter, contact);
			qsort(contact, 200, sizeof(struct phoneBook), sortContact);	// Sort contact struct by name
			counter--;
			break;
		case 5:
			storeContact(counter, contact);
			break;
		}
	} while (menu != 5);


	return 0;
}

/* Add new contact to %Structure_Variables */
int newContact(int counter, struct phoneBook *contact)
{
	char name[64],
		phoneNumber[64];
	int i,
		validate;

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

		if ((name[0] < -1 || name[0] > 255) || isalpha(name[0]) == 0) //Debug Assertion Failed
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
			if ((name[0] < -1 || name[0] > 255) || isalpha(phoneNumber[i]) != 0) //Debug Assertion Failed
			{
				printf("\tPhone numbers should only contain digits 0-9\n");
				validate += 1;
				break;
			}
		}

	} while (validate != 0);

	strcpy(contact[counter].name, name); // save name to contact[index].name
	strcpy(contact[counter].phoneNumber, phoneNumber); // save phone number to contact[index].phoneNumber 

	puts("");
	printf("New contact successfully added!\n");

	system("pause");
	return 0;
}

/* List contact from %Structure_Variables */
int listContact(int counter, struct phoneBook* contact)
{

	int i,
		prefix = 0;
	char incasePrefix;

	system("cls");
	printf("View List Contact\n");
	puts("");

	printf("%s %3s %-30s %12s\n", "", "#", "Name", "Phone Number"); // header
	for (i = 0; i < counter; i++)
	{
		//printf("%s %3d %-30s %12s\n", "", i + 1, contact[i].name, contact[i].phoneNumber); // body
		incasePrefix = contact[i].name[0];
		incasePrefix = toupper(incasePrefix);
		if (incasePrefix == prefix)
		{
			printf("%c", 32); // body
		}
		else
		{
			prefix = incasePrefix;
			printf("%c", prefix); // body
		}
		//printf("%c", prefix ); // body
		printf(" %3d %-30s %12s\n", i + 1, contact[i].name, contact[i].phoneNumber);
	}

	puts("");
	system("pause");
	return 0;
}

/* Search contact from %Structure_Variables */
int searchContact(int, struct phoneBook*)
{
	int i,
		found = 0;

	struct phoneBook rekontruksi[200]; // recountruction

	system("cls");
	printf("Search Contact\n");
	printf("Input name [1..30 char]: ");

	printf("Total %d contact<s> found.\n", found);
	system("pause");
	return 0;
}

/* Delete contact from %Structure_Variables */
int deleteContact(int, struct phoneBook*)
{

	system("cls");
	printf("Delete Contact\n");

	printf("Success deleted one contact.\n");
	system("pause");
	return 0;
}

/* Reconstruct contact to %Structure_Variables with qsort */
int sortContact(const void *contact1, const void *contact2)
{

	struct phoneBook *ptr_contact1 = (struct phoneBook *)contact1;
	struct phoneBook *ptr_contact2 = (struct phoneBook *)contact2;
	
	return strcmp(ptr_contact1->name, ptr_contact2->name);
}

/* Store contact from %Structure_Variables into Contact.txt*/
int storeContact(int, struct phoneBook*)
{

	return 0;
}


/*

known bug:

- fflush(stdin) issue in Microsoft Visual Studio 2015 @ http://stackoverflow.com/a/33216224
- Debug Assertion Failed @ http://bit.ly/1IwaBMC
	Debug Assertion Failed!; File: minkernel\crts\ucrt\src\appcrt\convert\isctyple.cpp; Line: 36; Expression: c >= -1 && c <=255
  when blank input in 
	scanf("%[^\n]", name);
	scanf("%[^\n]", phoneNumber);

*/