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
 * 
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
        printf("Q --> Quit\n\n");

        while (!isalnum(c = getchar())); // Solange einlesen bis Zahl oder Buchstabe
        c = toupper(c); // Make Uppercase 'c' --> 'C'

        switch (c) {
            case 'N':
                addNewAddress();
                break;
            case 'L':
                printAddress(startPointer);
                break;
                /*case 'R':
                    readAddressFile();
                    break;
                case 'S':
                    saveAddressFile();
                    break;
                case '1':
                    sortByName();
                case '2':
                    sortByStreet();
                    break;
                case '3':
                    sortByCity();
                    break;
                case 'Q':
                    quit();
                    break; */
                         
        }

    } while (c != 'Q');
    
    return (EXIT_SUCCESS);
}


