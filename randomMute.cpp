#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

using std::cout;
using std::cin;
using std::vector;
using std::string;


int main(){
    int pech;
    string plik;
    string x;
    int linie = 0;
    int id = 0;
    int wylosowany;
    string czas[6] = {"1 minuta", "5 minut", "10 minut", "1 dzień", "tydzień"};
    vector<string> ofiary;

    srand(time(NULL));

    cout << "---------- Kto dostanie mute? ----------\n";

    cout << "Ile osób dzisiaj ma pecha?\n";
    cin >> pech;

    cout << "Podaj nazwe pliku z ofiarami: ";
    cin >> plik;
    std::fstream kandydaci(plik);

    if (!kandydaci)
    {
        cout << "Nie ma takiego pliku!";
        return 0;
    }
    

    while (getline(kandydaci, x))
    {
        ofiary.push_back(x);
        linie++;
    }

    for (int i = 1; i <= pech; i++){
        wylosowany = rand() % linie;
        id = (rand() % 5);
        cout << "Wylosowano: " << ofiary[wylosowany] << " na " <<  czas[id] << '\n';
        id = 0;
    }

    cout << "----------------------------------------\n";
}
