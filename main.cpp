extern "C" {
#include "program.h"
}

#include <psp2/kernel/processmgr.h>
#include <psp2/power.h>

int main(int argc, char *argv[])
{
	scePowerSetArmClockFrequency(444);
    scePowerSetGpuClockFrequency(222);
    scePowerSetBusClockFrequency(222);
    scePowerSetGpuXbarClockFrequency(222);
   program_start();
   
   	sceKernelExitProcess(0);
	return 0;
}