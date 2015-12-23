/*
	SimplePhonebook - Simple phonebook console made with C language.
	(c) 2015 Nusantara Project.

	repository @ https://github.com/suabahasa/SimplePhonebook
*/

#define _CRT_SECURE_NO_WARNINGS //Error	C4996	'scanf': This function or variable may be unsafe.Consider using scanf_s instead.To disable deprecation, use _CRT_SECURE_NO_WARNINGS.See online help for details.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

char bilas; // fflush variable

/* phoneBook structure */
struct phoneBook {	
	int id;
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
	struct phoneBook contact[200]; // As my old nokia phone model. If you know what I mean. haha

	/* Dummy data */
	int aiueo;	counter = 100; // dummy
	char dummyName[100][64] = { "Brazil", "British Indian Ocean Territory", "Brunei Darussalam", "Bulgaria", "Burkina Faso", "Burundi", "Cambodia", "Cameroon", "Canada", "Cape Verde", "Cayman Islands", "Central African Republic", "Chad", "Chile", "China", "Christmas Island", "Cocos Islands", "Colombia", "Comoros", "Congo", "Congo", "Cook Islands", "Costa Rica", "Cote d'Ivoire", "Croatia", "Cuba", "Cyprus", "Czech Republic", "Denmark", "Djibouti", "Dominica", "Dominican Republic", "East Timor", "Ecuador", "Egypt", "El Salvador", "Equatorial Guinea", "Eritrea", "Estonia", "Ethiopia", "Falkland Islands", "Faroe Islands", "Fiji", "Finland", "France", "France Metropolitan", "French Guiana", "French Polynesia", "French Southern Territories", "Gabon", "Gambia", "Georgia", "Germany", "Ghana", "Gibraltar", "Greece", "Greenland", "Grenada", "Guadeloupe", "Guam", "Guatemala", "Guinea", "Guinea-Bissau", "Guyana", "Haiti", "Heard and Mc Donald Islands", "Vatican City State", "Honduras", "Hong Kong", "Hungary", "Iceland", "Afghanistan", "Albania", "Algeria", "American Samoa", "Andorra", "Angola", "Anguilla", "Antarctica", "Antigua and Barbuda", "Argentina", "Armenia", "Aruba", "Australia", "Austria", "Azerbaijan", "Bahamas", "Bahrain", "Bangladesh", "Barbados", "Belarus", "Belgium", "Belize", "Benin", "Bermuda", "Bhutan", "Bolivia", "Bosnia and Herzegowina", "Botswana", "Bouvet Island"};
	char dummyPhone[100][64] = {"7520194502", "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192", "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" , "9730185562", "3692011098", "0194321010", "8504397647", "1024419745", "7823212192", "2073718872", "9082108458", "2494921192" };
	for (aiueo = 0; aiueo < 100; aiueo++)
	{
		strcpy(contact[aiueo].name, dummyName[aiueo]);		strcpy(contact[aiueo].phoneNumber, dummyPhone[aiueo]);
	}
	qsort(contact, counter, sizeof(struct phoneBook), sortContact);	// Sort contact struct by name
	//printf("%d \t%s \t%s\n", 111, contact[110].name, contact[110].phoneNumber);
	/* end of Dummy data */

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
			qsort(contact, counter, sizeof(struct phoneBook), sortContact);	// Sort contact struct by name
			break;
		case 2:
			listContact(counter, contact);
			break;
		case 3:
			searchContact(counter, contact);
			break;
		case 4:
			deleteContact(counter, contact);
			qsort(contact, counter, sizeof(struct phoneBook), sortContact);	// Sort contact struct by name
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

	printf("%c %3s %-30s %12s\n", 32, "#", "Name", "Phone Number"); // header
	for (i = 0; i < counter; i++)
	{
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

		printf(" %3d %-30s %12s\n", i + 1, contact[i].name, contact[i].phoneNumber);
	}

	puts("");
	system("pause");
	return 0;
}

/* Search contact from %Structure_Variables */
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
	scanf("%c", &bilas); //fflush(stdin);
	puts("");

	for (j = 0; j < strlen(iName); j++)
	{
		iName[j] = tolower(iName[j]); // case insensitive
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
			printf("  %-30s %12s\n", contact[i].name, contact[i].phoneNumber); // body
			found++;
		}

		memset(iContact, 0, sizeof(iContact)); // clear the string
	}

	puts("");
	printf("Total %d contact<s> found.\n", found);
	system("pause");
	return 0;
}

/* Delete contact from %Structure_Variables */
int deleteContact(int counter, struct phoneBook* contact)
{

	int i,
		selected,
		prefix = 0,
		validate;
	char incasePrefix;

	system("cls");
	printf("View List Contact\n");
	puts("");

	printf("%c %3s %-30s %12s\n", 32, "#", "Name", "Phone Number"); // header
	for (i = 0; i < counter; i++)
	{
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

		printf(" %3d %-30s %12s\n", i + 1, contact[i].name, contact[i].phoneNumber);
	}

	puts("");
	do {
		validate = 0;
		printf("Input #number of contact that you want to delete[1..%d]: ", counter);
		scanf("%d", &selected);
		scanf("%c", &bilas);
		if (selected > counter || selected < 1)
		{
			printf("\t#number of contact should only between 1-%d\n", counter);
		}
	} while (selected > counter || selected < 1);
	
	//struct phoneBook dummy[1];
	//contact[selected - 1] = dummy[1];
	memset(&contact[selected - 1], sizeof(contact[selected - 1]), sizeof(contact[selected - 1]));

	printf("Success deleted one contact.\n");
	system("pause");
	return 0;
}

/* Reconstruct contact to %Structure_Variables with qsort */
int sortContact(const void *contact1, const void *contact2)
{

	struct phoneBook *ptr_contact1 = (struct phoneBook *)contact1;
	struct phoneBook *ptr_contact2 = (struct phoneBook *)contact2;

	// sort struct by name
	//return strcmp(ptr_contact1->name, ptr_contact2->name);
	return _strcmpi(ptr_contact1->name, ptr_contact2->name); // case insensitive
}

/* Store contact from %Structure_Variables into Contact.txt*/
int storeContact(int, struct phoneBook*)
{







	return 0;
}


/*

known problem and unresolve:

- fflush(stdin) issue in Microsoft Visual Studio 2015 @ http://stackoverflow.com/a/33216224
- Debug Assertion Failed @ http://bit.ly/1IwaBMC
	Debug Assertion Failed!; File: minkernel\crts\ucrt\src\appcrt\convert\isctyple.cpp; Line: 36; Expression: c >= -1 && c <=255
  when blank input in 
	scanf("%[^\n]", name);
	scanf("%[^\n]", phoneNumber);
- strcmpi(); C4996 @ https://msdn.microsoft.com/query/dev14.query?appId=Dev14IDEF1&l=EN-US&k=k%28C4996%29&rd=true
*/