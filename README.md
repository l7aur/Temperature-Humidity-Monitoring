# Temperature & Humidity Monitoring

*Arduino project for the Design with Microprocessors course at Technical University of Cluj-Napoca*

![diag_full2](https://github.com/user-attachments/assets/5c1507f6-167d-4f87-8bf6-00f907148260)
![diag_full3](https://github.com/user-attachments/assets/5a319f66-66e2-4769-9e09-82b37018609a)
![diag_full3](https://github.com/user-attachments/assets/094e57f5-1e3a-452d-8ac7-4580de8dbd31)

I chose this project because I was familiar with temperature measuring from another assignment. This topic seems interesting to me because there is a wide variety of sensors on the market with different specifications that can provide input data for a computation pipeline. I have used such kind of input to create a temperature histogram before (a great visual tool to detect average temperatures over a period of time and other statistics-related values), and now I want to implement a "feedback" circuit that has three main parts:

- **INPUT** some temperature sensor that acts as input source.
- **OUTPUT** different kinds of visual indicators such as LEDs and displays or transducers such as a fan.
- **CORE LOGIC** Arduino (C++) code that is to be uploaded on a Uno Board to manage the input and output.

Multiple solutions are available on the web, however I chose to let my creativity and skills decide how this job was developing. I tried to use multiple types of components to get the best out of this assignment. My purpose was to get a grasp on how to control the things that are most likely to be used in an Arduino project.

### Implementation

List of components:
- Arduino-Uno-compatible board and programming cable
- I2C LCD
- RGB LED
- 8-LED module
- DHT22 temperature & humidity sensor
- three 470Ω resistors
- one 4700Ω resistor
- one fan
- about 30 (F-M, M-M, F-F) wires

I have chosen to implement my project in a bottom-up manner, meaning that I started with small parts that had nothing to do with each other at first glance. Once all these modules had been designed, implemented and tested, I moved to creating the inter-component logic. The main advantage my approach offered was to let me think in object-oriented style. Thus, each component (printed circuit boards, simple LEDs, temperature or humidity sensors) was wrapped inside an abstract object (class). Being a relatively complex project thanks to the amount of components that have different behaviors, the development process was accelerated because I had access to the high-level abstraction mechanisms provided by C++. By trying to follow the **SOLID** principles and some good practice industry rules, the final form of the source code appears to me as maintainable, clear to use and improve, and most importantly free of bugs, useless code and redundancy.
