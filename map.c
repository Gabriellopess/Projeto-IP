#include <raylib.h>
#include "map.h"
#include "hero.h"
#include "enemy.h"
#include <stdio.h>
#include <stdlib.h>

#define RAIO 8

Rectangle *map(){
    Rectangle *vet = NULL;

    vet = (Rectangle *)realloc(vet,sizeof(Rectangle)*82);

    if(vet == NULL){
        printf("deu merda\n");
        exit(-1);
    }

    Rectangle rec1 = {(float)0, (float)381, (float)800, (float)20};
    vet[0]= rec1;
    Rectangle rec2 = {(float)0, (float)316, (float)207, (float)20}; 
    vet[1]= rec2;
    Rectangle rec3 = {(float)76, (float)291, (float)20, (float)40}; // vertical do lado direito do livro azul
    vet[2]= rec3;
    Rectangle rec4 = {(float)122, (float)252, (float)20, (float)60}; // no
    vet[3]= rec4;
    Rectangle rec5 = {(float)85, (float)208, (float)20, (float)60}; // no
    vet[4]= rec5;
    Rectangle rec6 = {(float)39, (float)247, (float)15, (float)18}; // ok
    vet[5]= rec6;
    Rectangle rec7 = {(float)0, (float)204, (float)98, (float)20};
    vet[6]= rec7;
    Rectangle rec8 = {(float)96, (float)204, (float)22, (float)130}; // no
    vet[7]= rec8;
    Rectangle rec9 = {(float)127, (float)146, (float)22, (float)80}; // no
    vet[8]= rec9;
    Rectangle rec10 = {(float)52, (float)71, (float)22, (float)40}; // ok
    vet[9]= rec10;
    Rectangle rec11 = {(float)0, (float)0, (float)800, (float)20};
    vet[10]= rec11;
    Rectangle rec12 = {(float)186, (float)10, (float)20, (float)148}; // segunda coluna de cima pra baixo
    vet[11]= rec12;
    Rectangle rec13 = {(float)186, (float)215, (float)20, (float)55}; // ok
    vet[12]= rec13;
    Rectangle rec14 = {(float)186, (float)204, (float)70, (float)20}; 
    vet[13]= rec14;
    Rectangle rec15 = {(float)250, (float)154, (float)20, (float)70}; // 
    vet[14]= rec15;
    Rectangle rec16 = {(float)250, (float)270, (float)20, (float)114}; // ok
    vet[15]= rec16;
    Rectangle rec17 = {(float)250, (float)270, (float)168, (float)20};
    vet[16]= rec17;
    Rectangle rec18 = {(float)315, (float)197, (float)20, (float)90}; // ok
    vet[17]= rec18;
    Rectangle rec19 = {(float)315, (float)110, (float)20, (float)40}; // ok
    vet[18]= rec19;
    Rectangle rec20 = {(float)250, (float)95, (float)220, (float)20}; 
    vet[19]= rec20;
    Rectangle rec21 = {(float)400, (float)20, (float)20, (float)90}; // terceita coluna de cima p baixo
    vet[20]= rec21;
    Rectangle rec22 = {(float)410, (float)270, (float)20, (float)65}; // ok 
    vet[21]= rec22;
    Rectangle rec23 = {(float)384, (float)154, (float)20, (float)70}; // ok
    vet[22]= rec23;
    Rectangle rec24 = {(float)384, (float)154, (float)80, (float)20};
    vet[23]= rec24;
    Rectangle rec25 = {(float)464, (float)154, (float)20, (float)150}; // ok
    vet[24]= rec25;
    Rectangle rec26 = {(float)484, (float)214, (float)67, (float)20};
    vet[25]= rec26;
    Rectangle rec27 = {(float)535, (float)219, (float)20, (float)100}; // no 
    vet[26]= rec27;
    Rectangle rec28 = {(float)535, (float)20, (float)20, (float)110}; // ok
    vet[27]= rec28;
    Rectangle rec29 = {(float)565, (float)290, (float)20, (float)150}; 
    vet[28]= rec29;
    Rectangle rec30 = {(float)565, (float)290, (float)20, (float)100}; // segunda coluna de baixo pra cima
    vet[29]= rec30;
    Rectangle rec31 = {(float)565, (float)290, (float)80, (float)20};
    vet[30]= rec31;
    Rectangle rec32 = {(float)618, (float)90, (float)188, (float)20}; // 
    vet[31]= rec32;
    Rectangle rec33 = {(float)618, (float)90, (float)20, (float)80}; // no 
    vet[32]= rec33;
    Rectangle rec34 = {(float)790, (float)90, (float)20, (float)365}; // vertical cantinho  direito
    vet[33]= rec34;
    Rectangle rec35 = {(float)0, (float)0, (float)8, (float)320}; // vertical do cantinho esquerdo
    vet[34]= rec35;
    Rectangle rec36 = {(float)618, (float)165, (float)20, (float)180}; // no
    vet[35]= rec36;

    //A partir daqui os diagonais....
    Rectangle dia1 = {(float)116, (float)258, (float)12, (float)12};
    vet[36]= dia1;
    Rectangle dia2 = {(float)108, (float)265, (float)13, (float)13};
    vet[37]= dia2;
    Rectangle dia3 = {(float)95, (float)278, (float)13, (float)13};
    vet[38]= dia3;
    Rectangle dia4 = {(float)72, (float)221, (float)13, (float)13};
    vet[39]= dia4;
    Rectangle dia5 = {(float)59, (float)234, (float)13, (float)13};
    vet[40]= dia5;
    Rectangle dia6 = {(float)5, (float)141, (float)13, (float)13};
    vet[41]= dia6;
    Rectangle dia7 = {(float)18, (float)154, (float)13, (float)13};
    vet[42]= dia7;
    Rectangle dia8 = {(float)31, (float)163, (float)13, (float)13};
    vet[43]= dia8;
    Rectangle dia9 = {(float)44, (float)175, (float)13, (float)13};
    vet[44]= dia9;
    Rectangle dia10 = {(float)57, (float)185, (float)13, (float)13};
    vet[45]= dia10;
    Rectangle dia11 = {(float)70, (float)194, (float)13, (float)13};
    vet[46]= dia11;
    Rectangle dia12 = {(float)70, (float)112, (float)13, (float)13};
    vet[47]= dia12;
    Rectangle dia13 = {(float)83, (float)124, (float)13, (float)13};
    vet[48]= dia13;
    Rectangle dia14 = {(float)96, (float)135, (float)13, (float)13};
    vet[49]= dia14;
    Rectangle dia15 = {(float)106, (float)143, (float)13, (float)13};
    vet[50]= dia15;
    Rectangle dia16 = {(float)522, (float)232, (float)13, (float)13};
    vet[51]= dia16;
    Rectangle dia17 = {(float)509, (float)245, (float)13, (float)13};
    vet[52]= dia17;
    Rectangle dia18 = {(float)496, (float)258, (float)13, (float)13};
    vet[53]= dia18;
    Rectangle dia19 = {(float)483, (float)271, (float)13, (float)13};
    vet[54]= dia19;
    Rectangle dia20 = {(float)552, (float)303, (float)13, (float)13};
    vet[55]= dia20;
    Rectangle dia21 = {(float)539, (float)316, (float)13, (float)13};
    vet[56]= dia21;
    Rectangle dia22 = {(float)526, (float)329, (float)13, (float)13};
    vet[57]= dia22;
    Rectangle dia23 = {(float)513, (float)342, (float)13, (float)13};
    vet[58]= dia23;
    Rectangle dia24 = {(float)500, (float)355, (float)13, (float)13};
    vet[59]= dia24;
    Rectangle dia25 = {(float)487, (float)368, (float)13, (float)13};
    vet[60]= dia25;
    Rectangle dia26 = {(float)634, (float)170, (float)13, (float)13};
    vet[61]= dia26;
    Rectangle dia27 = {(float)647, (float)183, (float)13, (float)13};
    vet[62]= dia27;
    Rectangle dia28 = {(float)658, (float)197, (float)13, (float)13};
    vet[63]= dia28;
    Rectangle dia29 = {(float)669, (float)210, (float)13, (float)13};
    vet[64]= dia29;
    Rectangle dia30 = {(float)680, (float)223, (float)13, (float)13};
    vet[65]= dia30;
    Rectangle dia31 = {(float)691, (float)236, (float)13, (float)13};
    vet[66]= dia31;
    Rectangle dia32 = {(float)703, (float)249, (float)13, (float)13};
    vet[67]= dia32;
    Rectangle dia33 = {(float)713, (float)262, (float)13, (float)13};
    vet[68]= dia33;
    Rectangle dia34 = {(float)721, (float)271, (float)13, (float)13};
    vet[69]= dia34;
    Rectangle dia35 = {(float)730, (float)281, (float)12, (float)12};
    vet[70]= dia35;

    //venenos
    Rectangle veneno = {(float)410, (float)335, (float)20, (float)46};
    vet[71]= veneno;
    Rectangle veneno2 = {(float)52, (float)20, (float)22, (float)51};
    vet[72]= veneno2;
    Rectangle veneno3 = {(float)618, (float)20, (float)20, (float)70};
    vet[73]= veneno3;

    //area segura
    Rectangle areaSeguranca = {(float)33, (float)335, (float)60, (float)45};
    vet[74]= areaSeguranca;
    Rectangle areaSeguranca2 = {(float)700, (float)110, (float)90, (float)45};
    vet[75]= areaSeguranca2;
    Rectangle areaSeguranca3 = {(float)300, (float)20, (float)100, (float)75};
    vet[76]= areaSeguranca3;

    Rectangle actGhost1 = {(float)15, (float)280, (float)25, (float)25};
    vet[77]= actGhost1;
    Rectangle actGhost2 = {(float)275, (float)300, (float)25, (float)25};
    vet[78]= actGhost2;
    Rectangle actGhost3 = {(float)650, (float)120, (float)25, (float)25};
    vet[79]= actGhost3;

    //mascara de gas
    Rectangle mask = {(float)20, (float)30, (float)25, (float)25};
    vet[80]= mask;

    //saida
    Rectangle door = {(float)780, (float)20, (float)20, (float)70};
    vet[81]= door;

    return vet;
}



void collisionHero(int *countTime,int *auxTime, int *timeElapsed, int *gameStage, int *books, Vector2 ballPosition,float *ballPositionx,float *ballPositiony,int *soltaInimigo1,int *soltaInimigo2,int * book3,int *power){
    Rectangle *mapa = NULL;
    mapa = map();

    //colisoes com o terreno
    if((*ballPositionx) <= 8 || ((*ballPositionx) >= 8 && (*ballPositionx) <= 207 && (*ballPositiony) >= 316 && (*ballPositiony) <= 336)
    || ((*ballPositionx) >= 0 && (*ballPositionx) <= 8 && (*ballPositiony) >= 0 && (*ballPositiony) <= 400)
    || ((*ballPositionx) >= 0 && (*ballPositionx) <= 800 && (*ballPositiony) >= 0 && (*ballPositiony) <= 20)
    || ((*ballPositionx) >= 250 && (*ballPositionx) <= 280 && (*ballPositiony) >= 270 && (*ballPositiony) <= 384)
    || ((*ballPositionx) >= 250 && (*ballPositionx) <= 418 && (*ballPositiony) >= 270 && (*ballPositiony) <= 290)
    || ((*ballPositionx) >= 618 && (*ballPositionx) <= 800 && (*ballPositiony) >= 90 && (*ballPositiony) <= 110)
    || ((*ballPositionx) >= 618 && (*ballPositionx) <= 638 && (*ballPositiony) >= 90 && (*ballPositiony) <= 170)){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356);
    }

    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[0])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356);
    }
    // if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[1])){
    //    deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356);
    // }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[2])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356);
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[5])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356);
    } 
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[6])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356);
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[9])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    // if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[10])){
    //     deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    // }
    if(CheckCollisionCircleRec(ballPosition, RAIO,mapa[11])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[12])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[13])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[14])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    // if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[15])){
    //     deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    // }
    // if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[16])){
    //     deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    // }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[17])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[18])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[19])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[20])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[21])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[22])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[23])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[24])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[25])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }

    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[27])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[29])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[30])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    // if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[31])){
    //     deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    // }
    // if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[32])){
    //     deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    // }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[33])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    // if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[34])){
    //     deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    // } 

    //diagonais
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[36])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[37])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[38])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[39])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[40])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[41])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[42])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[43])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[44])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[45])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[46])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[47])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[48])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[49])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[50])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[51])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[52])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[53])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[54])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[55])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[56])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[57])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[58])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[59])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[60])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[61])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[62])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[63])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[64])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[65])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[66])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[67])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[68])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[69])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }
    if(CheckCollisionCircleRec(ballPosition, 8, mapa[70])){
        deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
    }

    //books
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[77])){
        if((*soltaInimigo1) == 0){
            (*books)++;
        }
        (*soltaInimigo1) =1;
    } 
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[78])) {
        if((*soltaInimigo2) == 0){
            (*books)++;
        }
        (*soltaInimigo2) =1;
    }
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[79])) {
        if((*book3) == 0){
            (*books)++;
        }
        (*book3) = 1;
    }


    //mascara
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[80])) (*power) =1;

    //veneno
    if (!powerPoison((*power))){
        if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[71]) 
        || CheckCollisionCircleRec(ballPosition, RAIO, mapa[72])
        || CheckCollisionCircleRec(ballPosition, RAIO, mapa[73])){

            deathHero(books,ballPositionx,ballPositiony,soltaInimigo1,soltaInimigo2,book3,power,33,356); 
        }

    }
    
    //saida
    if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[81]) && (*soltaInimigo1) == 1 && (*soltaInimigo2) == 1 
    && (*book3) == 1){
        // CloseWindow(); 
        *gameStage = 4;
        if(countTime == 0){
            *auxTime = *timeElapsed;
            *countTime = 1;
        }
    } 
    else if(CheckCollisionCircleRec(ballPosition, RAIO, mapa[81])){
        (*ballPositionx) = 770;
    }
    free(mapa);

}



void collisionEnemy(Vector2 enemyPosition,Vector2 enemyPosition2,float *enemyPositionx,float *enemyPositiony,float *enemyPosition2x,float *enemyPosition2y){
    Rectangle *mapa = NULL;
    mapa = map();

    //area de segurança
    if(CheckCollisionCircleRec(enemyPosition, RAIO, mapa[74])){
        resetEnemy(enemyPositionx,enemyPositiony,450,80);
    }
    if(CheckCollisionCircleRec(enemyPosition2, RAIO, mapa[74])){
        resetEnemy(enemyPosition2x,enemyPosition2y,600,356);
    }

    if(CheckCollisionCircleRec(enemyPosition, RAIO, mapa[75])){
        resetEnemy(enemyPositionx,enemyPositiony,450,80);
    }
    if(CheckCollisionCircleRec(enemyPosition2, RAIO, mapa[75])){
        resetEnemy(enemyPosition2x,enemyPosition2y,600,356);
    }

    if(CheckCollisionCircleRec(enemyPosition, RAIO, mapa[76])){
        resetEnemy(enemyPositionx,enemyPositiony,450,80);
    }
    if(CheckCollisionCircleRec(enemyPosition2, RAIO, mapa[76])){
        resetEnemy(enemyPosition2x,enemyPosition2y,600,356);
    }

    free(mapa);
}