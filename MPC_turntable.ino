#include <Keypad.h> 
#include <LedControl.h>
#include <LiquidCrystal_I2C.h>

/* Define every musical note */
#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978
#define REST      0

/* Define keyboard */
const byte ROWS = 4; 
const byte COLS = 4; 
  
char hexaKeys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};
  
byte colPins[ROWS] = {5, 4, 3, 2}; 
byte rowPins[COLS] = {9, 8, 7, 6}; 

Keypad customKeypad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, ROWS, COLS); 
/* End of keyboard definition*/


/* LCD Display definition */
LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
/* End of LCD Display definition /*


/* Buzzer definition */
int BUZZER_PIN = 13;

/* The matrix led definition */
int DIN = 12;
int CS = 11;
int CLK = 10;

LedControl lc = LedControl(DIN, CLK, CS, 0);
/* End of matrix led definition */

int game_of_thrones_melody[] = {
  // Game of Thrones
  NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, //1
  NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_DS4,16, NOTE_F4,16,
  NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
  NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16, NOTE_G4,8, NOTE_C4,8, NOTE_E4,16, NOTE_F4,16,
  NOTE_G4,-4, NOTE_C4,-4,//5

  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
  NOTE_D4,-1, //7 and 8
  NOTE_F4,-4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12

  //repeats from 5
  NOTE_G4,-4, NOTE_C4,-4,//5

  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4, NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16, //6
  NOTE_D4,-1, //7 and 8
  NOTE_F4,-4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_F4,4, NOTE_AS3,-4,
  NOTE_DS4,16, NOTE_D4,16, NOTE_C4,-1, //11 and 12
  NOTE_G4,-4, NOTE_C4,-4,
  NOTE_DS4,16, NOTE_F4,16, NOTE_G4,4,  NOTE_C4,4, NOTE_DS4,16, NOTE_F4,16,
};

int imperial_march_melody[] = {
  // Darth Vader theme (Imperial March) - Star wars 
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8,
  NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16,

  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,//4
  NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16,
  NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,
  
  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,

  NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16,//9
  NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2,

  NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, //7 
  NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16,
};


/* Define is playing flag */
int IS_PLAYING[] = {0, 0, 0};
int *CURRENT_SONG;
int CURRENT_NOTES = 0;
/* Define the index of the current song played */
int CURRENT_SONG_INDEX = 0;
int currentNote = 0;

/* Define the speaker pins */
#define NO_OF_SPEAKERS 3
int VOLUME = 1;
int BPM = 35;
int SHOWBPM = 35;
int LOOPMODE = 0;
int LOOPNOTE = -1;
int LOOPTIME = 0;
int speakPins[NO_OF_SPEAKERS] = {A0, A1, A2};
/* Define number of notes for every theme */
int game_of_thrones_notes = sizeof(game_of_thrones_melody) / sizeof(game_of_thrones_melody[0]) / 2;
int imperial_march_notes = sizeof(imperial_march_melody) / sizeof(imperial_march_melody[0]) / 2;
/* Change this to make the song slower or faster */
int tempo = 85;
/* Calculate duration of a whole note */
int wholenote = (60000 * 4) / tempo;
int divider = 0, noteDuration = 0;
char god_title[20] = "Godfather";
char got_theme[20] = "Game of Thrones";
char imperial_title[20] = "Imperial March";


/* LED MATRIX */
/* Define some characters for the Led Matrix */
int CURRENT_STATE = -1;
byte eight[8]= {0x7E,0x7E,0x66,0x7E,0x7E,0x66,0x7E,0x7E};
byte vertigo[8] = {0xFF,0x81,0xBD,0xA5,0xAD,0xA1,0xBF,0x80};

/* Define hello welcome message */
byte h[8] = { 0x66,0x66,0x66,0x7E,0x7E,0x66,0x66,0x66};
byte e[8] = {0x7C,0x7C,0x60,0x7C,0x7C,0x60,0x7C,0x7C};
byte l[8] = {0x60,0x60,0x60,0x60,0x60,0x60,0x7E,0x7E};
byte o[8] = {0x7E,0x7E,0x66,0x66,0x66,0x66,0x7E,0x7E};

/* Define main STANDBY loop matrix model */
int STANDBY = 10;
int check_standby = 200;
int DELAY_STANDBY = 20;
byte STANDBY_1[8] = {0xFF,0x81,0x81,0x81,0x81,0x81,0x81,0xFF};
byte STANDBY_2[8] = {0x00,0x7E,0x42,0x42,0x42,0x42,0x7E,0x00};
byte STANDBY_3[8] = {0x00,0x00,0x3C,0x24,0x24,0x3C,0x00,0x00};
byte STANDBY_4[8] = {0x00,0x00,0x00,0x18,0x18,0x00,0x00,0x00};
int STANDBY_VAL[4] = {0, 0, 0, 0};


int currentFace = 0;
byte smiley[8]=   {0x3C,0x42,0xA5,0x81,0xA5,0x99,0x42,0x3C};
byte neutral[8]= {0x3C,0x42,0xA5,0x81,0xBD,0x81,0x42,0x3C};
byte frownie[8]=   {0x3C,0x42,0xA5,0x81,0x99,0xA5,0x42,0x3C};
byte xc[8] = {0x81,0x42,0x24,0x18,0x18,0x24,0x42,0x81};
/* Defined for freestyle */
byte form_0[8] = {0x18,0x18,0x18,0xFF,0xFF,0x18,0x18,0x18};
byte form_1[8] = {0x66,0x66,0x66,0xBD,0xBD,0x66,0x66,0x66};
byte form_2[8] = {0x09,0xC6,0xC2,0x19,0x98,0x43,0x63,0x90};
byte form_3[8] = {0xC3,0x3C,0x3C,0x99,0x99,0x3C,0x3C,0xC3};
byte form_4[8] = {0x01,0x02,0x04,0x08,0x10,0xA0,0xC0,0xE0};
byte form_5[8] = {0x07,0x03,0x05,0x08,0x10,0x20,0x40,0x80};
byte form_6[8] = {0x18,0x3C,0x7E,0xFF,0x7E,0x3C,0x18,0x18};
byte form_7[8] = {0xDB,0x81,0x81,0x18,0x58,0x81,0x81,0xDB};
byte form_8[8] = {0xDB,0xDB,0x18,0xC3,0xC3,0x18,0xDB,0xDB};



int MATRIX_DIMENSION = 8;
int MATRIX_POSITION_LED = 0;
/* LED MATRIX */
const unsigned long period = 100;
unsigned long startMillis;
unsigned long currentMillis;

void setup() {
    Serial.begin(9600);
    startMillis = millis();
  
    /* Set configuration for speakers */
    pinMode(speakPins[0], OUTPUT); // speaker 1
    pinMode(speakPins[1], OUTPUT); // speaker 2
    pinMode(speakPins[2], OUTPUT); // speaker 3

    /* Setup the LCD Display */
    lcd.init();
    lcd.init();
    // Print a message to the LCD.
    lcd.backlight();
    lcd.setCursor(0,0);
    lcd.print("Welcome master...");
    lcd.setCursor(0,1);
    lcd.print("Play some music!");
  
    /* Setup the matrix leds */
    lc.shutdown(0, false);
    lc.setIntensity(0, 7);
    lc.clearDisplay(0);

    /* Setup the buzzer */
    pinMode(BUZZER_PIN, OUTPUT);

    printHelloMessage();
    CURRENT_STATE = STANDBY;
}

/* Print numbers on the matrix */
void printByte(byte character [])
{
    int i = 0;
    for(i = 0; i < 8; i++) {
       lc.setRow(0, i, character[i]);
    }
}

void printHelloMessage()
{
    printByte(h);
    delay(500);
    printByte(e);
    delay(500);
    printByte(l);
    delay(500);
    lc.clearDisplay(0);
    printByte(l);
    delay(500);
    printByte(o);
    delay(500);

    lc.clearDisplay(0);
}

void printStandByMessage()
{
    simulateDelay(&STANDBY_VAL[0], STANDBY_1, 0);
    simulateDelay(&STANDBY_VAL[1], STANDBY_2, DELAY_STANDBY);
    simulateDelay(&STANDBY_VAL[2], STANDBY_3, DELAY_STANDBY * 2);
    simulateDelay(&STANDBY_VAL[3], STANDBY_4, DELAY_STANDBY * 3);

    if (STANDBY_VAL[0] == DELAY_STANDBY * 4) {
        STANDBY_VAL[2] = DELAY_STANDBY * 2;
    }

    if (STANDBY_VAL[0] == DELAY_STANDBY * 5) {
        STANDBY_VAL[1] = DELAY_STANDBY;
    }

    if (STANDBY_VAL[0] == DELAY_STANDBY * 6) {
        STANDBY_VAL[0] = 0;
        STANDBY_VAL[1] = 0;
        STANDBY_VAL[2] = 0;
        STANDBY_VAL[3] = 0;
    }
}

void simulateDelay(int *timesec, byte standbyVal[], int delay_time)
{
    if (*timesec == delay_time) {
        printByte(standbyVal);
    }
    
    *timesec = *timesec + 1;
}

void printVolume()
{
    lcd.clear();
    lcd.setCursor(4,0);
    lcd.print("Volume is");
    lcd.setCursor(7,1);
    lcd.print(VOLUME);
}

void printMelodyTitle(char title[])
{
    lcd.clear();
    lcd.setCursor(1,0);
    lcd.print("Now playing");
    lcd.setCursor(1,1);
    lcd.print(title);
}

void printStandBy()
{
    lcd.clear();
    // Print a message to the LCD.
    lcd.setCursor(0,0);
    lcd.print("Show your talent");
    lcd.setCursor(0,1);
    lcd.print("Play some music!");
}

void printLoopMessage()
{
    lcd.clear();
    // Print a message to the LCD.
    lcd.setCursor(0,0);
    lcd.print("Decrease the volume");
    lcd.setCursor(0,1);
    lcd.print("to use a loop!");
}

void printBPM()
{
    lcd.clear();
    // Print a message to the LCD.
    lcd.setCursor(1,0);
    lcd.print("Current BPM is");
    lcd.setCursor(7,1);
    lcd.print(SHOWBPM);
}

void play_song(int melody[], int melody_notes, int currentNote)
{
    // calculates the duration of each note
    divider = melody[currentNote + 1];
    if (divider > 0) {
      // regular note, just proceed
      noteDuration = (wholenote) / divider;
    } else if (divider < 0) {
      // dotted notes are represented with negative durations!!
      noteDuration = (wholenote) / abs(divider);
      noteDuration *= 1.5; // increases the duration in half for dotted notes
    }
  
    // we only play the note for 90% of the duration, leaving 10% as a pause
    if (VOLUME == 1) {
        tone(speakPins[0], melody[currentNote], noteDuration * 0.9);
        analogWrite(speakPins[0], noteDuration * 0.9);
    } else if (VOLUME == 2) {
        tone(speakPins[0], melody[currentNote], noteDuration * 0.9);
        tone(speakPins[1], melody[currentNote], noteDuration * 0.9);
        analogWrite(speakPins[0], noteDuration * 0.9);
        analogWrite(speakPins[1], noteDuration * 0.9);
    } else if (VOLUME == 3) {
        tone(speakPins[0], melody[currentNote], noteDuration * 0.9);
        tone(speakPins[1], melody[currentNote], noteDuration * 0.9);
        tone(speakPins[2], melody[currentNote], noteDuration * 0.9);
        analogWrite(speakPins[0], noteDuration * 0.9);
        analogWrite(speakPins[1], noteDuration * 0.9);
        analogWrite(speakPins[2], noteDuration * 0.9);
    }
  
    // Color the led matrix
    //lc.setRow(0, MATRIX_POSITION_LED, vertigo[MATRIX_POSITION_LED]);
    //MATRIX_POSITION_LED = MATRIX_POSITION_LED + 1;
    if (currentFace % 3 == 0) {
        printByte(smiley);
    } else if (currentFace % 3 == 1) {
        printByte(neutral) ;
    } else {
        printByte(frownie);
    }

    currentFace = currentFace + 1;
    // Wait for the specief duration before playing the next note.
    delay(noteDuration);

    //if (MATRIX_POSITION_LED == MATRIX_DIMENSION) {
    //    MATRIX_POSITION_LED = 0;
    //    lc.clearDisplay(0);
    //}
  
    // stop the waveform generation before the next note.
    noTone(speakPins[0]);
    noTone(speakPins[1]);
    noTone(speakPins[2]);
}

void playNote(int NOTE, int noteDuration)
{
     if (VOLUME == 1) {
        tone(speakPins[0], NOTE, noteDuration);
        analogWrite(speakPins[0], noteDuration);
    } else if (VOLUME == 2) {
        tone(speakPins[0], NOTE, noteDuration);
        tone(speakPins[1], NOTE, noteDuration);
        analogWrite(speakPins[0], noteDuration);
        analogWrite(speakPins[1], noteDuration);
    } else if (VOLUME == 3) {
        tone(speakPins[0], NOTE, noteDuration);
        tone(speakPins[1], NOTE, noteDuration);
        tone(speakPins[2], NOTE, noteDuration);
        analogWrite(speakPins[0], noteDuration);
        analogWrite(speakPins[1], noteDuration);
        analogWrite(speakPins[2], noteDuration);
    }
}

void freeStyleMode(char customKey)
{
    if (customKey=='7') {
        check_standby = 0;
        CURRENT_STATE = -1;
        playNote(NOTE_D4, 350);
        printByte(form_0);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_D4;
        }
    }
    
    if (customKey=='4') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_E4, 350);
        printByte(form_1);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_E4;
        }
    }

    if (customKey=='1') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_F3, 350);
        printByte(form_2);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_F3;
        }
    }

    if (customKey=='8') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_C1, 350);
        printByte(form_3);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_C1;
        }
    }

    if (customKey=='5') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_B4, 350);
        printByte(form_4);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_B4;
        }
    }

    if (customKey=='2') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_C3, 350);
        printByte(form_5);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_C3;
        }
    }
    
    if (customKey=='9') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_D1, 350);
        printByte(form_6);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_D1;
        }
    }
  
    if (customKey=='6') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_E5, 350);
        printByte(form_7);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_E5;
        }
    }

    if (customKey=='3') {
        check_standby = 0;
        CURRENT_STATE = -1;

        playNote(NOTE_FS2, 350);
        printByte(form_8);

        if (LOOPMODE == 0) {
            LOOPNOTE = NOTE_FS2;
        }
    } 
}

void loop() {
    currentMillis = millis();
    /* Get every key from keyboard pressing */
    char customKey = customKeypad.getKey();
    freeStyleMode(customKey);
  
    if (IS_PLAYING[CURRENT_SONG_INDEX] == 1) {
        /* Reset note variables */
        divider = 0; noteDuration = 0;
        wholenote = (60000 * 4) / tempo;
  
        play_song(CURRENT_SONG, CURRENT_NOTES, currentNote);
        currentNote = currentNote + 2;
  
        if (currentNote == CURRENT_NOTES * 2) {
            currentNote = 0;
            IS_PLAYING[CURRENT_SONG_INDEX] = 0;
            lc.clearDisplay(0);
        }
    }
  
    /* Start the Game of Thrones theme */
    if (customKey == '0') {
        printMelodyTitle(got_theme);
        /* Clear display and current flag */
        CURRENT_STATE = -1;
        lc.clearDisplay(0);

        tempo = 85;
        CURRENT_SONG_INDEX = 0;
        IS_PLAYING[CURRENT_SONG_INDEX] = 1;
        
        CURRENT_SONG = game_of_thrones_melody;
        CURRENT_NOTES = game_of_thrones_notes;
    }
  
    /* Start the Imperial March - Star Wars theme */
//    if (customKey == '*') {
//        printMelodyTitle(imperial_title);
//        /* Clear display and current flag */
//        CURRENT_STATE = -1;
//        lc.clearDisplay(0);
//     
//        tempo = 120;
//        CURRENT_SONG_INDEX = 1;
//        IS_PLAYING[CURRENT_SONG_INDEX] = 1;
//        
//        CURRENT_SONG = imperial_march_melody;
//        CURRENT_NOTES = imperial_march_notes;
//    }

     /* Make a little bit BPM */
     if (customKey == '*') {
      if (BPM < 65)
          BPM = BPM + 1;
          SHOWBPM = SHOWBPM - 1;
          printBPM();
     }
  
     /* Grow up the BPM */
     if (customKey == '#') {
          if (BPM > 0) {
              BPM = BPM - 1;
              SHOWBPM = SHOWBPM + 1;
          }
          printBPM();
     }
  
    /* Enter in the loop mode */
    if (customKey == 'D' && LOOPMODE == 0) {
        LOOPMODE = 1;
    } else if (customKey == 'D' && LOOPMODE == 1) {
        LOOPMODE = 0;
    }

    if (LOOPMODE == 1) {
        if (LOOPTIME >= BPM) {
            tone
            (BUZZER_PIN, LOOPNOTE, 200);
            analogWrite(BUZZER_PIN, 200);
            LOOPTIME = 0;
        }
    }

    /* Stop the current playing */
    if (customKey == 'C') {
        printStandBy();
        /* Clear display and set current flag */
        CURRENT_STATE = STANDBY;
        lc.clearDisplay(0);
      
        IS_PLAYING[CURRENT_SONG_INDEX] = 0;
        currentNote = 0;
    }

    /* Increase the volume */
    if (customKey == 'A') {
        if (VOLUME <= 2) {
            VOLUME = VOLUME + 1;
            printVolume();
        }
    }

    /* Decrease the volume */
    if (customKey == 'B') {
        if (VOLUME > 0){
           VOLUME = VOLUME - 1;
           printVolume();
        }
    }

    if (check_standby == 200) {
        CURRENT_STATE = STANDBY;
    }

    if (CURRENT_STATE == STANDBY) {
        printStandByMessage();
    }

    check_standby = check_standby + 1;
    LOOPTIME = LOOPTIME + 1;
    
    Serial.println(currentMillis);
}
