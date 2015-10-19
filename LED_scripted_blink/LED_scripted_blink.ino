
int animation[] = {15, 240, 15, 240, 15, 240, 15, 240, 204, 51, 204, 51, 204, 51, 204, 51, 170, 85, 170, 85, 170, 85, 170, 85,2,4,8,16,32,64,128,64,32,16,8,4,2};
void setup() {
  Serial.begin(9600);
  int y = 5;
  while (y < 13) {
    // initialize digital pin 13 as an output.
    pinMode(y, OUTPUT);
    y++;
  }

  
}


int offset = 5;
int decimal = 64;

int index = 0;

void loop()
{


  int leddisplay[] = {0, 0, 0, 0, 0, 0, 0, 0};

  getmod(leddisplay, animation[index]);

  for (int thisPin = 0; thisPin < 8; thisPin++) {
    // turn the pin on:

    digitalWrite( (thisPin + offset) , leddisplay[thisPin]);
  }




  index++;

  if (index > 36) {
    index = 0;
  }
  delay(300);


}

void getmod(int pdata[], int pdecimal)
{

  if (pdecimal >= 128) {
    pdata[0] = 1;
  }
  pdecimal = pdecimal % 128;

  if (pdecimal >= 64) {
    pdata[1] = 1;
  }
  pdecimal = pdecimal % 64;

  if (pdecimal >= 32) {
    pdata[2] = 1;
  }
  pdecimal = pdecimal % 32;

  if (pdecimal >= 16) {
    pdata[3] = 1;
  }
  pdecimal = pdecimal % 16;

  if (pdecimal >= 8) {
    pdata[4] = 1;
  }
  pdecimal = pdecimal % 8;

  if (pdecimal >= 4) {
    pdata[5] = 1;
  }
  pdecimal = pdecimal % 4;

  if (pdecimal >= 2) {
    pdata[6] = 1;
  }
  pdecimal = pdecimal % 2;

  if (pdecimal >= 1) {
    pdata[7] = 1;
  }

}

