#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class song {
private:
    string title;
    string artist;
    string album;
    string duration;
    string filepath;

public:
    song(string t = "", string a = "", string al = "", string d = "", string fp = "")
        : title(t), artist(a), album(al), duration(d), filepath(fp) {}

    void play() const {
        cout << "Playing: " << title << " by " << artist << endl;
    }

    void pause() const {
        cout << "Pausing: " << title << endl;
    }

    void displayinfo() const {
        cout << "Title: " << title << endl;
        cout << "Artist: " << artist << endl;
        cout << "Album: " << album << endl;
        cout << "Duration: " << duration << " minutes" << endl;
        cout << "File Path: " << filepath << endl;
    }

    void savetofile(const string &filename) const {
        ofstream outfile(filename);
        if (outfile.is_open()) {
            outfile << "Title: " << title << endl;
            outfile << "Artist: " << artist << endl;
            outfile << "Album: " << album << endl;
            outfile << "Duration: " << duration << " minutes" << endl;
            outfile << "File Path: " << filepath << endl;
            outfile.close();
            cout << "Song information saved to " << filename << endl;
        } else {
            cout << "Unable to open file for writing." << endl;
        }
    }

    void loadfromfile(const string &filename) {
        ifstream infile(filename);
        if (infile.is_open()) {
            string line;
            getline(infile, line); 
            title = line.substr(line.find(":") + 2);

            getline(infile, line); /
            artist = line.substr(line.find(":") + 2);

            getline(infile, line); 
            album = line.substr(line.find(":") + 2);

            getline(infile, line); 
            duration = line.substr(line.find(":") + 2);
            
            getline(infile, line);
            filepath = line.substr(line.find(":") + 2);

            infile.close();
            cout << "Song information loaded from " << filename << endl;
        } else {
            cout << "Unable to open file for reading." << endl;
        }
    }
};

int main() {
    string filename;

    cout << "Enter the filename to load song information from: ";
    getline(cin, filename);

    string title, artist, album, filepath, duration;

    cout << "Enter song title: ";
    getline(cin, title);
    cout << "Enter artist name: ";
    getline(cin, artist);
    cout << "Enter album name: ";
    getline(cin, album);
    cout << "Enter song duration (in minutes): ";
    getline(cin, duration);
    cout << "Enter file path: ";
    getline(cin, filepath);

    song mysong(title, artist, album, duration, filepath);
    mysong.savetofile(filename);

    int choice;

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Play Song\n";
        cout << "2. Pause Song\n";
        cout << "3. Display Song Info\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1:
                mysong.play();
                break;
            case 2:
                mysong.pause();
                break;
            case 3:
                mysong.displayinfo();
                break;
            case 4:
                cout << "Exiting. Enjoy!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    song anothersong;
    anothersong.loadfromfile(filename);

    return 0;
}
