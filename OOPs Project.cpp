#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <string>
using namespace std;

class Song
{
private:
    int id;
    string title;
    string artist;
    string album;
    string genre;
    double duration;

public:
    Song() {}
    Song(int i, string t, string a, string al, string g, double d)
        : id(i), title(t), artist(a), album(al), genre(g), duration(d) {}

    int getId() const { return id; }
    string getTitle() const { return title; }
    string getArtist() const { return artist; }
    string getAlbum() const { return album; }
    string getGenre() const { return genre; }
    double getDuration() const { return duration; }

    void display() const
    {
        cout << "\n---------------------------------------";
        cout << "\nID: " << id;
        cout << "\nTitle: " << title;
        cout << "\nArtist: " << artist;
        cout << "\nAlbum: " << album;
        cout << "\nGenre: " << genre;
        cout << "\nDuration: " << duration << " mins";
        cout << "\n---------------------------------------\n";
    }

    string toFileFormat() const
    {
        return to_string(id) + "|" + title + "|" + artist + "|" + album + "|" + genre + "|" + to_string(duration);
    }
};

// ------------------- LIBRARY CLASS -------------------
class Library
{
private:
    vector<Song> songs;
    int nextId = 1;

public:
    void addSong()
    {
        string title, artist, album, genre;
        double duration;

        cout << "\nEnter Song Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Artist Name: ";
        getline(cin, artist);
        cout << "Enter Album Name: ";
        getline(cin, album);
        cout << "Enter Genre: ";
        getline(cin, genre);
        cout << "Enter Duration (in minutes): ";
        cin >> duration;

        songs.push_back(Song(nextId++, title, artist, album, genre, duration));
        cout << "\nSong added successfully!\n";
    }

    void displayAll() const
    {
        if (songs.empty())
        {
            cout << "\nNo songs available.\n";
            return;
        }
        cout << "\nAll Songs in Library:\n";
        for (const auto &s : songs)
        {
            s.display();
        }
    }

    void searchByTitle() const
    {
        string keyword;
        cout << "\nEnter title to search: ";
        cin.ignore();
        getline(cin, keyword);

        bool found = false;
        for (const auto &s : songs)
        {
            if (s.getTitle() == keyword)
            {
                s.display();
                found = true;
            }
        }
        if (!found)
            cout << "\nNo song found with that title.\n";
    }

    void removeSong()
    {
        int id;
        cout << "\nEnter song ID to delete: ";
        cin >> id;

        auto it = remove_if(songs.begin(), songs.end(),
                            [id](const Song &s)
                            { return s.getId() == id; });

        if (it != songs.end())
        {
            songs.erase(it, songs.end());
            cout << "\nSong removed successfully!\n";
        }
        else
        {
            cout << "\nNo song found with that ID.\n";
        }
    }

    void saveToFile(const string &filename) const
    {
        ofstream file(filename);
        for (const auto &s : songs)
        {
            file << s.toFileFormat() << endl;
        }
        cout << "\nLibrary saved to file successfully!\n";
    }

    void loadFromFile(const string &filename)
    {
        ifstream file(filename);
        if (!file)
            return;

        songs.clear();
        string line;
        while (getline(file, line))
        {
            int id;
            string title, artist, album, genre;
            double duration;
            replace(line.begin(), line.end(), '|', ' ');
            stringstream ss(line);
            ss >> id >> ws;
            getline(ss, title, ' ');
            getline(ss, artist, ' ');
            getline(ss, album, ' ');
            getline(ss, genre, ' ');
            ss >> duration;
            songs.push_back(Song(id, title, artist, album, genre, duration));
            nextId = id + 1;
        }
    }
};

// ------------------- MAIN FUNCTION -------------------
int main()
{
    Library lib;
    const string filename = "songs.txt";
    lib.loadFromFile(filename);

    int choice;
    do
    {
        cout << "\n=========  MUSIC MANAGEMENT SYSTEM  =========";
        cout << "\n1. Add Song";
        cout << "\n2. View All Songs";
        cout << "\n3. Search Song by Title";
        cout << "\n4. Delete Song";
        cout << "\n5. Save Library";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            lib.addSong();
            break;
        case 2:
            lib.displayAll();
            break;
        case 3:
            lib.searchByTitle();
            break;
        case 4:
            lib.removeSong();
            break;
        case 5:
            lib.saveToFile(filename);
            break;
        case 6:
            cout << "\nExiting Music Management System...\n";
            break;
        default:
            cout << "\nInvalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}