/*
 * buzzer.c
 *
 *  Created on: 17 Sep 2020
 *      Author: linus
 */


#include "buzzer.h"
#include "main.h"
#include "devices/LED.h"
#include "dwt_stm32_delay.h"

LED BSTAT = STAT_INIT();
LED BSAVE = SAVE_INIT();
LED BPRGM = PRGM_INIT();
LED BRDY = RDY_INIT();

float C = 523.25;
float Cis = 554.37;
float D = 587.33;
float Dis = 622.25;
float E = 659.25;
float F = 698.46;
float Fis = 739.99;
float G = 783.99;
float Gis = 830.61;
float A = 880.0;
float Ais = 932.33;
float B = 987.77;

#define SF 1.5


float sixteenth = 128.0 / SF;
float eighth = 256.0 / SF;
float fourth = 512.0 / SF;


void play(float freq, float time)
{
	float value = 0.0;
	while(value < time){
		HAL_GPIO_TogglePin(BUZ_GPIO_Port, BUZ_Pin);
		DWT_Delay_us (1000*1000/freq);
		value += 1000/freq;
	}
	HAL_GPIO_WritePin(BUZ_GPIO_Port, BUZ_Pin, GPIO_PIN_RESET);
};

void take_on_me(void)
{
	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * Fis,sixteenth);
	HAL_Delay(sixteenth);
	play(2 * Fis,sixteenth);
	HAL_Delay(sixteenth);

	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * D,eighth);
	play(B,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(B,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(2 * E,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(2 * E,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(2 * E,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * Gis,sixteenth);
	HAL_Delay(sixteenth);
	play(2 * Gis,sixteenth);
	HAL_Delay(sixteenth);

	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * A,eighth);
	play(3 * Cis,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * A,sixteenth);
	HAL_Delay(sixteenth);
	play(2 * A,sixteenth);
	HAL_Delay(sixteenth);

	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * A,sixteenth);
	HAL_Delay(sixteenth);
	play(2 * E,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(2 * D,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(2 * Fis,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(2 * Fis,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	HAL_Delay(eighth);
	play(2 * Fis,eighth);

	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * E,sixteenth);
	HAL_Delay(sixteenth);
	play(2 * E,sixteenth);
	HAL_Delay(sixteenth);

	toggle(&BPRGM);
	toggle(&BRDY);

	play(2 * Fis,eighth);
	play(2 * E,eighth);

}

void coffin_dance(int n)
{
	play(n*G,eighth);
	HAL_Delay(eighth);
	play(n*G,eighth);
	play(n*D,eighth);
	play(n*C,eighth);
	HAL_Delay(eighth);
	play(n*Ais,eighth);
	HAL_Delay(eighth);
	play(n*A,eighth);
	HAL_Delay(eighth);
	play(n*A,eighth);
	play(n*A,eighth);
	play(n*C,eighth);
	HAL_Delay(eighth);
	play(n*Ais,eighth);
	play(n*A,eighth);
	play(n*G,eighth);
	HAL_Delay(eighth);
	play(n*G,eighth);
	play(n*2*Ais,eighth);
	play(n*2*A,eighth);
	play(n*2*Ais,eighth);
	play(n*2*A,eighth);
	play(n*2*Ais,eighth);
	play(n*G,eighth);
	HAL_Delay(eighth);
	play(n*G,eighth);
	play(n*2*Ais,eighth);
	play(n*2*A,eighth);
	play(n*2*Ais,eighth);
	play(n*2*A,eighth);
	play(n*2*Ais,eighth);
}

