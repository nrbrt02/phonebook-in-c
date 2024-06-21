#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct{

    char name[50];
    int contactN;
    char email[60];

}contact;

add();
all();
search();
update();
deleteC();

int main(){
        system("color 1b");

    int choice;

    do{
        printf("\t\t\t\t\ ====== PHONEBOOK SYSTEM =====");
        printf("\n\t\t\t\t\t-------------------------\n");
        printf("\t\t\t\t\ 1- Add Contact \n");
        printf("\t\t\t\t\ 2- View All contacts \n");
        printf("\t\t\t\t\ 3- Search  Contact by Name \n");
        printf("\t\t\t\t\ 4- Update Contact \n");
        printf("\t\t\t\t\ 5- Delete Contact \n");
        printf("\t\t\t\t\ 0- Exit \n");
        printf("\t\t\t\t\ --------------------------------\n");

        scanf("%d", &choice);

        switch(choice){
            case 1:
                system("cls");
                add();
                break;
            case 2:
                system("cls");
                all();
                break;
            case 3:
                system("cls");
                search();
                break;
            case 4:
                system("cls");
                update();
                break;
            case 5:
                system("cls");
                deleteC();
                break;
        }

    }while(choice != 0);

}

add(){
            system("color 3b");

        FILE *AddContact;

        AddContact = fopen("contact.txt", "a");

        printf("\n\t\t\t\t\ Contact Name:... ");
        scanf("%s", contact.name);
        printf("\n\t\t\t\t\ Contact Number:... ");
        scanf("%d", &contact.contactN);
        printf("\n\t\t\t\t\ Contact Email:... ");
        scanf("%s", contact.email);

        fwrite(&contact, sizeof(contact), 1, AddContact);
        //fprintf(AddContact, "%s\t%d\t%s\t|\n", contact.name, contact.contactN, contact.email);

        printf("\n\t\t\t\t\ ====== Contact Added successfly ===== \n\n");

        fclose(AddContact);

}

all(){
            system("color 8c");

    FILE *allContact;
    char buffer[200];
    int n = 0;
    allContact = fopen("contact.txt", "r");

    printf("\t\t\t\t\ ====== Phonebook-All Records ===== \n\n");
    printf("\t\t\t\t\+------+----------------+-----------------------+ \n");
    printf("\t\t\t\t\| Name | Number \t| Email\t\t\t| \n");
    printf("\t\t\t\t\+------+----------------+-----------------------+ \n");

    while(fread(&contact, sizeof(contact), 1, allContact)){

        printf("\t\t\t\t|%s\t%d\t%s\t| \n", contact.name, contact.contactN, contact.email);
        printf("\t\t\t\t\+-----------------------------------------------+ \n");
        n++;
    }
    printf("\t\t\t\t\+----------+\n");
    printf("\t\t\t\t\|%d Records |\n", n);
    printf("\t\t\t\t\+----------+\n");

    fclose(allContact);
}

search(){
        system("color 5d");

    FILE *searchContact;
    char searchW[50];
    int count = 0;
    searchContact = fopen("contact.txt", "r");

    printf("\t\t\t\t\ ------Search a Name:....");
    scanf("%s", searchW);

        printf("\t\t\t\t\+------+----------------+---------------+ \n");
        printf("\t\t\t\t\| Name | Number \t| Email \t| \n");
        printf("\t\t\t\t\+------+----------------+---------------+ \n");

    while(fread(&contact, sizeof(contact), 1, searchContact)){



        if(stricmp(searchW, contact.name)==0){

            printf("\t\t\t\t|%s\t%d\t%s\t| \n", contact.name, contact.contactN, contact.email);
            printf("\t\t\t\t\+---------------------------------------+ \n");

            count++;
        }
}
    fclose(searchContact);

    printf("\t\t\t\t+---------------+\n");
    printf("\t\t\t\t| %d record found|\n", count);
    printf("\t\t\t\t+---------------+\n");

}

update(){
        system("color 2e");

    FILE *records, *temp;
    records = fopen("contact.txt", "r");
    temp = fopen("temp.txt", "w");

    char searchW[50];
    int found;

    printf("\t\t\t\t ====== Search A word:....");
    scanf("%s", searchW);

    printf("\t\t\t\t\+------+----------------+---------------+ \n");
    printf("\t\t\t\t\| Name | Number \t| Email \t| \n");
    printf("\t\t\t\t\+------+----------------+---------------+ \n");

    while(fread(&contact, sizeof(contact), 1, records)){

        if(stricmp(contact.name, searchW) == 0){

        printf("\t\t\t\t|%s\t%d\t%s\t| \n", contact.name, contact.contactN, contact.email);
        printf("\t\t\t\t\+---------------------------------------+ \n");

            printf("\n\t\t\t\t\ New Contact Name:... ");
            scanf("%s", contact.name);
            printf("\n\t\t\t\t\ New Contact Number:... ");
            scanf("%d", &contact.contactN);
            printf("\n\t\t\t\t\ New Contact Email:... ");
            scanf("%s", contact.email);

            found = 1;
        }

        fwrite(&contact, sizeof(contact), 1, temp);

    }

    fclose(records);
    fclose(temp);

    if(found == 1){
        remove("contact.txt");
        rename("temp.txt", "contact.txt");
        printf("\n\t\t\t\t\ ===== Record Updated Successfuly \n\n");

    }



}

sort(){}

deleteC(){

    FILE *deleteContact;
    FILE *temp;
    char searchW[50];
    deleteContact = fopen("contact.txt", "r");
    temp = fopen("temp.txt", "w");
    int found = 0;

    printf("\t\t\t\t\ ------Search a Name:....");
    scanf("%s", searchW);

    printf("\n\t\t\t\t\+------+----------------+---------------+ \n");
    printf("\t\t\t\t\| Name | Number \t| Email \t| \n");
    printf("\t\t\t\t\+------+----------------+---------------+ \n");

    while(fread(&contact, sizeof(contact), 1, deleteContact)){


        if(stricmp(searchW, contact.name) == 0){

            printf("\t\t\t\t|%s\t%d\t%s\t| \n", contact.name, contact.contactN, contact.email);
            printf("\t\t\t\t\+---------------------------------------+ \n");

            found = 1;
        }else{
            fwrite(&contact, sizeof(contact), 1, temp);
        }


    }

    fclose(deleteContact);
    fclose(temp);

    if(found == 1){

        remove("contact.txt");
        rename("temp.txt", "contact.txt");
        printf("\t\t\t\t\ ======  Record updated successfuly ===== \n");

    }else if(found = 0){
            printf("\t\t\t\t======== record not found =====\n");
    }else{
            printf("\t\t\t\t======== Something went Wrong|\n");
    }



}
