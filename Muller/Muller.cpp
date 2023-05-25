#include<bits/stdc++.h>

using namespace std;

class Muller{
public:

long double Funcion(int g,long double Coe[],long double n){
		f=0;
		for(int i=0;i<=g;++i)
		{
		f+=Coe[i]*(pow(n,g-i));
		}//fin for
return f;
}//fin Funcion

void Grafica(int grado, long double Coe[],long double n){
	ofstream file_plot;
	file_plot.open("Grafica.dat");

	for(double i=-100;i<=100;i+=0.001)
	{
		f=Funcion(g,Coe,i);
		file_plot<<i<<" "<<f<<endl;
	}//fin for

	file_plot.close();

	FILE*vent=popen("gnuplot -persist" , "w");
	fprintf(vent,"load \"Grafica.txt\" \n");
}//fin Grafica


void Datos(){

	cout<<"*****Este programa realiza el método de Muller*****"<<endl<<endl;
	cout<<"Ingrese el grado de su polinomio"<<endl;
	cin>>g;
	long double Coe[g];
	cout<<"Ingrese los coeficientes de su polinomio"<<endl;
	for(int i=0;i<=g;++i)
		{
		cout<<"Ingrese el valor de x^"<<g-i<<":";
		cin>>Coe[i];
		}//fin for
	cout<<"Ingrese sus tres valores iniciales: "<<endl;
	cout<<"x0: ";
	cin>>x0;
	cout<<"x1: ";
	cin>>x1;
	cout<<"x2: ";
	cin>>x2;
	cout<<"Ingrese el error mínimo deseado ";
	cin>>k;

	fx0=Funcion(g,Coe,x0);
		if(fx0==0)
			cout<<"La raíz de su polinomio es: "<<x0<<endl;

	fx1=Funcion(g,Coe,x1);
		if(fx1==0)
			cout<<"La raíz de su polinomio es: "<<x1<<endl;

	fx2=Funcion(g,Coe,x2);
		if(fx2==0)
			cout<<"La raíz de su polinomio es: "<<x2<<endl;

	else{
	cout<<endl;
	cout<<"X3"<<setw(20)<<"F(X3)"<<setw(23)<<"Error Relativo"<<setw(23)<<"Error Absoluto"<<endl;
	for(int i=0;i<=10000;++i){

		fx0=Funcion(g,Coe,x0);
	        fx1=Funcion(g,Coe,x1);
	        fx2=Funcion(g,Coe,x2);

	        h1=x1-x2;
	        h2=x0-x2;
	        e0=fx0-fx2;
	        e1=fx1-fx2;
	        w=h1*(h2*h2)-(h1*h1)*h2;

		a=((e0*h1)-(e1*h2))/w;
		b=((e1*(h2*h2))-((h1*h1)*e0))/w;
		c=fx2;

		er=0;
		ea=0;

		x3=x2-((2*c)/(b+sqrt((b*b)-4*a*c)));

		er=fabs(xn-x3)/xn;
                ea=fabs(x3-xn)/fabs(x3+xn);

		fx3=Funcion(g,Coe,x3);

		if(i<=10){
			cout<<x3;
        	        cout<<setw(20)<<fx3;
			if(i>=1){
				cout<<setw(20)<<er;
				cout<<setw(20)<<ea;
			}//fin if
			else{
				cout<<setw(20)<<"0"<<setw(20)<<"0";
			}//fin else

		cout<<endl;
		}//fin if

			if(fx3==0){
				i=10000;
			}//fin else if

			if(abs(k-er)<=k){
				i=10000;
			}//fin if
		x2=x3;
		xn=x3;
	}//fin for
}//fin else
		cout<<"\nLa raíz del polinomio es: "<<setprecision(6)<<x3<<endl;
}//fin Datos
private:
	long double f=0;
	long double x0;
	long double x1;
	long double x2;
	long double x3;
	long double xn;
	long double fx0;
	long double fx1;
	long double fx2;
	long double fx3;
	long double a;
	long double b;
	long double c;
	long double e0;
	long double e1;
	long double h1;
	long double h2;
	long double w;
	int g;
	long double k;
	long double er;
	long double ea;
};//fin clase Muller

int main(){
Muller muller;
muller.Datos();
}//fin main
