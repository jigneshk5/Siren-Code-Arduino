/*This is my Arduino project on making diffent Siren Sound with their LED scnc/transitions. You can get the this code from my Github 
 * repository named "Siren", You can watch its working on my Youtube Channel and the complete tutorial is explained in my Aruino Create account
 * named coding_killer. Now it's your turn to make some cool tone using my Project and explore all the possibilities.
 */
boolean lastbutton=LOW;
boolean currentbutton=LOW;
int input=0;
int buzz=13; // Buzzer Pin
int j=3;
int k=12;
void setup() {
for(int i=3;i<=12;i++)
pinMode(i,OUTPUT);
pinMode(2,INPUT);
}
boolean debounce(boolean last){                 //Function to solve the problem of button debouncing
  boolean current=digitalRead(2);
  if(last!=current)
  {
    delay(5);
    current=digitalRead(2);
    }
  return current;
  }
void loop() {
  for(int i=3;i<=12;i++)
  digitalWrite(i,LOW);
  currentbutton=debounce(lastbutton);
  if(lastbutton==LOW && currentbutton==HIGH)
  {
  input++;
  }
  lastbutton=currentbutton;
  settone(input);
}

void settone(int input)
{

if(input==1) 
one();
else if(input==2)
oneA();
else if(input==3)
two();
else if(input==4)
twoA();
else if(input==5)
three();
else if(input==6)
threeA();
else if(input==7)
four();
}

void one() {         //This function produces the 1st siren sound with ON/OFF led transition.
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
    for(int i=3;i<=7;i++)
    digitalWrite(i,HIGH);
  }
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
    for(int i=3;i<=7;i++)
    {
      digitalWrite(i,LOW);
      digitalWrite(i+5,HIGH);
      }
  }
  }
  
void oneA() {                //This function produces differnt transition on 1st siren.
  
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  if(j>=3){
    digitalWrite(j,HIGH);
    j=j+1;
    digitalWrite(k,HIGH);
    k=k-1;
    if(j==8)
    j=3;
    if(k==7)
    k=12;
    }  
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  }
void two() {                   //This function produces the 2nd siren sound with progressive led transition.
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
     loopF(3,12,20);
     loopR(12,3,20);
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  }
void twoA() {                  //This function produces differnt transition on 2nd siren.
  // Whoop up
  for(int hz = 440; hz < 1000; hz+=25){
    tone(buzz, hz, 50);
    delay(5);
  }
     loopF(3,k,20);
     loopR(12,j,20);
     k--;
     if(k==3)
     k=12;
     j++;
     if(j==12)
     j=3;
  // Whoop down
  for(int hz = 1000; hz > 440; hz-=25){
    tone(buzz, hz, 50);
    delay(5);
  }
  }
  void three() {              //This function produces the 3rd siren(AMBULANCE) sound with led transition.
  tone(buzz,440,200);
    delay(300);
  for(int i=3;i<=6;i++)
  digitalWrite(i,HIGH);
  noTone(buzz);
  tone(buzz,494,500);
  delay(300);
  for(int i=3;i<=6;i++){
  digitalWrite(i,LOW);
  digitalWrite(i+6,HIGH);
  }
  noTone(buzz);
  tone(buzz,523,300);
   delay(200);
  digitalWrite(7,HIGH);
  delay(50);
  digitalWrite(8,HIGH);
  delay(50);
  noTone(buzz);
}
  void threeA() {              //This function produces differnt transition on 3rd siren.
  tone(buzz,440,200);
    delay(100);
    loopF(5,10,20);
    loopR(10,5,20);
  noTone(buzz);
  for(int i=3;i<=4;i++){
  digitalWrite(i,HIGH);
  digitalWrite(i+8,HIGH);}
  tone(buzz,494,500);
  delay(300);
  noTone(buzz);
  for(int i=3;i<=4;i++){
  digitalWrite(i,LOW);
  digitalWrite(i+8,LOW);
  }
  tone(buzz,523,300);
   delay(300);
  noTone(buzz);
}
void four() {                             //This function produces the 4th siren(POLICE) sound with led transition.
for(int i=3;i<=11;i+=2)
digitalWrite(i,HIGH);
  for(int hz = 440; hz < 1000; hz++){
    tone(buzz, hz, 50);
    delay(5);
  }
for(int i=3;i<=11;i+=2)
digitalWrite(i,LOW);
 for(int i=4;i<=12;i+=2)
digitalWrite(i,HIGH);
  for(int hz = 1000; hz > 440; hz--){
    tone(buzz, hz, 50);
    delay(5);
    }
  }
  // SOME EXTRA FUNCTIONS OTHER THAN THE SIREN TONES
    void loopF(int spin,int epin,int dela){    //loopF can blink the led in forward direction so spin must be lower than epin.
    for(int i=spin;i<=epin;i++){
    digitalWrite(i,HIGH);
    delay(dela);
    low();
    if(spin==epin){
    spin=3;
    epin=12;}
    }}
  void loopR(int epin,int spin,int dela){      //loopR can blink the led in reverse/backward direction so epin must be lower than spin.
    for(int i=epin;i>=spin;i--){
    digitalWrite(i,HIGH);
    delay(dela);
    low();
    if(spin==epin){
    spin=3;
    epin=12;}
    }}
  void low(){                                  //Used by loopF and loopR
   for(int i=3;i<=12;i++)
  digitalWrite(i,LOW);
    }
