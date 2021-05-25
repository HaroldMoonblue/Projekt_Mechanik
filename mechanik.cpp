#include <iostream>

using namespace std;

class Osoba {
public:
    string imie;
    string nazwisko;
    string nr_telefonu;

};

class Pracownik :Osoba {
public:
    int kod_pracownika;
};

bool Logowanie(int kod_pracownika) {
    if (kod_pracownika == 1234) {
        cout << "Kod poprawny" << endl;
        return true;
    }
    else {
        cout << "Kod niepoprawny" << endl;
        return false;
    }
}

class Część {
public:
    string nazwa;
    string opis;
    int cena;
    string numer_zamowienia;
public:
    void dodaj_czesc(string nazwaczesci, string opisczesci, int cenaczesci) {
        nazwa = nazwaczesci;
        opis = opisczesci;
        cena = cenaczesci;
       
    }
    void dodaj_do_zamowienia(string numer_zamowieniaczesci) {
        numer_zamowienia = numer_zamowieniaczesci;
    }
};

class Usługa {
public:
    string data_oddania_auta;
    string opis_prac;
    bool czy_przysługuje_zamienne;
    bool czy_gotowe;
    string rodzaj_usługi;
    string numer_uslugi;
public:
    void rejestracja_uslugi(string numer_uslugi, string data_oddania_auta, string opis_prac, bool czy_przysluguje_zamienne, bool czy_gotowe, string rodzaj_uslugi) {

    }
    bool znajdz_usluge(string numer_zlecenia) {
       if (numer_zlecenia == numer_uslugi) {
           return true;
       }
       else {
           return false;
       }
    }

    void dodaj_opis(string dodawany_opis) {
        opis_prac = opis_prac + dodawany_opis;
    }
    void zmien_status_gotowosci(bool deklarowana_gotowosc) {
        czy_gotowe = deklarowana_gotowosc;
    }
};

class Pojazd {
    string marka;
    string model;
    string nr_rejestracyjny;
    int rocznik;
    string nr_vin;
    string ostatni_przeglad;
    int id_klienta;

    void dodajPojazd() {

    }
};

class Pojazd_zamienny : Pojazd {
    bool czy_wolny;
    string data_od;
    string data_do;
    int przebieg_początkowy;
    int przebieg_zwrócony;
    int id_klienta;
    string opis;
    int cena_za_dobe;

    int ile_przejechano(int przebieg_początkowy, int przebieg_zwrócony) {
        return przebieg_zwrócony - przebieg_początkowy;
    }
    bool wypozycz(bool czy_wolny) {
        if (czy_wolny == true) {
            czy_wolny = false;
        }
        else {
            cout << "Auto jest już zajęte" << endl;
        }
    }
    int cena_za_wypozyczenie() {

    }
    void dodaj_pojazd_zamienny() {

    }

};

class Pojazd_klienta :Pojazd {
    int id_klienta;

    void dodaj_pojazd_klienta() {

    }
};


void prace_serwisowe() {
    cout << "Podaj kod autoryzacyjny: ";
    int kod;
    cin >> kod;
    bool wynik_logowania = Logowanie(kod);
    if (wynik_logowania == true) {
        cout << "Podaj numer zlecenia: ";
        string numer_zlecenia;
        cin >> numer_zlecenia;
        Usługa usługa = Usługa();
        bool czy_istnieje_usluga = usługa.znajdz_usluge(numer_zlecenia);
        if (czy_istnieje_usluga == true) {
            cout << "Rejestruje prace serwisowe do usługi: " + numer_zlecenia << endl;
            cout << "Czy zostały wykonane dodatkowe naprawy? [T/N]" << endl;
            string ask_naprawy;
            cin >> ask_naprawy;
            if (ask_naprawy == "T" || ask_naprawy == "t" || ask_naprawy == "tak" || ask_naprawy == "TAK") {
                cout << "Podaj opis wykonywanych prac: " << endl;
                string opis_prac_zlecenie;
                cin >> opis_prac_zlecenie;
                usługa.dodaj_opis(opis_prac_zlecenie);
                cout << "Opis został dodany do zlecenia" << endl;
            }else {
                cout << "Nie dodajemy nowych prac" << endl;
            }
            cout << "Czy auto jest już gotowe do odbioru przez klienta [T/N]" << endl;
            string ask_gotowe;
            cin >> ask_gotowe;
            if (ask_gotowe == "T" || ask_gotowe == "t" || ask_gotowe == "tak" || ask_gotowe == "TAK") {
                bool zmianagotowosci = true;
                usługa.zmien_status_gotowosci(zmianagotowosci);
                cout << "Auto gotowe, zadzwoń do klienta aby mógł je odebrać" << endl;

            }
            else {
                cout << "Auto nie zostanie zapisane jako gotowe, kończymy" << endl;
            }
        }
        else {
            cout << "Taka usługa nie istnieje, kończymy" << endl;
        }
    }
    else {
        cout << "Logowanie błędne" << endl;
    }
}

void zamowienie_czesci() {
    cout << "Podaj kod autoryzacyjny: ";
    int kod;
    cin >> kod;
    bool wynik_logowania = Logowanie(kod);
    string nazwa;
    string opis;
    int cena;
    string numer_zamowienia;

    if (wynik_logowania == true) {
        cout << "Dodawanie części" << endl;
        cout << "Podaj nazwę części: ";
        cin >> nazwa;
        cout << endl;
        cout << "Podaj opis części: " << endl;
        cin >> opis;
        cout << endl;
        cout << "Podaj cenę części" << endl;
        cin >> cena;
        cout << endl;
        Część część = Część();
        część.dodaj_czesc(nazwa, opis, cena);
        cout << "Część została dodana" << endl;
        cout << endl;
        cout << "Czy chcesz dodać część do istniejącego numeru zlecenia? [T/N]" << endl;
        string ask_naprawy;
        cin >> ask_naprawy;
        if (ask_naprawy == "T" || ask_naprawy == "t" || ask_naprawy == "tak" || ask_naprawy == "TAK") {
            cout << "Podaj numer zlecenia" << endl;
            string numer_zlecenia;
            cin >> numer_zlecenia;
            Usługa usługa = Usługa();
            bool czy_istnieje_usluga = usługa.znajdz_usluge(numer_zlecenia);
            if (czy_istnieje_usluga == true) {
                cout << "Część zostanie zapisana jako uzyta do podanej usługi" << endl;
                część.dodaj_do_zamowienia(numer_zlecenia);
            }
            else {
                cout << "Nie ma takiej usługi" << endl;
            }
        }
        else {
            cout << "Część została zapisana ale nie przypisana do żadnego zgłoszenia, kończymy" << endl;
        }
    }
    else {
        cout << "Logowanie błędne "<< endl;    
    }
}

int main()
{
    setlocale(LC_CTYPE, "Polish");
    cout << "" << endl;
    cout << " .----------------.  .----------------.  .----------------.  .----------------.  .----------------.  .-----------------. .----------------.  .----------------. " << endl;
    cout << "| .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. || .--------------. |" << endl;
    cout << "| | ____    ____ | || |  _________   | || |     ______   | || |  ____  ____  | || |      __      | || | ____  _____  | || |     _____    | || |  ___  ____   | |" << endl;
    cout << "| ||_   \\  /   _|| || | |_   ___  |  | || |   .' ___  |  | || | |_   ||   _| | || |     /  \\     | || ||_   \\|_   _| | || |    |_   _|   | || | |_  ||_  _|  | |" << endl;
    cout << "| |  |   \\/   |  | || |   | |_  \\_|  | || |  / .'   \\_|  | || |   | |__| |   | || |    / /\\ \\    | || |  |   \\ | |   | || |      | |     | || |   | |_/ /    | |" << endl;
    cout << "| |  | |\\  /| |  | || |   |  _|  _   | || |  | |         | || |   |  __  |   | || |   / ____ \\   | || |  | |\\ \\| |   | || |      | |     | || |   |  __'.    | |" << endl;
    cout << "| | _| |_\\/_| |_ | || |  _| |___/ |  | || |  \\ `.___.'\\  | || |  _| |  | |_  | || | _/ /    \\ \\_ | || | _| |_\\   |_  | || |     _| |_    | || |  _| |  \\ \\_  | |" << endl;
    cout << "| ||_____||_____|| || | |_________|  | || |   `._____.'  | || | |____||____| | || ||____|  |____|| || ||_____|\\____| | || |    |_____|   | || | |____||____| | |" << endl;
    cout << "| |              | || |              | || |              | || |              | || |              | || |              | || |              | || |              | |" << endl;
    cout << "| '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' || '--------------' |" << endl;
    cout << " '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------'  '----------------' " << endl;
    cout << "" << endl;

    cout << "						 __      ____   _____ ___ ___ ___  ____  _____ _____   _____          " << endl;
    cout << "						 \\ \\    / /\\ \\ / / _ )_ _| __| _ \\|_  / |_   _| _ \\ \\ / / _ )  " << endl;
    cout << "						  \\ \\/\\/ /  \\ V /| _ \\| || _||   / / /    | | |   /\\ V /| _ \\  " << endl;
    cout << "						   \\_/\\_/    |_| |___/___|___|_|_\\/___|   |_| |_|_\\ |_| |___/     " << endl;
    cout << "						                                                                      " << endl;
    
    cout << endl;

    cout << "                                                                                           " << endl;
    cout << "  _____ _____   _____   ___ ___    _   ___ _____      ___  _ ___ _  __   _                 " << endl;
    cout << " |_   _| _ \\ \\ / / _ ) | _ \\ _ \\  /_\\ / __/ _ \\ \\    / / \\| |_ _| |/ /  /_\\       " << endl;
    cout << "   | | |   /\\ V /| _ \\ |  _/   / / _ \\ (_| (_) \\ \\/\\/ /| .` || || ' <  / _ \\        " << endl;
    cout << "   |_| |_|_\\ |_| |___/ |_| |_|_\\/_/ \\_\\___\\___/ \\_/\\_/ |_|\\_|___|_|\\_\\/_/ \\_\\  " << endl;
    cout << "                                                                                           " << endl;

    cout << "[1] Rejestrowanie prac serwisowych" << endl;
    cout << "[2] Zamówienie części" << endl;
    cout << "[3] Wydanie auta zastępczego" << endl;
    cout << "[4] Odbiór auta zastępczego" << endl;
    cout << "[5] Powrót do menu głównego" << endl;
    cout << endl;
    cout << "Twój wybór: ";
    int choose;
    cin >> choose;
    switch (choose) {
    case 1:
        cout << "Rejestrowanie prac serwisowych" << endl;
        prace_serwisowe();
        break;
    case 2:
        cout << "Zamówienie części" << endl;
        zamowienie_czesci();
        break;
    case 3:
        cout << "Wydanie auta zastępczego" << endl;
    case 4:
        cout << "Odbiór auta zastępczego" << endl;
        break;
    case 5:
        cout << "Powrót do menu głównego" << endl;
        break;
    default:
        cout << "Nie ma takiej opcji! Kończymy" << endl;
    }


    cout << "                                                                              " << endl;
    cout << "  _____ _____   _____   _  _____ ___ ___  _____      ___  _ ___ _  __   _     " << endl;
    cout << " |_   _| _ \\ \\ / / _ ) | |/ /_ _| __| _ \\/ _ \\ \\    / / \\| |_ _| |/ /  /_\\    " << endl;
    cout << "   | | |   /\\ V /| _ \\ | ' < | || _||   / (_) \\ \\/\\/ /| .` || || ' <  / _ \\   " << endl;
    cout << "   |_| |_|_\\ |_| |___/ |_|\\_\\___|___|_|_\\\\___/ \\_/\\_/ |_|\\_|___|_|\\_\\/_/ \\_\\  " << endl;
    cout << "                                                                              " << endl;
    cout << "                                                                              " << endl;


    cout << "                                                           " << endl;
    cout << "  _____ _____   _____   _  ___    ___ ___ _  _ _____ _     " << endl;
    cout << " |_   _| _ \\ \\ / / _ ) | |/ / |  |_ _| __| \\| |_   _/_\\    " << endl;
    cout << "   | | |   /\\ V /| _ \\ | ' <| |__ | || _|| .` | | |/ _ \\   " << endl;
    cout << "   |_| |_|_\\ |_| |___/ |_|\\_\\____|___|___|_|\\_| |_/_/ \\_\\  " << endl;
    cout << "                                                           " << endl;
    cout << "                                                           " << endl;
}

