#include "records.h"
#include "main.h"
#include "list.h"

int main() {
    int selector;
    list list;

    cout << "\nThis program tracks the performance of your record collection."
         << "\nYou must have a Discogs collection to use this program."
         << "\nIf you haven't already, download your Discogs collection via "
         << "\nExport -> Collection -> Export Collection Data"
         << "\nThis should give you a .csv document to work with";

    selector = menu();

    switch(selector) {
        case 1: import(); break;
        case 2: display(list); break;
        case 3: edit(list); break;
        case 4: delete_item();
    }
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

int import(){
    return 0;
}

int display(list & list){
    list.display();
    return 0;
}

int edit(list & list){
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
        case 1: add(list); break;
        case 2: edit(list);
    }
    cout << "\n\nWhat artist would you like to edit?\n";
    cin >> name_entry;
    list.edit(name_entry);
    return 0;
}

int delete_item(){
    return 0;
}

int add(list & list){
    list.add();
    return 0;
}