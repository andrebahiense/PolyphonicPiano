/* PIANO POLIFONICO - Por Andre Bahiense e Alexandre Magalhães / Agosto de 2017
| A quantidade de vozes vai variar de acordo com a quantidade de timers de cada Arduino
|
|
--------------------------------------------------------------------------------------------*/
#include <Tone.h>

// Declaração de vozes
Tone tone1; 
Tone tone2;
Tone tone3;
Tone tone4;

// Declaração das notas apertadas
int nota1=0;
int nota2=0;
int nota3=0;
int nota4=0;

// Marcação para a ativação de cada nota
int flag1=0;
int flag2=0;
int flag3=0;
int flag4 =0;

// Vetor de Frequencias ja identificadas. A biblioteca Tone.h define previamente as notas de 31 a 4978 Hz
int notas[24]={NOTE_C4,NOTE_CS4,NOTE_D4,NOTE_DS4,NOTE_E4,NOTE_F4,NOTE_FS4,NOTE_G4,NOTE_GS4,NOTE_A4,NOTE_AS4,NOTE_B4,NOTE_C5,NOTE_CS5,NOTE_D5,NOTE_DS5,NOTE_E5,NOTE_F5,NOTE_FS5,NOTE_G5,NOTE_GS5,NOTE_A5,NOTE_AS5,NOTE_B5};

// Vetor de identificação dos botões
int botoes[24]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

void setup()
{
 Serial.begin(9600);
 
 //Definição das pinos de Output
 tone1.begin(12);
 tone2.begin(11);
 tone3.begin(10);
 tone4.begin(9);

}
void loop()
{

// Loop de identificação de botões ativos
  int indice=0;
 for(int i=30;i<54;i++){
  if(digitalRead(i)==HIGH){
    /*if(indice<3 && botoes[indice]>0){
      indice++;
      botoes[indice]=i;
    }*/
   /* if(botoes[indice]>0)
    {
      indice++;
    }*/
    if(indice<4){
    botoes[indice]=i;
    indice++;
    }
    
 }
 }
 for(int l=0;l<3;l++){
  Serial.print(botoes[l]);
 }
 Serial.println(botoes[3]);
  for(int j=0;j<4;j++){
    
    
    //Rotina de execução das notas
    if(botoes[j]!=0){
    if(flag1==0){
    tone1.play(notas[botoes[j]-30]);
    flag1=1;
    nota1=botoes[j];
    }

    else if(flag2==0 && flag1==1 || flag3==0){
      tone2.play(notas[botoes[j]-30]);
      flag2=1;
      nota2=botoes[j];
    }
    else if(flag3==0 && flag2==2 || flag1==1 ){
      tone3.play(notas[botoes[j]-30]);
      flag3=1;
      nota3=botoes[j];
    }
    else if(flag4==0 && flag2==2 || flag1==1 || flag3==0){
      tone4.play(notas[botoes[j]-30]);
      flag4=1;
      nota4=botoes[j];
    }
    
    
  }
 }


 if(indice==0){
 tone1.stop();
 tone2.stop();
 tone3.stop();
 tone4.stop();
 flag1=0;
 flag2=0;
 flag3=0;
 flag4=0;
 for(int g=0;g<4;g++){
  botoes[g]=0;
 }
 }
 
 //Condicional de para nenhum botao apertado
 if(digitalRead(nota1)==LOW){
  tone1.stop();
  flag1=0;
 }
  if(digitalRead(nota2)==LOW){
  tone2.stop();
  flag2=0;
 }
  if(digitalRead(nota3)==LOW){
  tone3.stop();
  flag3=0;
 }
  if(digitalRead(nota4)==LOW){
  tone4.stop();
  flag4=0;
 }

 
}
