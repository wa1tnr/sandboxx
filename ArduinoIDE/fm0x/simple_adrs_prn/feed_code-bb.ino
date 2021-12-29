/* feed_code-aa.ino */
/* Memory[] SHOWS UP in the ram dump if declared volatile! */
/*  lcmp */
/* 29 Dec 02:36z */

// for wokwi Uno simulator:

//    [ https://wokwi.com/arduino/new?template=arduino-uno ]

/* ************************    ADDRESSES    *********************** */
// ram address:
// #define START_ADDRESS 0x200003BA

// internal flashROM address:
// #define START_ADDRESS 0x1d20

#define START_ADDRESS 0xF7FF+1+800+400+400+400

// #define START_ADDRESS 0x0

// how much output - in units of 16 byte lines:
#define LINES 0x1000

// p is an integer and is assigned a value that is an address:
int p = START_ADDRESS;

// generic print buffer to print to the USB serial port:
// char buffer[128];






/* ********************    C PREPROCESSOR MACRO    ********************** */
#define lcl_printf() \
    buf_ptr = * & buffer; \
    memcpy(buffering, buf_ptr, sizeof buffer); \
    print_buffer();



char buffering[64];

// don't know how to declare this to find it in the memory dump ;)
// 01:55 UTC



// const uint16_t Memory[] = {


void burgers() {

    char buffer[48];
    char* buf_ptr;
  
    buffer[0] = 'a';
    buffer[1] = 'z';
    buffer[2] = '\000';

    int Memory[] = {
    0xfe, 0xed, 0xc0, 0xde, 0xca, 0xde, 0xce, 0xde,
    0xfe, 0xed, 0xc0, 0xde, 0xca, 0xde, 0xce, 0xde,
    0xfe, 0xed, 0xc0, 0xde, 0xca, 0xde, 0xce, 0xde,
    };
    printf(Memory[2]);
    // sprintf(buf_ptr, "%X", Memory[16]);
    // lcl_printf();
}

// simple putch() as used in the C language:
void putch(char ch) {
    Serial.print(ch);
}


void print_buffer(void) {
    Serial.print(buffering);
}

void space_it(void) {
      sprintf(buffering, "%c", ' ');
      print_buffer();
}

void newline(void) {
      sprintf(buffering, "%c", '\n');
      print_buffer();
}

void testpa(void) {
      newline();
      space_it();
      
      char buffer[48]; // 32 also 64
      char* buf_ptr;

      buffer[0] = 'a';
      buffer[1] = 'b';
      buffer[2] = 'c';
      buffer[3] = '\000';

      buf_ptr = buffer;

      int buf_size, buf_ptr_size;

      buf_size = sizeof(buffer); // captures "abc\000" size
      buf_ptr_size = sizeof(buf_ptr);

      int buf_len = strlen(buffer);

      // size_t gottem;

      sprintf(buffering, "%c", '\'');
      print_buffer();

      memcpy(buffering, buf_ptr, sizeof buffer);
      print_buffer();

      sprintf(buffering, "%c%c", '\'', ' ');
      print_buffer();

      sprintf(buffering, "%s ", " is the buffer contents");
      print_buffer();

      sprintf(buf_ptr, "\n         sizeof(buf_ptr) is  %d", buf_ptr_size);

      lcl_printf();

      sprintf(buf_ptr, "%s", "\n         sizeof(buffer)  is ");

      lcl_printf();

      buf_size = sizeof(buffer); // captures "abc\000" size

      sprintf(buf_ptr, "%d\n", buf_size); // related to string length, possibly
      lcl_printf();

      sprintf(buf_ptr, "%s", "         strlen(buffer)  is ");
      lcl_printf();

      sprintf(buf_ptr, " %d\n", buf_len); // related to string length, possibly
      lcl_printf();

      uint8_t adrs;
      adrs = (uint8_t) & buf_ptr;

      sprintf(buf_ptr, "%s", "adrs (& buf_ptr) in hex is        ");
      lcl_printf();

      // print the buffer's address in ram
      sprintf(buf_ptr, "0x%.8X\n", adrs);
      lcl_printf();

      sprintf(buf_ptr, "%s", "adrs (& buf_ptr) in decimal is  ");
      lcl_printf();

      sprintf(buf_ptr, "%c%.11u\n\n", ' ', adrs);
      lcl_printf();

      burgers();

}

/* **************************    DUMP    ************************* */
int dump_16_bytes(void) {
    char buffer[48]; // 32 also 64
    char* buf_ptr;
    buffer[0] = 'a';
    buffer[1] = 'b';
    buffer[2] = 'c';
    buffer[3] = '\000';

    buf_ptr = buffer;

    char *ram;
    ram = (char *) p; // not used immediately - see Line 43, below

    sprintf(buf_ptr, "\n%4X: ", p); // print an integer 'p' as a formatted string,
                                   // to a string buffer 'buffer'
    lcl_printf();

    // Serial.print('x'); // was annoying
    Serial.print(' ');
    int count = -1;
    for (int i = 0; i < 16; i++) {
        count++;
        if (i == 8)
            putch('\040'); // extra padding after eighth byte is printed
        if (count > 3) {
            count = (count & 0x03); // pad every four bytes ..
            putch('\040');          // with a space char, 0x20 (octal: \040)
        }
        char c = *ram++;      // c now holds the character stored at address p

                              // see Line 27, above, for initial value of *ram

// ----------------------------------------------------------------------------------------
// Exercise   - modify  *ram  so that it does not increment:
//
//      char c = *ram;        // why are we allowed to use  *ram++  here? What does it do?
// ----------------------------------------------------------------------------------------

        sprintf(buf_ptr, " %02X", (c & 0xff)); // format c as two hexadecimal digits (in ASCII)
        lcl_printf();
        // Serial.print("DebugFOO"); // random foo to prove where/when this gets executed
    }
    ram = (char *) p; // see Line 27 - does the exact same thing, but in the present context

    putch('\040'); putch('\040'); putch('\040'); // three spaces

    // print out the ASCII equivalents, in the rightmost 16 columns:
    for (int i = 0; i < 16; i++) {
        buffer[0] = (uint32_t) * ram++;
        if (buffer[0] > 0x7e || buffer[0] < ' ')
            buffer[0] = (uint32_t) '.'; // use a dot for non-printing characters
        buffer[1] = '\0';
        buf_ptr = 
        lcl_printf();
    }
    // increment address in memory by 16:
    return p + 16;
}




void setup (void) {
    Serial.begin(115200);
//  while (!Serial) { } // await a connection
    delay(2000); // after connect, wait 2 sec
    Serial.println("here is.");

    testpa();



    delay(6000);      
        for (int index = LINES; index > 0; index--) { // dump three lines 16 bytes/line
        // p has an initial value the first time through this loop
        // p is an address in RAM or ROM
        p = dump_16_bytes();
    }
}

void loop (void) {
    while (-1) { }
    Serial.println("Escaped the while()\r\n");
}

// END.
