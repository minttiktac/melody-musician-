#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class musician {
private:
    string filename;

public:
    musician(const string& fname) : filename(fname) {}

    void addSong(const string& title, const string& artist, const string& album, const string& duration, const string& filePath) {
        ofstream file(filename, ios::app);
        if (file.is_open()) {
            file <<"\nTitle:"<< title <<"\nArtist:"<< artist <<"\n Album: " << album << "\nDuration:" << duration <<"\nFilepath:" << filePath << endl;
            cout << "Song '" << title << "' has been added to " << filename << "." << endl;
        } else {
            cerr << "Error opening file for writing." << endl;
        }
    }

    void editSong(const string& title, const string& newTitle, const string& newArtist, const string& newAlbum, const string& newDuration, const string& newFilePath) {
        ifstream fileIn(filename);
        ofstream tempFile("temp.txt");

        if (!fileIn.is_open() || !tempFile.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(fileIn, line)) {
            stringstream ss(line);
            string currentTitle, artist, album, duration, filePath;
            getline(ss, currentTitle, ',');
            getline(ss, artist, ',');
            getline(ss, album, ',');
            getline(ss, duration, ',');
            getline(ss, filePath, ',');

            if (currentTitle == title) {
                tempFile << newTitle << "," << newArtist << "," << newAlbum << "," << newDuration << "," << newFilePath << endl;
                found = true;
                cout << "Song '" << title << "' has been updated." << endl;
            } else {
                tempFile << line << endl;
            }
        }

        if (!found) {
            cout << "Song '" << title << "' not found in " << filename << "." << endl;
        }

        fileIn.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    }

    void deleteSong(const string& title) {
        ifstream fileIn(filename);
        ofstream tempFile("temp.txt");

        if (!fileIn.is_open() || !tempFile.is_open()) {
            cerr << "Error opening file." << endl;
            return;
        }

        string line;
        bool found = false;
        while (getline(fileIn, line)) {
            stringstream ss(line);
            string currentTitle;
            getline(ss, currentTitle, ',');

            if (currentTitle == title) {
                found = true;
                cout << "Song '" << title << "' has been deleted from " << filename << "." << endl;
            } else {
                tempFile << line << endl;
            }
        }

        if (!found) {
            cout << "Song '" << title << "' not found in " << filename << "." << endl;
        }

        fileIn.close();
        tempFile.close();

        remove(filename.c_str());
        rename("temp.txt", filename.c_str());
    }
};

int main() {
    string filename;
    cout << "Enter the filename to store songs: ";
    getline(cin, filename);

    musician musicianObj(filename);

    int choice;
    string title, artist, album, duration, filePath, newTitle, newArtist, newAlbum, newDuration, newFilePath;

    do {
        cout << "\n1. Add Song\n2. Edit Song\n3. Delete Song\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  // Ignore the newline character left in the buffer by cin

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist: ";
                getline(cin, artist);
                cout << "Enter album: ";
                getline(cin, album);
                cout << "Enter duration: ";
                getline(cin, duration);
                cout << "Enter file path: ";
                getline(cin, filePath);
                musicianObj.addSong(title, artist, album, duration, filePath);
                break;

            case 2:
                cout << "Enter the title of the song to edit: ";
                getline(cin, title);
                cout << "Enter new title: ";
                getline(cin, newTitle);
                cout << "Enter new artist: ";
                getline(cin, newArtist);
                cout << "Enter new album: ";
                getline(cin, newAlbum);
                cout << "Enter new duration: ";
                getline(cin, newDuration);
                cout << "Enter new file path: ";
                getline(cin, newFilePath);
                musicianObj.editSong(title, newTitle, newArtist, newAlbum, newDuration, newFilePath);
                break;

            case 3:
                cout << "Enter the title of the song to delete: ";
                getline(cin, title);
                musicianObj.deleteSong(title);
                break;

            case 4:
                cout << "Exiting." << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
