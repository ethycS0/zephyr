#include <zephyr/kernel.h>
#include <zephyr/arch/cfi.h>

void z_riscv_landing_pad_init(void)
{
	csr_set(mseccfg, 0x400);
#ifdef CONFIG_RISCV_S_MODE
	csr_set(menvcfg, 0x2);
#endif
}

void z_riscv_shadow_stack_init(void)
{
}

void z_riscv_cfi_init(void)
{
#ifdef CONFIG_RISCV_LANDING_PADS
	z_riscv_landing_pad_init();
#endif

#ifdef CONFIG_RISCV_SHADOW_STACK
	z_riscv_shadow_stack_init();
#endif
}
