# Project Name
TARGET = Blink

FREERTOS_DIR = FreeRTOS/FreeRTOS-Kernel

# Sources
CPP_SOURCES = \
Blink.cpp \
freertos_hooks.cpp 

C_SOURCES = \
$(FREERTOS_DIR)/tasks.c \
$(FREERTOS_DIR)/queue.c \
$(FREERTOS_DIR)/list.c \
$(FREERTOS_DIR)/timers.c \
$(FREERTOS_DIR)/event_groups.c \
$(FREERTOS_DIR)/stream_buffer.c \
$(FREERTOS_DIR)/portable/GCC/ARM_CM7/r0p1/port.c \
$(FREERTOS_DIR)/portable/MemMang/heap_4.c

# Library Locations
LIBDAISY_DIR = ../../libDaisy
DAISYSP_DIR = ../../DaisySP

C_INCLUDES += \
-I$(LIBDAISY_DIR)/Drivers/CMSIS/RTOS2/Include \
-I$(FREERTOS_DIR)/include \
-I$(FREERTOS_DIR)/portable/GCC/ARM_CM7/r0p1

# Core location, and generic makefile.
SYSTEM_FILES_DIR = $(LIBDAISY_DIR)/core
include $(SYSTEM_FILES_DIR)/Makefile

