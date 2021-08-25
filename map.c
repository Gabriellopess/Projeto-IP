#include "raylib.h"
#include "map.h"
#include "hero.h"
#include <stdio.h>
#include <stdlib.h>


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
    Rectangle rec3 = {(float)76, (float)291, (float)20, (float)40};
    vet[2]= rec3;
    Rectangle rec4 = {(float)122, (float)252, (float)20, (float)60};
    vet[3]= rec4;
    Rectangle rec5 = {(float)85, (float)208, (float)20, (float)60};
    vet[4]= rec5;
    Rectangle rec6 = {(float)39, (float)247, (float)15, (float)18};
    vet[5]= rec6;
    Rectangle rec7 = {(float)0, (float)204, (float)98, (float)20};
    vet[6]= rec7;
    Rectangle rec8 = {(float)96, (float)204, (float)22, (float)130};
    vet[7]= rec8;
    Rectangle rec9 = {(float)127, (float)146, (float)22, (float)80};
    vet[8]= rec9;
    Rectangle rec10 = {(float)52, (float)71, (float)22, (float)40};
    vet[9]= rec10;
    Rectangle rec11 = {(float)0, (float)0, (float)800, (float)20};
    vet[10]= rec11;
    Rectangle rec12 = {(float)186, (float)10, (float)20, (float)148};
    vet[11]= rec12;
    Rectangle rec13 = {(float)186, (float)215, (float)20, (float)55};
    vet[12]= rec13;
    Rectangle rec14 = {(float)186, (float)204, (float)70, (float)20};
    vet[13]= rec14;
    Rectangle rec15 = {(float)250, (float)154, (float)20, (float)70};
    vet[14]= rec15;
    Rectangle rec16 = {(float)250, (float)270, (float)20, (float)114};
    vet[15]= rec16;
    Rectangle rec17 = {(float)250, (float)270, (float)168, (float)20};
    vet[16]= rec17;
    Rectangle rec18 = {(float)315, (float)197, (float)20, (float)90};
    vet[17]= rec18;
    Rectangle rec19 = {(float)315, (float)110, (float)20, (float)40};
    vet[18]= rec19;
    Rectangle rec20 = {(float)250, (float)95, (float)220, (float)20};
    vet[19]= rec20;
    Rectangle rec21 = {(float)400, (float)20, (float)20, (float)90};
    vet[20]= rec21;
    Rectangle rec22 = {(float)410, (float)270, (float)20, (float)65};
    vet[21]= rec22;
    Rectangle rec23 = {(float)384, (float)154, (float)20, (float)70};
    vet[22]= rec23;
    Rectangle rec24 = {(float)384, (float)154, (float)80, (float)20};
    vet[23]= rec24;
    Rectangle rec25 = {(float)464, (float)154, (float)20, (float)150};
    vet[24]= rec25;
    Rectangle rec26 = {(float)484, (float)214, (float)67, (float)20};
    vet[25]= rec26;
    Rectangle rec27 = {(float)535, (float)219, (float)20, (float)100};
    vet[26]= rec27;
    Rectangle rec28 = {(float)535, (float)20, (float)20, (float)110};
    vet[27]= rec28;
    Rectangle rec29 = {(float)565, (float)290, (float)20, (float)150};
    vet[28]= rec29;
    Rectangle rec30 = {(float)565, (float)290, (float)20, (float)100};
    vet[29]= rec30;
    Rectangle rec31 = {(float)565, (float)290, (float)80, (float)20};
    vet[30]= rec31;
    Rectangle rec32 = {(float)618, (float)90, (float)188, (float)20};
    vet[31]= rec32;
    Rectangle rec33 = {(float)618, (float)90, (float)20, (float)80};
    vet[32]= rec33;
    Rectangle rec34 = {(float)790, (float)90, (float)20, (float)365};
    vet[33]= rec34;
    Rectangle rec35 = {(float)0, (float)0, (float)8, (float)320};
    vet[34]= rec35;
    Rectangle rec36 = {(float)618, (float)165, (float)20, (float)180};
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

    //books
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


