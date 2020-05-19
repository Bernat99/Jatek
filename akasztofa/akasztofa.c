#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include "akasztofa.h"
#include <conio.h>
#include <windows.h>
#define N 100


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
    int sor = rand() % 19 + 1;

    for(int i = 1; i <= sor && fscanf(be, "%s", szo) != EOF; i++);
    //printf("%s", szo);
    fclose(be);
}


int kiir_es_feldolgoz(char *fajlNev, int lehetoseg)
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
    megfejtes[hossz] = '\0';

    int hiba = 0, helyes = 0;
    char ch, v;
    bool f, voltSegitseg = false;

    while(hiba < lehetoseg && helyes < hossz)
    {

        printf("A szo: %s\nA szo %i betubol all\tHatralevo probalkozasok szama: %i\tHelytelen karakterek: ", megfejtes, strlen(szo), lehetoseg - hiba);
        for(int i = 0; i < hiba; i++)
        {
            printf("%c, ", helytelen[i]);
        }
        printf("\nIrj be egy karaktert!\n");
        //kirajzol(hiba);
        ch = getche();
        f = false;
        for(int i = 0; i < hossz; i++)
        {
            if(ch == szo[i] && megfejtes[i] == '_')
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

        if(hiba == lehetoseg / 2 && !voltSegitseg)
        {
            voltSegitseg = true;
            printf("Szeretned hogy a gep segitsen egy karaktert? (i-igen, barmi mas-nem)\n");
            v = getch();
            if(v == 'i')
            {
                segitseg(szo,megfejtes);
                helyes++;
            }
        }

        system("CLS");
    }
    printf("A helyes megfejtes: %s\n", szo);

    if(hiba >= lehetoseg)
    {
        printf("Vesztettel :(\n");
        Sleep(2000);
        return helyes;
    }
    return 25;
}

/*void kirajzol(int hiba)
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
}*/

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
    megfejtes[hossz] = '\0';
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
        //kirajzol(hiba);
        ch = getche();
        f = false;
        for(int i = 0; i < hossz; i++)
        {
            if(ch == szo[i] && megfejtes[i] == '_')
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

        /*if(hiba == 6)
        {
            printf("Egy probalkozasod maradt\nA gep segit egy karaktert\n");
            Sleep(1500);
            segitseg(szo,megfejtes);
            helyes++;
        }*/

        system("CLS");
    }
    printf("A helyes megfejtes: %s\n", szo);
    if(hiba >= 7)
    {
        //printf("Vesztettel :(\n");

        return helyes;
    }

    return 25;
}

char jatek_tipusa()
{
    printf("\t\t\tSZOJATEK\n\n");
    printf("1: Egy szemely jatszik, 7 probalkozasi lehetoseggel.\n2: Ket szemely jatszik.\n3: Egy szemely jatszik, 12 probalkozasi lehetoseggel.\n");
    char valasz = getch();
    printf("%c ",valasz);
    while(valasz != '1' && valasz != '2' && valasz != '3')
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
        pont = kiir_es_feldolgoz("szavak.txt", 7);
        return pont;
    }
    else
    {
        if(valasz == '2')
        {
            char ch;
            int i = 1, elsoPontja = 0, masodikPontja = 0, x;
            char nev1[N], nev2[N];

            printf("Irajtok be a neveket\nElso jatekos neve:");
            scanf("%s", nev1);
            printf("Masodik jatekos neve: ");
            scanf("%s", nev2);

            do
            {
                printf("%s irjon be egy szavat, amit %s kell kitalaljon\n", i % 2 == 1 ? nev1 : nev2, i % 2 == 0 ? nev1 : nev2);
                scanf("%s", szo);
                printf("%s talalja ki a szavat!\n",i % 2 == 1 ? nev2 : nev1);
                //Sleep(1000);
                system("cls");


                x = ket_jatekos(szo);
                printf("Szeretnetek meg jatszani? (i-igen, barmi mas-nem)\n");
                ch = getch();
                if(i % 2 == 0)
                {
                    elsoPontja += x;
                }
                else
                {
                    masodikPontja += x;
                }
                i++;
            }
            while(ch == 'i');
            printf("%s pontja: %i\n%s pontja: %i\n", nev1,
                   elsoPontja, nev2, masodikPontja);
            if(elsoPontja > masodikPontja)
            {
                printf("%s nyert\n", nev1);
            }
            else
            {
                if(masodikPontja > elsoPontja)
                {
                    printf("%s nyert\n", nev2);
                }
                else
                {
                    printf("A pontszamok egyenlok\n");
                }
            }
        }
        else
            if(valasz == '3')
            {
                pont = kiir_es_feldolgoz("szavak.txt", 12);
                return pont;
            }
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
        if(valasz == '1' || valasz == '3')
        {
            pontok += aktualis_pont;
            printf("Ebben a korben elert pontod: %i\nAz osszpontszamod: %i\n", aktualis_pont, pontok);
            printf("Szeretnel meg jatszani? (i-igen, barmi mas-nem)\n");
            ch = getch();
            system("cls");
        }
    }
    while(ch == 'i');
    if(valasz == '1' || valasz == '3')
    {
        bk = fopen("rekord.txt", "rt");
        if(!bk)
        {
            printf("Hianyzik a rekord.txt fajl!!!");
            exit(1);
        }
        int rekord;
        fscanf(bk,"%i",&rekord);
        //system("cls");
        printf("Az eddigi rekord: %i\nA te pontszamod: %i\n", rekord, pontok);
        fclose(bk);
        if(pontok > rekord)
        {
            remove("rekord.txt");
            bk = fopen("rekord.txt", "wt");
            fprintf(bk,"%i",pontok);
            fclose(bk);
            printf("Gratulalok! Rekordott dontottel!\n");
        }
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
