################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MKUART/subdir.mk
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
rybka.lss \

FLASH_IMAGE += \
rybka.hex \

EEPROM_IMAGE += \
rybka.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: rybka.elf secondary-outputs

# Tool invocations
rybka.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,rybka.map -mmcu=atmega32 -o "rybka.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

rybka.lss: rybka.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S rybka.elf  >"rybka.lss"
	@echo 'Finished building: $@'
	@echo ' '

rybka.hex: rybka.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex rybka.elf  "rybka.hex"
	@echo 'Finished building: $@'
	@echo ' '

rybka.eep: rybka.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex rybka.elf  "rybka.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: rybka.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 rybka.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) rybka.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
