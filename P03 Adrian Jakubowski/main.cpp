#include <iostream>
#include <time.h> //do losowania liczb pseudolosowych
#include <fstream> //do zapisu wyniku do pliku
#include <stdio.h> //do liczenia czasu
#include <chrono> // do liczenia czasu


using namespace std;


void wypelnianieTablicy(int tablica[], int rozmiar);
void szukanie(int tablica[], int rozmiar);

ofstream plik;

int main()
{

    int rozmiarPobrany;
    cout<<"Podaj z ilu elementow ma skladac sie tablica: "<<endl;
    cin>>rozmiarPobrany;
    const int rozmiar=rozmiarPobrany; //constans, bo rozmiar jest staly przez caly program

    int tablica[rozmiar];

    auto begin = std::chrono::high_resolution_clock::now(); //poczatek liczenia czasu

    plik.open("wyniki.txt");

    wypelnianieTablicy(tablica, rozmiar);

    szukanie(tablica,rozmiar);

    auto end = std::chrono::high_resolution_clock::now(); //koniec liczenia czasu
    double elapsed = double(std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin).count()); //czas obliczen - roznica konca i poczatku

    plik<<endl<<"Zmierzony czas: "<< elapsed/(1e9)<<endl;

    plik.close();

}



// ** WYPE£NIANIE TABLICY LICZBAMI PSEUDOLOSOWYMI **
void wypelnianieTablicy(int tablica[], int rozmiar)
{
    srand(time(NULL)); // do losowania liczb pseudolosowych

    plik<<"Wylosowana tablica liczb:"<<endl;

    for(int i = 0; i<rozmiar; i++)
    {
        tablica[i]=rand()%(rozmiar-1)+1;
        plik<<tablica[i]<<", ";
    }
}


// ** SZUKANIE POWTARZAJACYCH SIE ELEMENTOW TABLICY **
void szukanie(int tablica[], int rozmiar)
{
    plik<<endl<<endl;


    plik<<"Powtarzajacy sie element/elementy to:"<<endl;
    for(int k = 0; k<rozmiar; k++)
    {

        int licznik=0;

        for(int j = 0; j<rozmiar; j++)
            {
            if(tablica[j]==tablica[k])
                licznik++;
            }

        if(licznik==2)
            plik<<tablica[k]<<" ";


        tablica[k]=0;
    }

    plik<<endl;

}
