#include "records.h"
#include "main.h"
#include "list.h"

int main() {
    int selector;
    list list;

    cout << "\nThis program tracks the performance of your record collection"
         << "\nTo begin, download your Discogs collection via "
         << "\nExport -> Collection -> Export Collection Data";

    selector = menu();

    switch(selector) {
        case 1: import(); break;
        case 2: display(list); break;
        case 3: edit(); break;
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

}

int display(list & list){
    list.display();
}

int edit(){
    string name_entry;
    cout << "\n\nWhat artist would you like to edit?\n";
    cin >> name_entry;

}

int delete_item(){

}