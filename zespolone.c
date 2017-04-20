#include<stdio.h>
#include<math.h>

struct zespolona
    {
    float re;
    float im;
    };

struct zespolona dodawanie_zespolonej(struct zespolona z1, struct zespolona z2)
    {
    struct zespolona z3;

    z3.re=z1.re+z2.re;
    z3.im=z1.im+z2.im;

    return z3;
    }

struct zespolona mnozenie_zespolonej(struct zespolona z1, struct zespolona z2)
    {
    struct zespolona z3;

    z3.re=z1.re*z2.re-z1.im*z2.im;
    z3.im=z1.im*z2.re+z1.re*z2.im;

    return z3;
    }

float modul_zespolonej(struct zespolona z1)
    {
    float m;

    m=sqrt(z1.re*z1.re+z1.im*z1.im);

    return m;
    }

struct zespolona sprzezenie_zespolonej(struct zespolona z)
    {
    struct zespolona z2;

    z2.re=z.re;
    z2.im=-z.im;

    return z2;
    }

struct zespolona odejmowanie_zespolonej(struct zespolona z1, struct zespolona z2)
    {
    struct zespolona z3;

    z3.re=z1.re-z2.re;
    z3.im=z1.im-z2.im;

    return z3;
    }

struct zespolona dzielenie_zespolonej(struct zespolona z1, struct zespolona z2)
    {
    struct zespolona z3, z4;

    if(modul_zespolonej(z2)==0)
        {
        z3.re=0;
        z3.im=0;
        return z3;
        }

    z4.re=z2.re/(modul_zespolonej(z2)*modul_zespolonej(z2));
    z4.im=-z2.im/(modul_zespolonej(z2)*modul_zespolonej(z2));
    z3=mnozenie_zespolonej(z1, z4);
    return z3;
    };

void wyswietl_zespolona(struct zespolona z)
    {
    printf("%f+%fi", z.re, z.im);

    return;
    }

int main()
    {
    struct zespolona z1, z2, dod, mno, dzie, sprz1, sprz2, odej;
    float mod1,mod2;

    printf("wprowadz zespolona z1:\nre=");
    scanf("%f", &z1.re);
    printf("im=");
    scanf("%f", &z1.im);
    printf("\nwprowadz zespolona z2:\nre=");
    scanf("%f", &z2.re);
    printf("im=");
    scanf("%f", &z2.im);

    dod=dodawanie_zespolonej(z1, z2);
    mno=mnozenie_zespolonej(z1,z2);
    dzie=dzielenie_zespolonej(z1,z2);
    sprz1=sprzezenie_zespolonej(z1);
    sprz2=sprzezenie_zespolonej(z2);
    odej=odejmowanie_zespolonej(z1,z2);
    mod1=modul_zespolonej(z1);
    mod2=modul_zespolonej(z2);

    printf("dodawanie=");
    wyswietl_zespolona(dod);
    printf("\nmnozenie=");
    wyswietl_zespolona(mno);
    if(mod2!=0)
        {
        printf("\ndzielenie=");
        wyswietl_zespolona(dzie);
        }
    else
        printf("\ndzielenie=blad 0 w mianowniku");

    printf("\nsprzezenie1=");
    wyswietl_zespolona(sprz1);
    printf("\nsprzezenie2=");
    wyswietl_zespolona(sprz2);
    printf("\nodejmowanie=");
    wyswietl_zespolona(odej);
    printf("\nmodul1=%f", mod1);
    printf("\nmodul2=%f", mod2);

    return 0;
    }

