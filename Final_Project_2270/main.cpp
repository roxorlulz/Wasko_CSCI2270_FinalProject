#include <iostream>
#include "MusicTree.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

MusicTree MT;
std::vector<std::string> Playlists;

int mainMenu(){
    int input = 0;
    cout<<"==== MAIN MENU ===="<<endl;
    cout<<"(1) Input Song To Library"<<endl;
    cout<<"(2) Delete Song From Library"<<endl;
    cout<<"(3) Find A Song"<<endl;
    cout<<"(4) Print Library A-Z"<<endl;
    cout<<"(5) Play-list Menu"<<endl;
    cout<<"(6) Quit"<<endl;
    cin>>input;
    return input;

}


void playlistMenu(){
    int index = 0;
    int pInput = 0;
    cout<<"==== PLAYLIST MENU ===="<<endl;
    cout<<"(1) Create a Playlist"<<endl;
    cout<<"(2) Input Song To Playlist"<<endl;
    cout<<"(3) Delete Song From Playlist"<<endl;
    cout<<"(4) Find A Song"<<endl;
    cout<<"(5) Print Playlist"<<endl;
    cout<<"(6) Choose a Different Playlist"<<endl;
    cout<<"(7) Back to Main Menu"<<endl;
    cin>>pInput;
    bool playlist = true;
    while(playlist){
        if(pInput == 1){


        }
        else if(pInput == 2){


        }
        else if(pInput == 3){


        }
        else if(pInput == 4){


        }
        else if(pInput == 5){

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Input Song To Playlist"<<endl;
            cout<<"(2) Delete Song From Playlist"<<endl;
            cout<<"(3) Song Info"<<endl;
            cout<<"(4) Quick Print Playlist"<<endl;
            cout<<"(5) Print Menu"<<endl;
            cout<<"(6) Back to Main Menu"<<endl;
            cin>>pInput;

        }
        else if(pInput == 6){

        }
        else if(pInput == 7){
            break;
        }
        else{
            cout<<"Please Enter a Valid response:"<<endl;
            cin>>pInput;
        }
    }

}


int main()
{
    Playlists.push_back("Library");
    int Rating;
    string Title;
    string Artist;
    string Length;
    int counter = 0;//counter is for the column of text it is in
    string data2;
    string data;
    ifstream inFile("Music.txt"/*argv[1]*/);//opens file
    while(getline(inFile, data)){//separates data by line
        stringstream ss(data);
        while(getline(ss, data2, ',')){//separates data by comma
            if(counter == 0){
                Rating = stoi(data2);//stoi converts from string to int
                counter++;
            }
            else if(counter == 1){
                Title = data2;//putting data in proper storage
                counter++;
            }
            else if(counter == 2){
                Artist = data2;
                counter++;
            }
            else if(counter == 3){
                Length = data2;
                counter = 0;
            }
        }
        MT.insertMusicNode(Rating, Title, Artist, Length, 0);//goes to create the tree when program starts
    }
    bool programRunning = true;
    int mainInput = 0;
    mainInput = mainMenu();
    while(programRunning){
        if(mainInput == 1){
            int r;
            string t;
            string a;
            string l;
            cout<<"Enter a song name: "<<endl;
            cin.ignore();
            getline(cin,t);
            cout<<"Enter the artist of this song: "<<endl;
            getline(cin,a);
            cout<<"Enter how long the dong is here:"<<endl;
            cout<<"The format is '_:__' (If you don't know please enter 'UNKNOWN')"<<endl;
            getline(cin,l);
            cout<<"What would you rate this song out of 5?"<<endl;
            cin>>r;
            MT.insertMusicNode(r,t,a,l,0);
            mainInput = mainMenu();

        }
        else if(mainInput == 2){
            string title;
            cout<<"Enter a Song Name:"<<endl;
            cin.ignore();
            getline(cin,title);
            MT.deleteMusicNode(title, 0);
            mainInput = mainMenu();



        }
        else if(mainInput == 3){
            string title;
            cout<<"Enter a Song Name:"<<endl;
            cin.ignore();
            getline(cin,title);
            MT.findSong(title, 0);
            mainInput = mainMenu();

        }
        else if(mainInput == 4){
            MT.songPrintAZ(0);
            mainInput = mainMenu();

        }
        else if(mainInput == 5){
            playlistMenu();
            mainInput = mainMenu();

        }
        else if(mainInput == 6){
            cout<<"Goodbye!"<<endl;
            programRunning = false;

        }

        else{
            cout<<"Please Input a Valid Response"<<endl;
            mainInput = mainMenu();

        }
    }



    return 0;
}
