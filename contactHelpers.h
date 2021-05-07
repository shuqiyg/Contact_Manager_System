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

// +-------------------------------------------------+
// | NOTE:  Copy/Paste your Assignment-2 Milestone-2 |
// |        contents below...                        |
// +-------------------------------------------------+

#include "contacts.h"

// clearKeyboard
void clearKeyboard(void);

// pause
void pause(void);

// getInt
int getInt(void);

// getIntInRange
int getIntInRange(int min, int max);

// yes
int yes(void);

// menu
int menu(void);

// contactManagerSystem
void contactManagerSystem(void);

// +-------------------------------------------------+
// |                                                 |
// |                    N E W                        |
// |           S T U F F     G O E S                 |
// |                  B E L O W                      |
// |                                                 |
// +-------------------------------------------------+
// | ====== Assignment 2 | Milestone 3 =======       |
// +-------------------------------------------------+
// | NOTE:  Add new function prototypes as per the   |
// |        Milestone-3 specifications document      |
// +-------------------------------------------------+

// Generic function to get a ten-digit phone number (provided for you)
void getTenDigitPhone(char phoneNum[]);


// findContactIndex (provided for you)
int findContactIndex(const struct Contact contacts[], int size, const char cellNum[]);


// displayContactHeader
void displayContactHeader(void);


// displayContactFooter:
void displayContactFooter(int count);


// displayContact:
void displayContact(const struct Contact* contact);


// displayContacts:
void displayContacts(const struct Contact contacts[], int size);


// searchContacts:
void searchContacts(const struct Contact contacts[], int size);


// addContact:
void addContact(struct Contact contacts[], int size);


// updateContact:
void updateContact(struct Contact contacts[], int size);


// deleteContact:
void deleteContact(struct Contact contacts[], int size);


// sortContacts:
void sortContacts(struct Contact contacts[], int size);
