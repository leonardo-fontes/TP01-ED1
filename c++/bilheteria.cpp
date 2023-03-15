#include <iostream>
#include <locale.h>

using namespace std;


/* Fileiras 1 a 5: R$ 50,00
Fileiras 6 a 10: R$ 30,00
Fileiras 11 a 15: R$ 15,00*/
int lugares_ocupados = 0;
int valor_bilheteria = 0;
int fileiras = 15;
int poltronas = 40;
const char*  total_poltronas[16][41];

void operation1()
{
    int select_fileira = 0;
    int select_poltrona = 0;
    cout << "Selecione a fileira (entre 1 a 15): ";
    cin >> select_fileira;
    if (select_fileira <= 5) {
        valor_bilheteria += 50; 
    } else if (select_fileira > 5 && select_fileira <= 10){
        valor_bilheteria += 30;
    } else {
        valor_bilheteria += 15; 
    }


    cout << "Selecione a poltrona (entre 1 a 40): ";
    cin >> select_poltrona;

    if(total_poltronas[select_fileira][select_poltrona] == "."){
        cout << "Reserva efetuada com sucesso!" << endl; 
        lugares_ocupados += 1; 
        total_poltronas[select_fileira][select_poltrona] = "#" ;
    } else{
        cout << "O lugar já está ocupado!" << endl; 
    }

    
}

void operation2()
{
    /* vamos declarar a matriz para organizar as poltronas*/
    for (int i = 1; i < 16; i++)
    {
        for (int j = 1; j < 41; j++)  
        {
            cout << total_poltronas[i][j]; 
        }
        cout << endl; 
    }
}

void operation3() {

    cout << "Quantidade de lugares ocupados: " << lugares_ocupados << endl;
    cout << "Valor da bilheteria: R$" << valor_bilheteria << endl;
}

int main()
{
    setlocale(LC_ALL, "portuguese");

    int select_option = 01;


    for (int i = 1; i < 16; i++)
    {
        for (int j = 1; j < 41; j++)  
        {
            total_poltronas[i][j] = "." ; 
        }
        
    }


    while (select_option != 0)
    {

        cout << "Qual das seguintes opções você deseja?" << endl;
        cout << "0 - finalizar" << endl;
        cout << "1 - Reservar poltrona" << endl;
        cout << "2 - Mapa de ocupação" << endl;
        cout << "3 - Faturamento" << endl;
        cin >> select_option;

        switch (select_option)
        {
        case 0:
            select_option = 0;
            cout << "Obrigado por utilizar nossos serviços!";
            break;

        case 1:
            operation1();
            break;

        case 2:
            operation2();
            break;

        case 3:
            operation3();
            break;

        default:
            cout << "Opção inválida!" << endl;
            break;
        }
    }

    return 0;
}