#ifndef _ASM_ARM_MODULE_H
#define _ASM_ARM_MODULE_H

#define MODULES_ARE_ELF32
#define Elf_Shdr	Elf32_Shdr
#define Elf_Sym		Elf32_Sym
#define Elf_Ehdr	Elf32_Ehdr
#define Elf_Rel		Elf32_Rel
#define Elf_Rela	Elf32_Rela
#define ELF_R_TYPE(X)	ELF32_R_TYPE(X)
#define ELF_R_SYM(X)	ELF32_R_SYM(X)

struct unwind_table;

struct mod_arch_specific
{
#ifdef CONFIG_ARM_UNWIND
	Elf_Shdr *unw_sec_init;
	Elf_Shdr *unw_sec_devinit;
	Elf_Shdr *unw_sec_core;
	Elf_Shdr *sec_init_text;
	Elf_Shdr *sec_devinit_text;
	Elf_Shdr *sec_core_text;
	struct unwind_table *unwind_init;
	struct unwind_table *unwind_devinit;
	struct unwind_table *unwind_core;
#endif
};

/*
 * Include the ARM architecture version.
 */
#define MODULE_ARCH_VERMAGIC	"ARMv" __stringify(__LINUX_ARM_ARCH__) " "

#endif /* _ASM_ARM_MODULE_H */
