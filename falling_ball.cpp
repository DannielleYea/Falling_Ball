#include <iostream>
#include <stdio.h>
#include <ctime>
#include <thread>
#include <windows.h>

using namespace std;

char ekran[12][8];
short igra = true;
short x = 4;
short prolaz = -3;
short vrijeme = 500;

void tipke(){
		 while(igra){
			  if( (GetAsyncKeyState( 'A' ) & 0x8000) && x > 0){
			      ekran[11][x] = 0;
			      ekran[11][--x] = 2;
						}
        else if( (GetAsyncKeyState( 'D' ) & 0x8000) && x < 7){
            ekran[11][x] = 0;
            ekran[11][++x] = 2;
						}
            
        Sleep(100);
   }
}

void ispis(){
	while(igra){
	for(int i = 12; i > 0 ; i--)
					for(int j = 0; j < 8; j++){
							if(i == 1)
									 cout << (char)254;
							else{
									if(ekran[i][j] == 1)
									    cout << (char)254;
					        else if(ekran[i][j] == 2)
					            cout << 'O';
					        else
					            cout << " ";
	    				    if(j == 7)
	    				    		 cout << (char)254 << endl;
				    	    }
					}
	    cout << (char)254;
	    Sleep(10);
	    system("cls");
	  }
}


int main(){
  thread t1(tipke);	
  thread t2(ispis);
  
  ekran[11][x] == 2;
  
  srand(time(0));
  rand();
  short sredina;
  short rep = 5;
  
	while(igra){
	    //ekran[11][x] = 2; 
	    if(1 == ekran[11][x]){
	    	igra = false;
	    	system("pause");
			}
		
      if(rep == 5){
      	rep = 0;
      	vrijeme *= 0.95;
      	sredina = (rand() % 5) + 2;
      	prolaz++;
     	
				for(int i = 0 ; i < 8; i++)
				    if(i != sredina-1)
	    		      ekran[0][i] = 1;
		        else 
      	        i += 2;
      }
      
      for(int i = 11 ; i >= 0 ; i--)
        if(ekran[i][0] == 1)
          for(int j = 0 ; j < 8 ; j++){
			            if(ekran[i][j] == 1){
			            	if(i == 11)
			            			 ekran[i][j] = 0;
            			  else{
					            ekran[i][j] = 0;
			            		ekran[i+1][j] = 1;	
											}
									}	
				  }
      
		  rep++;
	   	Sleep(vrijeme);
  }
		
  t1.join();
  t2.join();
  cout <<"Rezultat je: " << prolaz << endl;
  system("pause");
  return 0;
}
