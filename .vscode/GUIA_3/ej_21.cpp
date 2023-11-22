/*
Cargar de teclado, en una lista circular, los datos de los jugadores de un juego de rol de mesa, para administrar
sus turnos. 
De cada uno se almacenará: nombre de jugador, puntaje, raza de su personaje (dato numérico,
donde 1 es mago, 2 es guerrero, 3 es elfo).

a) Se debe permitir cargar, como máximo, 10 jugadores, insertando cada nuevo jugador al final. Validar
también que la raza sólo sea 1, 2 ó 3, dejando al usuario en un bucle hasta que ingrese una raza válida.

b) Dado el nombre de un jugador, indicar las características de la raza de su personaje: si es 1 (mago) se
debe imprimir "1 punto de sanación por cada 5 de daño recibido"; si es 2 (guerrero) se debe imprimir
"20% más de daño infligido"; si es 3 (elfo) se debe imprimir "capacidad de resucitar a un compañero a
cambio de 200 puntos".

c) Dada una raza y una cantidad de puntos de penalidad, restar del puntaje la cantidad dada, para todos
los jugadores de esa raza.

d) Imprimir los nombres de todos los jugadores, junto a su puntaje.*/






#include <iostream>
#include <cctype>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;


struct Player_Specs
{
    string player_name;
    int scored_points;
    int chosen_race;
};


struct nodo
{
    Player_Specs player;
    nodo* siguiente;
};


void space_jump()
{
    std::this_thread::sleep_for(std::chrono::seconds(2));
    for (int i = 0; i < 20; i++)
    {
        cout << endl;
    }
    

}


void print_circular_list(nodo *end)
{   
    if (end != nullptr)
    {
    nodo* aux = end->siguiente;
    cout << '\t' <<"|DETAILS OF THE PLAYERS|"<<endl;
    do {
    std::this_thread::sleep_for(std::chrono::seconds(2));
    cout <<"|NAME: "<< aux->player.player_name<< " |RACE: "  <<aux->player.chosen_race<<" |POINTS: "<< aux->player.scored_points<<  '|' ;
    cout << endl;
    aux = aux->siguiente;
    } 
    while (aux != end->siguiente);
    }
}

bool verify_wish()
{
    int eleccion=2;
    while (eleccion!=0&&eleccion!=1)
    {
    cout << "Desea seguir con la carga?"<<endl;        
    cout << "[0] NO"<<endl;
    cout << "[1] SI"<<endl;
    cout << "Ingresar eleccion: ";
    cin >>eleccion;
    if (eleccion<0||eleccion>1)
    {
        cout << "VUELVA A INGRESAR SU ELECCION..."<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(3));
        continue;
    }
    }
    if (eleccion==1)
    {
        return true;
    }
    else
    {
        return false;
    }
}


nodo* insert_at_circular_end(nodo* end,nodo* nuevo)
{ 
    if (end == nullptr)
    {
    nuevo->siguiente = nuevo;
    }
    else
    {
    nuevo->siguiente = end->siguiente;
    end->siguiente = nuevo;
    }   
    return nuevo;
}

int race_election()
{
    int eleccion=0;
    cout << '\t'<< "***CHOOSE DESIRED RACE***"<<endl<<endl;
    while (eleccion<1 || eleccion>3)
    {    
    cout << "[1] MAGE"<<endl;
    cout << "[2] WARRIOR"<< endl;
    cout << "[3] ELF"<<endl;
    cout << "CHOOSE YOUR RACE: ";
    cin >> eleccion;
    switch (eleccion)
    {
    case 1:
        cout <<endl<< "YOU HAVE CHOSEN THE PATH OF THE SAGE";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 1;
        break;
    case 2:
        cout <<endl<< "YOU HAVE CHOSEN THE PATH OF THE MIGTHY WARRIOR";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 2;
        break;
    case 3:
        cout <<endl<< "YOU HAVE CHOSEN THE PATH OF THE WARY ELF";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        return 3;
        break;
    default:
        cout <<endl<< "CHOOSE AN AVAILABLE RACE!!!"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        break;
    }
    }
    return 0;
}




nodo* load_of_players(nodo* end)
{
    bool deseo=true;
    int player_count=0;
    nodo* nuevo;
    Player_Specs ex_player;
    while (player_count!=10&&deseo)
    {
        nuevo=new nodo;
        cout << "Insert name of the player: ";
        getline(cin>>ws,ex_player.player_name);
        ex_player.chosen_race=race_election();
        cout <<endl<< "Insert scored points of the player: ";
        cin >> ex_player.scored_points;
        nuevo->player=ex_player;
        end=insert_at_circular_end(end,nuevo);
        player_count++;
        deseo=verify_wish();
    }
    return end;
}

void inform_perks_of_player(nodo* end,string player_name)
{
    if (end!=nullptr)
    {
        nodo* aux=end->siguiente;
        do
        {
            if (aux->player.player_name==player_name)
            {
                cout << '\t'<< player_name<< " UNIQUE PERKS"<<endl;
                std::this_thread::sleep_for(std::chrono::seconds(2));
                switch (aux->player.chosen_race)
                {
                case 1:
                    cout << "|MAGE PERKS: |1 healing point per 5 taken damage|"<<endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                case 2:
                    cout << "|WARRIOR PERKS: |20% MORE INFLICTED DAMAGE|"<<endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                case 3:
                    cout << "|ELF PERKS: |ABLE TO REVIVE A TEAMMATE FOR 200 POINTS|"<<endl;
                    std::this_thread::sleep_for(std::chrono::seconds(2));
                    break;
                default:
                    break;
                }
            }
            
            
        } while (aux!=end->siguiente);
        
    }
    

}

void pay_penalization(nodo* &end)
{
    int fault_race;
    int penalization_points;
    cout << "Insert penalization points: ";
    cin >> penalization_points;
    cout << endl<< "Insert penalized race: ";
    cin >> fault_race;
    if (fault_race>3||fault_race<1)
    {
        cout <<endl<<  "NON EXISTING RACE!!!";
        return;
    }
    if (end!=nullptr)
    {
        nodo* aux=end->siguiente;
        do
        {
            if (aux->player.chosen_race==fault_race)
            {
                aux->player.scored_points-=penalization_points;                
            }
            aux=aux->siguiente;
        } while (aux!=end->siguiente);
        
    }
    cout <<endl<< "The race "<< fault_race <<" has been discounted "<< penalization_points<<" points...";


}



int main()
{
    nodo* fantasy_ptr=nullptr;
    string chosen_name;
    fantasy_ptr=load_of_players(fantasy_ptr);
    space_jump();
    print_circular_list(fantasy_ptr);
    cout <<endl<< "Insert name of a player to see their unique perks: ";
    getline(cin>>ws,chosen_name);
    inform_perks_of_player(fantasy_ptr,chosen_name); 
    space_jump();
    pay_penalization(fantasy_ptr);
    space_jump();
    print_circular_list(fantasy_ptr);
}