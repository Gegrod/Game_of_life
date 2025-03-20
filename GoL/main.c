#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

const ROZMIAR = 25;

void copiuj(int od[ROZMIAR][ROZMIAR], int cel[ROZMIAR][ROZMIAR]) {
    for(int x = 0; x < ROZMIAR; x++) {
        for(int y = 0; y < ROZMIAR; y++) {
            cel[x][y] = od[x][y];

        }
    }
}

void obsluz_komorke(int t[ROZMIAR][ROZMIAR], int temp[ROZMIAR][ROZMIAR], int x, int y) {
            int ile_somsiadow = 0;
            if(y+1<=ROZMIAR-1 && temp[x][y+1] == 1){ ile_somsiadow++; }
            if(x+1<=ROZMIAR-1 && temp[x+1][y] == 1){ ile_somsiadow++; }
            if(x-1>=0 && temp[x-1][y] == 1){ ile_somsiadow++; }
            if(y-1>=0 && temp[x][y-1] == 1){ ile_somsiadow++; }
            if(x-1>=0 && y-1 >= 0 && temp[x-1][y-1]==1){ ile_somsiadow++; }//lewy gora
            if(x+1<=ROZMIAR-1 && y-1 >= 0 && temp[x+1][y-1]==1){ ile_somsiadow++; }//prawy gora
            if(x-1>=0 && y+1 <= ROZMIAR-1 && temp[x-1][y+1]==1){ ile_somsiadow++; }//lewo dol
            if(x+1<=ROZMIAR-1 && y+1 <= ROZMIAR-1 && temp[x+1][y+1]==1){ ile_somsiadow++; }//prawo dol

            if((ile_somsiadow != 3 && ile_somsiadow != 2)&& temp[x][y] == 1){//poprawne
                t[x][y] = 0;
            }
            if(temp[x][y] == 0 && ile_somsiadow == 3){
                t[x][y] = 1;
            }

}

void matematika(int t[ROZMIAR][ROZMIAR]){
    int temp[ROZMIAR][ROZMIAR];
    copiuj(t, temp);

    for(int y = 0; y<ROZMIAR;y++){
        for(int x = 0; x<ROZMIAR;x++){
            obsluz_komorke(t, temp, x, y);
        }
    }
}


void zrob_grafiti_na_scianie_i_zaplac_kare(int t[ROZMIAR][ROZMIAR]){
    for(int y = 0; y<ROZMIAR;y++){
        for(int x = 0; x<ROZMIAR;x++){
            printf("%d ",t[x][y]);

        }
        printf("\n");

    }


}

 int loop(int t[ROZMIAR][ROZMIAR]) {
    while(1) {
        system("cls");
        zrob_grafiti_na_scianie_i_zaplac_kare(t);
        matematika(t);
        getchar();
    }
}

int main()
{
    int a[ROZMIAR][ROZMIAR];
    for(int y = 0; y<ROZMIAR;y++){
        for(int x = 0; x<ROZMIAR;x++){
            a[x][y] = 0;
        }
    }


    a[5][2] = 1;
    a[4][2] = 1;
    a[6][2] = 1;
    a[6][2] = 1;

    loop(a);
    return 0;
}
