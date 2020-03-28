#include <iostream>
#include <string>

#include "Song.h"

using namespace std;

Song::Song() {
    size = 0;
    title = "";
    artist = "";
}

Song::Song(string a, string t, int s) {
    size = s;
    title = t;
    artist = a;
}

string Song::getTitle() const {
    return title;
}

void Song::setTitle(string t) {
    title = t;
}

string Song::getArtist() const {
    return artist;
}

void Song::setArtist(string a) {
    artist = a;
}

int Song::getSize() const {
    return size;
}

void Song::setSize(int s) {
    size = s;
}
