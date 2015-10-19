
int animation[256];
void setup() {
  Serial.begin(9600);
  int y = 5;
  while(y<13){
  // initialize digital pin 13 as an output.
  pinMode(y, OUTPUT);
  y++;
  }

  for (int i = 0; i <= 255; i++){
    animation[i] = i;
  }

}

int offset = 5;
int decimal = 64;

int index = 0;

void loop()
{

  
int leddisplay[] = {0,0,0,0,0,0,0,0};

getmod(leddisplay,animation[index]);

for (int thisPin = 0; thisPin < 8; thisPin++) {
    // turn the pin on:
    
    digitalWrite( (thisPin + offset) , leddisplay[thisPin]);
}

  


index++;

if (index > 255){ index = 0; }
delay(100);


}

void getmod(int pdata[],int pdecimal)
{

  if (pdecimal >= 128){ pdata[0]=1; }
  pdecimal = pdecimal % 128;
  
    if (pdecimal >= 64){ pdata[1]=1; }
  pdecimal = pdecimal % 64;
  
    if (pdecimal >= 32){ pdata[2]=1; }
  pdecimal = pdecimal % 32;
  
    if (pdecimal >= 16){ pdata[3]=1; }
  pdecimal = pdecimal % 8;
  
    if (pdecimal >= 128){ pdata[4]=1; }
  pdecimal = pdecimal % 8;
  
    if (pdecimal >= 4){ pdata[5]=1; }
  pdecimal = pdecimal % 4;
  
    if (pdecimal >= 2){ pdata[6]=1; }
  pdecimal = pdecimal % 2;
  
    if (pdecimal >= 1){ pdata[7]=1; }
 
}

