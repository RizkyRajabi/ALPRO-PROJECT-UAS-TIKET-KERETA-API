#include <iostream>
#include <string>
using namespace std;

/* Fungsi untuk Login
Fungsinya untuk mminta username dan password yang sudah ditentukan.
Jika Kombinasi username dan password cocok, maka login berhasil.
jika kombinasi salah, pengguna diminta untuk mengisinya kembali.*/
bool login () {

    const string usernameYangbenar = "prabowo"; // Username yang benar
    const string passwordYangbenar = "maxwin99"; // Password yang benar

    string username;
    string password;

    cout << "Masukkan Username: ";
    cin >> username;
    cout << "Masukkan Password: " ;
    cin >> password;

    if (username == usernameYangbenar && password == passwordYangbenar){
        // Jika usenamr dan password cocok
        cout << "Login Berhasil! ***SELAMAT DATANG***" <<endl << endl;
        return true;
        } else {
        // Jika username atau password salah
        cout << "Login Gagal! Nama atau Password salah!" << endl << endl;
        return login();// Rekursi untuk user mengisi ulang login jika salah
    }
}

/* Fungsi untuk menampilkan Nama Kelompok
Fungsi ini menampilkan nama kelompok, anggota, dan informasi proyek.*/
void NamaKelompok(){
    cout << "   ***************************************************************" << endl;
    cout << "   |          TUGAS PROJECT UAS ALGORITMA & PEMROGRAMAN          |" << endl;
    cout << "   |              SISTEM PEMESANAN TIKET KERETA API              |" << endl;
    cout << "   |-------------------------------------------------------------|" << endl;
    cout << "   |    NAMA KELOMPOK : TUKANG BUBUR NAIK AYAM                   |" << endl;
    cout << "   |    ANGGOTA       : ANDHIKA SUBAGJA (2410631170008)          |" << endl;
    cout << "   |                    MUHAMMADRIZKY RAJABI (2410631170039)     |" << endl;
    cout << "   |                    NAZRIL ADRIAN (2410631170097)            |" << endl;
    cout << "   |    KELAS         : 1B INFORMATIKA                           |" << endl;
    cout << "   |                                                             |" << endl;
    cout << "   ***************************************************************" << endl << endl;
}

/* Fungsi untuk pemilihan Jadwal Kereta
Fungsi ini meminta tanggal, bulan, dan  tahun keberangkatan dari pengguna.
Jika sudah dimasukkan, pengguna diminta untuk mengkonfirmasi apakah jadwal sudah benar.
Jika jadwal dikira salah, maka pengguna diminta untuk mengulang input*/
    bool pilihJadwal(string& tanggal, string& bulan, string& tahun) {

        cout << "Masukkan Jadwal Keberangkatan (1-31): ";
        cin >> tanggal;
        cout << "Masukkan Bulan Keberangkatan (1-12): ";
        cin >> bulan;
        cout << "Masukkan Tahun Keberangkatan (2024): ";
        cin >> tahun;
        cout << endl;

        char pilihan;
        cout << "Apa jadwal yang anda masukkan benar? (y/n): " << tanggal << " - " << bulan << " - " << tahun << endl;
        cin >> pilihan;

        if (pilihan == 'y' || pilihan == 'Y') {
                // Jika pengguna memilih "y", jadwa dianggap benar
                cout << endl;
            return true;
        } else {
            // Jika pengguna memilih n, input jadwal akan diulang
            cout << "SILAHKAN MASUKKAN ULANG JADWAL ANDA DENGAN TELITI." << endl << endl;
            return pilihJadwal (tanggal, bulan, tahun);
        }
}

/* Fungsi untuk pemilihan Destinasi
Fungsi ini meminta pengguna memilih salah satu dari empat destinasi yang tersedia/
Jika input tidak valid, pengguna diminta untuk mengulang pilihan.*/
void pilihDestinasi (string& destinasi ) {
    int pilihanDestinasi;

    cout << "Pilih Destinasi\n";
    cout << "1. Bandung\n";
    cout << "2. Majalengka\n";
    cout << "3. Ngawi\n";
    cout << "4. Papua\n";
    cout << "Masukkan Pilihan Destinasi Anda (1,2,3,4): ";
    cin >> pilihanDestinasi; // Rekursi untuk mengulang input jika salah
    cout << endl;

    // Menggunakan switch untuk memilih destinasi 1-4
    switch (pilihanDestinasi) {
        case 1: destinasi = "Bandung";
            break;
        case 2: destinasi = "Majalengka";
            break;
        case 3: destinasi = "Ngawi";
            break;
        case 4: destinasi = "Papua";
            break;
        default:
            // Jika input tidak valid, ulangi proses
            cout << "PILIHAN DESTINASI INVALID.\nSILAHKAN COBA LAGI :)." << endl << endl;
            return pilihDestinasi (destinasi);//jika memilih <1 atau >4 akan kembali ke pilihan destinasi
    }
}

/* Fungsi untuk pemilihan Kelas Kereta
Fungsi ini meminta pengguna memilih kelas kereta berdasarkan destinasi yang sudah dipilih sebelumnya.
Harga tiket ditentukan berdasarkan kelas dan destinasi.
Jika input tidak valid, pengguna diminta mengulang input.*/
void pilihKelas(const string& destinasi, string& kelas, int& harga) {
    int pilihanKelas = 0; // Inialisasi pilihanKelas dengan nilai awal
                         // Jika tidak maka kondisi while tidak terpenuhi dan outputnya akan keluar angka acak

    while (pilihanKelas < 1 || pilihanKelas > 3) {
        // Looping sampai pengguna memberikan input valid
        cout << "Pilih kelas:\n";
        cout << "1. Ekonomi (150K - 500K)\n";
        cout << "2. Bisnis (500K - 1000K)\n";
        cout << "3. Eksekutif (1000K - 2000K)\n";
        cout << "Masukkan pilihan kelas (1/2/3): ";
        cin >> pilihanKelas;
        cout << endl;

    // Untuk menentukan kelas dan harga berdasarkan destinasi
    if (destinasi == "Bandung") {
        if (pilihanKelas == 1) { kelas = "Ekonomi"; harga = 150000; }
        else if (pilihanKelas == 2) { kelas = "Bisnis"; harga = 500000; }
        else if (pilihanKelas == 3) { kelas = "Eksekutif"; harga = 1000000; }
    } else if (destinasi == "Majalengka") {
        if (pilihanKelas == 1) { kelas = "Ekonomi"; harga = 200000; }
        else if (pilihanKelas == 2) { kelas = "Bisnis"; harga = 600000; }
        else if (pilihanKelas == 3) { kelas = "Eksekutif"; harga = 1200000; }
    } else if (destinasi == "Ngawi") {
        if (pilihanKelas == 1) { kelas = "Ekonomi"; harga = 300000; }
        else if (pilihanKelas == 2) { kelas = "Bisnis"; harga = 800000; }
        else if (pilihanKelas == 3) { kelas = "Eksekutif"; harga = 1500000; }
    } else if (destinasi == "Papua") {
        if (pilihanKelas == 1) { kelas = "Ekonomi"; harga = 500000; }
        else if (pilihanKelas == 2) { kelas = "Bisnis"; harga = 1000000; }
        else if (pilihanKelas == 3) { kelas = "Eksekutif"; harga = 2000000; }
    }
    if (pilihanKelas < 1 || pilihanKelas > 3) {
        // Jika input tidak valid
        cout << "PILIHAN KELAS INVALID.\nSILAHKAN COBA LAGI :)." << endl << endl;
        }
    }
        //output kelas dan harga yang telah dipilih
        cout << "Kelas yang dipilih: " << kelas << endl;
        cout << "Harga Tiket: Rp " << harga << endl << endl;
}

/* Fungsi untuk pemilihan Letak Kursi
Fungsi ini meminta pengguna memilih lokasi kursi pilihannya ada di (depan, tengah, belakang).
Jika input tidak valid, pengguna diminta untuk mengulang input.*/
string pilihLetak () {
    int letakKursi;
    cout << "Pilih letak kursi:\n";
    cout << "1. Depan\n";
    cout << "2. Tengah\n";
    cout << "3. Belakang\n";
    cout << "Masukkan pilihan posisi (1/2/3): ";
    cin >> letakKursi;
    cout << endl;

    // Menggunakan switch untuk memilih letak kursi 1-3
    switch (letakKursi) {
        case 1:
            return "Di Depan";
        case 2:
            return "Di Tengah";
        case 3:
            return "Di Belakang";
        default:
            // Jika input tidak valid, ulangi proses
            cout << "PILIHAN KURSI INVALID.\nSILAHKAN COBA LAGI :)." << endl << endl;
            return pilihLetak();
    }
}

/*Fungsi untuk pemilihan Posisi Kursi
Fungsi ini meminta pengguna memilih posisi kursinya disebelah mana apakah di (dekat kaca atau dekat lorong).
Jika input tidak valid, pengguna diminta untuk mengulang input.*/
string pilihPosisi () {
    int posisiKursi;
    cout << "Pilih Letak Kursi:\n";
    cout << "1.Dekat Kaca\n";
    cout << "2.Dekat Lorong\n";
    cout << "Masukkan Pilihan Anda (1/2): ";
    cin >> posisiKursi;
    cout << endl;

    // Menggunakan switch untuk memilih posisi kursi 1-2
    switch (posisiKursi) {
    case 1:
        return "Dekat Kaca";
    case 2:
        return "Dekat Lorong";
    default:
        // Jika input tidak valid, ulangi proses
        cout << "PILIHAN KURSI INVALID.\nSILAHKAN COBA LAGI :)." << endl << endl;
        return pilihPosisi ();
    }
}

/*Fungsi untuk mencetak struck tiket
Fungsi ini menampilkan informasi tiket yang telah dipilih oleh pengguna sebelumnya.*/
void cetakTiket(const string& tanggal, const string& bulan, const string& tahun, const string& destinasi, const string& kelas, const string& posisi, const string& letak, int harga)  {
    cout << "*********************** STRUCK TIKET ***********************" << endl;
    cout << "Jadwal Keberangkatan : " << tanggal << " - " << bulan << " - " << tahun << endl;
    cout << "Destinasi            : " << destinasi << endl;
    cout << "Kelas                : " << kelas << endl;
    cout << "Letak Kursi          : " << letak << endl;
    cout << "Posisi Kursi         : " << posisi << endl;
    cout << "Harga Total          : Rp." << harga << endl;
    cout << "************************************************************" << endl;
}

int main() {

            NamaKelompok(); // Menampilkan informasi kelompok

            login(); // Memastikan hanya pengguna yang dapat melanjutkan (username dan password sudah ditentukan)

            string tanggal, bulan, tahun;
            pilihJadwal(tanggal, bulan, tahun); // Meminta input jadwal keberangkatan

            string destinasi;
            pilihDestinasi(destinasi); // Meminta input destinasi perjalanan

            string kelas;
            int harga;
            pilihKelas(destinasi, kelas, harga); // Meminta input kelas kereta dan menghitung harga yang sudah ditetapkan.

            string letak = pilihLetak(); // Meminta input letak kursi

            string posisi = pilihPosisi(); // Meminta input posisi kursi

            // Mencetak struk tiket dengan semua informasi yang sudah dipilih
            cetakTiket(tanggal, bulan, tahun, destinasi, kelas, posisi, letak, harga);

            return 0; // program selesai
}





