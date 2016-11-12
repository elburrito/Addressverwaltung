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

void readAddressFile() {

    AddressPtr_t tempPtr; // Pointer to struct Address_

    FILE *f = fopen("addressFile.txt", "r"); // Alternativ "a", wenn nicht überschrieben werden soll
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    if ((tempPtr = (AddressPtr_t) malloc(sizeof (Address_t))) != NULL) { // Speicherallokiierung erfolgreich

        fscanf(f, "%s[^\n]", &tempPtr->firstname);
        fscanf(f, "%s[^\n]", &tempPtr->name);
        fscanf(f, "%s[^\n]", &tempPtr->streetName);
        fscanf(f, "%d[^\n]", &tempPtr->streetNumber);
        fscanf(f, "%d[^\n]", &tempPtr->zip);
        fscanf(f, "%s[^\n]", &tempPtr->city);

        tempPtr->next = startPointer;
        startPointer = tempPtr;
    }
}

void printAddressFile() {

    AddressPtr_t printFilePointer = startPointer;

    FILE *f = fopen("fileAddressen", "w"); // Alternativ "a", wenn nicht überschrieben werden soll
    if (f == NULL) {
        printf("Error opening file!\n");
        exit(1);
    } else {

        while (printFilePointer != NULL) {
            fprintf(f, "Firstname: %s\r\n", printFilePointer->firstname);
            fprintf(f, "Name: %s\r\n", printFilePointer->name);
            fprintf(f, "Street name: %s\r\n", printFilePointer->streetName);
            fprintf(f, "Street number: %d\r\n", printFilePointer->streetNumber);
            fprintf(f, "Zip number: %d\r\n", printFilePointer->zip);
            fprintf(f, "City: %s\r\n\r\n", printFilePointer->city);

            printFilePointer = printFilePointer->next;
        }
        fclose(f);
    }
}

