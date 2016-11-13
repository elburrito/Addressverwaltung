/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "Address.h"

void readAddressFile() {

    AddressPtr_t tempPtr = startPointer; // Pointer to struct Address_

    FILE *fp = fopen("addressFile.txt", "r"); // Alternativ "a", wenn nicht überschrieben werden soll
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    }

    while ((!feof(fp)) && ((tempPtr = (AddressPtr_t) malloc(sizeof (Address_t))) != NULL)) {

        fscanf(fp, "%s[^\n]", &tempPtr->firstname);
        fscanf(fp, "%s[^\n]", &tempPtr->name);
        fscanf(fp, "%s[^\n]", &tempPtr->streetName);
        fscanf(fp, "%d[^\n]", &tempPtr->streetNumber);
        fscanf(fp, "%d[^\n]", &tempPtr->zip);
        fscanf(fp, "%s[^\n]", &tempPtr->city);

        tempPtr->next = startPointer;
        startPointer = tempPtr;
    }
    fclose(fp);
}

void printAddressFile() {

    AddressPtr_t printFilePointer = startPointer;

    FILE *fp = fopen("fileAddressen", "w"); // Alternativ "a", wenn nicht überschrieben werden soll
    if (fp == NULL) {
        printf("Error opening file!\n");
        exit(1);
    } else {

        while (printFilePointer != NULL) {
            fprintf(fp, "Firstname: %s\r\n", printFilePointer->firstname);
            fprintf(fp, "Name: %s\r\n", printFilePointer->name);
            fprintf(fp, "Street name: %s\r\n", printFilePointer->streetName);
            fprintf(fp, "Street number: %d\r\n", printFilePointer->streetNumber);
            fprintf(fp, "Zip number: %d\r\n", printFilePointer->zip);
            fprintf(fp, "City: %s\r\n\r\n", printFilePointer->city);

            printFilePointer = printFilePointer->next;
        }
        fclose(fp);
    }
}

