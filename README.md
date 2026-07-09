[![Version: 1.0 Release](https://img.shields.io/badge/Version-1.0%20Release-green.svg)](https://github.com/0x007e/hal-avr0-rtc) ![Release](https://github.com/0x007e/hal-avr0-rtc/actions/workflows/release.yml/badge.svg) [![License GPLv3](https://img.shields.io/badge/License-GPLv3-lightgrey)](https://www.gnu.org/licenses/gpl-3.0.html)

# `hal-avr0-rtc` - AVR0 RTC Hardware Abstraction

The `hal-avr0-rtc` is a lightweight hardware abstraction library for `AVR0` microcontrollers. It provides a clean interface for `rtc` clock initialization while hiding direct register-level interaction from higher software layers. The library is intended for projects that want to separate low-level device startup code from application logic and establish a small, reusable system layer for AVR0 targets.

## Features

- `RTC` clock configuration for AVR0 devices.
- Encapsulation of low-level register access.
- Compact and reusable API for embedded projects.
- Foundation for layered HAL architectures.

> The `hal-avr0-rtc` library reduces coupling by providing a focused interface for essential system services. This improves portability inside a project, keeps startup code organized, and makes higher-level modules easier to maintain.

## File Structure

![File Structure](https://0x007e.github.io/hal-avr0-rtc/rtc_8c__incl.png)

```
hal/
└── avr0/
    └── rtc/
        ├── rtc.c
        └── rtc.h
```

## Downloads

The library can be downloaded (`zip` or `tar`), cloned or used as submodule in a project.

| Type      | File               | Description              |
|:---------:|:------------------:|:-------------------------|
| Library   | [zip](https://github.com/0x007E/hal-avr0-rtc/releases/latest/download/library.zip) / [tar](https://github.com/0x007E/hal-avr0-rtc/releases/latest/download/library.tar.gz) | AVR0 `rtc` library |

### Using with `git clone`

```sh
mkdir -p ./hal/avr0
git clone https://github.com/0x007E/hal-avr0-rtc.git ./hal/avr0
mv ./hal/avr0/hal-avr0-rtc ./hal/avr0/rtc
```

### Using as `git submodule`

```sh
git submodule add https://github.com/0x007E/hal-avr0-rtc.git ./hal/avr0/rtc
```

## Programming

Additional parameters like system clock selection and prescaler can be setup in the [header file](./rtc.h). A user friendly description can be found [here](https://0x007e.github.io/hal-avr0-rtc/rtc_8h.html).

```c
#include <avr/io.h>
#include <avr/interrupt.h> 

#include "../hal/avr0/rtc/rtc.h"

ISR(RTC_CNT_vect)
{
    RTC.INTFLAGS = RTC_OVF_bm;
}

int main(void)
{
    rtc_init();
    sei();

    while(1) { }
}
```

> With standard settings (`F_CPU@20MHz`, presacler `/1` and overflow `0x21`) the `rtc` ticks around `~1ms`. More details can be found in this [blog entry](https://0x007e.github.io/microcontroller/2026/01/29/use-avr0-rtc-to-control-a-systick-software-timer.html).


## Additional Information

| Type       | Link               | Description              |
|:----------:|:------------------:|:-------------------------|
| AVR0-Series | [pdf](https://ww1.microchip.com/downloads/en/DeviceDoc/megaAVR0-series-Family-Data-Sheet-DS40002015B.pdf) | megaAVR® 0-series family datasheet |

---

R. GAECHTER