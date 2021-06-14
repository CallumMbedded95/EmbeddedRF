#ifndef TIMER_H
#define TIMER_H

#define TIM2_ADDR 0x40000000

#define TIMx_CR1_OFFSET		0x00
#define TIMx_CR2_OFFSET		0x04
#define TIMx_SMCR_OFFSET	0x08
#define TIMx_DIER_OFFSET	0x0C
#define TIMx_SR_OFFSET		0x10
#define TIMx_EGR_OFFSET		0x14
#define TIMx_CCMR1_OFFSET	0x18
#define TIMx_CCMR2_OFFSET	0x1C
#define TIMx_CCER_OFFSET	0x20
#define TIMx_CNT_OFFSET 	0x24
#define TIMx_PSC_OFFSET		0x28
#define TIMx_ARR_OFFSET		0x2C
#define	TIMx_CCR1_OFFSET	0x34
#define TIMx_CCR2_OFFSET	0x38
#define TIMx_CCR3_OFFSET	0x3C
#define TIMx_CCR4_OFFSET	0x40
#define TIMx_DCR_OFFSET		0x48
#define TIMx_DMAR_OFFSET	0x4C

// THE CLOCK CTR UPCOUNTS ALL THE WAY TO AUTO_RELOAD. (0 - AUTO RELOAD)
void tim2_enable_clock(uint16_t AUTO_RELOAD);

int32_t get_tim2_clock_ctr();

#endif