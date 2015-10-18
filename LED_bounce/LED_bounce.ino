void setup() {
  Serial.begin(9600);
  int y = 5;
  while(y<13){
  // initialize digital pin 13 as an output.
  pinMode(y, OUTPUT);
  y++;
  }


}
int offset = 5;
int leds = 8;
float width = 100.0;
float direction = 2.0;
float delta = (leds-1) / width;
float x = 0.0;
float size  = 0;

void loop() {
  

  
  int active = round(x * delta);
  
  

  for ( int i = 0; i < leds; i++ ) {
     int led = i + offset;
    if (i == active) {
      digitalWrite(led, HIGH);
      Serial.println("High");
    } 
    else if (abs(active - i) <= size){
      digitalWrite(led, HIGH);
      Serial.println("High");
  }
    
    else {
      digitalWrite(led, LOW);
      Serial.println(led);
    }
    
    
  }
  
  x = x + direction;
  if (x >= width) direction = -direction;
  if (x <= 0) direction = -direction;
  delay(10);
  
}


