void setup() {
  // put your setup code here, to run once:
  for(int pin=2;pin<=7;pin++){
    pinMode(pin, OUTPUT);
    if(pin>=4){
      digitalWrite(pin, LOW);
    }else{
      digitalWrite(pin, HIGH);
    }
  }
}
int anode[3] = {2, 3, 4};
int cathode[3] = {5, 6, 7};
boolean data[][3][3] = {
  {
    {0, 1, 0},
    {0, 1, 0},
    {0, 1, 0}
  },
  {
    {0, 0, 1},
    {0, 1, 0},
    {1, 0, 0}
  },
  {
    {0, 0, 0},
    {1, 1, 1},
    {0, 0, 0}
  },
  {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1}
  },
};

void loop() {
  // put your main code here, to run repeatedly:
  for(int phase=0;phase<4;phase++){
    for(int delay_keep=0;delay_keep<50;delay_keep++){
      display(data[phase]);
      delay(1);
    }
  }
}

void display(boolean matrix[][3]){
  for(int x=0; x<3; x++){
    for(int y=0; y<3; y++){
      digitalWrite(anode[y], matrix[x][y]);
      digitalWrite(cathode[x], !matrix[x][y]);
      delay(1);
      digitalWrite(anode[y], LOW);
      digitalWrite(cathode[x], HIGH);
    }
  }
}
