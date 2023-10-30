/*Generar una lista con los datos personales de los alumnos de un colegio (legajo, apellido y nombre, DNI) y las
notas de tres materias: matemática, literatura y geografía (para cada alumno se cargarán las tres materias). Las
notas pueden ir de 1 a 10 y se debe validar que el usuario no ingrese notas incorrectas, volviendo a pedir una
nueva nota cada vez que ingrese una incorrecta, hasta que ingrese un valor en el rango indicado. Se pide
informar la cantidad de alumnos que aprobaron las tres materias (se aprueba con 7) y el porcentaje que
representan los aprobados sobre el total de alumnos.*/



#include <iostream>
#include <cstring>
#include <thread>
#include <chrono>

using namespace std;

struct notas
{
    int matem;
    int literature;
    int geography;
};

struct alumno
{
    int legajo;
    string nombre;
    string apellido;
    int dni;
    notas nota;        
};

struct nodo
{
    alumno alumnos;
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



int print_list_of_alumnate(nodo *inicio)
{   
    int total_quantity=0;
    cout << '\t' <<"| ALUMNATE "<<"|"<<endl;
    for (nodo  *aux = inicio; aux!=nullptr; aux=aux->siguiente)
    {
        cout << "Alumno |"<< aux->alumnos.nombre <<" - "<< aux->alumnos.apellido ;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "|DNI= " << aux->alumnos.dni<< " Legajo= "<< aux->alumnos.legajo << '|';
        cout <<endl;
        cout << "\t"<< "| GRADES |"<<endl;
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout << "|Mathematics= "<< aux->alumnos.nota.matem << "|Geography= "<< aux->alumnos.nota.geography << "|Literature= "<< aux->alumnos.nota.literature<<"|"<<endl;
        total_quantity++;
    }
    std::this_thread::sleep_for(std::chrono::seconds(5));
    return total_quantity;
}

nodo* end_insertion(nodo *inicio,nodo *nuevo)
{

    if (inicio==nullptr)
        {
            inicio=nuevo;
        }
        else
        {

            nodo *aux=inicio;
            while (aux->siguiente!=nullptr)
            {
                aux=aux->siguiente;
            }
            aux->siguiente=nuevo;
        }
    return inicio;

}
bool verifier(nodo* &head,int dni)
{
    for (nodo* aux=head;aux!=nullptr;aux=aux->siguiente)
    {
        if (aux->alumnos.dni==dni)
        {
            return true;
        }
        
    }
    return false;

}
int verify_dni(nodo* head,int dni)
{
    bool verificador=true;
    while (verificador)
    {
        verificador=verifier(head,dni);
        if (verificador==false)
        {
            return dni;
        }
        cout <<endl<< "Se ha ingresado un DNI repetido...";
        std::this_thread::sleep_for(std::chrono::seconds(3));
        cout <<endl<< "Ingrese un DNI no repetido: ";
        cin >> dni;
    }
    return dni;
}

int verify_note(int charged_grade)
{
    while (charged_grade<1||charged_grade>10)
    {
        cout<<endl<<endl<<"Ha ingresado una nota incorrecta...";
        std::this_thread::sleep_for(std::chrono::seconds(2));
        cout <<endl<< "Ingrese de vuelta la nota en el formato correcto(de 1 a 10): ";
        cin >> charged_grade;
    }
    return charged_grade;


}
nodo* load_of_alumnate(nodo* head)
{
    bool deseo=true;
    nodo *nuevo;
    alumno alumn;
    cout << "Ingresar dni del alumno  : ";
    cin >> alumn.dni;
    while (deseo)
    {
        nuevo=new nodo;
        nuevo->siguiente=nullptr;
        cout << "Ingrese el legajo del alumno: ";
        cin >> alumn.legajo;
        cout << "Ingrese el nombre del alumno: ";
        getline(cin>>ws,alumn.nombre);
        cout << "Ingrese el apellido: ";
        getline(cin>>ws,alumn.apellido);
        nuevo->alumnos=alumn;
        cout << "Ingrese la nota de literatura: ";
        cin >> alumn.nota.literature;
        alumn.nota.literature=verify_note(alumn.nota.literature);
        cout << "Ingrese la nota de geografia: ";
        cin >> alumn.nota.geography;
        alumn.nota.geography=verify_note(alumn.nota.geography);
        cout << "Ingrese la nota de matematica: ";
        cin >> alumn.nota.matem;
        alumn.nota.matem=verify_note(alumn.nota.matem);
        nuevo->alumnos.nota=alumn.nota;
        head=end_insertion(head,nuevo);
        deseo=verify_wish();
        if (not deseo)
        {
            cout << "Finalizando..."<<endl;
            std::this_thread::sleep_for(std::chrono::seconds(3));
            break;
        }
        cout << "Ingresar dni del alumno: ";
        cin >> alumn.dni;
        alumn.dni=verify_dni(head,alumn.dni);

    }
    return head;
}

void quantity_of_excellent_students(nodo* head,int total_students)
{
    int quantity=0;
    for (nodo* aux=head; aux!=nullptr;aux=aux->siguiente)
    {
        if (aux->alumnos.nota.geography>=7&&aux->alumnos.nota.literature>=7&&aux->alumnos.nota.matem>=7)
        {
            quantity++;
        }
        
    }
    cout << "\t"<< " ***CANTIDAD DE ALUMNOS DE EXCELENCIA*** "<<endl;
    cout << "Cantidad de alumnos con las 3 notas aprobadas= "<< quantity<<endl;
    cout << "Porcentaje de alumnos con las 3 notas aprobadas= "<< (quantity*100)/total_students<< "%";
    


}


int main()
{
    nodo* head=nullptr;
    head=load_of_alumnate(head);
    space_jump();
    int total_of_students=print_list_of_alumnate(head);
    space_jump();
    quantity_of_excellent_students(head,total_of_students);


}