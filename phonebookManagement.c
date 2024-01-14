#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 20
#define MAX_EMAIL_LENGTH 50
#define MAX_ADDRESS_LENGTH 100

struct PhoneBook {
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
};


int main() {
    int choice;

    while (1) {
        
        printf("PhoneBook Management System\n\n");
       
        printf("1. Add contact\n");
        printf("2. Edit contact\n");
        printf("3. Delete contact\n");
        printf("4. Display all contacts\n");
        printf("5. Search contact\n");
        printf("6. Exit\n");
     
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_contact();
                break;
            case 2:
                edit_contact();
                break;
            case 3:
                delete_contact();
                break;
            case 4:
                display_contacts();
                break;
            case 5:
                search_contact();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}

void add_contact() {
    struct PhoneBook contact;
    FILE *fp;

    fp = fopen("contacts.txt", "a");

    printf("Enter name: ");
    scanf("%s", contact.name);
    printf("Enter phone number: ");
    scanf("%s", contact.phone);
    printf("Enter email without @gmail.com: ");
    scanf("%s",contact.email);
    printf("Enter address: ");
    scanf("%s",contact.address);

    fprintf(fp, "%s %s %s@gmail.com %s\n", contact.name, contact.phone, contact.email, contact.address);

    printf("Contact added successfully\n");

    fclose(fp);
}

void edit_contact() {
    struct PhoneBook contact;
    FILE *fp, *temp;
    char name[MAX_NAME_LENGTH];
    char phone[MAX_PHONE_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char address[MAX_ADDRESS_LENGTH];
    int found = 0;

    printf("Enter name to edit: ");
    scanf("%s", name);

    fp = fopen("contacts.txt", "r");
    temp = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %s %s ", contact.name, contact.phone, contact.email,contact.address) != EOF) {
        if (strcmp(name, contact.name) == 0) {
            printf("Enter new phone number: ");
            scanf("%s", phone);
            printf("Enter new email without @gmail.com: ");
            scanf("%s", email);
            printf("Enter new address: ");
            scanf("%s", address);

            fprintf(temp, "%s %s %s@gmail.com %s\n", name, phone,email,address);
            found = 1;

            printf("Contact updated successfully\n");
        } else {
            fprintf(temp, "%s %s %s %s\n", contact.name, contact.phone, contact.email,contact.address);
        }
    }

    if (!found) {
        printf("Contact not found\n");
    }

    fclose(fp);
    fclose(temp);

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
}

void delete_contact() {
    struct PhoneBook contact;
    FILE *fp, *temp;
    char name[MAX_NAME_LENGTH];
    int found = 0;

    printf("Enter name to delete: ");
    scanf("%s", name);

    fp = fopen("contacts.txt", "r");
    temp = fopen("temp.txt", "w");

    while (fscanf(fp, "%s %s %s %s", contact.name, contact.phone,contact.email,contact.address) != EOF) {
        if (strcmp(name, contact.name) == 0) {
            found = 1;

            printf("Contact deleted successfully\n");
        } else {
            fprintf(temp, "%s %s %s %s\n", contact.name, contact.phone,contact.email,contact.address);
        }
    }

    if (!found) {
        printf("Contact not found\n");
    }
    fclose(fp);
    fclose(temp);   
    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");
    }

void display_contacts() {
struct PhoneBook contact;
FILE *fp;
fp = fopen("contacts.txt", "r");

printf("Name\t\tPhone\t\t\tEmail\t\t\tAddress\n");
printf("--------------------------------------------------------------------------------------\n");

while (fscanf(fp, "%s %s %s %s", contact.name, contact.phone,contact.email,contact.address) != EOF) {
    printf("%s\t\t%s\t\t%s\t\t%s\n", contact.name, contact.phone,contact.email,contact.address);
}

fclose(fp);
}
void search_contact() {
struct PhoneBook contact;
FILE *fp;
char name[MAX_NAME_LENGTH];


int found = 0;
printf("Enter name to search: ");
scanf("%s", name);

fp = fopen("contacts.txt", "r");

while (fscanf(fp, "%s %s %s %s", contact.name, contact.phone,contact.email,contact.address) != EOF) {
    if (strcmp(name, contact.name) == 0) {
        printf("Name\t\tPhone\t\tEmail\t\tAddress\n");
        printf("---------------------------------------\n");
        printf("%s\t\t%s\t\t%s\t\t%s\n", contact.name, contact.phone,contact.email,contact.address);
        found = 1;
    }
}

if (!found) {
    printf("Contact not found\n");
}

fclose(fp);
}






