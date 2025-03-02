#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <ctime>

struct piece
{
	int number;
	char color[100];
};

void ReadPieces(piece*& vector)
{
	std::cout << "Read pieces: ";
	vector = new piece[16];
	for (int i = 0; i < 14; i++)
	{
		int number = rand() % 13 + 1;
		int color = rand() % 4;
		vector[i].number = number;
		if (color == 0)
			strcpy(vector[i].color, "red");
		else
			if (color == 1)
				strcpy(vector[i].color, "blue");
			else
				if (color == 2)
					strcpy(vector[i].color, "black");
				else
					strcpy(vector[i].color, "yellow");
	}
}

void Display(piece* vector)
{
	for (int i = 0; i < 14; i++)
		std::cout << vector[i].number << ' ' << vector[i].color << ' ';
	std::cout << std::endl;
}

void QuickSort(piece*& vector, int left, int right)
{
	int i = left, j = right;
	int middle = vector[(i + j) / 2].number;
	while (i <= j)
	{
		while (middle > vector[i].number)
			i++;
		while (vector[j].number > middle)
			j--;
		if (i <= j)
		{
			piece aux = vector[i];
			vector[i] = vector[j];
			vector[j] = aux;
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(vector, left, j);
	if (i < right)
		QuickSort(vector, i, right);
}

void ValueSequence(piece* vector)
{
	std::cout << "\nPieces ordered by value:\n";
	for (int i = 0; i < 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j < 14; j++)
			if (formation[0].number == vector[j].number)
			{
				int ok = 1;
				for (int p = 0; p < position && ok == 1; p++)
					if (strcmp(formation[p].color, vector[j].color) == 0)
						ok = 0;
				if (ok == 1)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
		{
			for (int p = 0; p < position; p++)
				std::cout << formation[p].number << ' ' << formation[p].color << ' ';
			std::cout << '\n';
		}
		delete[] formation;
	}
}

void CheckOrdered(piece* vector, piece* orderedVector)
{
	int number = 0;
	for (int i = 0; i < 14; i++)
		if (vector[i].number != orderedVector[i].number)
			number++;
	if (number)
		std::cout << '\n' << number << " pieces have changed their position " << '\n';
}

void NumberSequence(piece* vector)
{
	std::cout << "Pieces ordered by color:\n";
	for (int i = 0; i < 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j < 14; j++)
			if (strcmp(formation[0].color, vector[j].color) == 0)
			{
				if (formation[position - 1].number + 1 == vector[j].number)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
		{
			for (int p = 0; p < position; p++)
				std::cout << formation[p].number << ' ' << formation[p].color << ' ';
			std::cout << '\n';
		}
		delete[] formation;
	}
}

void Draw(piece*& vector)
{
	int number = rand() % 13 + 1;
	int color = rand() % 4;
	vector[15].number = number;
	if (color == 0)
		strcpy(vector[15].color, "red");
	else
		if (color == 1)
			strcpy(vector[15].color, "blue");
		else
			if (color == 2)
				strcpy(vector[15].color, "black");
			else
				strcpy(vector[15].color, "yellow");
	std::cout << "\nThe 15th piece is " << vector[15].number << " " << vector[15].color << std::endl;
}

void LongestFormation(piece* vector)
{
	int length = 0;
	piece* maxim;
	maxim = new piece[10];
	for (int i = 0; i <= 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j <= 14; j++)
			if (formation[0].number == vector[j].number)
			{
				int ok = 1;
				for (int p = 0; p < position && ok == 1; p++)
					if (strcmp(formation[p].color, vector[j].color) == 0)
						ok = 0;
				if (ok == 1)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
			for (int p = 0; p < position; p++)
				if (formation[p].number == vector[14].number)
					if (strcmp(formation[p].color, vector[14].color) == 0)
						if (length < position)
						{
							length = position;
							for (int j = 0; j < position; j++)
							{
								maxim[j].number = formation[j].number;
								strcpy(maxim[j].color, formation[j].color);
							}
						}
		delete[] formation;
	}
	for (int i = 0; i <= 12; i++)
	{
		piece* formation;
		formation = new piece[10];
		formation[0].number = vector[i].number;
		strcpy(formation[0].color, vector[i].color);
		int position = 1;
		for (int j = i; j <= 14; j++)
			if (strcmp(formation[0].color, vector[j].color) == 0)
			{
				if (formation[position - 1].number + 1 == vector[j].number)
				{
					formation[position].number = vector[j].number;
					strcpy(formation[position].color, vector[j].color);
					position++;
				}
			}
		if (position >= 3)
			for (int p = 0; p < position; p++)
				if (formation[p].number == vector[14].number)
					if (strcmp(formation[p].color, vector[14].color) == 0)
						if (length < position)
						{
							length = position;
							for (int j = 0; j < position; j++)
							{
								maxim[j].number = formation[j].number;
								strcpy(maxim[j].color, formation[j].color);
							}
						}
		delete[] formation;
	}
	if (length > 0)
	{
		std::cout << "\nThe longest formation made with this piece is: ";
		for (int i = 0; i < length; i++)
			std::cout << maxim[i].number << ' ' << maxim[i].color << ' ';
	}
	else
		std::cout << "\nA formation cannot be made with this piece";
	delete[] maxim;
}

int main()
{
	srand(time(NULL));
	piece* vector;
	piece* vectorOrdonat;
	vectorOrdonat = new piece[15];
	ReadPieces(vector);
	Display(vector);
	for (int i = 0; i < 14; i++)
		vectorOrdonat[i] = vector[i];
	QuickSort(vectorOrdonat, 0, 13);
	CheckOrdered(vector, vectorOrdonat);
	ValueSequence(vector);
	NumberSequence(vector);
	Draw(vector);
	LongestFormation(vector);
	delete[] vector;
	delete[] vectorOrdonat;
	return 0;
}