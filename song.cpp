#include <iostream>
#include <string>
using namespace std;

class Song {
protected:
    string title;
    string artist;
    string album;
    string duration;
    string filepath;

public:
   
    Song(string tit, string art, string albu, string dur, string file)
        : title(tit), artist(art), album(albu), duration(dur), filepath(file) {}

    ~Song() {}

    
    void play() {
        cout << "Playing: " << title << " by " << artist << endl;
    }

    void pause() {
        cout << "Paused: " << title << endl;
    }

    void display() {
        cout << "Title: " << title << "\nBy: " << artist << "\nAlbum: " << album
             << "\nDuration: " << duration << "\nFilepath: " << filepath << endl;
    }

  

    
    string getTitle() const { return title; }
};

int main() {
    string title, artist, album, duration, filepath;
    int choice;

  
    cout << "Enter the title of the song: ";
    getline(cin, title);
    cout << "Enter the artist of the song: ";
    getline(cin, artist);
    cout << "Enter the album name: ";
    getline(cin, album);
    cout << "Enter the duration of the song: ";
    getline(cin, duration);
    cout << "Enter the filepath: ";
    getline(cin, filepath);

 
    Song s(title, artist, album, duration, filepath);

    do {
        cout << "\nEnter a choice (1: Play, 2: Pause, 3: Display, 4: Exit): ";
      getline(cin,choice);
      

        switch (choice) {
            case 1:
                s.play();
                break;
            case 2:
                s.pause();
                break;
            case 3:
                s.display();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4." << endl;
                break;
        }
    } while (choice != 4);

    return 0;
}
