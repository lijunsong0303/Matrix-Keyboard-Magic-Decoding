# Matrix-Keyboard-Magic-Decoding

For other MCU ports to be set to open-drain outputs, the pins should have pull-ups enabled or external 10KΩ pull-up resistors at each pin.

![4x4keyC51](https://github.com/user-attachments/assets/f85a5e44-f80b-49ff-942f-88618cc59ad5)

## License

This project is licensed under the GNU LGPL v3 License.





## Advantages of the Single-Key Lookup-Based Keypad Decoder

### Constant-Time Execution (O(1))
The decoding process uses direct table lookup and bitwise operations, eliminating iterative row/column scanning. This ensures predictable and minimal execution time.

### High Performance and Low Latency
Compared to conventional scanning-and-compare methods, this approach significantly reduces instruction count, making it well-suited for time-critical embedded systems.

### Compact and Efficient Implementation
The algorithm requires only a small lookup table and simple bit manipulation, resulting in minimal code size and low memory footprint—ideal for resource-constrained microcontrollers.

### Deterministic Single-Key Detection
Only valid single-key presses produce a defined output (1–16). Any multi-key press is automatically rejected, improving input reliability without additional logic.

### Built-in Multi-Key Filtering
The design inherently filters out simultaneous key presses using bit pattern validation, avoiding the need for explicit multi-key detection code.

### Direct Mapping to Sequential Output
Each key is mapped directly to a continuous numeric range (1–16), simplifying downstream processing and application logic.  
If no buttons are pressed, or if multiple buttons are pressed simultaneously, the value returns 0.
