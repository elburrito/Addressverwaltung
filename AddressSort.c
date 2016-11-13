/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Address.h"

/* TODO: make it the same function for Ints and for Strings by turning zip into char*/

/* @param startPointer*/
void sortByZip(AddressPtr_t start) {
    int swapped = 0;
    AddressPtr_t ptr1;
    AddressPtr_t ptr2 = NULL;

    if (ptr1 == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != ptr2) {
            if (ptr1->zip > ptr1->next->zip) {
                swapAll(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

/* @param startPointer*/

/*TODO: substitute name by the field chosen by user criteria*/
void sortByFirstName(AddressPtr_t start) {

    int swapped = 0;
    AddressPtr_t ptr1;
    AddressPtr_t ptr2 = NULL;

    if (ptr1 == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = start;

        while (ptr1->next != ptr2) {
            if ((strcmp(ptr1->firstname, ptr1->next->firstname)) > 0) {
                swapAll(ptr1, ptr1->next);
                swapped = 1;
            }
            ptr1 = ptr1->next;
        }
        ptr2 = ptr1;
    } while (swapped);
}

void swapAll(AddressPtr_t a, AddressPtr_t b) {
    int tempZip = a->zip;
    a->zip = b->zip;
    b->zip = tempZip;

    int tempStreet = a->streetNumber;
    a->streetNumber = b->streetNumber;
    b->streetNumber = tempStreet;

    char buffer[MAX];
    strcpy(buffer, a->firstname);
    strcpy(a->firstname, b->firstname);
    strcpy(b->firstname, buffer);

    strcpy(buffer, a->name);
    strcpy(a->name, b->name);
    strcpy(b->name, buffer);

    strcpy(buffer, a->streetName);
    strcpy(a->streetName, b->streetName);
    strcpy(b->streetName, buffer);

    strcpy(buffer, a->city);
    strcpy(a->city, b->city);
    strcpy(b->city, buffer);

}

/*char getCriteria() {
    char field;
    do {
        printf("By which criteria do you want to sort?\n");
        printf("F --> First name\n");
        printf("L --> Last name\n");
        printf("S --> Street name\n");
        // printf("N --> Street number\n");
        printf("Z --> Zip code\n");
        printf("C --> City \n");
        printf("Q --> Quit programm \n");

        while (!isalnum(field = getchar())); // Solange einlesen bis Zahl oder Buchstabe
        field = toupper(field); // Make Uppercase 'c' --> 'C'      

    } while (field != 'Q');
    return field;
} */