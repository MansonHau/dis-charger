
// Pin declarations
int load_control = 10;
int voltage_monitor = A0;

int battery_volts = 0;
int stop_point = 100; // Modify this as needed: Stop point for 12V lead acid between 10 to 12 volts.
bool test_complete = false; // Declares the test complete

void setup() {
  // Pin configurations
  pinMode(load_control, OUTPUT);
  pinMode(voltage_monitor, INPUT);

  }

void loop() {
  // Check the incoming voltage to begin the discharge test

  battery_volts = analogRead(voltage_monitor);

  // Begin discharging if voltage is high enough
  if (battery_volts > stop_point && test_complete == false) {
    digitalWrite(load_control, HIGH);
    test_complete = false;
  }
  
  // Stop if voltage drops below set stop point
  if (battery_volts <= stop_point || test_complete == true) {
    digitalWrite(load_control, LOW);
    test_complete = true;
  }

  delay(500);
  

}
