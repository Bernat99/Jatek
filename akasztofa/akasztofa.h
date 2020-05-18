#ifndef AKASZTOFA_H_INCLUDED
#define AKASZTOFA_H_INCLUDED

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdbool.h>


///egy szo beolvasas egy random sorbol
void beolvas(char *fajlNev, char szo[]);
int kiir_es_feldolgoz(char *fajlNev, int lehetoseg);
char beolvas_karakter();
void kirajzol(int hiba);
int ket_jatekos(char szo[]);
void ismetles();
char jatek_tipusa();
int jatek(char valasz);
void segitseg(char szo[], char megfejtes[]);



#endif // AKASZTOFA_H_INCLUDED
