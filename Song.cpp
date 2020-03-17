#include <iostream>
#include <string>

#include "Song.h"

using namespace std;

Song::Song(string a, string t, int s) {
	size = s;
	title = t
	artist = a;	
}

string Song::getTitle() {
	return title;
}

void Song::setTitle(string t) {
	title = t;
}

string Song::getArtist() {
	return artist;
}

void Song::setArtist(string a) {
	artist = a;
}

int Song::getSize() {
	return size;
}

void Song::setSize(int s) {
	size = s;
}
