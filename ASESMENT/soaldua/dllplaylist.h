#ifndef DLLPLAYLIST_H
#define DLLPLAYLIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <cmath> 
#include <algorithm> 

struct Song {
    std::string Title;
    std::string Artist;
    int DurationSec; 
    int PlayCount;   
    float Rating;    
};

struct Node {
    Song info;
    Node* prev; 
    Node* next; 
};

struct List {
    Node* head; 
    Node* tail; 
};

float calculatePopularityScore(int playCount, float rating);
bool isEmpty(List L);
List createList(); 
Node* allocate(Song S); 
void deallocate(Node* P);

void insertFirst(List &L, Song S);
void insertLast(List &L, Song S);
void insertAfter(List &L, Node* Q, Song S);
void insertBefore(List &L, Node* Q, Song S);

void deleteFirst(List &L, Song &S);
void deleteLast(List &L, Song &S);
void deleteAfter(List &L, Node* Q, Song &S);
void deleteBefore(List &L, Node* Q, Song &S);

Node* searchNodeAtPosition(List L, int posisi);
void updateAtPosition(List &L, int posisi, Song S);

void viewListSimple(List L, const std::string& title); 
void searchByPopularityRangeSimple(List L, float minScore, float maxScore);

#endif