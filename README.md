# Custom x86 Operating System with Fair Scheduler

This project is a small 32-bit x86 operating system kernel built primarily in C++.  
The kernel is loaded using the GRUB bootloader (Multiboot compliant) and runs inside QEMU.

The goal of this project was to understand how an OS boots, how a kernel is structured, and how CPU scheduling works internally.

## What I Implemented

- GRUB-based boot process using Multiboot
- Minimal kernel written in C++
- Custom linker script
- Direct VGA text mode output by writing to video memory (0xB8000)
- Simplified implementation of Linux Completely Fair Scheduler (CFS)

## Scheduler Overview

Each task maintains:
- remaining work
- weight
- virtual runtime (vruntime)

The scheduler selects the task with the minimum `vruntime`.

Fairness logic: vruntime += DEFAULT_WEIGHT / task_weight

This allows higher-weight tasks to receive relatively more CPU time.

## Technologies Used

- C++
- Cross GCC (i686-elf)
- GNU Linker (ld)
- GRUB (Multiboot)
- QEMU

This project helped me understand low-level system programming, OS boot flow, and fair CPU scheduling concepts.
