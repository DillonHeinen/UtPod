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

}

bool Song::operator==(const Song &rhs) {
    if((rhs.getArtist() == this->getArtist()) &&
       (rhs.getTitle() == this->getTitle())   &&
       (rhs.getSize() == this->getSize())) {
        return true;
    }
    else {
        return false;
    }
}

bool Song::operator<(const Song &rhs) {
    if (rhs.getArtist() > this->getArtist()) {
        return true;
    }
    else if(rhs.getArtist() < this-> getArtist()) {
        return false;
    }
    else if(rhs.getTitle() > this->getTitle()) {
        return true;
    }
    else if(rhs.getTitle() < this->getTitle()) {
        return false;
    }
    else if(rhs.getSize() > this->getSize()) {
        return true;
    }
    else if(rhs.getSize() < this->getSize()) {
        return false;
    }
    else{
        return false;
    }
}

bool Song::operator>(const Song &rhs) {
    if(rhs.getArtist() < this->getArtist()) {
        return true;
    }
    else if(rhs.getArtist() > this->getArtist()) {
        return false;
    }
    else if(rhs.getTitle() < this->getTitle()) {
        return true;
    }
    else if(rhs.getTitle() > this->getTitle()) {
        return false;
    }
    else if(rhs.getSize() < this->getSize()) {
        return true;
    }
    else if(rhs.getSize() > this->getSize()) {
        return false;
    }
    else {
        return false;
    }
}
