#include <stdio.h>

char plansza[3][3];

void ustawienie_pustych_pol();

void wyswietlanie_planszy();

void wyswietlenie_planszy_pomoc();

void ruch_gracza_pierwszego();

void ruch_gracza_drugiego();

char sprawdzenie_wygranej();

int main() {
    printf("Gra w kolko i krzyzyk\nA=wiersz B=kolumna np. (1 1)\n\n");
    ustawienie_pustych_pol();
    wyswietlenie_planszy_pomoc();

    char sprawdzenie;
    for(int i=0; i<5; i++)
    {
        wyswietlanie_planszy();
        ruch_gracza_pierwszego();
        sprawdzenie = sprawdzenie_wygranej();
        if(sprawdzenie != ' ')
        {
            break;
        }
        else if(i==4)
        {
            printf("Remis sprobujcie jeszcze raz\n");
            break;
        }
        wyswietlanie_planszy();
        ruch_gracza_drugiego();
        sprawdzenie = sprawdzenie_wygranej();
        if(sprawdzenie != ' ')
        {
            break;
        }
    }

    wyswietlanie_planszy();
    if (sprawdzenie == 'X')
    {
        printf("Wygral gracz 1\n");
    }
    else if (sprawdzenie == 'O')
    {
        printf("Wygral gracz 2\n");
    }
    return 0;
}

void ustawienie_pustych_pol() {
    int x, y;
    for (x = 0; x < 3; x++)
    {
        for (y = 0; y < 3; y++)
        {
            plansza[x][y] = ' ';
        }
    }
}

void wyswietlenie_planszy_pomoc(){
    printf("1    |   |     ");
    printf("\n  ---|---|---\n");
    printf("2    |   |     ");
    printf("\n  ---|---|---\n");
    printf("3    |   |     \n");
    printf("   1   2   3  ");
    printf("\n\n\n");
}

void wyswietlanie_planszy() {
    printf(" %c | %c | %c  ", plansza[0][0],plansza[0][1], plansza[0][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c  ", plansza[1][0],plansza[1][1], plansza[1][2]);
    printf("\n---|---|---\n");
    printf(" %c | %c | %c  ", plansza[2][0],plansza[2][1], plansza[2][2]);
    printf("\n");
}

void ruch_gracza_pierwszego() {
    int a;
    int b;
    printf("[Gracz 1] Podaj swoj ruch A B: ");
    scanf("%d %d", &a, &b);
    printf("\n");
    a=a-1;
    b=b-1;
    if (plansza[a][b] != ' ') {
        printf("Nieprawidlowy ruch, musisz wykonac go jeszcze raz\n");
        ruch_gracza_pierwszego();
    }
    else
    {
        plansza[a][b] = 'X';
    }
}

void ruch_gracza_drugiego() {
    int a;
    int b;
    printf("[Gracz 2] Podaj swoj ruch A B: ");
    scanf("%d %d", &a, &b);
    printf("\n");
    a=a-1;
    b=b-1;
    if (plansza[a][b] != ' ')
    {
        printf("Nieprawidlowy ruch, musisz wykonac go jeszcze raz\n");
        ruch_gracza_drugiego();
    }
    else
    {
        plansza[a][b] = 'O';
    }
}

char sprawdzenie_wygranej() {
    // sprawdzenie pionu
    if (plansza[0][0] == plansza[1][0] && plansza[0][0] == plansza[2][0])
    {
        return plansza[0][0];
    }
    if (plansza[0][1] == plansza[1][1] && plansza[0][1] == plansza[2][1])
    {
        return plansza[1][1];
    }
    if (plansza[0][2] == plansza[1][2] && plansza[0][2] == plansza[2][2])
    {
        return plansza[2][2];
    }


    // sprawdzenie poziomu

    if (plansza[0][0] == plansza[0][1] && plansza[0][0] == plansza[0][2])
    {
        return plansza[0][0];
    }

    if (plansza[1][0] == plansza[1][1] && plansza[1][0] == plansza[1][2])
    {
        return plansza[1][1];
    }

    if (plansza[2][0] == plansza[2][1] && plansza[2][0] == plansza[2][2])
    {
        return plansza[2][2];
    }

    // sprawdzenie przekatnej
    if(plansza[0][0]==plansza[1][1] && plansza[1][1]==plansza[2][2])
    {
        return plansza[1][1];
    }

    if(plansza[0][2]==plansza[1][1] && plansza[1][1]==plansza[2][0])
    {
        return plansza[1][1];
    }
    return ' ';
}