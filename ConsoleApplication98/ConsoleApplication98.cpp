#pragma once
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <Windows.h>
#include <string.h>


using namespace std;

class People
{
private:

	int countid;
	char* Fio;

public:
	People();
	People(int _countid, const char* _fio);

	People(const People& obj);

	~People();

	void ShowPeople(int countpeople, People* p);

	People& operator =(const People& obj);

	People(const People& obj);

};

/////////////////////////////////////////////////////////////////////

class Flat
{
private:

	int* flat_number;
	People* PeopleFlat;

public:

	Flat();
	Flat(int _f, int countflat, People* p);

	void initFlat(int countflat, People* p);

	void ShowFlat(int countflat, int countpeople, People* p);

	Flat(const Flat& obj);

	~Flat();

};

//////////////////////////////////////////////////////////////////////////////////////////////////

class House
{
private:

	int house_number;
	Flat* HouseFlat;

public:

	House();
	House(int _h, Flat* _f);

	void init(int _h, int countflat, Flat* f);
	void ShowHouse(int countflat, int countpeople, People* p);

	House(const House& obj);

	~House();
};

//////////////////////////////////////////////////////////////////////////////////////////////////

People::People()
{
	countid = 0;
	Fio = new char[7] { "NoName" };
}

People::People(int _countid, const char* _fio)
{
	int FullName;
	FullName = strlen(_fio);

	Fio = new char[FullName + 1];

	countid = _countid;
	strcpy(Fio, _fio);
}

People::People(const People& obj)
{
	int FullName, countid;
	FullName = strlen(obj.Fio);

	countid = obj.countid;

	Fio = new char[FullName + 1];
	strcpy(Fio, obj.Fio);
}

People::~People()
{
	delete[]Fio;
}

void People::ShowPeople(int countpeople, People* p)
{

	cout << "FIO: " << endl;

	for (size_t i = 0; i < countpeople; i++)
	{
		cout << p[i].Fio << endl;
	}

}

People& People::operator=(const People& obj)
{
	if (Fio != nullptr)
	{
		delete[]Fio;
	}

	int length = strlen(obj.Fio);
	Fio = new char[length + 1];

	strcpy(Fio, obj.Fio);

	return *this;
}

People::People(const People& obj)
{
	int length = strlen(obj.Fio);
	Fio = new char[length + 1];

	strcpy(Fio, obj.Fio);
}


//////////////////////////////////////////////////////////////////////////////////////////////////

Flat::Flat()
{
	flat_number = nullptr;
	PeopleFlat = nullptr;
}

Flat::Flat(int _f, int countflat, People* p)
{
	flat_number[countflat] = _f;
	PeopleFlat = p;
}

void Flat::initFlat(int countflat, People* p)
{
	flat_number = new int[countflat] { 7, 2, 3 };
	PeopleFlat = p;
}

void Flat::ShowFlat(int countflat, int countpeople, People* p)
{
	cout << "HoMePa KBaPTuP: ";
	for (size_t i = 0; i < countflat; i++)
	{
		cout << Flat::flat_number[i];
		if (i != countflat - 1)
			cout << ", ";
		else
			cout << ".";
	}
	cout << endl;
	PeopleFlat->ShowPeople(countpeople, p);
}

Flat::Flat(const Flat& obj)
{
	flat_number = obj.flat_number;
	PeopleFlat = obj.PeopleFlat;
}

Flat::~Flat()
{
	delete[] flat_number;
	delete[] PeopleFlat;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////

House::House()
{
	house_number = 0;
	HouseFlat = nullptr;
}

House::House(int _h, Flat* _f)
{
	house_number = _h;
	HouseFlat = _f;
}

void House::init(int _h, int countflat, Flat* f)
{
	this->house_number = _h;
	HouseFlat = f;
}

void House::ShowHouse(int countflat, int countpeople, People* p)
{
	cout << "HoMeP DoMa: " << house_number << endl;
	HouseFlat->ShowFlat(countflat, countpeople, p);
}

House::House(const House& obj)
{
	house_number = obj.house_number;
	HouseFlat = obj.HouseFlat;
}

House::~House()
{
	HouseFlat = nullptr;
	delete[] HouseFlat;
}

/////////////////////////////////////////////////////////////////////////////////////

int main()
{


	int countid = 1;

	int countpeople = 3;

	int counhouse = 1;

	int countflat = 3;

	People* p = new People[countpeople]
	{
		{countid++, "KoCTuH AHDPeu UgoPEBuch"},
		{countid++, "3auKoB APCeHUu OlegOBuch"},
		{countid++, "FeHyaK CTaHuClaB BlaDuMuPoBuch"}
	};




	p->ShowPeople(countpeople, p);

	cout << endl;
	cout << "-------------------";
	cout << endl;

	Flat f;

	f.initFlat(countflat, p);

	f.ShowFlat(countflat, countpeople, p);

	cout << endl;
	cout << "-------------------";
	cout << endl;

	House h;
	h.init(20, countflat, &f);

	h.ShowHouse(countflat, countpeople, p);

	cout << endl;
	cout << "-------------------";
	cout << endl;
}