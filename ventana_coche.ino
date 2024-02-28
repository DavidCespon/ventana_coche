// Definir los pines de entrada y salida
const int pinEntrada = 12;
const int pinSalida1 = 8;
const int pinSalida2 = 7;

// Variable para almacenar el estado de la entrada
int estadoEntradaAnterior = LOW;
// Variable para controlar qué salida está activa
int salidaActiva = 0;
// Variable pra controlar el tiempo de las salidas activas 
int contadortiempo = 7000;
void setup() {
  // Inicializar los pines
  pinMode(pinEntrada, INPUT);
  pinMode(pinSalida1, OUTPUT);
  pinMode(pinSalida2, OUTPUT);
}

void loop() {
  // Leer el estado actual de la entrada
  int estadoEntrada = digitalRead(pinEntrada);
  // Contar el tiempo para desactivar las salidas
  if (contadortiempo>=7000){
    digitalWrite(pinSalida2, LOW);
    digitalWrite(pinSalida1, LOW);
  }
  else contadortiempo=contadortiempo+10;
  
  // Si la entrada ha cambiado de LOW a HIGH (activada)
  if (estadoEntrada == HIGH && estadoEntradaAnterior == LOW) {
    // Cambiar el estado de las salidas según la salida activa actual
    if (salidaActiva == 0) {
      digitalWrite(pinSalida1, HIGH);
      digitalWrite(pinSalida2, LOW);
      salidaActiva = 1;
    } else {
      digitalWrite(pinSalida1, LOW);
      digitalWrite(pinSalida2, HIGH);
      salidaActiva = 0;
    }
    contadortiempo = 0; 
  }
  delay (10); 
  // Actualizar el estado anterior de la entrada
  estadoEntradaAnterior = estadoEntrada;
}
