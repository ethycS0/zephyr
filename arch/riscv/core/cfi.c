#include <zephyr/kernel.h>
#include <zephyr/arch/cfi.h>
#include <zephyr/arch/riscv/csr.h>

void z_riscv_landing_pad_init(void)
{
#ifndef CONFIG_RISCV_S_MODE
	csr_set(mseccfg, MSECCFG_MLPE);
#else
	csr_set(menvcfg, MENVCFG_LPE);
#endif

#ifdef CONFIG_USERSPACE
	csr_set(senvcfg, SENVCFG_LPE);
#endif
}

void z_riscv_cfi_init(void)
{
#ifdef CONFIG_RISCV_LANDING_PADS
	z_riscv_landing_pad_init();
#endif
}
