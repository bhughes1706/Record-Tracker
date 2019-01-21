#include "records.h"
#include "main.h"
#include "table.h"
#include "seven.h"
#include "seventy_eights.h"
#include "boxset.h"

int main() {
    int selector;
    table table;

    cout << "\nThis program tracks the performance of your record collection.";
    /*<< "\nYou must have a Discogs collection to use this program."
    << "\nIf you haven't already, download your Discogs collection via "
    << "\nExport -> Collection -> Export Collection Data"
    << "\nThis should give you a .csv document to work with";*/

    do {
        selector = menu();
        switch (selector) {
            case 1: import(table); break;
            case 2: display_all(table); break;
            case 3: edit(table); break;
            case 4: delete_item(table);
            default: break;
        }
    } while(selector != 5);
    return 0;
}

int menu() {
    int selector;
    do {
        cout << "\n\nWould you like to: \n1) Import Database \n2) Display entire database"
             << "\n3) Edit current database \n4) Delete current database \n5) Exit\n"
             << "Enter option: ";
        cin >> selector; cin.ignore(1000, '\n');
        if(cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            selector = 0;
        }
        if(selector > 5 || selector <= 0)
            cout << "\n\nPlease enter valid number.";
    } while(selector > 5 || selector <= 0);
    return selector;
}

int import(table & table){
    int selector = 0;
    do {
        cout << "\n\n1) Import a .txt file\n"
             << "2) Import .csv file\n";
        cin >> selector; cin.ignore(1000, '\n');
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            selector = 0;
        }
        if(selector > 2 || selector <= 0)
            cout << "\n\nPlease enter valid number.";
    } while (selector > 2 || selector <= 0);

    switch(selector){
        case 1: table.importtxt(); break;
        case 2: table.importcsv(); break;
        default: break;
    }
    return 0;
}

int display_all(table & table){
    table.display_all();
    return 0;
}

int edit(table & table){
    string name_entry;
    int selector;
    do{
        cout << "\n\nWould you like to: \n1) Add a record manually"
             << "\n2) Edit record in database\n";
        cin >> selector; cin.ignore(1000, '\n');
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
        }
        if(selector != 1 && selector != 2){
            cout << "\nPlease enter a valid number.";
        }
    }while(selector == 2 || selector == 1);

    switch(selector){
        case 1: add(table); break;
        case 2: edit(table);
        default: break;
    }
    cout << "\n\nWhat artist would you like to edit?\n";
    cin >> name_entry;
    table.edit(name_entry);
    return 0;
}

int delete_item(table & table){
    string artist_name;
    cout << "\nWhat artists would you like to delete?\n";
    cin >> artist_name;
    table.delete_record(artist_name);
    return 0;
}

int add(table & table){
    table.add();
    return 0;
}