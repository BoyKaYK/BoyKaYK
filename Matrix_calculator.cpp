#include <iostream>
#include <fstream>
#include <string>
#include "print.h"
#include "print_error.h"

using namespace std;

int matx_plus[10][10];                 
int matx_minus[10][10];
int matx_umnoz[10][10];
char n;
char n1;
char n2;
char n3;
int matxa[10][10];
int matxb[10][10];
const int ASCII = 48;
int error_dod = 0;
int error_mnoz = 0;
int error_text = 0;
// Wczytywacz

void reader() { 

    

    int p = 0;
    string M1 = "M1.txt";                     //pobiera adresy na kazdy plik.
    string S1 = "SIZE1.txt";
    string M2 = "M2.txt";
    string S2 = "SIZE2.txt";
    ifstream read1;
    ifstream size1;                         //deklaruje zmienne dla  wczytywania z plikow.
    ifstream read2;
    ifstream size2;
    read1.open(M1);                     // otwiera pliki.
    size1.open(S1);
    read2.open(M2);      
    size2.open(S2);


    size1.get(n);           //przepisanie do zmiennych .
    n = n - ASCII;

    for (int i = 0; i < 2; i++) {
        size1.get(n1);
    }
    n1 = n1 - ASCII;                   

    string Mx1;
    while (!read1.eof()) {
        read1 >> Mx1;             

    }



    size2.get(n2);          
    n2 = n2 - ASCII;

    for (int i = 0; i < 2; i++) {
        size2.get(n3);                   
    }
    n3 = n3 - ASCII;

    string Mx2;
    while (!read2.eof()) {
        read2 >> Mx2;

    }


    if (n != n2 || n1 != n3) {

        error_dod++;                             
    }
    if (n1 != n2) {
        error_mnoz++;
    }

    for (int i = 0; i < n; i++)
    {


        for (int j = 0; j < n1; j++) {

            matxa[i][j] = Mx1[p] - ASCII;                            // robi z 'stringa ' dwuwymiarowa tabele .
            
            if (Mx1[p] < 48 || Mx1[p] > 57) {
                error_text++;
                
            }
            p++;
        }
    }

    p = 0;

    for (int i = 0; i < n2; i++)
    {


        for (int j = 0; j < n3; j++) {

            matxb[i][j] = Mx2[p] - ASCII;
            
            if (Mx2[p] < 48 || Mx2[p] > 57) {
                error_text++;

            }
            p++;
        }
    }
    read1.close();
    read2.close();
    size1.close();                //zamyka pliki.
    size2.close();
}



int plu()
{
    
    reader(); // Wczytywacz

    if (error_text > 0) {
        cout << "Pomylka wczytywania: sprawdz wpisane macierze." << endl;
        
        return 0;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n1; j++)
        {
            matx_plus[i][j] = matxa[i][j] + matxb[i][j];

        }

    cout << "wynnik dodawania macierzy :" << endl;

    if (error_dod == 0) {
        print(matx_plus, n, n1);      //funkcja wypisywania.
    }
    else {
        print_error();             // funkcja wypisywania pomylki rozmiarow.s
    }

    return 0;
}
    
int minu() {
    
    reader(); // Wczytywacz

    if (error_text > 0) {
        cout << "Pomylka wczytywania: sprawdz wpisane macierze."<<endl;

        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            matx_minus[i][j] = matxa[i][j] - matxb[i][j];

        }
    }

    cout << "wynnik odejmowania macierzy :" << endl;

    if (error_dod == 0) {
        print(matx_minus,n,n1);
    }
    else {
        print_error();
    }

    return 0;
}
 int mnoz(){

     reader(); // Wczytywacz 

     if (error_text > 0) {
         cout << "Pomylka wczytywania: sprawdz wpisane macierze." << endl;

         return 0;
     }
        
    for (int i = 0; i < n; i++)
    {
       for (int j = 0; j < n; j++)
        {
            matx_umnoz[i][j] = 0;
            for (int k = 0; k < n; k++)
                matx_umnoz[i][j] += matxa[i][k] * matxb[k][j];

        }
    }

    cout << "wynnik mnozenia macierzy :" << endl;

    if (error_mnoz == 0) {
        print(matx_umnoz, n, n);
    }
    else {
        print_error();
    }

    return 0;
}
 int main() {

     string rodzaj;

     cout << "\t\t\t\t\t\t KALKULATOR MACIERZOWY \n\t\t\tDzieki niemu mozesz dodac, odjac a nawet pomnozyc macierze przez siebie" << endl;
     cout << " Aby uzyskac wynik:\n-> Wpisz rodzaj operacji jaka chcesz uzyskac(dodac, odjac lub pomnozyc).\n-> Macierze automatycnie pobierane z plikow.\n";
     
     while (true) {

     cin >> rodzaj;

     if (rodzaj == "dodac") {

         plu();
     }
     else if (rodzaj == "odjac") {

         minu();
     }
     else if (rodzaj == "pomnozyc") {

         mnoz();
     }
     else {
         cout << "niema takiej operacji !"<<endl;
     }
 }
 
       
    
    return 0;
}


