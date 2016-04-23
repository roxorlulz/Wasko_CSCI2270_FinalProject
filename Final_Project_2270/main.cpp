#include <iostream>

using namespace std;

int mainMenu(){
    int input = 0;
    cout<<"==== MAIN MENU ===="<<endl;
    cout<<"(1) Input Song To Library"<<endl;
    cout<<"(2) Delete Song From Library"<<endl;
    cout<<"(3) Find A Song"<<endl;
    cout<<"(4) Quick Print Library"<<endl;
    cout<<"(5) Print Menu"<<endl;
    cout<<"(6) Play-list Menu"<<endl;
    cout<<"(7) Quit"<<endl;
    cin>>input;
    return input;

}

void printPlayMenu(){
    int printInput = 0;
    cout<<"==== PRINT MENU ===="<<endl;
    cout<<"(1) Print A-Z"<<endl;
    cout<<"(2) Print Z-A"<<endl;
    cout<<"(3) Print By Genre"<<endl;
    cout<<"(4) Print By Song Length (Short to Long)"<<endl;
    cout<<"(5) Print By Song Length (Long to Short)"<<endl;
    cout<<"(6) Back to Previous Menu"<<endl;
    cin>>printInput;
    bool printMenu = true;
    while(printMenu){
        if(printInput == 1){


        }
        else if(printInput == 2){


        }
        else if(printInput == 3){


        }
        else if(printInput == 4){


        }
        else if(printInput == 5){


        }
        else if(printInput == 6){
            break;
        }
        else{
            cout<<"Please Enter a Valid response:"<<endl;
            cin>>printInput;
        }
    }
}

void printLibMenu(){
    int printInput = 0;
    cout<<"==== PRINT MENU ===="<<endl;
    cout<<"(1) Print A-Z"<<endl;
    cout<<"(2) Print Z-A"<<endl;
    cout<<"(3) Print By Genre"<<endl;
    cout<<"(4) Print By Song Length (Short to Long)"<<endl;
    cout<<"(5) Print By Song Length (Long to Short)"<<endl;
    cout<<"(6) Back to Previous Menu"<<endl;
    cin>>printInput;
    bool printMenu = true;
    while(printMenu){
        if(printInput == 1){


        }
        else if(printInput == 2){


        }
        else if(printInput == 3){


        }
        else if(printInput == 4){


        }
        else if(printInput == 5){


        }
        else if(printInput == 6){
            break;
        }
        else{
            cout<<"Please Enter a Valid response:"<<endl;
            cin>>printInput;
        }
    }
}

void playlistMenu(){
    int pInput = 0;
    cout<<"==== PLAYLIST MENU ===="<<endl;
    cout<<"(1) Input Song To Playlist"<<endl;
    cout<<"(2) Delete Song From Playlist"<<endl;
    cout<<"(3) Find A Song"<<endl;
    cout<<"(4) Quick Print Playlist"<<endl;
    cout<<"(5) Print Menu"<<endl;
    cout<<"(6) Back to Main Menu"<<endl;
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
            printPlayMenu();
            cout<<"==== PLAYLIST MENU ===="<<endl;
            cout<<"(1) Input Song To Playlist"<<endl;
            cout<<"(2) Delete Song From Playlist"<<endl;
            cout<<"(3) Find A Song"<<endl;
            cout<<"(4) Quick Print Playlist"<<endl;
            cout<<"(5) Print Menu"<<endl;
            cout<<"(6) Back to Main Menu"<<endl;
            cin>>pInput;

        }
        else if(pInput == 6){
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
    bool programRunning = true;
    int mainInput = 0;
    mainInput = mainMenu();
    while(programRunning){
        if(mainInput == 1){


        }
        else if(mainInput == 2){


        }
        else if(mainInput == 3){


        }
        else if(mainInput == 4){


        }
        else if(mainInput == 5){
            printLibMenu();
            mainInput = mainMenu();

        }
        else if(mainInput == 6){
            playlistMenu();
            mainInput = mainMenu();
        }
        else if(mainInput == 7){
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
