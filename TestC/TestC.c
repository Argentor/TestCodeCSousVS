#include <stdio.h>
#include <stdlib.h>

static int FctAddition(int nombre1, int nombre2)
{
    return (nombre1 + nombre2);
}

int main()
{
    // Uniquement pour test GIT
    printf("-----------  Test 6 -----------\n");

    printf("---------------------------------------------------------------------\n");
    printf("Tableau \n");

    char chat[] = "miaou";
    printf("Nom du chat: %s\n", chat);

    const char* chien = "warffff";
    printf("Nom du chien %s\n", chien);

    printf("---------------------------------------------------------------------\n");
    printf("Declaration d'une structure avec nom de type de structure en 2 temps\n");
    struct TypePoint
    {
        int X;
        int Y;
    };
    struct TypePoint Point1, Point2;

    Point1.X = 12;
    Point1.Y = 24;
    Point2.X = 7;
    Point2.Y = 15;
    printf("Point1 = %d,%d, Point2 = %d,%d \n", Point1.X, Point1.Y, Point2.X, Point2.Y);

    printf("---------------------------------------------------------------------\n");
    printf("Declaration d'une structure avec nom de type de structure (optionnel) et instance immediate\n");
    struct TypePointb               // type TypePointb optionnelle pour Point1b, Point2b
    {
        int X;
        int Y;
    } Point1b, Point2b;             // instantiation immediate
    struct TypePointb Point3b;      // instantiation par emploi du nom de type de structure

    Point1b.X = 12;
    Point1b.Y = 24;
    Point2b.X = 7;
    Point2b.Y = 15;
    Point3b.X = 55;
    Point3b.Y = 17;
    printf("Point1b = %d,%d, Point2b = %d,%d, Point3b = %d,%d \n", Point1b.X, Point1b.Y, Point2b.X, Point2b.Y, Point3b.X, Point3b.Y);

    printf("---------------------------------------------------------------------\n");
    printf("Declaration structure avec typedef \n");
    typedef struct
    {
        int X;
        int Y;
    } TypePointc;

    TypePointc Point1c;      // instantiation par type de structure sans besoin de struct

    Point1c.X = 12;
    Point1c.Y = 24;
    printf("Point1c = %d,%d \n", Point1c.X, Point1c.Y);

    printf("---------------------------------------------------------------------\n");
    printf("Initialiser une structure a la declaration \n");

    struct date
    {
        int jour, mois, annee;
    };

    struct time
    {
        int heure, minute, seconde;
    };

    struct DateNaissance
    {
        char Nom[20];
        struct date date;
        struct time time;
    };

    struct DateNaissance m1 = { "Albert",6,2,1967,18,35 };
    printf("Init par liste              %s  %02d/%02d/%04d  %02u:%02u  \n", m1.Nom, m1.date.jour, m1.date.mois, m1.date.annee, m1.time.heure, m1.time.minute);

    struct DateNaissance m2 = { "Albert",{6,2,1967}, {18,35} };
    printf("Init detaille par structure %s  %02d/%02d/%04d  %02u:%02u  \n", m2.Nom, m2.date.jour, m2.date.mois, m2.date.annee, m2.time.heure, m2.time.minute);

    printf("---------------------------------------------------------------------\n");
    printf("Pointeurs\n");

    int i = 23;
    int* ptr;

    ptr = &i;
    printf("%d\n", *ptr);

    *ptr = 55;
    printf("%d\n", i);

    i = 777;
    printf("%d.\n", *ptr);

    char c = 'a';
    int d = 12;
    int j = 4567;
    struct
    {
        int x, y;
        float dx, dy;
    }s1;

    s1.x = 6;
    s1.y = 9;

    s1.dx = (float)7.77;
    s1.dy = (float)9.97;

    printf("c = %d,\t\t     l'adresse de c est :\t%p\n", c, &c);
    printf("d = %d,\t\t     l'adresse de d est :\t%p\n", d, &d);
    printf("j = %d,\t     l'adresse de j est :\t%p\n", j, &j);
    printf("s1.x = %d,\t  l'adresse de s1.x est :\t%p\n", s1.x, &s1.x);
    printf("s1.y = %d,\t  l'adresse de s1.y est :\t%p\n", s1.y, &s1.y);
    printf("s1.dx = %f,\t l'adresse de s1.dx est :\t%p\n", s1.dx, &s1.dx);
    printf("s1.dy = %f,\t l'adresse de s1.dy est :\t%p\n", s1.dy, &s1.dy);

    printf("---------------------------------------------------------------------\n");
    printf("Acces a une structure par pointeurs\n");

    typedef struct
    {
        int x;
        int y;
        int z;
    } Typexyz;

    Typexyz xyz;
    Typexyz* Ptrxyz;

    xyz.x = 20;
    xyz.y = 55;
    xyz.z = 98;
    printf("Acces  en  direct  x = %d, y = %d, z = %d\n", xyz.x, xyz.y, xyz.z);

    Ptrxyz = &xyz;
    Ptrxyz->x = 21;
    Ptrxyz->y = 56;
    Ptrxyz->z = 99;
    printf("Acces    en  direct   x = %d, y = %d, z = %d\n", xyz.x, xyz.y, xyz.z);
    printf("Acces   par pointeur  x = %d, y = %d, z = %d\n", Ptrxyz->x, Ptrxyz->y, Ptrxyz->z);
    printf("Acces par operateur * x = %d, y = %d, z = %d\n", (*Ptrxyz).x, (*Ptrxyz).y, (*Ptrxyz).z);        // Non recommandÚ

    printf("---------------------------------------------------------------------\n");
    printf("Acces direct et par pointeur a un tableau \n");
    int tab[5] = { 11,22,33,44,55 };
    printf("tableau  = %d %d %d %d %d \n", tab[0], tab[1], tab[2], tab[3], tab[4]);

    int tab2[5] = { 0 };          // tous les ÚlÚments sont effacÚs
    printf("tableau vide = %d %d %d %d %d \n", tab2[0], tab2[1], tab2[2], tab2[3], tab2[4]);

    int* ptab;
    ptab = tab;

    printf("Acces direct et par pointeur a un tableau \n");
    printf("tableau  = %d %d %d %d %d \n", tab[0], tab[1], tab[2], tab[3], tab[4]);
    printf("add tableau  = \n%p \n%p \n%p \n%p \n%p \n", &tab[0], &tab[1], &tab[2], &tab[3], &tab[4]);

    printf("tableau  = %d %d %d %d %d \n", *ptab, *(ptab + 1), *(ptab + 2), *(ptab + 3), *(ptab + 4));
    printf("add tableau  = \n%p \n%p \n%p \n%p \n%p \n", ptab, (ptab + 1), (ptab + 2), (ptab + 3), (ptab + 4));

    printf("---------------------------------------------------------------------\n");
    printf("Dereferencement de pointeur \n");
    int var1 = 50;
    int var2 = 60;

    int* pvar = &var1;
    printf("var1 direct = %d, var1 par pointeur = %d, adresse de pvar= %p\n", var1, *pvar, pvar);

    pvar = &var2;
    printf("var2 direct = %d, var2 par pointeur = %d, adresse de pvar= %p\n", var2, *pvar, pvar);

    pvar = &var1;
    int** ppvar;
    ppvar = &pvar;          // pointe sur l'adresse de pvar
    printf("var1 direct = %d, var1 par pointeur de pointeur= %d, var1 par pointeur = %d, \nadresse de ppvar= %p, \nadresse de  pvar= %p\n", var1, (**ppvar), *pvar, ppvar, pvar);

    // Affectation de var1 par pointeur de pointeur
    (**ppvar) = 1;
    printf("var1 direct = %d, var1 par pointeur de pointeur= %d, var1 par pointeur = %d, \nadresse de ppvar= %p, \nadresse de  pvar= %p\n", var1, (**ppvar), *pvar, ppvar, pvar);

    printf("---------------------------------------------------------------------\n");
    printf("Pointeurs de fonction \n");

    int Add1 = 33;
    int Add2 = 44;

    printf("Addition de Add1 %d avec Add2 %d = %d par appel de fonction FctAddition\n", Add1, Add2, FctAddition(Add1, Add2));

    // static int FctAddition(int nombre1, int nombre2)
    int (*pFct) (int, int) = FctAddition;
    printf("Addition de Add1 %d avec Add2 %d = %d par appel du pointeur de la fonction addition", Add1, Add2, pFct(Add1, Add2));

    printf("\n");
    return 0;
}
