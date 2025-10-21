#DEFINE nivelMax 2
#DEFINE qtdMax 2
int m1_1 = 2;
int m1_2 = 3;
int m1_3 = 4;
int m1_4 = 5;
int m2_1 = 6;
int m2_2 = 7;
int m2_3 = 8;
int m2_4 = 9;
int m3_1 = 10;
int m3_2 = 11;
int m3_3 = 12;
int m3_4 = 13;
int x = 0;
int y = 0;
int z = 0;
int fc = A0;
int posI = A1;
int nivel = 0;
int qtd = 0;
int coordenadas[3][3][3] = { //   [x,y,z]  [nivel]  [qtd]
  {
    {0, 0, 0},
    {0, 0, 0},         // x
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},         // y      
    {0, 0, 0}
  },
  {
    {0, 0, 0},
    {0, 0, 0},         // z
    {0, 0, 0}
  }
};
int lPeca[3] = {0,0,0} // {x,y,z}
void setup() {

  pinMode(posI,INPUT);
  pinMode(fc,INPUT);
  pinMode(m1_1,OUTPUT);
  pinMode(m1_2,OUTPUT);
  pinMode(m1_3,OUTPUT);
  pinMode(m1_4,OUTPUT);
  pinMode(m2_1,OUTPUT);
  pinMode(m2_2,OUTPUT);
  pinMode(m2_3,OUTPUT);
  pinMode(m2_4,OUTPUT);
  pinMode(m3_1,OUTPUT);
  pinMode(m3_2,OUTPUT);
  pinMode(m3_3,OUTPUT);
  pinMode(m3_4,OUTPUT);

}

void loop() {

  if (analogRead(fc)>10){

    posicionar(lPeca[0],lPeca[1],lPeca[2]);
    posicionar(
              coordenadas[0][nivel][qtd],
              coordenadas[1][nivel][qtd],
              coordenadas[2][nivel][qtd]
              );
      
    calcularPos();
    
  }
 
}
 
 void passo_horario(int m) {
  ativaBobinas(1, 0, 0, 0, m);
  delay(5);
  ativaBobinas(0, 1, 0, 0, m);
  delay(5);
  ativaBobinas(0, 0, 1, 0, m);
  delay(5);
  ativaBobinas(0, 0, 0, 1, m);
  delay(5);
}

void passo_antihorario(int m) {
  ativaBobinas(0, 0, 0, 1, m);
  delay(5);
  ativaBobinas(0, 0, 1, 0, m);
  delay(5);
  ativaBobinas(0, 1, 0, 0, m);
  delay(5);
  ativaBobinas(1, 0, 0, 0, m);
  delay(5);
}

void ativaBobinas(int a, int b, int c, int d, int m) {
  
  switch(m){
    case 1:
      digitalWrite(m1_1, a);
      digitalWrite(m1_2, b);
      digitalWrite(m1_3, c);
      digitalWrite(m1_4, d);
      break;
    case 2:
      digitalWrite(m2_1, a);
      digitalWrite(m2_2, b);
      digitalWrite(m2_3, c);
      digitalWrite(m2_4, d);
      break;
    case 3:
      digitalWrite(m3_1, a);
      digitalWrite(m3_2, b);
      digitalWrite(m3_3, c);
      digitalWrite(m3_4, d);
  }
  
}

void calcularPos(){

    if(qtd=qtdMax){
      qtd = 0;      
      if (nivel<nivelMax){   
        nivel++;
      }
      else{
        nivel = 0;    
      }    
    }
    else{
      qtd++;
    }
  
}

void posicionar(int i, int j, int k){

  i = i - x;
  j = j - y;
  k = k - z;

  for (int n=1;1;){
    
    n = 0;
    
    if (i<0){
      passo_antihorario(1);
      x--;
      n = 1;
    }
    
    if (j<0){
      passo_antihorario(2);
      y--;
      n = 1;
    }
    
    if (k<0){
      passo_antihorario(3);
      z--;
      n = 1;
    }
    
    if (i>0){
      passo_horario(1);
      x++;
      n = 1;
    }
    
    if (j>0){
      passo_horario(2);
      y++;
      n = 1;
    }
    
    if (k>0){
      passo_horario(3);
      z++;
      n = 1;
    }
    
  }

}
