#include<iostream>
#include<math.h>
#include<string>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include"Gauss.h"

using namespace std;

long double Funcion(long long int,long double*,long double);
string DecimalAFraccion(long double);
void ImprimirPolinomio(long long int,long double*);
void Grafica(long long int,long double*,long double);
int main(){
	Gauss Interpolacion;
	long long int Puntos=0,Grado=0,Punto,Cont=0;
	long double *Soluciones,x=0,fx=0,datoX,datoY;
	string archivo;
	cout<<"Ingrese el nombre del archivo."<<endl;
	cin>>archivo;
	ifstream Datos(archivo,ios::in);
	if(!Datos){
		cerr<<"No se pudo abrir el archivo"<<endl;
		exit(EXIT_FAILURE);
	}
	long double Valores[100][2];
	while(Datos>>Punto>>datoX>>datoY){
		cout<<Punto<<"\t"<<datoX<<"\t"<<datoY<<endl;
		for(int c=0;c<2;++c){
			if(c==0)
				Valores[Punto][c]=datoX;
			else
				Valores[Punto][c]=datoY;
		}
	}
	cout<<"Ingrese el grado con el que desea que se genere el polinomio de aproximación(Grado maximo="<<Punto<<")."<<endl;
	cin>>Grado;
	/*if(Grado<Punto){
		cout<<"Ingrese los "<<Grado+1<<" puntos con los que desea trabajar.(Disponibles de 1-"<<Punto+1<<")Porfavor de ingresarlos en orden creciente."<<endl;
	}*/
	long double Matriz[15][15]={0};
	for(int r=0;r<=Grado;++r)
		for(int c=0;c<=Grado+1;++c){
			if(c!=Grado+1)
				Matriz[r][c]=pow(Valores[r][0],c);
			else
				Matriz[r][c]=Valores[r][1];
		}
	cout<<"Sistema de ecuaciones que se obtuvo."<<endl;
	Interpolacion.ImpMatriz(Grado+1,Matriz);
	Soluciones=Interpolacion.MetGauss(Grado+1,Matriz);
	ImprimirPolinomio(Grado,Soluciones);
	cout<<"Ingrese un punto que desea evaluar en el polinomio de aproximación: "<<endl;
	cin>>x;
	fx=Funcion(Grado,Soluciones,x);
	cout<<"f("<<x<<")="<<fx<<endl;
	Grafica(Grado,Soluciones,x);
	return 0;
}

long double Funcion(long long int n,long double Parametros[],long double x){
	long double Fx=0;
	for(int i=0;i<=n;++i)
		Fx+=Parametros[i]*pow(x,i);
	return Fx;
}
/*string DecimalAFraccion(long double numero){
	if(numero-int(numero)!=0){
		long double num2=1;
		double n=1;
		double d=1;	
		string Fraccion={0};	
		while(!(num2==numero)){
			num2=n/d;
			if(num2<numero)
				++n;
			if(num2>numero){
				--n;
				++d;
			}
		}
		Fraccion+=("("+to_string(int(n))+"/"+to_string(int(d))+")");	
		return Fraccion;
	}
	else
		return to_string(int(numero));
}*/
void ImprimirPolinomio(long long int Grado,long double Soluciones[]){
	long double Aux;
	cout<<"El polinomio de aproximación es: f(x)= ";
	/*for(int i=n;i>=0;--i){
		Aux=double(Soluciones[i]);
		if(i>1){
			if(Soluciones[i]>=0&&i!=n)
				cout<<"+"<<DecimalAFraccion(Aux)<<"x^"<<i;
			else if(i==n)
				cout<<DecimalAFraccion(Aux)<<"x^"<<i;
			else
				cout<<"-"<<DecimalAFraccion(-1*Aux)<<"x^"<<i;
			
		}
		else if(i==1){
			if(Soluciones[i]>=0)
				cout<<"+"<<DecimalAFraccion(Aux)<<"x";
			else
				cout<<"-"<<DecimalAFraccion(-1*Aux)<<"x";
		}
		else{
			if(Soluciones[i]>=0)
				cout<<"+"<<DecimalAFraccion(Aux);
			else
				cout<<"-"<<DecimalAFraccion(-1*Aux);

		}


	}*/
	for(int i=Grado;i>=0;--i){
		if(Soluciones[i]>0&&i!=0&&i!=Grado){
			if(i!=1)
				cout<<"+"<<Soluciones[i]<<"x^"<<i;
			else
				cout<<"+"<<Soluciones[i]<<"x";
		}
		else if(i==0){
			if(Soluciones[i]>0)
				cout<<"+"<<Soluciones[i];
			else
				cout<<Soluciones[i];
		}
		else{
			if(i!=1)
				cout<<Soluciones[i]<<"x^"<<i;
			else
				cout<<Soluciones[i]<<"x";				
		}
	}
	cout<<endl;
}
void Grafica(long long int n,long double Parametros[],long double x){
	long double fx=0;
	ofstream file_plot;
	file_plot.open("Grafica.dat");
	for(double i=x-100;i<=x+100;i+=0.001){
		fx=Funcion(n,Parametros,i);
		file_plot<<i<<" "<<fx<<endl;
	}
	file_plot.close();
	FILE*vent=popen("gnuplot -persist","w");
	fprintf(vent, "load \"Grafica.txt\" \n");
}
