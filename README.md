# kanjiNumerals

## Disclaimers

This program's output is only valid for positive integers up to (not including) 1,0000,0000

## How it works

Running the program starts a command line prompt that calls the function *to_kanji* on user input and prints the result. To end the program, press enter without typing any input.

The function *to_kanji* expects a string formatted in American decimal notation. That is to say, commas and leading zeroes are ignored, and "." or  any other non-numeric char is interpreted as the end of the number (fractions are not supported).

The return value is a string of kanji representing that number as it might be said in a phrase. That is to say, 50 returns "五十" (five tens), as opposed to "五〇" (five zero).

The code is thoroughly commented, feel free to take a look around!

## Examples

	to_kanji("3") == "三"

	to_kanji("500") == "五百"

	to_kanji("365.25") == "三百六十五"

	to_kanji("10,000") == "万"

	to_kanji("12345") == "万二千三百四十五"
