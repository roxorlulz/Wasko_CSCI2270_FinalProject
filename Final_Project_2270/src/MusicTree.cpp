#include <iostream>
#include "MusicTree.h"
#include <vector>

using namespace std;

MusicTree::MusicTree()
{
    //ctor
    root0 = NULL;
    root1 = NULL;
    root2 = NULL;
    root3 = NULL;
    root4 = NULL;
    root5 = NULL;
    Playlists.push_back("Main Library");
}

MusicTree::~MusicTree()
{
    //dtor
}

void MusicTree::insertMusicNode(int rating, string title, string artist, string length, int tree){
    MusicNode * current = new MusicNode;
    if(tree == 0){
        current = root0;
    }
    else if(tree == 1){
        current = root1;
    }
    else if(tree == 2){
        current = root2;
    }
    else if(tree == 3){
        current = root3;
    }
    else if(tree == 4){
        current = root4;
    }
    else if(tree == 5){
        current = root5;
    }
    MusicNode * insNode = new MusicNode(rating, title, artist, length);
    MusicNode * currentP = new MusicNode;
    if(current == NULL){
        if(tree == 0){
            root0 = insNode;
        }
        else if(tree == 1){
            root1 = insNode;
        }
        if(tree == 2){
            root2 = insNode;
        }
        else if(tree == 3){
            root3 = insNode;
        }
        else if(tree == 4){
            root4 = insNode;
        }
        else if(tree == 5){
            root5 = insNode;
        }
    }
    else{
        while(current != NULL){
            currentP = current;
            if(currentP->title.compare(insNode->title) > 0){//tells whether to move left or right
                current = current->leftChild;
            }
            else{
                current = current->rightChild;
            }
        }
        if(currentP->title.compare(insNode->title) > 0){//setting the pointers once the place for this node in the tree is found
            currentP->leftChild = insNode;
            insNode->parent = currentP;
            insNode->leftChild = NULL;
            insNode->rightChild = NULL;
            //cout<<"parent set"<<endl;
        }
        else{
            currentP->rightChild = insNode;
            insNode->parent = currentP;
            insNode->leftChild = NULL;
            insNode->rightChild = NULL;
            //cout<<"parent set"<<endl;
        }
    }
    cout<<"Added "<<insNode->title<<" By "<<insNode->artist<<" To "<<Playlists[tree]<<endl;

}

void MusicTree::songPrintAZ(int tree){
    MusicNode * root = new MusicNode;
    if(tree == 0){
        printMusicAZ(root0);
    }
    else if(tree == 1){
        printMusicAZ(root1);
    }
    else if(tree == 2){
        printMusicAZ(root2);
    }
    else if(tree == 3){
        printMusicAZ(root3);
    }
    else if(tree == 4){
        printMusicAZ(root4);
    }
    else if(tree == 5){
        printMusicAZ(root5);
    }
}

void MusicTree::printMusicAZ(MusicNode * node){
    if(node != NULL){

    if(node->leftChild != NULL){
        printMusicAZ(node->leftChild);//recursive program to call the left most then down the list
    }
        cout<<"Song: "<<node->title<<" by: "<<node->artist<<endl;

    if(node->rightChild != NULL){
        printMusicAZ(node->rightChild);
    }
    }
    else{
        cout<<"You have to put something in the playlist to print it, Silly!"<<endl;
    }

}

void MusicTree::deleteMusicNode(string title, int tree){
    bool songFound = false;
    MusicNode * temp = new MusicNode;
    MusicNode * root = new MusicNode;
    if(tree == 0){
        temp = root0;
        root = root0;
    }
    else if(tree == 1){
        temp = root1;
        root = root1;
    }
    else if(tree == 2){
        temp = root2;
        root = root2;
    }
    else if(tree == 3){
        temp = root3;
        root = root3;
    }
    else if(tree == 4){
        temp = root4;
        root = root4;
    }
    else if(tree == 5){
        temp = root5;
        root = root5;
    }
    while(temp != NULL){
        if(temp->title == title){
//          ============= NO CHILDREN =====================
            if(temp->leftChild == NULL and temp->rightChild == NULL){
                if(temp == root){
                    root = NULL;
                    if(tree == 0){
                        root0 = NULL;
                    }
                    else if(tree == 1){
                        root1 = NULL;
                    }
                    else if(tree == 2){
                        root2 = NULL;
                    }
                    else if(tree == 3){
                        root3 = NULL;
                    }
                    else if(tree == 4){
                        root4 = NULL;
                    }
                    else if(tree == 5){
                        root5 = NULL;
                    }
                }
                else if(temp->parent->leftChild == temp){
                    temp->parent->leftChild = NULL;
                }
                else{
                    temp->parent->rightChild = NULL;
                }
            cout<<"Deleted "<<temp->title<<endl;
            delete temp;
            songFound = true;
            break;
            }
//          ================== BOTH CHILDREN ======================
            else if(temp->leftChild != NULL and temp->rightChild != NULL){
                MusicNode * minNode = temp->rightChild;
                while(minNode->leftChild != NULL){
                    minNode = minNode->leftChild;
                }
                if(minNode->parent == temp){
                    if(temp->parent->leftChild == temp){
                        temp->parent->leftChild = minNode;
                        minNode->parent = temp->parent;
                        temp->leftChild->parent = minNode;
                        minNode->leftChild = temp->leftChild;
                    }
                    else{
                        temp->parent->rightChild= minNode;
                        minNode->parent = temp->parent;
                        temp->leftChild->parent = minNode;
                        minNode->leftChild = temp->leftChild;

                    }
                }
                else{
                    if(temp->parent->leftChild == temp){
                        if(minNode->leftChild != NULL){
                            minNode->parent->leftChild = minNode->rightChild;
                            minNode->rightChild->parent = minNode->parent;
                        }
                        else{
                            minNode->parent->leftChild = NULL;
                        }
                        minNode->parent = temp->parent;
                        temp->parent->leftChild = minNode;
                        minNode->leftChild = temp->leftChild;
                        minNode->rightChild = temp->rightChild;
                        temp->rightChild->parent = minNode;
                        temp->leftChild->parent = minNode;

                    }
                    else{
                        if(minNode->leftChild != NULL){
                            minNode->parent->leftChild = minNode->rightChild;
                            minNode->rightChild->parent = minNode->parent;
                        }
                        else{
                            minNode->parent->leftChild = NULL;
                        }
                        minNode->parent = temp->parent;
                        temp->parent->rightChild = minNode;
                        minNode->leftChild = temp->leftChild;
                        minNode->rightChild = temp->rightChild;
                        temp->rightChild->parent = minNode;
                        temp->leftChild->parent = minNode;

                    }
                }
                cout<<"Deleted "<<temp->title<<endl;
                delete temp;
                songFound = true;
                break;
            }
//          ============== ONE CHILD ====================
            else{
                if(temp->leftChild != NULL){
                    MusicNode * x = temp->leftChild;
                    if(temp->parent->leftChild == temp){
                        temp->parent->leftChild = x;
                    }
                    else{
                        temp->parent->rightChild = x;
                    }
                    x->parent = temp->parent;
                }
                else{
                    MusicNode * x =temp->rightChild;
                    if(temp->parent->leftChild == temp){
                        temp->parent->leftChild = x;
                    }
                    else{
                        temp->parent->rightChild = x;
                    }
                    x->parent = temp->parent;
                }
                cout<<"Deleted "<<temp->title<<endl;
                delete temp;
                songFound = true;
                break;
            }
        }

        else if(temp->title.compare(title) > 0){
            temp = temp->leftChild;
        }
        else{
            temp = temp->rightChild;
        }
    }
    if(!songFound){
        cout<<"Unable to Find Song. Please be sure What You Entered Is Correct."<<endl;
    }
}

void MusicTree::findSong(string title, int tree){
    MusicNode * temp = new MusicNode;
    if(tree == 0){
        temp = root0;
    }
    else if(tree == 1){
        temp = root1;
    }
    else if(tree == 2){
        temp = root2;
    }
    else if(tree == 3){
        temp = root3;
    }
    else if(tree == 4){
        temp = root4;
    }
    else if(tree == 5){
        temp = root5;
    }
    while(temp != NULL){
        if(temp->title == title){
            cout<<" "<<endl;
            cout<<"SONG INFORMATION"<<endl;
            cout<<"~~~~~~~~~~~~~~~~~"<<endl;
            cout<<"Title:"<<temp->title<<endl;
            cout<<"Artist:"<<temp->artist<<endl;
            cout<<"Length:"<<temp->length<<endl;
            cout<<"You Rated This Song A "<<temp->rating<<" Out of 5"<<endl;
            break;
        }
        else if(temp->title.compare(title) > 0){
            temp = temp->leftChild;
        }
        else{
            temp = temp->rightChild;
        }

    }
    if(temp == NULL){
        cout<<"Unable to Find Song. Please be sure What You Entered Is Correct."<<endl;//if it gets to an end and it isnt there temp will be NULL
    }

}

void MusicTree::createAPlaylist(string name){
    bool repeat = false;
    for(int i = 0; i<Playlists.size(); i++){
        if(Playlists[i] == name){
            repeat = true;
        }
    }
    if(!repeat){
        Playlists.push_back(name);
        cout<<name<<" Added to Playlists."<<endl;
    }
    else{
        cout<<"That Playlist already exists please come up with a new name."<<endl;
    }
}

void MusicTree::PlaylistGetter(){
    cout<<"=================="<<endl;
    for(int i = 0; i<Playlists.size(); i++){
        cout<<"["<<i+1<<"] "<<Playlists[i]<<endl;
    }
    cout<<"=================="<<endl;
}

int MusicTree::PlaylistIndex(string name){
    int i = 0;
    for(i = 0; i<Playlists.size(); i++){
        if(Playlists[i] == name){
            break;
        }
    }
    return i;
}

void MusicTree::PlaylistSetter(string old, string New){
    bool found = false;
    for(int i = 0; i<Playlists.size(); i++){
        if(Playlists[i] == old){
            found = true;
            Playlists[i] = New;
            break;
        }
    }
    if(!found){
        cout<<"Could not find Playlist"<<endl;
    }
}

int MusicTree::countSongs(int tree){
    int *c = 0;
    if(tree == 0){
        return CountSongs(root0);
    }
    else if(tree == 1){
        return CountSongs(root1);
    }
    else if(tree == 2){
        return CountSongs(root2);
    }
    else if(tree == 3){
        return CountSongs(root3);
    }
    else if(tree == 4){
        return CountSongs(root4);
    }
    else if(tree == 5){
        return CountSongs(root5);
    }

}

int MusicTree::CountSongs(MusicNode* Node){
        if (!Node){//if theres no node don't add anything
            return 0;
        }
        else {
            return CountSongs(Node->leftChild) + CountSongs(Node->rightChild) + 1;// adds one to the counter pointer
        }

}




