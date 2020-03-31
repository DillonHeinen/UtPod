#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Beatles", "Hey Jude1", 4);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    cout << endl;

    t.showSongList();

    t.shuffle();

    cout << endl;

    Song s2("Beatles", "Hey Jude2", 5);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    cout << endl;

    t.showSongList();

    cout << endl;

    Song s3("Beatles", "Hey Jude3", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Beatles", "Hey Jude4", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Beatles", "Hey Jude5", 241);
    result = t.addSong(s5);
    cout << "add result = " << result << endl;

    cout << endl;

    t.showSongList();

    t.sortSongList();

    cout << endl;

    t.showSongList();

    cout << endl;

    t.showSongList();

    cout << endl;

    result = t.removeSong(s2);
    cout << "delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << "delete result = " << result << endl;

    cout << endl;

    t.showSongList();

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
    cout << t.getRemainingMemory() << endl;

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

}
