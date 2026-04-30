# NmeaGenerator Changelog

###
## [v1.1.0] / 2026-xx-xx

### Added
- Plugin window can be maximized/minimized
- Settings window can be resized
- Checksum verificator in "Manual Input" tab
- Option to keep sending data when window is closed (need to be activated in Preferences)
- Button to copy to clipboard the sentence in "Manual Input" tab
- Option to automatically copy NMEA sentence to clipboard when manually sending in "Sentence builder" (need to be activated in Preferences)
- Configurable timer for sending simulation data
- Dual vessel simulations (Own ship & AIS/TLL target) can now run simultaneously
- Add AIS encoding & capabilities (class A & B) in "Simulation" & "Sentence builder" tabs

### Fixed
- Sentences with "!" as first character are accepted in "Manual input" tab.  
- Convert simulation START/STOP button into a toggle button to indicate state.
- Easier position input in "Simulation tab"
- Display error due to field's width too small in "Sentence builder"
- XDR IDs now follow NMEA 4.11 revision

###
## [v1.0.0] / 2026-04-15
### Initial release
