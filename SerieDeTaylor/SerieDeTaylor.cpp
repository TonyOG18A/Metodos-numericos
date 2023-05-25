#include<bits/stdc++.h>

#define PI 3.141592653589793238462643
#define e 2.72828182845904523536028747
using namespace std;

class Funciones{
	public:
		//Metodo para calcular factoriales.
		unsigned long long int factorial(long long num){
			if(num<2)
				return num;
			else
				return num*factorial(num-1);
			/*for(long long int i=1;i<=num;++i)
				fac*=i;
			return fac;*/
				
		}
		
		void Grafica(long double Px[],long double x){
			ofstream file_plot;
			file_plot.open("Grafica.dat");
			
			for(double i=x-4,j=0;i<=x+4,j<800;i+=0.01,++j){
				//Fx=Px[int(j)];
				file_plot<<i<<" "<<Px[int(j)]<<endl;
			}
			file_plot.close();

			FILE*vent=popen("gnuplot -persist","w");
			fprintf(vent, "load \"Grafica.txt\" \n");

		}
		//Metodo para serie de Taylor de funcion Cos(x).
		void Cosx(){
		cout<<"Ingrese el grado de su polinomio de Taylor(Maximo 65): ";
		cin>>grado;
		long double res[grado+1];
		cout<<"a= ";
		cin>>a;
		cout<<"x= ";
		cin>>x;
		px=cos((a*PI)/180);
		cout<<factorial(21)<<endl;
		for(int i=0;i<800;++i)
			Graf[i]=cos((a*PI)/180);
		for(int i=1;i<=grado;++i){
			if(i%2!=0){
				res[i]=sigImp*(long double)(sin((a*PI)/180));
				sigImp*=-1;
			}
			else{
				res[i]=sigPar*(long double)(cos((a*PI)/180));
				sigPar*=-1;
			}
			px+=(res[i]*(long double)(pow(x-a,i)))/factorial(i);
			for(double j=a-4,k=0;j<=a+4,k<800;j+=0.01,++k)
				Graf[int(k)]+=(res[i]*(long double)(pow(j-a,i)))/factorial(i);
			
			
		}
		Grafica(Graf,a);
		cout<<"\nP(x)= "<<setprecision(60)<<px<<endl;
		}//fin metodo para funcion Cos(x).
		//Metodo para serie de Taylor de funcion Sen(x).
		void Senx(){
		cout<<"Ingrese el grado de su polinomio de Taylor(Maximo 65): ";
		cin>>grado;
		long double res[grado+1];
		cout<<"a= ";
		cin>>a;
		cout<<"x= ";
		cin>>x;
		px=sin((a*PI)/180);
		for(int i=1;i<=grado;++i){
			if(i%2!=0){
				sigImp*=-1;
				res[i]=sigImp*cos((a*PI)/180);
			}
			else{	
				sigPar*=-1;
				res[i]=sigPar*sin((a*PI)/180);	
			}
			px+=(res[i]*(long double)(pow(x-a,i)))/factorial(i);
			for(double j=a-4,k=0;j<=a+4,k<800;j+=0.01,++k)
				Graf[int(k)]+=(res[i]*(long double)(pow(j-a,i)))/factorial(i);
		}
		cout<<"\nP(x)= "<<setprecision(60)<<px<<endl;
		}
		void Lnx(){
		cout<<"Ingrese el grado de su polinomio de Taylor(Maximo 65): ";
		cin>>grado;
		long double res[grado+1];
		cout<<"a= ";
		cin>>a;
		cout<<"x= ";
		cin>>x;	
		px=log(a);
		for(int i=1;i<=grado;++i,++pot){
			if(i==1)
				res[i]=c/(pow(a,pot));
			if(i==2)
				res[i]=-c/(pow(a,pot));
			if(i%2!=0&&i!=1){
				c*=(pot-1);
				res[i]=c/(pow(a,pot));
			}
			if(i%2==0&&i!=2){
				c*=(pot-1);
				res[i]=-c/(pow(a,pot));
			}				
			px+=(res[i]*(long double)(pow(x-a,i)))/factorial(i);
		}
		cout<<"\nP(x)= "<<setprecision(60)<<px<<endl;
		}
		void ex(){
		cout<<"Ingrese el grado de su polinomio de Taylor(Maximo 65): ";
		cin>>grado;
		long double res[grado+1];
		cout<<"a= ";
		cin>>a;
		cout<<"x= ";
		cin>>x;	
		px=pow(e,a);
		for(int i=1;i<=grado;++i)
			px+=((long double)(pow(e,a))*(long double)(pow(x-a,i)))/factorial(i);
		cout<<"\nP(x)= "<<setprecision(60)<<px<<endl;
		}
	private:
		long long int grado=0;
		long long int sigImp=-1;
		long long int sigPar=-1;
		long long int i=1;
		long long int pot=1;
		long long int c=1;
		long long int pos=0;
		long long int fac=1;
		long double a=0;
		long double x=0;
		long double px=0;
		long double Fx=0;
		long double Graf[800];
		
			
};

unsigned long long int factorial(long long int);

int main(){
Funciones funciones;
int opc=0;
cout<<"Escoja una funcion.\n1.-Cos(x).           2.-Sen(x).\n3.-Ln(x).            4.-e^(x)"<<endl;
cin>>opc;
switch(opc){
	case 1:
	funciones.Cosx();
	break;
	case 2:
	funciones.Senx();
	break;
	case 3:
	funciones.Lnx();
	break;
	case 4:
	funciones.ex();
	break;
}
return 0;
}


