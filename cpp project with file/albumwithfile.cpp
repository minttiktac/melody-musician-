#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int max_songs = 100;

class album {
private:
    string album_name;
    string song_titles[max_songs];
    string song_artists[max_songs];
    string album_cover_path;  // New attribute for album cover
    int song_count;

public:
    album(const string& name) : album_name(name), song_count(0), album_cover_path("") {}

    void add_song_to_album(const string& title, const string& artist) {
        if (song_count < max_songs) {
            song_titles[song_count] = title;
            song_artists[song_count] = artist;
            song_count++;
            cout << "song added to album: " << title << " by " << artist << endl;
        } else {
            cout << "album is full. cannot add more songs." << endl;
        }
    }

    void remove_song_from_album(const string& title) {
        bool found = false;
        for (int i = 0; i < song_count; ++i) {
            if (song_titles[i] == title) {
                found = true;
                // Shift songs down to fill the gap
                for (int j = i; j < song_count - 1; ++j) {
                    song_titles[j] = song_titles[j + 1];
                    song_artists[j] = song_artists[j + 1];
                }
                song_count--;
                cout << "song removed from album: " << title << endl;
                break;
            }
        }
        if (!found) {
            cout << "song not found in album: " << title << endl;
        }
    }

    void set_album_cover(const string& cover_path) {
        album_cover_path = cover_path;
        cout << "album cover set to: " << cover_path << endl;
    }

    void display_album_info() const {
        cout << "album name: " << album_name << endl;
        cout << "album cover: " << album_cover_path << endl;
        cout << "songs: " << endl;
        for (int i = 0; i < song_count; ++i) {
            cout << "song " << i + 1 << ":" << endl;
            cout << "title: " << song_titles[i] << endl;
            cout << "artist: " << song_artists[i] << endl;
            cout << "-----------------------" << endl;
        }
    }

   void save_songs_to_file(const string& filename) const {
    ofstream file(filename);
    if (file.is_open()) {
        // Write album name, album cover, and song count with clear labels
        file << "Album Name: " << album_name << endl;
        file << "Album Cover: " << album_cover_path << endl;
        file << "Song Count: " << song_count << endl;
        file<<"-----------------------------------------"<<endl;

        // Write each song's title and artist with clear labels
        for (int i = 0; i < song_count; ++i) {
            file << "Song " << i + 1 << " Title: " << song_titles[i] << endl;
            file << "Song " << i + 1 << " Artist: " << song_artists[i] << endl;
            file<<"___________________________________"<<endl;
        }

        file.close();
        cout << "Songs saved to file: " << filename << endl;
    } else {
        cout << "Error: Could not open file for writing." << endl;
    }
}

void load_songs_from_file(const string& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        // Read album name
        getline(file, line);
        album_name = line.substr(line.find(": ") + 2);

        // Read album cover
        getline(file, line);
        album_cover_path = line.substr(line.find(": ") + 2);

        // Read song count
        getline(file, line);
        song_count = stoi(line.substr(line.find(": ") + 2));

        // Read each song's title and artist
        for (int i = 0; i < song_count; ++i) {
            getline(file, line);
            song_titles[i] = line.substr(line.find(": ") + 2);

            getline(file, line);
            song_artists[i] = line.substr(line.find(": ") + 2);
        }

        file.close();
        cout << "Songs loaded from file: " << filename << endl;
    } else {
        cout << "Error: Could not open file for reading." << endl;
    }
}

};

int main() {
    string album_name, title, artist, cover_path, filename;
    int choice;

    cout << "enter the album name: ";
    getline(cin, album_name);

    album my_album(album_name);

    cout << "enter the filename to load songs from (or press enter to skip): ";
    getline(cin, filename);
    if (!filename.empty()) {
        my_album.load_songs_from_file(filename);
    }

    do {
        cout << "1. add song\n2. remove song\n3. set album cover\n4. display all songs\n5. save and exit\nenter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character left in the buffer by cin

        switch (choice) {
            case 1:
                cout << "enter the title of the song: ";
                getline(cin, title);
                cout << "enter the artist name: ";
                getline(cin, artist);
                my_album.add_song_to_album(title, artist);
                break;

            case 2:
                cout << "enter the title of the song to remove: ";
                getline(cin, title);
                my_album.remove_song_from_album(title);
                break;

            case 3:
                cout << "enter the path to the album cover image: ";
                getline(cin, cover_path);
                my_album.set_album_cover(cover_path);
                break;

            case 4:
                my_album.display_album_info();
                break;

            case 5:
                cout << "enter the filename to save songs to: ";
                getline(cin, filename);
                my_album.save_songs_to_file(filename);
                cout << "exiting..." << endl;
                break;

            default:
                cout << "invalid choice! please enter a number between 1 and 5." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
