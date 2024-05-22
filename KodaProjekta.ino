int rdeca = 13;
int zelena = 12;
int tipkaGOR = 9;
int tipkaSTOP=8;
int tipkaDOL=7;
int elektromagnetni_ventil1 = 2;
int elektromagnetni_ventil2 = 3;
int vrednost = 0;
bool GOR = false;
bool DOL = false;
bool stop = true;

void setup() {
  Serial.begin(9600);
  pinMode(rdeca, OUTPUT);
  pinMode(zelena, OUTPUT);
  pinMode(elektromagnetni_ventil1, OUTPUT);
  pinMode(elektromagnetni_ventil2, OUTPUT);
  pinMode(tipkaGOR, INPUT);
  pinMode(tipkaSTOP, INPUT);
  pinMode(tipkaDOL, INPUT);  
}

void loop() {

  if(digitalRead(tipkaGOR) == HIGH){
    stop = true;
  }
  if(digitalRead(tipkaDOL) == HIGH){
    stop = true;
  }
  if(digitalRead(tipkaSTOP) == HIGH){
    stop = false;
    digitalWrite(elektromagnetni_ventil2, LOW);
    digitalWrite(elektromagnetni_ventil1, LOW);
    digitalWrite(zelena, LOW);
    digitalWrite(rdeca, LOW);
  }

  if(stop == true && digitalRead(tipkaGOR) == HIGH || GOR == true){
    DOL = false;
    GOR = true;
    digitalWrite(elektromagnetni_ventil2, LOW);
    digitalWrite(rdeca, LOW);
    digitalWrite(zelena, HIGH);
    if(stop == false){
      digitalWrite(elektromagnetni_ventil2, LOW);
      digitalWrite(elektromagnetni_ventil1, LOW);
      digitalWrite(zelena, LOW);
      digitalWrite(rdeca, LOW);
      DOL = false;
      GOR = false;
    }
    else if(vrednost < 30 && stop == true){
        digitalWrite(elektromagnetni_ventil1, HIGH);
        delay(100);
        vrednost++;
        Serial.print("GOR: ");
        Serial.println(vrednost);
    }
    else{
      digitalWrite(elektromagnetni_ventil1, LOW);
      GOR = false;
      DOL = false;
    }
  }
  if(stop == true && digitalRead(tipkaDOL) == HIGH || DOL == true){
    GOR = false;
    DOL = true;
    digitalWrite(elektromagnetni_ventil1, LOW);
    digitalWrite(zelena, LOW);
    digitalWrite(rdeca, HIGH);
    if(stop == false){
      digitalWrite(elektromagnetni_ventil2, LOW);
      digitalWrite(elektromagnetni_ventil1, LOW);
      digitalWrite(zelena, LOW);
      digitalWrite(rdeca, LOW);
      DOL = false;
      GOR = false;
    }
    else if(vrednost > 0 && stop == true){
      digitalWrite(elektromagnetni_ventil2,HIGH);
      delay(100);
      vrednost--;
      Serial.print("GOR: ");
      Serial.println(vrednost);
    }
    else{
      digitalWrite(elektromagnetni_ventil2, LOW);
      DOL = false;
      GOR = false;
    }
  }
}