#include "header.h"
#include "userInterface.h"
#include "clrscr.h"

using namespace std;


listCelebs L_C;
listFollowers L_F;

int state = 0;
/*
    -1 : exit
     0  : select mode
     1  : celeb mode [signup]
     2  : follower mode [signup]
*/

void init () {
    CreateListCeleb(L_C);
    CreateListFollower(L_F);
}

void showMenu () {
    cout << "==============Welcome==============\n\n";
    string choice[5] = {
        "Add new Celeb", 
        "Add new Follower",
        "Login as Celeb",
        "Login as Follower",
        "Exit"
        };

    state = multiChoice(choice, 5);
    if (state >= 5) state = -1;
    clrscr();
}

void CelebSignUp () {
    cout << "=============New Celeb==============\n\n";
    addressCeleb P = AllocateCeleb(getString("Enter new Username : "));

    InsertLastCeleb(L_C, P);
    clrscr();
    cout << "new Celeb : "<< info(last(L_C)).username << " added\n";
    state = 0;
}


void FollowerSignUp () {
    cout << "=============New Follower===========\n\n";
    InsertLastFollower(L_F, AllocateFollower("hh"));
    clrscr();
    cout << "new Follower : "<< info(last(L_F)).username << " added\n";
    state = 0;
}

int main () {

    init();

    while(state != -1) {
        cout << '\n';
        switch (state) {
            case 0:
                showMenu();
                
                break;
            case 1:
                CelebSignUp();
                break;
            case 2:
                FollowerSignUp();
                break;
            default:
                state = -1;
                break;
        }
    }

    return 0;
}