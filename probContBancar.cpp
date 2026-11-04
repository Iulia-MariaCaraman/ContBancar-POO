#include<iostream>
#include<string>

using namespace std;

enum TipCont {
	CURENT,
	ECONOMII,
	INVESTITII
};
class ContBancar {
	string titular;
	int nrTranzactii;
	float* istoricTranzactii;
	float limitaDepunere;
	float soldCurent;
	TipCont tipCont;

public:
	ContBancar(string titular, int nrTranzactii, float* istoricTranzactii, float limitaDepunere, TipCont tipCont) {
		this->titular = titular;
		this->tipCont = tipCont;
		this->soldCurent = 0;
		if (limitaDepunere < 0) {
			this->limitaDepunere = -limitaDepunere;
		}
		else {
			this->limitaDepunere = limitaDepunere;
		}
		if (istoricTranzactii != nullptr && nrTranzactii > 0) {
			this->nrTranzactii = nrTranzactii;
			this->istoricTranzactii = new float[this->nrTranzactii];

			for (int i = 0; i < this->nrTranzactii; i++) {
					if (istoricTranzactii[i] < 0) {
						this->istoricTranzactii[i] = -istoricTranzactii[i];
					}
					else {
						this->istoricTranzactii[i] = istoricTranzactii[i];
					}
				}
			
			for (int i = 0; i < this->nrTranzactii; i++) {
				if (this->istoricTranzactii[i] > this->limitaDepunere) {
					this->istoricTranzactii[i] = this->limitaDepunere;
				}
			}
			for (int i = 0; i < this->nrTranzactii; i++) {
				if (this->istoricTranzactii[i] == 0) {
					this->istoricTranzactii[i] = 50.0f; //valoare aleasa pt a inlocui tranzactiile nule;
				}
			}

			for (int i = 0; i < this->nrTranzactii; i++) {
				this->soldCurent += this->istoricTranzactii[i];
			}
		}
		else {
			this->istoricTranzactii = nullptr;
			this->nrTranzactii = 0;
		}

	}

	void modifEnum(TipCont tipCont) {
		this->tipCont = tipCont;
	}

	void afisare() {
		cout << this->titular;
		cout << endl;
		cout << this->nrTranzactii;
		cout << endl;
		for (int i = 0; i < this->nrTranzactii; i++) {
			cout << this->istoricTranzactii[i] << " ";
		}
		cout << endl;
		cout << this->limitaDepunere;
		cout << endl;
		cout << this->soldCurent;
		cout << endl;
		cout << this->tipCont;
		cout << endl;
	}

	int nrTranzactiiDepasindMedia() {
		float medie = 0.0f;
		int contorNrTranz = 0;
		if (this->istoricTranzactii != 0 && this->nrTranzactii > 0) {
			for (int i = 0; i < this->nrTranzactii; i++) {
				medie += this->istoricTranzactii[i];
			}

			for (int i = 0; i < this->nrTranzactii; i++) {
				if (this->istoricTranzactii[i] > medie / this->nrTranzactii) {
					contorNrTranz++;
				}
			}
			return contorNrTranz;
		}
		else {
			return 0;
		}
	}


	~ContBancar() {
		if (this->istoricTranzactii != nullptr) {
			delete[] this->istoricTranzactii;
			this->istoricTranzactii = nullptr;
		}
	}
};

void stergerePrimaTranzactieMin(float*& istoricTranzactii, int& nrTranzactii) {
	if (istoricTranzactii != nullptr && nrTranzactii > 0) {
		float valMin = istoricTranzactii[0];

		for (int i = 1; i < nrTranzactii; i++) {
			if (istoricTranzactii[i] < valMin) {
				valMin = istoricTranzactii[i];
			}
		}
		int indexMin = 0;
		for (int i = 0; i < nrTranzactii; i++) {
			if (istoricTranzactii[i] == valMin) {
				indexMin = i;
				break;
			}
		}
		if (nrTranzactii == 1) {
			delete[] istoricTranzactii;
			istoricTranzactii = nullptr;
			nrTranzactii = 0;
		}
		else {
			int k = 0;
			float* vectorNou = new float[nrTranzactii - 1];
			for (int i = 0; i < nrTranzactii; i++) {
				if (i != indexMin) {
					vectorNou[k++] = istoricTranzactii[i];
				}
			}
			delete[] istoricTranzactii;
			istoricTranzactii = vectorNou;
			nrTranzactii--;
		}
	}
}

int main() {
	float istoricTranzactii[] = { 800.0f,-600.0f,300.0f };
	ContBancar c1("Iulia", 3, istoricTranzactii, 700.0f, ECONOMII);
	cout << "Afisare cont fara modif: ";
	c1.afisare();
	c1.modifEnum(INVESTITII);
	cout << "Modificare tip cont enum: ";
	c1.afisare();
	cout << "Numar tranzactii care depasesc media: " << c1.nrTranzactiiDepasindMedia();
	cout << endl;

	int dim = 3;
	float* istoricNou = new float[dim] {200.0f, 200.0f, 400.0f};
	cout << "Afisam contul fara modif";
	for (int i = 0; i < dim; i++) {
		cout << istoricNou[i] << " ";
}
	cout << endl;
	stergerePrimaTranzactieMin(istoricNou,dim);
	cout << "Afisam contul dp modif";
	for (int i = 0; i < dim; i++) {
		cout << istoricNou[i] << " ";
	}
	delete[] istoricNou;
	istoricNou = nullptr;
	return 0;
}