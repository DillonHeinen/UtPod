#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod a;
    UtPod b(256);
    UtPod c(0);
    UtPod d(513);
    UtPod e(-1);
    int result = a.getTotalMemory();
    cout << "Total memory of UtPod a = "<< result << endl;

    result = b.getTotalMemory();
    cout << "Total memory of UtPod b = "<< result << endl;

    result = c.getTotalMemory();
    cout << "Total memory of UtPod c = "<< result << endl;

    result = d.getTotalMemory();
    cout << "Total memory of UtPod d = "<< result << endl;

    result = e.getTotalMemory();
    cout << "Total memory of UtPod e = "<< result << endl;

    cout << endl;

    Song s1;                            //creating song using default constructor with size 1
    s1.setTitle("Title1");
    s1.setArtist("Artist1");
    s1.setSize(1);

    string title = s1.getTitle();
    string artist = s1.getArtist();
    int size = s1.getSize();

    cout << "s1 title = " << title << endl;
    cout << "s1 artist = " << artist << endl;
    cout << "s1 size = " << size << endl << endl;

    Song s2("Artist2","Title2",2);      //creating song with size 2

    title = s2.getTitle();
    artist = s2.getArtist();
    size = s2.getSize();

    cout << "s2 title = " << title << endl;
    cout << "s2 artist = " << artist << endl;
    cout << "s2 size = " << size << endl << endl;

    Song s3("Artist3","Title3",512);    //creating a song with size 512

    title = s3.getTitle();
    artist = s3.getArtist();
    size = s3.getSize();

    cout << "s3 title = " << title << endl;
    cout << "s3 artist = " << artist << endl;
    cout << "s3 size = " << size << endl << endl;

    Song s4("Artist4","Title4",0);      //creating a song with size 0

    title = s4.getTitle();
    artist = s4.getArtist();
    size = s4.getSize();

    cout << "s4 title = " << title << endl;
    cout << "s4 artist = " << artist << endl;
    cout << "s4 size = " << size << endl << endl;

    Song s5("Artist5","Title5",5);
    Song s6("Artist6","Title6",6);
    Song s7("Artist7","Title7",7);
    Song s8("Artist8","Title8",8);

    cout << "adding Song s1 to UtPod a..." << endl;
    result = a.addSong(s1);
    if(result == 0){
        cout << "addition was a success" << endl << endl;
    }
    else if(result == -1){
        cout << "addition failed: not enough memory to add song" << endl << endl;
    }

    cout << "adding Song s2 to UtPod a..." << endl;
    result = a.addSong(s2);
    if(result == 0){
        cout << "addition was a success" << endl << endl;
    }
    else if(result == -1){
        cout << "addition failed: not enough memory to add song" << endl << endl;
    }

    a.showSongList();

    result = a.getTotalMemory();
    cout << endl << "total memory in UtPod a = " << result << "MB" << endl;

    result = a.getRemainingMemory();
    cout << "remaining memory in UtPod a = " << result << "MB" << endl << endl;

    cout << "adding Song s5 to UtPod a..." << endl;
    result = a.addSong(s5);
    if(result == 0){
        cout << "addition was a success" << endl << endl;
    }
    else if(result == -1){
        cout << "addition failed: not enough memory to add song" << endl << endl;
    }

    cout << "adding Song s6 to UtPod a..." << endl;
    result = a.addSong(s6);
    if(result == 0){
        cout << "addition was a success" << endl << endl;
    }
    else if(result == -1){
        cout << "addition failed: not enough memory to add song" << endl << endl;
    }

    cout << "adding Song s7 to UtPod a..." << endl;
    result = a.addSong(s7);
    if(result == 0){
        cout << "addition was a success" << endl << endl;
    }
    else if(result == -1){
        cout << "addition failed: not enough memory to add song" << endl << endl;
    }

    cout << "adding Song s8 to UtPod a..." << endl;
    result = a.addSong(s8);
    if(result == 0){
        cout << "addition was a success" << endl << endl;
    }
    else if(result == -1){
        cout << "addition failed: not enough memory to add song" << endl << endl;
    }

    a.showSongList();

    result = a.getTotalMemory();
    cout << endl << "total memory in UtPod a = " << result << "MB" << endl;

    result = a.getRemainingMemory();
    cout << "remaining memory in UtPod a = " << result << "MB" << endl << endl;

    cout << "sorting UtPod a.." << endl << endl;
    a.sortSongList();

    a.showSongList();

    cout << endl << "shuffling UtPod a..." << endl << endl;
    a.shuffle();

    a.showSongList();

    cout << endl << "sorting UtPod a.." << endl << endl;
    a.sortSongList();

    a.showSongList();

    cout << endl << "adding Song s3 to UtPod a..." << endl;
    result = a.addSong(s3);
    if(result == 0){
        cout << "addition was a success" << endl << endl;
    }
    else if(result == -1){
        cout << "addition failed: not enough memory to add song" << endl;
        cout << "remaining memory = " << a.getRemainingMemory() << "MB" << endl;
        cout << "s3 size = " << s3.getSize() << "MB" << endl << endl;
    }

    a.showSongList();

    cout << endl << "removing Song s1 from UtPod a..." << endl;
    result = a.removeSong(s1);
    if(result == 0){
        cout << "removal was a success" << endl << endl;
    }
    else if(result == -2){
        cout << "removal failed: Song s1 not found in UtPod a" << endl << endl;
    }

    cout << "removing Song s8 from UtPod a..." << endl;
    result = a.removeSong(s8);
    if(result == 0){
        cout << "removal was a success" << endl << endl;
    }
    else if(result == -2){
        cout << "removal failed: Song s1 not found in UtPod a" << endl << endl;
    }

    cout << "removing Song s3 from UtPod a..." << endl;
    result = a.removeSong(s3);
    if(result == 0){
        cout << "removal was a success" << endl << endl;
    }
    else if(result == -2){
        cout << "removal failed: Song s1 not found in UtPod a" << endl << endl;
    }

    a.showSongList();

    cout << endl << "remaining memory in UtPod a = " << a.getRemainingMemory() << endl << endl;

    cout << "clearing memory of UtPod a..." << endl;
    a.clearMemory();
    cout << "remaining memory in UtPod a = " << a.getRemainingMemory() << endl;
    
}    

    /*
    UtPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "add result = " << result << endl;

    cout << endl;

    t.showSongList();

    t.shuffle();

    cout << endl;

    t.showSongList();

    cout << endl;

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "add result = " << result << endl;

    cout << endl;

    t.showSongList();

    t.shuffle();

    cout << endl;

    t.showSongList();

    cout << endl;

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "add result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "add result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    cout << endl;

    t.showSongList();       //show song list -- 5 Songs

    t.sortSongList();       //Sort and show song list -- 5 Songs
                            //
    cout << endl;           //
                            //
    t.showSongList();       //

    cout << endl;

    t.shuffle();            //Shuffle and show song list -- 5 songs
                            //
    cout << endl;           //
                            //
    t.showSongList();       //

    cout << endl;

    t.sortSongList();       //Sort shuffled song list and show -- 5 songs
                            //
    cout << endl;           //
                            //
    t.showSongList();       //

    cout << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    cout << endl;

    t.showSongList();       //show songs after deleting 2 -- 3 Songs

    cout << endl;

    t.shuffle();            //shuffle and show songs -- 3 songs
                            //
    t.showSongList();       //

    cout << endl;

    t.sortSongList();       //sort and show songs -- 3 songs
                            //
    t.showSongList();       //

    cout << endl;

    result = t.removeSong(s1);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s5);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << "delete result = " << result << endl;

    cout << endl;

    t.showSongList();

    cout << endl;

    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    cout << endl;

    t.showSongList();
    cout << "memory = " << t.getRemainingMemory() << endl;
    t.addSong(s5);
    cout << "memory = " << t.getRemainingMemory() << endl;

    cout << endl;

    t.clearMemory();
    t.showSongList();

    Song s6("Beatles", "Yellow Submarine", 16);
    Song s7("Beatles", "Yellow Submarine", 16);

    bool result2 = s3 < s6;
    cout << result2 << endl;

    result2 = s6 > s7;
    cout << result2 << endl;

    result2 = s6 == s7;
    cout << result2 << endl;

    cout << t.getTotalMemory() << endl;
    */
