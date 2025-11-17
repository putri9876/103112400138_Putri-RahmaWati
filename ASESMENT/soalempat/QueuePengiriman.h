#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

const int MAX = 5;
const int BIAYA_PER_KG = 8250;

struct Paket {
    string KodeResi;
    string NamaPengirim;
    int BeratBarang;
    string Tujuan;
};

typedef struct QueueEkspedisi {
    Paket dataPaket[MAX];
    int Head;
    int Tail;
} Queue;

bool isEmpty(Queue Q);
bool isFull(Queue Q);
void createQueue(Queue &Q);
void enQueue(Queue &Q, Paket P);
Paket deQueue(Queue &Q);
void viewQueue(Queue Q);

int TotalBiayaPengiriman(Queue Q);