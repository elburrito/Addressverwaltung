/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"

/* 
 * Im Moment eine einfache verkettete Liste
 */

AddressPtr_t addNewAddress(void) {
    

    AddressPtr_t tempPtr;   // Pointer to struct Address_


    if ((tempPtr = (AddressPtr_t) malloc(sizeof (Address_t))) != NULL) { // Speicherallokiierung erfolgreich

        printf("First name: ");
        scanf("%s[^\n]", &tempPtr->firstname);

        printf("Last name: ");
        scanf("%s[^\n]", &tempPtr->name);

        printf("Street name: ");
        scanf("%s[^\n]", &tempPtr->streetName);

        printf("Street number: ");
        scanf("%d[^\n]", &tempPtr->streetNumber);

        printf("Zip number: ");
        scanf("%d[^\n]", &tempPtr->zip);

        printf("City: ");
        scanf("%s[^\n]", &tempPtr->city);

        tempPtr->next = startPointer;
        startPointer = tempPtr;
        return startPointer;
    }
}

/* @param startPointer, pointing to the first element of the linked list*/
void printAddress (AddressPtr_t printPointer) {

    //AddressPtr_t printPointer = startPointer;

    while (startPointer != NULL) {
        printf("Firstname: %s\n", startPointer->firstname);
        printf("Name: %s\n", startPointer->name);
        printf("Street name: %s\n", startPointer->streetName);
        printf("Street number: %d\n", startPointer->streetNumber);
        printf("Zip number: %d\n", startPointer->zip);
        printf("City: %s\n\n", startPointer->city);

        startPointer = startPointer->next;
    }
}

