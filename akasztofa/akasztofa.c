#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "akasztofa.h"
#include <conio.h>
#include <windows.h>
#define N 100
#define HIBA1 7


void beolvas(char *fajlNev, char szo[N])
{
    FILE *be;
    be = fopen(fajlNev, "rt");
    if(!be)
    {
        printf("Fajl megnyitasi hiba!\n");
        exit(1);
    }

    srand(time(NULL));
    int sor = rand() % 10 + 1;

    for(int i = 1; i <= sor && fscanf(be, "%s", szo) != EOF; i++);
    printf("%s", szo);
    fclose(be);
}


int kiir_es_feldolgoz(char *fajlNev)
{
    char szo[N];
    beolvas(fajlNev, szo);

    char megfejtes[N], helytelen[N];
    int hossz = strlen(szo);
    for(int i = 0; i < hossz; i++)
    {
        if(szo[i] != ' ')
        {
            megfejtes[i] = '_';
        }

    }

    int hiba = 0, helyes = 0;
    char ch;
    bool f;

    while(hiba < 7 && helyes < hossz)
    {

        printf("A szo: %s\nA szo %i betubol all\tHatralevo probalkozasok szama: %i\tHelytelen karakterek: ", megfejtes, strlen(szo), 7 - hiba);
        for(int i = 0; i < hiba; i++)
        {
            printf("%c, ", helytelen[i]);
        }
        printf("\nIrj be egy karaktert!\n");
        kirajzol(hiba);
        ch = getche();
        f = false;
        for(int i = 0; i < hossz; i++)
        {
            if(ch == szo[i])
            {
                megfejtes[i] = ch;
                f = true;
                helyes++;
            }

        }

        if(f == false)
        {
            helytelen[hiba] = ch;
            hiba++;

            printf("\nNincs ilyen karakter :( \n");
            Sleep(1500);
        }

        if(hiba == 6)
        {
            printf("Egy probalkozasod maradt\nA gep segit egy karaktert\n");
            Sleep(1500);
            segitseg(szo,megfejtes);
            helyes++;
        }

        system("CLS");
    }

    if(hiba >= 7)
    {
        printf("Vesztettél :(\n");
        Sleep(2000);
        return helyes;
    }
    return 25;
}

void kirajzol(int hiba)
{
    switch(hiba)
    {
        case 1: printf("|\n|\n"); break;
        case 2: printf("|\n|\n|\n|\n"); break;
        case 3: printf("|-----\n|\n|\n|\n"); break;
        case 4: printf("|-----\n|    O\n|\n|\n"); break;
        case 5: printf("|-----\n|    O\n|    |\n|\n"); break;
        case 6: printf("|-----\n|    O\n|   -|-\n|\n"); break;
        case 7: printf("|-----\n|    O\n|   -|-\n|   / "); printf("\\");break;
    }
}

int ket_jatekos(char szo[N])
{
    char megfejtes[N], helytelen[N];
    int hossz = strlen(szo);
    for(int i = 0; i < hossz; i++)
    {
        if(szo[i] != ' ')
        {
            megfejtes[i] = '_';
        }

    }

    int hiba = 0, helyes = 0;
    char ch;
    bool f;

    while(hiba < 7 && helyes < hossz)
    {
        printf("A szo: %s\nA szo %i betubol all\tHatralevo probalkozasok szama: %i\tHelytelen karakterek: ", megfejtes, strlen(szo), 7 - hiba);
        for(int i = 0; i < hiba; i++)
        {
            printf("%c, ", helytelen[i]);
        }
        printf("\nIrj be egy karaktert!\n");
        kirajzol(hiba);
        ch = getche();
        f = false;
        for(int i = 0; i < hossz; i++)
        {
            if(ch == szo[i])
            {
                megfejtes[i] = ch;
                f = true;
                helyes++;
            }

        }

        if(f == false)
        {
            helytelen[hiba] = ch;
            hiba++;

            printf("\nNincs ilyen karakter :( \n");
            Sleep(1500);
        }

        if(hiba == 6)
        {
            printf("Egy probalkozasod maradt\nA gep segit egy karaktert\n");
            Sleep(1500);
            segitseg(szo,megfejtes);
            helyes++;
        }

        system("CLS");
    }
    if(hiba >= 7)
    {
        printf("Vesztettel :(\n");
        Sleep(2000);
        return helyes;
    }
    return 25;
}

char jatek_tipusa()
{
    printf("1: Egy szemely jatszik.\n2: Ket szemely jatszik.");
    char valasz = getch();
    printf("%c ",valasz);
    while(valasz != '1' && valasz != '2')
    {
        printf("Helytelen valasztas!\nProbald ujra\n");
        valasz = getch();
    }

    system("cls");
    return valasz;
}

int jatek(char valasz)
{

    char szo[N];
    int pont;
    if(valasz == '1')
    {
        pont = kiir_es_feldolgoz("szavak.txt");
        return pont;
    }
    else
    {
        printf("Az elso jatekos irjon be egy szavat, amit a masodik jatekos kell kitalaljon\n");
        scanf("%s", szo);
        printf("A masodik jatekos talalja ki a szavat!\n");
        //Sleep(1000);
        system("cls");
        ket_jatekos(szo);

    }

}

void ismetles()
{
    FILE *bk;
    char ch;
    int pontok = 0, aktualis_pont;
    char valasz = jatek_tipusa();
    do
    {
        aktualis_pont = jatek(valasz);
        pontok += aktualis_pont;
        printf("Ebben a jatekben elert pontod: %i\nAz osszpontszamod: %i\n", aktualis_pont, pontok);
        printf("Szeretnel meg jatszani? (i-igen, barmi mas-nem)\n");
        ch = getch();
        system("cls");

    }
    while(ch == 'i');
    bk = fopen("rekord.txt", "rt");
    if(!bk)
    {
        printf("Hianyzik a rekord.txt fájl!!!");
        exit(1);
    }
    int rekord;
    fscanf(bk,"%i",&rekord);
    system("cls");
    printf("Az eddigi rekord: %i\n", rekord);
    fclose(bk);
    if(aktualis_pont > rekord)
    {
        remove("rekord.txt");
        bk = fopen("rekord.txt", "wt");
        fprintf(bk,"%i",pontok);
        fclose(bk);
        printf("Rekordott dontottel!\nEddigi rekord: %i, a te pontszamod: %i", rekord, pontok);
    }

}

void segitseg(char szo[], char megfejtes[])
{
    bool f = true;
    srand(time(0));
    int r;
    while(f)
    {
        r = rand() % strlen(szo);
        if(megfejtes[r] == '_')
        {
            megfejtes[r] = szo[r];
            f = false;
        }
    }
}

