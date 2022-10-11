<<<<<<< HEAD
/*********************************
*             Motor              * Nombre de la clase
**********************************
*  - default_speed : int         *
*  - pin_dir: int                *
*  - pin_pwm: int                * Atributos
*  - speed: int                  *
*  - invert: bool                *
**********************************
*  + stop() : void               *
*  + backward() : void           *
*  + forward() : void            * Metodos o Acciones.
*  + invertDirection() : void    *
*  + setSpeed(int speed) : void  *
**********************************/

class Motor
{
private:
    /***************** Atributos ************************/
    int default_speed = 100;
    int pin_dir, pin_pwm, speed;
    bool invert;

public:
    /**************** Metodo constructor *****************/
    Motor(int pdir, int ppwm)
    {
        //seteo los pines de direccion y pwm.
        pin_dir = pdir;
        pin_pwm = ppwm;
        //defino los pines de direccion y pwm como salida.
        pinMode(pin_dir, OUTPUT);
        pinMode(pin_pwm, OUTPUT);
        //seteo la velocidad
        speed = default_speed;
    }
    /**************** Metodos o Acciones *****************/
    void setSpeed(int s)
    {
        if (s >= 100)
        {
            //si la veloidad es mayor a 100, seteo la velocidad a 100.
            s = 100;
        }
        else if (s <= 0)
        {
            //si la veloidad es menor a 0, seteo la velocidad a 0.
            s = 0;
        }

        int value = (int)s * 255 / 100;
        speed = value;
    }

    void forward() //Voy hacia adelante.
    {

        //seteo la direccion hacia adelante.
        //NOTA: Utilizo el FLAG invertir, para que el motor se mueva en el sentido contrario.
        //Ya que fisicamente  el motor se encuentra invertido por lo tanto, el motor va hacia atras.
        //De esta forma resolvemos el problema de que el motor se mueva en el sentido contrario.
        digitalWrite(pin_dir, invert);
        //seteo la velocidad.
        analogWrite(pin_pwm, speed);
    }

    void backward() //Voy hacia atras.
    {
        //seteo la direccion hacia atras.
        //NOTA: Utilizo el FLAG invertir, para que el motor se mueva en el sentido contrario.
        //Ya que fisicamente  el motor se encuentra invertido por lo tanto, el motor va hacia adelante.
        //De esta forma resolvemos el problema de que el motor se mueva en el sentido contrario.
        digitalWrite(pin_dir, !invert);
        //seteo la velocidad.
        analogWrite(pin_pwm, speed);
    }

    void invertDirection()
    {
        //cambio el valor del flag invertir.
        invert = !invert;
    }

    void stop() //Freno
    {
        //seteo la velocidad a 0 para frenar el motor.
        digitalWrite(pin_dir, LOW);
        analogWrite(pin_pwm, 0);
    }
};

//Defino los pines de los motores.
#define PIN_MOTOR_DERECHO_DIR 4
#define PIN_MOTOR_DERECHO_PWM 5
#define PIN_MOTOR_IZQUIERDO_DIR 6
#define PIN_MOTOR_IZQUIERDO_PWM 7

//Instancio los motores
Motor m1 = Motor(PIN_MOTOR_DERECHO_DIR, PIN_MOTOR_DERECHO_PWM);
Motor m2 = Motor(PIN_MOTOR_IZQUIERDO_DIR, PIN_MOTOR_IZQUIERDO_PWM);


void setup()
{
    
}

void loop()
{
  
=======
class Pulsador {
  private:
    int pin;
    bool flanco = HIGH;
    bool estado_anterior = !flanco;

    //metodo
  public:
    Pulsador(int p) {
      pin = p;

      pinMode(pin, INPUT);
    }

    void setFlanco(bool f) {
      flanco = f;
      estado_anterior = !flanco;
    }

    //metodos o acciones
    bool getIsPress() {
      bool estado_actual = digitalRead(pin);
      bool estado = (estado_anterior != estado_actual) && estado_actual == flanco;
      estado_anterior = estado_actual;
      return estado;
    }

    String getIsPressText() {
      if (getIsPress()) return "PRESS";
      else return "IS NOT PRESS";
    }
};

Pulsador *p1 = new Pulsador(PIN_PULSADOR_1);

int contador = 0;
void setup() {

}

void loop() {

>>>>>>> c969a206b557aee4b55ac1ac1a4ff9b6371e86d9
}
