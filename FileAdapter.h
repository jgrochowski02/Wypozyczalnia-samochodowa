#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

/*
FileAdapter to jest klasa pozwalaj¹ca w prosty sposób zarz¹dzaæ plikami
w sposób przypominaj¹cy baze danych.
Wiersze w odpowiadaj¹ rekordom, natomiast kolumny atrybutom,
przy czym pierwszym atrybutem jest id, które jest autoincreamentowane.
Klasa ta posiada 3 operacje:
    -odczyt [pojedynczego rekordu (readRecord) lub wszystkich (readAllRecords) ]
    -zapis nowych danych
    -usuniêcie rekordu

przyk³adowe u¿ycie.

Aby stworzyæ now¹ instancje np. dla klientów nale¿y wywo³aæ

    FileAdapter clients("client.txt");

Aby zapisaæ dane do pliku nale¿y u¿yæ metody writeRecord,
która przyjmuje tylko jeden parametr, jest to string,
a dane powinny byæ poodzielane spacj¹ np.

    clients.writeRecord("Wojciech Gos");
    clients.writeRecord("Antoni Grabski");
    clients.writeRecord("Jan Grochowski");

dane w pliku bêd¹ wygl¹daæ nastêpuj¹co

    1 Wojciech Gos
    2 Antoni Grabski
    3 Jan Grochowski

przy czym wa¿na jest kolejnoœæ wprowadzania danych bo jeœli zamieni³bym
miejscami imie z nazwiskiem przy jednym rekordzie to wprowadza³oby
niejednoznacznoœæ danych.

Do odczytywania danych z pliku potrzebne s¹ 2 biblioteki:

    #include <sstream>
    #include <vector>

Do odczytania jednego rekordu wystarczy podaæ jego numer id.

    string data = clients.readRecord(3);

natomiast jeœli chcemy odczytaæ jedn¹ informacje np. nazwisko, wystarczy nale¿y u¿yæ
funkcje istringstream.

    istringstream iss(data);
    int id;
    string imie, nazwisko;
    iss >> id >> imie >> nazwisko;
    cout << nazwisko << endl;

Jak widaæ powy¿ej trzeba znaæ dok³adnie strukture danych i na jej podstawie nale¿y
potem definiowaæ zmienne, aby uzyskiwaæ dok³adnie takie dane jakie chcemy.
Tutaj struktura wygl¹da nastêpuj¹co:

    ------------------------
    | ID | IMIE | NAZWISKO |
    ------------------------

Dane oddzielone spacj¹ s¹ traktowane jako osobne atrybuty.
Usuwanie danych równie¿ jest proste, wystarczy podaæ id rekordu.

    clients.deleteRecord(3);

A ¿eby odczytaæ ca³¹ zawartoœæ pliku

    for(int i=0; i<client_data.size(); ++i){
        cout << client_data[i] << endl;
    }
*/

#ifndef FileAdapter_h
class FileAdapter {
private:
    string file_name;
    string increment_file_name;

    ifstream openRead() {
        ifstream file;
        file.open(file_name);
        return file;
    }

    ofstream openWrite() {
        ofstream file;
        file.open(file_name, ios::app);
        return file;
    }

    bool isWantedId(const int &id, const string &data) {
        int current_id;
        istringstream iss(data);
        iss >> current_id;
        if (current_id == id)
            return true;
        return false;
    }

    void initId() {
        ofstream file;
        file.open(increment_file_name);
        file << "1";
        file.close();
    }

    int getId() {
        ifstream file;
        file.open(increment_file_name);
        string data;
        getline(file, data);
        int id;
        istringstream iss(data);
        iss >> id;
        file.close();
        return id;
    }

    void increment() {
        ofstream file;
        int new_id = getId() + 1;
        file.open(increment_file_name);
        file << new_id;
        file.close();
    }

public:
    FileAdapter(string file_name) {
        this->file_name = file_name;
        this->increment_file_name = "increment_" + file_name;
        ifstream database = openRead();
        if (database.fail()) {
            cout << "Cant open file: " << file_name << endl;
            cout << "Creating new: "
                 << file_name << endl;

            database.open(file_name, ios::out);
        }

        fstream auto_increment;
        auto_increment.open(increment_file_name);
        if (auto_increment.fail()) {
            cout << "Cant open file: "
                 << increment_file_name << endl;
            cout << "Creating new: "
                 << increment_file_name << endl;

            auto_increment.open(increment_file_name, ios::out);
            auto_increment.close();
            initId();
        }
    }

    string readRecord(int id) {
        string data;
        ifstream file = openRead();
        int current_id;
        string str;
        if (file.is_open()) {

            while (getline(file, data)) {
                if (isWantedId(id, data)) {
                    file.close();
                    return data;
                }
            }
        }
        file.close();
        return "";
    }

    vector<string> readAllRecords() {
        string data;
        ifstream file = openRead();
        int current_id;
        string str;
        vector<string> records;
        if (file.is_open()) {

            while (getline(file, data)) {
                records.push_back(data);
            }
        }
        file.close();
        return records;
    }

    int writeRecord(const string &data) {
        int id = getId();
        increment();
        ofstream file = openWrite();
        file << "\n"
             << id << " " << data;
        file.close();
        return id;
    }

    void deleteRecord(int id) {
        string data;
        ifstream file_read = openRead();
        int current_id;
        string tmp_file_name = "tmp_" + file_name;

        fstream tmp_file;
        tmp_file.open(tmp_file_name, ios::out);
        if (!tmp_file.is_open()) {
            cout << "Cant create tmp_file: " << tmp_file_name << endl;
            return;
        }
        if (file_read.is_open()) {

            while (getline(file_read, data)) {
                if (!isWantedId(id, data)) {
                    tmp_file << data << "\n";
                }
            }
        }
        file_read.close();
        tmp_file.close();

        ofstream file_write;
        file_write.open(file_name);
        tmp_file.open(tmp_file_name, ios::in);
        if (file_write.is_open()) {
            while (getline(tmp_file, data)) {
                file_write << data << "\n";
            }
        }
        remove(tmp_file_name.c_str());
    }
};

#endif
