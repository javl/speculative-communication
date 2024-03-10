import serial
import time

def send_file_to_arduino(file_path, serial_port='COM3', baud_rate=9600):
    # Open the serial port
    with serial.Serial(serial_port, baud_rate) as ser:
        # Open the file
        with open(file_path, 'r') as file:
            # Read the file line by line
            for line in file:
                # Write each line to the serial port
                ser.write(line.encode())
                # Wait for the data to be transmitted
                time.sleep(0.01)

# Usage
send_file_to_arduino('your_file.txt')
