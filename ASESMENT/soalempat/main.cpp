#include "QueuePengiriman.h"

void tampilkanMenu() {
    cout << "\nKomanian Ekspress" << endl;
    cout << "1. Input Data Paket " << endl;
    cout << "2. Hapus Data Paket " << endl;
    cout << "3. Tampilkan queue paket" << endl;
    cout << "4. Hitung Total Biaya Pengiriman" << endl;
    cout << "5. Keluar" << endl;
    cout << "Pilihan anda: ";
}

int main() {
    Queue Q;
    int pilihan;
    Paket paket_dihapus;

    cout << "1) Membuat Queue Kosong" << endl;
    createQueue(Q);

    Paket P1 = {"123456", "Hutao", 14, "Sumeru"};
    Paket P2 = {"234567", "Ayaka", 10, "Fontaine"};
    Paket P3 = {"345678", "Bennet", 7, "Natlan"};
    Paket P4 = {"456789", "Furina", 16, "Liyue"};
    Paket P5 = {"567890", "Nefer", 6, "Inazuma"};

    do {
        tampilkanMenu();
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "\n3) Input data paket (enQueue) otomatis:" << endl;
                enQueue(Q, P1);
                enQueue(Q, P2);
                enQueue(Q, P3);
                enQueue(Q, P4);
                enQueue(Q, P5);
                break;
            
            case 2:
                cout << "\n5) Lakukan deQueue sebanyak 1x" << endl;
                paket_dihapus = deQueue(Q);
                if (paket_dihapus.KodeResi != "") {
                    cout << "Paket yang dihapus: Resi " << paket_dihapus.KodeResi << ", Tujuan " << paket_dihapus.Tujuan << endl;
                }
                break;

            case 3:
                cout << "\n4) & 6) Tampilkan queue paket" << endl;
                viewQueue(Q);
                break;

            case 4: {
                cout << "\nHitung Total Biaya Pengiriman (Bagian B)" << endl;
                int totalBiaya = TotalBiayaPengiriman(Q);
                cout << "Total Biaya Pengiriman semua paket dalam queue: Rp " << totalBiaya << endl;
                cout << " (Biaya per kg: Rp " << BIAYA_PER_KG << ")" << endl;
                break;
            }

            case 5:
                cout << "Program selesai. Terima kasih." << endl;
                break;

            default:
                cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
        }
    } while (pilihan != 5);

    return 0;
}