#include <iostream>
#include <string>

#include "UtPod.h"
#include "Song.cpp"
#include "Song.h"

using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY;
    songs = NULL;
}

UtPod::UtPod(int size) {
    if((size <= 0) || (size > MAX_MEMORY)) {
        memSize = MAX_MEMORY;
    }
    else {
        memSize = size;
    }

    songs = NULL;
}

int UtPod::addSong(Song const *s) {
    if(s->getSize() > getRemainingMemory()) {
        s->next = songs->next;
        songs->next = s;
        return SUCCESS;
    }
    else {
        return NO_MEMORY;
    }
}

int UtPod::removeSong(Song const &s) {
    int removalFlag = 0;     //checks if songs has been removed
    struct SongNode *previous = songs;
    struct SongNode *current = songs->next;

    if(current == NULL) {     //checks if song list is empty
        return -1;
    }
    else {
        if(songs->s->title == s->title) {    //checks if head is requested removal
            struct SongNode *ptr;
            ptr = songs;
            songs = songs->next;
            delete ptr;
            return SUCCESS;
        }

        while(current != NULL) {      //head is not song and list is not empty
            if(current->s->title == s->title) {
                previous->next = current->next;
                delete current;
                return SUCCESS;
            }
        }
        return -1;      //unsuccessful removal
    }
}

void UtPod::shuffle() {
    if(songs != NULL) {                //filter empty UtPod
        if(songs->next != NULL) {    //filter one-song UtPod
            int length = 0;
            struct SongNode* ptrSplit = songs;
            while(ptrSplit != NULL) {
                length++;
                ptrSplit = ptrSplit->next;
            }

            for(int i = 0; i < length/2; i++) {
                ptrSplit = ptrSplit->next;
            }

            struct SongNode* ptrHead = songs;
            struct SongNode* ptrHeadAdvance = ptrHead;
            struct SongNode* ptrSplitAdvance = ptrSplit;

            while(ptrHead != NULL) {             //interleaving loop
                ptrHeadAdvance = ptrHead->next;
                ptrSplitAdvance = ptrSplit->next;

                ptrHead->next = ptrSplit;
                ptrSplit->next = ptrHeadAdvance;

                ptrHead = ptrHeadAdvance;
                ptrSplit = ptrSplitAdvance;
            }

            if(ptrSplit != NULL) {
                ptrHead->next = ptrSplit;    //connects final song to NULL if even num songs
            }
        }
    }
}

void UtPod::showSongList() {
    if(songs == NULL) {
        cout << "There are no songs on the UtPod." << endl;
    }
    else{
        SongNode *ptr;
        while(ptr != NULL) {
            cout << ptr->s->title << ", " << ptr->s->artist << ", " << ptr->size << " MB" << endl;
            ptr = ptr->next;
        }
    }
}

void UtPod::sortSongList() {
    //save for later
}

void UtPod::clearMemory() {
    if((songs != NULL) && (songs->next == NULL)) {    //only one song on UtPod
        delete songs;
    }
    else if((songs != NULL)) {            //several songs on UtPod
        SongNode *previous = songs;
        SongNode *current = songs->next;
        while(current != NULL) {
            delete previous;
            previous = current;
            current = current->next;
        }
        delete previous;     //deletes last song before NULL
    }
}

int UtPod::getTotalMemory() {
    return memSize;
}

int UtPod::getRemainingMemory() {
    if(songs == NULL) {      //UtPod is empty
        return memSize;
    }
    else {
        SongNode *ptr;
        int sizeUsed = 0;
        while(ptr != NULL) {
            sizeUsed =  sizeUsed + ptr->s->size;
        }
        return (memSize - sizeUsed);
    }
}

UtPod::~UtPod() {
    clearMemory();
}
