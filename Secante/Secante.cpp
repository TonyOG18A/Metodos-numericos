#include<bits/stdc++.h>
using namespace std;

class Biseccion{
	public:
		long double Funcion(long long int n,long double Parametros[],long double x){
			Fx=0;
			for(int i=0;i<=n;++i)
				Fx+=Parametros[i]*pow(x,n-i );
			return Fx;
		}
		void Grafica(long long int n,long double Parametros[],long double x){
			ofstream file_plot;
			file_plot.open("Grafica.dat");
			
			for(double i=x-20;i<=x+20;i+=0.001){
				Fx=Funcion(n,Parametros,i);
				file_plot<<i<<" "<<Fx<<endl;
			}
			file_plot.close();

			FILE*vent=popen("gnuplot -persist","w");
			fprintf(vent, "load \"Grafica.txt\" \n");
		}
		void Bisec(){
			cout<<"Ingrese el grado de su polinomio: ";
			cin>>Grado;
			long double Parametros[Grado+1];
			cout<<"Ingrese los parametros de su polinomio A0x^(n)+A1x^(n-1)+A2x^(n-2)+...+An.\n";
			for(int i=0;i<=Grado;++i){
				cout<<"x^"<<Grado-i<<": ";
				cin>>Parametros[i];
				
			}
		
			cout<<"Error: ";
			cin>>error;
			cout<<"Ingrese el intervalo [a,b]: ";
			cin>>a>>b;
			Grafica(Grado,Parametros,a);
			
			Fa=Funcion(Grado,Parametros,a);
			Fb=Funcion(Grado,Parametros,b);
			if((Fa-Fb)==0){
				++a;	
				++b;
				cout<<"Con los puntos que se dieron se crea una secante paralela al eje de las x, por lo que se le tuvo que sumar una unidad a cada punto."<<endl;
			}
			
				
			//if(Fa*Fb<0){
				
				cout<<setw(15)<<"a"<<setw(15)<<"b"<<setw(15)<<"Pm"<<setw(15)<<"F(pm)"<<setw(20)<<"Error relativo"<<setw(20)<<"Error absoluto"<<endl;
				for(int i=0;i<100000;++i){

					er=0;
					Fa=Funcion(Grado,Parametros,a);
					Fb=Funcion(Grado,Parametros,b);
					c=a-((Fa*(a-b))/(Fa-Fb));
					Fc=Funcion(Grado,Parametros,c);
					er=fabs((c0-c)/c0);
					ea=fabs(c0-c)/abs(c0+c);
					
					if(i<=15){
						cout<<setw(15)<<a<<setw(15)<<b<<setw(15)<<c<<setw(15)<<Fc<<setw(15);
						if(i>=1)	
							cout<<setw(20)<<er<<setw(20)<<ea;
						else
							cout<<setw(20)<<"0"<<setw(20)<<"0";
						cout<<endl;
					}
					
					if(i%2==0)
						b=c;
					else
						a=c;
					if(Fc==0)
						i=100000;
					if(Fa-Fb==0){
						i=100000;
						c=c0;
					}
					if(abs(error-er)<=error)
						i=100000;
					c0=c;
				}
			//}
			cout<<"La raiz es: "<<setprecision(6)<<c<<endl;
			}

	private:
		long long int Grado=0;
		long double Fx=0;
		long double a=0;
		long double b=0;
		long double c=0;
		long double c0=0;
		long double Fa=0;
		long double Fb=0;
		long double Fc=0;
		long double er=0;
		long double ea=0;
		long double error=0;
	
};

int main(){
	Biseccion Biseccion1;
	Biseccion1.Bisec();
	

return 0;
}
