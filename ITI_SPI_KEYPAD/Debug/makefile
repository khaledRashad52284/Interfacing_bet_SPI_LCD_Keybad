################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ITI_SPI_KEYPAD.lss \

FLASH_IMAGE += \
ITI_SPI_KEYPAD.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: ITI_SPI_KEYPAD.elf secondary-outputs

# Tool invocations
ITI_SPI_KEYPAD.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ITI_SPI_KEYPAD.map -mmcu=atmega32 -o "ITI_SPI_KEYPAD.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ITI_SPI_KEYPAD.lss: ITI_SPI_KEYPAD.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ITI_SPI_KEYPAD.elf  >"ITI_SPI_KEYPAD.lss"
	@echo 'Finished building: $@'
	@echo ' '

ITI_SPI_KEYPAD.hex: ITI_SPI_KEYPAD.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ITI_SPI_KEYPAD.elf  "ITI_SPI_KEYPAD.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ITI_SPI_KEYPAD.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ITI_SPI_KEYPAD.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ITI_SPI_KEYPAD.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
