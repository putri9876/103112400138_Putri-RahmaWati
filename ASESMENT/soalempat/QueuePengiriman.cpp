#include "QueuePengiriman.h"

void createQueue(Queue &Q) {
    Q.Head = -1;
    Q.Tail = -1;
    cout << "Queue berhasil dibuat. Head dan Tail diinisialisasi ke -1." << endl;
}

bool isEmpty(Queue Q) {
    return Q.Head == -1;
}

bool isFull(Queue Q) {
    return Q.Tail == MAX - 1;
}

void enQueue(Queue &Q, Paket P) {
    if (isFull(Q)) {
        cout << "ERROR: Queue penuh, data paket gagal ditambahkan." << endl;
        return;
    }
    
    if (isEmpty(Q)) {
        Q.Head = 0;
    }
    
    Q.Tail++;
    Q.dataPaket[Q.Tail] = P;
    cout << "Paket Resi " << P.KodeResi << " (" << P.NamaPengirim << ") berhasil di-enQueue." << endl;
}

Paket deQueue(Queue &Q) {
    Paket P_kosong = {"", "", 0, ""};
    if (isEmpty(Q)) {
        cout << "ERROR: Queue kosong, tidak ada data paket yang dihapus." << endl;
        return P_kosong;
    }
    
    Paket P = Q.dataPaket[Q.Head];
    
    for (int i = Q.Head; i < Q.Tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i+1];
    }
    
    Q.Tail--;
    
    if (Q.Tail == -1) {
        Q.Head = -1;
    }
    
    cout << "Paket Resi " << P.KodeResi << " (" << P.NamaPengirim << ") berhasil di-deQueue (diproses)." << endl;
    return P;
}

void viewQueue(Queue Q) {
    if (isEmpty(Q)) {
        cout << "\nQueue Kosong, tidak ada paket untuk ditampilkan." << endl;
        return;
    }
    
    cout << "\nDATA PAKET DALAM QUEUE" << endl;
    cout << "Index Resi      Nama Pengirim  Berat (kg) Tujuan" << endl;
    
    for (int i = Q.Head; i <= Q.Tail; i++) {
        cout << setw(5) << i
             << setw(10) << Q.dataPaket[i].KodeResi
             << setw(15) << Q.dataPaket[i].NamaPengirim
             << setw(12) << Q.dataPaket[i].BeratBarang
             << setw(8) << Q.dataPaket[i].Tujuan
             << endl;
    }
    cout << "Head: " << Q.Head << ", Tail: " << Q.Tail << ". Jumlah data: " << Q.Tail - Q.Head + 1 << endl;
}

int TotalBiayaPengiriman(Queue Q) {
    int totalBerat = 0;
    if (isEmpty(Q)) {
        return 0;
    }
    
    for (int i = Q.Head; i <= Q.Tail; i++) {
        totalBerat += Q.dataPaket[i].BeratBarang;
    }
    
    return totalBerat * BIAYA_PER_KG;
}