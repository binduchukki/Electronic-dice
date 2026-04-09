int segPins[] = {2,3,4,5,6,7,8}; // a,b,c,d,e,f,g
int buttonPin = 9;
int buzzerPin = 10;

// Numbers 1 to 6 (Common Cathode)
byte diceNumbers[6][7] = {
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}  // 6
};

void setup() {
  for(int i=0; i<7; i++){
    pinMode(segPins[i], OUTPUT);
  }
  
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  randomSeed(analogRead(0)); // better randomness
}

void loop() {
  if(digitalRead(buttonPin) == LOW) {
    
    // Dice rolling effect
    for(int i=0; i<10; i++){
      int temp = random(0,6);
      displayNumber(temp);
      tone(buzzerPin, 1000);
      delay(100);
      noTone(buzzerPin);
      delay(100);
    }

    // Final dice value
    int diceValue = random(0,6);
    displayNumber(diceValue);

    Serial.print("Dice Value: ");
    Serial.println(diceValue + 1);

    // Final beep
    tone(buzzerPin, 1500);
    delay(300);
    noTone(buzzerPin);

    delay(500); // debounce
  }
}

// Function to display number
void displayNumber(int num) {
  for(int i=0; i<7; i++){
    digitalWrite(segPins[i], diceNumbers[num][i]);
  }
}
