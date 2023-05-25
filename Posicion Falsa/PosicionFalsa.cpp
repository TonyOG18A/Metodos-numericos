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
			
			for(double i=x-10;i<=x+10;i+=0.001){
				Fx=Funcion(n,Parametros,i);
				file_plot<<i<<" "<<Fx<<endl;
			}
			file_plot.close();

			FILE*vent=popen("gnuplot-qt -persist","w");
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
			//cout<<"Ingrese el error: ";
			//cin>>error;
			Fa=Funcion(Grado,Parametros,a);
			Fb=Funcion(Grado,Parametros,b);
			if(Fa*Fb<0){
				//cout<<"a\t\t"<<"b\t\t"<<"Pm\t\t"<<"F(a)\t\t"<<"F(b)\t\t"<<"F(pm)\t\t"<<"Error relativo\t\t"<<"Error absoluto\t\t"<<endl;
				cout<<setw(15)<<"a"<<setw(15)<<"b"<<setw(15)<<"c"<<setw(15)<<"F(c)"<<setw(20)<<"Error relativo"<<setw(20)<<"Error absoluto"<<endl;
				for(int i=0;i<1000;++i){
					er=0;
					Fa=Funcion(Grado,Parametros,a);
					Fb=Funcion(Grado,Parametros,b);
					c=b-((Fb*(b-a))/(Fb-Fa));
					Fc=Funcion(Grado,Parametros,c);
					er=fabs((c0-c)/c0);
					ea=fabs(c0-c)/abs(c0+c);
					c0=c;
					if(i<=15){
						cout<<setw(15)<<a<<setw(15)<<b<<setw(15)<<c<<setw(15)<<Fc<<setw(15);
						if(i>=1)	
							cout<<setw(20)<<er<<setw(20)<<ea;
						else
							cout<<setw(20)<<"0"<<setw(20)<<"0";
						cout<<endl;
					}
					if(Fa*Fc<0)
						b=c;
					else
						a=c;
					if(Fc==0)
						i=1000;
					if(abs(error-er)<=error)
						i=1000;
					
				/*else{
					cout<<"Ingrese el intervalo [a,b]: ";
					cin>>a>>b;
					--i;
				}*/
				}
			}
			cout<<"La raiz es: "<<setprecision(20)<<c<<endl;
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
