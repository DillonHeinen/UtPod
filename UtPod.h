class UtPod {
   private:
	static const int MAX_MEMORY = 512;
	static const int SUCCESS = 0;
	static const int NO_MEMORY = -1;
	static const int NOT_FOUND = -2;

	struct SongNode {      //linked list for song list
		song s;
		SongNode* next;
	} SongNode;
	
	SongNode* songs;     //head pointer

	int memSize;	
	
   public:
	UtPod();    //default constructor
	
	UtPod(int size);

	int addSong(Song const *s);

	int removeSong(Song const *s);

	void shuffle();

	void showSongList();

	void sortSongList();

	void clearMemory();

	int getTotalMemory();

	int getRemainingMemory();

	~UtPod();     //deconstructor
};
