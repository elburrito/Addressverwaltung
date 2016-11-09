/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Address.h
 * Author: Khando
 *
 * Created on 7. November 2016, 17:18
 */

#ifndef ADDRESS_H
#define ADDRESS_H
#define MAX 45

typedef struct Address_* AddressPtr_t;
AddressPtr_t startPointer;
 
typedef struct Address_{
    char firstname[MAX];
    char name[MAX]; 
    char streetName[MAX];
    int streetNumber;
    int zip;            // könnte man hier int:5 machen? 
    char city[MAX];
    int index;          // index for sorting functions
    AddressPtr_t next;  //Pointer auf nächste Addresse
} Address_t; 


/*function adds new Address and returns a pointer to struct Address_ (currently used in printAddress function)*/
AddressPtr_t addNewAddress(void);

void printAddress (AddressPtr_t printPointer);

/*readAddressFile();

saveAddressFile();

sortByName();

sortByStreet();

sortByCity();

quit(); */

#endif