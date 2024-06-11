#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define VELICINA 3

void prikazi_tablu(char tabla[VELICINA][VELICINA]);
int proveri_pobedu(char tabla[VELICINA][VELICINA]);
int proveri_nereseno(char tabla[VELICINA][VELICINA]);
void napravi_potez(char tabla[VELICINA][VELICINA], char igrac);

int main() {
	char tabla[VELICINA][VELICINA] = { {' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '} };
	char trenutni_igrac = 'X';
	int broj_poteza = 0;

	while (1)
	{
		system("cls");
		prikazi_tablu(tabla);
		napravi_potez(tabla, trenutni_igrac);
		broj_poteza++;

		if (proveri_pobedu(tabla)) {
			system("cls");
			prikazi_tablu(tabla);
			printf("Igrac %c je pobedio. Cestitamo!\n", trenutni_igrac);
			break;
		}
		else if (proveri_nereseno(tabla))
		{
			system("cls");
			prikazi_tablu(tabla);
			printf("Igra je neresena.\n");
			break;
		}

		//Промена играча
		trenutni_igrac = (trenutni_igrac == 'X') ? 'O' : 'X';
	}

	system("pause");
	return 0;
}

void prikazi_tablu(char tabla[VELICINA][VELICINA])
{
	printf("  0 1 2\n");
	for (int i = 0; i < VELICINA; i++)
	{
		printf("%d ", i);
		for (int j = 0; j < VELICINA; j++)
		{
			printf("%c ", tabla[i][j]);
		}
		printf("\n");
	}
}

int proveri_pobedu(char tabla[VELICINA][VELICINA])
{
	//Провера редова и колона
	for (int i = 0; i < VELICINA; i++)
	{
		if (tabla[i][0] == tabla[i][1] && tabla[i][1] == tabla[i][2] && tabla[i][0] != ' ') {
			return 1;
		}
		if (tabla[0][i] == tabla[1][i] && tabla[1][i] == tabla[2][i] && tabla[0][i] != ' ') {
			return 1;
		}
	}

	//Провера дијагонала
	if (tabla[0][0] == tabla[1][1] && tabla[1][1] == tabla[2][2] && tabla[0][0] != ' ') {
		return 1;
	}
	if (tabla[0][2] == tabla[1][1] && tabla[1][1] == tabla[2][0] && tabla[0][2] != ' ') {
		return 1;
	}

	return 0;
}

int proveri_nereseno(char tabla[VELICINA][VELICINA])
{
	for (int i = 0; i < VELICINA; i++)
	{
		for (int j = 0; j < VELICINA; j++)
		{
			if (tabla[i][j] == ' ') {
				return 0;
			}
		}
	}
	return 1;
}

void napravi_potez(char tabla[VELICINA][VELICINA], char igrac)
{
	int red, kolona;
	while (1)
	{
		printf("Igrac %c, unesite red i kolonu (odvojene razmakom): ", igrac);
		scanf("%d %d", &red, &kolona);
		if (red >= 0 && red < VELICINA && kolona >= 0 && kolona < VELICINA && tabla[red][kolona] == ' ')
		{
			tabla[red][kolona] = igrac;
			break;
		}
		else
		{
			printf("Nevazeci ptez, pokusajte ponovo.\n");
		}
	}
}
