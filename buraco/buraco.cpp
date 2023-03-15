#include <iostream>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <math.h>
#include <locale.h>

using namespace std;

string jogadores[4] = {"1", "2", "3", "4"};
int cartas_sorteadas[44];
string naipe[4] = {"1", "2", "3", "4"};
string card_number[13] = {"01", "02", "03", "04", "05", "06", "07", "08", "09", "10", "11", "12", "13"};
string deck[2] = {"1", "2"};
string total_deck[4][13][2];
string total_cards[104];
int cards = 0;
int x_sorteadas[44];

void percorrer_deck()
{
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 13; k++)
            {
                total_cards[cards] = (naipe[j]) + (card_number[k]) + (deck[i]);

                cards += 1;
            }
        }
    }
}

void sortear_cards()
{

    srand(time(0));
    for (int i = 0; i < 44; i++)
    {

        bool validar_if_exists;
        int randomNumber;
        do
        {
            validar_if_exists = false;
            randomNumber = rand() % 105;

            for (int carta : cartas_sorteadas)
            {
                if (carta == randomNumber)
                {
                    validar_if_exists = true;
                }
            }
        } while (validar_if_exists == true);

        cartas_sorteadas[i] = randomNumber;
    }
}

void distribuir_cards()
{
    int index = 0;

    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 11; j++)
        {
            int carta = cartas_sorteadas[index];
            jogadores[i] = total_cards[carta];
            index++;
            cout << "O jogador " << i + 1 << " recebera: " << jogadores[i] << endl;
        }
    }
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    percorrer_deck();
    sortear_cards();
    distribuir_cards();

    return 0;
}