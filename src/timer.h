#ifndef TIMER_H
#define TIMER_H

void timer_init();
void onIrq0(struct InterruptRegisters *regs);

#endif //timer_h
