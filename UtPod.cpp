#include <iostream>
#include <string>
#include "UtPod.h"

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

int UtPod::addSong(Song &newSong) {
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

int UtPod::removeSong(Song const &s) {
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
    if(songs != NULL) {                //filter empty UtPod
        if(songs->next != NULL) {    //filter one-song UtPod
            int length = 0;
            struct SongNode* ptrSplit = songs;
            while(ptrSplit != NULL) {
                length++;
                ptrSplit = ptrSplit->next;
            }

            ptrSplit = songs;
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
        struct SongNode *ptr;
        ptr = songs;
        while(ptr != NULL) {
            cout << ptr->s.getTitle() << ", " << ptr->s.getArtist() << ", " << ptr->s.getSize() << " MB" << endl;
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
        struct SongNode *previous = songs;
        struct SongNode *current = songs->next;
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
        struct SongNode *ptr = songs;
        int sizeUsed = 0;
        while(ptr != NULL) {
            sizeUsed =  sizeUsed + ptr->s.getSize();
            ptr = ptr->next;
        }
        return (memSize - sizeUsed);
    }
}

UtPod::~UtPod() {
    clearMemory();
}
