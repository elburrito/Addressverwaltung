/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <windows.h>
#include "Address.h"

/* 
 * Im Moment eine einfache verkettete Liste
 */

int quit(){
    MessageBox(0,"DO YOU LIKE NATURE?", "------------xXXX YOU QUIT XXXx----------", MB_YESNO);
    return(EXIT_SUCCESS);
}

void addNewAddress() {
    
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
        total++;
    }
}

void printAddressConsole(){
    
    AddressPtr_t printConsPointer = startPointer;

    while (printConsPointer != NULL) {
        printf("Firstname: %s\n", printConsPointer->firstname);
        printf("Name: %s\n", printConsPointer->name);
        printf("Street name: %s\n", printConsPointer->streetName);
        printf("Street number: %d\n", printConsPointer->streetNumber);
        printf("Zip number: %d\n", printConsPointer->zip);
        printf("City: %s\n\n", printConsPointer->city);

        printConsPointer = printConsPointer->next;
    }
}

