#include <iostream>
#include <math.h>

#define pi 3.14159265

using namespace std;

float calcolo_k(double,float,int);


int main(){
	
	float f_min,f_max,k=0,bs,bp,L_tot;
	double tau,angolo_rad,lunghezza[100],distanza[100];
	int angolo;
	
	cout<<"Inserire valore inferiore intervallo frequenze: [MHz]"<<endl;
	cin>>f_min;
	cout<<endl<<"Inserire valore superiore intervallo frequenze: [MHz]"<<endl;
	cin>>f_max;
	
	bp=f_max/f_min;
	cout<<endl<<"Il rapporto BP e': "<<bp<<endl;
		
	cout<<endl<<"Determinare l'angolo che si vuole dare agli elementi dell'antenna (angolo riferito a meta' sezione)."<<endl;
	cout<<"Il valore deve essere compreso tra 4-25 gradi. Piu' e' ampio l'angolo meno elementi avra' l'antenna."<<endl;
	cout<<"DEVE ESSERE UN NUMERO INTERO"<<endl;
	cin>>angolo;
	angolo_rad=angolo*pi/180;
	
	cout<<endl<<"Inserire il valore di tau. Deve essere compreso tra 0.84 e 0.98"<<endl<<" (scegliendo 0.84 si avra' un'antenna con pochi elementi ma molto lunga, scegliendo 0.98 si avra' un'antenna piu' corta ma con piu' elementi)"<<endl;
	cout<<"Si consiglia un valore tra 0.88 e 0.94"<<endl;
	cin>>tau;
	
	cout<<endl<<"Valori inseriti: "<<tau<<" "<<angolo<<"gradi"<<endl;
	
	k=calcolo_k(tau,k,angolo);
	cout<<endl<<"Il fattore k e': "<<k<<endl;
	
	bs=k*bp;
	cout<<endl<<"Il fattore BS e': "<<bs<<endl;
	
	L_tot=(1-(1/bs))*(1/tan(angolo_rad))*0.25*(28800/f_min);
	cout<<endl<<"La lunghezza totale dell'asta di supporto deve essere: "<<L_tot<<"cm"<<endl;	
	
	//calcolo lunghezze dipoli e distanze
	double somma=0;
	lunghezza[0]=7200/f_min;
	int i=1,j=0;
	while(somma<L_tot){
		lunghezza[i]=lunghezza[i-1]*tau;
		distanza[j]=(lunghezza[j]-lunghezza[i])*(1/tan(angolo_rad));
		somma=somma+distanza[j];
		i++;
		j++;
	}
	
	cout<<endl<<"L'antenna e' formata da "<<i<<" elementi per lato."<<endl;
	cout<<endl<<"La distanza tra il centro del primo elemento e dell'ultimo e': "<<somma<<"cm."<<endl;
	
	cout<<endl<<"Le lunghezze dei "<<i<<" semidopoli sono: "<<endl;
	for(int n=0;n<i;n++)
		cout<<"Elemento "<<n<<": "<<lunghezza[n]<<"cm"<<endl;
		
	cout<<endl<<"Le distanze tra i semidipoli sono: "<<endl;
	for(int n=0;n<j;n++)
		cout<<"Distanza tra "<<n<<" ed "<<n+1<<" : "<<distanza[n]*10<<"mm"<<endl;
	
	system("PAUSE");
	
}


float calcolo_k(double tau,float k,int angolo){
	
	if(angolo==4){
		if(tau==0.84)
			k=3.919;
		else if(tau==0.85)
			k=3.578;
		else if(tau==0.86)
			k=3.258;
		else if(tau==0.87)
			k=2.961;
		else if(tau==0.88)
			k=2.685;	
		else if(tau==0.89)
			k=2.432;
		else if(tau==0.90)
			k=2.201;
		else if(tau==0.91)
			k=1.992;
		else if(tau==0.92)
			k=1.805;
		else if(tau==0.93)
			k=1.640;
		else if(tau==0.94)
			k=1.496;
		else if(tau==0.95)
			k=1.375;
		else if(tau==0.96)
			k=1.276;
		else if(tau==0.97)
			k=1.199;
		else if(tau==0.98)
			k=1.144;
	}
	
	else if(angolo==5){
		if(tau==0.84)
			k=3.353;
		else if(tau==0.85)
			k=3.080;
		else if(tau==0.86)
			k=2.825;
		else if(tau==0.87)
			k=2.587;
		else if(tau==0.88)
			k=2.367;	
		else if(tau==0.89)
			k=2.165;
		else if(tau==0.90)
			k=1.980;
		else if(tau==0.91)
			k=1.813;
		else if(tau==0.92)
			k=1.663;
		else if(tau==0.93)
			k=1.531;
		else if(tau==0.94)
			k=1.417;
		else if(tau==0.95)
			k=1.320;
		else if(tau==0.96)
			k=1.241;
		else if(tau==0.97)
			k=1.179;
		else if(tau==0.98)
			k=1.135;
	}
	
	else if(angolo==6){
		if(tau==0.84)
			k=2.975;
		else if(tau==0.85)
			k=2.748;
		else if(tau==0.86)
			k=2.536;
		else if(tau==0.87)
			k=2.338;
		else if(tau==0.88)
			k=2.155;	
		else if(tau==0.89)
			k=1.986;
		else if(tau==0.90)
			k=1.883;
		else if(tau==0.91)
			k=1.693;
		else if(tau==0.92)
			k=1.569;
		else if(tau==0.93)
			k=1.459;
		else if(tau==0.94)
			k=1.364;
		else if(tau==0.95)
			k=1.283;
		else if(tau==0.96)
			k=1.217;
		else if(tau==0.97)
			k=1.166;
		else if(tau==0.98)
			k=1.129;
	}
	
	else if(angolo==7){
		if(tau==0.84)
			k=2.705;    
		else if(tau==0.85)
			k=2.511;
		else if(tau==0.86)
			k=2.329;
		else if(tau==0.87)
			k=2.160;
		else if(tau==0.88)
			k=2.003;	
		else if(tau==0.89)
			k=1.859;
		else if(tau==0.90)
			k=1.727;
		else if(tau==0.91)
			k=1.608;
		else if(tau==0.92)
			k=1.501;
		else if(tau==0.93)
			k=1.407;
		else if(tau==0.94)
			k=1.326;
		else if(tau==0.95)
			k=1.257;
		else if(tau==0.96)
			k=1.200;
		else if(tau==0.97)
			k=1.156;
		else if(tau==0.98)
			k=1.125;
	}
	
	else if(angolo==8){
		if(tau==0.84)
			k=2.503;    
		else if(tau==0.85)  //2,503 2,333 2,174 2,026 1,889 1,763 1,648 1,544 1,451 1,368 1,297 1,237 1,188 1,149 1,122
			k=2.333;
		else if(tau==0.86)
			k=2.174;
		else if(tau==0.87)
			k=2.026;
		else if(tau==0.88)
			k=2.889;	
		else if(tau==0.89)
			k=1.763;
		else if(tau==0.90)
			k=1.648;
		else if(tau==0.91)
			k=1.544;
		else if(tau==0.92)
			k=1.451;
		else if(tau==0.93)
			k=1.368;
		else if(tau==0.94)
			k=1.297;
		else if(tau==0.95)
			k=1.237;
		else if(tau==0.96)
			k=1.188;
		else if(tau==0.97)
			k=1.149;
		else if(tau==0.98)
			k=1.122;
	}
	
	else if(angolo==9){
		if(tau==0.84)
			k=2.345;    
		else if(tau==0.85)  //2,345 2,194 2,053 1,922 1,800 1,688 1,586 1,494 1,411 1,338 1,275 1,222 1,178 1,144 1,119
			k=2.194;
		else if(tau==0.86)
			k=2.053;
		else if(tau==0.87)
			k=1.922;
		else if(tau==0.88)
			k=1.800;	
		else if(tau==0.89)
			k=1.688;
		else if(tau==0.90)
			k=1.586;
		else if(tau==0.91)
			k=1.494;
		else if(tau==0.92)
			k=1.411;
		else if(tau==0.93)
			k=1.338;
		else if(tau==0.94)
			k=1.275;
		else if(tau==0.95)
			k=1.222;
		else if(tau==0.96)
			k=1.178;
		else if(tau==0.97)
			k=1.144;
		else if(tau==0.98)
			k=1.119;
	}
	
	else if(angolo==10){
		if(tau==0.84)
			k=2.218;    
		else if(tau==0.85)  //2,218 2,083 1,956 1,838 1,729 1,628 1,537 1,454 1,379 1,314 1,257 1,209 1,170 1,139 1,117
			k=2.083;
		else if(tau==0.86)
			k=1.956;
		else if(tau==0.87)
			k=1.838;
		else if(tau==0.88)
			k=1.729;	
		else if(tau==0.89)
			k=1.628;
		else if(tau==0.90)
			k=1.537;
		else if(tau==0.91)
			k=1.454;
		else if(tau==0.92)
			k=1.379;
		else if(tau==0.93)
			k=1.314;
		else if(tau==0.94)
			k=1.257;
		else if(tau==0.95)
			k=1.209;
		else if(tau==0.96)
			k=1.170;
		else if(tau==0.97)
			k=1.139;
		else if(tau==0.98)
			k=1.117;
	}
	
	else if(angolo==11){
		if(tau==0.84)
			k=2.114;    
		else if(tau==0.85)  //2,114 1,991 1,876 1,769 1,670 1,579 1,496 1,421 1,354 1,294 1,243 1,199 1,163 1,136 1,116
			k=1.991;
		else if(tau==0.86)
			k=1.876;
		else if(tau==0.87)
			k=1.769;
		else if(tau==0.88)
			k=1.670;	
		else if(tau==0.89)
			k=1.579;
		else if(tau==0.90)
			k=1.496;
		else if(tau==0.91)
			k=1.421;
		else if(tau==0.92)
			k=1.354;
		else if(tau==0.93)
			k=1.294;
		else if(tau==0.94)
			k=1.243;
		else if(tau==0.95)
			k=1.199;
		else if(tau==0.96)
			k=1.163;
		else if(tau==0.97)
			k=1.136;
		else if(tau==0.98)
			k=1.116;
	}
	
	else if(angolo==12){
		if(tau==0.84)
			k=2.027;    
		else if(tau==0.85)  //2,027 1,915 1,810 1,712 1,622 1,538 1,462 1,393 1,332 1,278 1,230 1,191 1,158 1,133 1,114
			k=1.915;
		else if(tau==0.86)
			k=1.810;
		else if(tau==0.87)
			k=1.712;
		else if(tau==0.88)
			k=1.622;	
		else if(tau==0.89)
			k=1.538;
		else if(tau==0.90)
			k=1.462;
		else if(tau==0.91)
			k=1.392;
		else if(tau==0.92)
			k=1.332;
		else if(tau==0.93)
			k=1.278;
		else if(tau==0.94)
			k=1.230;
		else if(tau==0.95)
			k=1.191;
		else if(tau==0.96)
			k=1.158;
		else if(tau==0.97)
			k=1.133;
		else if(tau==0.98)
			k=1.114;
	}
	
	else if(angolo==13){
		if(tau==0.84)
			k=1.954;    
		else if(tau==0.85)  //1,954 1,850 1,754 1,664 1,580 1,504 1,434 1,370 1,313 1,263 1,220 1,183 1,153 1,130 1,113
			k=1.850;
		else if(tau==0.86)
			k=1.754;
		else if(tau==0.87)
			k=1.664;
		else if(tau==0.88)
			k=1.580;	
		else if(tau==0.89)
			k=1.504;
		else if(tau==0.90)
			k=1.434;
		else if(tau==0.91)
			k=1.370;
		else if(tau==0.92)
			k=1.313;
		else if(tau==0.93)
			k=1.263;
		else if(tau==0.94)
			k=1.220;
		else if(tau==0.95)
			k=1.183;
		else if(tau==0.96)
			k=1.153;
		else if(tau==0.97)
			k=1.130;
		else if(tau==0.98)
			k=1.113;
	}
	
	else if(angolo==14){
		if(tau==0.84)
			k=1.891;    
		else if(tau==0.85)  //1,891 1,795 1,705 1,622 1,545 1,474 1,409 1,350 1,298 1,251 1,211 1,177 1,149 1,128 1,112
			k=1.795;
		else if(tau==0.86)
			k=1.705;
		else if(tau==0.87)
			k=1.622;
		else if(tau==0.88)
			k=1.545;	
		else if(tau==0.89)
			k=1.472;
		else if(tau==0.90)
			k=1.409;
		else if(tau==0.91)
			k=1.350;
		else if(tau==0.92)
			k=1.298;
		else if(tau==0.93)
			k=1.251;
		else if(tau==0.94)
			k=1.211;
		else if(tau==0.95)
			k=1.177;
		else if(tau==0.96)
			k=1.149;
		else if(tau==0.97)
			k=1.128;
		else if(tau==0.98)
			k=1.112;
	}
	
	else if(angolo==15){
		if(tau==0.84)
			k=1.836;    
		else if(tau==0.85)  //1,836 1,747 1,663 1,568 1,514 1,448 1,387 1,333 1,284 1,241 1.203 1,172 1,146 1,126 1,111
			k=1.747;
		else if(tau==0.86)
			k=1.663;
		else if(tau==0.87)
			k=1.568;
		else if(tau==0.88)
			k=1.514;	
		else if(tau==0.89)
			k=1.448;
		else if(tau==0.90)
			k=1.387;
		else if(tau==0.91)
			k=1.333;
		else if(tau==0.92)
			k=1.284;
		else if(tau==0.93)
			k=1.241;
		else if(tau==0.94)
			k=1.203;
		else if(tau==0.95)
			k=1.172;
		else if(tau==0.96)
			k=1.146;
		else if(tau==0.97)
			k=1.126;
		else if(tau==0.98)
			k=1.111;
	}
	
	else if(angolo==16){
		if(tau==0.84)
			k=1.787;    
		else if(tau==0.85)  //1,787 1,704 1,626 1,554 1,487 1,425 1,369 1,318 1,272 1,232 1,197 1,167 1,143 1,124 1,111
			k=1.704;
		else if(tau==0.86)
			k=1.626;
		else if(tau==0.87)
			k=1.554;
		else if(tau==0.88)
			k=1.487;	
		else if(tau==0.89)
			k=1.425;
		else if(tau==0.90)
			k=1.369;
		else if(tau==0.91)
			k=1.318;
		else if(tau==0.92)
			k=1.272;
		else if(tau==0.93)
			k=1.232;
		else if(tau==0.94)
			k=1.197;
		else if(tau==0.95)
			k=1.167;
		else if(tau==0.96)
			k=1.143;
		else if(tau==0.97)
			k=1.124;
		else if(tau==0.98)
			k=1.111;
	}
	
	else if(angolo==17){
		if(tau==0.84)
			k=1.745;    
		else if(tau==0.85)  //1,745 1,667 1,594 1,526 1,463 1,405 1,352 1,304 1,261 1,223 1,191 1,163 1,140 1,123 1,110
			k=1.667;
		else if(tau==0.86)
			k=1.594;
		else if(tau==0.87)
			k=1.526;
		else if(tau==0.88)
			k=1.463;	
		else if(tau==0.89)
			k=1.405;
		else if(tau==0.90)
			k=1.352;
		else if(tau==0.91)
			k=1.304;
		else if(tau==0.92)
			k=1.261;
		else if(tau==0.93)
			k=1.223;
		else if(tau==0.94)
			k=1.191;
		else if(tau==0.95)
			k=1.163;
		else if(tau==0.96)
			k=1.140;
		else if(tau==0.97)
			k=1.123;
		else if(tau==0.98)
			k=1.110;
	}
	
	else if(angolo==18){
		if(tau==0.84)
			k=1.707;    
		else if(tau==0.85)  //1,707 1,633 1,564 1,500 1,441 1,387 1,337 1,292 1,252 1,216 1,185 1,159 1,138 1,121 1,109
			k=1.633;
		else if(tau==0.86)
			k=1.564;
		else if(tau==0.87)
			k=1.500;
		else if(tau==0.88)
			k=1.441;	
		else if(tau==0.89)
			k=1.387;
		else if(tau==0.90)
			k=1.337;
		else if(tau==0.91)
			k=1.292;
		else if(tau==0.92)
			k=1.252;
		else if(tau==0.93)
			k=1.216;
		else if(tau==0.94)
			k=1.185;
		else if(tau==0.95)
			k=1.159;
		else if(tau==0.96)
			k=1.138;
		else if(tau==0.97)
			k=1.121;
		else if(tau==0.98)
			k=1.109;
	}
	
	else if(angolo==19){
		if(tau==0.84)
			k=1.672;    
		else if(tau==0.85)  //1,672 1,603 1,538 1,478 1,422 1,371 1,324 1,281 1,243 1,210 1,181 1,156 1,136 1,120 1,109
			k=1.603;
		else if(tau==0.86)
			k=1.538;
		else if(tau==0.87)
			k=1.478;
		else if(tau==0.88)
			k=1.422;	
		else if(tau==0.89)
			k=1.371;
		else if(tau==0.90)
			k=1.324;
		else if(tau==0.91)
			k=1.281;
		else if(tau==0.92)
			k=1.243;
		else if(tau==0.93)
			k=1.210;
		else if(tau==0.94)
			k=1.181;
		else if(tau==0.95)
			k=1.156;
		else if(tau==0.96)
			k=1.136;
		else if(tau==0.97)
			k=1.120;
		else if(tau==0.98)
			k=1.109;
	}
	
	else if(angolo==20){
		if(tau==0.84)
			k=1.642;    
		else if(tau==0.85)  //1,642 1,576 1,515 1,458 1,405 1,356 1,312 1,271 1,235 1,204 1,176 1,153 1,134 1,119 1,108
			k=1.576;
		else if(tau==0.86)
			k=1.515;
		else if(tau==0.87)
			k=1.458;
		else if(tau==0.88)
			k=1.405;	
		else if(tau==0.89)
			k=1.356;
		else if(tau==0.90)
			k=1.312;
		else if(tau==0.91)
			k=1.271;
		else if(tau==0.92)
			k=1.235;
		else if(tau==0.93)
			k=1.204;
		else if(tau==0.94)
			k=1.176;
		else if(tau==0.95)
			k=1.153;
		else if(tau==0.96)
			k=1.134;
		else if(tau==0.97)
			k=1.119;
		else if(tau==0.98)
			k=1.108;
	}
	
	else if(angolo==21){
		if(tau==0.84)
			k=1.614;    
		else if(tau==0.85)  //1,614 1,551 1,493 1,439 1,389 1,343 1,301 1,262 1,228 1,198 1,172 1,150 1,132 1,118 1,108
			k=1.551;
		else if(tau==0.86)
			k=1.493;
		else if(tau==0.87)
			k=1.439;
		else if(tau==0.88)
			k=1.389;	
		else if(tau==0.89)
			k=1.343;
		else if(tau==0.90)
			k=1.301;
		else if(tau==0.91)
			k=1.262;
		else if(tau==0.92)
			k=1.228;
		else if(tau==0.93)
			k=1.198;
		else if(tau==0.94)
			k=1.172;
		else if(tau==0.95)
			k=1.150;
		else if(tau==0.96)
			k=1.132;
		else if(tau==0.97)
			k=1.118;
		else if(tau==0.98)
			k=1.108;
	}
	
	else if(angolo==22){
		if(tau==0.84)
			k=1.588;    
		else if(tau==0.85)  //1,588 1,529 1,474 1,422 1,374 1,331 1,291 1,254 1,222 1,193 1,169 1,148 1,130 1,117 1,108
			k=1.529;
		else if(tau==0.86)
			k=1.474;
		else if(tau==0.87)
			k=1.422;
		else if(tau==0.88)
			k=1.374;	
		else if(tau==0.89)
			k=1.331;
		else if(tau==0.90)
			k=1.291;
		else if(tau==0.91)
			k=1.254;
		else if(tau==0.92)
			k=1.222;
		else if(tau==0.93)
			k=1.193;
		else if(tau==0.94)
			k=1.169;
		else if(tau==0.95)
			k=1.148;
		else if(tau==0.96)
			k=1.130;
		else if(tau==0.97)
			k=1.117;
		else if(tau==0.98)
			k=1.108;
	}
	
	else if(angolo==23){
		if(tau==0.84)
			k=1.564;    
		else if(tau==0.85)  //1,564 1,508 1,456 1,407 1,361 1,319 1,281 1,247 1,216 1,189 1,165 1,145 1,129 1,116 1,107
			k=1.508;
		else if(tau==0.86)
			k=1.456;
		else if(tau==0.87)
			k=1.407;
		else if(tau==0.88)
			k=1.361;	
		else if(tau==0.89)
			k=1.319;
		else if(tau==0.90)
			k=1.281;
		else if(tau==0.91)
			k=1.247;
		else if(tau==0.92)
			k=1.216;
		else if(tau==0.93)
			k=1.189;
		else if(tau==0.94)
			k=1.165;
		else if(tau==0.95)
			k=1.145;
		else if(tau==0.96)
			k=1.129;
		else if(tau==0.97)
			k=1.116;
		else if(tau==0.98)
			k=1.107;
	}
	
	else if(angolo==24){
		if(tau==0.84)
			k=1.543;    
		else if(tau==0.85)  //1,543 1,489 1,439 1,392 1,349 1,309 1,273 1,240 1,211 1,185 1,162 1,143 1,128 1,116 1,107
			k=1.489;
		else if(tau==0.86)
			k=1.439;
		else if(tau==0.87)
			k=1.392;
		else if(tau==0.88)
			k=1.349;	
		else if(tau==0.89)
			k=1.309;
		else if(tau==0.90)
			k=1.273;
		else if(tau==0.91)
			k=1.240;
		else if(tau==0.92)
			k=1.211;
		else if(tau==0.93)
			k=1.185;
		else if(tau==0.94)
			k=1.162;
		else if(tau==0.95)
			k=1.143;
		else if(tau==0.96)
			k=1.128;
		else if(tau==0.97)
			k=1.116;
		else if(tau==0.98)
			k=1.107;
	}
	
	else if(angolo==25){
		if(tau==0.84)
			k=1.523;    
		else if(tau==0.85)  //1,523 1,472 1,424 1,379 1,338 1,300 1,265 1,234 1,206 1,181 1,159 1,141 1,126 1,115 1,107
			k=1.472;
		else if(tau==0.86)
			k=1.424;
		else if(tau==0.87)
			k=1.379;
		else if(tau==0.88)
			k=1.338;	
		else if(tau==0.89)
			k=1.300;
		else if(tau==0.90)
			k=1.265;
		else if(tau==0.91)
			k=1.234;
		else if(tau==0.92)
			k=1.206;
		else if(tau==0.93)
			k=1.181;
		else if(tau==0.94)
			k=1.159;
		else if(tau==0.95)
			k=1.141;
		else if(tau==0.96)
			k=1.126;
		else if(tau==0.97)
			k=1.115;
		else if(tau==0.98)
			k=1.107;
	}
	
	else if(angolo==26){
		if(tau==0.84)
			k=1.504;    
		else if(tau==0.85)  //1,504 1,455 1,409 1,367 1,327 1,291 1,258 1,228 1,201 1,177 1,157 1,139 1,125 1,114 1,106
			k=1.455;
		else if(tau==0.86)
			k=1.409;
		else if(tau==0.87)
			k=1.367;
		else if(tau==0.88)
			k=1.327;	
		else if(tau==0.89)
			k=1.291;
		else if(tau==0.90)
			k=1.258;
		else if(tau==0.91)
			k=1.228;
		else if(tau==0.92)
			k=1.201;
		else if(tau==0.93)
			k=1.177;
		else if(tau==0.94)
			k=1.157;
		else if(tau==0.95)
			k=1.139;
		else if(tau==0.96)
			k=1.125;
		else if(tau==0.97)
			k=1.114;
		else if(tau==0.98)
			k=1.106;
	}
	
	else if(angolo==27){
		if(tau==0.84)
			k=1.487;    
		else if(tau==0.85)  //1,487 1,440 1,396 1,355 1,318 1,283 1,251 1,222 1,197 1,174 1,154 1,138 1,124 1,114 1,106
			k=1.440;
		else if(tau==0.86)
			k=1.396;
		else if(tau==0.87)
			k=1.355;
		else if(tau==0.88)
			k=1.318;	
		else if(tau==0.89)
			k=1.283;
		else if(tau==0.90)
			k=1.251;
		else if(tau==0.91)
			k=1.222;
		else if(tau==0.92)
			k=1.197;
		else if(tau==0.93)
			k=1.174;
		else if(tau==0.94)
			k=1.154;
		else if(tau==0.95)
			k=1.138;
		else if(tau==0.96)
			k=1.124;
		else if(tau==0.97)
			k=1.114;
		else if(tau==0.98)
			k=1.106;
	}
	
	return k;
	
}

















