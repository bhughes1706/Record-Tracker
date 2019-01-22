// Created by Brian Hughes on 2019-01-18.

#include "records.h"


int records::display(){
    if(info.display())
        return 1;
    return 0;
}

int records::edit() {
    return 0;
}

void records::display_options() const {

}

int records::edit_object() {
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
    return 0;
}

int record_info::edit() {
    return 0;
}
