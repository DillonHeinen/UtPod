#include <iostream>
#include <string>
#include <ctime>
#include "UtPod.h"

using namespace std;

UtPod::UtPod() {                                  //in working order
    memSize = MAX_MEMORY;
    songs = NULL;
    srand(time(0));
}

UtPod::UtPod(int size) {                          //in working order
    if((size <= 0) || (size > MAX_MEMORY)) {
        memSize = MAX_MEMORY;
    }
    else {
        memSize = size;
    }

    songs = NULL;
    srand(time(0));
}

int UtPod::addSong(Song &newSong) {                      //in working order
    if(newSong.getSize() <= getRemainingMemory()) {
        struct SongNode* temp = new struct SongNode;
        if(songs == NULL) {
            temp->next = NULL;
        }
        else {
            temp->next = songs;
        }
        songs = temp;
        temp->s.setTitle(newSong.getTitle());
        temp->s.setArtist(newSong.getArtist());
        temp->s.setSize(newSong.getSize());
        return SUCCESS;
    }
    else {
        return NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s) {                  //in working order
    struct SongNode *previous = songs;
    if(previous == NULL) {     //checks if song list is empty
        return -1;
    }
    struct SongNode *current = songs->next;

    if(songs->s.getTitle() == s.getTitle()) {    //checks if head is requested removal
        struct SongNode *ptr;
        ptr = songs;
        songs = songs->next;
        delete ptr;
        return SUCCESS;
    }

    while(current != NULL) {      //head is not song and list is not empty
        if(current->s.getTitle() == s.getTitle()) {
            previous->next = current->next;
            delete current;
            return SUCCESS;
        }
        else {
            current = current->next;
            previous = previous->next;
        }
    }
    return -1;      //unsuccessful removal
}

void UtPod::shuffle() {
    int length = 0;
    struct SongNode* ptr = songs;
    while(ptr != NULL) {           //get number of songs in linked list
        length++;
        ptr = ptr->next;
    }
    struct SongNode *switch1;
    struct SongNode *switch2;

    for(int i = 0; i < length*2; i++) {
        switch1 = songs;
        switch2 = songs;

        long num1 = (rand() % length) + 1;
        long num2 = (rand() % length) + 1;

        while(num1 != 0) {
            switch1 = switch1->next;
            num1--;
        }
        while(num2 != 0) {
            switch2 = switch2->next;
            num2--;
        }
        swap(switch1, switch2);
    }
}

void UtPod::showSongList() {                    //in working order
    if(songs == NULL) {
        cout << "There are no songs on the UtPod." << endl;
    }
    else{
        struct SongNode *ptr;
        ptr = songs;
        while(ptr != NULL) {
            cout << ptr->s.getTitle() << ", " << ptr->s.getArtist() << ", " << ptr->s.getSize() << " MB" << endl;
            ptr = ptr->next;
        }
    }
}

void UtPod::swap(struct SongNode* currentSong, struct SongNode* nextSong) {           //in working order
    Song temp = nextSong->s;
    nextSong->s = currentSong->s;
    currentSong->s = temp;
}

void UtPod::sortSongList() {                    //in working order
    if((songs != NULL) && (songs->next != NULL)) {                //filter out cases where less than 2 songs in UtPod
        struct SongNode* index = songs;
        while(index != NULL) {
            struct SongNode *currentSong = songs;
            struct SongNode *nextSong = songs->next;
            while (nextSong != NULL) {
                if (currentSong->s > nextSong->s) {
                    swap(currentSong, nextSong);
                }
                currentSong = nextSong;
                nextSong = nextSong->next;
            }
            index = index->next;
        }
    }
}

void UtPod::clearMemory() {                           //in working order
    if((songs != NULL) && (songs->next == NULL)) {    //only one song on UtPod
        delete songs;
        songs = NULL;
    }
    else if((songs != NULL)) {            //several songs on UtPod
        struct SongNode *previous = songs;
        struct SongNode *current = songs->next;
        while(current != NULL) {
            delete previous;
            previous = current;
            current = current->next;
        }
        delete previous;     //deletes last song before NULL
        songs = NULL;
    }
}

int UtPod::getTotalMemory() {            //in working order
    return memSize;
}

int UtPod::getRemainingMemory() {        //in working order
    if(songs == NULL) {      //UtPod is empty
        return memSize;
    }
    else {
        struct SongNode *ptr = songs;
        int sizeUsed = 0;
        while(ptr != NULL) {
            sizeUsed =  sizeUsed + ptr->s.getSize();
            ptr = ptr->next;
        }
        return (memSize - sizeUsed);
    }
}

UtPod::~UtPod() {                       //in working order
    clearMemory();
}
