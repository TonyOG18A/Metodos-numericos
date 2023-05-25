#include<bits/stdc++.h>
using namespace std;
class Newton{

public:
		long double Funcion(long long int n,long double Parametros[],long double x){
			Fx=0;
			for(int i=0.
;i<=n;++i)
				Fx+=Parametros[i]*pow(x,n-i );
			return Fx;
		}
		long double Derivada(long long int n,long double Parametros[],long double x){
			fx=0;
			for(int i=0;i<n;++i)
				fx+=(Parametros[i])*(n-i)*pow(x,n-i-1);
			return fx;
		}
		void Grafica(long long int n,long double Parametros[],long double x){
			ofstream file_plot;
			file_plot.open("Grafica.dat");
			
			for(double i=x-10;i<=x+10;i+=0.001){
				Fx=Funcion(n,Parametros,i);
				fx=Derivada(n,Parametros,i);
				file_plot<<i<<" "<<Fx<<" "<<fx<<endl;
			}

			file_plot.close();

			FILE*vent=popen("gnuplot -persist","w");
			fprintf(vent, "load \"Grafica.txt\" \n");
		}
		void MetNewton(){
			cout<<"Ingrese el grado de su polinomio: ";
			cin>>Grado;
			long double Parametros[Grado+1];
			cout<<"Ingrese los parametros de su polinomio A0x^(n)+A1x^(n-1)+A2x^(n-2)+...+An.\n";
			for(int i=0;i<=Grado;++i){
				cout<<"x^"<<Grado-i<<": ";
				cin>>Parametros[i];
			}
			//for(int i=Grado;i>=Grado-2;--i)
			
			cout<<"Error: ";
			cin>>error;
			cout<<"Ingrese un punto x: ";
			cin>>x0;
			Fx0=Funcion(Grado,Parametros,x0);
			if(fx0==0){
				++x0;
				cout<<"Se tuvo que aumentar una unidad (1) a su valor inicial, ya que ese punto evaluado en la derivada da cero (0), por lo que estaria haciendo una division entre 0, lo cual NO está definido."<<endl; 

			}
			Fx0=Funcion(Grado,Parametros,x0);
			if(pow(Parametros[Grado-1],2)-4*Parametros[Grado-2]*Parametros[Grado]<0)
				cout<<"No existe solución real."<<endl;
				
			if(Fx0==0)
				cout<<"La raiz es: "<<setprecision(20)<<x0<<endl;
			else {
				cout<<setw(15)<<"x0"<<setw(15)<<"x1"<<setw(15)<<"Fx1"<<setw(20)<<"Error relativo"<<setw(20)<<"Error absoluto"<<endl;
				for(int i=0;i<1000;++i){
					Fx0=Funcion(Grado,Parametros,x0);
					fx0=Derivada(Grado,Parametros,x0);
					x1=x0-(Fx0/fx0);
					Fx1=Funcion(Grado,Parametros,x1);
					er=fabs((xv-x1)/xv);
					ea=fabs(xv-x1)/abs(xv+x1);
					if(i<=15&&Fx1-Fx0!=0){
							cout<<setw(15)<<x0<<setw(15)<<x1<<setw(15)<<Fx1<<setw(15);
							if(i>=1)	
								cout<<setw(20)<<er<<setw(20)<<ea;
							else
								cout<<setw(20)<<"0"<<setw(20)<<"0";
							cout<<endl;
					}
					if(Fx1-Fx0==0)
						i=1000;
					if(abs(error-er)<=error)
						i=1000;
					
					x0=x1;
					xv=x1;
				}	
				cout<<"La raiz es: "<<setprecision(6)<<x1<<endl;
			}
				Grafica(Grado,Parametros,x1);
		}

private:
		long long int Grado=0;
		long double Fx=0;
		long double fx=0;
		long double x0=0;
		long double x1=0;
		long double xv=0;
		long double Fx0=0;
		long double fx0=0;
		long double Fx1=0;
		long double er=0;
		long double ea=0;
		long double error=0;
};
int main(){
Newton Newton1;
Newton1.MetNewton();
return 0;
}



