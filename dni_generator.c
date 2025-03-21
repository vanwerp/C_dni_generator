#include <stdlib.h>
#include <time.h>
#include <stdio.h>

char get_letter(int dni_number);

int main(void)
{   
    char dni[9];

    printf("Welcome to my Spanish ID (DNI) generator \n");
    printf("Generating ID number... \n");

    srand(time(NULL));
    
    for (int i = 0; i < 8; i++)
    {
        dni[i] = (rand() % 10) + '0';
    }

    printf("Getting ID letter... \n");
    int dni_number;
    sscanf(dni,"%d",&dni_number);
    dni[8] = get_letter(dni_number);

    printf("Your random ID is: %s \n",dni);

    return 0;
}

char get_letter(int dni_number)
{
    switch (dni_number % 23)
    {
    case 0:
        return 'T';
    case 1:
        return 'R';
    case 2:
        return 'W';
    case 3:
        return 'A';
    case 4:
        return 'G';
    case 5:
        return 'M';
    case 6:
        return 'Y';
    case 7:
        return 'F';
    case 8:
        return 'P';
    case 9:
        return 'D';
    case 10:
        return 'X';
    case 11:
        return 'B';
    case 12:
        return 'N';
    case 13:
        return 'J';
    case 14:
        return 'Z';
    case 15:
        return 'S';
    case 16:
        return 'Q';
    case 17:
        return 'V';
    case 18:
        return 'H';
    case 19:
        return 'L';
    case 20:
        return 'C';
    case 21:
        return 'K';
    case 22:
        return 'E';
    }
}