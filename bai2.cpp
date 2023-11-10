#include<bits/stdc++.h>
using namespace std;

class Vemaybay{
	public:
		string tenchuyen;
		string ngaybay;
		float giave;
	public:
		Vemaybay();
		Vemaybay(string t, string d, float g);
		~Vemaybay();
		void nhap();
		void xuat();
		float getgiave();
};
Vemaybay::Vemaybay(){
}
Vemaybay::Vemaybay(string t, string d, float g){
	tenchuyen = t;
	ngaybay = d;
	giave = g;
}
Vemaybay::~Vemaybay(){
}
void Vemaybay::nhap(){
	cout <<" nhap ten chuyen :";
	cin.ignore();
	getline(cin, tenchuyen) ; cin.ignore();
	cout << "nhap ngay bay : ";
	getline(cin, ngaybay); cin.ignore();
	cout <<"nhap gia ve : ";
	cin >> giave;
}
void Vemaybay::xuat(){
	cout << "ten chuyen :"<< tenchuyen << endl;
	cout << "ngay bay :"<< ngaybay << endl;
	cout <<"gia ve :"<< giave << endl;
}
float Vemaybay::getgiave(){
	return giave;
}

class Nguoi{
	protected:
		string hoten;
		string gioitinh;
		int tuoi;
	public:
		Nguoi();
		Nguoi(string t, string g, int tuoi){
			hoten = t;
			gioitinh = g;
			this->tuoi = tuoi;
		}
		~Nguoi();
		void nhap();
		void xuat();
}; 
Nguoi::Nguoi(){
}
Nguoi::~Nguoi(){
};
void Nguoi::nhap(){
	cout << "nhap ho ten : " ; 
	cin.ignore();
	getline(cin, hoten);
	cin.ignore();
	cout <<"nhap gioi tinh : ";
	getline(cin, gioitinh);
	cin.ignore();
	cout << "nhap tuoi : ";	cin >> tuoi;
}
void Nguoi::xuat(){
	cout << hoten << endl;
	cout << gioitinh << endl;
	cout << tuoi << endl;
}

class Hanhkhach : Nguoi{
	private:
		Vemaybay * ve;
		int soluong;
	public:
		Hanhkhach(){
		}
		Hanhkhach(Vemaybay *ve, int soluong){
			for(int i = 0; i < soluong ; i ++){
				this->ve[i] = ve[i];
			}
		}
		~Hanhkhach(){
		}
		void nhap();
		void xuat();
		float tongtien();		
};
void Hanhkhach::nhap(){
	Nguoi::nhap();
	cout << "nhap so ve :";
	cin >> soluong;
	this-> ve = new Vemaybay[soluong];
	for(int i = 0; i < soluong; i ++){
		ve[i].nhap();
	}
}
void Hanhkhach::xuat(){
	Nguoi::xuat();
	for(int i = 0; i < soluong; i ++ ){
		ve[i].xuat() ;
	}
}
float Hanhkhach::tongtien(){
	float sum = 0;
	for(int i = 0; i < soluong; i ++){
		sum += ve[i].getgiave();
	}
	return sum;
}

bool cmp(Hanhkhach a, Hanhkhach b){
	return a.tongtien() > b.tongtien();
}
int main(){
	int n;
	cout << " nhap so khach : ";
	 cin >> n;
	Hanhkhach a[n];
	for(int i = 0; i < n; i ++){
		a[i].nhap();
	}
	sort(a, a + n, cmp);
	for(int i = 0; i < n; i ++){
		a[i].xuat();
		cout << "tong tien :"<< a[i].tongtien() << endl;
	}	
}
