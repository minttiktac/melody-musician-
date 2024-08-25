#include <iostream>
#include <string>

using namespace std;

const int MAX_SONGS = 100; 

class Album {
private:
    string albumName; 
    string songTitles[MAX_SONGS];   // Array to store song titles
    string songArtists[MAX_SONGS];  // Array to store song artists
    int songCount; 

public:
   
    Album(const string& name) : albumName(name), songCount(0) {}

    void addSongToAlbum(const string& title, const string& artist) {
        if (songCount < MAX_SONGS) {
            songTitles[songCount] = title;
            songArtists[songCount] = artist;
            songCount++;
            cout << "Song added to album: " << title << " by " << artist << endl;
        } else {
            cout << "Album is full. Cannot add more songs." << endl;
        }
    }

    void removeSongFromAlbum(const string& title) {
        bool found = false;
        for (int i = 0; i < songCount; ++i) {
            if (songTitles[i] == title) {
                found = true;
                // Shift songs down to fill the gap
                for (int j = i; j < songCount - 1; ++j) {
                    songTitles[j] = songTitles[j + 1];
                    songArtists[j] = songArtists[j + 1];
                }
                songCount--;
                cout << "Song removed from album: " << title << endl;
                break;
            }
        }
        if (!found) {
            cout << "Song not found in album: " << title << endl;
        }
    }

    void displayAlbumInfo() const {
        cout << "Album Name: " << albumName << endl;
        cout << "Songs:" << endl;
        for (int i = 0; i < songCount; ++i) {
            cout << "Song " << i + 1 << ":" << endl;
            cout << "Title: " << songTitles[i] << endl;
            cout << "Artist: " << songArtists[i] << endl;
            cout << "-----------------------" << endl;
        }
    }
};

int main() {
    string albumName, title, artist;
    int choice;

    cout << "Enter the album name: ";
    getline(cin, albumName);

    Album myAlbum(albumName);

    do {
        cout << "1. Add Song\n2. Remove Song\n3. Display All Songs\n4. Exit\nEnter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter the title of the song: ";
                getline(cin, title);
                cout << "Enter the artist name: ";
                getline(cin, artist);
                myAlbum.addSongToAlbum(title, artist);
                break;

            case 2:
                cout << "Enter the title of the song to remove: ";
                getline(cin, title);
                myAlbum.removeSongFromAlbum(title);
                break;

            case 3:
                myAlbum.displayAlbumInfo();
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
