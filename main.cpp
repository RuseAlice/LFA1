#include <iostream>
#include <fstream>
#include <queue>
#include <string.h>
using namespace std;
fstream fin("fisier.in");

struct tranzitie{
int primul;
int ultimul;
char litera;

};

int verificare_alfabet(char a, char alf[5], int n )
{
    for(int i=0;i<n;i++)
    {
        if(a==alf[i])
            return 1;
    }
    return 0;
}



int main()
{   tranzitie tr[10];
    int nr_stari, i, j,stari[10]={0}, nr_lit, stare_init, finale, nr_tranz, x,y, contor;
    char alfabet[5], lit, cuvant[12];

    fin>>nr_stari;
    fin>>stare_init;
    fin>>finale;///nr stari finale
    ///vectorul pt stari finale
    for(i=1;i<=finale;i++)
    {
        fin>>j;

        stari[j]=1;
    }
    fin>>nr_lit;
    ///alfabetul
    for(i=0;i<nr_lit;i++)
    {
        fin>>lit;
        alfabet[i]=lit;
    }
    fin>>nr_tranz;
    for(i=0;i<nr_tranz;i++)
    {
        fin>>x>>y>>lit;
        tr[i].primul=x;
        tr[i].ultimul=y;
        tr[i].litera=lit;///pot sa fac direct fin>>tr[i].primul;
    }


    for(i=0;i<nr_tranz;i++)
    {

        cout<<tr[i].primul<<" ";
        cout<<tr[i].ultimul<<" ";
        cout<<tr[i].litera<<endl;
    }
    cout<<"cuvantul: ";
    cin>>cuvant;
///------------------------------------------------pana aici a fost citirea datelor
  ///  cout<<strlen(cuvant);
   queue <int> q; ///am creat coada
    q.push(stare_init);
    contor=1;
    i=0;
    ///i<
    while(strlen(cuvant)>i)///---------------------------------------inceput while
    {if(!verificare_alfabet(cuvant[i],alfabet,strlen(cuvant)))///verificam dc litera e din alfabet
        {
            cout<<"litera nu apartine alfabetului";
            return 0;
        }

       x=contor;
        contor=0;
    for(int k=0;k<x;k++)
    {   if(q.empty())
        {
            cout<<"NU";
            return 0;
        }
        y=q.front();
        q.pop();///pt ca l-am salvat in y
        lit=cuvant[i];
        for(j=0;j<nr_tranz;j++)
        {
            if(tr[j].primul==y && tr[j].litera==lit)///pointer sau nu?
            {
                q.push(tr[j].ultimul);
                cout<<tr[j].ultimul<<" ";
                contor++;
            }

        }
         if(q.empty())
            {cout<<"NU e acceptat, nu mai exista tranzitie";
            return 0;
            }

    }
    i++;
    }///--------------------------------------------------------------sf while
    while(!q.empty())
   {

    y=q.front();
    q.pop();
    if(stari[y]==1)
        {
            cout<<y<<" CUV BUN yay ";
            return 0;
        }
    }
        cout<<y<<" nu e stare finala";


    ///citesc datele

    ///coada pt stari

    ///functie recursiva?
    ///ac pt o stare si apoi la fel pt fiecare din starile in care ajung

///verificare litera, fct separata
    /**
    -citesc o litera
    -tb sa retin undeva la ce litera am ramas PT FIECARE STARE nu merge recursiv
    -sa il apelez recursiv dupa ce termin cu toate starile pt o litera, cum fac asta???
    -vector de stari 0-nu, 1-finala
    -cand ne oprim??
    -verif la sf ca starea la care am aj sa fie finala
    -tb sa nu se repete
    -bd like?

-contor cate stari pot sa fac pana schimb litera
-coada

    */




}
