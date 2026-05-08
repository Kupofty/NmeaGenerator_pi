# NmeaGenerator_pi

An OpenCPN plugin for generating, injecting, and simulating NMEA 0183 sentences — useful for testing, debugging, and validating navigation data flows without real hardware sensors.

## Installation

Three options are available:
- **Compile from source** — see [INSTALL.md](INSTALL.md) for instructions
- **Download a tarball** — available on [Cloudsmith](https://cloudsmith.io/~kupoftyopencpn/repos/)
- **Install via the OpenCPN plugin catalogue**

## Modes

### Manual Input
Send custom NMEA sentences, either manually or automatically, with full control over sentence content and optional checksum calculation.

### Sentence Builder
Quickly access the most common NMEA sentences, customize values within valid ranges, and trigger them manually or on a schedule.   
A built-in search box makes it easy to find specific sentences.

### Simulation Mode
Generate continuous NMEA data streams simulating own ship and/or AIS targets, with interactive steering and throttle controls that update position in real time.

For full details, see the [manual](https://github.com/Kupofty/NmeaGenerator_pi/blob/main/manual/modules/ROOT/pages/index.adoc).

## Typical Use Cases

- OpenCPN plugin development and testing
- Navigation instrument validation
- AIS and GPS simulation
- Debugging NMEA data pipelines
- Training without physical navigation equipment

## Discussions

For questions, bug reports, or feature requests :
- Open a GitHub [Issue](https://github.com/Kupofty/NmeaGenerator_pi/issues)
- Ask on GitHub [Discussions](https://github.com/Kupofty/NmeaGenerator_pi/discussions)
- Join the thread on the [Cruisers & Sailing forum](https://www.cruisersforum.com/forums/f134/nmeagenerator-plugin-299761.html)