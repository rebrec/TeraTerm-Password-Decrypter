/* Tera Term
Copyright(C) 1994-1998 T. Teranishi
All rights reserved. */
/* TTMACRO.EXE, password encryption */
//#include "teraterm.h"
#include "./def.h"
//#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

int main(int argc, char *argv[])
{
   string line;
   char * strIN;
   char * strOUT;
    ifstream myfile ("data.txt");
    if (myfile.is_open())
    {
        while ( myfile.good() )
        {
            getline (myfile,line);
            cout << "Original : " << line << endl;

	    strIN = new char [line.length()+1];
	    strOUT = new char [50];
  	    std::strcpy (strIN, line.c_str());
	    Decrypt(strIN,strOUT);
	    printf("%s\n",strOUT);
        }
        myfile.close();
    }
    else cout << "Unable to open file"; 

    return 0;

/*
	size_t nb = 38;
	char line[80];
	//CHAR Output = malloc(sizeof(CHAR) * nb);
	char * Output;
	Output = (char) malloc(sizeof(char) * 80);
	//char* my_string = (char *) malloc (sizeof(char)*nb);
	//Decrypt(argv[1],Output);
	//printf("Chaine décryptée  : %s\n", Output);
	FILE *filepointer;
	char string[100];
	filepointer=fopen("data.txt", "r"); /* filepointer points to data.txt */
/*	if (filepointer==NULL) { /* error opening file returns NULL */
/*		printf("Could not open data.txt!\n"); /* error message */
/*		return 1; /* exit with failure */
/*	}
	while(read(filepointer,80,Output) !=NULL)
	{
		printf("une ligne\n");
	//	sscanf (line, "%c", Output);
		printf("%s\n", Output);
	}	

	fclose(filepointer); /* close the file */
	//return 0; /* success */
	
}



void DecCombine(PCHAR Str, int *i, BYTE b)
{
	int cptr, bptr;
	unsigned int d;
	cptr = *i / 8;
	bptr = *i % 8;
	if (bptr==0) {
		Str[cptr] = 0;
	}
	d = ((BYTE)Str[cptr] << 8) |
	(b << (10 - bptr));
	Str[cptr] = (BYTE)(d >> 8);
	Str[cptr+1] = (BYTE)(d & 0xff);
	*i = *i + 6;
	return;
}
BYTE DecCharacter(BYTE c, LPBYTE b)
{
	BYTE d;
	if (c < *b) {
		d = (BYTE)0x5e + c - *b;
	}
	else {
		d = c - *b;
	}
	d = d & 0x3f;
	if (*b<0x30) {
		*b = 0x30;
	}
	else if (*b<0x40) {
		*b = 0x40;
	}
	else if (*b<0x50) {
		*b = 0x50;
	}
	else if (*b<0x60) {
		*b = 0x60;
	}
	else if (*b<0x70) {
		*b = 0x70;
	}
	else {
		*b = 0x21;
	}
	return d;
}
void Decrypt(PCHAR InStr, PCHAR OutStr)
{
	int i, j, k;
	BYTE b;
	char Temp[512];
	OutStr[0] = 0;
	j = strlen(InStr);
	if (j==0) {
		return;
	}
	b = 0x21;
	for (i=0 ; i < j ; i++) {
		Temp[i] = DecCharacter(InStr[i],&b);
	}
	if ((Temp[0] ^ Temp[j-1]) != (BYTE)0x3f) {
		return;
	}
	i = 1;
	k = 0;
	while (i < j-2) {
		Temp[i] = ((BYTE)Temp[i] - (BYTE)Temp[i+1]) & (BYTE)0x3f;
		DecCombine(OutStr,&k,Temp[i]);
		i = i + 2;
	}
}
