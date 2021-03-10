#include <iostream>
#include <string>

using namespace std;

class autoturism
{
private:
	string marca;
	int recenzii;
	string clasaAuto = "sedan";
	double greutate;
	char* model;
	float* pret;
	int nrPreturi;

public:
	autoturism()
	{
		marca = "Necunoscuta";
		recenzii = 0;
		greutate = 0;
		model = nullptr;
		pret = nullptr;
		nrPreturi = 0;
	}

	autoturism(string marca, int recenzii, double greutate,const char* model, float* pret, int nrPreturi)
		:autoturism()
	{
		this-> marca = marca;
		this->recenzii = recenzii;
		this->greutate = greutate;

		if(model != nullptr)
		{
			this->model = new char [strlen(model) + 1];
			strcpy_s(this->model, strlen(model) + 1, model);
		}

		if(pret != nullptr && nrPreturi > 0)
		{
			this->nrPreturi = nrPreturi;
			this->pret = new float [nrPreturi];
			for(int i = 0; i < nrPreturi; i++)
			{
				this->pret [i] = pret [i];
			}
		}
		else
		{
			model = nullptr;
			pret = nullptr;
		}
	}

	autoturism(const autoturism& a)
	{
		this->marca = a.marca;
		this->recenzii = a.recenzii;
		this->greutate = a.greutate;
		if(model != nullptr)
		{
			this->model = new char [strlen(a.model) + 1];
			strcpy_s(this->model, strlen(a.model) + 1, a.model);
		}
		if(pret != nullptr && nrPreturi > 0)
		{
			this->nrPreturi = a.nrPreturi;
			this->pret = new float [a.nrPreturi];
			for(int i = 0; i < a.nrPreturi; i++)
			{
				this->pret[i] = a.pret [i];
			}
		}
		else
		{
			model = nullptr;
			pret = nullptr;
		}
	}

	~autoturism()
	{
		if(model != nullptr)
		{
			delete [] model;
		}
		if(pret != nullptr)
		{
			delete [] pret;
		}
	}

	autoturism& operator=(const autoturism& a)
	{
		if(model != nullptr)
		{
			delete [] model;
		}
		if(pret != nullptr)
		{
			delete [] pret;
		}
		this->marca = a.marca;
		this->recenzii = a.recenzii;
		this->greutate = a.greutate;
		if(model != nullptr)
		{
			this->model = new char [strlen(a.model) + 1];
			strcpy_s(this->model, strlen(a.model) + 1, a.model);
		}
		if(pret != nullptr && nrPreturi > 0)
		{
			this->nrPreturi = a.nrPreturi;
			this->pret = new float [a.nrPreturi];
			for(int i = 0; i < a.nrPreturi; i++)
			{
				this->pret [i] = a.pret [i];
			}
		}
		else
		{
			model = nullptr;
			pret = nullptr;
		}
		return *this;
	}

	string getMarca()
	{
		return marca;
	}
	void setMarca(string marca)
	{
		this->marca = marca;
	}

	int getRecenzii()
	{
		return recenzii;
	}
	void setRecenzii(int recenzii)
	{
		this->recenzii = recenzii;
	}

	double getGreutate()
	{
		return greutate;
	}
	void setGreutate(double greutate)
	{
		this->greutate = greutate;
	}

	float* getPret()
	{
		if(pret != nullptr)
		{
			float* copie = new float [nrPreturi];
			for(int i = 0; i < nrPreturi; i++)
			{
				copie [i] = pret [i];
			}
			return copie;
		}
		else
		{
			return nullptr;
		}
	}
	void setPret(float* pret, int nrPreturi)
	{
		if(pret != nullptr && nrPreturi != 0)
		{
			this->nrPreturi = nrPreturi;
			if(this->pret != nullptr)
			{
				delete [] this->pret;
			}
			this->pret = new float [nrPreturi];
			for(int i = 0; i < nrPreturi; i++)
			{
				this->pret[i] = pret[i];
			}
		}
	}

	string getClasa()
	{
		return clasaAuto;
	}
};

int main()
{
	cout << "----------------Apel constructor implicit----------------" << endl;
	autoturism a;
	a.setMarca("Aro");
	a.setRecenzii(120);
	cout << a.getMarca() << endl;
	cout << a.getRecenzii() << endl;

	cout << "----------------Pointer la obiect----------------" << endl;
	autoturism* pa;
	pa = &a;
	cout << a.getMarca() << endl;
	cout << sizeof(a) << endl;
	autoturism a2 = a;
	cout << sizeof(a2) << endl;

	cout << "----------------Alocare dinamica obiect----------------" << endl;
	pa = new autoturism();
	cout << pa->getClasa() << endl;
	delete pa;

	float vector [2] = { 14.45, 874.4560 };
	autoturism a3("Daewoo", 4200, 1200.45, "Cielo", vector, 2);
	cout << a3.getMarca() << endl;

	for(int i = 0; i < sizeof(vector) / sizeof(float); i++)
	{
		cout << *a3.getPret()<<" ";
	}
	cout << endl;
	
	float vector2 [] = { 14500.45, 4254.45,8504.123 };
	autoturism* pa2 = new autoturism("Subaru", 7500, 1450.78,"STI", vector2, 3);
	pa2->setRecenzii(1000);
	cout << pa2->getRecenzii() << endl;
	delete  pa2;
}