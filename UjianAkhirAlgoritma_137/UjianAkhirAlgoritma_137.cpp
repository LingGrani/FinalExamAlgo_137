//	1. Manajemen Data Mahasiswa
//	Di sebuah universitas, terdapat seorang administrator akademik bernama Budi yang
//	bertanggung jawab untuk mengelola data mahasiswa.Setiap tahun, universitas tersebut
//	menerima banyak mahasiswa baru sebanyak 100 mahasiswa dan Budi harus memastikan
//	data mahasiswa terorganisir dengan baik.Budi ingin memiliki aplikasi yang dapat
//	menampilkan, mengurutkan, dan mencari data mahasiswa dengan mudah.Data yang ingin
//	Budi simpan untuk setiap mahasiswa adalah NIM, nama, jurusan, dan tahun masuk.Budi
//	berharap aplikasi ini dapat membantu mencari data mahasiswa berdasarkan NIM dan
//	menampilkan semua data mahasiswa yang masuk berdasarkan tahun masuk secara terurut.
//	Berdasarkan kasus diatas, buatlah program yang sesuai dengan kebutuhan Budi!(40 Poin)


#include <iostream>
#include <string>
using namespace std;

//isi disini



const int MAX_MAHASISWA = 100;
int NIM[MAX_MAHASISWA];
string nama[MAX_MAHASISWA];
int tahunMasuk[MAX_MAHASISWA];
int jumlahMahasiswa = 0;

//isi disini

string jurusan[MAX_MAHASISWA];


void tambahMahasiswa() {
	if (jumlahMahasiswa < MAX_MAHASISWA) {
		cout << "========== TAMBAH MAHASISWA ==========" << endl;
		cout << "NIM : ";
		cin >> NIM[jumlahMahasiswa];
		cin.ignore();
		cout << "Nama : ";
		getline(cin, nama[jumlahMahasiswa]);
		cout << "Jurusan : ";
		getline(cin, jurusan[jumlahMahasiswa]);
		cout << "Tahun Masuk: ";
		cin >> tahunMasuk[jumlahMahasiswa];
		cin.ignore();
		jumlahMahasiswa++;
		cout << "Mahasiswa berhasil ditambahkan!" << endl;
	}
	else {
		cout << "Kapasitas maksimum mahasiswa telah tercapai." << endl;
	}
};

//isi disini
void tampilkanSemuaMahasiswa() {
	if (jumlahMahasiswa == 0) {
		cout << "==== DATA BELUM DIMASUKAN ====" << endl;
	}
	else {
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "\nNIM\t\t :  " << NIM[i] << endl;
			cout << "Nama\t\t :  " << nama[i] << endl;
			cout << "Jurusan\t\t :  " << jurusan[i] << endl;
			cout << "Tahun Masuk\t :  " << tahunMasuk[i] << endl << endl;
		}
	}
};


//isi disini
void algorithmacariMahasiswaByNIM() {
	if (jumlahMahasiswa == 0) {
		cout << "==== DATA BELUM DIMASUKAN ====" << endl;
	}
	else {
		int NIM_Cari;
		int jumlah = 0;
		cout << "NIM Yang Dicari: ";
		cin >> NIM_Cari;
		for (int i = 0; i < jumlahMahasiswa; i++) {
			if (NIM[i] == NIM_Cari) {
				cout << "\nMahasiswa dengan NIM: " << NIM_Cari << " Found at position " << i + 1<< endl;
				cout << "NIM\t\t :  " << NIM[i] << endl;
				cout << "Nama\t\t :  " << nama[i] << endl;
				cout << "Jurusan\t\t :  " << jurusan[i] << endl;
				cout << "Tahun Masuk\t :  " << tahunMasuk[i] << endl << endl;
				jumlah++;
			}
		}
		if (jumlah == 0) {
			cout << "\nData tidak Ada" << endl;
		}
	}
};


//isi disini
void algorithmaSortByTahunMasuk() {
	if (jumlahMahasiswa == 0) {
		cout << "==== DATA BELUM DIMASUKAN ====" << endl;
	}
	else {
		int tempNIM, tempTahunMasuk;
		string tempNama, tempJurusan;//variable data temporer / penyimpanan sementara
		int j; // variable J sebagai penanda

		for (int i = 1; i < jumlahMahasiswa; i++) //1. looping dengan i dimulai dari 1 hingga n - 1
		{
			tempNIM = NIM[i];
			tempNama = nama[i];
			tempJurusan = jurusan[i];
			tempTahunMasuk = tahunMasuk[i];//2. simpan nilai arr[i] ke variabel sementara temp
			j = i - 1; //3. setting nilai j sama dengan i-1
			while (j >= 0 && tahunMasuk[j] > tempTahunMasuk) //4. looping while dimana nilai j lebih besar sama dengan 0 dan array[j] lebih besar dari temp
			{
				NIM[j + 1] = NIM[j];// simpan arr[j + 1] kedalam variable arr[j]
				nama[j + 1] = nama[j];
				jurusan[j + 1] = jurusan[j];
				tahunMasuk[j + 1] = tahunMasuk[j];
				j--; // j decrement
			}
			NIM[j + 1] = tempNIM;
			nama[j + 1] = tempNama;
			jurusan[j + 1] = tempJurusan;
			tahunMasuk[j + 1] = tempTahunMasuk; // 5. simpan nilai temp ke dalam arr[j+1]
		}
		for (int i = 0; i < jumlahMahasiswa; i++) {
			cout << "\nNIM\t\t :  " << NIM[i] << endl;
			cout << "Nama\t\t :  " << nama[i] << endl;
			cout << "Jurusan\t\t :  " << jurusan[i] << endl;
			cout << "Tahun Masuk\t :  " << tahunMasuk[i] << endl << endl;
		}
	}
};

int main() {
	int pilihan;
	do {
		cout << "========== MENU MANAJEMEN DATA MAHASISWA ==========" << endl;
		cout << "1. Tambah Mahasiswa" << endl;
		cout << "2. Tampilkan Semua Mahasiswa" << endl;
		cout << "3. Cari Mahasiswa berdasarkan NIM" << endl;
		cout << "4. Tampilkan Mahasiswa berdasarkan Tahun Masuk" << endl;
		cout << "5. Keluar" << endl;
		cout << "Pilihan: ";
		cin >> pilihan;
		cin.ignore();
		switch (pilihan) {
		case 1:
			//isi disini
			tambahMahasiswa();
			break;
		case 2:
			//isi disini
			tampilkanSemuaMahasiswa();
			break;
		case 3:
			//isi disini
			algorithmacariMahasiswaByNIM();
			break;
		case 4:
			//isi disini
			algorithmaSortByTahunMasuk();
			break;
		case 5:
			cout << "Terima kasih! Program selesai." << endl;
			break;
		default:
			cout << "Pilihan tidak valid. Silakan coba lagi." << endl;
		}
		cout << endl;
	} while (pilihan != 5);
	return 0;
}

//2. Berdasarkan studi kasus diatas, algoritma apa saja yang anda gunakan ? (10 Poin)
//		a. ALgoritma InsertionSort
//		b. Traverse
// 
//3. Jelaskan perbedaan mendasar antara algorithma stack dan queue!(15 Poin)
//		Stack adalah struktur data linear yang mengikuti prinsip LIFO (Last-In, First-Out)
//		Queue adalah struktur data linear yang mengikuti prinsip FIFO (First-In, First-Out). 
// 
//4. Jelaskan pada saat bagaimana harus menggunakan algorithma stack ? (15 poin)
//	•	Contoh penggunaan stack adalah penumpukan aktivitas(rekursi), undo / redo dalam editor teks, dan evaluasi ekspresi matematika dalam notasi postfix.
// 
//  •	Operasi dasar pada stack adalah push (menambahkan elemen ke atas stack) dan pop (menghapus elemen dari atas stack).
//	•	Stack hanya memiliki akses ke elemen teratas(top) dari stack.
//	•	Operasi lain pada stack meliputi peek(melihat elemen teratas tanpa menghapusnya) dan isEmpty(memeriksa apakah stack kosong)
// 
//5. Perhatikan gambar berikut : (20 Poin)
//	a. Seberapa banyak kedalaman yang dimiliki struktur tersebut ?
//		4
// 
//	b.Bagaimana cara membaca struktur pohon di atas ? (Pilih salah satu metode yaitu
// 
//	Inorder, Preorder atau Postorder Traversal)
//	In = 1 5 8 12 15 10 20 22 25 28 30 36 38 40 45 48 50 (SALAH)
//	Preorder = 25 20 10 5 1 8 12 15 22 36 30 28 40 38 48 45 50 (BENAR)
//	Post = 1 8 5 15 12 10 22 20 28 38 45 50 48 30 40 36 25 (SALAH)