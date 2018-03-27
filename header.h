#ifndef STD_HEADER
#define STD_HEADER

#include <string>

// Macros

#define first(L) (L).first
#define last(L)  (L).last
#define next(P)  (P)->next
#define prev(P)  (P)->prev
#define info(P)  (P)->info

// List Declaration

typedef struct Follower *addressFollower;
typedef struct Celeb *addressCeleb;

struct listFollowers {
    addressFollower first;
    addressFollower last;
};


struct listCelebs {
    addressCeleb first;
    addressCeleb last;
};

// Celebrity Data Structure

struct infotypeCeleb {
    std::string username;
    listFollowers Followers;
};

struct Celeb {
    infotypeCeleb info;
     addressCeleb next;
     addressCeleb prev; 
};

addressCeleb AllocateCeleb (std::string username);
addressCeleb GetCeleb (listCelebs Celebs, std::string username);
addressCeleb DeleteCeleb (listCelebs L, addressCeleb C);
addressCeleb DeleteFirstCeleb (listCelebs L);
addressCeleb DeletelastCeleb (listCelebs L);

void DeallocateCeleb (std::string username);
void InsertLastCeleb (listCelebs L, addressCeleb C);
void CreateListCeleb (listCelebs L);
void addNewFollower (addressCeleb C, addressFollower F);

// Followers Data Structure

struct infotypeFollower {
    std::string username;
    struct listCelebs Following;
};

struct Follower {
    infotypeFollower info;
    addressFollower next; 
    addressFollower prev;
};

addressFollower AllocateFollower (std::string username);
addressFollower GetFollower (listFollowers Followers, std::string username);
addressFollower DeleteFollower (listFollowers L, addressFollower C);
addressFollower DeleteFirstFollower (listFollowers L);
addressFollower DeletelastFollower (listFollowers L);

void DeallocateFollower (std::string username);
void InsertLastFollower (listFollowers L, addressFollower F);
void CreateListFollower (listFollowers L);
void addNewFollowing (addressFollower F, addressCeleb C);

#endif