# NmeaGenerator_pi

OpenCPN plugin for generating, injecting, and simulating NMEA 0183 sentences.  
Used for testing, debugging, and validating navigation data flows without requiring real hardware sensors.


## Modes

### Manual Input
- Send custom NMEA sentences (manual or automated)
- Full control over the sentence content
- Optional automatic checksum calculation


### Prebuilt List
- Includes most common NMEA sentences for quick access
- Each sentence can be customized within valid value ranges
- Trigger sentences manually or enable automated sending for selected entries
- Built-in search box to quickly find specific NMEA sentences


### Simulation Mode
- Generates continuous NMEA data streams
- Simulates own ship or AIS target
- Control steering and throttle with position updated accordingly


## Typical Applications
- OpenCPN plugin development and testing
- Navigation instrument validation
- AIS and GPS simulation
- Debugging NMEA data pipelines
- Training without physical navigation equipment
