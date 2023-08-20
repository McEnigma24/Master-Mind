#include <iostream>
#include <string>
#include <windows.h>
#include "headers.h"

using namespace std;

void Proste_Wyswietlanie(int tab[10][4])
{
    int r = 0;
    for(int i=0; i<10; i++)
    {
        cout<<i+1<<" --- ";
        for(int j=0; j<4; j++)
        {
            r = rand()% 6 +1;
            tab[i][j] = r;
            cout<<tab[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
void Gora(int checker)
{
    if(checker == 0) for(int i=0; i<13*4+1; i++) cout<<"x";

    //Feed Back

    if(checker == 0)
    {
        cout<<"   ";
        for(int i=0; i<11; i++) cout<<"x";
        cout<<endl;
    }
    //


    for(int j=0; j<4; j++)
    {
        cout<<"x";
        for(int i=0; i<12; i++) cout<<" ";
    }
    cout<<"x";

    //Feed Back
    cout<<"   x";
    for(int i=0; i<9; i++) cout<<" ";
    cout<<"x"<<endl;
}
void Dol()
{
    for(int j=0; j<4; j++)
    {
        cout<<"x";
        for(int i=0; i<12; i++) cout<<" ";
    }
    cout<<"x";
    cout<<"   x";
    for(int i=0; i<9; i++) cout<<" ";
    cout<<"x"<<endl;



    for(int i=0; i<13*4+1; i++) cout<<"x";
    cout<<"   ";
    for(int i=0; i<11; i++) cout<<"x";
    cout<<endl;
}




void Wyswietl_Plansze(int tab[10][4], int feed_back[10][4])
{
    for(int i=0; i<10; i++) Jedna_Linijka(i, tab, feed_back);
}
void Jedna_Linijka(int j, int tab[10][4], int feed_back[10][4])
{
    Gora(j);
    for(int i=0; i<4; i++)
    {
        cout<<"x";
        switch(tab[j][i])
        {
            case 0:
            {
                for(int x=0; x<12; x++) cout<<" ";
                break;
            }
            case 1:
            {
                cout<<"  czerwony";
                cout<<"  ";
                break;
            }
            case 2:
            {

                cout<<"  zielony";
                cout<<"   ";
                break;
            }
            case 3:
            {

                cout<<"  niebieski";
                cout<<" ";
                break;
            }
            case 4:
            {

                cout<<"   zolty";
                cout<<"    ";
                break;
            }case 5:
            {

                cout<<"   bialy";
                cout<<"    ";
                break;
            }
            case 6:
            {

                cout<<"   czarny";
                cout<<"   ";
                break;
            }
            default:
                {
                    for(int x=0; x<12; x++) cout<<"-";
                    break;
                }
        }
    }
    cout<<"x";

    //Miejsce na feed back

    if(feed_back[j][0] != -69)
    {
        cout<<"   x ";
        for(int i=0; i<4; i++)
        {
            switch(feed_back[j][i])
            {
                case 0:
                {
                    cout<<"  ";
                    break;
                }
                case 1:
                {
                    cout<<"1 ";
                    break;
                }
                case 2:
                {
                    cout<<"2 ";
                    break;
                }
                default:
                {
                    cout<<"- ";
                    break;
                }
            }
        }
        cout<<"x";
    }
    else cout<<"    Nice Cock";


    cout<<endl;
    Dol();
}




void Order_Feed_Back_Tab(int* feed_back_tab)
{
if(feed_back_tab != NULL)
{
    int ile_2 = 0;
    int ile_1 = 0;

    for(int i=0; i<4; i++)
    {
        if(feed_back_tab[i] == 2) ile_2++;
        else if(feed_back_tab[i] == 1) ile_1++;
    }

    for(int i=0; i<4; i++) feed_back_tab[i] = 0;

    int index = 0;

    //cout<<"ile_2: "<<ile_2<<endl;
    //cout<<"ile_1: "<<ile_1<<endl;
    //cout<<endl;

    for(; index<ile_2; index++) feed_back_tab[index] = 2;
    for(int i=0; i<ile_1; i++)
    {
        feed_back_tab[index] = 1;
        index++;
    }
}
else cout<<"Feed back tab == NULL"<<endl;
}
int* Feed_Back_Tab(int user_colors[4], int sekretny_kod[4])
{
    int* feed_back_tab = new int[4];
    for(int i=0; i<4; i++) feed_back_tab[i] = 0;

    int x = 0;
    int ile_razy_wystapil = 0;

    for(int i=0; i<4; i++)
    {
        x = user_colors[i];
        ile_razy_wystapil = 0;

        if(x == sekretny_kod[i]) feed_back_tab[i] = 2;
        else
        {
            for(int j=0; j<4; j++) if(sekretny_kod[j] == x) ile_razy_wystapil++;
            if(ile_razy_wystapil >= 1) feed_back_tab[i] = 1;
        }
    }
    return feed_back_tab;
}



void Top()
{
    //for(int i=0; i<20; i++)cout<<" ";
    //cout<<"Secret Code"<<endl;

    for(int i=0; i<20; i++)cout<<" ";
    cout<<"Secret Code";

    for(int i=0; i<26; i++) cout<<" ";
    cout<<"Feed Back"<<endl;

    int tab[10][4] = {-10, -10 ,-10, -10};

   Jedna_Linijka(0, tab, tab);
   cout<<endl<<endl<<endl;
}

void Winning_Top(int tab[10][4], int feed_back[10][4])
{

    for(int i=0; i<20; i++)cout<<" ";
    cout<<"Secret Code";

    for(int i=0; i<26; i++) cout<<" ";
    cout<<"Feed Back"<<endl;

   Jedna_Linijka(0, tab, feed_back);
   cout<<endl<<endl<<endl;
}

void Winning_Screen_Update(int sekretny_kod[4], int tab[10][4], int feed_back[10][4])
{
    system("cls");

    int fake_tab[10][4] = {0};
    int fake_feed_back[10][4] = {0};

    for(int i=0; i<4; i++)
    {
        fake_tab[0][i] = sekretny_kod[i];
        fake_feed_back[0][i] = -69;
    }

    Winning_Top(fake_tab, fake_feed_back);
    Wyswietl_Plansze(tab, feed_back);
}

void Screen_Update(int tab[10][4], int feed_back[10][4])
{
    system("cls");
    Top();
    Wyswietl_Plansze(tab, feed_back);
}



bool Ask_For_User_Colors_Return_Feed_Back(int sekretny_kod[4], int tab[10][4], int feed_back[10][4], int ktora_runda)
{
if(feed_back != NULL && tab != NULL)
{
    int user_colors[4] = {0};
    cout << endl << "Feedback 1 => correct color, wrong place       Feedback 2 => correct color, correct place" << endl << endl << endl;
    cout<<"Choose your colors     ->  input numbers after space and insert with 'enter'"<<endl;
    cout<<"1. czerwony"<<endl;
    cout<<"2. zielony"<<endl;
    cout<<"3. niebieski"<<endl;
    cout<<"4. zolty"<<endl;
    cout<<"5. bialy"<<endl;
    cout << "6. czarny" << endl << endl;


    for(int i=0; i<4; i++) cin>>user_colors[i]; //dorobic petle co pyta o potwierdzenie kolorow

    cout<<"user colors"<<endl;
    for(int i=0; i<4; i++) cout<<i+1<<". "<<user_colors[i]<<endl;
    cout<<endl<<endl;


    //ustawianie wybranych kolorow to duzej tablicy
    for(int i=0; i<4; i++) tab[ktora_runda][i] = user_colors[i];


    //Feed_Back
    int* feed_back_tab = Feed_Back_Tab(user_colors, sekretny_kod);
    Order_Feed_Back_Tab(feed_back_tab);
    //Ustawianie feed back do duzej tablicy
    for(int i=0; i<4; i++) feed_back[ktora_runda][i] = feed_back_tab[i];


    int did_he_get_it = 0;
    for(int i=0; i<4; i++) if(feed_back_tab[i] == 2) did_he_get_it++;

    if(did_he_get_it == 4) return true;
    else return false;
}
else
{
    cout<<"tab to NULL"<<endl;
    return false;
}
}

bool Czy_Znajduje_Sie_W_Tablicy(int* tab, int dlugosc, int key)
{
    if(tab != NULL && dlugosc > 0)
    {
        for(int i=0; i<dlugosc; i++) if(tab[i] == key) return true;
        return false;
    }
    else
    {
        cout<<"tab to NULL"<<endl;
        return false;
    }
}
bool Czy_Liczby_Powtarzaja_Sie_W_Tablicy(int* tab, int dlugosc)
{
if(tab != NULL)
{
    int actual = 0;
    int limit = 0;

    for(int i=0; i<dlugosc; i++)
    {
        actual = tab[i];
        limit = 0;
        for(int j=0; j<dlugosc; j++)
        {
            if(actual == tab[j]) limit++;
            if(limit > 1) return true;
        }
    }
    return false;
}
else
{
    cout<<"tab to NULL"<<endl;
    return false;
}
}
bool Czy_Dziala()
{
    int sekretny_kod[4] = {0};
    int r = 0;
    int choice = 2;

    for(int i=0; i<4; i++)
    {
        r = rand()% 6 + 1;

        if(choice == 2) while(Czy_Znajduje_Sie_W_Tablicy(sekretny_kod, 4, r)) r = rand()% 6 + 1;
        sekretny_kod[i] = r;
    }

    if(Czy_Liczby_Powtarzaja_Sie_W_Tablicy(sekretny_kod, 4)) return false;
    else return true;
}
void Statystyka_Powtarzalnosci(int ile)
{
    int licznik = 0;
    for(int i=0; i<ile; i++) if(Czy_Dziala() == false) licznik++;
    cout<<"to jest licznik "<<((double)licznik/(double)ile) * 100<<"%"<<endl;
}

void Gra()
{
    int sekretny_kod[4] = {0};
    int r = 0;

    // choosing mode
    int choice = 1;
    do
    {
        cout << "Would you like a code with possibility of repeating colors or with all unique colors?" << endl;
        cout << "1. No Repeating" << endl;
        cout << "2. Repeating" << endl;
        cin >> choice;

        if (!(choice == 1 || choice == 2))
        {
            system("cls");
            cout << "wrong input" << endl;
            Sleep(1000);
        }

    } while (!(choice == 1 || choice == 2));
    system("cls");

    if (choice == 2) choice = 1;
    else if (choice == 1) choice = 2;

    // choosing code generation or user set
    int random_code_or_user_set = 1;
    do
    {
        cout << "Would you like a code with possibility of repeating colors or with all unique colors?" << endl;
        cout << "1. Random -> computer genereted" << endl;
        cout << "2. User set -> after choosing this you will insert your code" << endl;
        cin >> random_code_or_user_set;

        if (!(random_code_or_user_set == 1 || random_code_or_user_set == 2))
        {
            system("cls");
            cout << "wrong input" << endl;
            Sleep(1000);
        }

    } while (!(random_code_or_user_set == 1 || random_code_or_user_set == 2));

    // seting up the code
    if (random_code_or_user_set == 1)
    {
        for (int i = 0; i < 4; i++)
        {
            r = rand() % 6 + 1;

            if (choice == 2) while (Czy_Znajduje_Sie_W_Tablicy(sekretny_kod, 4, r)) r = rand() % 6 + 1;
            sekretny_kod[i] = r;
        }
    }
    else if (random_code_or_user_set == 2)
    {
        string set_code = "";
        int one_color;

        for (int i = 0; i < 4; i++)
        {
            do
            {
                system("cls");
                cout << "Ready to input code  ->  insert one by one\n\n";
                cout << "czerwony = 1\n";
                cout << "zielony = 2\n";
                cout << "niebieski = 3\n";
                cout << "zolty = 4\n";
                cout << "bialy = 5\n";
                cout << "black = 6\n\n";
                cout << "code -> " + set_code;            
          
                cin >> one_color;

                if (!(1 <= one_color && one_color <= 6))
                {
                    system("cls");
                    cout << "wrong input" << endl;
                    Sleep(1000);
                }

            } while (!(1 <= one_color && one_color <= 6));

            // z powtórzeniami
            if (choice == 1)
            {
                sekretny_kod[i] = one_color;
                set_code += to_string(one_color) + " ";
            }
            // bez powtórzeñ
            else if (choice == 2)
            {
                if (Czy_Znajduje_Sie_W_Tablicy(sekretny_kod, 4, one_color))
                {
                    system("cls");
                    cout << "color already in code" << endl;
                    Sleep(1000);

                    i--;
                    continue;
                }
                else
                {
                    sekretny_kod[i] = one_color;
                    set_code += to_string(one_color) + " ";
                }
            }
        }
    }

    system("cls");
    cout<<"ok"<<endl;
    Sleep(1000);
    system("cls");
    cout<<"Let's play   --->    input numbers after space and insert with 'enter'"<<endl;
    Sleep(2500);
    system("cls");


    int tab[10][4] = {0};
    int feed_back[10][4] = {0};


    for(int j=9; j>=0; j--)
    {
        Screen_Update(tab, feed_back);        
        if(Ask_For_User_Colors_Return_Feed_Back(sekretny_kod, tab, feed_back, j))
        {
            Winning_Screen_Update(sekretny_kod, tab, feed_back);
            cout<<endl<<endl<<"Brawo udalo ci sie"<<endl;
            Sleep(5000);
            cout<<endl<<"Koniec Gry"<<endl;
            Sleep(1000);
            break;
        }
        else Screen_Update(tab, feed_back);
    }
}