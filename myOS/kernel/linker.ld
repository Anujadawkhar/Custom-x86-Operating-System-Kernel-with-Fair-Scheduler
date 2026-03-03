ENTRY(kernel_main)

SECTIONS
{
  . = 1M; /*kernel loads at 1MB*/

  .multiboot : { *(.multiboot) }
  .text : { *(.text*) }
  .data : { *(.data*) }
  .bss  : { *(.bss*) }
}
