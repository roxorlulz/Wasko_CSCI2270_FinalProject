#include <iostream>
#include "MusicTree.h"
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

MusicTree MT;

string mainMenu(){//making the main menu a function allows for an easy way to have two menus
    string input;
    cout<<"==== MAIN MENU ===="<<endl;
    cout<<"(1) Input Song To Library"<<endl;
    cout<<"(2) Delete Song From Library"<<endl;
    cout<<"(3) Find A Song"<<endl;
    cout<<"(4) Print Library A-Z"<<endl;
    cout<<"(5) Play-list Menu"<<endl;
    cout<<"(6) Count Songs In Library"<<endl;
    cout<<"(7) Quit"<<endl;
    cin>>input;
    return input;

}


void playlistMenu(){
    int index = 0;
    string pInput;
    cout<<"==== PLAYLIST MENU ===="<<endl;
    cout<<"(1) Create a Playlist"<<endl;
    cout<<"(2) Input Song To Playlist"<<endl;
    cout<<"(3) Delete Song From Playlist"<<endl;
    cout<<"(4) Find A Song"<<endl;
    cout<<"(5) Print Playlist Songs"<<endl;
    cout<<"(6) See What Playlists You Have"<<endl;
    cout<<"(7) Change a Playlists Name"<<endl;
    cout<<"(8) Count Songs in Playlist"<<endl;
    cout<<"(9) Back to Main Menu"<<endl;
    cin>>pInput;
    bool playlist = true;
    while(playlist){
        if(pInput == "1"){
            string pTitle;
            cout<<"What would you like to call the Playlist?"<<endl;
            cin.ignore();
            getline(cin,pTitle);
            MT.createAPlaylist(pTitle);

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;

        }
        else if(pInput == "2"){
            string pName;
            cout<<"Enter the Playlist you would like to access:"<<endl;
            cin.ignore();
            getline(cin,pName);
            int element = 0;
            element = MT.PlaylistIndex(pName);
            while(element == -1){
                MT.PlaylistGetter();
                cout<<"Sorry the Playlist you entered does not exist please choose one of the Playlists above."<<endl;
                getline(cin,pName);
                element = MT.PlaylistIndex(pName);
            }

            int r;
            string t;
            string a;
            string l;
            cout<<"Enter a song name: "<<endl;
            //cin.ignore();
            getline(cin,t);
            cout<<"Enter the artist of this song: "<<endl;
            getline(cin,a);
            cout<<"Enter how long the dong is here:"<<endl;
            cout<<"The format is '_:__' (If you don't know please enter 'UNKNOWN')"<<endl;
            getline(cin,l);
            cout<<"What would you rate this song out of 5?"<<endl;
            cin>>r;
            MT.insertMusicNode(r,t,a,l,element);


            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;


        }
        else if(pInput == "3"){
            string pName;
            cout<<"Enter the Playlist you would like to access:"<<endl;
            cin.ignore();
            getline(cin,pName);
            int element = 0;
            element = MT.PlaylistIndex(pName);

            while(element == -1){
                MT.PlaylistGetter();
                cout<<"Sorry the Playlist you entered does not exist please choose one of the Playlists above."<<endl;
                getline(cin,pName);
                element = MT.PlaylistIndex(pName);
            }

            string title;
            cout<<"Enter a Song Name:"<<endl;
            getline(cin,title);
            MT.deleteMusicNode(title, element);

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;


        }
        else if(pInput == "4"){
            string pName;
            cout<<"Enter the Playlist you would like to access:"<<endl;
            cin.ignore();
            getline(cin,pName);
            int element = 0;
            element = MT.PlaylistIndex(pName);

            while(element == -1){
                MT.PlaylistGetter();
                cout<<"Sorry the Playlist you entered does not exist please choose one of the Playlists above."<<endl;
                getline(cin,pName);
                element = MT.PlaylistIndex(pName);
            }

            string title;
            cout<<"Enter a Song Name:"<<endl;
            getline(cin,title);
            MT.findSong(title, element);

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;

        }
        else if(pInput == "5"){
            string pName;
            cout<<"Enter the Playlist you would like to access:"<<endl;
            cin.ignore();
            getline(cin,pName);
            int element = 0;
            element = MT.PlaylistIndex(pName);

            while(element == -1){
                MT.PlaylistGetter();
                cout<<"Sorry the Playlist you entered does not exist please choose one of the Playlists above."<<endl;
                getline(cin,pName);
                element = MT.PlaylistIndex(pName);
            }
            MT.songPrintAZ(element);

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;

        }
        else if(pInput == "6"){
            MT.PlaylistGetter();

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;

        }
        else if(pInput == "7"){
            string old;
            string New;
            cout<<"What is the name of the Playlist you will be changing?"<<endl;
            cin.ignore();
            getline(cin,old);
            cout<<"What Do you want to re-name it?"<<endl;
            getline(cin,New);
            MT.PlaylistSetter(old,New);

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;
        }
        else if(pInput == "8"){
            string pName;
            cout<<"Enter the Playlist you would like to access:"<<endl;
            cin.ignore();
            getline(cin,pName);
            int element = 0;
            element = MT.PlaylistIndex(pName);

            while(element == -1){
                MT.PlaylistGetter();
                cout<<"Sorry the Playlist you entered does not exist please choose one of the Playlists above."<<endl;
                getline(cin,pName);
                element = MT.PlaylistIndex(pName);
            }

            cout<<"The number of songs in the Main Library is: "<<MT.countSongs(element)<<endl;

            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Create a Playlist"<<endl;
            cout<<"(2) Input Song To Playlist"<<endl;
            cout<<"(3) Delete Song From Playlist"<<endl;
            cout<<"(4) Find A Song"<<endl;
            cout<<"(5) Print Playlist Songs"<<endl;
            cout<<"(6) See What Playlists You Have"<<endl;
            cout<<"(7) Change a Playlists Name"<<endl;
            cout<<"(8) Count Songs in Playlist"<<endl;
            cout<<"(9) Back to Main Menu"<<endl;
            cin>>pInput;

        }
        else if(pInput == "9"){
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
    //Playlists.push_back("Library");
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
    string mainInput;
    mainInput = mainMenu();
    while(programRunning){
        if(mainInput == "1"){
            int rating;
            string r;
            string t;
            string a;
            string l;
            cout<<"Enter a song name: "<<endl;
            cin.ignore();
            getline(cin,t);
            cout<<"Enter the artist of this song: "<<endl;
            getline(cin,a);
            cout<<"Enter how long the song is here:"<<endl;
            cout<<"The format is '_:__' (If you don't know please enter 'UNKNOWN')"<<endl;
            while(1){
                cin>>l;
                //52 to 47 are the ascii values of the valid time inputs
                if(((int)l[1]>53 || (int)l[1]<48)||((int)l[2]>53 || (int)l[2]<48))cout<<"Please enter a valid input"<<endl;
                else break;
            }
            cout<<"What would you rate this song out of 5?"<<endl;//found it
            while(1){
                cin>>r;
                //52 to 47 are the ascii values of the valid time inputs
                if((int)r[0]>53 || (int)r[0]>47)cout<<"Please enter a valid input"<<endl;
                else break;
            }
            mainInput = mainMenu();

        }
        else if(mainInput == "2"){
            string title;
            cout<<"Enter a Song Name:"<<endl;
            cin.ignore();
            getline(cin,title);
            MT.deleteMusicNode(title, 0);
            mainInput = mainMenu();



        }
        else if(mainInput == "3"){
            string title;
            cout<<"Enter a Song Name:"<<endl;
            cin.ignore();
            getline(cin,title);
            MT.findSong(title, 0);
            mainInput = mainMenu();

        }
        else if(mainInput == "4"){
            MT.songPrintAZ(0);
            mainInput = mainMenu();

        }
        else if(mainInput == "5"){
            playlistMenu();
            mainInput = mainMenu();

        }
        else if(mainInput == "6"){
            cout<<"The number of songs in the Main Library is: "<<MT.countSongs(0)<<endl;
            mainInput = mainMenu();
        }
        else if(mainInput == "7"){
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
