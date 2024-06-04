String inputString = "";
bool stringComplete = false;
//bool exit = 0;
bool last_command = 0;
unsigned long t_alive = 0;


void serialEvent()
{
  if (Serial.available() > 0)
  {
    char inChar = (char)Serial.read(); // get the new byte:
    inputString += inChar;             // add it to the inputString:
    if (inChar == '\n')
    { // if the incoming character is a newline, set a flag so the main loop cando something about it:
      stringComplete = true;
    }
  }
}


void confronta_stringhe()
{
  stringComplete = false;

  String confronto = String(inputString);
  //Serial.println(confronto);

  /*if (confronto.equals("SERIALE1\n") == 1)
  {
    //  ASCOLTA E SCRIVI IN SERIALE 1
    seriale_1();

  } else if (confronto.equals("SERIALE2\n") == 1)
  {
    //  ASCOLTA E SCRIVI IN SERIALE 2
    seriale_2();

  } else {
    Serial.println("");
    Serial.println(" Digitare i comandi: 'SERIALE1' , 'SERIALE2' ");
    Serial.println("");
  }*/

  if ( (confronto.equals("1\n") == 1) || (confronto.equals("2\n") == 1) || (confronto.equals("3\n") == 1) || (confronto.equals("4\n") == 1) || (confronto.equals("5\n") == 1) || (confronto.equals("6\n") == 1) || (confronto.equals("7\n") == 1) || (confronto.equals("8\n") == 1) || (confronto.equals("9\n") == 1) || (confronto.equals("10\n") == 1) )
  {
    //Serial.println("SERIALE1");
    Serial1.println("");
    Serial1.print(confronto);
    last_command = 0;
  }
  else if ( (confronto.equals("11\n") == 1) || (confronto.equals("12\n") == 1) || (confronto.equals("13\n") == 1) )
  {
    //Serial.println("SERIALE2");
    Serial2.println("");
    Serial2.print(confronto);
    last_command = 1;
  }
  else if ( (confronto.equals("98\n") == 1) || (confronto.equals("99\n") == 1) )
  {
    Serial2.print(confronto);
    Serial1.print(confronto);
    /*if (last_command)
    {
      //Serial.println("SERIALE2");
      //Serial2.println("");
      Serial2.print(confronto);
    }
    else
    {
      //Serial.println("SERIALE1");
      //Serial1.println("");
      Serial1.print(confronto);
    }*/
  }
  else
  {
    Serial.println("COMANDO ERRATO:");
    Serial.println(confronto);
    Serial.println(".");
  }


  inputString = ""; // clear the string:
  stringComplete = false;
}


/*bool isValidMessage(String message) {
  for (unsigned int i = 0; i < message.length(); i++) {
    char c = message.charAt(i);
    if (!isPrintable(c)) {
      return false; // Contains special character, not a valid message
    }
  }
  return true; // No special characters found, valid message
}*/


bool isPrintable(char c) {
  // Check if character is printable and not a special character
  // ASCII values 32 (space) to 126 (~) are printable characters
  return (c >= 32 && c <= 126);
}


//  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


void setup() {
  // Start the main hardware serial port for communication with the PC
  Serial.begin(9600);
  // Start Serial1 for communication with the other board
  Serial1.begin(9600);  //  2560
  // Start Serial2 for communication with the other board
  Serial2.begin(9600);  //  644

  inputString.reserve(200); // reserve 200 bytes for the inputString

  Serial.println("");
  Serial.println("[SETUP] In attesa...");
  Serial.println("");

  t_alive = millis();
}


void loop() {

  //  --------------------------------------------------------------------------------------------

  //  WRITE TO THE BOARDS

  serialEvent();
  if (stringComplete)
  {
    confronta_stringhe();

    //Serial.println("");
    //Serial.println("...");
    return;
  }

  //  --------------------------------------------------------------------------------------------

  //  READ FROM THE BOARDS

  // Read data from the other board and send it to the PC 2560
  if (Serial1.available()) {
    char data = Serial1.read();
    if (isPrintable(data)) Serial.write(data);
    if (data == '\n') Serial.write(data);
  }

  // Read data from the other board and send it to the PC 644
  if (Serial2.available()) {
    char data = Serial2.read();
    if (isPrintable(data)) Serial.write(data);
    if (data == '\n') Serial.write(data);
  }

  //  --------------------------------------------------------------------------------------------

  //  ALIVE

  /*if ((millis() - t_alive) > 2000) {
    Serial.println("alive");
    t_alive = millis();
  }*/

  /*

  //  --------------------------------------------------------------------------

  // Read data from the other board and send it to the PC 2560
  if (Serial1.available()) {
    char data = Serial1.read();
    Serial.write(data);
  }

  // Optionally, send data from the PC to the other board 2560
  if (Serial.available()) {
    char data = Serial.read();
    Serial1.write(data);
  }

  //  ---------------------------------------------------------------------------

  // Read data from the other board and send it to the PC 644
  if (Serial2.available()) {
    char data = Serial2.read();
    Serial.write(data);
  }

  // Optionally, send data from the PC to the other board 644
  if (Serial.available()) {
    char data = Serial.read();
    Serial2.write(data);
  }

  */

}


//  *-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*


//  FUNZIONI DI TEST PER SCEGLIERE UNA SERIALE E LEGGERNE UNA ALLA VOLTA


void seriale_1();
void seriale_2();


void seriale_1() {
  bool exit = 0;
  while(!exit) {
    
    // Read data from the other board and send it to the PC 2560
    if (Serial1.available() > 0)
    {
      char inChar = (char)Serial1.read(); // get the new byte:
      inputString += inChar;             // add it to the inputString:
      if (inChar == '\n')
      {
        /*char data = Serial1.read();
        Serial.write(data);*/
        String confronto = String(inputString);
        Serial.println(confronto);
        inputString = ""; // clear the string:
      }
    }

    // Optionally, send data from the PC to the other board 2560
    if (Serial.available() > 0)
    {
      char inChar = (char)Serial.read(); // get the new byte:
      inputString += inChar;             // add it to the inputString:
      if (inChar == '\n')
      {
        String confronto = String(inputString);
        Serial.println(confronto);
        if (confronto.equals("EXIT\n") == 1) {
          exit = 1;
        } else {
          /*char data = Serial.read();
          Serial1.write(data);*/
          String confronto = String(inputString);
          Serial1.println(confronto);
          inputString = ""; // clear the string:
        }
      }
    }
    

    /*
    // Read data from the other board and send it to the PC 2560
    if (Serial1.available()) {
      char data = Serial1.read();
      Serial.write(data);
    }

    // Optionally, send data from the PC to the other board 2560
    if (Serial.available()) {
      char data = Serial.read();
      //Serial1.write(data);
      if (data == 'x') exit = 1; else Serial1.write(data);
    }
    */

  }
  exit = 0;

}


void seriale_2() {
  bool exit = 0;
  while(!exit) {
    
    // Read data from the other board and send it to the PC 2560
    if (Serial2.available() > 0)
    {
      char inChar = (char)Serial2.read(); // get the new byte:
      inputString += inChar;             // add it to the inputString:
      if (inChar == '\n')
      {
        /*char data = Serial2.read();
        Serial.write(data);*/
        String confronto = String(inputString);
        Serial.println(confronto);
        inputString = ""; // clear the string:
      }
    }

    // Optionally, send data from the PC to the other board 2560
    if (Serial.available() > 0)
    {
      char inChar = (char)Serial.read(); // get the new byte:
      inputString += inChar;             // add it to the inputString:
      if (inChar == '\n')
      {
        String confronto = String(inputString);
        Serial.println(confronto);
        if (confronto.equals("EXIT\n") == 1) {
          exit = 1;
        } else {
          /*char data = Serial.read();
          Serial2.write(data);*/
          String confronto = String(inputString);
          Serial2.println(confronto);
          inputString = ""; // clear the string:
        }
      }
    }
    

    /*
    // Read data from the other board and send it to the PC 644
    if (Serial2.available()) {
      char data = Serial2.read();
      Serial.write(data);
    }

    // Optionally, send data from the PC to the other board 644
    if (Serial.available()) {
      char data = Serial.read();
      if (data == 'x') exit = 1; else Serial2.write(data);
    }
    */

  }
  exit = 0;

}
