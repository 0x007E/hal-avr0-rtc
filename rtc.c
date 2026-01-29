/**
 * @file rtc.c
 * @brief Initializes the real-time clock (RTC) peripheral.
 *
 * @details
 * This function configures and enables the RTC on AVR0 devices using the configuration macros `RTC_OVERFLOW`, `RTC_CLOCK`, and `RTC_PRESCALER`. It sets the overflow period, selects the clock source, enables the overflow interrupt, and starts the RTC.
 *
 * @author g.raf
 * @date 2026-01-24
 * @version 1.0 Release
 * @copyright
 * Copyright (c) 2026 g.raf
 * Released under the GPLv3 License. (see LICENSE in repository)
 *
 * @note The corresponding ISR for the overflow interrupt
 *       (typically `RTC_CNT_vect`) must be implemented in the application
 *       for the RTC interrupt to be serviced.
 *
 * @see https://github.com/0x007e/hal-avr0-rtc "AVR0 GitHub Repository"
 */

#include "rtc.h"

/**
 * @brief Initializes the real-time clock (RTC) peripheral.
 *
 * @details
 * This function configures and enables the RTC on AVR0 devices using the
 * configuration macros `RTC_OVERFLOW`, `RTC_CLOCK`, and `RTC_PRESCALER`.
 * It sets the overflow period, selects the clock source, enables the
 * overflow interrupt, and starts the RTC.
 *
 * @note The corresponding ISR for the overflow interrupt (typically `RTC_CNT_vect`) must be implemented in the application for the RTC interrupt to be serviced.
 */
void rtc_init(void)
{	
	RTC.INTCTRL = RTC_OVF_bm;
    RTC.CLKSEL = RTC_CLOCK;

    while (RTC.STATUS & RTC_PERBUSY_bm);
    RTC.PER = RTC_OVERFLOW;

    while (RTC.STATUS & RTC_CTRLABUSY_bm);
    RTC.CTRLA = RTC_PRESCALER | RTC_RTCEN_bm;
}