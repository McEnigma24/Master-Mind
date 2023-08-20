#include <iostream>
#include <windows.h>

using namespace std;

class pionek
{
public:
    string kolor;
public:

    pionek(int wybor)
    {
        switch(wybor)
        {
        case 1:
            {
                kolor = "czerwony";
                //kolor = "red";
                break;
            }
        case 2:
            {
                kolor = "zielony";
                //kolor = "green";
                break;
            }
        case 3:
            {
                kolor = "niebieski";
                //kolor = "blue";
                break;
            }
        case 4:
            {
                kolor = "zolty";
                //kolor = "yellow";
                break;
            }
        case 5:
            {
                kolor = "bialy";
                //kolor = "white";
                break;
            }
        case 6:
            {
                //kolor = "czarny";
                kolor = "black";
                break;
            }
        default:
            {
                kolor = "blad";
                //kolor = "error";
                break;
            }
        }
    }
};

void Wyswietl_Plansze(int tab[10][4], int feed_back[10][4]);
void Jedna_Linijka(int j, int tab[10][4], int feed_back[10][4]);
bool Czy_Znajduje_Sie_W_Tablicy(int* tab, int dlugosc, int key);
bool Czy_Liczby_Powtarzaja_Sie_W_Tablicy(int* tab, int dlugosc);
void Gora(int checker);
void Dol();
void Gra();
bool Czy_Dziala();
void Statystyka_Powtarzalnosci(int ile);
void Proste_Wyswietlanie(int tab[10][4]);
void Top();
bool Ask_For_User_Colors_Return_Feed_Back(int sekretny_kod[4], int tab[10][4], int feed_back[10][4], int ktora_runda);
int* Feed_Back_Tab(int user_colors[4], int sekretny_kod[4]);
void Order_Feed_Back_Tab(int* feed_back_tab);
void Screen_Update(int tab[10][4], int feed_back[10][4]);