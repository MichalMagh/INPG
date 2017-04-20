#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define R 14
#define P 12
#define N 10
eststety
int number_of_entries;

typedef struct tree tree;

struct tree
    {
    char surname[R];
    char name[R];
    char PESEL[P];
    char nr1[N];
    char nr2[N];
    tree* left;
    tree* right;
    };

tree* create(void)                                          /*stworz strukture*/
    {
    tree* p;
    p=(tree*)malloc(sizeof(tree));
    p->left=NULL;
    p->right=NULL;
    return p;
    }

void delete_one(tree** p)                                   /*uson jedna struktura*/
    {
    free(*p);
    p=NULL;
    }

void print_elem_of_tree(tree elem)                         /*wypisuje element drzewa*/
    {
    int i,x;

    printf(" ");
    for(i=0, x=0; i<R;++i)
        {
        if((elem.surname)[i]!='\0' && (elem.surname)[i]!='\n' && x==0)
            printf("%c",(elem.surname)[i]);
         else
            {
            printf(" ");
            x=1;
            }
        }

    printf(" ");
    for(i=0, x=0; i<R;++i)
        {
        if((elem.name)[i]!='\0' && (elem.name)[i]!='\n' && x==0)
            printf("%c",(elem.name)[i]);
         else
            {
            printf(" ");
            x=1;
            }
        }

    printf(" ");
    for(i=0, x=0; i<P;++i)
        {
        if((elem.PESEL)[i]!='\0' && (elem.PESEL)[i]!='\n' && x==0)
            printf("%c",(elem.PESEL)[i]);
         else
            {
            printf(" ");
            x=1;
            }
        }

    printf(" ");
    for(i=0, x=0; i<N;++i)
        {
        if((elem.nr1)[i]!='\0' && (elem.nr1)[i]!='\n' && x==0)
            printf("%c",(elem.nr1)[i]);
        else
            {
            printf(" ");
            x=1;
            }
        }

    printf(" ");
    for(i=0, x=0; i<N;++i)
        {
        if((elem.nr2)[i]!='\0' && (elem.nr2)[i]!='\n' && x==0)
            printf("%c",(elem.nr2)[i]);
         else
            {
            printf(" ");
            x=1;
            }
        }

    printf("\n");
    }

void PreOrder_show_all(tree* t)                             /*wypisuje wszystkie rekordy danych*/
    {
    if(t==NULL)
        return;

    PreOrder_show_all((*t).left);

    print_elem_of_tree(*t);

    PreOrder_show_all((*t).right);
    }

void INSERT(tree** t, tree** n)                             /*dodaj rekord*/
    {
    int x;
    tree* helper;
    helper=*t;

    if(*t==NULL)                                            /*dodaj na poczatek*/
        {
        *t=*n;
        *n=NULL;
        ++number_of_entries;
        return;
        }

    while(helper!=NULL)
        {
        x=strcmp((*n)->surname,helper->surname);

        if(x<0)                                             /*idz na lewo*/
            {
            if(helper->left==NULL)
                {
                helper->left=*n;
                *n=NULL;
                ++number_of_entries;

                return;
                }

            helper=helper->left;
            }
        else if(x>0)                                         /*idz na prawo*/
            {
            if(helper->right==NULL)
                {
                helper->right=*n;
                *n=NULL;
                ++number_of_entries;

                return;
                }

            helper=helper->right;
            }
        else
            {
            x=strcmp((*n)->name,helper->name);

            if(x<0)                                             /*idz na lewo*/
                {
                if(helper->left==NULL)
                    {
                    helper->left=*n;
                    *n=NULL;
                    ++number_of_entries;

                    return;
                    }

                helper=helper->left;
                }
            else if(x>0)                                             /*idz na prawo*/
                {
                if(helper->right==NULL)
                    {
                    helper->right=*n;
                    *n=NULL;
                    ++number_of_entries;

                    return;
                    }

                helper=helper->right;
                }
            else
                {
                x=strcmp((*n)->PESEL,helper->PESEL);

                if(x<0)                                             /*idz na lewo*/
                    {
                    if(helper->left==NULL)
                        {
                        helper->left=*n;
                        *n=NULL;
                        ++number_of_entries;

                        return;
                        }

                    helper=helper->left;
                    }
                else if(x>0)                                         /*idz na lewo*/
                    {
                    if(helper->right==NULL)
                        {
                        helper->right=*n;
                        *n=NULL;
                        ++number_of_entries;

                        return;
                        }

                    helper=helper->right;
                    }
                else                                                /*aktualizuj nr1 i nr2*/
                    break;
                }
            }
        }

    if(helper!=NULL)
        {
        for(x=0;x<N && ((*n)->nr1)[x]!='\0';++x)
            (helper->nr1)[x]=((*n)->nr1)[x];

        for(x=0;x<N && ((*n)->nr2)[x]!='\0';++x)
            (helper->nr2)[x]=((*n)->nr2)[x];

        delete_one(n);
        }
    }

void cut_endline(tree* one)                                 /*ucina znak nowej linii*/
    {
    int i;

    for(i=0;(one->surname)[i]!='\0';++i)
        if((one->surname[i])=='\n')
            {
            (one->surname[i])='\0';
            break;
            }

    for(i=0;(one->name)[i]!='\0';++i)
        if((one->name[i])=='\n')
            {
            (one->name[i])='\0';
            break;
            }

    for(i=0;(one->PESEL)[i]!='\0';++i)
        if((one->PESEL[i])=='\n')
            {
            (one->PESEL[i])='\0';
            break;
            }

    for(i=0;(one->nr1)[i]!='\0';++i)
        if((one->nr1[i])=='\n')
            {
            (one->nr1[i])='\0';
            break;
            }

    for(i=0;(one->nr2)[i]!='\0';++i)
        if((one->nr2[i])=='\n')
            {
            (one->nr2[i])='\0';
            break;
            }

    }

void enter_data(tree* one)                                  /*wprowadzanie danych*/
    {
    char c;
    int i;
    if(one==NULL)
        {
        printf("blad tworzenia struktury");
        return;
        }

    for(i=0;i<R;++i)                                                                     /*wypełnij tablice zerami*/
            {
            if(i<N)
                {
                one->surname[R]='\0';
                one->name[R]='\0';
                one->PESEL[P]='\0';
                one->nr1[N]='\0';
                one->nr2[N]='\0';
                continue;
                }
            else if(i<P)
                {
                one->surname[R]='\0';
                one->name[R]='\0';
                one->PESEL[P]='\0';
                continue;
                }
            else
                {
                one->surname[R]='\0';
                one->name[R]='\0';
                }
            }

    while((c = getchar()) != '\n' && c != '\0');

    printf("nazwisko: ");
    fgets(one->surname,R,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    printf("imie    : ");
    fgets(one->name,R,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    printf("PESEL   : ");
    fgets(one->PESEL,P,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    printf("nr1     : ");
    fgets(one->nr1,N,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    printf("nr2     : ");
    fgets(one->nr2,N,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    cut_endline(one);
    }

void copy_elem(tree* to, tree* from)                        /*kopiowanie struktury from do to*/
    {
    int i;

    for(i=0; i<R && (from->surname)[i]!='\0';++i)
        (to->surname)[i]=(from->surname)[i];

    for(i=0; i<R && (from->name)[i]!='\0';++i)
        (to->name)[i]=(from->name)[i];

    for(i=0; i<P && (from->PESEL)[i]!='\0';++i)
        (to->PESEL)[i]=(from->PESEL)[i];

    for(i=0; i<N && (from->nr1)[i]!='\0';++i)
        (to->nr1)[i]=(from->nr1)[i];

    for(i=0; i<N && (from->nr2)[i]!='\0';++i)
        (to->nr2)[i]=(from->nr2)[i];

    to->left=from->left;
    to->right=from->right;
    }

tree* InOrder_serch(tree* t, tree serch)                    /*zwraca wsk. na dany rekord -wyszukiwanie po imieniu i nazwisku i PESEL-u*/
    {
    tree* helper=NULL;

    if(t==NULL)
        return NULL;

    if(((strcmp(t->surname,serch.surname))==0 && (strcmp(t->name,serch.name))==0) || (strcmp(t->PESEL,serch.PESEL))==0)
        return t;

    helper=InOrder_serch(t->left,serch);

    if(helper!=NULL)
        return helper;

    helper=InOrder_serch(t->right,serch);

    return helper;
    }

tree* serch_minimum(tree* t)                                /* zwraca wsk. na minimum, czyli alfabetycznie pierwszy*/
    {
    tree* helper;

    if(t==NULL)
        return NULL;

    if((*t).left==NULL)
        return t;

    helper=serch_minimum((*t).left);

    return helper;
    }

tree* serch_maximum(tree* t)                                /* zwraca wsk. na maximum, czyli alfabetycznie ostatni*/
    {
    tree* helper;

    if(t==NULL)
        return NULL;

    if((*t).right==NULL)
        return t;

    helper=serch_maximum(t->right);

    return helper;
    }

void InOrder(tree*t)                                        /* wyswietla drzewo inOrder*/
    {
    if(t==NULL)
        return;

    print_elem_of_tree(*t);
    InOrder((*t).left);
    InOrder((*t).right);
    }

int Number_of_nodes(tree* t)                               /*zwraca licze wezlow*/
    {
    int i=0;

    if(t==NULL)
        return i;

    if((*t).left!=NULL || (*t).right!=NULL)
        ++i;

    i+=Number_of_nodes((*t).left);
    i+=Number_of_nodes((*t).right);

    return i;
    }

int hight_of_tree(tree* t)                                  /*zwraca wysokosc drzewa*/
    {
    int i=0, x, y;

    if(t==NULL)
        return i;

    //if((*t).left!=NULL || (*t).right!=NULL)
        ++i;

    x=hight_of_tree((*t).left);
    y=hight_of_tree((*t).right);

    if(x<y)
        i+=y;
    else
        i+=x;

    return i;
    }

void surname_name_PESEL(tree* serched)                      /*wprowadzanie danych do szukania*/
    {
    char c;
    int i;

    for(i=0;i<R;++i)                                                                     /*wypełnij tablice zerami*/
            {
            if(i<P)
                {
                serched->surname[R]='\0';
                serched->name[R]='\0';
                serched->PESEL[P]='\0';
                continue;
                }
            else
                {
                serched->surname[R]='\0';
                serched->name[R]='\0';
                }
            }

    printf("podaj (nazwisko i imie) lub PESEL\n");
    while((c = getchar()) != '\n' && c != EOF);

    printf("nazwisko: ");
    fgets(serched->surname,R,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    printf("imie    : ");
    fgets(serched->name,R,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    printf("PESEL   : ");
    fgets(serched->PESEL,P,stdin);
    while((c = getchar()) != '\n' && c != EOF);

    cut_endline(serched);
    }

int menu(tree** t,tree** helper)                            /*menu*/
    {
    int x;
    tree *serched;
    printf("Aktualna liczba wpisow: %i\nWybierz co chcesz zrobic:\n1-dodaj wpis \n2-wypisz element \n3-wypisz wszystko alfabetycznie \n4-wyswietl pierwszy alfabetycznie \n5-wyswietl ostatni alfabetycznie \n6-wyswietl calosc InOrder \n7-liczba wezlow i wysokosc drzewa \n8-wyjscie \n", number_of_entries);
    scanf("%i",&x);

    switch(x)
        {
        case 1:
            {
            *helper=create();
            enter_data(*helper);
            INSERT(t,helper);
            break;
            }
        case 2:
            {
            serched=create();
            surname_name_PESEL(serched);
            *helper=InOrder_serch(*t,*serched);
            delete_one(&serched);
            if(*helper==NULL)
                {
                printf("NIE ZNALEZIONO\n");
                return 1;
                }
            print_elem_of_tree(**helper);
            break;
            }
        case 3:
            {
            PreOrder_show_all(*t);
            break;
            }
        case 4:
            {
            print_elem_of_tree(*(serch_minimum(*t)));
            break;
            }
        case 5:
            {
            print_elem_of_tree(*(serch_maximum(*t)));
            break;
            }
        case 6:
            {
            InOrder(*t);
            break;
            }
        case 7:
            {
            printf("liczba wezlow  :%i\nwysokosc drzewa:%i\n",Number_of_nodes(*t),hight_of_tree(*t));
            break;
            }
        case 8:
            {
            return 0;
            break;
            }
        default:
            {
            return 1;
            }
        }

    return 1;
    }

void delete_tree(tree** t)                                  /*usowa cale drzewo*/
    {
    if(*t==NULL)
        return;

    delete_tree(&((*t)->left));
    delete_tree(&((*t)->right));
    delete_one(t);
    *t=NULL;
    }

void load_from_file(char** file_name, tree** t, int argc)                 /*wczzyruje dane z pliku*/
    {
    FILE* inout=fopen(file_name[argc], "r");
    tree* h;
    char x;
    int i,j;

    if(inout==NULL)
        {
        printf("blad otwierania pliku");
        return ;
        }

    x=getc(inout);

    while(x!=EOF)
        {
        h=create();
        if(h==NULL)
            break;



        for(i=0;i<R;++i)                                                                     /*wypełnij tablice zerami*/
            {
            if(i<N)
                {
                h->surname[R]='\0';
                h->name[R]='\0';
                h->PESEL[P]='\0';
                h->nr1[N]='\0';
                h->nr2[N]='\0';
                continue;
                }
            else if(i<P)
                {
                h->surname[R]='\0';
                h->name[R]='\0';
                h->PESEL[P]='\0';
                continue;
                }
            else
                {
                h->surname[R]='\0';
                h->name[R]='\0';
                }
            }

        (h->surname)[0]=x;
        printf("%c",x);

        for(i=1, j=0;i<R && (x=getc(inout))!='\n' && x!=EOF && x!='\0';++i)                        /*nazwisko*/
            if(((x<91 && x>64) || (x<123 && x>96) || x==45) && j<R)
                {
                (h->surname)[j]=x;
                printf("%c",x);
                ++j;
                }

        if(x==EOF)
            {
            delete_one(&h);
            break;
            }

        for(i=0, j=0;i<R && (x=getc(inout))!='\n' && x!=EOF && x!='\0';++i)                        /*nazwisko*/
            if(((x<91 && x>64) || (x<123 && x>96) || x==45) && j<R)
                {
                (h->name)[j]=x;
                printf("%c",x);
                ++j;
                }

        if(x==EOF)
            {
            delete_one(&h);
            break;
            }

        for(i=0, j=0;i<R && (x=getc(inout))!='\n' && x!=EOF && x!='\0';++i)                        /*nazwisko*/
            if(x>47 && x<58 && j<P)
                {
                (h->PESEL)[j]=x;
                printf("%c",x);
                ++j;
                }

        if(x==EOF)
            {
            delete_one(&h);
            break;
            }

        for(i=0, j=0;i<R && (x=getc(inout))!='\n' && x!=EOF && x!='\0';++i)                        /*nazwisko*/
            if(x>47 && x<58 && j<N)
                {
                (h->nr1)[j]=x;
                printf("%c",x);
                ++j;
                }

        if(x==EOF)
            {
            delete_one(&h);
            break;
            }

        for(i=0, j=0;i<R && (x=getc(inout))!='\n' && x!=EOF && x!='\0';++i)                        /*nazwisko*/
            if(x>47 && x<58 && j<N)
                {
                (h->nr2)[j]=x;
                printf("%c",x);
                ++j;
                }

        INSERT(t,&h);
        }

    fclose(inout);
    }

void copy_to_file(FILE* inout, tree** t)                                    /*zapis do pliku InOrder*/
    {
    int i;

    if(inout==NULL)
        {
        printf("blad otwierania pliku");
        return;
        }

    if(*t==NULL)
        return;

    fprintf(inout,"\n");
    for(i=0;i<R && ((*t)->surname)[i]!='\0';++i)
        fprintf(inout,"%c",((*t)->surname)[i]);
    fprintf(inout,"\n");
    for(i=0;i<R && ((*t)->name)[i]!='\0';++i)
        fprintf(inout,"%c",((*t)->name)[i]);
    fprintf(inout,"\n");
    for(i=0;i<P && ((*t)->PESEL)[i]!='\0';++i)
        fprintf(inout,"%c",((*t)->PESEL)[i]);
    fprintf(inout,"\n");
    for(i=0;i<N && ((*t)->nr1)[i]!='\0';++i)
        fprintf(inout,"%c",((*t)->nr1)[i]);
    fprintf(inout,"\n");
    for(i=0;i<N && ((*t)->nr2)[i]!='\0';++i)
        fprintf(inout,"%c",((*t)->nr2)[i]);

    copy_to_file(inout,&((*t)->left));
    copy_to_file(inout,&((*t)->right));

    }

int main(int argc, char** argv)// edit inpg
    {
    number_of_entries=0;
    FILE* inout;
    tree* h=NULL, *t=NULL;

    load_from_file(argv,&t,1);

    while(menu(&t,&h));

    inout=fopen(argv[1],"w");// inpg
    if(inout!=NULL)
        fclose(inout);

    inout=fopen(argv[1],"w+");
    copy_to_file(inout,&t);
    delete_tree(&t);

    if(inout!=NULL)
        fclose(inout);

    return 0;
    }


