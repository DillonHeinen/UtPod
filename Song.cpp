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

Song::~Song() {
    //remains empty because songs do not dynamically allocated memory
}

bool Song::operator==(const Song &rhs) {
    return (rhs.artist == this->artist) &&
           (rhs.title == this->title) &&
           (rhs.size == this->size);
}

bool Song::operator<(const Song &rhs) {
    if (rhs.artist > this->artist) {
        return true;
    }
    else if(rhs.artist < this->artist) {
        return false;
    }
    else if(rhs.title > this->title) {
        return true;
    }
    else if(rhs.title < this->title) {
        return false;
    }
    else if(rhs.size > this->size) {
        return true;
    }
    else if(rhs.size < this->size) {
        return false;
    }
    else{
        return false;
    }
}

bool Song::operator>(const Song &rhs) {
    if(rhs.artist < this->artist) {
        return true;
    }
    else if(rhs.artist > this->artist) {
        return false;
    }
    else if(rhs.title < this->title) {
        return true;
    }
    else if(rhs.title > this->title) {
        return false;
    }
    else if(rhs.size < this->size) {
        return true;
    }
    else if(rhs.size > this->size) {
        return false;
    }
    else {
        return false;
    }
}
