#ifndef MUSICTREE_H
#define MUSICTREE_H

#include <vector>
#include <iostream>

struct MusicNode{
    int rating;
    std::string title;
    std::string length;
    std::string artist;
    MusicNode *parent;
    MusicNode *leftChild;
    MusicNode *rightChild;

    MusicNode(){};

    MusicNode(int inRating, std::string inTitle, std::string inArtist, std::string inLength)
    {
        rating = inRating;
        title = inTitle;
        artist = inArtist;
        length = inLength;
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }
};

class MusicTree
{

    public:
        MusicTree();
        ~MusicTree();
        void insertMusicNode(int rating, std::string title, std::string artist, std::string length, int tree);
        void songPrintAZ(int tree);
        void deleteMusicNode(std::string title, int tree);
        void findSong(std::string title, int tree);
        void addSongToPlaylist(std::string title, int tree);
        void createAPlaylist(std::string name);
        void PlaylistGetter();
        int PlaylistIndex(std::string name);
        void PlaylistSetter(std::string current, std::string New);
        int countSongs(int tree);



    protected:

    private:
        bool searchTree(std::string title, int tree);
        void printMusicAZ(MusicNode * node);
        int CountSongs(MusicNode *Node);
        std::vector <std::string> Playlists;
        MusicNode * search(std::string title);
        MusicNode * treeMinimum(MusicNode *node);
        MusicNode * root0;
        MusicNode * root1;
        MusicNode * root2;
        MusicNode * root3;
        MusicNode * root4;
        MusicNode * root5;


};
#endif // MUSICTREE_H
