#ifndef SONG
#define SONG
#include <string>

using namespace std;

class Song {
private:
    int size;
    string title;
    string artist;

public:
    Song();
    Song(string a, string t, int s);

    string getTitle() const;
    void setTitle(string t);

    string getArtist() const;
    void setArtist(string a);

    int getSize() const;
    void setSize(int s);

    ~Song();

    //operator overloading functions
    bool operator==(const Song &rhs);
    bool operator<(const Song &rhs);
    bool operator>(const Song &rhs);
};

#endif
