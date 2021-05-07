//==============================================
// Name:           Shuqi Yang
// Student Number: 132162207
// Email:          syang136@myseneca.ca
// Section:        NUU
// Date:           
//==============================================
// Assignment:     2
// Milestone:      4
//==============================================


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "contactHelpers.h"
#include "contacts.h"
#define MAXCONTACTS 5

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+

void clearKeyboard(void)
{
    while (getchar() != '\n') {
        // empty execution code block on purpose 
    }
}

// pause
void pause(void)
{
    printf("(Press Enter to Continue)");
    clearKeyboard();
}

// getInt
int getInt(void)
{
    int Value;
    char NL;
    do {
        scanf("%d%c", &Value, &NL);
        if (NL != '\n') {
            clearKeyboard();
            printf("*** INVALID INTEGER *** <Please enter an integer>: ");
        }
    } while (NL != '\n');
    return Value;
}

// getIntInRange
int getIntInRange(int min, int max)
{
    int intInput;
    int outOfRange;
    do {
        intInput = getInt();
        if (intInput < min || intInput > max) {
            printf("*** OUT OF RANGE *** <Enter a number between %d and %d>: ",
                min, max);
            outOfRange = 1;
        }
        else {
            outOfRange = 0;
        }
    } while (outOfRange == 1);
    return intInput;
}

// yes
int yes(void)
{
    char Value;
    char NL;
    int vldEntry = 1;
    do {
        scanf("%c%c", &Value, &NL);
        if (NL != '\n') {
            clearKeyboard();
            printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
            vldEntry = 0;
        }
        else {
            if ((Value == 'y') | (Value == 'Y')) {
                return 1;
            }
            else if ((Value == 'n') | (Value == 'N')) {
                return 0;
            }
            else {
                printf("*** INVALID ENTRY *** <Only (Y)es or (N)o are acceptable>: ");
                vldEntry = 0;
            }
        }
    } while (vldEntry == 0);
    return 0;
}

// menu
int menu(void)
{
    int optValue;
    printf("Contact Management System\n");
    printf("-------------------------\n");
    printf("1. Display contacts\n");
    printf("2. Add a contact\n");
    printf("3. Update a contact\n");
    printf("4. Delete a contact\n");
    printf("5. Search contacts by cell phone number\n");
    printf("6. Sort contacts by cell phone number\n");
    printf("0. Exit\n\n");
    printf("Select an option:> ");
    optValue = getIntInRange(0, 6);
    return optValue;
}

// contactManagerSystem
void contactManagerSystem(void)
{
    struct Contact sampleConts[MAXCONTACTS] = { {{ "Rick", {'\0'}, "Grimes" },
                                                { 11, "Trailer Park", 0, "A7A 2J2", "King City" },
                                                { "4161112222", "4162223333", "4163334444" }},
                                               {
                                                  { "Maggie", "R.", "Greene" },
                                                  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
                                                  { "9051112222", "9052223333", "9053334444" }},
                                               {
                                                  { "Morgan", "A.", "Jones" },
                                                  { 77, "Cottage Lane", 0, "C7C 9Q9", "Peterborough" },
                                                  { "7051112222", "7052223333", "7053334444" }},
                                               {
                                                  { "Sasha", {'\0'}, "Williams" },
                                                  { 55, "Hightop House", 0, "A9A 3K3", "Bolton" },
                                                  { "9052223333", "9052223333", "9054445555" } },
                                              };
    int sysOn = 1;
    do {
        int input = menu();
        switch (input) {
        case 1:
            printf("\n");
            displayContacts(sampleConts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 2:
            printf("\n");
            addContact(sampleConts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 3:
            printf("\n");
            updateContact(sampleConts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 4:
            printf("\n");
            deleteContact(sampleConts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 5:
            printf("\n");
            searchContacts(sampleConts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 6:
            printf("\n");
            sortContacts(sampleConts, MAXCONTACTS);
            pause();
            printf("\n");
            break;

        case 0:
            printf("\nExit the program? (Y)es/(N)o: ");
            int yesOrNo = yes();
            if (yesOrNo == 1) {
                printf("\nContact Management System: terminated\n");
                sysOn = 0;
            }
            else {
                printf("\n");
            }
        }
    } while (sysOn == 1);
}







// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | Put empty function definitions below...         |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (ensures 10-digit chars entered)
// ---------------------------------------------------------------------------------
// NOTE: Modify this function to validate only numeric character digits are entered
// ---------------------------------------------------------------------------------
void getTenDigitPhone(char phoneNum[])
{
    int needInput = 1;

    while (needInput == 1)
    {
        scanf("%[^\n]", phoneNum);
        clearKeyboard();

        // (String Length Function: validate entry of 10 characters)
        if (strlen(phoneNum) == 10) {
            int i, numCount = 0;
            for (i = 0; i < 10; i++) {
                if (!isdigit(phoneNum[i])) {
                    printf("Enter a 10-digit phone number: ");
                    break;
                }
                else {
                    numCount++;
                }
            }
            if (numCount == 10) {
                needInput = 0;
            }
        }
        else
        {
            printf("Enter a 10-digit phone number: ");
        }
    }
}


// findContactIndex:
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[])
{   
    int i;
    for (i = 0; i < size; i++) {
        if (strcmp(contacts[i].numbers.cell, cellNum) == 0) {
            return i;
        }
    }
    return -1;
          
}


// displayContactHeader
void displayContactHeader(void) {
    printf("+");
    int i;
    for (i = 0; i < 77; i++) {
        printf("-");
    }
    printf("+\n");
    printf("|");
    for (i = 0; i < 30; i++) {
        printf(" ");
    }
    printf("Contacts Listing");
    for (i = 0; i < 31; i++) {
        printf(" ");
    }
    printf("|\n");
    printf("+");
    for (i = 0; i < 77; i++) {
        printf("-");
    }
    printf("+\n");
}


// displayContactFooter:
void displayContactFooter(int count) {
    printf("+");
    int i;
    for (i = 0; i < 77; i++) {
        printf("-");
    }
    printf("+\n");
    printf("Total contacts: %d\n\n", count);
}


// displayContact:
void displayContact(const struct Contact* contact) {
    if (strcmp((*contact).name.middleInitial, "\0") != 0) {
        printf(" %s %s %s\n",
            (*contact).name.firstName, (*contact).name.middleInitial, (*contact).name.lastName);
    }
    else {
        printf(" %s %s\n", (*contact).name.firstName, (*contact).name.lastName);
    }
    printf("    C: %-10s   H: %-10s   B: %-10s\n",
        (*contact).numbers.cell, (*contact).numbers.home, (*contact).numbers.business);
    printf("       %d %s, ", (*contact).address.streetNumber, (*contact).address.street);
    if ((*contact).address.apartmentNumber > 0) {
        printf("Apt# %d, ", (*contact).address.apartmentNumber);
    }
    printf("%s, %s\n", (*contact).address.city, (*contact).address.postalCode);
}


// displayContacts:
void displayContacts(const struct Contact contacts[], int size) {
    int valCount = 0;
    
    displayContactHeader();
    int i,j;
    for (i = 0; i < size; i++) {
        int zeroCount = 0;
        for (j = 0; j < 10; j++) {            
            if (contacts[i].numbers.cell[j] == '0') {
                zeroCount++;
            }            
        }
        if (zeroCount != 10) {
            if (strcmp(contacts[i].numbers.cell, "\0") != 0) 
            {
                displayContact(&(contacts[i]));
                valCount++;
            }
        }
    }
    displayContactFooter(valCount);
}


// searchContacts:
void searchContacts(const struct Contact contacts[], int size) {
    char celNum[100];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(celNum);
    int index = findContactIndex(contacts, size, celNum);
    if ( index != -1) {
        printf("\n");
        displayContact(&(contacts[index]));
        printf("\n");
    }
    else {
        printf("*** Contact NOT FOUND ***\n\n");
    }
}


// addContact:
void addContact(struct Contact contacts[], int size) {
    //check if there's any cell number string length equal to zero(0)
    int index = findContactIndex(contacts, size,  "\0"); 
    if (index != -1) {
        getContact(&(contacts[index]));
        printf("--- New contact added! ---\n\n");
    }
    else {
        printf("*** ERROR: The contact list is full! ***\n\n");
    }
    
}


// updateContact:
void updateContact(struct Contact contacts[], int size) {
    char celNum[100];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(celNum);
    int index = findContactIndex(contacts, size, celNum);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n\n");
    }
    else {
        printf("\nContact found:\n");
        displayContact(&(contacts[index]));
        printf("\n");
        printf("Do you want to update the name? (y or n): ");
        if (yes() == 1) {
            getName(&(contacts[index].name));
        }
        printf("Do you want to update the address? (y or n): ");
        if (yes() == 1) {
            getAddress(&(contacts[index].address));
        }
        printf("Do you want to update the numbers? (y or n): ");
        if (yes() == 1) {
            getNumbers(&(contacts[index].numbers));
        }
        printf("--- Contact Updated! ---\n\n");
    }
}


// deleteContact:
void deleteContact(struct Contact contacts[], int size) {
    char celNum[100];
    printf("Enter the cell number for the contact: ");
    getTenDigitPhone(celNum);
    int index = findContactIndex(contacts, size, celNum);
    if (index == -1) {
        printf("*** Contact NOT FOUND ***\n");
    }
    else {
        printf("\nContact found:\n");
        displayContact(&(contacts[index]));
        printf("\n");
        printf("CONFIRM: Delete this contact? (y or n): ");
        if (yes() == 1) {
            contacts[index].numbers.cell[0] = '\0';
            printf("--- Contact deleted! ---\n\n");
        }
        else {
            printf("\n");
        }
        
    }
}


// sortContacts:
void sortContacts(struct Contact contacts[], int size) {
    int i, j;
    struct Contact temp;
    for (i = size-1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (strcmp(contacts[j].numbers.cell, contacts[j + 1].numbers.cell) > 0 ){
                temp = contacts[j];
                contacts[j] = contacts[j + 1];
                contacts[j + 1] = temp;
            }
        }
    }
    printf("--- Contacts sorted! ---\n\n");
}
