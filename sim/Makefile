
RISCV_ARCH := -march=rv32ic
LINKER_SCRIPT := ../firmware/sections.lds
CROSS=/opt/riscv32i/bin/riscv32-unknown-elf-
CFLAGS:= -Wl,-Bstatic,-T,$(LINKER_SCRIPT),--strip-debug -ffreestanding -DICEBREAKER -nostdlib  
CFLAGS+= -I../firmware


RTL_FILES := ../rtl/kletech_soc.v
RTL_FILES += ../rtl/picosoc.v
RTL_FILES += ../rtl/picorv32.v
RTL_FILES += ../rtl/simpleuart.v
RTL_FILES += ../rtl/spimemio.v

TB_FILES += ../tb/testbench.v
TB_FILES += ../tb/spiflash.v

ifdef TEST
C_TEST := ../tests/$(TEST).c
else
C_TEST := ../tests/basic_rw.c
endif

firmware.elf : $(LINKER_SCRIPT) ../firmware/start.s  $(C_TEST)
	$(CROSS)gcc $(RISCV_ARCH) $(CFLAGS) -o firmware.elf ../firmware/start.s $(C_TEST)

firmware.hex : firmware.elf 
	$(CROSS)objcopy -O verilog $^ $@ 

testbench.vpp : $(RTL_FILES) $(TB_FILES)
	iverilog -s testbench -o $@ $^

sim : testbench.vpp firmware.hex 
	vvp -N $< +firmware=firmware.hex

clean :
	rm -f firmware.elf firmware.hex testbench.vpp testbench.vcd

.PHONY : clean all sim
