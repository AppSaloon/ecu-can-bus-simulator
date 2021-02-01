# ecu-can-bus-simulator
This is a small example sketch that simulates a cars ecu. I copied the base code from [instructables user mviljoen2](http://www.instructables.com/id/Arduino-OBD2-Simulator/).

## Supported PID's

* 0x00: SupportedPID
* 0x01: MilCleared
* 0x05: Coolant Temperature in on Celsius
* 0x0C: RPM
* 0x0D: Vehicle Speed
* 0x0F: Intake Air Temperature
* 0x10: MAF Value
* 0x46: Ambient Air Temperature
* 0x3C: Catalytic converter Sensor1 
* 0x3D: Catalytic converter Sensor2 
* 0x3E: Catalytic converter Sensor3
* 0x3F: Catalytic converter Sensor4

## Features
 * [x] sends value back on request
 * [ ] configuration of first 0 to 20 pids
 * [ ] correct input values

# Dependencies
this example uses the [Seeed Studio library](https://github.com/Seeed-Studio/CAN_BUS_Shield)

# Compatible shields
* Seeedstudio [CAN-BUS Shield V1.2](http://www.seeedstudio.com/depot/CANBUS-Shield-V12-p-2256.html) [wiki](http://www.seeedstudio.com/wiki/CAN-BUS_Shield_V1.2) [github](https://github.com/Seeed-Studio/CAN_BUS_Shield)
* Sparkfun [CAN-BUS Shield](https://www.sparkfun.com/products/13262) [github](https://github.com/sparkfun/SparkFun_CAN-Bus_Arduino_Library)

# Sources
* [car hackers handbook](http://opengarages.org/handbook/2014_car_hackers_handbook_compressed.pdf)
* [odbII PID's (wikipedia)](https://en.wikipedia.org/wiki/OBD-II_PIDs)
