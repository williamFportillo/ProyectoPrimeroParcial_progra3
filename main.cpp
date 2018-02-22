#include <iostream>
#include<conio.h>
#include<windows.h>
#include <ctime>
using namespace std;
void gotoxy(int x, int y);
void Carro(int x, int y);
void CarroContra1(int x, int y);
void CarroContra2(int x, int y);
void CarroContra3(int x, int y);
void borrar(int x, int y);
void mover();
void moverCarroContra();
void datos(int x, int y);
int x2=80;
int y2=3;
int x=4;
int y=26;
int xc1=4;
int yc1=15;
int xc2=20;
int yc2=8;
int xc3=38;
int yc3=1;
int velocidad=20;
int v=3;
int niv=1;
int puntuacion=20;
int puntos=0;
bool pause=false;
int p=0;
int lista[1][10]={p};

void gotoxy(int x,int y){
    HANDLE hcon;
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y= y;
    hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(hcon,dwPos);
}

void Carro(int x, int y){
    gotoxy(x,y); printf   ("   00  ");
    gotoxy(x,y+1); printf("  0000  ");
    gotoxy(x,y+2); printf ("   00  ");
    gotoxy(x,y+3);printf ("  0000  ");

}

void CarroContra1(int x,int y ){
    gotoxy(x,y); printf("  ----  ");
    gotoxy(x,y+1); printf("   --  ");
    gotoxy(x,y+2); printf("  ----  ");
    gotoxy(x,y+3); printf("   --  ");
}

void CarroContra2(int x,int y ){
    gotoxy(x,y); printf("  ----  ");
    gotoxy(x,y+1); printf("   --  ");
    gotoxy(x,y+2); printf("  ----  ");
    gotoxy(x,y+3); printf("   --  ");
}

void CarroContra3(int x,int y ){
    gotoxy(x,y); printf("  ----  ");
    gotoxy(x,y+1); printf("   --  ");
    gotoxy(x,y+2); printf("  ----  ");
    gotoxy(x,y+3); printf("   --  ");
}

void borrar(int x,int y){
    gotoxy(x,y);  printf("          ");
    gotoxy(x,y+1);printf("          ");
    gotoxy(x,y+2);printf("           ");
    gotoxy(x,y+3);printf("           ");

}

void mover(){
    if(kbhit()){
    char tecla = getch();
        switch(tecla){
            case 75:
                if(x>1){
                    borrar(x,y);
                    x -=2;
                    Carro(x,y);
                }
                break;
            case 77:
                if(x<37){
                    borrar(x,y);
                    x +=2;
                    Carro(x,y);
                }
                break;
            case 'q':
                pause=true;
                Sleep(1000);
                if(pause==true) {
                    getch();
                    Sleep(0);
                    pause = false;
                }
                break;
        }
    }
}

void moverCarroContra() {

    if (yc1 >= 26) {
        borrar(xc1, yc1);
     //  xc1 =  1+rand() % 38;
        yc1 = 0;
    }else{
        borrar(xc1,yc1);
        yc1++;

    }
     if(yc2>=26) {
         borrar(xc2, yc2);
       //  xc2 = 1+rand()%38;
         yc2 = 0;
     }else{
         borrar(xc2,yc2);
       yc2++;
         }
     if(yc3>=26){
        borrar(xc3,yc3);
       //xc3 = 1+rand()%38;
        yc3=0;
    }else{
         borrar(xc3,yc3);
         yc3++;
     }

    Sleep(velocidad);
}

void choque(){
    if(yc1==y&& xc1==x||yc2==y && xc2==x||yc3==y && xc3==x){
        v--;
    }
    if(yc1+4==y+4||yc2+4==y+4||yc3+4==y+4){
        puntos=puntos+puntuacion;
    }

}

void datos(int x, int y){
    gotoxy(x,y); printf("          Vida: ");cout<<v;
    gotoxy(x, y + 1); printf("         Nivel: "); cout << niv;
    gotoxy(x,y+2);printf("        Puntos: ");cout <<puntos;
    gotoxy(x,y+3);printf("    Puntuacion: ");cout<<"+"<<puntuacion;
 p=puntos;
}


int main(){
int opc=0;
    int msec=0;
    int conta=0;
    do{
cout <<"--------------------------Bienvenido-------------------------"<<endl;
    cout<<"1. Jugar"<<endl;
    cout<<"2. Datos"<<endl;
    cout<<"3. Salir"<<endl;
    cout<<"Ingrese una opcion: ";
    cin >>opc;
    switch(opc) {
        case 1:
            system("cls");
            clock_t tiempo;
            tiempo = clock();
                while (v!=0) {

                    mover();

                    Carro(x, y);
                    moverCarroContra();

                    CarroContra1(xc1, yc1);
                    CarroContra2(xc2, yc2);
                    CarroContra3(xc3, yc3);
                    choque();

                    datos(x2, y2);

                    tiempo=clock()-tiempo;
                    msec =  float(tiempo) / CLOCKS_PER_SEC;
                    lista[1][10]={puntos};
                    if(msec==10){
                        tiempo=0.00;
                        niv++;
                        if(niv==10){
                            niv=0;
                            velocidad=velocidad-5;
                            puntuacion=puntuacion+20;
                        }
                    }

                    Sleep(velocidad);
                }
                system("cls");
                cout<<"Game OVER"<<endl;
            cout <<"Presione cualquier Tecla: ";
            getch();
                v=3;
                niv=0;
                puntuacion=20;
                puntos=0;
                system("cls");
                break;
                case 2:
                system("cls");
            for (int i = 0; i <10 ; ++i) {
                cout<<"*-"<<i<<"Puntuacion: "<<lista[i][i]<<endl;
            }
                    cout << "Presione cualquier tecla para regresar: ";
                    getch();
                    system("cls");


                break;
        default:
            if(opc>3 || opc <1)
            cout <<"valor incorrecto";
            system("cls");
            }
    }while(opc!=3);



    }



