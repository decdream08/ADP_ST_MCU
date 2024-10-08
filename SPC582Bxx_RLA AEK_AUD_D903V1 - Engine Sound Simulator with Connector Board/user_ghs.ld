/****************************************************************************
*
* Copyright © 2016-2019 STMicroelectronics - All Rights Reserved
*
* License terms: STMicroelectronics Proprietary in accordance with licensing
* terms SLA0098 at www.st.com.
* 
* THIS SOFTWARE IS DISTRIBUTED "AS IS," AND ALL WARRANTIES ARE DISCLAIMED, 
* INCLUDING MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
*
* EVALUATION ONLY – NOT FOR USE IN PRODUCTION
*****************************************************************************/

/*
 * This file is automatically generated and can be overwritten, do no change
 * this file manually.
 */

/*
 * SPC582Bxx memory setup.
 */

DEFAULTS {
__irq_stack_size__      = 0;
__process_stack_size__  = 4096;
}

MEMORY
{
    dataflash : org = 0x00800000, len = 128k
    flash     : org = 0x00FC0000, len = 256k
	sound	  : org = 0x01000000, len = 768k
    ram       : org = 0x400A8000, len = 96K
}

OPTION ("-e=_reset_address")

SECTIONS
{
    . = ADDR(flash);
    .boot0 ALIGN(16) :
    {
        *(.boot)
        *(.handlers)
        *(.crt0)
    } > flash

    /* The IVPR register requires a 256 bytes alignment.*/
    .boot1 align (0x100):
    {
        __ivpr_base__ = .;
        *(.ivors)
    } > flash

    /* The vectors table requires a 4kB alignment.*/
    .boot2 align (0x1000):
    {
        *(.vectors)
    } > flash

    constructors  ALIGN(4) :
    {
        __init_array_start = .;
        "*(.init_array.*)"   
        *(.init_array)
        __init_array_end = .;
    } > flash

    destructors  ALIGN(4) :
    {
        __fini_array_start = .;
        *(.fini_array)
        "*(.fini_array.*)"   
        __fini_array_end = .;
    } > flash

    .vletext  ALIGN(16)  :
    {
        *(.vletext)
        "*(.vletext.*)"
        "*(.ghs.linkonce.t_vle.*)"
    } > flash

    .syscall ALIGN(16) :
    {
        *(.syscall)
        "*(.syscall.*)"
        "*(.ghs.linkonce.t_vle.*)"
    } > flash

    .text  ALIGN(16)  :
    {
        *(.text)
        "*(.text.*)"
        "*(.ghs.linkonce.t.*)"
    } > flash

    .rodata  ALIGN(16) :
    {
        *(.rodata)
        "*(.rodata.*)"
    } > flash

    .sdata2  ALIGN(16) :
    {
        __sdata2_start__ = . + 0x8000;
        *(.sdata2)
        "*(.sdata2.*)"
        "*(.ghs.linkonce.s2.*)"
        *(.sbss2)
        "*(.sbss2.*)"
        "*(.ghs.linkonce.sb2.*)"
    } > flash

    .eh_frame_hdr :
    {
        *(.eh_frame_hdr)
    } > flash

    .eh_frame : 
    {
        *(.eh_frame)
    } > flash

	.sounddb  ALIGN(16)	:	
    {
        __sounddb_start__ = . ;
        *(.sounddb)
        "*(.sounddb.*)"
        "*(.gnu.linkonce.s.*)"
		    KEEP(*(.sounddb))
        __sounddb_end__ = .;
    } > sound

    .romdata  ALIGN(16) :
    {
        __romdata_start__ = .;
    } > flash

    .stacks ALIGN(16) :
    {
        . = ALIGN(8);
        __irq_stack_base__ = .;
        . += __irq_stack_size__;
        . = ALIGN(8);
        __irq_stack_end__ = .;
        __process_stack_base__ = .;
        __main_thread_stack_base__ = .;
        . += __process_stack_size__;
        . = ALIGN(8);
        __process_stack_end__ = .;
        __main_thread_stack_end__ = .;
    } > ram

    .data : AT(__romdata_start__)
    {
        . = ALIGN(4);
        __data_start__ = .;
        *(.data)
        "*(.data.*)"
        "*(.ghs.linkonce.d.*)"
    } > ram

    .sdata :
    {
        . = ALIGN(4);
        __sdata_start__ = . + 0x8000;
        *(.sdata)
        "*(.sdata.*)"
        "*(.ghs.linkonce.s.*)"
        __data_end__ = .;
    } > ram

    .sbss :
    {
        __bss_start__ = .;
        *(.sbss)
        "*(.sbss.*)"
        "*(.ghs.linkonce.sb.*)"
        *(.scommon)
    } > ram

    .bss :
    {
        *(.bss)
        "*(.bss.*)"
        "*(.ghs.linkonce.b.*)"
        *(COMMON)
        __bss_end__ = .;
    } > ram

    __dataflash_size__  = sizeof(dataflash);
    __dataflash_start__ = addr(dataflash);
    __dataflash_end__   = endaddr(dataflash);
    __flash_size__      = sizeof(flash);
    __flash_start__     = addr(flash);
    __flash_end__       = endaddr(flash);
    __ram_size__        = sizeof(ram);
    __ram_start__       = addr(ram);
    __ram_end__         = endaddr(ram);
    __heap_base__       = __bss_end__;
    __heap_end__        = __ram_end__;  
	__ghsbegin_heap		= __heap_base__;
	__ghsend_heap		= __heap_end__;
}
