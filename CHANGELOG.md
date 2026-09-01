# NmeaGenerator Changelog



--------------------------------------------------------------------------------------------
## [v1.2.1] / 2026-xx-xx
### Changed
- Minor labels changes
- Minor layout tweaks


--------------------------------------------------------------------------------------------
## [v1.2.0] / 2026-08-09
### Added
- Multiple AIS targets management with selectable control target
- Manual input list allowing multiple NMEA sentences to be configured and transmitted simultaneously
- Context menu action to update Own Ship or selected AIS target position from cursor location
- Persistent storage of last simulation vessel position across sessions

### Removed
- Manual position input for simulation ship & AIS targets
- "Help" button in "Sentence builder". Links moved to the manual.


--------------------------------------------------------------------------------------------
## [v1.1.0] / 2026-06-11
### Added
- AIS encoding & capabilities (AIVDM/AIVDO) in "Simulation" & "Sentence builder" tabs
- Vessel simulations (Own ship & AIS target) can now run simultaneously
- Checksum verificator in "Manual Input" tab
- New XDR transducers in "Sentence builder" tab
- Plugin window can be maximized/minimized & Settings window can be resized
- Option to keep sending data when window is closed (need to be activated in Preferences)
- Buttons to copy to clipboard the sentence in "Manual Input" and "Sentence builder" tabs
- Configurable timer for sending simulation data 
- Option to configure custom MMSI for AIS simulation and VDM in "Sentence Builder"
- Translations in DE/ES/FR

### Fixed
- Sentences with "!" as first character are accepted in "Manual input" tab.  
- Easier position input in "Simulation tab"
- Display error due to field's width too small in "Sentence builder"
- XDR IDs now follow NMEA 4.11 revision
- Convert simulation START/STOP button into a toggle button to indicate state.
- Remove manual checksum when auto-checksum is activated to prevent sending sentence with 2 checksums


--------------------------------------------------------------------------------------------
## [v1.0.0] / 2026-04-15
### Initial release
