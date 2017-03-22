#include<iostream>

#include<time.h>

using namespace std;

class Data {
private:
	int an;
	int luna;
	int zi;
	int ora;
	int minute;
	int secunde;

public:
	int get_an()
	{
		return an;
	}
	int get_luna()
	{
		return luna;
	}
	int get_zi()
	{
		return zi;
	}
	int get_ora()
	{
		return ora;
	}
	int get_minute()
	{
		return minute;
	}
	int get_secunde()
	{
		return secunde;
	}

	void set_an(int an)
	{
		if (an > 1970)
			this->an = an;
	}
	void set_luna(int luna)
	{
		if (luna > 0 && luna < 13)
			this->luna = luna;
	}
	void set_zi(int zi)
	{
		if (zi > 0 && zi < 32)
			this->zi = zi;
	}
	void set_ora(int ora)
	{
		if (ora >= 0 && ora <= 24)
			this->ora = ora;
	}
	void set_minute(int minute)
	{
		if (minute >= 0 && minute < 60)
			this->minute = minute;
	}
	void set_secunde(int secunde)
	{
		if (secunde >= 0 && secunde < 60)
			this->secunde = secunde;
	}

	Data()
	{
		an = 2015;
		luna = 8;
		zi = 13;
		ora = 12;
		minute = 30;
		secunde = 28;
	}

	Data(int an, int luna, int zi, int ora, int minute, int secunde)
	{
		this->an = an;
		this->luna = luna;
		this->zi = zi;
		this->ora = ora;
		this->minute = minute;
		this->secunde = secunde;
	}

	Data(int an, int luna, int zi)
	{
		this->an = an;
		this->luna = luna;
		this->zi = zi;
		this->ora = NULL;
		this->minute = NULL;
		this->secunde = NULL;
	}

	Data(Data &u)
	{
		this->an = u.an;
		this->luna = u.luna;
		this->zi = u.zi;
		this->ora = u.ora;
		this->minute = u.minute;
		this->secunde = u.secunde;
	}

	Data operator=(Data &temp)
	{
		this->an = temp.an;
		this->luna = temp.luna;
		this->zi = temp.zi;
		this->ora = temp.ora;
		this->minute = temp.minute;
		this->secunde = temp.secunde;
		return *this;
	}


	~Data()
	{

	}

	int prelucrare_date(Data &u) // functia va ajuta la determinarea a timpului pentrecut de o masina intr-o zona 
	{
		int s;
		s = u.ora * 3600 + u.minute * 60 + u.secunde;
		return s;
	}

	friend istream& operator>>(istream& intrare, Data &u);
	friend ostream& operator<<(ostream& iesire, Data &u);

	void afisare()
	{
		if (luna >= 3 && luna <= 5)
			cout << "Anotimpul este primavara" << endl;
		else
			if (luna >= 6 && luna <= 8)
				cout << "Anotimpul este vara" << endl;
			else
				if (luna >= 9 && luna <= 11)
					cout << "Anotimpul este toamna" << endl;
				else
					if (luna = 12 || (luna <= 2 && luna >= 1))
						cout << "Anotimpul este iarna" << endl;
		cout << "Data este: " << endl;
		if (zi < 10)
			cout << "0" << zi << "-";
		else
			cout << zi << "-";
		if (luna < 10)
			cout << "0" << luna << "-";
		else
			cout << luna << "-";
		cout << an << "  ";

		if (ora < 10)
			cout << "0" << ora << ":";
		else
			cout << ora << ":";
		if (minute < 10)
			cout << "0" << minute << ":";
		else
			cout << minute << ":";
		if (secunde < 10)
			cout << "0" << secunde << endl;
		else
			cout << secunde << endl;
	}

};

istream& operator>>(istream& intrare, Data &u)
{
	cout << "An: "; intrare >> u.an;
	cout << "Luna: "; intrare >> u.luna;
	cout << "Zi: "; intrare >> u.zi;

	cout << "Ora: "; intrare >> u.ora;
	cout << "Minutele: "; intrare >> u.minute;
	cout << "Secundele: "; intrare >> u.secunde;

	return intrare;
}

ostream& operator<<(ostream& iesire, Data &u)
{

	cout << "Data este: " << endl;
	if (u.zi < 10)
		iesire << "0" << u.zi << "-";
	else
		iesire << u.zi << "-";
	if (u.luna < 10)
		iesire << "0" << u.luna << "-";
	else
		iesire << u.luna << "-";
	iesire << u.an << "  ";

	if (u.ora < 10)
		iesire << "0" << u.ora << ":";
	else
		iesire << u.ora << ":";
	if (u.minute < 10)
		iesire << "0" << u.minute << ":";
	else
		iesire << u.minute << ":";
	if (u.secunde < 10)
		iesire << "0" << u.secunde << endl;
	else
		iesire << u.secunde << endl;
	if (u.luna >= 3 && u.luna <= 5)
		cout << "Anotimul este primavara" << endl;
	else
		if (u.luna >= 6 && u.luna <= 8)
			cout << "Anotimul este vara" << endl;
		else
			if (u.luna >= 9 && u.luna <= 11)
				cout << "Anotimul este toamna" << endl;
			else
				if (u.luna == 12 || u.luna == 2 || u.luna == 1)
					cout << "Anotimul este iarna" << endl;

	return iesire;
}

class date_geografice
{
private:
	__int64 timp;
	float latitudine;
	float longitudine;
	int viteza;

public:
	__int64 get_timp()
	{
		return timp;
	}
	float get_latitudine()
	{
		return latitudine;
	}
	float get_longitudine()
	{
		return longitudine;
	}
	int get_viteza()
	{
		return viteza;
	}

	void set_timp(__int64 timp)
	{
		if (timp > 0)
			this->timp = timp;
	}
	void set_latitudine(float lat_nou)
	{
		if (lat_nou > 0 && lat_nou < 180)
			latitudine = lat_nou;
	}
	void set_longitudine(float long_nou)
	{
		if (long_nou)
			longitudine = long_nou;
	}
	void set_viteza(int vit_noua)
	{
		if (vit_noua > 20 && vit_noua < 250)
			viteza = vit_noua;
	}

	date_geografice()
	{
		timp = 1439468124395;
		latitudine = 52.508136732688236;
		longitudine = 13.221306336558827;
		viteza = 130;
	}

	date_geografice(float latitudine, float longitudine, int viteza, __int64 timp_nou)
	{
		this->timp = timp_nou;
		this->latitudine = latitudine;
		this->longitudine = longitudine;
		this->viteza = viteza;
	}

	date_geografice(float latitudine, float longitudine)
	{
		this->timp = NULL;
		this->latitudine = latitudine;
		this->longitudine = longitudine;
		this->viteza = NULL;
	}


	date_geografice(date_geografice &s)
	{
		this->timp = s.timp;
		this->latitudine = s.latitudine;
		this->longitudine = s.longitudine;
		this->viteza = s.viteza;
	}

	date_geografice operator=(date_geografice &temp)
	{
		this->timp = temp.timp;
		this->latitudine = temp.latitudine;
		this->longitudine = temp.longitudine;
		this->viteza = temp.viteza;
		return *this;
	}

	Data ora(__int64 millis)
	{
		Data d;
		millis = millis / 1000;
		tm *timp = localtime(&millis);
		long secunde = (millis) % 60;
		long minute = (millis / (60)) % 60;
		long ora = (millis / (60 * 60)) % 24;
		long an = 1970 + (millis / 60 / 60 / 24 / 365);
		long zi = timp->tm_mday;
		long luna = 1 + timp->tm_mon;
		d.set_secunde(secunde);
		d.set_minute(minute);
		d.set_ora(ora);
		d.set_zi(zi);
		d.set_luna(luna);
		d.set_an(an);
		return d;
	}

	~date_geografice()
	{

	}

	void afisare()
	{
		cout << "Timpul: " << timp << endl;
		cout << "Latitudine: " << latitudine << endl;
		cout << "Longitudine: " << longitudine << endl;
		cout << "Viteza: " << viteza << endl;
	}

	friend ostream& operator<<(ostream& iesire, date_geografice &dg);
	friend istream& operator>>(istream& intrare, date_geografice &dg);
};

ostream& operator<<(ostream& iesire, date_geografice &dg)
{
	iesire << "Timpul: " << dg.timp << endl;
	dg.ora(dg.timp);
	Data d = dg.ora(dg.timp);
	cout << d;
	iesire << "Latitudine: " << dg.latitudine << endl;
	iesire << "Longitudine: " << dg.longitudine << endl;
	iesire << "Viteza: " << dg.viteza << endl;
	return iesire;
}

istream& operator>>(istream& intrare, date_geografice &dg)
{
	cout << "Timpul: "; intrare >> dg.timp;
	cout << "Latitudinea: "; intrare >> dg.latitudine;
	cout << "Longitudinea: "; intrare >> dg.longitudine;
	cout << "Viteza: "; intrare >> dg.viteza;
	return intrare;
}

class masina {
private:
	char* nume_masina;
	int vit_max;
	int vit_medie_urb;
	int vit_medie;
	int nr_pozitii;
	date_geografice* gps;
	static int nr_masini;
	const int id;

public:
	char* get_nume_masina()
	{
		return nume_masina;
	}
	int get_vit_max()
	{
		return vit_max;
	}
	int get_vit_medie_urb()
	{
		return vit_medie_urb;
	}
	int get_vit_medie()
	{
		return vit_medie;
	}
	int get_nr_pozitii()
	{
		return nr_pozitii;
	}
	static int get_nr_masini()
	{
		return nr_masini;
	}
	const int get_id()
	{
		return id;
	}
	date_geografice* get_gps()
	{
		return gps;
	}

	void set_nume(char *nume_nou)
	{
		if (nume_masina != NULL)
		{
			delete[] nume_masina;
		}
		nume_masina = new char[strlen(nume_nou) + 1];
		strcpy(nume_masina, nume_nou);
	}
	void set_vit_max(int vit_max_nou)
	{
		if (vit_max_nou > 80 && vit_max_nou < 300)
			vit_max = vit_max_nou;
	}
	void set_vit_medie_urb(int vit_medieurb_nou)
	{
		if (vit_medieurb_nou > 50)
			vit_medie_urb = vit_medieurb_nou;
	}
	void set_vit_medie(int vit_medie_noua)
	{
		if (vit_medie_noua > 40)
			vit_medie = vit_medie_noua;
	}
	void set_nr_poztii(int nr_pozitii)
	{
		if (nr_pozitii > 0)
			this->nr_pozitii = nr_pozitii;
	}
	void set_static_nr_masini(int nr_masini)
	{
		if (nr_masini > 0)
			this->nr_masini = nr_masini;
	}
	class motor {
	private:
		char* tip;
		int capacitate_cilindrica;
		int consum_mediu_oras;
		int consum_mediu;

	public:
		char* get_tip()
		{
			return tip;
		}
		int get_capacitate_cilindrica()
		{
			return capacitate_cilindrica;
		}
		int get_consum_mediu_oras()
		{
			return consum_mediu_oras;
		}
		int get_consum_mediu()
		{
			return consum_mediu;
		}

		void set_tip(char* tip)
		{
			if (this->tip != NULL)
				delete[] this->tip;
			if (tip != NULL)
			{
				this->tip = new char[strlen(tip) + 1];
				strcpy(this->tip, tip);
			}
		}
		void set_cap_cil(int cap_cil_nou)
		{
			if (cap_cil_nou < 3000)
				capacitate_cilindrica = cap_cil_nou;
		}
		void set_consum_mediu_oras(int cons_nou_oras)
		{
			if (cons_nou_oras < 20)
				consum_mediu_oras = cons_nou_oras;
		}
		void set_consum_mediu(int cons_mediu_nou)
		{
			if (cons_mediu_nou < 15)
				consum_mediu = cons_mediu_nou;
		}

		motor()
		{
			tip = new char[strlen("Motor") + 1];
			strcpy(tip, "Motor");
			capacitate_cilindrica = 1500;
			consum_mediu_oras = 12;
			consum_mediu = 8;
		}
		motor(char* tip, int capacitate_cilindrica, int consum_mediu_oras, int consum_mediu)
		{
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
			this->capacitate_cilindrica = capacitate_cilindrica;
			this->consum_mediu_oras = consum_mediu_oras;
			this->consum_mediu = consum_mediu;
		}
		motor(char* tip)
		{
			this->tip = new char[strlen(tip) + 1];
			strcpy(this->tip, tip);
			this->capacitate_cilindrica = NULL;
			this->consum_mediu_oras = NULL;
			this->consum_mediu = NULL;
		}
		motor(motor &m)
		{
			this->tip = new char[strlen(m.tip) + 1];
			strcpy(this->tip, m.tip);
			this->capacitate_cilindrica = m.capacitate_cilindrica;
			this->consum_mediu_oras = m.consum_mediu_oras;
			this->consum_mediu = m.consum_mediu;
		}
		motor operator=(motor &temp)
		{
			if (this->tip != NULL)
				delete[] this->tip;
			this->tip = new char[strlen(temp.tip) + 1];
			strcpy(this->tip, temp.tip);
			this->capacitate_cilindrica = temp.capacitate_cilindrica;
			this->consum_mediu_oras = temp.consum_mediu_oras;
			this->consum_mediu = temp.consum_mediu;
			return *this;
		}

		~motor()
		{
			delete[] tip;
		}

		void afisare()
		{
			cout << "Tipul motorului este: " << tip << endl;
			cout << "Motorul are capacitatea cilindrica de: " << capacitate_cilindrica << endl;
			cout << "Consumul mediu in oras este: " << consum_mediu_oras << endl;
			cout << "Consumul mediu al masinii este: " << consum_mediu << endl;
		}
		/*void consum_combustibil_oras(int rezervor, int nr_km_oras)
		{
		if (rezervor -= nr_km_oras * consum_mediu_oras / 100 > 0)
		rezervor -= nr_km_oras * consum_mediu_oras / 100;
		else
		throw "Insuficient combustibil";
		}*/
		float consum_combustibil(float rezervor, int nr_km)
		{
			if ((float)(rezervor - (float)nr_km * (float)consum_mediu / 100) > 0)
			{
				rezervor = (float)(rezervor - (float)nr_km * (float)consum_mediu / 100);
				return rezervor;
			}
			else
				throw "Nu este suficient combustibil";
		}

		friend istream& operator>>(istream& intrare, masina::motor &t);
		friend ostream& operator<<(ostream& iesire, masina::motor &t);
	}motorul;

	masina() :id(masina::nr_masini + 1)
	{
		nume_masina = new char[strlen("Masina") + 1];
		strcpy(nume_masina, "Masina");
		vit_max = 160;
		vit_medie_urb = 60;
		vit_medie = 80;
		nr_pozitii = 1;
		gps = new date_geografice[nr_pozitii];
		for (int i = 0; i < nr_pozitii; i++)
		{
			date_geografice a;
			gps[i] = a;
		}
		masina::motor();
		masina::nr_masini++;
	}

	masina(char* nume_masina, int vit_max, int vit_medie_urb, int vit_medie, int nr_pozitii, date_geografice *f, masina::motor c, int id_nou) : id(id_nou)
	{
		this->nume_masina = new char[strlen(nume_masina) + 1];
		strcpy(this->nume_masina, nume_masina);
		this->vit_max = vit_max;
		this->vit_medie_urb = vit_medie_urb;
		this->vit_medie = vit_medie;
		this->nr_pozitii = nr_pozitii;
		gps = new date_geografice[nr_pozitii];
		for (int i = 0; i < nr_pozitii; i++)
		{
			date_geografice a;
			a = f[i];
			gps[i] = a;
		}
		masina::motorul = c;
		masina::nr_masini++;
	}

	masina(char* nume_masina, int vit_max, int vit_medie, int id_nou, masina::motor d) :id(id_nou)
	{
		this->nume_masina = new char[strlen(nume_masina) + 1];
		strcpy(this->nume_masina, nume_masina);
		this->vit_max = vit_max;
		this->vit_medie = vit_medie;
		this->vit_medie_urb = NULL;
		this->nr_pozitii = 0;
		date_geografice gps(0, 0, 0, 0);
		masina::motorul = d;
		masina::nr_masini++;

	}

	masina(masina &s) : id(s.id)
	{
		this->nume_masina = new char[strlen(s.nume_masina) + 1];
		strcpy(this->nume_masina, s.nume_masina);
		this->vit_max = s.vit_max;
		this->vit_medie_urb = s.vit_medie_urb;
		this->vit_medie = s.vit_medie;
		this->nr_pozitii = s.nr_pozitii;
		this->gps = new date_geografice[nr_pozitii];
		for (int i = 0; i < nr_pozitii; i++)
		{
			this->gps[i] = s.gps[i];
		}
		masina::motorul = s.motorul;
		masina::nr_masini++;
	}

	masina operator=(masina &temp)
	{
		if (nume_masina != NULL)
			delete[] nume_masina;
		nume_masina = new char[strlen(temp.nume_masina) + 1];
		strcpy(nume_masina, temp.nume_masina);
		vit_max = temp.vit_max;
		vit_medie_urb = temp.vit_medie_urb;
		vit_medie = temp.vit_medie;
		nr_pozitii = temp.nr_pozitii;
		gps = new date_geografice[temp.nr_pozitii];
		for (int i = 0; i < temp.nr_pozitii; i++)
		{
			gps[i] = temp.gps[i];
		}
		masina::motorul = temp.motorul;
		return *this;
	}

	~masina()
	{
		masina::nr_masini--;
		delete[] nume_masina;
	}

	void afisare()
	{
		cout << "Idul unic al masinii este: auto " << id << endl;
		cout << "Marca masinii este: " << nume_masina << endl;
		cout << "Viteza maxima a masinii este: " << vit_max << endl;
		cout << "Viteza medie in oras este: " << vit_medie_urb << endl;
		cout << "Viteza medie a masinii este: " << vit_medie << endl;
		cout << "Acum numarul total de masini este: " << nr_masini << endl;
		for (int i = 0; i < nr_pozitii; i++)
			cout << gps[i] << endl;
		masina::motorul.afisare();
	}

	void modficare_vit_medie() // creste viteza medie pana atinge un maxim, ex: 100 km/h- pt ca masina sa parcurga distanta intr-un timp mai scurt si fara modificari mari ale consumului
	{
		while (vit_medie < 100)
			vit_medie++;
	}

	friend ostream& operator<<(ostream& iesire, masina &m);
	friend istream& operator>>(istream& intrare, masina &m);

};

int masina::nr_masini = 0;

istream& operator>>(istream& intrare, masina::motor &t)
{
	char aux2[20];
	cout << "Tipul motorului este (Gasoline/Diesel/Hibryd): "; intrare >> aux2;
	delete[] t.tip;
	t.tip = new char[strlen(aux2) + 1];
	strcpy(t.tip, aux2);
	cout << "Motorul are capacitatea cilindrica de: "; intrare >> t.capacitate_cilindrica;
	cout << "Consumul mediu in oras este: "; intrare >> t.consum_mediu_oras;
	cout << "Consumul mediu al masinii este: "; intrare >> t.consum_mediu;

	return intrare;
}

ostream& operator<<(ostream& iesire, masina::motor &t)
{
	iesire << "Tipul motorului este: " << t.tip << endl;
	iesire << "Motorul are capacitatea cilindrica de: " << t.capacitate_cilindrica << endl;
	iesire << "Consumul mediu in oras este: " << t.consum_mediu_oras << endl;
	iesire << "Consumul mediu al masinii este: " << t.consum_mediu << endl;
	return iesire;
}

istream& operator>>(istream& intrare, masina &m)
{
	delete[] m.nume_masina;
	char aux[20];
	cout << "Marca masinii este: "; intrare >> aux;
	m.nume_masina = new char[strlen(aux) + 1];
	strcpy(m.nume_masina, aux);
	cout << "Viteza maxima a masinii este: "; intrare >> m.vit_max;
	cout << "Viteza medie in oras este: "; intrare >> m.vit_medie_urb;
	cout << "Viteza medie a masinii este: "; intrare >> m.vit_medie;
	cout << "Introduceti datele geografice: (clasa date_geografice) " << endl;
	cout << "Introduceti numarul de pozitii in care s-a aflat masina: ";
	intrare >> m.nr_pozitii;
	delete[] m.gps;
	m.gps = new date_geografice[m.nr_pozitii];
	cout << "Coordonatele masinii sunt: " << endl;
	for (int i = 0; i < m.nr_pozitii; i++)
		intrare >> m.gps[i];
	cout << "Introduceti datele despre motor: " << endl;
	cin >> m.motorul;
	return intrare;
}

ostream& operator<<(ostream& iesire, masina &m)
{
	iesire << "Idul unic al masinii este: auto " << m.id << endl;
	iesire << "Marca masinii este: " << m.nume_masina << endl;
	iesire << "Viteza maxima a masinii este: " << m.vit_max << endl;
	iesire << "Viteza medie in oras este: " << m.vit_medie_urb << endl;
	iesire << "Viteza medie a masinii este: " << m.vit_medie << endl;
	iesire << "Numarul total de pozitii al masinii este: " << m.nr_pozitii << endl;
	if (m.nr_pozitii != 0)
		cout << "Introduceti datele geografice: (clasa date_geografice) " << endl;
	else
		cout << "Nu se cunosc datele geografice; " << endl;
	for (int i = 0; i < m.nr_pozitii; i++)
		iesire << endl << m.gps[i] << endl;
	iesire << "Datele despre motor sunt: " << endl;
	cout << m.motorul;
	return iesire;
}

class spatiu
{
private:
	char* tip;
	char* restrictie;
	int raza;
	float point_coord[3];
	float colt_stangasus_coord[3];
	float colt_dreaptajos_coord[3];

public:
	char* get_tip()
	{
		return tip;
	}
	char* get_restrictie()
	{
		return restrictie;
	}
	int get_raza()
	{
		return raza;
	}
	float* get_point_coord()
	{
		return point_coord;
	}
	float* get_colt_stangasus_coord()
	{
		return colt_stangasus_coord;
	}
	float* get_colt_dreaptajos_coord()
	{
		return colt_dreaptajos_coord;
	}

	void set_tip(char* tip)
	{
		if (this->tip != NULL)
			delete[] this->tip;
		if (tip != NULL)
		{
			this->tip = new char[strlen(tip)];
			strcpy(this->tip, tip);
		}
	}
	void set_restrictie(char* restrictie)
	{
		if (this->restrictie != NULL)
			delete[] this->restrictie;
		if (restrictie != NULL)
		{
			this->restrictie = new char[strlen(restrictie) + 1];
			strcpy(this->restrictie, restrictie);
		}
	}
	void set_raza(int raza)
	{
		if (raza > 0)
			this->raza = raza;
	}
	void set_point_coord(float lati, float longi)
	{
		if ((lati >= -90 && lati <= 90) && (longi <= 180 && longi >= -180))
		{
			point_coord[1] = lati;
			point_coord[2] = longi;
		}
	}
	void set_colt_stangasus_coord(float lati, float longi)
	{
		if ((lati >= -90 && lati <= 90) && (longi <= 180 && longi >= -180))
		{
			colt_stangasus_coord[1] = lati;
			colt_stangasus_coord[2] = longi;
		}
	}
	void set_colt_dreaptajos_coord(float lati, float longi)
	{
		if ((lati >= -90 && lati <= 90) && (longi <= 180 && longi >= -180))
		{
			colt_dreaptajos_coord[1] = lati;
			colt_dreaptajos_coord[2] = longi;
		}
	}

	spatiu()
	{
		this->tip = new char[strlen("circle") + 1];
		strcpy(tip, "circle");
		this->restrictie = new char[strlen("red") + 1];
		strcpy(restrictie, "red");
		point_coord[1] = 52.51520937766697; // latitudinea
		point_coord[2] = 13.18619331910953; //longitudinea
		raza = 50;

		colt_stangasus_coord[1] = 0;
		colt_stangasus_coord[2] = 0;
		colt_dreaptajos_coord[1] = 0;
		colt_dreaptajos_coord[2] = 0;
	}

	spatiu(char* tip, char* restrictie, int raza, float* point_coord, float* colt_stangasus_coord, float* colt_dreaptajos_coord)
	{
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
		this->point_coord[1] = point_coord[1]; // latitudinea
		this->point_coord[2] = point_coord[2]; //longitudinea

		this->colt_stangasus_coord[1] = colt_stangasus_coord[1];
		this->colt_stangasus_coord[2] = colt_stangasus_coord[2];
		this->colt_dreaptajos_coord[1] = colt_dreaptajos_coord[1];
		this->colt_dreaptajos_coord[2] = colt_dreaptajos_coord[2];
		this->raza = raza;
	}

	spatiu(char *tip, char* restrictie)
	{
		this->tip = new char[strlen(tip) + 1];
		strcpy(this->tip, tip);
		this->raza = NULL;
		this->restrictie = new char[strlen(restrictie) + 1];
		strcpy(this->restrictie, restrictie);
		this->point_coord[1] = NULL;
		this->point_coord[2] = NULL;
		this->colt_stangasus_coord[1] = NULL;
		this->colt_stangasus_coord[2] = NULL;
		this->colt_dreaptajos_coord[1] = NULL;
		this->colt_dreaptajos_coord[2] = NULL;
	}

	spatiu(spatiu &s)
	{
		this->tip = new char[strlen(s.tip) + 1];
		strcpy(this->tip, s.tip);
		this->restrictie = new char[strlen(s.restrictie) + 1];
		strcpy(this->restrictie, s.restrictie);
		this->point_coord[1] = s.point_coord[1]; // latitudinea
		this->point_coord[2] = s.point_coord[2]; //longitudinea
		this->colt_stangasus_coord[1] = s.colt_stangasus_coord[1];
		this->colt_stangasus_coord[2] = s.colt_stangasus_coord[2];
		this->colt_dreaptajos_coord[1] = s.colt_dreaptajos_coord[1];
		this->colt_dreaptajos_coord[2] = s.colt_dreaptajos_coord[2];
		this->raza = s.raza;

	}

	spatiu operator=(spatiu &temp)
	{
		delete[] this->tip;
		this->tip = new char[strlen(temp.tip) + 1];
		strcpy(this->tip, temp.tip);
		delete[] this->restrictie;
		this->restrictie = new char[strlen(temp.restrictie) + 1];
		strcpy(this->restrictie, temp.restrictie);
		this->point_coord[1] = temp.point_coord[1]; // latitudinea
		this->point_coord[2] = temp.point_coord[2]; //longitudinea
		this->colt_stangasus_coord[1] = temp.colt_stangasus_coord[1];
		this->colt_stangasus_coord[2] = temp.colt_stangasus_coord[2];
		this->colt_dreaptajos_coord[1] = temp.colt_dreaptajos_coord[1];
		this->colt_dreaptajos_coord[2] = temp.colt_dreaptajos_coord[2];
		this->raza = temp.raza;
		return *this;
	}

	~spatiu()
	{
		if (tip != NULL)
			delete[] tip;
		if (restrictie != NULL)
			delete[] restrictie;
	}

	void afisare()
	{
		cout << "Tipul spatiului este: " << tip << endl;
		cout << "Restrictie: " << restrictie << endl;
		cout << "Point: " << endl;
		cout << "Raza: " << raza << endl;
		cout << "Latitudine: " << point_coord[1] << endl;
		cout << "Longitudine: " << point_coord[2] << endl;
		cout << "Colturile: dreapta sus si stanga jos" << endl;
		cout << "Coltul stanga sus" << endl;
		cout << "Latitudine: " << colt_stangasus_coord[1] << endl;
		cout << "Longitudine: " << colt_stangasus_coord[2] << endl;
		cout << "Coltul dreapta jos" << endl;
		cout << "Latitudine: " << colt_dreaptajos_coord[1] << endl;
		cout << "Longitudine: " << colt_dreaptajos_coord[2] << endl;
	}

	void parcurgere_pe_diametru(int dist_parcursa) // functia este utilizata in cazul in care masina parcurge cercul pe diamtru
	{
		if (2 * raza - dist_parcursa > 0)
			raza = (2 * raza - dist_parcursa) / 2; // se verifica din diamtrul cercului cat a fost parcus
		else
			throw "Masina a iesit din cerc";
	}

	friend istream& operator>>(istream& intrare, spatiu &s);
	friend ostream& operator<<(ostream& iesire, spatiu &s);
};

istream& operator>>(istream& intrare, spatiu &s)
{
	cout << "Tipul spatiului este: (Circle/Rectangle) ";
	char aux[20];
	intrare >> aux;
	delete[] s.tip;
	s.tip = new char[strlen(aux) + 1];
	strcpy(s.tip, aux);
	cout << "Restrictie: (Red/Green/Yellow) ";
	intrare >> aux;
	s.restrictie = new char[strlen(aux) + 1];
	strcpy(s.restrictie, aux);
	cout << "Point(Latitudine si Longitudine) si Raza: - (Daca este dreptunghi initializati cu 0): " << endl;
	cout << "Latitudine: "; intrare >> s.point_coord[1];
	cout << "Longitudine: "; intrare >> s.point_coord[2];
	cout << "Raza: "; intrare >> s.raza;
	cout << "Colturile: dreapta sus si stanga jos - daca este cerc initializati cu 0" << endl;
	cout << "Coltul stanga sus" << endl;
	cout << "Latitudine: ";  intrare >> s.colt_stangasus_coord[1];
	cout << "Longitudine: ";  intrare >> s.colt_stangasus_coord[2];
	cout << "Coltul dreapta jos" << endl;
	cout << "Latitudine: ";  intrare >> s.colt_dreaptajos_coord[1];
	cout << "Longitudine: ";  intrare >> s.colt_dreaptajos_coord[2];
	return intrare;
}

ostream& operator<<(ostream& iesire, spatiu &s)
{
	iesire << "Tipul spatiului este: ";
	iesire << s.tip << endl;
	iesire << "Restrictie: ";
	iesire << s.restrictie << endl;
	iesire << "Raza: "; iesire << s.raza << endl;
	iesire << "Point: " << endl;
	iesire << "Latitudine: "; iesire << s.point_coord[1] << endl;
	iesire << "Longitudine: "; iesire << s.point_coord[2] << endl;
	iesire << "Colturile: dreapta sus si stanga jos" << endl;
	iesire << "Coltul stanga sus" << endl;
	iesire << "Latitudine: ";  iesire << s.colt_stangasus_coord[1] << endl;
	iesire << "Longitudine: "; iesire << s.colt_stangasus_coord[2] << endl;
	iesire << "Coltul dreapta jos" << endl;
	iesire << "Latitudine: ";  iesire << s.colt_dreaptajos_coord[1] << endl;
	iesire << "Longitudine: ";  iesire << s.colt_dreaptajos_coord[2] << endl;
	return iesire;
}

void main()
{
	char x;

	cout << "Testarea clasei Data(Introducere an, luna, zi, ora, minute, secunde):" << endl;
	cout << "Clasa este folosita pentru memorarea momentului de timp (dupa tranformare in UTC)" << endl;
	cout << "in care o masina se afla intr-o anumita pozitie " << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << endl << "CONSTRUCTORII: " << endl;
	Data d1;
	cout << endl << "Testare constructor fara parametri, citirea si afisarea:" << endl;
	cout << endl;
	d1.afisare();
	Data d2(2015, 8, 10, 12, 40, 50);
	cout << endl << "Testare constructor cu toti parametri:" << endl;
	cout << endl << d2;
	Data d3(2015, 7, 25);
	cout << endl << "Afisarea clasei prin apelul constructorului cu 3 parametri:" << endl;
	cout << endl << d3;

	Data d4;
	cout << endl << "Testare constructor fara parametri" << endl;
	d4.afisare();

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	cout << endl << "Testare >> si <<" << endl;
	cin >> d4;
	cout << endl << d4;

	cout << endl << "Testare getteri si setteri: " << endl;
	cout << "Get pentru an: " << d3.get_an();
	d3.set_an(2014);
	cout << "-dupa setter: " << d3.get_an() << endl;
	cout << "luna: " << d1.get_luna() << " ";
	d1.set_luna(5);
	cout << d1.get_luna() << endl;
	cout << "zi: " << d1.get_zi() << " ";
	d1.set_zi(7);
	cout << d1.get_zi();

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	cout << "Testare functia de prelucrare (tranformare din ore, minute, secunde in secunde): " << endl;
	int suma;
	cout << d2;
	suma = d2.prelucrare_date(d2);
	cout << "Dupa prelucrare: " << endl;
	cout << suma << endl;

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	cout << endl << "Testare clasa masina si clasa motorul(apartine clasei masina) " << endl;

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	masina m;
	cout << endl << "Testare functia de afisare - pt constructor fara parametri: " << endl;
	cout << endl << m;
	masina::motor c("Gasoline", 1000, 11, 8);
	date_geografice mg[] = {
		date_geografice(12.5, 15.4, 120, 14923121355),
		date_geografice(14.5, 13.4, 10, 14923546555)
	};

	cout << endl << "Testare: constructor cu toti parametri: " << endl;

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	masina m2("Dacia", 280, 100, 60, 2, mg, c, 2);
	cout << endl << m2;
	cout << endl << "Testare: constructor cu 4 parametri, respectiv un parametru pentru clasa Motor: " << endl;
	masina::motor d("Diesel");
	masina m22("Dacia", 250, 100, 50, d);
	cout << endl << m22;

	cout << endl << "Testare constructor copiere: " << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	masina m3 = m2;
	cout << endl << m3;
	cout << endl << "Testarea operator= :" << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	masina m4;
	m4 = m2;
	cout << endl << m4;
	cout << endl << "Testare functia de prelucrare: (Masina)-functia va creste viteza medie pana la 100 km daca este posibil" << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << "Viteza actuala: " << m.get_vit_medie();
	m.modficare_vit_medie();
	cout << " -dupa prelucrare: " << m.get_vit_medie() << endl;

	cout << endl << "Testare functia de prelucrare: (Motor):  " << endl;
	float combustibil;
	cout << "Va verifica daca masina poate parcurge o anumita distanta cu cantitatea de combustibil din rezervor" << endl;
	cout << "Cantitatea de combustibil din rezervor este: (litri): "; cin >> combustibil;
	int distanta;
	cout << "Distanta ce trebuie parcursa este: (km): "; cin >> distanta;
	try {
		m.motorul.consum_combustibil(combustibil, distanta);
		cout << "Distanta poate fi parcursa si ramane o cantitate de combustibil de: " << (float)m.motorul.consum_combustibil(combustibil, distanta) << endl;
	}
	catch (char* problema)
	{
		cout << problema << endl;
	}
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << endl << "Testare setter si getter: " << endl;
	cout << "Getter pentru gps: " << endl;
	for (int i = 0; i < m.get_nr_pozitii(); i++)
		cout << m.get_gps()[i] << endl;
	cout << "1. Masina: " << endl;
	cout << "Inainte de modificare viteza maxima: " << m.get_vit_max();
	m.set_vit_max(200);
	cout << " -dupa modificare: " << m.get_vit_max() << endl;
	cout << "2. Motor: " << endl;
	cout << "Inainte de setter capacitatea cilindrica: " << m.motorul.get_capacitate_cilindrica();
	m.motorul.set_cap_cil(1357);
	cout << " -dupa modificare: " << m.motorul.get_capacitate_cilindrica() << endl;

	cout << endl << "Testare operator>> " << endl;

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << endl;

	masina m5;
	cin >> m5;
	cout << endl << m5;

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << endl << "Testul pentru CLASA SPATIU: " << endl;
	cout << endl << "Constructor fara parametri: " << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	spatiu s;
	s.afisare();
	cout << endl;
	cout << endl << "Constructor cu 2 parametri: " << endl;
	spatiu s2("circle", "red");
	cout << endl << s2 << endl;
	float o[3], colt1[3], colt2[3];
	o[1] = 22.4;
	o[2] = 25.6;
	colt1[1] = 0;
	colt1[2] = 0;
	colt2[1] = 0;
	colt2[2] = 0;
	cout << endl << "Constructor cu toti parametri: " << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	spatiu s3("circle", "green", 50, o, colt1, colt2);
	cout << endl << s3 << endl;

	cout << endl << "Constructorul de copiere: " << endl;
	spatiu s5(s3);
	cout << endl << s5 << endl;

	cout << endl << "Operatorul= :" << endl;
	spatiu s4;
	s4 = s2;
	cout << endl << s4 << endl;

	cout << endl << "Testare setter: " << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << endl << "Valoarea razei inainte de setter " << s.get_raza() << " -dupa modificare: ";
	s.set_raza(85);
	cout << s.get_raza() << endl;

	cout << endl << "Functia ce verifica ce distanta a ramas neparcursa din diametrul cercului";

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	cout << endl << "(1.Daca masina parcurge cercul pe diametru sau 2*R, unde R=85, iar distanta parcursa este: 60)";
	try {
		s.parcurgere_pe_diametru(60);
		cout << endl << "Distanta ramasa: " << s.get_raza() << endl;
	}
	catch (char *exceptie)
	{
		cout << exceptie;
	}
	cout << endl << "2.Caz in care distanta parcursa este 180, iar raza 85";

	try {
		s.parcurgere_pe_diametru(180);
		cout << endl << "Distanta ramasa: " << s.get_raza() << endl;
	}
	catch (char *exceptie)
	{
		cout << endl << exceptie << endl;
	}
	cout << endl << "Setteri si Getteri: " << endl;
	cout << "Restrictie: " << s.get_restrictie();
	s.set_restrictie("green");
	cout << " -dupa modificare: " << s.get_restrictie() << endl;

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;

	cout << "Testare operator >>" << endl;
	cin >> s;
	cout << endl << "Afisare citire: " << endl;
	cout << endl << s;

	cout << endl << "Testare clasa Date_geografice: " << endl;

	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << "Testare constructori: " << endl;
	cout << endl << "Constructor fara parametri: " << endl;
	date_geografice dg;
	cout << dg << endl;
	cout << endl << "Constructor cu toti parametri: " << endl;
	date_geografice dg2(12.34555512, 42.6412222, 120, 1439467798552); // afisarea zecimalelor nu este exacta
	cout << dg2 << endl;
	cout << endl << "Constructor cu mai putini parametri: " << endl;
	date_geografice dg3(32.65554, 43.77455);
	cout << dg3 << endl;
	cout << endl << "Constructor de copiere: " << endl;
	date_geografice dg4 = dg2;
	cout << dg4 << endl;
	cout << endl << "Operatorul egal: " << endl;
	date_geografice dg5;
	dg5 = dg2;
	cout << dg5;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << "Functia de prelucrare: (fiind folosita de fiecare data cand se afiseaza timp in milisecunde" << endl;
	cout << "si trebuie transformat in UTC)" << endl;
	cout << dg2.ora(dg2.get_timp());
	cout << endl << "Testare setteri si getteri: " << endl;
	cout << endl << "Press any key to continue: [a-z][1-9] ";
	cin >> x;
	cout << "Forma initiala - Forma finala" << endl;
	cout << "Latitudine: " << dg.get_latitudine() << " - ";
	dg.set_latitudine(45.7236);
	cout << dg.get_latitudine() << endl;
	cout << "Longitudine: " << dg.get_longitudine() << " - ";
	dg.set_longitudine(47.8935);
	cout << dg.get_longitudine() << endl;
	cout << "Viteza: " << dg.get_viteza() << " - ";
	dg.set_viteza(150);
	cout << dg.get_viteza() << endl;
	cout << "Testare operator >>" << endl;
	cin >> dg;
	cout << endl << "Afisare citire: " << endl;
	cout << endl << dg;
}