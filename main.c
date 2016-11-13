/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 *http://www.anyexample.com/programming/c/qsort__sorting_array_of_strings__integers_and_structs.xml/

/* 
 * File:   main.c
 * Author: Khando
 *
 * Created on 7. November 2016, 17:17
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "Address.h"

/*
 * TODO: implement delete option to delete all addresses and free memory !!! 
 */

AddressPtr_t startPointer = NULL; //pointer auf struct Address_t

int main(int argc, char** argv) {
    char c;

    do {
        printf("\n");
        printf("N --> New address\n");
        printf("L --> List addresses\n");
        printf("R --> Read addresses from file\n");
        printf("S --> Save addresses to file\n");
        printf("1 --> Sort list by name\n");
        printf("2 --> Sort list by street\n");
        printf("3 --> Sort list by city\n");
        printf("4 --> Sort list by ZIP\n");
        printf("Q --> Quit\n\n");

        while (!isalnum(c = getchar())); // Solange einlesen bis Zahl oder Buchstabe
        c = toupper(c); // Make Uppercase 'c' --> 'C'

        switch (c) {
            case 'N':
                addNewAddress();
                break;
            case 'L':
                printAddressConsole();
                break;
            case 'S':
                printAddressFile();
                break;
            case 'R':
                readAddressFile();
                break;
            case 'Q':
                quit();
                break;
            case '1':
                sortList(startPointer, c);
                break;
            case '2':
                sortList(startPointer, c);
                break;
            case '3':
                sortList(startPointer, c);
                break;
            case '4':
                sortList(startPointer, c);
                break;
        }

    } while (c != 'Q');

    return (EXIT_SUCCESS);
}
