#ifndef AKASZTOFA_H_INCLUDED
#define AKASZTOFA_H_INCLUDED

#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#define WIN32_LEAN_AND_MEAN

#include <stdio.h>
#include <stdbool.h>


///egy szo beolvasas egy random sorbol
void beolvas(char *fajlNev, char szo[]);
///a rejtett szo kiirasa es a probalkozasok feldolgozasa, a pontok szamat teriti vissza
int kiir_es_feldolgoz(char *fajlNev, int lehetoseg);
//char beolvas_karakter();
//void kirajzol(int hiba);
///a probalkozasok feldolgozasa ket jatekos eseten, az egyik jatekos pontjat teriti vissza
int ket_jatekos(char szo[]);
///a pontok feldolgozasa illeteve a jatek ismetlese amennyiben a jatekos azt szeretne
void ismetles();
///a 3 lehetoseg kozul visszateriti azt, amit a jatekos valasztott
char jatek_tipusa();
///itt hivodnak meg a valasznak megfelelo fuggvenyek, szinten a pontokat teriti vissza
int jatek(char valasz);
///egy jatekos eseten segit kitalalni egy karaktert amikor a lehetosegek szama a felere csokken
void segitseg(char szo[], char megfejtes[]);



#endif // AKASZTOFA_H_INCLUDED
