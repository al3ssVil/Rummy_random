#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

struct piesa
{
	int numar;
	char culoare[100];
};

void citirePiese(piesa*& vector)
{
	std::cout << "Citeste piese ";
	vector = new piesa[16];
	for (int i = 0; i < 14; i++)
	{	
		int numar = rand() % 14;
		int culoare = rand() % 4;
		vector[i].numar = numar;
		if (culoare == 0)
			strcpy(vector[i].culoare, "rosu");
		else
			if (culoare == 1)
				strcpy(vector[i].culoare, "albastru");
			else
				if (culoare == 2)
					strcpy(vector[i].culoare, "negru");
				else
					strcpy(vector[i].culoare, "galben");
	}
}

void afisare(piesa* vector)
{
	for (int i = 0; i < 14; i++)
		std::cout << vector[i].numar << ' ' << vector[i].culoare << ' ';
	std::cout<<std::endl;
}

void quickSort(piesa*& vector, int left, int right)
{
	int i = left, j = right;
	int mijloc = vector[(i + j) / 2].numar;
	while (i <= j)
	{
		while (mijloc > vector[i].numar)
			i++;
		while (vector[j].numar > mijloc)
			j--;
		if (i <= j)
		{
			piesa aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			i++;
			j--;
		}
	}
	if (left < j)
		quickSort(vector, left, j);
	if (i < right)
		quickSort(vector, i, right);
}

void succesiuneCuloare(piesa* vector)
{
	for (int i = 0; i < 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j < 14; j++)
			if (formatie[0].numar == vector[j].numar)
			{
				int ok = 1;
				for (int p = 0; p < pozitie && ok == 1; p++)
					if (strcmp(formatie[p].culoare, vector[j].culoare) == 0)
						ok = 0;
				if (ok == 1)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
		{
			for (int p = 0; p < pozitie; p++)
				std::cout << formatie[p].numar << ' ' << formatie[p].culoare << ' ';
			std::cout << '\n';
		}
		delete[] formatie;
	}
}

void verificareOrdonat(piesa* vector, piesa* vectorOrdonat)
{
	int numar = 0;
	for (int i = 0; i < 14; i++)
		if (vector[i].numar != vectorOrdonat[i].numar)
			numar++;
	if (numar)
		std::cout << numar << " piese si au schimbat pozitia " << '\n';
}

void succesiuneNumar(piesa* vector)
{
	for (int i = 0; i < 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j < 14; j++)
			if (strcmp(formatie[0].culoare, vector[j].culoare) == 0)
			{
				if (formatie[pozitie - 1].numar + 1 == vector[j].numar)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
		{
			for (int p = 0; p < pozitie; p++)
				std::cout << formatie[p].numar << ' ' << formatie[p].culoare << ' ';
			std::cout << '\n';
		}
		delete[] formatie;
	}
}

void tragere(piesa*& vector)
{
	int numar = rand() % 14;
	int culoare = rand() % 4;
	vector[15].numar = numar;
	if (culoare == 0)
		strcpy(vector[15].culoare, "rosu");
	else
		if (culoare == 1)
			strcpy(vector[15].culoare, "albastru");
		else
			if (culoare == 2)
				strcpy(vector[15].culoare, "negru");
			else
				strcpy(vector[15].culoare, "galben");
	std::cout << "A 15 piesa este " << vector[15].numar << " " << vector[15].culoare << std::endl;
}

void ceaMaiLungaFormatie(piesa* vector)
{
	int Lungime = 0;
	piesa* maxim;
	maxim = new piesa[10];
	for (int i = 0; i <= 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j <= 14; j++)
			if (formatie[0].numar == vector[j].numar)
			{
				int ok = 1;
				for (int p = 0; p < pozitie && ok == 1; p++)
					if (strcmp(formatie[p].culoare, vector[j].culoare) == 0)
						ok = 0;
				if (ok == 1)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
			for (int p = 0; p < pozitie; p++)
				if (formatie[p].numar == vector[14].numar)
					if (strcmp(formatie[p].culoare, vector[14].culoare) == 0)
						if (Lungime < pozitie)
						{
							Lungime = pozitie;
							for (int j = 0; j < pozitie; j++)
							{
								maxim[j].numar = formatie[j].numar;
								strcpy(maxim[j].culoare, formatie[j].culoare);
							}
						}
		delete[] formatie;
	}
	for (int i = 0; i <= 12; i++)
	{
		piesa* formatie;
		formatie = new piesa[10];
		formatie[0].numar = vector[i].numar;
		strcpy(formatie[0].culoare, vector[i].culoare);
		int pozitie = 1;
		for (int j = i; j <= 14; j++)
			if (strcmp(formatie[0].culoare, vector[j].culoare) == 0)
			{
				if (formatie[pozitie - 1].numar + 1 == vector[j].numar)
				{
					formatie[pozitie].numar = vector[j].numar;
					strcpy(formatie[pozitie].culoare, vector[j].culoare);
					pozitie++;
				}
			}
		if (pozitie >= 3)
			for (int p = 0; p < pozitie; p++)
				if (formatie[p].numar == vector[14].numar)
					if (strcmp(formatie[p].culoare, vector[14].culoare) == 0)
						if (Lungime < pozitie)
						{
							Lungime = pozitie;
							for (int j = 0; j < pozitie; j++)
							{
								maxim[j].numar = formatie[j].numar;
								strcpy(maxim[j].culoare, formatie[j].culoare);
							}
						}
		delete[] formatie;
	}
	if (Lungime > 0)
		for (int i = 0; i < Lungime; i++)
			std::cout << maxim[i].numar << ' ' << maxim[i].culoare << ' ';
	else
		std::cout << "Nu se poate face o formatie cu aceasta piesa";
	delete[] maxim;
}

int main()
{
	srand(time(NULL));
	piesa* vector;
	piesa* vectorOrdonat;
	vectorOrdonat = new piesa[15];
	citirePiese(vector);
	afisare(vector);
	for (int i = 0; i < 14; i++)
		vectorOrdonat[i] = vector[i];
	quickSort(vectorOrdonat, 0, 13);
	verificareOrdonat(vector, vectorOrdonat);
	succesiuneCuloare(vector);
	succesiuneNumar(vector);
	tragere(vector);
	ceaMaiLungaFormatie(vector);
	delete[] vector;
	delete[] vectorOrdonat;
	return 0;
}