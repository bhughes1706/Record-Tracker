// Created by Brian Hughes on 2019-01-18.

#include "records.h"


int records::display(){
    return info.display();
}

int records::edit() {
    display_options();

    int select = 0;
    do{
        cout << "What would you like to choose? ";
        cin >> select; cin.ignore(1000, '\n');
        if(cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
        }
        if(select > 13 || select < 1)
        cout << "\nPlease enter a valid number";
    } while(select > 13 || select < 1);
    return edit_object(select);
}

int records::edit_object(int select) {
    string str_entry;
    int num_entry;
    cout << "What would you like the new value of ";
    switch(select){
        case 1: cout << " catalog ID to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 2: cout << " artist to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 3: cout << " album to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 4: cout << " label to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 5: cout << " format to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 6: cout << " rating to be? ";
                num_entry = enter_number(); info.edit_int(select, num_entry); break;
        case 7: cout << " release date to be? ";
                num_entry = enter_number(); info.edit_int(select, num_entry); break;
        case 8: cout << " release ID to be? ";
                num_entry = enter_number(); info.edit_int(select, num_entry); break;
        case 9: cout << " folder to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 10: cout << " date added to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 11: cout << " media condition to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 12: cout << " sleeve condition to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        case 13: cout << " notes to be? ";
                str_entry = enter_string(); info.edit_string(select, str_entry); break;
        default: cout << "\nError occurred\n"; return 0;
    }

    return 0;
}

string records::enter_string() {
    return std::string();
}

int records::enter_number() {
    return 0;
}

int record_info::display() {
    cout << "\n\nCatalog ID: " << catalog_id
         << "\nArtist: " << artist << "\nAlbum: " << album
         << "\nLabel: " << label << "\nFormat: " << format
         << "\nRating: " << rating << "\nReleased: " << released
         << "\nRelease ID: " << release_id << "\nFolder: " << collection_folder
         << "\nDate Added: " << date_added << "\nMedia Condition: "
         << media_condition << "\nSleeve Condition: " << sleeve_condition
         << "\nNotes: " << sleeve_condition << "\n";
    return 1;
}

void record_info::edit_int(int select, int entry) {
    switch(select){
        case 6: rating = entry; break;
        case 7: released = entry; break;
        case 8: release_id = entry; break;
        default: cout << "\nError occurred\n"; return;
    }
}

void record_info::edit_string(int select, string entry) {
    switch(select){
        case 1: catalog_id = entry; break;
        case 2: artist = entry; break;
        case 3: album = entry; break;
        case 4: label = entry; break;
        case 5: catalog_id = entry; break;
        case 9: collection_folder = entry; break;
        case 10: date_added = entry; break;
        case 11: media_condition = entry; break;
        case 12: sleeve_condition = entry; break;
        case 13: notes = entry; break;
        default: cout << "\nError occurred\n"; return;
    }
}

int record_info::display_options() const {
    cout << "\n1) Catalog ID: " << catalog_id
         << "\n2) Artist: " << artist << "\n3) Album: " << album
         << "\n4) Label: " << label << "\n5) Format: " << format
         << "\n6) Rating: " << rating << "\n7) Released: " << released
         << "\n8) Release ID: " << release_id << "\n9) Folder: " << collection_folder
         << "\n10) Date Added: " << date_added << "\n11) Media Condition: "
         << media_condition << "\n12) Sleeve Condition: " << sleeve_condition
         << "\n13) Notes: " << sleeve_condition << "\n";
    return 1;
}
