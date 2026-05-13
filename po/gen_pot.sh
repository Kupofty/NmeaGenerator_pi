#!/bin/bash

# ==============================================================
# Translation Template Generation Script
#
# --------------------------------------------------------------
# Author: Kupofty 
#
# This script prepares the translation template (.pot) used by
# gettext-based internationalization.
#
# It performs two main tasks:
#   1. Build the list of source files containing translatable
#      strings (POTFILES.in).
#   2. Extract these strings and generate/update the POT file.
#
# Expected project structure:
#
# project/
# ├─ inc/        → H/H++ header files
# ├─ src/        → C/C++ source files
# └─ po/         → translation files (.po / .pot)
# ==============================================================

# ---------- ANSI COLORS ----------
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
BLUE='\033[0;34m'
CYAN='\033[0;36m'
NC='\033[0m' # No Color

# Move to the project root directory (the script must be executed from the po/ folder)
echo -e "${CYAN}[*] Moving to project root directory...${NC}"
cd .. 


# --------------------------------------------------------------
# STEP 1: Generate the list of source files to scan
#
# POTFILES.in is used by gettext tools to know which files contain translatable strings.
#
# This command recursively searches the src/ directory for:
#   - .cpp  (C++ source files)
#   - .h    (header files)
#   - .hpp  (C++ header files)
#
# The resulting file list is written to:
#   po/POTFILES.in
# --------------------------------------------------------------

echo -e "${BLUE}[*] Generating POTFILES.in...${NC}"

find src/ \( -name "*.cpp" -o -name "*.h" -o -name "*.hpp" \) > po/POTFILES.in

if [ $? -eq 0 ]; then
    echo -e "${GREEN}[OK] POTFILES.in generated successfully.${NC}"
else
    echo -e "${RED}[ERROR] Failed to generate POTFILES.in.${NC}"
    exit 1
fi


# --------------------------------------------------------------
# STEP 2: Generate or update the translation template (.pot)
#
# xgettext scans all files listed in POTFILES.in and extracts
# strings marked for translation using the _() macro.
#
# Important options:
#
# --add-comments=TRANSLATORS
#   Include developer comments starting with "TRANSLATORS:"
#   in the generated POT file to help translators.
#
# --force-po
#   Always generate the output file even if no strings are found.
#
# --from-code=iso-8859-1
#   Specifies the encoding used in the source files.
#
# --keyword=_
#   Indicates that translatable strings are wrapped using _()
#
# --width=80
#   Sets the maximum line width in the generated file.
#
# --files-from
#   Provides the list of files to scan.
#
# Output:
#   po/nmeagenerator_pi.pot
#
# This file is the master translation template used to update
# language-specific .po files.
# --------------------------------------------------------------

echo -e "${BLUE}[*] Generating nmeagenerator_pi.pot...${NC}"

xgettext \
  --add-comments=TRANSLATORS \
  --force-po \
  --from-code=iso-8859-1 \
  --output=po/nmeagenerator_pi.pot \
  --keyword=_ \
  --width=80 \
  --files-from=po/POTFILES.in

if [ $? -eq 0 ]; then
    echo -e "${GREEN}[OK] Translation template generated successfully.${NC}"
else
    echo -e "${RED}[ERROR] xgettext failed.${NC}"
    exit 1
fi

echo -e "${YELLOW}[*] Done.${NC}"
