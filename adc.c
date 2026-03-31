#include <stdio.h>

/**
 * Converts a raw ADC reading to a battery percentage (0-100%).
 * Uses integer arithmetic with rounding and overflow protection.
 */
int adc_to_percent(int adc, int adc_max, int *out_percent) {
    // 1. Validate inputs and null pointer
    if (out_percent == NULL || adc_max <= 0 || adc < 0 || adc > adc_max) {
        return -1;
    }

    // 2. Use long for intermediate calculation to prevent overflow
    // Formula with rounding: ((adc * 100) + (adc_max / 2)) / adc_max
    long temp = ((long)adc * 100);
    int result = (int)((temp + (adc_max / 2)) / adc_max);

    // 3. Clamp the result to [0, 100]
    if (result > 100) {
        result = 100;
    } else if (result < 0) {
        result = 0;
    }

    // 4. Store result and return success
    *out_percent = result;
    return 0;
}