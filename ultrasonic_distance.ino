
const int trigPin = 13;
const int echoPin = 12;
const int white = 8;
const int green = 9;
const int yellow = 10;
const int red = 11;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(white, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  Serial.begin(9600);
}


void loop() {
  digitalWrite(white, HIGH);
  float distance = getDistance();
  lightIndicators(distance);
  Serial.print("Distance: ");
  Serial.println(distance);
  delay(100);
}

void lightIndicators(float distance) {
  if (distance < 20) {
    digitalWrite(red, HIGH);
  } else {
    digitalWrite(red, LOW);
  }
  if (distance < 50) {
    digitalWrite(yellow, HIGH);
  } else {
    digitalWrite(yellow, LOW);
  }

  if (distance < 80) {
    digitalWrite(green, HIGH);
  } else {
    digitalWrite(green, LOW);
  }
}

float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  float duration = pulseIn(echoPin, HIGH);
  return (duration*.0343)/2;
}
