#include <iostream>
#include <string>
using namespace std;

const int MAX_SONGS = 100; // Maximum number of songs a musician can have

class musician {
private:
    string titles[MAX_SONGS];
    string artists[MAX_SONGS];
    string albums[MAX_SONGS];
    string durations[MAX_SONGS];
    string filepaths[MAX_SONGS];
    int song_count;

public:
    musician() : song_count(0) {}

    void add_song() {
        if (song_count >= MAX_SONGS) {
            cout << "Cannot add more songs. Storage is full!" << endl;
            return;
        }

        cout << "Enter details for the new song:" << endl;

        cout << "Title: ";
        getline(cin, titles[song_count]);

        cout << "Artist: ";
        getline(cin, artists[song_count]);

        cout << "Album: ";
        getline(cin, albums[song_count]);

        cout << "Duration: ";
        getline(cin, durations[song_count]);

        cout << "Filepath: ";
        getline(cin, filepaths[song_count]);

        song_count++;
        cout << "Song added!" << endl;
    }

    void edit_song() {
        if (song_count == 0) {
            cout << "No songs available to edit." << endl;
            return;
        }

        int index;
        cout << "Enter the song number you want to edit (1 to " << song_count << "): ";
        cin >> index;
        cin.ignore(); // Clear the newline character from the input buffer

        if (index < 1 || index > song_count) {
            cout << "Invalid song number!" << endl;
            return;
        }

        cout << "Editing song " << index << ":" << endl;

        cout << "New Title: ";
        getline(cin, titles[index - 1]);

        cout << "New Artist: ";
        getline(cin, artists[index - 1]);

        cout << "New Album: ";
        getline(cin, albums[index - 1]);

        cout << "New Duration: ";
        getline(cin, durations[index - 1]);

        cout << "New Filepath: ";
        getline(cin, filepaths[index - 1]);

        cout << "Song updated!" << endl;
    }

    void delete_song() {
        if (song_count == 0) {
            cout << "No songs available to delete." << endl;
            return;
        }

        int index;
        cout << "Enter the song number you want to delete (1 to " << song_count << "): ";
        cin >> index;
        cin.ignore(); 

        if (index < 1 || index > song_count) {
            cout << "Invalid song number!" << endl;
            return;
        }

        // Shift the remaining songs up to fill the gap
        for (int i = index - 1; i < song_count - 1; ++i) {
            titles[i] = titles[i + 1];
            artists[i] = artists[i + 1];
            albums[i] = albums[i + 1];
            durations[i] = durations[i + 1];
            filepaths[i] = filepaths[i + 1];
        }

        song_count--;
        cout << "Song deleted!" << endl;
    }

    void display_songs() const {
        if (song_count == 0) {
            cout << "No songs to display." << endl;
            return;
        }

        for (int i = 0; i < song_count; ++i) {
            cout << "\nSong " << i + 1 << ":" << endl;
            cout << "Title: " << titles[i] << endl;
            cout << "Artist: " << artists[i] << endl;
            cout << "Album: " << albums[i] << endl;

            cout << "Duration: " << durations[i] << endl;
            cout << "Filepath: " << filepaths[i] << endl;
            cout << "---------------------------" << endl;
        }
    }
};

int main() {
    musician m;
    int choice;

    do {
        cout << "\nMenu:\n1. Add Song\n2. Edit Song\n3. Delete Song\n4. Display Songs\n5. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore(); 
        switch (choice) {
            case 1:
                m.add_song();
                break;
            case 2:
                m.edit_song();
                break;
            case 3:
                m.delete_song();
                break;
            case 4:
                m.display_songs();
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
                break;
        }
    } while (choice != 5);

    return 0;
}
