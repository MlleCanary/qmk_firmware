# MCU name
MCU = atmega32u4

# Bootloader selection
BOOTLOADER = caterina

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = no       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = yes      # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = yes        # Enable WS2812 RGB underlight.

SPLIT_KEYBOARD = yes

LAYOUTS = ortho_4x12
DEFAULT_FOLDER = keebio/levinson/rev2
