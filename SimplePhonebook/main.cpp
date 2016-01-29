/*
GSLC Assigment phone book with C language.

Group:
Joshua Gugun Siagian	1901496303
Ishak Charles			1901528734
Haryadi Irawan			1901528665

repository @ https://github.com/suabahasa/SimplePhonebook
*/

#define _CRT_SECURE_NO_WARNINGS //Error	C4996	'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* phoneBook structure */
struct phoneBook {
	char name[64],
		phoneNumber[64];
};


/* Function prototyping */
int newContact(int, struct phoneBook*);
int listContact(int, struct phoneBook*);
int searchContact(int, struct phoneBook*);
int deleteContact(int, struct phoneBook*);
int sortir(int, struct phoneBook*);
int sortContact(const void *, const void *);
int storeContact(int, struct phoneBook*);
int readContact(struct phoneBook*);


int main()
{
	int menu,
		counter = 0; // contact counter
	struct phoneBook contact[200]; // My old nokia phone only can store up to 200 contact. hahaha

	counter = readContact(contact);

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
		fflush(stdin); // comment if running on machine

		switch (menu) {
		case 1:
			newContact(counter, contact);
			counter++;
			//qsort(contact, counter, sizeof(struct phoneBook), sortContact);	// Sort contact struct by name
			sortir(counter, contact);	// Sort contact struct by name
			break;
		case 2:
			listContact(counter, contact);
			break;
		case 3:
			searchContact(counter, contact);
			break;
		case 4:
			deleteContact(counter, contact);
			if (counter > 0) {
				//qsort(contact, counter, sizeof(struct phoneBook), sortContact);	// Sort contact struct by name
				sortir(counter, contact);	// Sort contact struct by name
				counter--;
			}
			break;
		case 5:
			storeContact(counter, contact);
			break;
		}
	} while (menu != 5 || menu < 1 || menu > 5);

	return 0;
}

/* Read contact from Contact.txt file */
int readContact(struct phoneBook *contact)
{
	int counter = 0;
	long size;

	FILE *fp;
	fp = fopen("Contact.txt", "r");

	if (fp != NULL)
	{
		fseek(fp, 0, SEEK_END); //Reposition stream position indicator
		size = ftell(fp); // get size of the file

		if (size == 0)
		{
			fclose(fp);
			return counter;
		}
		else
		{
			fseek(fp, 0, SEEK_SET);//Reposition stream position indicator
			while (!feof(fp))
			{
				fscanf(fp, "%[^;];%s\n", &contact[counter].name, &contact[counter].phoneNumber);
				counter++;
			}
			fclose(fp);
			return counter;
		}
	}

	return 0;
}

/* Add new contact to contact structure */
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
		fflush(stdin); // comment if running on machine

		if (strlen(name) > 30)
		{
			printf("\tLength of name should be between 1 and 30 characters\n");
			validate += 1;
		}

		if ((name[0] < -1 || name[0] > 255) || isalpha(name[0]) == 0)
		{
			printf("\tFirst letter of name should be an alphabet\n");
			validate += 1;
		}
	} while (validate != 0);

	do {
		validate = 0;
		printf("Input phone number [6..12 digits]: ");
		scanf("%[^\n]", phoneNumber);
		fflush(stdin); // comment if running on machine

		if (strlen(phoneNumber) < 6 || strlen(phoneNumber) > 12)
		{
			printf("\tLength of phone numbers should be between 6 and 12 digits\n");
			validate += 1;
		}

		for (i = 0; i < strlen(phoneNumber); i++)
		{
			if ((phoneNumber[0] < -1 || phoneNumber[0] > 255) || isalpha(phoneNumber[i]) != 0)
			{
				printf("\tPhone numbers should only contain digits 0-9\n");
				validate += 1;
				break;
			}
		}
	} while (validate != 0);

	strcpy(contact[counter].name, name);
	strcpy(contact[counter].phoneNumber, phoneNumber);

	puts("");
	printf("New contact successfully added!\n");

	system("pause");
	return 0;
}

/* List contact from contact structure */
int listContact(int counter, struct phoneBook* contact)
{
	int i,
		prefix = 0;
	char incasePrefix;

	system("cls");
	printf("View List Contact\n");
	puts("");

	printf("%c %3s %-30s %12s\n", 32, "#", "Name", "Phone Number"); // table header
	for (i = 0; i < counter; i++)
	{
		incasePrefix = contact[i].name[0];
		incasePrefix = toupper(incasePrefix);

		if (incasePrefix == prefix) // table body
		{
			printf("%c", 32);
		}
		else
		{
			prefix = incasePrefix;
			printf("%c", prefix);
		}

		printf(" %3d %-30s %12s\n", i + 1, contact[i].name, contact[i].phoneNumber); // table body
	}

	puts("");
	system("pause");
	return 0;
}

/* Search contact from contact structure */
int searchContact(int counter, struct phoneBook* contact)
{
	int i,
		j,
		found = 0;
	char iName[64],
		iContact[64];
	char *strExist;

	system("cls");
	printf("Search Contact\n");
	printf("Input name [1..30 char]: ");
	scanf("%[^\n]", iName);
	fflush(stdin); // comment if running on machine
	puts("");

	for (j = 0; j < strlen(iName); j++)
	{
		iName[j] = tolower(iName[j]);
	}

	for (i = 0; i < counter; i++)
	{

		for (j = 0; j < strlen(contact[i].name); j++)
		{
			iContact[j] = tolower(contact[i].name[j]);
		}

		strExist = strstr(iContact, iName);

		if (strExist && strExist != iName)
		{
			printf("  %-30s %12s\n", contact[i].name, contact[i].phoneNumber); // table body
			found++;
		}

		memset(iContact, 0, sizeof(iContact)); // clear the string
	}

	puts("");
	printf("Total %d contact<s> found.\n", found);
	system("pause");
	return 0;
}

/* Delete contact from contact structure */
int deleteContact(int counter, struct phoneBook* contact)
{
	int i,
		selected,
		prefix = 0,
		validate;
	char incasePrefix;

	system("cls");
	printf("Delete Contact\n");
	puts("");

	printf("%c %3s %-30s %12s\n", 32, "#", "Name", "Phone Number"); // table header
	for (i = 0; i < counter; i++)
	{
		incasePrefix = contact[i].name[0];
		incasePrefix = toupper(incasePrefix);

		if (incasePrefix == prefix) // table body
		{
			printf("%c", 32);
		}
		else
		{
			prefix = incasePrefix;
			printf("%c", prefix);
		}

		printf(" %3d %-30s %12s\n", i + 1, contact[i].name, contact[i].phoneNumber); // table body
	}

	puts("");
	if (counter > 0) {
		do {
			validate = 0;
			printf("Input #number of contact that you want to delete[1..%d]: ", counter);
			scanf("%d", &selected);
			fflush(stdin); // comment if running on machine

			if (selected > counter || selected < 1)
			{
				printf("\t#number of contact should only between 1-%d\n", counter);
				validate += 1;
			}

		} while (validate != 0);

		memset(&contact[selected - 1], sizeof(contact[selected - 1]), sizeof(contact[selected - 1]));
		printf("Success deleted one contact.\n");
	}
	else
	{
		printf("There is no data to be deleted.\n");
	}

	system("pause");
	return 0;
}


int sortir(int count, struct phoneBook* contact)
{
	int i,
		j;
	for (i = 0; i < count; i++)
	{
		for (j = count - 1; j> i; j--)
		{
			if (strcmpi(contact[j].name, contact[j - 1].name) < 0)
			{
				struct phoneBook temp; // My old nokia phone only can store up to 200 contact. hahaha
				temp = contact[j];
				contact[j] = contact[j - 1];
				contact[j - 1] = temp;
			}
		}
	}
	return 0;
}

/* Reconstruct contact structure with Quicksort */
int sortContact(const void *contact1, const void *contact2)
{
	struct phoneBook *ptr_contact1 = (struct phoneBook *)contact1;
	struct phoneBook *ptr_contact2 = (struct phoneBook *)contact2;

	// sort struct by name
	return _strcmpi(ptr_contact1->name, ptr_contact2->name); // case insensitive
}

/* Store contact from contact structure into Contact.txt */
int storeContact(int counter, struct phoneBook* contact)
{
	int i;
	FILE *fp;
	fp = fopen("Contact.txt", "w");

	for (i = 0; i < counter; i++)
	{
		fprintf(fp, "%s;%s\n", contact[i].name, contact[i].phoneNumber);
	}

	fclose(fp);

	return 0;
}


/*

note:

- fflush(stdin) issue in Microsoft Visual Studio 2015 @ http://stackoverflow.com/a/33216224
- Debug Assertion Failed @ http://bit.ly/1IwaBMC
Debug Assertion Failed!; File: minkernel\crts\ucrt\src\appcrt\convert\isctyple.cpp; Line: 36; Expression: c >= -1 && c <=255
- when blank input in scanf
- strcmpi(); C4996 @ https://msdn.microsoft.com/query/dev14.query?appId=Dev14IDEF1&l=EN-US&k=k%28C4996%29&rd=true

*/