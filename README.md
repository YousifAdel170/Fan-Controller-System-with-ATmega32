# fan-controlled-system
Fan controlled system automatically

⚙️🖥️ Hardware Setup: For this project, I utilized the mighty ATmega32 MCU, operating at a clock frequency of 1 MHz. The system revolves around controlling a fan based on temperature readings from the LM35 sensor.



🌡️ Temperature-Based Fan Control: The system's primary role is to automatically switch the fan on or off and regulate its speed in accordance with the ambient temperature. Following is a breakdown of fan behavior according to various temperature ranges: 

❌ The fan is shut off to keep the room cool if the temperature falls below 30°C. 

☢️💨 The fan is activated at 25% of its maximum speed if the temperature hits or surpasses 30°C, creating a moderate airflow to control the temperature. 

☢️💨 The fan speed is increased to 50% of its full capacity when the temperature rises above 60°C, improving cooling efficiency. 

☢️💨 When the temperature exceeds 120°C, the fan runs at its full speed to ensure the best cooling performance. 

☢️💨 If the temperature climbs beyond 90°C, the fan operates at 75% of its maximum speed, intensifying the cooling power to combat the heat.



💻 System Output: Using a display with an LCD and the 8-bit mode, the current status of the fan is continuously updated and presented. Users are able to keep tabs on the fan's operation and state thanks to this.



🔌 Hardware Components: The system makes use of many important hardware elements to accomplish this functionality: ▪ Timer 0 PWM is used to precisely manage the speed of the DC motor, which serves as the fan, ▪ The LM35 Temperature Sensor, which delivers accurate temperature readings and is used as the input to control the fan's behavior.





🏗️ Layered Architecture: 

▪ Application Layer: The fan control logic is handled by this layer, which also decides when to turn the fan on or off and how fast it should spin in response to temperature readings. 



▪ HAL (Hardware Abstraction Layer): The HAL acts as an interface between the application layer and the hardware components. It encompasses modules for the LCD, LM35 Temperature Sensor, and the DC Motor (fan). It handles initialization, configuration, and communication with these hardware modules. 



▪ MCAL (Microcontroller Abstraction Layer): The MCAL interacts directly with the microcontroller's hardware peripherals. It includes modules for GPIO (General Purpose Input/Output) to control various pins, ADC (Analog-to-Digital Converter) for reading temperature values from the LM35 sensor, and PWM (Pulse Width Modulation) using Timer0 to control the fan's speed.
