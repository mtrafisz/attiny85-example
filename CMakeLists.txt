cmake_minimum_required(VERSION 3.5)
project(led_blink)

# set MCU and clock frequency
set(MCU attiny85)
set(F_CPU 8000000UL)

# setup compiler and linker
set(CMAKE_C_COMPILER avr-gcc)
set(CMAKE_OBJCOPY avr-objcopy)
set(CMAKE_SIZE avr-size)
set(CMAKE_AVRDUDE avrdude)

# set compiler flags
set(CMAKE_C_FLAGS "-mmcu=${MCU} -DF_CPU=${F_CPU} -Os -Wall -Wextra -Werror -std=c99")

# set linker flags
set(CMAKE_EXE_LINKER_FLAGS "-mmcu=${MCU}")

# set output file names
set(OUTPUT_ELF ${CMAKE_PROJECT_NAME}.elf)
set(OUTPUT_HEX ${CMAKE_PROJECT_NAME}.hex)

# add source files
set(SOURCE_FILES
    main.c
)

# compile and link
add_executable(${OUTPUT_ELF} ${SOURCE_FILES})

# create hex file
add_custom_command(TARGET ${OUTPUT_ELF} POST_BUILD
    COMMAND ${CMAKE_OBJCOPY} -O ihex -R .eeprom ${OUTPUT_ELF} ${OUTPUT_HEX}
    COMMENT "Creating hex file..."
)

# print size
add_custom_command(TARGET ${OUTPUT_ELF} POST_BUILD
    COMMAND ${CMAKE_SIZE} ${OUTPUT_ELF}
)

# upload to MCU via avrdude
add_custom_target(upload
    COMMAND ${CMAKE_AVRDUDE} -c arduino -p ${MCU} -P /dev/ttyUSB0 -b 19200 -U flash:w:${OUTPUT_HEX}
    DEPENDS ${OUTPUT_HEX}
    COMMENT "Uploading to MCU..."
)
