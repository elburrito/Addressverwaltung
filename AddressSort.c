/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Address.h"

/* @param startPointer*/
void sortList(AddressPtr_t start, char criteria){
    char currentField = criteria;

    int swapped = 0;
    AddressPtr_t ptr1;
    AddressPtr_t ptr2 = NULL;

    if (ptr1 == NULL) {
        return;
    }

    do {
        swapped = 0;
        ptr1 = start;
        int rc = 0;

        while (ptr1->next != ptr2) {
            switch (currentField) {
                case '1': rc = strcmp(ptr1->firstname, ptr1->next->firstname);
                    break;
                case '2': rc = strcmp(ptr1->streetName, ptr1->next->streetName);
                    break;
                case '3': rc = strcmp(ptr1->city, ptr1->next->city);
                    break;
                case '4': rc = ((ptr1->zip) > (ptr1->next->zip));       
                    break;
            }
            if (rc > 0) {
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
