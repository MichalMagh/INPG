#include<stdio.h>
#include<stdlib.h>
#define R 40


typedef struct wpis
    {
    char imie[R];
    char nazwisko[R];
    long nr;
    } wpis;

void wyswietl_wpis(wpis* tab)
    {
    puts(tab[0].nazwisko);
    puts(tab[0].imie);
    printf("\n%i\n", tab[0].nr);

    return;
    }

wpis* dodaj_wpis(wpis* tab, int rozmiar)
    {
    int i;
    wpis* tabp;

    tabp=malloc((rozmiar+1)*sizeof(wpis));
    if(tabp==NULL)
        return NULL;

    if((tab!=NULL) || (rozmiar!=0))
        {
        for(i=0;i<rozmiar;i++)
            tabp[i]=tab[i];

        free(tab);
        }

    printf("wprowadz nazwisko, imie i numer \n");
    fgets(tabp[rozmiar].nazwisko,R,stdin);
    fgets(tabp[rozmiar].imie,R,stdin);
    scanf("%i",&(tabp[rozmiar].nr));

    printf("dodano wpis\n");

    return tabp;
    }

int znajdz_wpis(wpis* tab, int rozmiar)
    {
    int i;
    long num;

    if(tab==NULL || rozmiar==0)
        return -1;

    printf("podaj numer tel. szukanego wpisu:\n");
    scanf("%i", &num);

    for(i=0;i<rozmiar;i++)
        {
        if(tab[i].nr==num)
            {
            printf("znaleziono wpis\n");

            return i;
            }
        }
    printf("nie znaleziono\n");

    return -1;
    }

wpis* usun_wpis(wpis* tab, int index, int rozmiar)
    {
    wpis* tabp;
    int i;

    if(index>rozmiar)
        return tab;

    tabp=malloc((rozmiar-1)*sizeof(wpis));
    if(tabp==NULL)
        return NULL;

    for(i=0;i<rozmiar;i++)
        {

        if(i=index)
            {
            i++;

            tabp[i-1]=tab[i];
            continue;
            }
        else if(i>index)
            {
            tabp[i-1]=tab[i];
            }
        else
            {
            tabp[i]=tab[i];
            }
        }
    free(tab);

    printf("usunieto wpis\n");

    return tabp;
    }

int main()
    {
    wpis *ksiazka;
    int d=0, p;

    ksiazka=NULL;

    ksiazka=dodaj_wpis(ksiazka, d);



    p=znajdz_wpis(ksiazka, d+1);

    wyswietl_wpis(ksiazka+p);

    ksiazka=usun_wpis(ksiazka, p, d+1);

    free(ksiazka);

    return 0;
    }

