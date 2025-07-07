# STM32CPP

# 📏 VL53L0X Distance Sensor Integration
The VL53L0X distance sensor library is now available.

The core driver, originally written in C by STMicroelectronics, has been lightly modified for easier integration. On top of that, I’ve implemented a high-level abstraction layer to simplify usage and enable clean interoperability with modern C++ code.

This simple example demonstrates how to:

- Integrate the C-based VL53L0X library into a C++ project

- Mix low-level C drivers with C++ abstractions

- Set up basic usage in an STM32 environment

🔗 Sample project:
github.com/czagaadam/STM32CPP/tree/main/Samples/CPP_AND_C

📚 VL53L0X Library source:
github.com/czagaadam/STM32CPP/tree/main/CLib/vl53l0x



# 🔌 I2C Class – Example Usage
The custom I2C class has been uploaded and is now available for use.

In this example, you’ll find a practical demonstration of how to utilize the I2C class to interface with the following devices:

- 🧪 MCP3221 – 12-bit ADC

- 🌡️ MCP9800 – Temperature sensor

- 📦 MCP23008 – I/O port expander

- 🔗 Example project:
github.com/czagaadam/STM32CPP/tree/main/Samples/CPP_I2C_Test

This sample shows how to handle communication with multiple I2C peripherals using clean and reusable C++ abstractions.

![ezgif-1-fc8456bf6d](https://github.com/user-attachments/assets/9b2483c4-fbea-4ccf-89f5-9ef2931af1e5)
