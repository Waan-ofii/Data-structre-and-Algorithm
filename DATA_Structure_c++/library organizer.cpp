#include <iostream>
#include <string>
using namespace std;

const int MAX_SONGS = 10;

struct SongNode {
    string artist;
    string songs[MAX_SONGS];
    int songCount = 0;
    SongNode* left = nullptr;
    SongNode* right = nullptr;
};

class MusicLibrary {
private:
    SongNode* root;

    void insert(SongNode* &node, const string &title, const string &artist) {
        if (!node) {
            node = new SongNode{artist};
            node->songs[0] = title;
            node->songCount = 1;
        } else if (artist < node->artist) {
            insert(node->left, title, artist);
        } else if (artist > node->artist) {
            insert(node->right, title, artist);
        } else {
            
            for (int i = 0; i < node->songCount; ++i) {
                if (node->songs[i] == title) {
                    cout << "Song already exists for this artist.\n";
                    return;
                }
            }
            if (node->songCount < MAX_SONGS) {
                node->songs[node->songCount++] = title;
            } else {
                cout << "Maximum number of songs reached for artist.\n";
            }
        }
    }

    void inOrder(SongNode* node) {
        if (node) {
            inOrder(node->left);
            cout<<"\nArtist: ";
            cout << node->artist << "\n";
            cout<<"songs: \n";
            for (int i = 0; i < node->songCount; ++i)
                cout << node->songs[i] << endl;
            inOrder(node->right);
        }
    }

    bool searchArtist(SongNode* node, const string &artist) {
        if (!node) return false;
        if (node->artist == artist) return true;
        if (artist < node->artist)
            return searchArtist(node->left, artist);
        return searchArtist(node->right, artist);
    }

    SongNode* findArtist(SongNode* node, const string& artist) {
        if (!node) return nullptr;
        if (node->artist == artist) return node;
        if (artist < node->artist)
            return findArtist(node->left, artist);
        return findArtist(node->right, artist);
    }

    void deleteSong(SongNode* node, const string& title) {
        int index = -1;
        for (int i = 0; i < node->songCount; ++i) {
            if (node->songs[i] == title) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << " Song not found for this artist.\n";
            return;
        }

        for (int i = index; i < node->songCount - 1; ++i)
            node->songs[i] = node->songs[i + 1];
        node->songCount--;

        cout << " Song \"" << title << " removed from \"" << node->artist << "\".\n";
    }

    void destroy(SongNode* node) {
        if (node) {
            destroy(node->left);
            destroy(node->right);
            delete node;
        }
    }

public:
    MusicLibrary() : root(nullptr) {}
    ~MusicLibrary() { destroy(root); }

    void addSong(const string &title, const string &artist) {
        insert(root, title, artist);
    }

    void searchArtist(const string &artist) {
        if (searchArtist(root, artist))
            cout << " Found artist " << artist << "\n";
        else
            cout << artist << " not found.\n";
    }

    void listSongs() {
        cout << " Music Library:\n";
        inOrder(root);
    }

    void removeSongFromArtist(const string &title, const string &artist) {
        SongNode* node = findArtist(root, artist);
        if (!node) {
            cout << "Artist" << artist << "not found.\n";
            return;
        }
        deleteSong(node, title);
    }

    void playSong(const string& title, const string& artist) {
    SongNode* node = findArtist(root, artist);
    if (!node) {
        cout << "Artist " << artist << " not found.\n";
        return;
    }

    for (int i = 0; i < node->songCount; ++i) {
        if (node->songs[i] == title) {
            cout << " playing: " << title << " by " << artist << "\n";
            return;
        }
    }

    cout << "Song " << title << " not found for artist " << artist << "\n";
}

};

int main() {
    MusicLibrary lib;
    int choice;
    string title, artist;

    while(true) {
        cout << "\n Music Library Menu ";
        cout << "\n1. Add Song";
        cout << "\n2. Remove a Song of an Artist";
        cout << "\n3. Search Artist";
        cout << "\n4. List All Songs";
        cout << "\n5. Play a Song";
        cout << "\n0. Exit";
        cout << "\nChoose: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter song title: ";
                getline(cin, title);
                cout << "Enter artist name: ";
                getline(cin, artist);
                lib.addSong(title, artist);
                break;
            case 2:
                cout << "Enter artist name: ";
                getline(cin, artist);
                cout << "Enter song title to remove: ";
                getline(cin, title);
                lib.removeSongFromArtist(title, artist);
                break;
            case 3:
                cout << "Enter artist name to search: ";
                getline(cin, artist);
                lib.searchArtist(artist);
                break;
            case 4:
                lib.listSongs();
                break;
            case 5:
                cout << "Enter artist name: ";
                getline(cin, artist);
                cout << "Enter song title to play: ";
                getline(cin, title);
                lib.playSong(title, artist);
                break;
            case 0:
                cout << "program exited\n";
                break;
            default:
                cout << "Invalid option!\n";
        }
    } 

    return 0;
}

