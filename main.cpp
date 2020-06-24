#include <iostream>
#include <random>
using namespace std;

void message(unsigned int y, float czas = 0)
{
	switch (y)
	{
	case 0:
	{
		cout << "\nProgram obliczy okres lokaty kapitałowej do osiągnięcia upragnionych odsetek.\n";
		break;
	}
	case 1:
	{
		cout << "Uzyskanie wybranej kapitalizacji odsetek nastąpi po okresie: " << czas << ".\n";
		break;
	}
	}
}

void pobierz_dane(unsigned int &kw_poczatkowa, unsigned int &kw_odsetek, double &oprocentowanie, double &kapitalizacja)
{
	cout << "Jaka ma być kwota początkowa lokaty?\n";
	cin >> kw_poczatkowa;
	cout << "Jaka ma być oczekiwana wartość odsetek?\n";
	cin >> kw_odsetek;
	cout << "Jakie jest oprocentowanie lokaty? (Dla 1% -> 0.01)\n";
	do { cin >> oprocentowanie; } while (oprocentowanie > 1 || oprocentowanie <= 0);
	cout << "Ile wynosi okres kapitalizacji lokaty? (Dla pół roku -> 0.5)\n";
	do { cin >> kapitalizacja; } while (kapitalizacja < 0);
}

float okres_kapitalizacji(double kw_szukana, unsigned int kw_odsetek, float oprocentowanie, float kapitalizacja)
{
	static float czas = 0;
	static int kw_poczatkowa = kw_szukana;

	if (kw_szukana - kw_poczatkowa < kw_odsetek)
	{
		kw_szukana = kw_szukana + kw_szukana * (oprocentowanie * kapitalizacja);
		czas += kapitalizacja;
		cout << "Dla okresu kapitalizacji: " << czas << ", kwota lokaty wynosi: " << kw_szukana << endl;
		okres_kapitalizacji(kw_szukana, kw_odsetek, oprocentowanie, kapitalizacja);
	}

	return czas;
}

int main()
{
	unsigned int kw_poczatkowa, kw_odsetek, y;
	double oprocentowanie, kapitalizacja, wynik;

	message(y = 0);
	
	pobierz_dane(kw_poczatkowa, kw_odsetek, oprocentowanie, kapitalizacja);

	wynik = okres_kapitalizacji(kw_poczatkowa, kw_odsetek, oprocentowanie, kapitalizacja);

	message(y = 1, wynik);

	return 0;
}
