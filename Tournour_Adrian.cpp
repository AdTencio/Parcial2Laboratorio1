#include<iostream>
#include<cstdlib>

using namespace std;
int cargarDatos(float vDias[], int vSucu[], int&, string&);
void punto1(int numMayor, string&);
void punto2(float vDias[]);
void punto3(int vSucu[]);
void punto4(float VDias[]);

int main(){
float vDias[31]={0};
int vSucu[10]={0};
int numMayor=0;
string numMayorProducto="Chau";
    while(true){
int opc;
        system("cls");
        cout<<"1) CARGAR DATOS"<<endl;
        cout<<"2) PUNTO A"<<endl;
        cout<<"3) PUNTO B"<<endl;
        cout<<"4) PUNTO C"<<endl;
        cout<<"5) PUNTO D"<<endl;
        cout<<"--------------"<<endl;
        cout<<"0) SALIR"<<endl;
        cout<<endl;
        cout<<"INGRESAR OPCION ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1: cargarDatos(vDias, vSucu, numMayor, numMayorProducto);
                    break;
            case 2: punto1(numMayor, numMayorProducto);
                    break;
            case 3: punto2(vDias);
                    break;
            case 4: punto3(vSucu);
                    break;
            case 5: punto4(vDias);
                    break;
            case 0:return 0;
                   break;
        }


    system("pause");

}
    return 0;
}

int cargarDatos(float vDias[],int vSucu[], int& numMayor, string& nomMayorProducto){
    int numVenta, unidades, dia, sucursal, producto;
    float importe;
    bool seguir=true, primerDato=true;
    int cantidadMayor = 0;
    char nombreMayor[31];
    string nombreProducto;
    cout<<"Numero de venta: ";
    cin>>numVenta;


    while(seguir){
        cout<<"Dia: ";
        cin>>dia;
        cout<<"Sucursal: ";
        cin>>sucursal;
        cout<<"Num de producto: ";
        cin>>producto;
        cout<<"Nombre del producto ";
        cin>>nombreProducto;
        cout<<"Cantidad de unidades: ";
        cin>>unidades;
        cout<<"Importe total: ";
        cin>>importe;
        vDias[dia-1]+=importe;
        vSucu[sucursal-1]+=unidades;

        if(dia==5){
            if(cantidadMayor<unidades) {
                cantidadMayor=unidades;
                numMayor=producto;
                nomMayorProducto=nombreProducto;
            }
        }


        cout<<"Numero de venta: ";
        cin>>numVenta;
        if(numVenta==0)seguir=false;

    }
    //return numMayor;
}

void punto1(int numMayor, string& nomMayorProducto){
    cout<<"El producto con mayor cantidad de unidades vendidas en una sola venta el dia 5 fue: "<<numMayor<<endl<<"de nombre: "<<nomMayorProducto<<endl;;

}

void punto2(float vDias[]){
    int x=0;
        for(x=0;x<31;x++){

            if(vDias[x]>100000){
                    cout<<"Se supero los 100000 pesos recaudados en los dias: ";
                    cout<<x+1<<endl;
            }

        }
}
void punto3(int vSucu[]){
int menorSucu = 0, menormonto = 0;
int x;
bool primerDato=true;

    for(x=0;x<10;x++){
        if(vSucu[x]>0){
            if(primerDato){
            menormonto=vSucu[x];
            menorSucu=x+1;
            primerDato=false;
        }
        else{
            if(vSucu[x]<menorSucu){
                menormonto=vSucu[x];
                menorSucu=x+1;
            }


        }

    }
}
    cout<<"La sucursal con menor cantidad de unidades vendidas en todo el mes fue: "<<menorSucu<<endl;
}

void punto4(float vDias[]){
int x, acu=0;
    for(x=0;x<31;x++){
        if(vDias[x]==0){
            acu++;
        }

    }
    cout<<"La cantidad de dias sin recaudacion fue: "<<acu<<endl;
}

