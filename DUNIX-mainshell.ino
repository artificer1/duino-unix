#include <Arduino.h>

const int MAX_LINE_LENGTH = 80;

char command[MAX_LINE_LENGTH];
int commandIndex = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("Initialized!");
}

void loop() {
  if (Serial.available()) {
    char c = Serial.read();
    if (c == '\n') {
      command[commandIndex] = '\0';
      executeCommand();
      commandIndex = 0;
    } else if (commandIndex < MAX_LINE_LENGTH - 1) {
      command[commandIndex++] = c;
    }
  }
}

void executeCommand() {
  if (strcmp(command, "help") == 0) {
    printHelp();
  } else if (strcmp(command, "cat") == 0) {
    catCommand();
  } else if (strcmp(command, "ps") == 0) {
    psCommand();
  } else if (strcmp(command, "uname") == 0) {
    unameCommand();
  } else {
    Serial.println("Unknown command");
  }
}

void printHelp() {
  Serial.println("Available commands:");
  Serial.println("help - Display this help message");
  Serial.println("cat - Print input line");
  Serial.println("ps - Print process information");
  Serial.println("uname - Print system information");
}

void catCommand() {
  Serial.print("Input: ");
  Serial.println(command);
}

void psCommand() {
  Serial.println("Process ID: 12345");
  Serial.println("Running task: Main loop");
}

void unameCommand() {
  Serial.println("DUNIX Shell");
}
