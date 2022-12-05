# MCU name
MCU = RP2040
BOARD = GENERIC_RP_RP2040

# Bootloader selection
BOOTLOADER = rp2040
#I2C_DRIVER	= I2CD1

# Build Options
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = yes       # Enable Bootmagic Lite
MOUSEKEY_ENABLE = yes       # Mouse keys
EXTRAKEY_ENABLE = yes       # Audio control and System control
CONSOLE_ENABLE = yes        # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = no           # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
AUDIO_ENABLE = no           # Audio output
RGBLIGHT_ENABLE = no 		# Enable WS2812 RGB underlight.
UCIS_ENABLE = yes
#POINTING_DEVICE_DRIVER = pimoroni_trackball
OLED_ENABLE = no
TAP_DANCE_ENABLE = yes
RAW_ENABLE = yes
VIA_ENABLE = yes
