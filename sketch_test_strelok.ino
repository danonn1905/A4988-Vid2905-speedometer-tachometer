/*
тест стрелок
*/
const int dirPin = 12;//подключите 12 пин к dir
const int stepPin = 13;//подключите 13 пин к step
const int stepsPerRevolution = 500;//кол-во шагов
const int pribPin = 3;//питание приборной панели
const int enPin = 9;// Включение сна драйвера
void setup()
{
pinMode(stepPin, OUTPUT);
pinMode(dirPin, OUTPUT);
pinMode(pribPin, OUTPUT);
pinMode(enPin, OUTPUT);
{
}
digitalWrite(dirPin, HIGH); // Установка вращения по часовой стрелки
for (int x = 0; x < stepsPerRevolution; x++)
{
digitalWrite(stepPin, HIGH);
delayMicroseconds(1450);
digitalWrite(stepPin, LOW);
delayMicroseconds(25);
delay(1);
}
digitalWrite(dirPin, LOW); // Установка вращения против часовой стрелки
for (int x = 0; x < stepsPerRevolution; x++)
{
digitalWrite(stepPin, HIGH);
delayMicroseconds(1450);
digitalWrite(stepPin, LOW);
delayMicroseconds(25);
}
delay(10);
}
void loop()
{
digitalWrite(enPin, HIGH); // Включение сна драйвера
delay(10);

delay(10);
digitalWrite(pribPin, LOW); // Выключение питания приборки
}
